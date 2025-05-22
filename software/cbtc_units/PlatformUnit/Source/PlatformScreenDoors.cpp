/// @file PlatformScreenDoors.h
///
/// @author    Adam zielinski
///
/// @copyright © SYDAC Pty Ltd, 2017

#include "PlatformScreenDoors.h"

#include "core_data_access/Feature.h"

#include "core_comms_structure/CoreObjectConstants.h"
#include "project_features/ProjectFeatureConstants.h"

#include "cbtc_common/FeatureProperties.h"

#include "Project/Utilities/RawToString.h"
#include "utility/Utilities.h"
#include "core_types/SessionData.h"
#include "common/StandardLogging.h"

namespace
{
    const auto   REQUEST_FREQUENCY = 4.0;
    const double DOOR_OPEN_POSITION = 100.0;
    const double DOOR_CLOSE_POSITION = 0.0;


    /// Returns the value of the Feature ID of a feature object.
    ///
    /// @param object The object to get the Feature ID of.
    ///
    /// @return  The Feature ID Value corresponding to the position Number, or -1 if one does not
    ///          exist (or if the object is not a Feature).
    int GetFeatureID(Comms::Object object)
    {
        int ret = -1;

        // Test the code in debug - we should never be calling this for a non feature object.
        assert(object.IsValid());
        assert(Core::GetClassID(object) == Core::ClassID::FEATURE);

        // If this object is a Feature we can look for the FEATUREID
        ret = static_cast<int>(object.Numbers().Get(Core::ValueName::Feature::FEATURE_ID).value);

        return ret;
    }

    /// Swaps the order of the inputted SD code and returns an SD code of the required output length
    ///
    /// If the inputted SD Code is longer than the returned SD Code, only the order of first sd_code_out_length
    /// bits are swapped.
    ///
    /// Examples:
    ///    SwapOrderSDCode (0011001010, 10, 15) returns 0101001100
    ///    SwapOrderSDCode (0011001010, 10, 7) returns  0101001
    ///
    /// @param sd_code            : SD code whose bit order is to be swapped
    /// @param sd_code_in_length  : Length of the SD Code being provided
    /// @param sd_code_out_length : Length of the SD Code being returned
    ///
    /// @returns returns a SD code where the order of the inputted SD Code bits has been swapped
    ///
    int SwapOrderSDCode(int sd_code, int sd_code_in_length, int sd_code_out_length)
    {
        int inverted_sd_code = 0;
        int number_bits_to_invert;

        // Determine the number of bits whose order needs to be swapped
        if (sd_code_in_length <= sd_code_out_length)
            number_bits_to_invert = sd_code_in_length;
        else
            number_bits_to_invert = sd_code_out_length;

        // Swap the order of the bits
        for (int i = 0; i < number_bits_to_invert; i++)
        {
            int next_door_inhibited = 1 << i;
            int inverted_next_door_inhibit = 1 << (number_bits_to_invert - 1 - i);

            if (sd_code & next_door_inhibited)
                inverted_sd_code = inverted_sd_code | inverted_next_door_inhibit;
        }

        return inverted_sd_code;
    }

    /// Updates a bit code by inserting a one between the given start and end bit
    ///
    /// @param bit_code  : Bit code into which bits are to be inserted
    /// @param start_bit : location of the first bit to be inserted
    /// @param end_bit   : location of the last bit to be inserted
    ///
    /// @returns the inputted bit code with the additional bits set
    ///
    void InsertBits(int& bit_code, int start_bit, int end_bit)

    {
        for (int i = start_bit; i < end_bit; i++)
        {
            int next_bit_to_set = 1 << i;
            bit_code = bit_code | next_bit_to_set;
        }
    }

    /// Checks all doors are inhibited or not using given inhibited code
    /// and total number of doors in the train.
    ///
    /// @param inhibit_code                 : Inhibit code to be checked(inhibiting all doors or not)
    /// @param total_number_of_train_doors  : Total number of doors in the train
    ///
    /// @returns true if inhibit_code is for inhibiting all the doors, false otherwise
    ///
    bool AllDoorsInhibited(int inhibit_code, int total_number_of_train_doors)
    {
        int all_doors_inhibit_code = 0;

        InsertBits(all_doors_inhibit_code, 0, total_number_of_train_doors);

        return ((all_doors_inhibit_code & inhibit_code) == all_doors_inhibit_code);
    }
}


////////////////////////////////////////////////////////////////////////////////////////
// Platfform Screen Doors
////////////////////////////////////////////////////////////////////////////////////////

using namespace PlatformControl;

/// Constructor
///
PlatformScreenDoors::PlatformScreenDoors(Comms::Gateway                    &gateway,
    Common::Data::DataAccess          &data_access,
    WorldAPI::WorldAccess             &world_access,
    PlatformDoors::PlatformDoorsStateChangeCallback state_change_callback)
    : m_gateway(gateway),
    m_state_change_callback(state_change_callback)
{
    try
    {
        // Determine the ID of our PSD feature type
        auto psd_id = Core::Database::Feature(data_access).GetFeatureType(Project::FeatureTypes::FETY_PSD).feature_type_id;

        // Determine the ID of the states that we care about
        m_psd_state_ids.m_psd_open_state = Core::Database::Feature(data_access).GetFeatureTypeState(psd_id, Project::FeatureStates::OPEN).feature_type_state_id;
        m_psd_state_ids.m_psd_closed_state = Core::Database::Feature(data_access).GetFeatureTypeState(psd_id, Project::FeatureStates::CLOSED).feature_type_state_id;

        m_psd_feature_type_filter.SetAcceptableType(psd_id);
    }
    catch (CommonException &e)
    {
        e.AddStackTrace(FLSTAMP, "Failed to find required Platform Screen Door feature Id States. Platform Doors will not be updated.");
        Trace::GetLogger().LogException(e);
    }

    // Filter the feature watcher to only watch stopping points and add a callback to handle updates
    m_psd_feature_watcher.SetFeatureTypeFilter(WorldAPI::CreateFilterCallback(m_psd_feature_type_filter));
    m_psd_feature_watcher.SetRequestFrequency(REQUEST_FREQUENCY);
    m_psd_feature_watcher.AddCallback(MakeCallback(&PlatformScreenDoors::PSDFeatureWatcherCallback, this));

    {
        const std::lock_guard<Comms::Gateway> COMMS_LOCK(m_gateway);
        const std::lock_guard<std::mutex>     DATA_LOCK(m_mutex);
        auto root_object = m_gateway.GetRootObject();
        m_psd_feature_watcher.Attach(root_object);
    }
}

/// Destructor
///
PlatformScreenDoors::~PlatformScreenDoors()
{
    const std::lock_guard<std::mutex>     DATA_LOCK(m_mutex);
    const std::lock_guard<Comms::Gateway> COMMS_LOCK(m_gateway);
    m_psd_feature_watcher.Detach();
    m_platform_feature_id_to_psd_map.clear();
}

/// Get the platform door associated with the identified platform feature
///
/// @param platfrom_feature_id : Identifies platform whose PSD data we want
///
/// @returns PSD data for the identified platform feature. Nullptr if platform does not have PSD's
/// 
std::shared_ptr<PlatformScreenDoors::PlatformDoors> PlatformScreenDoors::GetPlatformScreenDoor(int platform_feature_id)
{
    const std::lock_guard<std::mutex>     DATA_LOCK(m_mutex);

    // Lookup the platform door by platform feature Id
    auto psd_iter = m_platform_feature_id_to_psd_map.find(platform_feature_id);

    if (psd_iter != m_platform_feature_id_to_psd_map.end())
    {
        // Return the Platform Screen Door Data
        return psd_iter->second;
    }

    return nullptr;
}


/// Callback that is called when a feature is created or destroyed
///
///
void PlatformScreenDoors::PSDFeatureWatcherCallback(WorldAPI::FeatureWatcher::CallbackInfo callback_info)
{
    // The Comms mutex is implicitly in scope for the duration of this function.
    const auto &psd = callback_info.object;

    if (psd.IsValid())
    {
        const auto psd_object_id = psd.GetID();
        assert(psd_object_id != Sim::INVALID_NUMBER);

        switch (callback_info.reason)
        {
        case WorldAPI::FeatureWatcher::CallbackInfo::CREATION:
        {
            auto platform_door = std::shared_ptr<PlatformScreenDoors::PlatformDoors>(new PlatformScreenDoors::PlatformDoors(callback_info, m_gateway, m_psd_state_ids, m_state_change_callback));

            if (platform_door != nullptr)
            {
                const std::lock_guard<std::mutex>     DATA_LOCK(m_mutex);

                m_psd_object_id_to_platform_feature_id.insert(std::make_pair(psd_object_id, platform_door->GetPlatformFeatureId()));
                m_platform_feature_id_to_psd_map.insert(std::make_pair(platform_door->GetPlatformFeatureId(), platform_door));
            }
            else
                Trace::GetLogger().STAMP(Trace::ERR) << "Failed to create Plaform Door object for " << psd_object_id << Trace::EndLog();
            break;
        }
        case WorldAPI::FeatureWatcher::CallbackInfo::DESTRUCTION:
        {
            const auto platform_feature_id = m_psd_object_id_to_platform_feature_id[psd_object_id];

            {
                const std::lock_guard<std::mutex> DATA_MEMBER_LOCK(m_mutex);

                m_psd_object_id_to_platform_feature_id.erase(psd_object_id);
                m_platform_feature_id_to_psd_map.erase(platform_feature_id);
            }

            break;
        }
        }
    }
    else
        Trace::GetLogger().STAMP(Trace::ERR) << "Failed to extract Platform Screen Door feature object" << Trace::EndLog();

}


////////////////////////////////////////////////////////////////////////////////////////
// Platfform Screen Door
////////////////////////////////////////////////////////////////////////////////////////


/// Constructor for PSD that is not associated with a PSD feature
///
/// @param psd_info : Contains info about a PSD feature
/// @param simulator_data : Data used to find the different PSD feature states
/// @param psd_state_ids  : Ids that represent the different PSD feature sates
/// @param state_change_callback : Callback to be called when the state of the platform doors changes
///
PlatformScreenDoors::PlatformDoors::PlatformDoors(WorldAPI::FeatureWatcher::CallbackInfo  psd_info,
    Comms::Gateway                         &gateway,
    PSDStatesIds                            psd_state_ids,
    PlatformDoorsStateChangeCallback        state_change_callback)
    : m_gateway(gateway),
    m_current_psd_state(PlatformScreenDoors::PlatformDoors::DoorState::CLOSED),
    m_open_inhibit_code(SD_OPEN_ALL_DOORS), m_close_inhibit_code(SD_CLOSE_ALL_DOORS),
    m_state_change_callback(state_change_callback)
{
    assert(psd_info.object.IsValid());
    assert(psd_info.object.GetID() != Sim::INVALID_OBJECT);

    try
    {
        auto platform_feature_id_property_id = psd_info.object.Numbers().Info().GetID(Project::FeatureProperties::PLATFORM_SCREEN_DOORS::PLATFORM_FEATURE_ID);
        auto sdo_code_property_id = psd_info.object.Numbers().Info().GetID(Project::FeatureProperties::PLATFORM_SCREEN_DOORS::SDO_CODE);
        auto door_position_property_id = psd_info.object.Numbers().Info().GetID(Project::FeatureProperties::PLATFORM_SCREEN_DOORS::DOOR_POSITION);
        auto number_door_property_id = psd_info.object.Numbers().Info().GetID(Project::FeatureProperties::PLATFORM_SCREEN_DOORS::NUMBER_DOORS);

        // Only add the PSD if all the required properties have been defined
        if (platform_feature_id_property_id != Sim::INVALID_NUMBER &&
            sdo_code_property_id != Sim::INVALID_NUMBER &&
            door_position_property_id != Sim::INVALID_NUMBER &&
            number_door_property_id != Sim::INVALID_NUMBER)
        {
            m_object = psd_info.object;
            m_psd_feature_id = GetFeatureID(psd_info.object);
            m_automatic_state_number = psd_info.object.Numbers().Get(Core::ValueName::Feature::AUTOMATIC_STATE);
            m_state_number = psd_info.object.Numbers().Get(Core::ValueName::Feature::STATE);
            m_platform_feature_id = psd_info.object.Numbers().Store().Get(platform_feature_id_property_id);
            m_sd_code = psd_info.object.Numbers().Store().Get(sdo_code_property_id);
            m_doors_position = psd_info.object.Numbers().Store().Get(door_position_property_id);
            m_number_platform_doors = static_cast<int>(psd_info.object.Numbers().Store().Get(number_door_property_id).value);
            m_psd_state_ids = psd_state_ids;

            // Add a listenter for the PSD Door Position
            NumberListener psd_num_listener;
   
            psd_num_listener.AddCallback(m_doors_position, [this](Sim::Number number) { this->PSDDoorPositionUpdated(number); });
            Sim::NumberInfo m_doors_position_info = m_object.Numbers().Info().GetInfo(m_doors_position.id);
            m_object.Numbers().Store().Request(m_doors_position_info, 0);
            m_object.Numbers().Store().AddListener(psd_num_listener);
        }
        else
        {
            Trace::GetLogger().STAMP(Trace::ERR) << "Platform Screen Door '" << psd_info.object.GetName() << "' found without '";

            if (platform_feature_id_property_id == Sim::INVALID_NUMBER)
                Trace::GetLogger().STAMP(Trace::ERR) << Project::FeatureProperties::PLATFORM_SCREEN_DOORS::PLATFORM_FEATURE_ID << "  ";
            if (sdo_code_property_id == Sim::INVALID_NUMBER)
                Trace::GetLogger().STAMP(Trace::ERR) << Project::FeatureProperties::PLATFORM_SCREEN_DOORS::SDO_CODE << "  ";
            if (door_position_property_id == Sim::INVALID_NUMBER)
                Trace::GetLogger().STAMP(Trace::ERR) << Project::FeatureProperties::PLATFORM_SCREEN_DOORS::DOOR_POSITION << "  ";
            if (number_door_property_id == Sim::INVALID_NUMBER)
                Trace::GetLogger().STAMP(Trace::ERR) << Project::FeatureProperties::PLATFORM_SCREEN_DOORS::NUMBER_DOORS << "  ";

            Trace::GetLogger().STAMP(Trace::ERR) << "' property!" << Trace::EndLog();
        }
    }
    catch (CommonException &e)
    {
        Trace::GetLogger().LogException(e);
        Trace::GetLogger().STAMP(Trace::ERR) << "Failed to extract properties for Platform Screen Door feature\""
            << psd_info.object.GetName() << "\" (Object ID: " << psd_info.object.GetID()
            << "). This feature will be ignored." << Trace::EndLog();
    }
}

/// Destructor
///
PlatformScreenDoors::PlatformDoors::~PlatformDoors()
{
}

/// Callback on the PSD Door Position Property
///
/// Determine the state of the platform doors based on the current PSD state and PSD door Position.
/// Upon a change in state will call the state change callback function that was registered with the
/// object when it was created.
///
/// @param number Number associated with PSD Door position property
///
void PlatformScreenDoors::PlatformDoors::PSDDoorPositionUpdated(Sim::Number number)
{
    std::unique_lock<std::mutex>  DATA_LOCK(m_mutex);

    assert(m_state_number.id != Sim::INVALID_NUMBER);
    assert(m_object.IsValid());
    auto prev_psd_state = m_current_psd_state;

    // Determine the Current state
    auto door_position = number.value;
    {
        const std::lock_guard<Comms::Gateway> COMMS_LOCK(m_gateway);
        m_object.Numbers().Store().Get(m_state_number);
    }

    // Only consider doors closed when the door position reaches the doors fully closed position
    if (door_position > DOOR_CLOSE_POSITION)
    {
        if (door_position < DOOR_OPEN_POSITION)
        {
            if (m_state_number.value == m_psd_state_ids.m_psd_open_state)
                m_current_psd_state = PlatformScreenDoors::PlatformDoors::DoorState::OPENING;

            else if (m_state_number.value == m_psd_state_ids.m_psd_closed_state)
                m_current_psd_state = PlatformScreenDoors::PlatformDoors::DoorState::CLOSING;
        }
        else if ((m_state_number.value == m_psd_state_ids.m_psd_open_state) && (m_open_inhibit_code != SD_OPEN_ALL_DOORS) && m_psd_open_fault)
        {
            m_current_psd_state = PlatformScreenDoors::PlatformDoors::DoorState::OPEN_WITH_FAULT;
        }
        else
        {
            m_current_psd_state = PlatformScreenDoors::PlatformDoors::DoorState::OPEN;
        }
    }
    else if (door_position == DOOR_CLOSE_POSITION)
    {
        if ((m_close_inhibit_code != SD_CLOSE_ALL_DOORS) && m_psd_close_fault)
            m_current_psd_state = PlatformScreenDoors::PlatformDoors::DoorState::CLOSED_WITH_FAULT;
        else
            m_current_psd_state = PlatformScreenDoors::PlatformDoors::DoorState::CLOSED;
    }

    // Need to unlock the mutex before calling the callback since the callback may call to a
    // method in this object.
    DATA_LOCK.unlock();

    // Notify callback about state change
    if (m_current_psd_state != prev_psd_state)
        m_state_change_callback(m_psd_feature_id, m_current_psd_state);
}

/// Opens the platform screen door using the SD code provided
///
/// @param sd_code_length : Length of the SD code being provided
/// @param sd_code : SD code where a bit value of one indicates the open is to be inhibited
/// @param invert : Swap the order of the SD code bits. (0110001010 -> 0101000110)
/// @param psd_open_fault : Flags whether PSD fault is present
///
void PlatformScreenDoors::PlatformDoors::OpenPlatformDoors(int sd_code, int sd_code_length, bool invert, bool psd_open_fault)
{
    std::unique_lock<std::mutex>  DATA_LOCK(m_mutex);

    auto psd_sd_code = sd_code;
    m_open_inhibit_code = sd_code;
    m_psd_open_fault = psd_open_fault;

    // Invert the sd code if required
    if (invert)
        psd_sd_code = SwapOrderSDCode(sd_code, sd_code_length, m_number_platform_doors);

    // Need to inhibit any platform doors that do not have an associated train door
    if (m_number_platform_doors > sd_code_length)
        InsertBits(psd_sd_code, sd_code_length, m_number_platform_doors);

    // Set the comms lock
    const std::lock_guard<Comms::Gateway> COMMS_LOCK(m_gateway);

    if (!AllDoorsInhibited(m_open_inhibit_code, sd_code_length))
    {
        // Write out the SD code into the PSD feature
        m_sd_code.value = psd_sd_code;
        m_object.Numbers().Store().Set(m_sd_code);

        // Now Open the doors
        m_object.Numbers().Store().Get(m_doors_position);
        if ((m_current_psd_state == PlatformScreenDoors::PlatformDoors::DoorState::ALL_FAILED_TO_CLOSE))
        {
            // If doors failed to close then they are already open and so we just need to change their state
            m_current_psd_state = PlatformScreenDoors::PlatformDoors::DoorState::OPEN;
            DATA_LOCK.unlock();
            m_state_change_callback(m_psd_feature_id, m_current_psd_state);
        }
        else if ((m_automatic_state_number.value == m_psd_state_ids.m_psd_open_state) && (m_doors_position.value == DOOR_OPEN_POSITION))
        {
            // If we have some open doors already open then reset the door position so that the remaining
            // doors will open. Note that we can do this because if the state is open and the door position
            // is already in the fully open state then the Unigine script will leave the door in the fully 
            // open position and ignore the updates to the door position value.
            if (m_current_psd_state != PlatformScreenDoors::PlatformDoors::DoorState::OPEN)
            {
                m_doors_position.value = DOOR_CLOSE_POSITION;
                m_object.Numbers().Store().Set(m_doors_position);
            }
        }
        else
        {
            // If not already in the open state then place into open state
            m_automatic_state_number.value = m_psd_state_ids.m_psd_open_state;
            m_object.Numbers().Store().Set(m_automatic_state_number);
        }
    }
    else if (m_current_psd_state != PlatformScreenDoors::PlatformDoors::DoorState::OPEN)
    {
        auto prev_psd_state = m_current_psd_state;
        m_current_psd_state = PlatformScreenDoors::PlatformDoors::DoorState::ALL_FAILED_TO_OPEN;

        // Write out the SD code into the PSD feature
        m_sd_code.value = 0.0;
        m_object.Numbers().Store().Set(m_sd_code);

        // Need to unlock the mutex before calling the callback since the callback may call to a
        // method in this object.
        DATA_LOCK.unlock();

        // Notify callback about state change
        if (m_current_psd_state != prev_psd_state)
            m_state_change_callback(m_psd_feature_id, m_current_psd_state);
    }
}

/// Opens the platform screen door using the SD code provided
///
/// This function can be used to open all platform doors that had previously failed to
/// opened due to a fault. In the case where some platform doors have already been opened
/// this function resets the door position to the door closed positin so that the PSD Door
/// control unit will once again start to increment the door position value from 0 down to 100.
/// It should be noted that this is Ok since the unigine script will ignore updating the 
/// door position of any doors that are already in the fully open position. Only the doors
/// that previously failed to open will now open.
///
void PlatformScreenDoors::PlatformDoors::OpenAllPlatformDoors(int sd_code_length)
{
    const std::lock_guard<std::mutex>  DATA_LOCK(m_mutex);

    auto psd_sd_code = SD_OPEN_ALL_DOORS;
    m_open_inhibit_code = SD_OPEN_ALL_DOORS;

    // Need to inhibit any platform doors that do not have an associated train door
    if (m_number_platform_doors > sd_code_length)
        InsertBits(psd_sd_code, sd_code_length, m_number_platform_doors);

    // Set the comms lock
    const std::lock_guard<Comms::Gateway> COMMS_LOCK(m_gateway);

    // Write out the SD code into the PSD feature
    m_sd_code.value = psd_sd_code;
    m_object.Numbers().Store().Set(m_sd_code);

    // Now Open the doors
    m_object.Numbers().Store().Get(m_doors_position);
    if ((m_automatic_state_number.value == m_psd_state_ids.m_psd_open_state) && (m_doors_position.value == DOOR_OPEN_POSITION))
    {
        // If we have some open doors already open then reset the door position so that the remaining
        // doors will open. Note that we can do this because if the state is open and the door position
        // is already in the fully open state then the Unigine script will leave the door in the fully 
        // open position and ignore the updates to the door position value.
        if (m_current_psd_state != PlatformScreenDoors::PlatformDoors::DoorState::OPEN)
        {
            m_doors_position.value = DOOR_CLOSE_POSITION;
            m_object.Numbers().Store().Set(m_doors_position);
        }
    }
    else
    {
        // If not already in the open state then place into open state
        m_automatic_state_number.value = m_psd_state_ids.m_psd_open_state;
        m_object.Numbers().Store().Set(m_automatic_state_number);
    }
}

/// Closes the platform screen door using the SD code provided
///
/// @param sd_code : SD code where a bit value of one indicates the close is to be inhibited
/// @param sd_code_length : Length of the SD code being provided
/// @param invert : Swap the order of the SD code bits
/// @param psd_close_fault : Flags whether PSD fault is present
///
void PlatformScreenDoors::PlatformDoors::ClosePlatformDoors(int sd_code, int sd_code_length, bool invert, bool psd_close_fault)
{
    std::unique_lock<std::mutex>  DATA_LOCK(m_mutex);

    auto psd_sd_code = sd_code;
    m_close_inhibit_code = sd_code;
    m_psd_close_fault = psd_close_fault;

    // Invert the sd code if required
    if (invert)
        psd_sd_code = SwapOrderSDCode(sd_code, sd_code_length, m_number_platform_doors);

    // Need to inhibit any platform doors that do not have an associated train door
    if (m_number_platform_doors > sd_code_length)
        InsertBits(psd_sd_code, sd_code_length, m_number_platform_doors);

    // Set the Comms Lock
    const std::lock_guard<Comms::Gateway> COMMS_LOCK(m_gateway);

    if (!AllDoorsInhibited(m_close_inhibit_code, sd_code_length))
    {
        // Write out the SD code into the PSD feature
        m_sd_code.value = psd_sd_code;
        m_object.Numbers().Store().Set(m_sd_code);

        // Now Close the doors
        m_object.Numbers().Store().Get(m_doors_position);
        if ((m_current_psd_state == PlatformScreenDoors::PlatformDoors::DoorState::ALL_FAILED_TO_OPEN))
        {
            // If doors failed to open then they are already closed and so we just need to change their state
            m_current_psd_state = PlatformScreenDoors::PlatformDoors::DoorState::CLOSED;
            DATA_LOCK.unlock();
            m_state_change_callback(m_psd_feature_id, m_current_psd_state);
        }
        else if ((m_automatic_state_number.value == m_psd_state_ids.m_psd_closed_state) && (m_doors_position.value == DOOR_CLOSE_POSITION))
        {
            // If we have some doors already closed (but not all) then reset the door position so that the remaining doors
            // will close. Note that we can do this because if the PSD state is closed and the door position
            // is already in the fully closed state then the Unigine script will leave the door in the fully
            // closed position and ignore the updates to the door position value.
            if ((m_current_psd_state != PlatformScreenDoors::PlatformDoors::DoorState::CLOSED))
            {
                m_doors_position.value = DOOR_OPEN_POSITION;
                m_object.Numbers().Store().Set(m_doors_position);
            }
        }
        else
        {
            // If not already in the closed state then place PSD into closed state
            m_automatic_state_number.value = m_psd_state_ids.m_psd_closed_state;
            m_object.Numbers().Store().Set(m_automatic_state_number);
        }
    }
    else if (m_current_psd_state != PlatformScreenDoors::PlatformDoors::DoorState::CLOSED)
    {
        auto prev_psd_state = m_current_psd_state;
        m_current_psd_state = PlatformScreenDoors::PlatformDoors::DoorState::ALL_FAILED_TO_CLOSE;

        // Write out the SD code into the PSD feature
        m_sd_code.value = 0.0;
        m_object.Numbers().Store().Set(m_sd_code);

        // Need to unlock the mutex before calling the callback since the callback may call to a
        // method in this object.
        DATA_LOCK.unlock();

        // Notify callback about state change
        if (m_current_psd_state != prev_psd_state)
            m_state_change_callback(m_psd_feature_id, m_current_psd_state);
    }
}

/// Closes all platform screen door
///
/// This function can be used to close all platform doors that had previously failed to
/// close due to a fault. In the case where some platform doors have already been closed
/// this function resets the door position to the open positin so that the PSD Door control
/// unit will once again start to decrement the door position value from 100 down to 0.
/// It should be noted that this is Ok since the unigine script will ignore updating the 
/// door position of any doors that are already in the fully closed position. Only the doors
/// that previously failed to be closed will now close.
///
void PlatformScreenDoors::PlatformDoors::CloseAllPlatformDoors(int sd_code_length)
{
    const std::lock_guard<std::mutex>  DATA_LOCK(m_mutex);

    auto psd_sd_code = SD_CLOSE_ALL_DOORS;
    m_close_inhibit_code = SD_CLOSE_ALL_DOORS;

    // Need to inhibit any platform doors that do not have an associated train door
    if (m_number_platform_doors > sd_code_length)
        InsertBits(psd_sd_code, sd_code_length, m_number_platform_doors);

    // Set the Comms Lock
    const std::lock_guard<Comms::Gateway> COMMS_LOCK(m_gateway);

    // Write out the SD code into the PSD feature
    m_sd_code.value = psd_sd_code;
    m_object.Numbers().Store().Set(m_sd_code);

    // Now Close the doors
    m_object.Numbers().Store().Get(m_doors_position);
    if ((m_automatic_state_number.value == m_psd_state_ids.m_psd_closed_state) && (m_doors_position.value == DOOR_CLOSE_POSITION))
    {
        // If we have some doors already closed (but not all) then reset the door position so that the remaining doors
        // will close. Note that we can do this because if the PSD state is closed and the door position
        // is already in the fully closed state then the Unigine script will leave the door in the fully
        // closed position and ignore the updates to the door position value.
        if ((m_current_psd_state != PlatformScreenDoors::PlatformDoors::DoorState::CLOSED) &&
            (m_current_psd_state != PlatformScreenDoors::PlatformDoors::DoorState::ALL_FAILED_TO_OPEN))
        {
            m_doors_position.value = DOOR_OPEN_POSITION;
            m_object.Numbers().Store().Set(m_doors_position);
        }
    }
    else
    {
        // If not already in the closed state then place PSD into closed state
        m_automatic_state_number.value = m_psd_state_ids.m_psd_closed_state;
        m_object.Numbers().Store().Set(m_automatic_state_number);
    }
}

/// Returns the feature id of the platform screen door
///
/// @returns feature Id of the platform screen door
///
int PlatformScreenDoors::PlatformDoors::GetPSDFeatureId()
{
    const std::lock_guard<std::mutex> DATA_MEMBER_LOCK(m_mutex);

    return m_psd_feature_id;
}

/// Returns the feature id of the platform associated with the platform screen door
///
/// @returns platform feature Id associated with the platform screen door
///
int PlatformScreenDoors::PlatformDoors::GetPlatformFeatureId()
{
    const std::lock_guard<std::mutex> DATA_MEMBER_LOCK(m_mutex);

    {
        const std::lock_guard<Comms::Gateway> COMMS_LOCK(m_gateway);
        m_object.Numbers().Store().Get(m_platform_feature_id);
        return static_cast<int>(m_platform_feature_id.value);
    }
}

/// Returns the current state of the platform screen door
///
/// Platform Doors are considered to be open if any of the doors are not completely shut
///
/// @returns current state of the platform screen door
///
PlatformScreenDoors::PlatformDoors::DoorState PlatformScreenDoors::PlatformDoors::GetPlatformDoorsState()
{
    const std::lock_guard<std::mutex> DATA_MEMBER_LOCK(m_mutex);

    return m_current_psd_state;
}