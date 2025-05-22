///
/// @file       PlatformDoorControlUnit.h
///
///             Unit keeps track of all (PSD) Platform Screen Door features. 
///             When the features state changes, then the position of the doors 
///             Starts to increment from 0-100 after state is set to open
///             Starts to decrement from 100-0 after state is set to closed.
///             Time taken by door to completely open from closed state and
///             vice versa should be 3 seconds (duration is configurable via 
///             worldmodel.ini). This unit will not do any updates to door
///             position if the PSD feature state is automate.
///
/// @ingroup    PlatformDoorControlUnit.dll
///
/// @author     Raghu Gandi
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2017


#ifndef PLATFORM_DOOR_CONTROL_UNIT_H
#define PLATFORM_DOOR_CONTROL_UNIT_H

#include "sim_comms\Unit.h"
#include "core_types\SessionData.h"
#include "common\DataAccess.h"
#include "common\Properties.h"
#include "world_api\TrainPathWatcher.h"

#include <string>
#include <mutex>
#include <list>

namespace
{        
    enum class DoorState
    {
        CLOSE_STATE = 0,
        OPEN_STATE  = 1
    };

    const double DOOR_FULLY_OPENED                 = 100.0;
    const double DOOR_FULLY_CLOSED                 = 0.0;
    const double PERIOD                            = 0.2;   // 5 Hz
    const double REQUEST_FREQUENCY                 = 10.0;
    const double DEFAULT_OPERATION_TURNAROUND_TIME = 3.0;
    const double MINIMUM_OPERATION_TURNAROUND_TIME = 1.0;
    const double MAXIMUM_OPERATION_TURNAROUND_TIME = 10.0;

/// @brief  CalculateDoorPosition will calculate the door position based on the
///         Platform Screen Door feature parameters
///         : State, Door Position, operation turnaround time.
///
/// @param  door_state                : This is either open or close. Based on this state,
///                                     the door is either opened or closed.
/// @param  operation_turnaround_time : This is the time taken by door to completely
///                                     open from closed state and vice versa.
/// @param  door_position             : Current Door Position.
///
/// @return door_position             : This is updated door position to which the door
///                                     will be moved in vision.

    double CalculateDoorPosition(const DoorState &door_state,
        const double &operation_turnaround_time, const double door_position)
    {
        auto door_pos = door_position;

        if( (door_position > DOOR_FULLY_CLOSED) && (DoorState::CLOSE_STATE == door_state) )
        {
            //close the door
            door_pos -= (100.0/operation_turnaround_time)*PERIOD;
            door_pos = (door_pos < DOOR_FULLY_CLOSED) ? DOOR_FULLY_CLOSED : door_pos;
        }
        else if( (door_position < DOOR_FULLY_OPENED) && (DoorState::OPEN_STATE == door_state) )
        {
            //open the door
            door_pos += (100.0/operation_turnaround_time)*PERIOD;
            door_pos = (door_pos > DOOR_FULLY_OPENED) ? DOOR_FULLY_OPENED : door_pos;
        }
        return door_pos;
    }
}//end of namespace

/// @brief  PlatformDoorControlUnit will manage the state of the 
///         PSD features at all platforms, opening and closing the doors 
///         when their state changes.
class PlatformDoorControlUnit : public Comms::SteppingUnit
{
public:
    PlatformDoorControlUnit(Comms::Gateway &gateway,
                            Common::Data::DataAccess &data_access,
                            Common::Properties &properties);
    ~PlatformDoorControlUnit();

    std::string GetName() const override { return "Platform Door Control Unit"; }

    // In order to step ...
    void Step(double new_time) override;
    double GetPeriod() const override;

private:
    void SetOperationTurnAroundTime(Common::Properties &properties);
    // Callbacks
    void PSDObjectCallback(WorldAPI::FeatureWatcher::CallbackInfo info);

    // Store the feature type IDs that we are interested in.
    int                         m_PSD_feature_type_id;
    WorldAPI::FeatureTypeFilter m_PSD_filter;
    WorldAPI::FeatureWatcher    m_PSD_watcher;

    //state ID's for the PSD feature 
    int     m_open_state_id;
    int     m_close_state_id;

    //Variables for reading information from properties file
    double  m_operation_turnaround_time;
    
    Sim::ValueID::ID m_state_id;
    Sim::ValueID::ID m_door_position_number_id;

    // our PSD Objects
    typedef Comms::Object PSDObject;
    std::list<PSDObject> m_PSD_objects;
    typedef std::list<PSDObject>::iterator psd_object_itr;
    std::mutex m_mutex;
};

#endif //PLATFORM_DOOR_CONTROL_UNIT_H
