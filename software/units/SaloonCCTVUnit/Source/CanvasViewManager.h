///
/// @file       CCTVCommsInterface.h
///
///             Calculates the Canvas View and 
///             updates vision with requested perspective ids via Vision Interface
///
/// @ingroup    Mumbai L2-L7 CCTV
///
/// @author     Yatendra Gupta
///
/// @copyright  (C) Copyright:  OKTAL SYDAC Pvt Ltd, 2022
///

#pragma once

#include "IVisionInterface.h"
#include "ICCTVProperties.h"
#include "core_services/PerspectiveLinker.h"
#include <set>
#include <string>
namespace
{
    class VisionEngineModeCompare
    {
    public:
        bool operator()(const Core::Data::VisionEngineMode &lhs, const Core::Data::VisionEngineMode &rhs) const
        {
            return (lhs.name < rhs.name);
        }
    };

    const auto VISION_ENGINE_MODE = std::string("Vision Engine Mode");
    const auto CAMERA             = std::string("Camera");
    const auto VIEW_COUNT         = std::string("View Count");
    const auto VIEW_INDEX         = std::string("View Index");
    const auto TYPE               = std::string("Type");
    const auto NAME               = std::string("Name");
}

struct CCTVCameraVisionMode
{
    CCTVCameraVisionMode::CCTVCameraVisionMode();

    CCTVCameraVisionMode::CCTVCameraVisionMode(const Core::Data::VisionEngineMode &mode);

    static const std::string TYPE;
    int         vision_engine_mode_id;
    std::string name;
    std::string type;
    int view_count;
    
    // Basic default perspective definition
    std::vector<Core::Data::VisionModeCamera> cameras;
};

class CanvasViewManager
{
public:
    CanvasViewManager(IVisionInterface &iVisionInterface, ICCTVProperties &ICCTVProperties, const std::string &engine_selector_key);
    ~CanvasViewManager();

    void UpdateView(const std::string &mode_name, size_t view_id, size_t perspective_id);

    // This method expects perspective IDs to be in same order of assocuated view IDs
    // in ascending order only.
    // Ex. [ V_ID_2 <=> P_ID_1, V_ID_0 <=> P_ID_2, V_ID_1 <=> P_ID_4, V_ID_3 <=> P_ID_3 ]
    // then vector should be: [P_ID_2, P_ID_4, P_ID_1, P_ID_3]
    void UpdateView(const std::string &mode_name, std::vector<size_t> &perspective_id);

    size_t AddCameraViewModes(const std::vector<std::string> &modes);
    std::vector<Core::View> CalculateViews(const Core::Data::VisionEngineMode &vem) const;

private:
    Comms::Object   m_vision_engine_object;

    std::vector<Core::Data::VisionEngineMode> m_vision_engine_all_modes;
    std::set<Core::Data::VisionEngineMode, VisionEngineModeCompare> m_vision_engine_modes;

    std::map<std::string, std::vector<Core::View>> m_mode_to_canvas_views;
    Core::Locking<std::mutex> m_core_lock;

    std::recursive_mutex m_local_mutex;

    IVisionInterface &m_iVisionInterface;
    std::string     m_selector_key;
public:

    double m_canvas_x;
    double m_canvas_y;
    double m_canvas_length;
    double m_canvas_height;
};
