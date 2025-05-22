/// @file FeatureHelpers.h
/// Free-standing functions to retrieve info on features.
///
/// @copyright © SYDAC Pty Ltd, 2018

#pragma once

#include <core_data_access/Feature.h>
#include <core_comms_structure/CoreObjectConstants.h>
#include <sim_comms/Object.h>

#include <set>
#include <string>

namespace
{
    const double    INVALID_STATE   = -1.0;
    const int       INVALID_TYPE    = -1;
}

namespace Project
{
    static inline std::set<int> GetFeatureTypeIDsInGroup(Common::Data::DataAccess &data_access, const std::string &group_name)
    {
        std::set<int> ret;

        Core::Database::Feature feature_access(data_access);
        std::vector<Core::Data::FeatureType> feature_types = feature_access.GetAllFeatureTypes();

        for (auto &feature_type : feature_types)
        {
            if (feature_type.feature_type_group_name == group_name)
            {
                ret.insert(feature_type.feature_type_id);
            }
        }

        return ret;
    }

    static inline int GetTypeOfObject(const Comms::Object &obj)
    {
        int type = INVALID_TYPE;
        if (obj.IsValid())
        {
            auto feature_type_id_property = obj.Numbers().Info().GetID(Core::ValueName::Feature::TYPE);
            type = static_cast<int>(obj.Numbers().Store().Get(feature_type_id_property).value);
        }

        return type;
    }

    static inline double GetStateOfObject(const Comms::Object &obj)
    {
        double state = INVALID_STATE;
        if (obj.IsValid())
        {
            auto state_property_id = obj.Numbers().Info().GetID(Core::ValueName::Feature::STATE);
            state = obj.Numbers().Store().Get(state_property_id).value;
        }

        return state;
    }
}
