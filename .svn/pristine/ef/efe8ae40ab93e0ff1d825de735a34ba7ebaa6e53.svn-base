///
/// @file       CanvasViewManager.cpp
///
///             Calculates the Canvas View and 
///             updates vision with requested perspective ids via Vision Interface
///
/// @ingroup    Mumbai L2-L7 CCTV
///
/// @author     Yatendra Gupta
///
/// @copyright  (C) Copyright:  OKTAL SYDAC Pvt Ltd, 2022

#include "CanvasViewManager.h"
#include "CCTVProperties.h"
#include "project_comms_structure/ProjectObjectConstants.h"
#include "core_data_access/Vision.h"
#include "Common/PropertySerialization.h"

namespace
{
    /// The Serialize function to be used with Sydac::SerializeGroupedEntries<DataAccess::VisionModeCamera>
    ///
    /// @param o            The output VisionModeCamera object.
    /// @param properties   Properties to be serialized.
    /// @param section      The Properties section that has the VisionModeCamera configuration.

    void Serialize(Core::Data::VisionModeCamera &o, const Common::Properties &properties, const std::string &section)
    {
        o.view_index = properties.GetProperty<int>(section, VIEW_INDEX);
        o.type       = properties.GetProperty<std::string>(section, TYPE);
        o.name       = properties.GetProperty<std::string>(section, NAME);
    }
}

const std::string CCTVCameraVisionMode::TYPE = "Saloon_CCTV";

/// The default constructor for the PlatformCameraVisionMode.
///
/// This initializes the vision engine mode to have zero views.

CCTVCameraVisionMode::CCTVCameraVisionMode()
    : vision_engine_mode_id(-1), type(TYPE), view_count(0)
{
}

/// The conversion constructor from VisionEngineMode to CCTVCameraVisionMode.
///
/// Initializes the FixedVisionEngineMode from the properties defined in the VisionEngineMode.
///
/// @param mode The base VisionEngineMode object that has the properties of the CCTVCameraVisionMode.

CCTVCameraVisionMode::CCTVCameraVisionMode(const Core::Data::VisionEngineMode &mode)
{
    if(mode.type != TYPE)
        throw std::runtime_error("Failed to create CCTVCameraVisionMode from the VisionEngineMode of type '" +
        mode.type + "'.");

    vision_engine_mode_id = mode.vision_engine_mode_id;
    name                  = mode.name;
    type                  = mode.type;

    view_count   = mode.properties.GetProperty(VISION_ENGINE_MODE, VIEW_COUNT, 0);

    cameras = Common::SerializeGroupedEntries<Core::Data::VisionModeCamera>(mode.properties, VISION_ENGINE_MODE, CAMERA);
}

CanvasViewManager::CanvasViewManager(IVisionInterface &iVisionInterface, ICCTVProperties & iCCTVProperties, const std::string &engine_selector_key)
    : 
    m_iVisionInterface(iVisionInterface),
    m_selector_key(engine_selector_key)
{
    m_canvas_x      = iCCTVProperties.GetCanvasX();
    m_canvas_y      = iCCTVProperties.GetCanvasY();
    m_canvas_length = iCCTVProperties.GetCanvasLength();
    m_canvas_height = iCCTVProperties.GetCanvasHeight();

    const auto vision_engine_all_modes = m_iVisionInterface.GetAllVisionEngineModes();
    std::for_each(vision_engine_all_modes.begin(), vision_engine_all_modes.end(), [&](Core::Data::VisionEngineMode vem)
    {
        auto views = CalculateViews(vem);
        m_iVisionInterface.AddViews(vem.name, views);
    });
}

CanvasViewManager::~CanvasViewManager()
{
}

size_t CanvasViewManager::AddCameraViewModes(const std::vector<std::string> &modes)
{
    size_t set_modes_count = 0;

    std::lock_guard<std::recursive_mutex> lock(m_local_mutex);
    const auto vision_engine_all_modes = m_iVisionInterface.GetAllVisionEngineModes();

    std::for_each(modes.begin(), modes.end(), [&](std::string mode_name)
    {
        // Search by name for the desired mode in all available modes.
        auto mode_itr = std::find_if(vision_engine_all_modes.begin(), vision_engine_all_modes.end(),
            [&](Core::Data::VisionEngineMode mode)
            {
                return mode.name == mode_name;
            });

        // If mode found, push it in desired modes
        if(mode_itr != vision_engine_all_modes.end())
        {
            m_vision_engine_modes.insert(*mode_itr);
            ++set_modes_count;
        }
    });

    return set_modes_count;
}

/// Calculates Core::View objects based on information in a VisionEngineMode objects.
/// The number and arrangement of views are based on the view_count
/// items within the VisionEngineMode object. If either of the variables view_columns
/// or view_rows are zero, it is calculated to provide at least enough views to display all
/// the views in view_count.
///
/// @param vem  The VisionEngineMode object to calculate views for.
/// @return The calculated Core::View objects to be created.

std::vector<Core::View> CanvasViewManager::CalculateViews(const Core::Data::VisionEngineMode &vem) const
{
    // Below diagram explains the layout of possible view displays of the CCTV screen.
    //
    //                     |<---CANVAS_TOTAL_LENGTH--->|
    //
    //                            __(DRAWN_CANVAS_X, DRAWN_CANVAS_Y)       |<CANVAS_DRAWN_LENGTH>|
    //        ___          ______|______________________             ____________________________
    //         ^           |     |                     |             |                           |
    //         |           |     V_____________________|             |     ______________________|         ___
    //         |           |     |  View 1  |  View 2  |             |     |                     |          ^
    //         |           |     |Car Camera|Car Camera|             |     |                     |          |
    // CANVAS_TOTAL_HEIGHT |     |    1     |     2    |     OR      |     |       View 1        |          |
    //         |           |     |----------|----------|             |     |     Car Camera      | CANVAS_DRAWN_HEIGHT
    //         |           |     |  View 3  |  View 4  |             |     |          1          |          |
    //         |           |     |Car Camera|Car Camera|             |     |                     |          |
    //         V           |     |    3     |     4    |             |     |                     |          V
    //        ---          -----------------------------             -----------------------------         ---
    //                     ^
    //                     |
    //                   (0,0)
    //
    const double CANVAS_TOTAL_LENGTH = 1.0;
    const double CANVAS_TOTAL_HEIGHT = 1.0;

    // Calculate percentage on scale of 0 to 1.
    //const double CANVAS_DRAWN_HEIGHT = m_canvas_height / (m_canvas_y + m_canvas_height);
    const double CANVAS_DRAWN_LENGTH = m_canvas_length / (m_canvas_x + m_canvas_length);
    const double DRAWN_CANVAS_Y = m_canvas_y / (m_canvas_y + m_canvas_height);
    const double DRAWN_CANVAS_X = m_canvas_x / (m_canvas_x + m_canvas_length);

    CCTVCameraVisionMode scvem(vem);
    auto view_count = scvem.view_count;

    std::vector<Core::View> views;

    switch(view_count)
    {
    case SINGLE_VIEW_COUNT:
        {
            Core::View v;
            v.is_enabled        = true;
            v.view_id           = 0;
            v.perspective_id    = DEFAULT_PERSPECTIVE_ID;
            v.position_bottom   = 0.0;
            v.position_left     = CANVAS_TOTAL_LENGTH - CANVAS_DRAWN_LENGTH;
            v.position_right    = CANVAS_TOTAL_LENGTH;
            v.position_top      = CANVAS_TOTAL_HEIGHT - DRAWN_CANVAS_Y;

            views.push_back(v);
        }
        break;

    case FOUR_VIEW_COUNT:
        for(int view = 0; view < view_count; ++view)
        {
            Core::View v;
            v.is_enabled      = true;
            v.view_id         = int(view);
            v.perspective_id  = DEFAULT_PERSPECTIVE_ID;
            switch(view)
            {
            case FIRST_VIEW:
                v.position_bottom   = CANVAS_TOTAL_HEIGHT - DRAWN_CANVAS_Y - ((CANVAS_TOTAL_HEIGHT - DRAWN_CANVAS_Y) / 2);
                v.position_left     = CANVAS_TOTAL_LENGTH - CANVAS_DRAWN_LENGTH;
                v.position_right    = CANVAS_TOTAL_LENGTH - ((CANVAS_TOTAL_LENGTH - DRAWN_CANVAS_X) / 2);
                v.position_top      = CANVAS_TOTAL_HEIGHT - DRAWN_CANVAS_Y;
                break;

            case SECOND_VIEW:
                v.position_bottom   = CANVAS_TOTAL_HEIGHT - DRAWN_CANVAS_Y - ((CANVAS_TOTAL_HEIGHT - DRAWN_CANVAS_Y) / 2);
                v.position_left     = CANVAS_TOTAL_LENGTH - ((CANVAS_TOTAL_LENGTH - DRAWN_CANVAS_X) / 2);
                v.position_right    = CANVAS_TOTAL_LENGTH;
                v.position_top      = CANVAS_TOTAL_HEIGHT - DRAWN_CANVAS_Y;
                break;

            case THIRD_VIEW:
                v.position_bottom   = 0.0;
                v.position_left     = CANVAS_TOTAL_LENGTH - CANVAS_DRAWN_LENGTH;
                v.position_right    = CANVAS_TOTAL_LENGTH - ((CANVAS_TOTAL_LENGTH - DRAWN_CANVAS_X) / 2);
                v.position_top      = CANVAS_TOTAL_HEIGHT - DRAWN_CANVAS_Y - ((CANVAS_TOTAL_HEIGHT - DRAWN_CANVAS_Y) / 2);
                break;

            case FOURTH_VIEW:
                v.position_bottom   = 0.0;
                v.position_left     = CANVAS_TOTAL_LENGTH - ((CANVAS_TOTAL_LENGTH - DRAWN_CANVAS_X) / 2);
                v.position_right    = CANVAS_TOTAL_LENGTH;
                v.position_top      = CANVAS_TOTAL_HEIGHT - DRAWN_CANVAS_Y - ((CANVAS_TOTAL_HEIGHT - DRAWN_CANVAS_Y) / 2);
                break;
            }

            views.push_back(v);
        }
        break;
    }

    return views;
}

void CanvasViewManager::UpdateView(const std::string &mode_name, size_t view_id, size_t perspective_id)
{
    m_iVisionInterface.UpdateView(mode_name, view_id, perspective_id);
}

void CanvasViewManager::UpdateView(const std::string &mode_name, std::vector<size_t> &perspective_ids)
{
    m_iVisionInterface.UpdateView(mode_name, perspective_ids);
}
