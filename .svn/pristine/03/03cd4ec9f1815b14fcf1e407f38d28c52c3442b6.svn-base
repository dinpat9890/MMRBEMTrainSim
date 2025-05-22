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


#include "CCTVVisionManager.h"
#include "Common/StandardLogging.h"

namespace
{
    const std::string SINGLE_VIEW_MODE = "SingleView";
    const std::string FOUR_VIEW_MODE = "FourView";

    std::string CalculateSelectorName(size_t class_id, std::string selector)
    {
        std::stringstream return_value;
        Sim::ObjectDefinition engine_definition = Core::GetObjectDefinition(int(class_id));
        return_value << engine_definition.name << " " << selector;

        return return_value.str();
    }
}

CCTVVisionManager::CCTVVisionManager(Comms::Gateway &gateway, Common::Data::DataAccess &data_access, std::string engine_selector_key, Core::BaseScenarioData::HubData &hub_data) :
    m_gateway(gateway),
    m_hub_data(hub_data),
    m_selector_key(engine_selector_key),
    m_perspective_linker(m_core_lock)
{
    Core::Database::Vision vision = Core::Database::Vision(data_access);

    m_vision_engine_all_modes = vision.GetAllVisionEngineModes();

    m_vision_engine_all_modes.erase(remove_if(m_vision_engine_all_modes.begin(), m_vision_engine_all_modes.end(),
        [&](const Core::Data::VisionEngineMode &mode) {
        return mode.type != engine_selector_key; }), m_vision_engine_all_modes.end());
}

void CCTVVisionManager::Start()
{
    const OS::Lock<Comms::Gateway> LOCK(m_gateway);
    m_perspective_linker.Attach(m_gateway.GetRootObject());
    Comms::AddCreationCallback(m_gateway.GetRootObject(), MakeCallback(&CCTVVisionManager::ObjectCreated, this));
}

CCTVVisionManager::~CCTVVisionManager(void)
{
}

void CCTVVisionManager::ObjectCreated(Comms::Object object)
{
    size_t class_id = Core::GetClassID(object);

    switch (class_id)
    {
    case Project::ClassID::WORLD:
    {
        Comms::AddCreationCallback(object, MakeCallback(&CCTVVisionManager::ObjectCreated, this));
    }
    break;

    case Project::ClassID::TRAIN:
    {
        if (object.Numbers().Get(Train::ValueName::Train::SCENARIO_TRAIN_ID).value == m_hub_data.scenario_train_id)
        {
            Comms::AddCreationCallback(object, MakeCallback(&CCTVVisionManager::ObjectCreated, this));
        }
    }
    break;
    case Core::ClassID::HUB:
    {
        /*
        Deal with only our own hub
        */

        //if it is not our hub, return.
        if (object.Numbers().Get(Core::ValueName::Hub::HUB_ID).value != m_hub_data.hub_id)
        {
            return;
        }

        try
        {
            std::lock_guard<std::recursive_mutex> lock(m_local_mutex);

            std::shared_ptr<HubWrapper> hub = std::make_shared<HubWrapper>(object);
            Trace::GetLogger().STAMP(Trace::VERBOSE) << "VisionEngineMode " << Trace::EndLog();
            // Create a canvas and take control of each mode
            std::for_each(m_vision_engine_all_modes.begin(), m_vision_engine_all_modes.end(), [&](Core::Data::VisionEngineMode vem)
            {
                std::shared_ptr<Core::CanvasObjectPerspectiveControl> c(std::make_shared<Core::CanvasObjectPerspectiveControl>(vem.vision_engine_mode_id, vem.name));
                std::shared_ptr<Core::CanvasPerspectiveLinker>        pl(std::make_shared<Core::CanvasPerspectiveLinker>(m_perspective_linker, *c.get()));

                c->SetParentObject(object);
                Trace::GetLogger().STAMP(Trace::VERBOSE) << "VisionEngineMode vem.name : " << vem.name << " " << vem.type << " " << vem.vision_engine_mode_id  << Trace::EndLog();
                hub->m_canvases.insert(std::make_pair(vem.name, c));
                hub->m_canvas_perspective_linkers.insert(std::make_pair(vem.name, pl));
                c.reset();
                pl.reset();

                AddViewsToCanvas(hub, vem.name);
            });

            m_hubs.push_back(hub);
            hub.reset();
        }
        catch (CommonException &e)
        {
            e.AddStackTrace(FLSTAMP, "Getting Hub ID");
            Trace::g_plog->LogException(e);
        }
        Comms::AddCreationCallback(object, MakeCallback(&CCTVVisionManager::ObjectCreated, this));
    }
    break;

    case Core::ClassID::VISION_ENGINE:
    {
        std::string vision_name = CalculateSelectorName(class_id, m_selector_key);// m_selector_key have ENGINE_NAME as key string
        if (object.GetName() == vision_name)
        {
            m_vision_engine_object = object;   // cab vision engine object
        }

        const std::string ENGINE_NAME_INST = "Saloon_CCTV_Inst";
        std::string inst_vision_name = CalculateSelectorName(class_id, ENGINE_NAME_INST);//m_inst_selector_key
        if (object.GetName() == inst_vision_name)
        {
            m_inst_vision_engine_object = object;   // instructor vision engine object
        }
    }
    break;

    case Core::ClassID::CANVAS:
        if (CalculateSelectorName(class_id, SINGLE_VIEW_MODE) == object.GetName())
        {
            m_mode_to_canvas[SINGLE_VIEW_MODE] = object;
        }
        else if (CalculateSelectorName(class_id, FOUR_VIEW_MODE) == object.GetName())
        {
            m_mode_to_canvas[FOUR_VIEW_MODE] = object;
        }
        break;
    case Project::ClassID::PERSPECTIVES:
    {
        Comms::AddCreationCallback(object, MakeCallback(&CCTVVisionManager::ObjectCreated, this));
    }
    break;

    case Project::ClassID::PERSPECTIVE:
    {
        AddObjectInClassIdMap(object);
        AddressCallbacksOfObject(Project::ClassID::PERSPECTIVE);
    }
    break;
    default:
        break;
    }
}

const std::vector<Core::Data::VisionEngineMode>& CCTVVisionManager::GetAllVisionEngineModes() const
{
    return m_vision_engine_all_modes;
}

void CCTVVisionManager::UpdateView(const std::string &mode_name, size_t view_id, size_t perspective_id)
{
    std::lock_guard<std::recursive_mutex> lock(m_local_mutex);
    std::for_each(m_hubs.begin(), m_hubs.end(), [&](std::shared_ptr<HubWrapper> hub)
    {
        auto canvas_itr = hub->m_canvases.find(mode_name);
        if (canvas_itr != hub->m_canvases.end())
        {
            auto view_itr = m_mode_to_views.find(mode_name);
            if (view_itr != m_mode_to_views.end())
            {
                auto view = std::find_if(view_itr->second.begin(), view_itr->second.end(), [&](Core::View view) { return view.view_id == view_id; });
                if (view != view_itr->second.end())
                {
                    const OS::Lock<Comms::Gateway> LOCK(m_gateway);
                    canvas_itr->second->SetViewPerspective(view->view_id, perspective_id);
                    Trace::GetLogger().STAMP(Trace::VERBOSE) << "Updating Single Perspective ID : " << perspective_id << "  ";
                }
            }
        }
    });
    Trace::GetLogger().STAMP(Trace::VERBOSE) << Trace::EndLog();
    auto view_itr = m_mode_to_canvas.find(mode_name);
    if (view_itr != m_mode_to_canvas.end())
    {
        if (view_itr->second.IsValid())
        {
            const OS::Lock<Comms::Gateway> LOCK(m_gateway);
            Sim::Number canvas_id = view_itr->second.Numbers().Store().Get(view_itr->second.Numbers().Info().GetID(Core::ValueName::Canvas::CANVAS_ID));

            if (m_vision_engine_object.IsValid()) {
                Sim::Number v_eng_canvas_id = m_vision_engine_object.Numbers().Store().Get(m_vision_engine_object.Numbers().Info().GetID(Core::ValueName::VisionEngine::CANVAS_ID));
                v_eng_canvas_id.value = canvas_id.value;
                m_vision_engine_object.Numbers().Store().Set(v_eng_canvas_id);
            }

            if (m_inst_vision_engine_object.IsValid()) {
                Sim::Number inst_v_eng_canvas_id = m_inst_vision_engine_object.Numbers().Store().Get(m_inst_vision_engine_object.Numbers().Info().GetID(Core::ValueName::VisionEngine::CANVAS_ID));
                inst_v_eng_canvas_id.value = canvas_id.value;
                m_inst_vision_engine_object.Numbers().Store().Set(inst_v_eng_canvas_id);
            }
        }
    }
}

void CCTVVisionManager::UpdateView(const std::string &mode_name, std::vector<size_t> &perspective_ids)
{
    std::lock_guard<std::recursive_mutex> lock(m_local_mutex);

    std::for_each(m_hubs.begin(), m_hubs.end(), [&](std::shared_ptr<HubWrapper> hub)
    {
        auto canvas_itr = hub->m_canvases.find(mode_name);
        if (canvas_itr != hub->m_canvases.end())
        {
            auto view_itr = m_mode_to_views.find(mode_name);
            if (view_itr != m_mode_to_views.end() && view_itr->second.size() == perspective_ids.size())
            {
                const OS::Lock<Comms::Gateway> LOCK(m_gateway);
                for (size_t idx = 0; idx < perspective_ids.size(); ++idx)
                {
                    canvas_itr->second->SetViewPerspective(view_itr->second[idx].view_id, perspective_ids[idx]);
                    Trace::GetLogger().STAMP(Trace::VERBOSE) << "Updating Perspective ID : " << perspective_ids[idx] << "  ";
                }
            }
        }
    });
    Trace::GetLogger().STAMP(Trace::VERBOSE) << Trace::EndLog();
    auto view_itr = m_mode_to_canvas.find(mode_name);
    if (view_itr != m_mode_to_canvas.end())
    {
        if (view_itr->second.IsValid())
        {
            const OS::Lock<Comms::Gateway> LOCK(m_gateway);
            Sim::Number canvas_id = view_itr->second.Numbers().Store().Get(view_itr->second.Numbers().Info().GetID(Core::ValueName::Canvas::CANVAS_ID));

            if (m_vision_engine_object.IsValid()) {
                Sim::Number v_eng_canvas_id = m_vision_engine_object.Numbers().Store().Get(m_vision_engine_object.Numbers().Info().GetID(Core::ValueName::VisionEngine::CANVAS_ID));
                v_eng_canvas_id.value = canvas_id.value;
                m_vision_engine_object.Numbers().Store().Set(v_eng_canvas_id);
            }

            if (m_inst_vision_engine_object.IsValid()) {
                Sim::Number inst_v_eng_canvas_id = m_inst_vision_engine_object.Numbers().Store().Get(m_inst_vision_engine_object.Numbers().Info().GetID(Core::ValueName::VisionEngine::CANVAS_ID));
                inst_v_eng_canvas_id.value = canvas_id.value;
                m_inst_vision_engine_object.Numbers().Store().Set(inst_v_eng_canvas_id);
            }
        }
    }
}

void CCTVVisionManager::AddViews(const std::string &mode_name, std::vector<Core::View> views)
{
    m_mode_to_views.insert(std::make_pair(mode_name, views));
    std::for_each(m_hubs.begin(), m_hubs.end(), [&](std::shared_ptr<HubWrapper> hub)
    {
        AddViewsToCanvas(hub, mode_name);
    });
}

void CCTVVisionManager::AddViewsToCanvas(std::shared_ptr<HubWrapper> hub, const std::string &mode_name)
{
    auto itr_canvases = hub->m_canvases.find(mode_name);

    if (itr_canvases != hub->m_canvases.end())
    {
        auto itr_mode_view = m_mode_to_views.find(mode_name);
        if (itr_mode_view != m_mode_to_views.end())
        {
            std::for_each(itr_mode_view->second.begin(), itr_mode_view->second.end(), [&](Core::View v)
            {
                itr_canvases->second->AddView(v);
            });
        }
    }
}

int CCTVVisionManager::GetPerspectiveOfView(const std::string &mode_name, int view_id)
{
    int i_perspective_view_id = -1;

    auto view_itr = m_mode_to_views.find(mode_name);
    if (view_itr != m_mode_to_views.end())
    {
        auto view = std::find_if(view_itr->second.begin(), view_itr->second.end(), [&](Core::View view) { return view.view_id == view_id; });
        if (view != view_itr->second.end())
        {
            i_perspective_view_id = view->perspective_id;
        }
    }

    return i_perspective_view_id;
}

std::vector<Core::View>& CCTVVisionManager::GetView(const std::string &mode_name)
{
    std::vector<Core::View> v;

    auto itr = m_mode_to_views.find(mode_name);
    if (itr != m_mode_to_views.end())
        return itr->second;

    return v;
}

CCTVVisionManager::HubWrapper::HubWrapper(Comms::Object hub_object)
    :m_hub_object(hub_object)
{
}

CCTVVisionManager::HubWrapper::~HubWrapper()
{
}

void CCTVVisionManager::AddObjectInClassIdMap(Comms::Object object)
{
    std::lock_guard<std::recursive_mutex> lock(m_local_mutex);

    size_t class_id = Core::GetClassID(object);
    std::vector<Comms::Object> objectVector;
    auto itrClassObjectVec = m_classid_objects.find(class_id);
    if (itrClassObjectVec == m_classid_objects.end())
    {
        objectVector.push_back(object);
        m_classid_objects[class_id] = objectVector;
    }
    else
    {
        itrClassObjectVec->second.push_back(object);
    }
}

int CCTVVisionManager::GetPerspectiveId(const std::string &perspective_name)
{
    std::lock_guard<std::recursive_mutex> lock(m_local_mutex);

    int iPerspectivesId = -1;
    auto classid_object_pair = m_classid_objects.find(Project::ClassID::PERSPECTIVE);
    if (classid_object_pair != m_classid_objects.end())
    {
        for (auto &object : classid_object_pair->second)
        {
            if (object.GetName().compare(perspective_name) == 0)
            {
                const OS::Lock<Comms::Gateway> LOCK(m_gateway);
                iPerspectivesId = static_cast<int>(object.Numbers().Store().Get(object.Numbers().Info().GetID(Project::ValueName::Perspective::PERSPECTIVE_ID)).value);
                break;
            }
        }
    }

    return iPerspectivesId;
}

void CCTVVisionManager::AddObjectCreationCallback(size_t class_id, const Object_Callback_t &cb)
{
    std::lock_guard<std::recursive_mutex> lock(m_local_mutex);

    auto callback_data_itr = map_class_id_creation_callback.find(class_id);
    if (callback_data_itr == map_class_id_creation_callback.end())
    {
        std::vector<Object_Callback_t *> callbacks;
        callbacks.push_back(cb.Clone());
        map_class_id_creation_callback.insert(std::make_pair(class_id, callbacks));
    }
    else
    {
        callback_data_itr->second.push_back(cb.Clone());
    }
}

void CCTVVisionManager::AddressCallbacksOfObject(size_t class_id)
{
    std::lock_guard<std::recursive_mutex> lock(m_local_mutex);

    auto itrObjectCallback = map_class_id_creation_callback.find(class_id);
    if (itrObjectCallback != map_class_id_creation_callback.end())
    {
        for_each(itrObjectCallback->second.begin(), itrObjectCallback->second.end(), [&](Object_Callback_t *cb)
        {
            (*cb)(class_id);
        });
    }
}
