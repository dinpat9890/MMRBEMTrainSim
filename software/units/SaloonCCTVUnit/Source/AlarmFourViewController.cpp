///
/// @file       AlarmFourViewController.cpp
///
///             It is Derrived class for CCTVView Controller
///             and updates Vision and UI when some event is triggered. Only supports Single view
///
/// @ingroup    Mumbai L2-L7 CCTV
///
/// @author     Yatendra Gupta
///
/// @copyright  (C) Copyright:  OKTAL SYDAC Pvt Ltd, 2022

#include "AlarmFourViewController.h"

namespace
{
    const size_t ACTIVE_BUTTON_COUNT_MAX = 4;
    const size_t CANVAS_SINGLE_VIEW_ID = 0;
    const double AUTO_ROTATTION_OFF = 0.0;
}

AlarmFourViewController::AlarmFourViewController(CommsInterface &comms, CanvasViewManager &canvas, CCTVState &state)
    : CCTVViewController(comms, canvas, state)
    , m_executed(false)
{
    std::vector<std::string> view_modes;
    view_modes.push_back(state.m_view_mode_to_mode_name[CCTVState::FOUR_VIEW_MODE]);
    canvas.AddCameraViewModes(view_modes);
}

AlarmFourViewController::~AlarmFourViewController()
{
    Trace::GetLogger().STAMP(Trace::VERBOSE) << "AlarmFourViewController Destructor" << Trace::EndLog();
}

void AlarmFourViewController::MarkExecutionCompleted()
{
    m_executed = false;
}

void AlarmFourViewController::Execute()
{
    if (!m_executed)
    {
        m_executed = true;
        if (m_saloon_cctv_state.m_alarm_mode == true)
        {
            std::vector<size_t> perspective_ids;
            CameraViewButtons buttons;
            buttons.Clear();

            // Set auto rotation off
            m_comms_interface.SetOutputNumber(Project::ValueName::VDUOutputs::AUTO_ROTATION_ON, AUTO_ROTATTION_OFF);
            size_t buttons_remaining_to_activate = ACTIVE_BUTTON_COUNT_MAX;
            std::vector<CCTVState::AlarmVehicleType> queuedEvents;

            for (int i = 0; i < CCTVState::FOUR_VIEW_SCREEN_ID && !m_saloon_cctv_state.m_alarm_events.empty(); i++)
            {
                CCTVState::AlarmVehicleType event_type = m_saloon_cctv_state.m_alarm_events.top();
                queuedEvents.push_back(event_type);
                m_saloon_cctv_state.m_alarm_events.pop();
                //m_saloon_cctv_state.m_current_alarm_list.erase(static_cast<int>(event_type.eventType));

                CameraViewButtons_AssociatedView asso_view = CameraViewButtons_AssociatedView_SINGLE_FEED_VIEW;
                switch (buttons_remaining_to_activate)
                {
                case 4:
                    event_type.asso_view = CameraViewButtons_AssociatedView_FIRST_VIEW;
                    break;
                case 3:
                    event_type.asso_view = CameraViewButtons_AssociatedView_SECOND_VIEW;
                    break;
                case 2:
                    event_type.asso_view = CameraViewButtons_AssociatedView_THIRD_VIEW;
                    break;
                case 1:
                    event_type.asso_view = CameraViewButtons_AssociatedView_FOURTH_VIEW;
                    break;
                }

                switch (static_cast<int>(event_type.eventType))
                {
                case CCTVState::ALARM_FIRE_1:
                    processFireAlarm(event_type, buttons, perspective_ids); //
                    m_comms_interface.SetOutputNumber(Project::ValueName::VDUOutputs::ALARM_ACTIVE_TYPE_INDEX, CCTVState::ALARM_FIRE_1);
                    m_comms_interface.SetOutputNumber(Project::ValueName::VDUOutputs::FIRE_ALARM_1, 1.0);
                    Trace::GetLogger().STAMP(Trace::INFO) << "Alarm - Fire Alarm Event Triggered " << Trace::EndLog();
                    break;
                case CCTVState::ALARM_OBSTCL_SALOON_DR_2:
                    processDoorObstcleAlarm(event_type, buttons, perspective_ids);
                    m_comms_interface.SetOutputNumber(Project::ValueName::VDUOutputs::ALARM_ACTIVE_TYPE_INDEX, CCTVState::ALARM_OBSTCL_SALOON_DR_2);
                    m_comms_interface.SetOutputNumber(Project::ValueName::VDUOutputs::OBSTCL_SALOON_DR_ALARM_2, 1.0);
                    Trace::GetLogger().STAMP(Trace::INFO) << "Alarm - Obstacle detected by saloon door type Event Triggered " << Trace::EndLog();
                    break;
                case CCTVState::ALARM_PECU_3:
                    processSaloonAlarm(event_type, 0, buttons, perspective_ids);
                    m_comms_interface.SetOutputNumber(Project::ValueName::VDUOutputs::ALARM_ACTIVE_TYPE_INDEX, CCTVState::ALARM_PECU_3);
                    m_comms_interface.SetOutputNumber(Project::ValueName::VDUOutputs::PECU_ALARM_3, 1.0);
                    Trace::GetLogger().STAMP(Trace::INFO) << "Alarm - PECU alarm type Event Triggered " << Trace::EndLog();
                    break;
                case CCTVState::ALARM_DR_UNLK_4:
                    processSaloonAlarm(event_type, 0, buttons, perspective_ids); //
                    m_comms_interface.SetOutputNumber(Project::ValueName::VDUOutputs::ALARM_ACTIVE_TYPE_INDEX, CCTVState::ALARM_DR_UNLK_4);
                    m_comms_interface.SetOutputNumber(Project::ValueName::VDUOutputs::DR_UNLK_ALARM_4, 1.0);
                    Trace::GetLogger().STAMP(Trace::INFO) << "Alarm - Door unlocked type Event Triggered " << Trace::EndLog();
                    break;
                case CCTVState::ALARM_EMRG_DR_OPN_5:
                    processEmergencyDoorAlarm(event_type, buttons, perspective_ids); //DMC Detrainment Camera
                    m_comms_interface.SetOutputNumber(Project::ValueName::VDUOutputs::ALARM_ACTIVE_TYPE_INDEX, CCTVState::ALARM_EMRG_DR_OPN_5);
                    m_comms_interface.SetOutputNumber(Project::ValueName::VDUOutputs::EMRG_DR_OPN_ALARM_5, 1.0);
                    Trace::GetLogger().STAMP(Trace::INFO) << "Alarm - Opening of emergency door type Event Triggered " << Trace::EndLog();
                    break;
                case CCTVState::ALARM_DRVR_DSK_6:
                    processCABAlarm(event_type, buttons, perspective_ids); //not in scope (DMC Detrainment Camera)
                    m_comms_interface.SetOutputNumber(Project::ValueName::VDUOutputs::ALARM_ACTIVE_TYPE_INDEX, CCTVState::ALARM_DRVR_DSK_6);
                    m_comms_interface.SetOutputNumber(Project::ValueName::VDUOutputs::DRVR_DSK_ALARM_6, 1.0);
                    Trace::GetLogger().STAMP(Trace::INFO) << "Alarm - Opening of driver console desk type Event Triggered " << Trace::EndLog();
                    break;
                case CCTVState::ALARM_OBSTRUCTION_DEFLCT_7:
                    processODDAlarm(event_type, buttons, perspective_ids); // (DMC ODD Camera)
                    m_comms_interface.SetOutputNumber(Project::ValueName::VDUOutputs::ALARM_ACTIVE_TYPE_INDEX, CCTVState::ALARM_OBSTRUCTION_DEFLCT_7);
                    m_comms_interface.SetOutputNumber(Project::ValueName::VDUOutputs::OBSTRUCTION_DEFLCT_ALARM_7, 1.0);
                    Trace::GetLogger().STAMP(Trace::INFO) << "Alarm - Obstruction deflection device type Event Triggered " << Trace::EndLog();
                    break;
                case CCTVState::ALARM_TRACK_EVENT_8:
                    processTrackAlarm(event_type, buttons, perspective_ids); // (DMC Driver's Track Camera)
                    m_comms_interface.SetOutputNumber(Project::ValueName::VDUOutputs::ALARM_ACTIVE_TYPE_INDEX, CCTVState::ALARM_TRACK_EVENT_8);
                    m_comms_interface.SetOutputNumber(Project::ValueName::VDUOutputs::TRACK_EVENT_ALARM_8, 1.0);
                    Trace::GetLogger().STAMP(Trace::INFO) << "Alarm - Track related events type Event Triggered " << Trace::EndLog();
                    break;
                case CCTVState::ALARM_EMRG_CCTV_9:
                    processSaloonAlarm(event_type, 0, buttons, perspective_ids); // not in scope
                    m_comms_interface.SetOutputNumber(Project::ValueName::VDUOutputs::ALARM_ACTIVE_TYPE_INDEX, CCTVState::ALARM_EMRG_CCTV_9);
                    m_comms_interface.SetOutputNumber(Project::ValueName::VDUOutputs::EMRG_CCTV_ALARM_9, 1.0);
                    Trace::GetLogger().STAMP(Trace::INFO) << "Alarm - CCTV emergency button Event Triggered " << Trace::EndLog();
                    break;
                case CCTVState::ALARM_OHE_10:
                    processOHEAlarm(event_type, buttons, perspective_ids); // (Driver's Forward View)
                    m_comms_interface.SetOutputNumber(Project::ValueName::VDUOutputs::ALARM_ACTIVE_TYPE_INDEX, CCTVState::ALARM_OHE_10);
                    m_comms_interface.SetOutputNumber(Project::ValueName::VDUOutputs::OHE_ALARM_10, 1.0);
                    Trace::GetLogger().STAMP(Trace::INFO) << "Alarm - OHE event type Event Triggered " << Trace::EndLog();
                    break;
                case CCTVState::ALARM_PANTO_11:
                    processPantoAlarm(event_type, buttons, perspective_ids); // PANTO Camera
                    m_comms_interface.SetOutputNumber(Project::ValueName::VDUOutputs::ALARM_ACTIVE_TYPE_INDEX, CCTVState::ALARM_PANTO_11);
                    m_comms_interface.SetOutputNumber(Project::ValueName::VDUOutputs::PANTO_ALARM_11, 1.0);
                    Trace::GetLogger().STAMP(Trace::INFO) << "Alarm - Pantograph event type Event Triggered " << Trace::EndLog();
                    break;
                }
                --buttons_remaining_to_activate;
            }
            //Trace::GetLogger().STAMP(Trace::VERBOSE) << "AlarmFourViewController::External Alarm, Vehicle Index : " << associated_vehicle_index + 1 << Trace::EndLog();
            //m_comms_interface.SetOutputNumber(Project::ValueName::VDUOutputs::SELECTED_VEHICLE_IDX, associated_vehicle_index + 1);

            while (buttons_remaining_to_activate > 0)
            {
                Trace::GetLogger().STAMP(Trace::VERBOSE) << "buttons_remaining_to_activate : " << buttons_remaining_to_activate << Trace::EndLog();
                --buttons_remaining_to_activate;
                SetEmptyButton(perspective_ids, buttons);
            }

            std::string buttons_state;
            buttons.AppendToString(&buttons_state);
            Trace::GetLogger().STAMP(Trace::VERBOSE) << "AlarmFourViewController::External Alarm, Buttons State : " << buttons.DebugString() << Trace::EndLog();

            m_comms_interface.SetOutputRaw(Project::ValueName::VDUOutputs::CAMERA_VIEW_BUTTONS_STATE, buttons_state);
            m_canvas_view_manager.UpdateView(m_saloon_cctv_state.m_view_mode_to_mode_name[CCTVState::FOUR_VIEW_MODE], perspective_ids);

            for (int i = 0; i < static_cast<int>(queuedEvents.size()); i++)
                m_saloon_cctv_state.m_alarm_events.push(queuedEvents[i]);
        }
    }
}

void AlarmFourViewController::SetEmptyButton(std::vector<size_t> & perspective_ids, CameraViewButtons & buttons)
{
    CameraViewButtons_AssociatedView associated_view = CameraViewButtons_AssociatedView_NO_VIEW;
    CameraViewButtons_Button button;
    button.Clear();
    button.set_id(0);
    button.set_name("");
    button.set_state(CameraViewButtons_State_DISABLED);
    button.set_associatedview(CameraViewButtons_AssociatedView_NO_VIEW);
    buttons.add_button()->CopyFrom(button);
    perspective_ids.push_back(0);
}

void AlarmFourViewController::processSaloonAlarm(CCTVState::AlarmVehicleType eventType, int door_index, CameraViewButtons & buttons, 
    std::vector<size_t> & perspective_ids)
{
    size_t buttons_remaining_to_activate = ACTIVE_BUTTON_COUNT_MAX;
    auto & all_camera_buttons = m_saloon_cctv_state.m_all_vehicle_internal_buttons;
    auto associated_vehicle_index = eventType.vehicle_idx - 1;

    auto button_list_itr =    all_camera_buttons.find(associated_vehicle_index);
    if (button_list_itr != all_camera_buttons.end())
    {
        auto & button_list = button_list_itr->second;
        auto & cam_button = button_list[door_index];
        CameraViewButtons_Button button;
        button.Clear();
        
            cam_button.button_state = CameraViewButtons_State_ACTIVE;
            CameraViewButtons_AssociatedView asso_view = CameraViewButtons_AssociatedView_SINGLE_FEED_VIEW;

            //associated_vehicle_index = item.second.vehicle_index;
            auto associated_camera = cam_button.camera_type;
            auto perspective_id = m_saloon_cctv_state.m_vehicle_cameras[associated_vehicle_index].GetPerspectiveOfCamera(associated_camera);
            perspective_ids.push_back(perspective_id);
            
            bool activeFlg = true;

        button.set_id(int(associated_vehicle_index));
        button.set_name(cam_button.camera_name);
        button.set_state(cam_button.button_state);
        button.set_associatedview(eventType.asso_view);
        button.set_alarmtype(static_cast<int>(eventType.eventType));
        if (activeFlg)
            buttons.add_button()->CopyFrom(button);
    }
    //else
    //    SetEmptyButton(perspective_ids, buttons);

}

void AlarmFourViewController::processFireAlarm(CCTVState::AlarmVehicleType eventType, CameraViewButtons & buttons, std::vector<size_t> & perspective_ids)
{
    processSaloonAlarm(eventType, 0, buttons, perspective_ids);
}
void AlarmFourViewController::processExternalAlarm(CCTVState::AlarmVehicleType eventType, CCTVState::CarCameraType camera_type,
    CameraViewButtons & buttons, std::vector<size_t> & perspective_ids)
{
    size_t buttons_remaining_to_activate = ACTIVE_BUTTON_COUNT_MAX;
    auto & all_camera_buttons = m_saloon_cctv_state.m_all_vehicle_external_buttons;
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
                perspective_ids.push_back(perspective_id);
                bool activeFlg = true;

                //button.set_id(int(item.first));
                button.set_id(int(associated_vehicle_index));
                button.set_name(panto_button.camera_name);
                button.set_state(panto_button.button_state);
                button.set_associatedview(eventType.asso_view);
                button.set_alarmtype(static_cast<int>(eventType.eventType));
                if (activeFlg)
                    buttons.add_button()->CopyFrom(button);

                break;
            }
        }
    }
    //else
    //    SetEmptyButton(perspective_ids, buttons);
}

void AlarmFourViewController::processInternalCabAlarm(CCTVState::AlarmVehicleType eventType, CCTVState::CarCameraType camera_type,
    CameraViewButtons & buttons, std::vector<size_t> & perspective_ids)
{
    size_t buttons_remaining_to_activate = ACTIVE_BUTTON_COUNT_MAX;
    auto & all_camera_buttons = m_saloon_cctv_state.m_all_vehicle_cab_buttons;
    auto associated_vehicle_index = eventType.vehicle_idx - 1;

    auto button_list_itr = all_camera_buttons.find(associated_vehicle_index);
    if (button_list_itr != all_camera_buttons.end())
    {
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
                perspective_ids.push_back(perspective_id);
                bool activeFlg = true;

                button.set_id(int(associated_vehicle_index));
                button.set_name(panto_button->second.camera_name);
                button.set_state(panto_button->second.button_state);
                button.set_associatedview(eventType.asso_view);
                button.set_alarmtype(static_cast<int>(eventType.eventType));
                if (activeFlg)
                    buttons.add_button()->CopyFrom(button);

            }
        }
    }
}

void AlarmFourViewController::processPantoAlarm(CCTVState::AlarmVehicleType eventType, CameraViewButtons & buttons, std::vector<size_t> & perspective_ids)
{
    processExternalAlarm(eventType, CCTVState::T_PANTO_CAMERA_1, buttons, perspective_ids);
}
void AlarmFourViewController::processDoorObstcleAlarm(CCTVState::AlarmVehicleType event_type, CameraViewButtons & buttons, std::vector<size_t> & perspective_ids)
{
    processSaloonAlarm(event_type, 0, buttons, perspective_ids);
}
void AlarmFourViewController::processEmergencyDoorAlarm(CCTVState::AlarmVehicleType eventType, CameraViewButtons & buttons, std::vector<size_t> & perspective_ids)
{
    processInternalCabAlarm(eventType, CCTVState::DM_CAB_CAMERA_1, buttons, perspective_ids); //DMC Cab or Detrainment Camera
}
void AlarmFourViewController::processTrackAlarm(CCTVState::AlarmVehicleType eventType, CameraViewButtons & buttons, std::vector<size_t> & perspective_ids)
{
    processExternalAlarm(eventType, CCTVState::DM_TRACK_CAMERA_1, buttons, perspective_ids); //DMC Track Camera
}
void AlarmFourViewController::processODDAlarm(CCTVState::AlarmVehicleType eventType, CameraViewButtons & buttons, std::vector<size_t> & perspective_ids)
{
    processExternalAlarm(eventType, CCTVState::DM_ODD_CAMERA_1, buttons, perspective_ids); //DMC ODD Camera
}
void AlarmFourViewController::processOHEAlarm(CCTVState::AlarmVehicleType eventType, CameraViewButtons & buttons, std::vector<size_t> & perspective_ids) //Front camera
{
    processExternalAlarm(eventType, CCTVState::DM_FRONT_CAMERA_1, buttons, perspective_ids); //Driver's Forward View
}
void AlarmFourViewController::processCABAlarm(CCTVState::AlarmVehicleType eventType, CameraViewButtons & buttons, std::vector<size_t> & perspective_ids) //driver console
{
    processExternalAlarm(eventType, CCTVState::DM_FRONT_CAMERA_1, buttons, perspective_ids); //DMC Detrainment Camera
}
