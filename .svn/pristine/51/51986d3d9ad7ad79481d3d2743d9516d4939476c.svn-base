///**************************************************************************************************
/// @file LMAFeatures.h
///
/// @author    Adam Zielinski
///
/// @copyright © SYDAC Pty Ltd, 2020
///**************************************************************************************************

#include "LMAFeatures.h"

#include "core_data_access/Feature.h"
#include "core_comms_structure/CoreObjectConstants.h"
#include "project_features/ProjectFeatureConstants.h"

#include "Utility/Utilities.h"

#include <algorithm>

// Stop state constants
const int STOP_STATE_RED_OFF = 1;
const int STOP_STATE_VIOLET  = 2;
const int STOP_STATE_GREEN   = 3;

const int STOP_STATE_ON = 1;
const int STOP_STATE_OFF  = 2;

namespace
{
    // Request LMA feature updates as soon as they change.
    // This will then trigger the Feature Watcher Callback/
    const auto REQUEST_FREQUENCY    = 20.0;  
    const auto DEBUG                = false;
    const auto MA_INHIBIT_DISABLED  = 0.0;

    /// Returns the value of the Feature ID of a feature object.
    ///
    /// @param object The object to get the Feature ID of.
    ///
    /// @return  The Feature ID Value corresponding to the position Number, or -1 if one does not
    ///          exist (or if the object is not a Feature).
    ///
    int GetFeatureID(Comms::Object object)
    {
        int ret = Sim::INVALID_NUMBER;

        // Test the code in debug - we should never be calling this for a non feature object.
        assert (object.IsValid());
        assert (Core::GetClassID(object) == Core::ClassID::FEATURE);
            
        // If this object is a Feature we can look for the FEATUREID
        ret = static_cast<int>(object.Numbers().Get(Core::ValueName::Feature::FEATURE_ID).value);

        return ret;
    }

    /// Helper function that, given an object, attempts to get it's feature type as an integer and
    /// returns it. If the object does not exist a value of -1 is returned.
    ///
    /// @param object  The object to get the feature type ID for.
    ///
    double GetFeatureTypeId(Comms::Object object)
    {
        assert(object.IsValid());
        try
        {
            const auto FEATURE_TYPE_ID = object.Numbers().Info().GetID(Core::ValueName::Feature::TYPE);
            return object.Numbers().Store().Get(FEATURE_TYPE_ID).value;
        }
        catch(...)
        {
            return Sim::INVALID_NUMBER;
        }
    }

}

using namespace LMA;

/// Constructor
///
/// @param gateway          The comms gateway
/// @param simulator_data   Object to access the simulator database
/// @param world_access     World Access API
/// @param path_watcher     Path Watcher for the train path
///
LMAFeatures::LMAFeatures(Comms::Gateway                  &gateway,
                         Common::Data::DataAccess        &data_access,
                         WorldAPI::WorldAccess           &world_access,
                         WorldAPI::TrainPathWatcher      &path_watcher)
  : m_gateway(gateway), 
    m_world_access(world_access),
    m_data_access(data_access),
    m_train_path_watcher(path_watcher),
    m_initialised(false)
{
    const std::lock_guard<std::mutex> DATA_MEMBER_LOCK(m_mutex);

    // The first step is to use the database to generate our state map.
    std::vector<Core::Data::FeatureTypeState> all_states;
    try
    {
        const auto features = Core::Database::Feature(m_data_access);
        all_states = features.GetAllFeatureTypeStates();
        m_main_line_signal_long_feature_id = features.GetFeatureType(Project::FeatureTypes::FETY_MAIN_LINE_SIGNAL_LONG).feature_type_id;
        m_shunt_signal_feature_id = features.GetFeatureType(Project::FeatureTypes::FETY_SHUNT_SIGNAL).feature_type_id;
        m_main_line_signal_short_feature_id = features.GetFeatureType(Project::FeatureTypes::FETY_MAIN_LINE_SIGNAL_SHORT).feature_type_id;
    }
    catch(CommonException &e)
    {
        e.AddStackTrace(FLSTAMP, "Querying for a list of all possible feature states.");
        throw;
    }

    // Populate a map of stop states for signals. To do this we just run 
    // through all of our states and look for the states that correspond
    // to a stop state! Track the signal types to set our filter with later.
    // NOTE:
    // CBTC must ignore traffic light controlled signals because they should have no effect on the CBTC system.
    // It's the driver's responsibility to stop at red signals. CBTC has not integrated system with traffic lights
    // and thus speed monitoring/hooks should not be affected but the traffic signal state
    for(size_t i = 0; i < all_states.size(); ++i)
    {
        if (all_states[i].stop_state == STOP_STATE_RED_OFF)
        {
           m_signal_stop_states[all_states[i].feature_type_id].insert(std::pair<int, int>(all_states[i].feature_type_state_id, all_states[i].stop_state));
           m_signal_types.insert(all_states[i].feature_type_id);
        }
        if (all_states[i].feature_type_id == m_shunt_signal_feature_id)
        {
            if (all_states[i].feature_type_state_id == STOP_STATE_ON)
            {
                m_signal_stop_states[all_states[i].feature_type_id].insert(std::pair<int, int>(all_states[i].feature_type_state_id, STOP_STATE_ON));
                m_signal_types.insert(all_states[i].feature_type_id);
            }
        }
    }

    // NOTE: The Feature Watcher used to be created here, in the constructor
    // but the feature watcher could potentially receive STATE_CHANGE callbacks out of sequence during the initalisation of the track.
    // The track points are controlled via script and initial scenario script conditions.
    // For some reason, 1 out of 10 times the feature watcher callback would receive notifications about a feature state in different order & then be out of sync with comms.
    // this would result in the LMAUnit thinking a feature was in the STOP state when in fact it was in a PERMISSIVE state, hence affecting the moving authority for the tram.
    // SOLUTION:
    // Move the FeatureWatcher creation code out of the constructor and into the first tick of the Unit, after the Session is started
}

void LMAFeatures::init_feature_watcher()
{
    if (m_initialised)
        return;

    // Set the features types that the LMA feature watcher is interested in
    m_lma_feature_feature_type_filter.SetAcceptableTypes(std::vector<int>(m_signal_types.begin(), m_signal_types.end()));

    // Filter the feature watcher to only watch for our LMA features and add a callback to handle updates
    m_lma_feature_feature_watcher.SetFeatureTypeFilter(WorldAPI::CreateFilterCallback(m_lma_feature_feature_type_filter));
    m_lma_feature_feature_watcher.SetRequestFrequency(REQUEST_FREQUENCY);
    m_lma_feature_feature_watcher.AddCallback(MakeCallback(&LMAFeatures::LMAFeatureWatcherCallback, this));

    {
        const std::lock_guard<Comms::Gateway> COMMS_LOCK(m_gateway);

        auto root_object = m_gateway.GetRootObject();
        m_lma_feature_feature_watcher.Attach(root_object);
    }

    m_initialised = true;
}

/// Destructor
///
LMAFeatures::~LMAFeatures()
{
    const std::lock_guard<std::mutex> DATA_MEMBER_LOCK(m_mutex);

    const std::lock_guard<Comms::Gateway> COMMS_LOCK(m_gateway);
    m_lma_feature_feature_watcher.Detach();
}

/// Update the information about the lma features on the path of a train travelling
/// in the forward direction
///
/// Important to note that the position of the train is relative to the front of the lead vehicle
///
void LMAFeatures::UpdateLMAFeaturesOnForwardPath()
{
    init_feature_watcher();

    const std::lock_guard<std::mutex> DATA_MEMBER_LOCK(m_mutex);

    // Invalidate all of the existing lma feature data    
    m_next_lma_feature.second.m_is_valid = false;
    m_next_stop_lma_feature.second.m_is_valid = false;
    m_previous_lma_feature.second.m_is_valid = false;
    m_last_lma_feature.second.m_is_valid = false;

   // Find all of the lma features on the path ahead of a train travelling in the forward direction
    m_path_features_ahead = [this]()
    {
        const std::lock_guard<WorldAPI::TrainPathWatcher> PATH_WATCHER_LOCK(m_train_path_watcher);

        if(m_train_path_watcher.HasPath())
            return m_world_access.GetPathFeatures(m_train_path_watcher.GetExtendedPath(), m_train_path_track_associations, 0.0, std::numeric_limits<double>::max());

        return std::vector<std::pair<double, Comms::Object>>();
    }();
    
    // Find the Next, Next Stop, next POS and nextEnd Point lma features
    if (m_path_features_ahead.size() > 0)
    {
        GetFeaturesOnPathAhead(m_path_features_ahead, m_next_lma_feature, m_next_stop_lma_feature, m_last_lma_feature);

        if (DEBUG)
        {
            Trace::GetLogger().STAMP(Trace::INFO)
                << "UpdateLMAFeaturesOnForwardPath Ahead " <<  m_path_features_ahead.size() <<  "\n=================="
                << "\n m_next_lma_feature:" << m_next_lma_feature.first << ", " << m_next_lma_feature.second.m_object.GetName()
                << "\n m_next_stop_lma_feature:" << m_next_stop_lma_feature.first << ", " << m_next_stop_lma_feature.second.m_object.GetName() << ", IsSignalStop:" << m_next_stop_lma_feature.second.IsSignalStop() << ", StateValue:" << m_next_stop_lma_feature.second.GetStateValue()
                << "\n m_last_lma_feature:" << m_last_lma_feature.first << ", " << m_last_lma_feature.second.m_object.GetName()
                << Trace::EndLog();

            for (auto &a : m_path_features_ahead)
                Trace::GetLogger().STAMP(Trace::ERR) << a.first << "," << GetFeatureID(a.second) << " " ;

             Trace::GetLogger().STAMP(Trace::ERR) << Trace::EndLog();
        }
    }

    // Find all of the lma features on the path behind a train travelling in the forward direction
    m_path_features_behind = [this]()
    {
        const std::lock_guard<WorldAPI::TrainPathWatcher> PATH_WATCHER_LOCK(m_train_path_watcher);

        if(m_train_path_watcher.HasPath())
            return m_world_access.GetPathFeatures(m_train_path_watcher.GetExtendedPath(), m_train_path_track_associations, -std::numeric_limits<double>::max(), 0.0);

        return std::vector<std::pair<double, Comms::Object>>();
    }();
    
    // Find the Previous lma feature
    if (m_path_features_behind.size() > 0)
    {
        GetFeaturesOnPathBehind(m_path_features_behind, m_previous_lma_feature);

        if (DEBUG)
        {
            Trace::GetLogger().STAMP(Trace::INFO)
                << "UpdateLMAFeaturesOnForwardPath Behind " <<  m_path_features_behind.size() <<  "\n=================="
                << "\n m_previous_lma_feature:" << m_previous_lma_feature.first << ", " << m_previous_lma_feature.second.m_object.GetName()
                << Trace::EndLog();

            for (auto &a : m_path_features_behind)        
                Trace::GetLogger().STAMP(Trace::ERR) << a.first << "," << GetFeatureID(a.second) << " " ;

             Trace::GetLogger().STAMP(Trace::ERR) << Trace::EndLog();
        }
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////
// Class LMAFeatures::LMAFeatureData functions
/////////////////////////////////////////////////////////////////////////////////////////////////

int LMAFeatures::LMAFeatureData::GetStateValue() const
{
    return m_state_value;
}

/// Returns true if the lma feature is a feature that represents an LMA stop point
///
/// @returns true if the lma feature represents an LMA stop point
///
bool LMAFeatures::LMAFeatureData::IsSignalStop() const
{
    if (m_lma_feature_type == LMAFeatureType::SIGNAL)
    {
        const auto it = m_signal_stop_states.find(GetStateValue());
        if (it != m_signal_stop_states.end() && (it->second > 0))
            return true;
    }
    return false;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Functions for finding lma features on the path
////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// Returns data about the next LMA feature on the path
///
/// Important Note: The reported position of a feature for a train travelling in the forward direction
///                 is relative to the front of the train whereas the reported position of a feature for
///                 a train travelling in the reverse direction is relative to the rear of the train
///
/// LMA feature data is marked as invalid if no LMA feature found
///
/// @returns Position and data about the next LMA feature found on the path.
///
LMAFeatures::LMAFeatureOnPath LMAFeatures::GetNextLMAFeature() const
{
    return m_next_lma_feature;
}

/// Returns data about the previous LMA feature on the path
///
/// Important Note: The reported position of a feature for a train travelling in the forward direction
///                 is relative to the front of the train whereas the reported position of a feature for
///                 a train travelling in the reverse direction is relative to the rear of the train
///
/// LMA feature data is marked as invalid if no LMA feature found
///
/// @returns Position and data about the previous LMA feature found on the path.
///
LMAFeatures::LMAFeatureOnPath LMAFeatures::GetPreviousLMAFeature() const
{
    return m_previous_lma_feature;
}

/// Returns data about the next LMA feature on the path which is in the Stop state
///
/// Important Note: The reported position of a feature for a train travelling in the forward direction
///                 is relative to the front of the train whereas the reported position of a feature for
///                 a train travelling in the reverse direction is relative to the rear of the train
///
/// LMA feature data is marked as invalid if no LMA feature found
///
/// @returns Position and data about the next Stop LMA feature found on the path.
///
LMAFeatures::LMAFeatureOnPath LMAFeatures::GetNextStopLMAFeature() const
{
    return m_next_stop_lma_feature;
}

/// Returns data about the last LMA feature on the path
///
/// Important Note: The reported position of a feature for a train travelling in the forward direction
///                 is relative to the front of the train whereas the reported position of a feature for
///                 a train travelling in the reverse direction is relative to the rear of the train
///
/// LMA feature data is marked as invalid if no LMA feature found
///
/// @returns Position and data about the last LMA feature on the path. 
///
LMAFeatures::LMAFeatureOnPath LMAFeatures::GetLastLMAFeature() const
{
    return m_last_lma_feature;
}

/// Returns the current state of a LMA feature
///
/// @param lma_feature LMA feature whose current state we want
///
///@returns the current state of the LMA Feature
///
LMAFeatures::State LMAFeatures::GetLMAFeatureState(LMAFeatures::LMAFeatureData lma_feature) const
{
    // Convert the Comms feature state into an LMA Feature state
    if (lma_feature.m_lma_feature_type == LMAFeatureType::SIGNAL)
    {
        if (lma_feature.IsSignalStop())
            return State::STOP;
        else
            return State::PROCEED;
    }

    return State::UNDEFINED;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Functions related to feature watcher
////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// This is the callback function registered with the feature watcher. It handles the actions required to
/// occur upon the creation and destruction of a LMA Feature object. 
///
/// @param callback_info Describes the feature object that has changed, and why we are being notified.
///
void LMAFeatures::LMAFeatureWatcherCallback(WorldAPI::FeatureWatcher::CallbackInfo callback_info)
{
    // The Comms mutex is implicitly in scope for the duration of this function.
    const auto &lma_feature_object = callback_info.object;

    if (lma_feature_object.IsValid()) 
    {
        const auto lma_feature_object_id = lma_feature_object.GetID();
        assert(lma_feature_object_id != Sim::INVALID_NUMBER);

        switch(callback_info.reason)
        {
            case WorldAPI::FeatureWatcher::CallbackInfo::CREATION:
            {
                int feature_type_id = static_cast<int>(GetFeatureTypeId(callback_info.object));
 
                if (m_signal_types.find(feature_type_id) != m_signal_types.end())
                {
                    try
                    {
                        LMAFeatureData lma_feature;
                        lma_feature.m_lma_feature_type   = LMAFeatureType::SIGNAL;
                        lma_feature.m_object             = callback_info.object;
                        lma_feature.m_feature_id         = GetFeatureID(callback_info.object);
                        lma_feature.m_state_value        = static_cast<int>(callback_info.object.Numbers().Get(Core::ValueName::Feature::STATE).value);
                        lma_feature.m_osp                = -2.5;
                        lma_feature.m_pop                = 0.0;
                        lma_feature.m_signal_stop_states = m_signal_stop_states[feature_type_id];
                        lma_feature.m_is_valid           = true;

                        {
                            const std::lock_guard<std::mutex> DATA_MEMBER_LOCK(m_mutex);

                            m_feature_obj_id_to_data.insert(std::make_pair(lma_feature_object_id, lma_feature));
                            m_train_path_track_associations.AddFeature(lma_feature_object);
      
                            if (true)
                            {
                                Trace::GetLogger().STAMP(Trace::INFO)
                                    << "Adding LMA Feature: " << lma_feature.m_object.GetID() << ", " << lma_feature.m_object.GetName()
                                    << "\n feature_type_id: " << feature_type_id
                                    << "\n State Value:" << lma_feature.GetStateValue()
                                    << Trace::EndLog();
                            }
                        }
                    }
                    catch(CommonException &e)
                    {
                        Trace::GetLogger().LogException(e);
                        Trace::GetLogger().STAMP(Trace::ERR) << "Failed to extract properties for Signal feature\""
                                                             << lma_feature_object.GetName() << "\" (Object ID: " << lma_feature_object_id
                                                             << "). This feature will be ignored." << Trace::EndLog();
                    }
                }

               break;
            }
            case WorldAPI::FeatureWatcher::CallbackInfo::DESTRUCTION:
            {
                const std::lock_guard<std::mutex> DATA_MEMBER_LOCK(m_mutex);

                // Remove the LMA feature
                m_feature_obj_id_to_data.erase(lma_feature_object_id);
                m_train_path_track_associations.RemoveFeature(lma_feature_object);

                break;
            }
            case WorldAPI::FeatureWatcher::CallbackInfo::STATE_CHANGE:
            {
                const std::lock_guard<std::mutex> DATA_MEMBER_LOCK(m_mutex);

                // Update the state of the LMA feature upon a state change
                auto id_to_lma_feature_data_iter = m_feature_obj_id_to_data.find(lma_feature_object_id);
                if (id_to_lma_feature_data_iter != m_feature_obj_id_to_data.end() && id_to_lma_feature_data_iter->second.m_object.IsValid())
                {
                    const std::lock_guard<Comms::Gateway> COMMS_LOCK(m_gateway);
                    //id_to_lma_feature_data_iter->second.m_object.Numbers().Store().Get(id_to_lma_feature_data_iter->second.m_state_number);

                    auto& lma_feature = id_to_lma_feature_data_iter->second;
                    lma_feature.m_state_value = static_cast<int>(callback_info.object.Numbers().Get(Core::ValueName::Feature::STATE).value);

                    if (DEBUG)
                    {
                        Trace::GetLogger().STAMP(Trace::INFO)
                            << "### LMA Feature Changed: " << lma_feature.m_object.GetID() << ", " << lma_feature.m_object.GetName()
                            << "\n State Value:" << lma_feature.GetStateValue()
                            << Trace::EndLog();
                    }
                }

                break;
            }
        }
    }
    else
    {
        Trace::GetLogger().STAMP(Trace::ERR) << "Failed to extract LMA feature object" << Trace::EndLog();
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Helper Functions 
////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// Gets the LMA features of interest that appear on the path ahead of the train
///
/// @param lma_features_on_path_ahead   Vector of the LMA Features on the path ahead of the train along with there location
/// @param next_lma_feature             First LMA feature that appears ahead of the train
/// @param next_stop_lma_feature        First LMA feature, in the Stop state, that appears ahead of the train
/// @param last_lma_feature             Last LMA feature that appears on the path ahead of the train
///
/// The returned LMA feature data is marked as invalid if no LMA feature found
///
void LMAFeatures::GetFeaturesOnPathAhead(const std::vector<std::pair<double, Comms::Object>> &lma_features_on_path_ahead,
                                         LMAFeatures::LMAFeatureOnPath                       &next_lma_feature,
                                         LMAFeatures::LMAFeatureOnPath                       &next_stop_lma_feature,
                                         LMAFeatures::LMAFeatureOnPath                       &last_lma_feature)
{
    // Find the first lma feature on the path ahead
    auto first_lma_feature_ahead = lma_features_on_path_ahead.begin();

    if(first_lma_feature_ahead == lma_features_on_path_ahead.end())
        return;

    const auto &lma_feature_object = first_lma_feature_ahead->second;
    {
        next_lma_feature.first  = first_lma_feature_ahead->first;
        next_lma_feature.second = m_feature_obj_id_to_data.at(lma_feature_object.GetID());

        if (DEBUG)
        {
            Trace::GetLogger().STAMP(Trace::VERBOSE)
                << "Found first LMA Feature " << first_lma_feature_ahead->first << " - " 
                << next_lma_feature.second.m_object.GetName() << " - " << next_lma_feature.second.m_feature_id
                << Trace::EndLog();
        }
    }

    // Find the last lma feature on the path ahead
    auto last_lma_feature_ahead = lma_features_on_path_ahead.rbegin();
    const auto &last_lma_feature_object = last_lma_feature_ahead->second;
    {
        last_lma_feature.first  = last_lma_feature_ahead->first;
        last_lma_feature.second = m_feature_obj_id_to_data.at(last_lma_feature_object.GetID());

        if (DEBUG)
        {
            Trace::GetLogger().STAMP(Trace::VERBOSE)
                << "found last LMA Feature " << last_lma_feature_ahead->first << " - " 
                << last_lma_feature.second.m_object.GetName() << " - " << last_lma_feature.second.m_feature_id
                << Trace::EndLog();
        }
    }

    // Find the Next Stop LMA feature
    for(const auto &lma_feature_on_path : lma_features_on_path_ahead)
    {
        const auto lma_position = lma_feature_on_path.first;
        const auto &lma_feature_object = lma_feature_on_path.second;

        try
        {
            const auto lma_feature_data = m_feature_obj_id_to_data.at(lma_feature_object.GetID());

            // Record the LMA Features of interest
            if(lma_feature_data.IsSignalStop())
            {
                // Found the next Stop state lma feature on the path ahead
                next_stop_lma_feature.first = lma_position;
                next_stop_lma_feature.second = lma_feature_data;
                
                Trace::GetLogger().STAMP(Trace::VERBOSE)
                    << "Found next stop LMA Feature " << lma_feature_data.m_feature_id << " - " << lma_feature_data.m_object.GetName()
                    << "\n lma_feature_data.m_is_valid:" << lma_feature_data.m_is_valid
                    << "\n lma_position:" << lma_position
                    << Trace::EndLog();

                return;
            }
        }
        catch (std::exception& ex)   // Couldn't figure out the lma feature data for this lma feature id.
        { 
            Trace::GetLogger().STAMP(Trace::ERR) << "UpdateLMAFeaturesOnForwardPath " << ex.what() << Trace::EndLog();
        } 
    }
}

/// Gets the LMA features of interest that appear on the path behind of the train
///
/// @param lma_features_on_path_behind Vector of the LMA Features on the path behind the train along with there location
/// @param previous_lma_feature        First LMA feature that appears behind the train
///
/// The returned LMA feature data is marked as invalid if no LMA feature found
///
void LMAFeatures::GetFeaturesOnPathBehind(const std::vector<std::pair<double, Comms::Object>>  &lma_features_on_path_behind,
                                          LMAFeatures::LMAFeatureOnPath                        &previous_lma_feature)
{
    // Find the previous markboard on the path behind
    auto first_lma_feature_behind = lma_features_on_path_behind.rbegin();
    const auto &lma_feature_object = first_lma_feature_behind->second;
    {
        previous_lma_feature.first = first_lma_feature_behind->first;
        previous_lma_feature.second = m_feature_obj_id_to_data.at(lma_feature_object.GetID());

        Trace::GetLogger().STAMP(Trace::VERBOSE)
            << "Previous LMA Feature is " << first_lma_feature_behind->first << " - " 
            << previous_lma_feature.second.m_feature_id
            << Trace::EndLog();
    }
}