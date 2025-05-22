//*****************************************************************************
//
// @file       DVASoundManager.cpp
//
//             Defines sound manager
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

#include "DVASoundManager.h"
#include "PISInterfaceProperties.h"
#include "project_comms_structure/ProjectObjectConstants.h"
#include "Common/StandardLogging.h"
#include "Utility/Utilities.h"
#include "core_types/AudioEngineTypes.h"
#include "sim_common/ObjectDefinition.h"
#include "sim_comms/Object.h"

#include <set>


namespace
{

// Anonymous namespace for local constants

    const double MIN_MSG_DURATION       = 0.6;
    const double REQUEST_FREQ           = 5;
    const int    DEFAULT_VOLUME_INDEX   = 12; 
    const double VOLUME_MULT            = 50;
    const int    MIN_VOLUME_INDEX       = 0;
    const int    MAX_VOLUME_INDEX       = 16;
    const int    MEDIUM_DEBUG_LOGGING   = 9 ;  // is set to any number less than 10 
    const int    FULL_DEBUG_LOGGING     = 99 ; // is set to any number less than 100 
    const int    MAX_VOLUME_PERCENT     = 100;
    const int    INVALID_MESSAGE_ID     = -1;
    const int    INVALID_WAVE_INDEX     = -1;
  
    // Convert Audio Index to Sound Volume for Audio Engine using lookup Map 
    double GetWaveVolume(const std::map<int, double> &volume_map, int vol_index)
    {
        double ret = 0;
        double volume_percent = 0.0;

        if (vol_index < MIN_VOLUME_INDEX)
            vol_index = MIN_VOLUME_INDEX;
        else if (vol_index > MAX_VOLUME_INDEX)
            vol_index = MAX_VOLUME_INDEX;

        auto iter = volume_map.find(vol_index);
        if(iter != volume_map.end())
            volume_percent = iter->second;

        //Convert Linear 0 - 100 to Mult*Log(Volume) for Wave Volume
        if (volume_percent > 0)
            ret = VOLUME_MULT*log10(volume_percent);

        if (ret > MAX_VOLUME_PERCENT)
            ret = MAX_VOLUME_PERCENT;

        return ret;
    }
}

namespace dva
{
//  Structure:      SoundData
//
//  Description:    Struct for holding information about DVA Sound Data.

struct SoundData
{
    // Constructor
    SoundData() 
        : m_play_timestamp(-1), m_state(NOT_STARTED) 
    {}
    // Object definition to create sound from
    Sim::ObjectDefinition   m_object_def;

    // Reference to SoundData Object. Will either be a valid value if
    // Object exists or invalid if Object doesn't exist.
    Comms::Object               m_object;

    double                      m_play_timestamp;

    enum State {NOT_STARTED, PLAY, STOPPED, FORCED_STOP};
    State                        m_state;
};


//  Structure:      WaveData
//
//  Description:    Struct for holding information about a DVA Wave.
//          

struct WaveData
{
    // Constructor. Wave properties only differ in audio files
    WaveData(const std::string &dva_msg_title, const std::vector<std::string> &audio_files, size_t id, bool loop=false)
        : m_title(dva_msg_title), 
          m_looped(loop),
          m_id(id)
    {
        m_data.to_completion    = false;
        m_data.loop             = loop;
        m_data.start_sample     = 0;
        m_data.end_sample       = 0;
        m_data.file_names       = audio_files;
    }

    // Set of parameters that defines a Wave. 
    AudioEngineTypes::AudioEngineFileData m_data;

    // Object definition to create wave from
    Sim::ObjectDefinition m_object_def;

    // Reference to Wave object. Will either be a valid value if Object
    // exists or invalid if Object doesn't exist.
    Comms::Object   m_object;

    // Sound child using this Wave. 
    SoundData       m_sound_data;

    // DVA message title (only used for debugging)
    std::string     m_title;

    bool            m_looped;

    // Wave object ID (the same ID is used for the corresponding sound object)
    dva::DVASoundManager::WaveID m_id;
};

///////////////////////////////////////////////////////////////////////////////////////////////////
// DVASoundManager - CONSTRUCTOR AND DESTRUCTOR
///////////////////////////////////////////////////////////////////////////////////////////////////



//  Function:       DVASoundManager::DVASoundManager
//
//  Description:    Constructor.
//
//  Parameters:
//      Comms::Gateway &gateway - The gateway to use.
//      Comms::Object audio_engine_object - AudioEngine Comms object that this 
//                                          DVAMessageManager will interface with.
//      Comms::Object tis_adjunct_object  - PIS comms object.
//      const TISAdjunct::Properties &properties - 
//
//  Notes:          This class requires the TISAdjunct and AudioEngine comms objects to be created 
//                  before construction.

DVASoundManager::DVASoundManager(Comms::Gateway        &gateway, 
                                 Comms::Object         audio_engine_object, 
                                 Comms::Object         pis_interface_object,
                                 Comms::Object         &dva_outputs_object,
                                 const dva::Properties &properties)
 : 	m_gateway(gateway), 
    m_audio_engine_obj(audio_engine_object), 
    m_pis_interface_obj(pis_interface_object),
    m_dva_outputs_object(dva_outputs_object),
    m_current_message_text(""),
    m_current_message_id(INVALID_MESSAGE_ID),
    m_current_message_looped(false),
    m_sound_state_id(Sim::INVALID_OBJECT),
	DVA_WAVE_ID_OFFSET(0),
    MIN_MSG_GAP(properties.GetMinimumMessageGap()), 
    MAX_MSG_DURATION(properties.GetMaximumMessageDuration()),
    SPEAKER_X_POSITION(properties.GetSpeakerXPosition()),
    SPEAKER_Y_POSITION(properties.GetSpeakerYPosition()),
    SPEAKER_Z_POSITION(properties.GetSpeakerZPosition()),
    m_dva_debug_enabled(properties.IsDVADebugEnabled()),
    m_dva_debug_level(properties.GetDVADebugLevel()),
    m_last_msg_timestamp(properties.GetLastMessageTimeStamp()), 
    m_waves()
{
	m_start_sound_state = 0;
    m_volume_map[0] = 0.0;
    m_volume_map[1] = 6.0;
    m_volume_map[2] = 12.0;
    m_volume_map[3] = 18.0;
    m_volume_map[4] = 25.0;
    m_volume_map[5] = 31.0;
    m_volume_map[6] = 37.0;
    m_volume_map[7] = 43.0;
    m_volume_map[8] = 50.0;
    m_volume_map[9] = 56.0;
    m_volume_map[10] = 62.0;
    m_volume_map[11] = 68.0;
    m_volume_map[12] = 75.0;
    m_volume_map[13] = 81.0;
    m_volume_map[14] = 87.0;
    m_volume_map[15] = 93.0;
    m_volume_map[16] = 100.0;
    

    m_cab_volume_index =  DEFAULT_VOLUME_INDEX;
    m_cab_volume = GetWaveVolume(m_volume_map, m_cab_volume_index);
    // get object values and Register callbacks
    {
        OS::Lock<Comms::Gateway> lock(m_gateway);

        // Move the potential throw to before the Callbacks are setup!

        // Now it is safe to setup the callbacks as we will not throw from here onwards (Unless we run out of memory etc)

        // Register a callback for when the TIS adjunct object is destructed
        Comms::AddDestructionCallback(m_pis_interface_obj, MakeCallback(&DVASoundManager::PISInterfaceDestructionCallback, this));

        // Register a callback for when our audio engine is destructed
        Comms::AddDestructionCallback(m_audio_engine_obj, MakeCallback(&DVASoundManager::AudioEngineDestructionCallback, this));

        // Register a callback to be notified when an audio engine child is created 
        Comms::AddCreationCallback(m_audio_engine_obj, MakeCallback(&DVASoundManager::AudioEngineChildCreatedCallback, this));
        
        // Add sound state listener
        m_sound_state_listener.AddCallback(MakeCallback(&DVASoundManager::SoundStateChangedCallback, this));
  
    }
}


//  Function:       DVASoundManager::~DVASoundManager
//
//  Description:    Destructor. Cleans up memory and removes callbacks.

DVASoundManager::~DVASoundManager()
{
    // Remove all callbacks and free dynamically allocated memory
    {
        OS::Lock<Comms::Gateway> lock(m_gateway);
        m_sound_state_listener.RemoveAllCallbacks();
        m_waves.clear();
    }

 }


///////////////////////////////////////////////////////////////////////////////////////////////////
// DVASoundManager - PUBLIC MEMBER FUNCTIONS
///////////////////////////////////////////////////////////////////////////////////////////////////


//  Function:       DVASoundManager::Process
//
//  Description:    Process function for the DVA Sound Manager, called by the 
//                  DVA Unit. Handles DVA message queue and stops any messages 
//                  exceeding the maximum message duration (indicates fault of 
//                  wav file etc).

void DVASoundManager::Process()
{
	if (m_start_sound_state == 0)
	{
		OS::Lock<Comms::Gateway> gateway_lock(m_gateway);
		// Only process sounds if both the audio engine object and the TIS adjunct object are valid
		if (m_audio_engine_obj.IsValid() && m_pis_interface_obj.IsValid())
		{
			// Safety check for failed waves
			double time = m_gateway.GetTiming().GetCurrentModuleTime();
			if (!m_waves.empty() && m_waves[0].m_sound_data.m_object.IsValid() &&
				m_waves[0].m_sound_data.m_state == dva::SoundData::PLAY &&
				(time - m_waves[0].m_sound_data.m_play_timestamp) > MAX_MSG_DURATION)
			{
				// Create a detailed log message
				Trace::GetLogger().STAMP(Trace::WARN) << "DVA Message \""
					<< m_waves[0].m_title
					<< "\" (ID "
					<< m_waves[0].m_id
					<< ") has exceeeded maximum duration.";

				for (size_t i = 0; i < m_waves[0].m_data.file_names.size(); ++i)
				{
					*Trace::g_plog << "\n" << m_waves[0].m_data.file_names[i];
				}

				*Trace::g_plog << Trace::EndLog();

				// Something is wrong with this sound, STOP DVA since any queued messages are
				// probably outdated
				StopDVA();
			}


			/////////////////////////////////////////////////////////////////////////////
			// Activate the next DVA sound in the queue if 
			//  - There has been at least m_msg_gap seconds since the last sound finished
			//  - The sound is in state NOT_STARTED
			//  - The sound object is valid
			/////////////////////////////////////////////////////////////////////////////
			for (auto &waves_iter : m_waves)
			{
				if ((time - m_last_msg_timestamp) >= MIN_MSG_GAP && !m_waves.empty() &&
					waves_iter.m_sound_data.m_state == SoundData::NOT_STARTED &&
					waves_iter.m_sound_data.m_object.IsValid())
				{
					// The first message in the queue is ready for playback
					if (m_dva_debug_level > MEDIUM_DEBUG_LOGGING)
						Trace::GetLogger().STAMP(Trace::INFO) << "Setting DVA Sound (" << m_waves[0].m_id
						<< ") to state PLAY. Message Gap " << (time - m_last_msg_timestamp) << " seconds"
						<< Trace::EndLog();

					// Update sound object state to PLAY

					if (waves_iter.m_sound_data.m_object.GetID() != Sim::INVALID_NUMBER)
					{
						Sim::Number num = Sim::Number(m_waves[0].m_sound_data.m_object.GetID(), m_sound_state_id);
						num.value = 1;

						waves_iter.m_sound_data.m_object.Numbers().Store().Set(num);
					}

					m_current_message_text = waves_iter.m_title;
					m_current_message_id = waves_iter.m_id;
					m_current_message_looped = waves_iter.m_looped;
				}

			}

			// Clear the message text if nothing queued.
			if (m_waves.empty() && !m_current_message_text.empty())
			{
				m_current_message_text.clear();
				m_current_message_id = INVALID_MESSAGE_ID;
				m_current_message_looped = false;
			}
		}
	}
}


//  Function:       DVASoundManager::AddDVASound
//
//  Description:    Adds DVA sound data to queue of DVA messages to be played.
//
//  Parameters:
//      const std::vector<std::string> & file_name_vector - Vector containing 
//                          the wav file names that makes up this DVA sound.

void DVASoundManager::AddDVASound(const std::string &dva_msg_title, const std::vector<std::string> &file_names, bool loop)
{
    Trace::GetLogger().STAMP(Trace::VERBOSE) << __FUNCTION__ << Trace::EndLog();
    OS::Lock<Comms::Gateway> gateway_lock(m_gateway);

    if (!m_audio_engine_obj.IsValid())
    {
        Trace::GetLogger().STAMP(Trace::ERR) << "Trying to Add a DVA Sound to invalid Audio Engine!" << Trace::EndLog();
        return;
    }

    size_t num_waves;
    // Get a unique ID for this wave
    WaveID wave_id = GetUniqueWaveId(num_waves);

    if(m_dva_debug_level > MEDIUM_DEBUG_LOGGING)
    {                
        Trace::GetLogger().STAMP(Trace::INFO) << "Queueing DVA message \"" << dva_msg_title
            << "\" (ID = " << wave_id << ")" << Trace::EndLog();
    }

    // Store the data for this DVa message
    m_waves.push_back(WaveData(dva_msg_title, file_names, wave_id, loop));

    // Setup Wave object definition.
    m_waves[num_waves].m_object.Invalidate();
    m_waves[num_waves].m_object_def = Project::GetObjectDefinition(Project::ClassID::WAVE);
    m_waves[num_waves].m_object_def.name = "Wave: " + m_waves[num_waves].m_title;
    m_waves[num_waves].m_object_def.SetNumberInitial(Project::ValueName::Wave::WAVE_ID, wave_id);

    // Encode the wave data to raw data
    Sim::Raw::Type raw_data;
    AudioEngineTypes::EncodeAudioFileData(raw_data, m_waves[num_waves].m_data);
    m_waves[num_waves].m_object_def.SetRawInitial(Project::ValueName::Wave::WAVEDATA, raw_data);

    // Setup Sound Data object definition.

    // There will only be one DVA sound per DVA wave, hence the ID is set to the wave ID
    m_waves[num_waves].m_sound_data.m_object.Invalidate();
    m_waves[num_waves].m_sound_data.m_object_def = Project::GetObjectDefinition(Project::ClassID::SOUND_DATA);
    m_waves[num_waves].m_sound_data.m_object_def.name = "Sound: " + m_waves[num_waves].m_title;

    // The DVA sound is not moving relative to the observer
    m_waves[num_waves].m_sound_data.m_object_def.SetNumberInitial(Project::ValueName::SoundData::FREQUENCY, 1);
    m_waves[num_waves].m_sound_data.m_object_def.SetNumberInitial(Project::ValueName::SoundData::OBSERVER_RELATIVE, true);

    // Speaker position relative to the observer
    m_waves[num_waves].m_sound_data.m_object_def.SetNumberInitial(Project::ValueName::SoundData::POSITION_X, SPEAKER_X_POSITION);
    m_waves[num_waves].m_sound_data.m_object_def.SetNumberInitial(Project::ValueName::SoundData::POSITION_Y, SPEAKER_Y_POSITION);
    m_waves[num_waves].m_sound_data.m_object_def.SetNumberInitial(Project::ValueName::SoundData::POSITION_Z, SPEAKER_Z_POSITION);

    // A sound object cannot be playing before it has been created
    m_waves[num_waves].m_sound_data.m_object_def.SetNumberInitial(Project::ValueName::SoundData::STATE, 0);

    // The DVA sound is not moving relative to the observer
    m_waves[num_waves].m_sound_data.m_object_def.SetNumberInitial(Project::ValueName::SoundData::VELOCITY_X, 0);
    m_waves[num_waves].m_sound_data.m_object_def.SetNumberInitial(Project::ValueName::SoundData::VELOCITY_Y, 0);
    m_waves[num_waves].m_sound_data.m_object_def.SetNumberInitial(Project::ValueName::SoundData::VELOCITY_Z, 0);

    // The DVA sound should have the volume of the Cab
    m_waves[num_waves].m_sound_data.m_object_def.SetNumberInitial(Project::ValueName::SoundData::VOLUME, GetSoundVolume());

    // Update Comms 
    try
    {
        // Create Wave Object
        m_audio_engine_obj.CreateChild(m_waves[num_waves].m_object_def);
    }
    catch (InvalidParameterException &e)
    {
        e.AddStackTrace(FLSTAMP, "Failed to create Wave object");
        Trace::g_plog->LogException(e);
    }
}


//  Function:       DVASoundManager::StopDVA
//
//  Description:    Stops any DVA sound currently playing and empties the queue 
//                  of DVA sounds.

void DVASoundManager::StopDVA()
{
    if(m_dva_debug_level > MEDIUM_DEBUG_LOGGING)
        Trace::GetLogger().STAMP(Trace::INFO) << "Stopping current DVA message and clearing queue" << Trace::EndLog();

    // Stop current DVA sound playing and destroy comms object
    OS::Lock<Comms::Gateway> lock(m_gateway);

    for(auto &waves_iter : m_waves)
    {
        // Start with investigating if there is a sound object defined
        if(waves_iter.m_sound_data.m_object.IsValid())
        {
            if(waves_iter.m_sound_data.m_state == SoundData::PLAY)
            {
                // This is a currently playing sound. Set the sound data state to STOPPED. 
                // This will trigger the deletion of the sound data object as well as the parent wave object.
                waves_iter.m_sound_data.m_state = SoundData::FORCED_STOP;

                Sim::Number simnum = Sim::Number(
                    waves_iter.m_sound_data.m_object.GetID(), m_sound_state_id);

                simnum.value = 0.0;
                
                waves_iter.m_sound_data.m_object.Numbers().Store().Set(simnum);

                Trace::GetLogger().STAMP(Trace::INFO) << "State changed to SoundData::FORCED_STOP" << Trace::EndLog();
            }
            else
            {
                // This is an inactive sound. Destroy it which will trigger parent wave destruction
                waves_iter.m_sound_data.m_object.Destroy();
            }
        }
        else if(waves_iter.m_object.IsValid())
        {
            // Destroy the wave object
            waves_iter.m_object.Destroy();
        }
    }

    m_current_message_text.clear();
    m_current_message_id = INVALID_MESSAGE_ID;
    m_current_message_looped = false;

    // Set DVA Outputs::DVA_started to disable and DVA_Stopped to enable
    auto announcement_started = 0;
    auto announcement_stopped = 1;
    SetDVAAttribute(Project::ValueName::DVAOutputs::DVA_STOPPED, announcement_stopped);
    SetDVAAttribute(Project::ValueName::DVAOutputs::DVA_STARTED, announcement_started);
	{
		//std::lock_guard lock(m_start_sound_mutex);
		m_start_sound_state = 0;
	}
}


///////////////////////////////////////////////////////////////////////////////////////////////////
// DVASoundManager - Helper Functions
///////////////////////////////////////////////////////////////////////////////////////////////////


//  Function:       DVASoundManager::UpdateSoundVolume
//
//  Description:    Helper function to update volume of any active sound data 
//                  object according to current cab volume and mute status.

void DVASoundManager::UpdateSoundVolume()
{
    OS::Lock<Comms::Gateway> lock(m_gateway);

    // Update volume for DVA SoundData object
    int new_volume = GetSoundVolume();

    for(auto &waves_iter : m_waves)
    {
        if(waves_iter.m_sound_data.m_object.IsValid())
        {
            // Update the comms volume
            Sim::Number::ID volume_id = waves_iter.m_sound_data.m_object.Numbers().Info().GetID(
                Project::ValueName::SoundData::VOLUME);
            Sim::Number simnum = Sim::Number(
                waves_iter.m_sound_data.m_object.GetID(), volume_id);
            simnum.value = new_volume;

            waves_iter.m_sound_data.m_object.Numbers().Store().Set(simnum);
        }
        else
        {
            // This sound data object has not been created yet, update the initial value
            waves_iter.m_sound_data.m_object_def.SetNumberInitial(Project::ValueName::SoundData::VOLUME, new_volume);
        }
    }
}


//  Function:       DVASoundManager::GetSoundVolume
//
//  Description:    Helper function to get the current volume for DVA Sound Data objects.

int DVASoundManager::GetSoundVolume() const
{
    return static_cast<int>(m_cab_volume);
}

//  Function:       DVASoundManager::GetSoundVolume
//
//  Description:    Function to set the current volume for DVA Sound Data objects.

void DVASoundManager::SetVolume(double volume_index)
{
    if(m_cab_volume_index  != volume_index)
    {
        m_cab_volume_index = static_cast<int>(volume_index);
        m_cab_volume = GetWaveVolume(m_volume_map, static_cast<int>(volume_index));

        if(m_dva_debug_level > MEDIUM_DEBUG_LOGGING)
            Trace::GetLogger().STAMP(Trace::INFO) << "Cab DVA/PA volume index changed to " << m_cab_volume_index 
            << " (AudioEngine Volume " << GetSoundVolume() << ")" << Trace::EndLog();

        UpdateSoundVolume();

    }
}
                                                                      
///////////////////////////////////////////////////////////////////////////////////////////////////
// DVASoundManager - CALLBACK FUNCTIONS
///////////////////////////////////////////////////////////////////////////////////////////////////


//  Function:       DVASoundManager::TISAdjunctDestructionCallback
//
//  Description:    The TIS adjunct object has been destroyed and our local 
//                  object needs to be invalidated.
//
//  Parameters:
//      Comms::Object object - Audio engine object

void DVASoundManager::PISInterfaceDestructionCallback(Comms::Object object)
{
    if(m_pis_interface_obj.IsValid())
        m_pis_interface_obj.Invalidate();
}

//  Function:       DVASoundManager::AudioEngineDestructionCallback
//
//  Description:    The audio engine handled by this DVA Sound manager has been destroyed and
//                  our local object needs to be invalidated.
//
//  Parameters:
//      Comms::Object object - Audio engine object

void DVASoundManager::AudioEngineDestructionCallback(Comms::Object object)
{
    if(m_audio_engine_obj.IsValid())
        m_audio_engine_obj.Invalidate();
}


//  Function:       DVASoundManager::AudioEngineChildCreatedCallback
//
//  Description:    Audio Engine child has been created. Create a SoundData 
//                  object if the object is a DVA wave object.
//
//  Parameters:
//      Comms::Object object - New audio engine child comms object.

void DVASoundManager::AudioEngineChildCreatedCallback(Comms::Object object)
{
    Trace::GetLogger().STAMP(Trace::VERBOSE) << __FUNCTION__ << Trace::EndLog();
    // Only interested in wave objects
    if(Core::GetClassID(object) == Project::ClassID::WAVE)
    {
        // A wave object has been created. Check if this is a DVA wave
        Sim::ValueID number_id = object.Numbers().Info().GetID(Project::ValueName::Wave::WAVE_ID);
        WaveID wave_id = static_cast<size_t>(object.Numbers().Info().GetInfo(number_id.id).initial);

        auto index = GetWaveIndex(wave_id);
        if(index != INVALID_WAVE_INDEX)
        {
            if(m_dva_debug_level > MEDIUM_DEBUG_LOGGING)
                Trace::GetLogger().STAMP(Trace::INFO) << "DVA Wave object (ID " 
                                                      << wave_id
                                                      << ") created." << Trace::EndLog();

            // Store the DVA wave object 
            m_waves[index].m_object = object;

            // Register for wave destruction and wave child creation 
            Comms::AddDestructionCallback(object, MakeCallback(&DVASoundManager::WaveDestructionCallback, this));
            Comms::AddCreationCallback(object, MakeCallback(&DVASoundManager::WaveChildCreatedCallback, this));

            // Create a SoundData object
            try
            {
                object.CreateChild(m_waves[index].m_sound_data.m_object_def);
            }
            catch (InvalidParameterException &e)
            {
                e.AddStackTrace(FLSTAMP, "Failed to create Sound Data object");
                Trace::g_plog->LogException(e);
            } 
        }
    }
}


//  Function:       DVASoundManager::WaveDestructionCallback
//
//  Description:    Destruction callback for wave object. Free memory for DVA 
//                  wave wrapper.
//
//  Parameters:
//      Comms::Object object - Wave object.

void DVASoundManager::WaveDestructionCallback(Comms::Object object)
{
    // Ensure this is our current wave
    Sim::ValueID wave_num_id = object.Numbers().Info().GetID(Project::ValueName::Wave::WAVE_ID);
    WaveID wave_id = wave_num_id.id ;

    WaveDataQueue::iterator iter = m_waves.begin();
    for( ; iter!=m_waves.end(); ++iter)
    {
        if(iter->m_id == wave_id)
        {            
            if(m_dva_debug_level > MEDIUM_DEBUG_LOGGING)
                Trace::GetLogger().STAMP(Trace::INFO) << "DVA Wave object (ID " << wave_id
                << ") destructed." << Trace::EndLog();

            // Remove the wave data element
            m_waves.erase(iter);

            break;
        }
        if(iter == m_waves.end())
            Trace::GetLogger().STAMP(Trace::ERR) << "Failed to find DVA wave data for wave ID = " 
            << wave_id << Trace::EndLog();
    }
}


//  Function:       DVASoundManager::WaveChildCreatedCallback
//
//  Description:    Callback function for DVA Sound Data object creation. Update
//                  the state of the Sound Data object to start playing.
//
//  Parameters:
//      Comms::Object object - Sound Data object.

void DVASoundManager::WaveChildCreatedCallback(Comms::Object object)
{
    if(Core::GetClassID(object) == Project::ClassID::SOUND_DATA)
    {

        for(size_t i=0; i<m_waves.size(); ++i)
        {
            // DVA sound objects have the same ID as their parent wave object
            if(object.GetParent().GetID() == m_waves[i].m_object.GetID())
            {

                // Found the wave data for this DVA Sound Data object
                m_waves[i].m_sound_data.m_object = object;
                if (m_dva_debug_level > MEDIUM_DEBUG_LOGGING)
                {
                    Trace::GetLogger().STAMP(Trace::INFO) << "DVA Sound Data object (ID " << m_waves[i].m_id
                        << ") created." << Trace::EndLog();
                }

                // Register for sound data destruction
                Comms::AddDestructionCallback(object, MakeCallback(&DVASoundManager::SoundDataDestructionCallback, this));

                // Register to be notified of changes for this sound
                {
                    m_sound_state_id = object.Numbers().Info().GetID(Project::ValueName::SoundData::STATE);
                }
                object.Numbers().Store().AddListener(m_sound_state_listener); 

                break;
            }
            if(i == (m_waves.size()-1))
            {
                // Invalid ID
                Trace::GetLogger().STAMP(Trace::WARN) << "DVA Sound Data object for unknown Wave object "
                    << "detected (ID " << m_waves[i].m_id << ")" <<Trace::EndLog();
            }
        }
    }   
}


//  Function:       DVASoundManager::SoundDataDestructionCallback
//
//  Description:    DVA Sound Data object destructed callback. Invalidate local 
//                  sound data object and destroy parent wave object.
//
//  Parameters:
//      Comms::Object object - Sound Data object.

void DVASoundManager::SoundDataDestructionCallback(Comms::Object object)
{
    // Ensure this is the DVA sound object of the current wave object (wave and sound object have the same ID)

    for(auto &waves_iter : m_waves)
    {
        if(waves_iter.m_sound_data.m_object == object)
        {
            if(waves_iter.m_sound_data.m_state == SoundData::PLAY)
                Trace::GetLogger().STAMP(Trace::WARN) << "Sound Data object (ID " << waves_iter.m_id 
                << ") in PLAY mode destructed" << Trace::EndLog();

            // Invalidate the sound data object.
            if(waves_iter.m_sound_data.m_object.IsValid())
                waves_iter.m_sound_data.m_object.Invalidate();

            // Destroy parent wave object
            waves_iter.m_object.Destroy();

            if(m_dva_debug_level > MEDIUM_DEBUG_LOGGING)
                Trace::GetLogger().STAMP(Trace::INFO) << "DVA Sound Data object (ID "
                    <<  waves_iter.m_id  << ") destroyed." << Trace::EndLog();

            break;
        }
    }
}

//  Function:       DVASoundManager::SoundStateChangedCallback
//
//  Description:    Callback function for Sound Data number changes. Handles 
//                  changes in state (play/stop).
//
//  Parameters:
//      const Sim::Number &obj_num - Sound Data object number that 
//                          ha;s changed.

void DVASoundManager::SoundStateChangedCallback(const Sim::Number &obj_num)
{
    // Only interested in state changes
    
    std::unique_lock<std::mutex> callback_lock(m_mutex);

    if(obj_num.id == m_sound_state_id)
    {
        // Find the updated sound 
        for(auto &waves_iter : m_waves)
        {
            if(waves_iter.m_sound_data.m_object.GetID() == obj_num.object_id)
            {
                // This sound data object has changed state
                bool is_playing = (obj_num.value != 0.0);
                double sim_time = m_gateway.GetTiming().GetCurrentModuleTime();

                if(is_playing)
                {
                    // Sound is now playing. Set the timestamp of the PLAY start of this DVA message
                    waves_iter.m_sound_data.m_state = SoundData::PLAY;
                    waves_iter.m_sound_data.m_play_timestamp = sim_time;
                    if(m_dva_debug_level > MEDIUM_DEBUG_LOGGING)
                        Trace::GetLogger().STAMP(Trace::INFO) << "DVA Sound (ID " << waves_iter.m_id 
                        << ") changed state to PLAY" << Trace::EndLog(); 

                    // Set DVA Outputs::DVA_started to enable and DVA_Stopped to disable
                    auto announcement_started = 1;
                    auto announcement_stopped = 0;
                    SetDVAAttribute(Project::ValueName::DVAOutputs::DVA_STARTED, announcement_started);
                    SetDVAAttribute(Project::ValueName::DVAOutputs::DVA_STOPPED, announcement_stopped);
					{
						//std::lock_guard lock(m_start_sound_mutex);
						m_start_sound_state = 1;
					}
                }
                else
                {
                    // Sound has stopped playing.
                    if(waves_iter.m_sound_data.m_state == SoundData::PLAY)
                    {
                        // Ensure the message has actually started playing
                        double msg_duration = sim_time - waves_iter.m_sound_data.m_play_timestamp;
                        if(msg_duration > MIN_MSG_DURATION)
                        {
                            // Message finished playing
                            waves_iter.m_sound_data.m_state = SoundData::STOPPED;
                            if(waves_iter.m_sound_data.m_object.IsValid())
                            {
                                // Detroy the sound data object
                                waves_iter.m_sound_data.m_object.Destroy();
                            }

                            // Set the timestamp of the last message stopped to enable a gap between messages
                            m_last_msg_timestamp = sim_time;

                            if(m_dva_debug_level > MEDIUM_DEBUG_LOGGING)
                                Trace::GetLogger().STAMP(Trace::INFO) << "DVA Sound (ID " << waves_iter.m_id 
                                << ") changed state to STOPPED. Duration = " << msg_duration 
                                << " seconds" <<Trace::EndLog(); 
                        }
                        else
                        {
                            // Reset the state of the wave since it was alomst immediately changed 
                            // from PLAY to STOPPED
                            if(m_dva_debug_level > MEDIUM_DEBUG_LOGGING)
                                Trace::GetLogger().STAMP(Trace::INFO) << "DVA Sound (ID " << waves_iter.m_id 
                                    << ") changed state to STOPPED after " << msg_duration 
                                    << " seconds. Reset the state to NOT_STARTED" << Trace::EndLog();
                            waves_iter.m_sound_data.m_state = SoundData::NOT_STARTED;
                        }

                        // Set DVA Outputs::DVA_started to disable and DVA_Stopped to enable
                        auto announcement_started = 0;
                        auto announcement_stopped = 1;                        
                        SetDVAAttribute(Project::ValueName::DVAOutputs::DVA_STOPPED, announcement_stopped);
                        SetDVAAttribute(Project::ValueName::DVAOutputs::DVA_STARTED, announcement_started);
						{
							//std::lock_guard lock(m_start_sound_mutex);
							m_start_sound_state = 0;
						}
                    }
                    else if(waves_iter.m_sound_data.m_state == SoundData::FORCED_STOP)
                    {
                        // This message should be stopped ino matter what
                        if(waves_iter.m_sound_data.m_object.IsValid())
                            waves_iter.m_sound_data.m_object.Destroy();

                        // Set the timestamp of the last message stopped to enable a gap between messages
                        m_last_msg_timestamp = sim_time;

                        if(m_dva_debug_level > MEDIUM_DEBUG_LOGGING)
                            Trace::GetLogger().STAMP(Trace::INFO) << "DVA Sound (ID " << waves_iter.m_id 
                                << ") forced to change state to STOPPED." <<Trace::EndLog(); 
                        
                        // Set DVA Outputs::DVA_started to disable and DVA_Stopped to enable
                        auto announcement_started = 0;
                        auto announcement_stopped = 1;
                        SetDVAAttribute(Project::ValueName::DVAOutputs::DVA_STOPPED, announcement_stopped);
                        SetDVAAttribute(Project::ValueName::DVAOutputs::DVA_STARTED, announcement_started);
						{
							//std::lock_guard lock(m_start_sound_mutex);
							m_start_sound_state = 0;
						}
                    }
                    else
                    {
                        Trace::GetLogger().STAMP(Trace::ERR) << "Sound Data object " << waves_iter.m_id 
                            << " changed to state STOPPED while being in state " 
                            << ((waves_iter.m_sound_data.m_state == SoundData::NOT_STARTED) ? "NOT_STARTED" : "STOPPED") 
                            << Trace::EndLog();
                    }
                }
                break;
            }
        }
    }
}

//  Function:       DVAVolume::GetSoundQueueSize
//
//  Description:    Return the number of Queued Waves for this Audio Engine
//
//  Parameters:
//      N/A
//  
//  Return:
//      int Number of Queued Sounds
//

int DVASoundManager::GetSoundQueueSize() const
{
    return static_cast<int>(m_waves.size());
}

DVASoundManager::WaveID DVASoundManager::GetUniqueWaveId(size_t &num_waves)
{
    // Get a unique ID for this wave
    WaveID wave_id;
    num_waves = m_waves.size();
    if(m_waves.empty())
        wave_id = DVA_WAVE_ID_OFFSET;
    else
        wave_id = m_waves[num_waves-1].m_id + 1;

    return wave_id;
}

int DVASoundManager::GetWaveIndex(const WaveID &wave_id)
{
    auto index = INVALID_WAVE_INDEX ;

    auto it = find_if(m_waves.begin(), m_waves.end(), [&wave_id](const WaveData& obj) {return obj.m_id == wave_id;});
    if (it != m_waves.end())
    {
        // found element. it is an iterator to the first matching element.
        // if you really need the index, you can also get it:
        index = std::distance(m_waves.begin(), it);
    }

    return index;
}

void DVASoundManager::SetDVAAttribute(const std::string & attribute_name, int value)
{
    OS::Lock<Comms::Gateway> lock(m_gateway);
    if (m_dva_outputs_object.IsValid())
    {
        Sim::Number::ID  attribute_id = m_dva_outputs_object.Numbers().Info().GetID(attribute_name.c_str());

        if (attribute_id != Sim::INVALID_NUMBER)
        {
             m_dva_outputs_object.Numbers().Store().Set(Sim::Number(value, attribute_id));
        }
        else
            Trace::GetLogger().STAMP(Trace::ERR) << m_dva_outputs_object.GetName() << " object did not have the " << attribute_name.c_str()
            << " property." << Trace::EndLog();
    }
    else
    {
        Trace::GetLogger().STAMP(Trace::ERR) << "DVA Outputs object is invalid." << Trace::EndLog();
    }
}


}