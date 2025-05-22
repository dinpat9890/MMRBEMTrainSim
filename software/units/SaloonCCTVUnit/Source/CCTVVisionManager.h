///
/// @file       CCTVVisionManager.h
///
///             Interface to Sydac Vision Properties.
///              It is fetch vision propeties from Sydac using watcher & also update output to it.
///
/// @ingroup    Mumbai L2-L7 CCTV
///
/// @author     Yatendra Gupta
///
/// @copyright  (C) Copyright:  OKTAL SYDAC Pvt Ltd, 2022
///


#pragma once
#include "IVisionInterface.h"
#include "project_comms_structure/ProjectObjectConstants.h"
#include "core_data_access/Vision.h"
#include "core_services/PerspectiveLinker.h"
#include <string>
#include <vector>
///
/// @file       CCTVVisionManager.cpp
///
///             Interface to Sydac Vision Properties.
///              It is fetch vision propeties from Sydac using watcher & also update output to it.
///
/// @ingroup    Mumbai L2-L7 CCTV
///
/// @author     Yatendra Gupta
///
/// @copyright  (C) Copyright:  OKTAL SYDAC Pvt Ltd, 2022
///

#include <set>
#include "sim_comms/Gateway.h"
#include "CanvasViewManager.h"
#include "core_types/SessionData.h"

#ifndef SALOON_VISION_MANAGER_H
#define SALOON_VISION_MANAGER_H

class CCTVVisionManager :
    public IVisionInterface
{
public:
    CCTVVisionManager(Comms::Gateway &gateway, Common::Data::DataAccess &data_access, std::string engine_selector_key, 
        Core::BaseScenarioData::HubData &hub_data);
   
    void Start();

    void ObjectCreated(Comms::Object object);

    void UpdateView(const std::string &mode_name, size_t view_id, size_t perspective_id) override;

    // This method expects perspective IDs to be in same order of assocuated view IDs
    // in ascending order only.
    // Ex. [ V_ID_2 <=> P_ID_1, V_ID_0 <=> P_ID_2, V_ID_1 <=> P_ID_4, V_ID_3 <=> P_ID_3 ]
    // then vector should be: [P_ID_2, P_ID_4, P_ID_1, P_ID_3]
    void UpdateView(const std::string &mode_name, std::vector<size_t> &perspective_id) override;
    virtual const std::vector<Core::Data::VisionEngineMode>& GetAllVisionEngineModes() const override;

    void AddViews(const std::string &mode_name, std::vector<Core::View> views) override;
    int GetPerspectiveId(const std::string &perspective_name) override;
    int GetPerspectiveOfView(const std::string &mode_name, int view_id) override;
    std::vector<Core::View> & GetView(const std::string &mode_name) override;
    
    void AddObjectCreationCallback(size_t class_id, const Object_Callback_t &cb);
    void AddObjectInClassIdMap(Comms::Object object);
    void AddressCallbacksOfObject(size_t class_id);

    ~CCTVVisionManager(void);
private:

    Comms::Gateway  &m_gateway;
    Core::BaseScenarioData::HubData &m_hub_data;
    std::string     m_selector_key;
    Comms::Object   m_vision_engine_object;
    Comms::Object   m_inst_vision_engine_object;

    std::vector<Core::Data::VisionEngineMode> m_vision_engine_all_modes;
    PerspectiveLinker m_perspective_linker;
    std::map<std::string, std::vector<Core::View>> m_mode_to_views;
    std::map<std::string, Comms::Object> m_mode_to_canvas;
    std::map<size_t, std::vector<Comms::Object>> m_classid_objects;
    std::map<size_t, std::vector<Object_Callback_t *>> map_class_id_creation_callback;
    Core::Locking<std::mutex> m_core_lock;

    std::recursive_mutex m_local_mutex;

    struct HubWrapper
    {
        HubWrapper(Comms::Object hub_object);
        ~HubWrapper();

        Comms::Object m_hub_object;

        std::map<std::string, std::shared_ptr<Core::CanvasObjectPerspectiveControl>> m_canvases;
        std::map<std::string, std::shared_ptr<Core::CanvasPerspectiveLinker>>        m_canvas_perspective_linkers;
    };
    std::vector<std::shared_ptr<HubWrapper>> m_hubs;

    void AddViewsToCanvas(std::shared_ptr<HubWrapper> hub, const std::string &mode_name);
};

#endif