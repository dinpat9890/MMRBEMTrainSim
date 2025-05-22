//*****************************************************************************
//
// @file       DVAUnit.cpp
//
//             Defines the DVA Unit. It listens request from PIS to play sound & form a sound request & create object under audio enginges to play sound
//              It also mute & stop announcements as per request from PIS
//
//  Reference:      https://adl-atlassian.simulation.lan/confluence/display/BJSNA/PIS+-+Implementation
//
// @ingroup    DVAUnit
//
// @author     Yogesh Warad
//
// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2017
//
//*****************************************************************************

#include "DVAUnit.h"
#include <thread>
#include "core_types/SessionData.h"
#include "project_comms_structure/ProjectObjectConstants.h"
#include "core_comms_structure/CoreObjectDefinition.h"
#include "world_api/TrainPathWatcher.h"
#include "world_api/WorldAccess.h"
#include "DVAAudioConfigHandler.h"

// From the common DLL files
#include "train_types/InitializationTypes.h"
using Initialization::Insert;

#include "Utility/Utilities.h"

#include "Common/StandardLogging.h"
#include "DVAUnit.h"

#include "PISConstants.h"
#include "file_access/FileUtilities.h"
#include "source/protobuf/PISprotos.pb.h"

using namespace dva;

// Anonymous namespace for local constants
namespace dva
{
    //   Constants
    const double PERIOD                = 0.5;
    const double REQUEST_FREQUENCY     = 20.0;
    int          MAX_VOLUME            = 100 ; 
    const int    MEDIUM_DEBUG_LOGGING  = 9 ;  // is set to any number less than 10 
    const int    FULL_DEBUG_LOGGING    = 99 ; // is set to any number less than 100 
   
    //  Function:       SetOnChange
    //
    //  Description:    Change the comms number if the value has changed
    //
    //  Parameters:
    //      Comms::Object object - The object containing the number
    //      Sim::Number::ID id - The id of the comms number
    //      int value        - The value to change to

    void SetOnChange(Comms::Object object, Sim::Number::ID id, int value)
    {
        Sim::Number num = object.Numbers().Store().Get(id);
        if(object.IsValid() && value != num.value)
        {
            num.value = value;
            object.Numbers().Store().Set(num);
        }
    }

    /// Helper function to make the serialization of strings syntactically nicer.
    ///
    /// @param s The string to convert into a Raw, probably produced by protobuf
    ///
    /// @return The corresponding byte array, to use within a raw

    Sim::Raw::Type StringToRaw(const std::string &s)
    {
        if(!s.empty())
            return Sim::Raw::Type(reinterpret_cast<const unsigned char *>(&*s.begin()), reinterpret_cast<const unsigned char *>(&*s.begin()) + s.size());
        return Sim::Raw::Type();
    }

    //  Function:       SetTextOnChange
    //
    //  Description:    Change the comms Raw if the String has changed
    //
    //  Parameters:
    //      Comms::Object object  - The object containing the Raw
    //      Sim::Raw::ID id - The id of the comms Raw
    //      std::string old_value - The Old value to compare with
    //      std::string new_value - The value to change to

    void SetTextOnChange(Comms::Object object, Sim::Raw::ID id, std::string &old_value, const std::string &new_value)
    {
        Sim::Raw raw = object.Raws().Store().Get(id);
        if(object.IsValid() && new_value != old_value)
        {
            old_value = new_value;
            raw.value = StringToRaw(new_value);
            object.Raws().Store().Set(raw);
        }
    }

    //  Function:       DecodeDVAPLayCommand
    //
    //  Description:    Deserializes a DVAPlayCommand from an array of bytes.
    //
    //  Parameters:
    //      const std::vector<unsigned char> &data - The array of bytes.
    //
    //  Return value:
    //      DVAPlayCommand        - The corresponding command.

    DVAPlayCommand DecodeDVAPlayCommand(const std::vector<unsigned char> &data)
    {
        DVAPlayCommand ret;

        dva::DvaPlayList dva_playlist;
        dva_playlist.ParseFromArray(&data[0], data.size());

        ret.loop = dva_playlist.loop();
        ret.title = dva_playlist.pid_text();

        // No Auto here as protobuf does not use STL containers
        for (int i = 0; i < dva_playlist.message_ids_size(); ++i)
        {
            ret.audio_ids.push_back(dva_playlist.message_ids(i));
        }

        return ret;
    }

    //  Function:       EncodeDVAPlayCommand
    //
    //  Description:    Serializes a DVAPlayCommand from an array of bytes.
    //
    //  Parameters:
    //      play_command Object.
    //
    //  Return value:
    //      std::vector<unsigned char> dva_playlist.ByteSize - The array of bytes.

    std::vector<unsigned char> EncodeDVAPlayCommand(DVAPlayCommand &play_command)
    {
        dva::DvaPlayList dva_playlist;

        dva_playlist.set_loop(play_command.loop);
        dva_playlist.set_pid_text(play_command.title);

        for (auto it = play_command.audio_ids.begin(); it!= play_command.audio_ids.end(); ++it)
        {
            dva_playlist.add_message_ids(*it);
        }

        std::vector<unsigned char> ret(dva_playlist.ByteSize());
        if (!dva_playlist.SerializeToArray(&ret[0], ret.size()))
        {
            //Error here
        }
        return ret;
    }


/// Constructor, where we initialize members, record the states we are interested in, set up our
/// watcher to watch for, and hook up callbacks.
///
/// @param gateway       The gateway to use.
/// @param data_access   The data access object to use.
/// @param world_access  The world access object to use.
/// @param path_watcher  The path watcher to use, which will automatically be hooked up to watch
///                      the correct train - we just remember it and use it to get our path.
/// @param session_data  session data object 
/// @param points_watcher  point watcher object 

DVAUnit::DVAUnit(Comms::Gateway &gateway, const std::shared_ptr<dva::Properties>&  pis_properties)
    : Comms::SteppingUnit(gateway), 
    m_dva_command_queue_id(Sim::INVALID_OBJECT), 
    m_dva_has_power(true),
    m_cab_speaker_volume(MAX_VOLUME),
    m_cab_muted(false),
    m_pis_properties(pis_properties),
    m_dva_debug_level(100/* Assign it m_properties.GetDVADebugLevel(). Originally it was const TrainModelApplication::Properties &properties*/), 
    m_dva_debug_enabled(1/*m_properties.IsDVADebugEnabled()*/), 
    m_station_broadcast_path(""/*m_properties.GetDVAStationBroadcastPath()*/),
    m_emergency_broadcast_path(""/*m_properties.GetDVAEmergBroadcastDataPath()*/),
    m_pis(),
    m_pis_outputs_object(), 
    m_dva_test_id(Sim::INVALID_OBJECT), 
    m_power_state_id(Sim::INVALID_OBJECT),
    m_unhandled_audio_managers(), 
    m_sound_managers(),
    m_dva_command_queue()
{
    Trace::GetLogger().STAMP(Trace::VERBOSE) << __FUNCTION__ << Trace::EndLog();
    m_dva_audio_handler.reset(new dva::DVAAudioConfigHandler() );
    std::string xml_file = m_pis_properties->GetStationListFile();

    FileAccess::XMLReader xml_reader(*m_dva_audio_handler);
    xml_reader.Read(xml_file.c_str());    
    if(xml_reader.AnyErrors())    
    {        
        Trace::GetLogger().STAMP(Trace::ERR) << "Reading the Station List xml file '"  << xml_file << "' Error : " << xml_reader.GetErrorLog() << Trace::EndLog();    
    }

    if(m_station_broadcast_path.size() == 0)
    {
        Trace::GetLogger().STAMP(Trace::INFO) << "Assign appropriatly" << m_station_broadcast_path << Trace::EndLog();
    }

    OS::Lock<Comms::Gateway> lock(gateway);
    Comms::AddCreationCallback(gateway.GetRootObject(), MakeCallback(&DVAUnit::ObjectCreated, this));

    m_command_listener.AddCallback(MakeCallback(&DVAUnit::DVACommandCallback, this));
    m_dva_stop_listener.AddCallback(MakeCallback(&DVAUnit::DVAStopCallback, this));
    m_dva_mute_listener.AddCallback(MakeCallback(&DVAUnit::DVAMuteCallback, this));

}

/// Everything automatically cleans up except for our watcher which we hooked up to the
/// root object and need to remove from it now.
void DVAUnit::ObjectCreated(Comms::Object object)
{
    Trace::GetLogger().STAMP(Trace::VERBOSE) << __FUNCTION__ << Trace::EndLog();
    
    std::unique_lock<std::mutex> callback_lock(m_mutex);

    // Determine the class id of this object
    int class_id = Core::GetClassID(object);

    if(class_id == Core::ClassID::WORLD)
    {
        Comms::AddCreationCallback(object, MakeCallback(&DVAUnit::ObjectCreated, this));
    }
    if(class_id == Project::ClassID::HUB)
    {         
        // Add a child creation callback for audio engine
        m_hub_objects.push_back(object);
        Comms::AddCreationCallback(object, MakeCallback(&DVAUnit::ObjectCreated, this));
        Comms::AddDestructionCallback(object, MakeCallback(&DVAUnit::HubDestructionCallback, this));
    }
    if(class_id == Project::ClassID::AUDIO_ENGINE)
    {    
            // Check if the PIS Adjunct object is created
            if(m_pis.IsValid()) 
            {
                // Create a DVA Sound Manager for this AudioEngine
                CreateDVASoundManager(object);
            }
            else
            {                        
                // Store this audio engine until TISAdjunct object has been created 
                m_unhandled_audio_managers.push_back(object);
            }

            Comms::AddCreationCallback(object, MakeCallback(&DVAUnit::ObjectCreated, this));

            // Add destruction callback
            Comms::AddDestructionCallback(object, MakeCallback(&DVAUnit::AudioEngineDestructionCallback, this));
       
    }
    // If this is a train then we need to create a train watcher for it
    else if(class_id == Train::ClassID::TRAIN)
    {
        Comms::AddCreationCallback(object, MakeCallback(&DVAUnit::ObjectCreated, this));
    }
    else if(class_id == Project::ClassID::VEHICLE)
    {
        Comms::AddCreationCallback(object, MakeCallback(&DVAUnit::ObjectCreated, this));
    }
    else if(class_id == Project::ClassID::PIS)
    {
        Comms::AddCreationCallback(object, MakeCallback(&DVAUnit::ObjectCreated, this));
        m_pis = object;
        TrainChildCallback(object); // Import TrainChildCreated function over here
    }
    else if (class_id == Project::ClassID::DVA)
    {
        Comms::AddCreationCallback(object, MakeCallback(&DVAUnit::ObjectCreated, this));
    }
    else if(class_id == Project::ClassID::PIS_OUTPUTS)         
    {
        Comms::AddCreationCallback(object, MakeCallback(&DVAUnit::ObjectCreated, this));

        // Register a callback function for the DVA Command Tray listener
        m_pis_outputs_object = object;
        m_dva_command_queue_id  = m_pis_outputs_object.Trays().Info().GetID(Project::ValueName::PISOutputs::DVA_COMMAND_QUEUE);
        Sim::TrayInfo info = m_pis_outputs_object.Trays().Info().GetInfo(m_dva_command_queue_id);
        m_pis_outputs_object.Trays().Store().Request(info,REQUEST_FREQUENCY);
        m_pis_outputs_object.Trays().Store().AddListener(m_command_listener);

        m_dva_stop_id  = m_pis_outputs_object.Numbers().Info().GetID(Project::ValueName::PISOutputs::DVA_STOP);
        Sim::NumberInfo numinfo = m_pis_outputs_object.Numbers().Info().GetInfo(m_dva_stop_id);
        m_pis_outputs_object.Numbers().Store().Request(numinfo,REQUEST_FREQUENCY);
        m_pis_outputs_object.Numbers().Store().AddListener(m_dva_stop_listener);

        m_dva_mute_id  = m_pis_outputs_object.Numbers().Info().GetID(Project::ValueName::PISOutputs::DVA_MUTE);
        numinfo = m_pis_outputs_object.Numbers().Info().GetInfo(m_dva_mute_id);
        m_pis_outputs_object.Numbers().Store().Request(numinfo,REQUEST_FREQUENCY);
        m_pis_outputs_object.Numbers().Store().AddListener(m_dva_mute_listener);
    }
    else if (class_id == Project::ClassID::DVA)
    {
        Comms::AddCreationCallback(object, MakeCallback(&DVAUnit::ObjectCreated, this));
    }
    else if (class_id == Project::ClassID::DVA_OUTPUTS)
    {
        Comms::AddCreationCallback(object, MakeCallback(&DVAUnit::ObjectCreated, this));

        // Get comms properties id.
        m_dva_outputs_object = object;
        m_dva_started_id = m_dva_outputs_object.Trays().Info().GetID(Project::ValueName::DVAOutputs::DVA_STARTED);
        m_dva_stopped_id = m_dva_outputs_object.Trays().Info().GetID(Project::ValueName::DVAOutputs::DVA_STOPPED);
    }
}

DVAUnit::~DVAUnit()
{
    Trace::GetLogger().STAMP(Trace::VERBOSE) << __FUNCTION__ << Trace::EndLog();

    // Remove audio engine callbacks and destroy sound managers
    for(size_t i = 0 ; i < m_sound_managers.size(); ++i)
    {
        if(m_sound_managers[i].first.IsValid())
        {
            m_sound_managers[i].first.Invalidate();
        }

        // Free DVA Sound Manager memory
        if(m_sound_managers[i].second)
        {
            delete m_sound_managers[i].second;
            m_sound_managers[i].second = NULL;
        }
    }
    m_sound_managers.clear();

    // Detach our feature watcher while we can still get the mutex
    OS::Lock<Comms::Gateway> lock(GetGateway());

    m_command_listener.RemoveAllCallbacks();
    m_dva_stop_listener.RemoveAllCallbacks();
    m_dva_mute_listener.RemoveAllCallbacks();

    //m_path_watcher.RemoveTrainCreationCallback(MakeCallback(&DVAUnit::TrainCreationCallback, this)); TODO:

    // Remove PIS Interface callbacks
    if(m_pis_outputs_object.IsValid())
    {
        //m_pis.RemoveDestructionCallback(MakeCallback(&DVAUnit::TrainChildDestructionCallback, this)); TODO:
        m_pis.Invalidate();
    }

    // Remove DACU Interface callbacks
    if(m_dacu.IsValid())
    {
        //m_dacu.RemoveDestructionCallback(MakeCallback(&DVAUnit::TrainChildDestructionCallback, this));TODO:
        m_dacu.Invalidate(); 
    }

    // Remove hub callbacks
    for(size_t i=0; i<m_hub_objects.size(); ++i)
    {
        if(m_hub_objects[i].IsValid())
        {
            //m_hub_objects[i].RemoveCreationCallback(MakeCallback(&DVAUnit::HubChildCreationCallback, this)); TODO:
            m_hub_objects[i].Invalidate();
        }
    }

    // Optional:  Delete all global objects allocated by libprotobuf.
    google::protobuf::ShutdownProtobufLibrary();

    // Remove root callbacks
    //if(GetGateway().GetRootObject().IsValid())
        //GetGateway().GetRootObject().RemoveCreationCallback(MakeCallback(&DVAUnit::RootChildCreationCallback, this));

    if(m_dva_debug_enabled)
        Trace::GetLogger().STAMP(Trace::VERBOSE) << "DVA Unit Destructed" << Trace::EndLog();

    //m_path_watcher.RemoveTrainCreationCallback(MakeCallback(&DVAUnit::TrainCallback, this)); TODO:

    m_watcher.Detach();
}

/// Returns a string holding the name of this unit.
std::string DVAUnit::GetName() const
{
    return "DVA Unit";
}

/// Called cyclically.
///
/// @param new_time  The time that this RunCycle corresponds to.

void DVAUnit::Step(double new_time)
{
    // Update our model. Make sure that we have the lock
    std::ostringstream msg;
    OS::Lock<Comms::Gateway> lock(GetGateway());
    //SetUnitTime(new_time);

    try
    {
        // Process the DVA command queue 
        if(m_pis.IsValid())
        {
            // Process DVA Commands (1 per run cycle)
            if(!m_dva_command_queue.empty())
            {
                // Throw away commands if there is no Audio Engine yet
                if (m_sound_managers.empty())
                {
                    if(m_dva_debug_enabled)
                    {
                        // Get a reference to the front queue element
                        DVAPlayCommand play_command(m_dva_command_queue.front());

                        Trace::GetLogger().STAMP(Trace::WARN) << "Discarding DVA play command \"" << play_command.title << "\" due to no Audio Engine" << Trace::EndLog();
                    }

                    // Pop the queue
                    m_dva_command_queue.pop();
                }
                // Only Queue Sounds on the Audio Engine if there are less than 2 currently queued.
                // See Bug 18621 - We are tying to use a minimum number of Audio Slots here.
                // By processing a maximum of 2 sounds onto the Audio engine at a time we can leave the
                // rest on the command queue until the Audio engine has finshed playing the last sound.
                // We can then load the next sound of the queue while the audio engine plays the next
                // sound in its own queue.
                else if (m_sound_managers[0].second /*&& m_sound_managers[0].second->GetSoundQueueSize() < 2*/)
                {
                    // Get a reference to the front queue element
                    DVAPlayCommand play_command(m_dva_command_queue.front());

                    if(m_dva_debug_enabled)
                        msg << "Processing DVA play command \"" << play_command.title << "\" - There are " << m_dva_command_queue.size() << " Sounds on the command Queue";

                    // Map each audio file ID to the corresponding audio file

                     std::vector<std::string> file_names;

					std::vector<int>::iterator id_iter = play_command.audio_ids.begin();

					for( ; id_iter != play_command.audio_ids.end(); ++ id_iter)
					{   
						std::string file_name = m_station_broadcast_path + m_dva_audio_handler->GetAudioFileName(*id_iter);
                        file_names.push_back(file_name);

                        if (m_dva_debug_enabled)
                            msg << "Processing DVA play file \"" << file_name << "\".";
                    }

                    if(m_dva_debug_enabled)
                        Trace::GetLogger().STAMP(Trace::INFO) << msg.str() << Trace::EndLog();

                    // Hand over the DVA command to the sound manager(s)
                    if(!file_names.empty())
                    {
                        for(size_t i=0 ; i<m_sound_managers.size(); ++i)
                        {
                            try
                            {
                            if(m_sound_managers[i].second)
                                m_sound_managers[i].second->AddDVASound(play_command.title, file_names, play_command.loop);
                            }
                            catch (InvalidParameterException &e)
                            {
                                Trace::GetLogger().STAMP(Trace::ERR) << "Exception thrown in run cycle : " << e.GetDescription() << Trace::EndLog();
                            }
                        }
                    }
                    else
                    {
                        Trace::GetLogger().STAMP(Trace::WARN) << "No valid audio files defined for DVA message \""
                            << play_command.title << "\" Ignoring invalid DVA message." << Trace::EndLog();
                    }

                    // Pop the queue
                    m_dva_command_queue.pop();
                }
            }

            // Hack - Update the PIS DVA Status and PID Text with the first sound manager.
            //        If there are any others they are playing the same messages as the first one.
            if (!m_sound_managers.empty())
            {
                if (m_sound_managers[0].second && m_pis.IsValid())
                {    
                    try
                    {
                        if(m_dva_status_id != Sim::INVALID_NUMBER)
                            SetOnChange(m_pis, m_dva_status_id, m_sound_managers[0].second->GetSoundQueueSize());
                    }
                    catch (InvalidParameterException &e)
                    {
                        Trace::GetLogger().STAMP(Trace::ERR) << "Exception thrown in run cycle : " << e.GetDescription() << Trace::EndLog();
                    }
                }

                // Let DVA Sound Managers process any queued DVA Sounds
                for(size_t i=0 ; i<m_sound_managers.size(); ++i)
                {
                    if(m_sound_managers[i].second)
                    {
						//std::lock_guard lock(m_sound_managers[i].second->GetSoundStateMutex());
						//if (m_sound_managers[i].second->GetSoundState() == 0)
							m_sound_managers[i].second->Process();
                    }
                } 
            }
        }
    }
    catch (InvalidParameterException &e)
    {
        Trace::GetLogger().STAMP(Trace::ERR) << "Exception thrown in run cycle : " << e.GetDescription() << Trace::EndLog();
    }
    catch (...)
    {
        Trace::GetLogger().STAMP(Trace::ERR) << "Unknown Exception thrown in run cycle : " << Trace::EndLog();
    }
}

/// Called by SimpleUnit, this returns the desired period for RunCycle() to be called at.

double DVAUnit::GetNextPeriod() const
{
    return PERIOD;
}

///
/// @param object  This is the function called whenever train object is created . 
///

void DVAUnit::TrainCallback(Comms::Object object)
{
    //TODO:
    //Project::ObjectDefinition pis_def = Project::GetObjectDefinition(Project::ClassID::PIS);
    //object.CreateChild(ConvertToCommsObjectDefinition(pis_def));
}

//  Function:       DVAUnit::TrainCreationCallback
//
//  Description:    This is set up in the constructor to be called when the
//                  train watcher finds the scenario train. 
//
//  Parameters:
//      Comms::Object object - This is the train object that we are interested in.

void DVAUnit::TrainCreationCallback(Comms::Object object)
{
    Trace::GetLogger().STAMP(Trace::VERBOSE) << __FUNCTION__ << Trace::EndLog();
    // Register for Train Child Creation
    Comms::AddCreationCallback(object, MakeCallback(&DVAUnit::TrainChildCallback,this));  
}

//  Function:       DVAUnit::RootChildCreationCallback
//
//  Description:    Root child callback function. If this is a Hub we add a 
//                  child creation callback to be notified of Audio Engine 
//                  object creation.
//
//  Parameters:
//      Comms::Object object - Root child object.

void DVAUnit::RootChildCreationCallback(Comms::Object object)
{
    Trace::GetLogger().STAMP(Trace::VERBOSE) << __FUNCTION__ << Trace::EndLog();
    // We are only interested in the Hub which is the parent of Audio Engines
    if(Core::GetClassID(object) == Project::ClassID::HUB)
    {         
        // Add a child creation callback for audio engine
        m_hub_objects.push_back(object);
        Comms::AddCreationCallback(object, MakeCallback(&DVAUnit::HubChildCreationCallback, this));
        Comms::AddDestructionCallback(object, MakeCallback(&DVAUnit::HubDestructionCallback, this));
    }
}

//  Function:       DVAUnit::HubDestructionCallback
//
//  Description:    Destruction callback function for hub objects. Just 
//                  invalidate our local object.
//
//  Parameters:
//      Comms::Object object - Hub object.

void DVAUnit::HubDestructionCallback(Comms::Object object)
{
    Trace::GetLogger().STAMP(Trace::VERBOSE) << __FUNCTION__ << Trace::EndLog();

    // Invalidate our local object to prevent it being used in the destructor.
    for(size_t i=0; i<m_hub_objects.size(); ++i)
    {
        if(m_hub_objects[i] == object && m_hub_objects[i].IsValid())
        {
            m_hub_objects[i].Invalidate();
            break;
        }
    }
}

//  Function:       DVAUnit::HubChildCreationCallback
//
//  Description:    Hub child callback function. If this is an Audio Engine we 
//                  attempt to create a DVA Sound Manager.
//
//  Parameters:
//      Comms::Object object - Hub child object.

void DVAUnit::HubChildCreationCallback(Comms::Object object)
{
    Trace::GetLogger().STAMP(Trace::VERBOSE) << __FUNCTION__ << Trace::EndLog();
    // We are only interested in the Hub which is the parent of Audio Engines

    if(Core::GetClassID(object) == Project::ClassID::AUDIO_ENGINE)
    {    
        // Only register the Audio Engines that we have configured.
        // Check if the TIS Adjunct object is created
        if(m_pis.IsValid()) 
        {
            // Create a DVA Sound Manager for this AudioEngine
            CreateDVASoundManager(object);
        }
        else
        {                        
            // Store this audio engine until TISAdjunct object has been created 
            m_unhandled_audio_managers.push_back(object);
        }

        // Add destruction callback
        Comms::AddDestructionCallback(object, MakeCallback(&DVAUnit::AudioEngineDestructionCallback, this));
    }
}

//  Function:       DVAUnit:CreateDVASoundManager
//
//  Description:    Creates a DVA Sound Manager Unit for the given audio engine. The manager is 
//                  only created if both the TISAdjunct object and the AudioEngine object are 
//                  valid.
//
//  Parameters:
//      const Comms::Object &tis_adjunct_object - TISAdjunct comms object
//      const Comms::Object &audio_engine_object - AudioEngine comms object
//
//  Return value:
//      bool        Flag indicating if creation of DVA Sound Manager succeeded or failed

void DVAUnit::CreateDVASoundManager(const Comms::Object &audio_engine_object)
{
    Trace::GetLogger().STAMP(Trace::VERBOSE) << __FUNCTION__ << Trace::EndLog();

    if(m_pis.IsValid() && audio_engine_object.IsValid())
    {
        try
        {
            // Create a DVA Sound Manager for this Audio Engine
            std::unique_ptr<DVASoundManager> mgr(new DVASoundManager(GetGateway(), audio_engine_object, m_pis, m_dva_outputs_object, *m_pis_properties));

            m_sound_managers.push_back(std::make_pair(audio_engine_object, mgr.release())); 
        }
        catch(InvalidParameterException &e)
        {
            e.AddStackTrace(FLSTAMP, "Failed to create DVA Sound Manager.");
            Trace::g_plog->LogException(e);
        }
    }
    else
    {
        if(m_dva_debug_enabled)
            Trace::GetLogger().STAMP(Trace::ERR) << "Failed to create DVA Sound Manager! tis_adjunct is invalid!" << Trace::EndLog();
    }
}

//  Function:           DVAUnit::AudioEngineDestructionCallback
//
//  Description:        Cleanup when an Audio Engine object is destroyed
//
//  Parameters:
//      Comms::Object object - The object being destroyed

void DVAUnit::AudioEngineDestructionCallback(Comms::Object object)
{
    Trace::GetLogger().STAMP(Trace::VERBOSE) << __FUNCTION__ << Trace::EndLog();

    std::unique_lock<std::mutex> callback_lock(m_mutex);

    if(m_dva_debug_level > FULL_DEBUG_LOGGING)
        Trace::GetLogger().STAMP(Trace::INFO) << "AudioEngine Object Destruction" << Trace::EndLog();

    // Delete the DVA Sound Manager for this audio engine
    std::vector< std::pair<Comms::Object, DVASoundManager *> >::iterator iter = m_sound_managers.begin();
    for(; iter != m_sound_managers.end(); ++iter)
    {
        if(iter->first == object)
        {    
            iter->first.Invalidate();

            // Destroy DVA Sound manager and remove element from map
            if(iter->second)
            {
                if(m_dva_debug_level > FULL_DEBUG_LOGGING)
                    Trace::GetLogger().STAMP(Trace::INFO) << "Erasing sound manager for Audio ID " << iter->second->GetAudioEngineID() << Trace::EndLog();

                delete iter->second;
                iter->second = NULL;
            }

            m_sound_managers.erase(iter);
            break;
        }
    }
}

//  Function:       DVAUnit::TrainChildCallback
//
//  Description:    This is set up to detect the creation of child objects of the 
//                  scenario train.
//
//  Parameters:
//      Comms::Object object - This is the child object that has been created

void DVAUnit::TrainChildCallback(Comms::Object object)
{
    Trace::GetLogger().STAMP(Trace::VERBOSE) << __FUNCTION__ << Trace::EndLog();    

    // We are interested in the PIS object
    if(Core::GetClassID(object) == Project::ClassID::PIS)
    {
        try
        {
            m_pis = object;

            if(m_dva_debug_level > FULL_DEBUG_LOGGING)
                Trace::GetLogger().STAMP(Trace::INFO) << "PIS Interface Object Creation" << Trace::EndLog();

            // Create a DVA Sound Manager for any AudioEngines that have already been created
            for(size_t i=0 ; i<m_unhandled_audio_managers.size(); ++i)
            {
                if(m_dva_debug_level > FULL_DEBUG_LOGGING)
                    Trace::GetLogger().STAMP(Trace::INFO) << "Delayed Soundmanager Object Creation" << Trace::EndLog();

                // Audio engine without DVA sound manager
                CreateDVASoundManager(m_unhandled_audio_managers[i]);
            }

            m_unhandled_audio_managers.clear();
        }
        catch(InvalidParameterException &e)
        {
            e.AddStackTrace(FLSTAMP, "Failed to process PIS creation.");
            Trace::g_plog->LogException(e);
        }
    }
}

//  Function:       DVAUnit::GetVolume
//
//  Description:    Get The Volume setting for the DVA.
//
//  Return:
//          int - The Volume (0 if muted, else the current Cab volume)
//   
int DVAUnit::GetVolume()
{
    if (m_cab_muted)
        return 0;
    else
        return static_cast<int>(m_cab_speaker_volume);
}

//  Function:           DVAUnit::DVACommandCallback
//
//  Description:        Callback function for TISAdjunct Tray object changes.
//                      Process change if it is a DVA command change.
//
//  Parameters:
//      const Sim::Tray &tray - The tray object that changed

void DVAUnit::DVACommandCallback(const Sim::Tray &tray_obj)
{
    Trace::GetLogger().STAMP(Trace::VERBOSE) << __FUNCTION__ << Trace::EndLog();

    if(m_dva_debug_level > MEDIUM_DEBUG_LOGGING)
        Trace::GetLogger().STAMP(Trace::INFO) << "DVA Command Received." << Trace::EndLog();
    
    std::unique_lock<std::mutex> callback_lock(m_mutex);

    // Only interested in DVA commands
    if(tray_obj.id == m_dva_command_queue_id && !tray_obj.value.empty())
    {
        // Ensure the DVA unit is functional, otherwise just ignore any new DVA commands
        // Hardcoded value for testing purpose only
        if(m_dva_has_power)
        {
            // Add the messages to the queue to be processed during a RunCycle.
            for (auto &msg : tray_obj.value)
            {
                try
                {
                    if(msg.type == DVACommandType::PLAY_MSG)
                    {
                        if(m_dva_debug_level > MEDIUM_DEBUG_LOGGING)
                        {
                            Trace::GetLogger().STAMP(Trace::INFO) << "Play command received from tray" << Trace::EndLog();
                        }

                        // Push new commands on to the queue.
                        m_dva_command_queue.push(DecodeDVAPlayCommand(msg.data));

                    }
                    else if(msg.type == DVACommandType::STOP_MSG)
                    {
                        if(m_dva_debug_level > MEDIUM_DEBUG_LOGGING)
                            Trace::GetLogger().STAMP(Trace::INFO) << "Stop command received from tray" << Trace::EndLog();

                        // Empty DVA Play command queue and stop any DVA messages playing
                        StopDVA();
                    }
                    else
                    {
                        Trace::GetLogger().STAMP(Trace::ERR) << "Unknown Command Type received on DVA Command Tray -> " << msg.type << Trace::EndLog();
                    }
                }
                catch (InvalidParameterException &e)
                {
                    e.AddStackTrace(FLSTAMP, "Error Processing DVA Command");
                    Trace::g_plog->LogException(e);
                }
            }
        }
        else
        {
            if(m_dva_debug_enabled)
                Trace::GetLogger().STAMP(Trace::INFO) << "Command discarded as DVA has no power" << Trace::EndLog();

        }

        // Remove the tray items in comms. This will cause this function to be triggered again, 
        // which is why there is a guard against the empty case right at the start.
        if(m_pis.IsValid())
            m_pis_outputs_object.Trays().Store().Remove(tray_obj.id, tray_obj.value.begin(), tray_obj.value.end());
    }
}

void DVAUnit::DVAStopCallback(const Sim::Number &num_obj)
{
    Trace::GetLogger().STAMP(Trace::VERBOSE) << __FUNCTION__ << Trace::EndLog();

    if (num_obj.id == m_dva_stop_id)
    {
       auto dva_stop = (num_obj.value > 0.0);

        if(dva_stop)
        {
            if(m_dva_debug_enabled)
                Trace::GetLogger().STAMP(Trace::INFO) << "DVA has power." << Trace::EndLog();
            StopDVA();
        }
    }
}

//  Function:           DVAUnit::DVAMuteCallback
//
//  Description:        Callback function for mute/unmute
//
//  Parameters:
//      const Sim::Tray &tray - The tray object that changed

void DVAUnit::DVAMuteCallback(const Sim::Number &num_obj)
{
   Trace::GetLogger().STAMP(Trace::VERBOSE) << __FUNCTION__ << Trace::EndLog();

   std::unique_lock<std::mutex> callback_lock(m_mutex);

    if(num_obj.id == m_dva_mute_id)
    {
        m_cab_muted = num_obj.value > 0;

        Trace::GetLogger().STAMP(Trace::INFO) << "Mute Changed To " 
                                              << (m_cab_muted?"ON":"OFF")
                                              << Trace::EndLog();

        if(!m_sound_managers.empty())
        {
            // Propagate the mute request to the managers
            for(size_t i=0; i<m_sound_managers.size(); ++i)
            {
                if(m_sound_managers[i].second)
                    m_sound_managers[i].second->SetVolume(GetVolume());
            }
        }
    }

}

//  Function:           DVAUnit::PisInterfaceNumberCallback
//
//  Description:        Callback function for PIS Interface object changes.
//                      Process change if it is a DVA Test Number change.
//
//  Parameters:
//      const Sim::Tray &tray - The tray object that changed

void DVAUnit::PisInterfaceNumberCallback(const Sim::Number &num_obj)
{
    Trace::GetLogger().STAMP(Trace::VERBOSE) << __FUNCTION__ << Trace::EndLog();

    std::unique_lock<std::mutex> callback_lock(m_mutex);

    // Only interested in DVA commands
    if(num_obj.id == m_dva_test_id)
    {
        // Get the new DVA Test command number
        try
        {
            DVAPlayCommand play_command;
            int test_command = static_cast<int>(m_pis.Numbers().Store().Get(m_dva_test_id));

            if (test_command >= 1000 && test_command <= 2099)
            {
                Trace::GetLogger().STAMP(Trace::INFO) << "DVA Test value " << test_command << " Received " << Trace::EndLog();

                Sim::Message msg;
                msg.type = 0;
                msg.time_stamp = GetGateway().GetTiming().system_time;
                msg.id = 0;           

                if(test_command == 1000)
                {
                    msg.type = DVACommandType::STOP_MSG;
                }
                else if (test_command < 2000)
                {
                    int message_id = test_command - 1000;

                    play_command.audio_ids.push_back(message_id);
                    play_command.title = "Unknown Message";

                    // Find the message if it exists  
                    auto itt = m_message_map.find(message_id);
                    if (itt != m_message_map.end())
                    {
                        play_command.title = itt->second.second;
                        play_command.loop  = false;
                    }
                    msg.type = DVACommandType::PLAY_MSG;
                    msg.data = EncodeDVAPlayCommand(play_command);
                }
                // Test Looped Messages
                else if (test_command < 3000)
                {
                    int message_id = test_command - 2000;

                    play_command.audio_ids.push_back(message_id);
                    play_command.title = "Unknown Message";

                    // Find the message if it exists  
                    auto itt = m_message_map.find(message_id);
                    if (itt != m_message_map.end())
                    {
                        play_command.title = itt->second.second;
                        play_command.loop = true;
                    }
                    msg.type = DVACommandType::PLAY_MSG;
                    msg.data = EncodeDVAPlayCommand(play_command);
                }

                // Send the DVA Command to the tray
                if (msg.type > 0)
                {
                    m_pis.Trays().Store().Send(m_dva_command_queue_id, msg);
                }
            }
        }
        catch (InvalidParameterException &e)
        {
            e.AddStackTrace(FLSTAMP, "Error Processing DVA Test Nuber change");
            Trace::g_plog->LogException(e);
        }

    }
}

//  Function:       DVAUnit::StopDVA
//
//  Description:    Function for deleting all queued DVA messages and stop any 
//                  DVA message that is being played.

void DVAUnit::StopDVA()
{
    Trace::GetLogger().STAMP(Trace::VERBOSE) << __FUNCTION__ << Trace::EndLog();

    if(m_dva_debug_enabled)
        Trace::GetLogger().STAMP(Trace::INFO) << "Stop DVA - " << m_dva_command_queue.size() << " commands deleted" << Trace::EndLog();

    // Empty the DVA play command queue
    while(!m_dva_command_queue.empty())
        m_dva_command_queue.pop();

    // Instruct the DVASoundManager(s) to stop DVA any DVA message playing and
    // remove all queued DVA messages
    for(size_t i=0; i<m_sound_managers.size(); ++i)
    {
        if(m_sound_managers[i].second)
            m_sound_managers[i].second->StopDVA();
    }
}

//  Function:           DVAUnit::TrainChildDestructionCallback
//
//  Description:        Cleanup when Vehicle Child object is destroyed
//
//  Parameters:
//      Comms::Object object - The object being destroyed

void DVAUnit::TrainChildDestructionCallback(Comms::Object object)
{
    Trace::GetLogger().STAMP(Trace::VERBOSE) << __FUNCTION__ << Trace::EndLog();

    if(Core::GetClassID(object) == Project::ClassID::PIS)
    {
        if(m_dva_debug_level)
            Trace::GetLogger().STAMP(Trace::INFO) << "PIS Interface Object Destruction" << Trace::EndLog();

        if(m_pis.IsValid())
            m_pis.Invalidate();

        // Destroy all DVA Sound Managers
        for(size_t i=0; i<m_sound_managers.size(); ++i)
        {
            if(m_sound_managers[i].second)
            {
                delete m_sound_managers[i].second;
                m_sound_managers[i].second = NULL;
            }
        }
        m_sound_managers.clear();
    }
}

}
