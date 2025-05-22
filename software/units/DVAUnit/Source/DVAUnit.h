//*****************************************************************************
//
// @file       DVAUnit.h
//
//  Description:    DVAUnit watch comms variables of PIS Output and play/stop/mute sound as per mentioned.
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

#pragma once

#include "DVAAudioConfigHandler.h"
#include "DVASoundManager.h"
#include "PISConstants.h"
#include "world_api/FeatureWatcher.h"
#include "world_api/PathFeatureWatcher.h"
#include "sim_common/Listener.h"
#include "sim_comms/Unit.h"
#include "PISInterfaceProperties.h"
#include "file_access/XMLReader.h"
#include <queue>

// Forward declarations
class AdjacencyUpdater;

namespace DataAccess { class SimulatorData; }
namespace WorldAPI   { class TrainPathWatcher; class WorldAccess; }

namespace dva
{

/// This is the Unit that is responsible for actually playing the sound with the help of audio engine .

class DVAUnit : public Comms::SteppingUnit
{
public:
    // Constructor and destructor
    DVAUnit(Comms::Gateway &gateway,  const std::shared_ptr<dva::Properties>& pis_properties);
    ~DVAUnit();


    // Define our own period
    std::string GetName() const;
    void        Step(double new_time) override;
    double      GetPeriod() const override{return (1.0 / 10.0);}
    double      GetNextPeriod() const;

private:

    // Callback functions - Scenario Train
    void        TrainCreationCallback(Comms::Object object);

    // Callback functions 
    void        TrainChildCallback(Comms::Object object);
    void        TrainChildDestructionCallback(Comms::Object object);
    void        DVACommandCallback(const Sim::Tray &tray_obj); 
    void        DVAStopCallback(const Sim::Number &num_obj); 
    void        DVAMuteCallback(const Sim::Number &num_obj); 

    void        PisInterfaceNumberCallback(const Sim::Number &num_obj);

    // Callback functions - Hub
    void        RootChildCreationCallback(Comms::Object object);
    void        HubDestructionCallback(Comms::Object object);

    // Callback functions - Audio Engine
    void        HubChildCreationCallback(Comms::Object object);
    void        AudioEngineDestructionCallback(Comms::Object object);

    // Watcher callbacks for when the train is observed, and for detonation
    void        TrainCallback(Comms::Object object);

    // Helper function to create a DVA Sound Managar for the given Audio Engine
    void        CreateDVASoundManager(const Comms::Object &audio_engine_object);

    // Helper function to clear DVA command queue and stop any DVA message playing
    void        StopDVA();

    // Helper Function to Get DVA Volume
    int         GetVolume();

    void        ObjectCreated(Comms::Object object);

private:

    // Listeners
    typedef Sim::Listener<Sim::Number, Sim::NoQueueing, Sim::IndividualCallbacks<Sim::Number> > number_listeners;
    number_listeners                                           m_number_listeners;

    // Listener for DVA command updates and corresponding number ID
    typedef Sim::Listener<Sim::Tray, Sim::NoQueueing, 
        Sim::AllCallbacks<Sim::Tray> > TrayListener;
    TrayListener                                               m_command_listener;
    

    // Listener for DVA Test Number changes and corresponding number ID
    typedef  Sim::Listener<Sim::Number, Sim::NoQueueing, 
        Sim::AllCallbacks<Sim::Number> > NumberListener;
    NumberListener                                              m_dva_stop_listener;
    NumberListener                                              m_dva_mute_listener;

    // DVA message queue
    Sim::Number::ID                                             m_dva_command_queue_id;
    Sim::Number::ID                                             m_dva_mute_id;
    Sim::Number::ID                                             m_dva_stop_id;
    Sim::Number::ID                                             m_dva_started_id;
    Sim::Number::ID                                             m_dva_stopped_id;

    // Map of Message id to pair of  Wave File Name, PID text 
    std::map<int, std::pair<std::string, std::string> >         m_message_map;
  
    // Our watcher and filter
    WorldAPI::FeatureWatcher                                    m_watcher;

    // DVA state
    bool                                                        m_dva_has_power;
    double                                                      m_cab_speaker_volume;
    bool                                                        m_cab_muted;

    // Properties. IMPORTANT: m_properties must be declared before the property values, otherwise
    // the constructor will fail.
    std::shared_ptr<dva::Properties>                            m_pis_properties;
    int                                                         m_dva_debug_level;
    bool                                                        m_dva_debug_enabled;
    const std::string                                           m_station_broadcast_path;
    const std::string                                           m_emergency_broadcast_path;

    // Comms objects
    Comms::Object                                               m_pis;
    Comms::Object                                               m_pis_outputs_object;
    Comms::Object                                               m_dacu;
    Comms::Object                                               m_dva_outputs_object;

    Sim::Number::ID                                             m_dva_test_id;
    Sim::Number::ID                                             m_dva_status_id;
    Sim::Number::ID                                             m_power_state_id;
    Sim::Number::ID                                             m_volume_state_id;
    Sim::Number::ID                                             m_mute_state_id;

    std::vector<Comms::Object>                                  m_hub_objects;
    std::vector<Comms::Object >                                 m_unhandled_audio_managers;
    std::vector< std::pair<Comms::Object, DVASoundManager *>>   m_sound_managers;

    std::unique_ptr<WorldAPI::PathFeatureWatcher>                 m_path_pis_watcher;
    std::queue<dva::DVAPlayCommand>                             m_dva_command_queue;

    // Audio XML handler and file data storage
    std::unique_ptr<dva::DVAAudioConfigHandler>                 m_dva_audio_handler;
    std::mutex                                                  m_mutex;
};

}