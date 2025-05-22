/// @file ReverseProfile.h
/// Free-standing functions to get feature orientation and reverse path features.
///
/// @author    Adam Zielinski
/// @copyright © SYDAC Pty Ltd, 2017
#pragma once

#include "WorldAPI/WorldAccess.h"

#include "SydacCommon/StandardLogging.h"
#include "Utility/Utilities.h"

namespace ReverseProfile
{
    namespace 
    {
        
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
            assert (object.IsValid());
            assert (Core::GetClassID(object) == Core::ClassID::FEATURE);
            
            // If this object is a Feature we can look for the FEATUREID
            ret = static_cast<int>(object.Numbers().Get(Core::ValueName::Feature::FEATURE_ID).value);

            return ret;
        }
    }

    /// Finds the features on the train path for a train travelling in the reverse direction.
    ///
    /// Position of the given features is relative to the rear of the train with positive numbers
    /// being ahead of the train in it's current direction of movement
    ///
    /// @param world_access                   : World Access API
    /// @param path                           : Path to be searched
    /// @param feature_track_associations_fwd : Associations for features in the direction in which train is oriented
    /// @param feature_track_associations_all : Associations for features in both directions of travel
    /// @param train_length                   : Length of the train. Is used to find the rear train position
    /// @param start_position                 : Start of the path we wish to search
    /// @param end_position                   : End of the path we wish to search
    ///
    /// @returns Pairs containing the (location, object) of path features that appear when train travelling in the reverse direction
    ///
    static std::vector<std::pair<double, Comms::Object>> GetReversePathFeatures(WorldAPI::WorldAccess          &world_access,
                                                                                const WorldAPI::SegmentPath    &path,
                                                                                WorldAPI::TrackAssociationMap   feature_track_associations_fwd,
                                                                                WorldAPI::TrackAssociationMap   feature_track_associations_all,
                                                                                const double                    train_length,
                                                                                const double                    start_position = -std::numeric_limits<double>::max(),
                                                                                const double                    end_position = std::numeric_limits<double>::max())
    {
        std::vector<std::pair<double, Comms::Object>> path_features_rev;

        // Determine which of the features are visible on the path ahead of the train when it is travelling in the reverse direction
        // Note that this approach assumes that all permisible speed signs are uni directional
        auto path_features_fwd = world_access.GetPathFeatures(path, feature_track_associations_fwd, start_position, end_position);
        auto path_features_all = world_access.GetPathFeatures(path, feature_track_associations_all, start_position, end_position);

        // Returns true if two objects have different feature Ids
        auto FeaturesDifferent = [&](const std::pair<double, Comms::Object> &a, const std::pair<double, Comms::Object> &b)
                                    {
                                        return GetFeatureID(a.second) != GetFeatureID(b.second);
                                    };

        std::set_symmetric_difference(path_features_all.begin(), path_features_all.end(), 
                                      path_features_fwd.begin(), path_features_fwd.end(), 
                                      std::back_inserter(path_features_rev), FeaturesDifferent);
        // In the reverse profile case we need to reverse the order, multiple by -1 and subtract the length of the train
        // in order to determine the distance from the rear of the train to the track feature 
        std::reverse(std::begin(path_features_rev), std::end(path_features_rev));
        transform(path_features_rev.begin(), path_features_rev.end(), path_features_rev.begin(), 
            [&](std::pair<double, Comms::Object> &next_feature)
            {
                next_feature.first = (next_feature.first * -1.0) - train_length;
                return next_feature;
            });

        return path_features_rev;
    }
}
