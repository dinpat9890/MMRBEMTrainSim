//******************************************************************************
//
//  File:           DVASoundManager.h
//
//  Description:    Declares the DVASoundManager class. The DVA sound manager 
//                  manages the creation, destruction and state updating of
//                  Wave and SoundData objects for playing DVA messages by an
//                  AudioEngine.
//
//  Reference:      https://adl-atlassian.simulation.lan/confluence/display/BJSNA/PIS+-+Implementation
//
// @ingroup         DVAUnit
//
//  Author:         Yogesh Warad
//
//  (C) Copyright:  SYDAC Pty Ltd, 2017
//
//******************************************************************************

#pragma once

#include "sim_common/Listener.h"
#include "sim_comms/Gateway.h"

#include "project_comms_structure/ProjectObjectDefinition.h"

#include <queue>
#include <vector>
#include <atomic>

namespace dva { class  Properties; }

namespace dva
{
    // Forward declarations

    struct WaveData;

    //  Class:          DVASoundManagerUnit
    //
    //  Description:    This is a Unit that is responsible for 

    class DVASoundManager
    {

    public:

        // Constructor & destructor
        DVASoundManager(Comms::Gateway        &gateway,
                        Comms::Object         audio_engine_object,
                        Comms::Object         pis_interface_object,
                        Comms::Object         &dva_outputs_object,
                        const dva::Properties &properties);

        ~DVASoundManager();

        // Process current message queue
        void Process();

        // DVA message methods
        void AddDVASound(const std::string &dva_msg_title, const std::vector<std::string> & file_name_vector, bool loop = false);
        void StopDVA();
        void SetVolume(double volume);
        // Identification method
        int  GetAudioEngineID() const { return m_audio_engine_id; }

        typedef size_t  WaveID;

        int GetSoundQueueSize() const;
		//int GetSoundState() const { return m_start_sound_state; }
		//std::mutex & GetSoundStateMutex() { return m_start_sound_mutex; }

    private:

        //  Structure:      DVAVolume
        //
        //  Description:    Struct for DVA Cab volume. Validates the volume value at construction.

        // Callback methods
        void PISInterfaceDestructionCallback(Comms::Object object);

        void AudioEngineDestructionCallback(Comms::Object object);

        void AudioEngineChildCreatedCallback(Comms::Object object);
        void WaveDestructionCallback(Comms::Object object);

        void WaveChildCreatedCallback(Comms::Object object);
        void SoundDataDestructionCallback(Comms::Object object);

        void SoundStateChangedCallback(const Sim::Number &object_num);

        // Helper functions
        void    UpdateSoundVolume();
        int     GetSoundVolume() const;
        WaveID  GetUniqueWaveId(size_t &num_waves);
        int     GetWaveIndex(const WaveID &wave_id);
        void    SetDVAAttribute(const std::string& attribute_name, int value);

        // Comms gateway
        Comms::Gateway          &m_gateway;

        // Comms objects 
        Comms::Object           m_audio_engine_obj;
        Comms::Object           m_pis_interface_obj;

        // DVA Outputs object for updating when announcement is started or stopped
        Comms::Object           &m_dva_outputs_object;

        // Cab settings listener and corresponding object number ID's
        typedef Sim::Listener<Sim::Number, Sim::NoQueueing, Sim::AllCallbacks<Sim::Number> > NumberListener;

        double                  m_cab_volume;
        int                     m_cab_volume_index;

        // Map of Volume index to Volume %
        std::map<int, double>   m_volume_map;

        std::string             m_current_message_text;
        int                     m_current_message_id;
        bool                    m_current_message_looped;

        // Sound state listener 
        NumberListener          m_sound_state_listener;
        Sim::Number::ID         m_sound_state_id;

        // DVA configuration properties
        WaveID                  DVA_WAVE_ID_OFFSET;
        double                  MIN_MSG_GAP;
        double                  MAX_MSG_DURATION;
        double                  SPEAKER_X_POSITION;
        double                  SPEAKER_Y_POSITION;
        double                  SPEAKER_Z_POSITION;

        bool                    m_dva_debug_enabled;
        int                     m_dva_debug_level;

        double                  m_last_msg_timestamp;

        // ID of the Audio Engine this DVa sound manager handles
        int                     m_audio_engine_id;      

        // Wave queue
        typedef std::vector<WaveData>   WaveDataQueue;
        WaveDataQueue                   m_waves;
        std::mutex                      m_mutex;

		std::atomic<int>                m_start_sound_state;
		//int                             m_start_sound_state;
		//std::mutex                      m_start_sound_mutex;
    };
}