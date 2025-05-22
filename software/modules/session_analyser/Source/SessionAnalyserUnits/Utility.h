/**
*  @file       This file contains the utility functions
*
* Raghu Gandi 
*
*  @copyright  © SYDAC Pty Ltd, 2018
*/

#pragma once

#include <sim_comms/Object.h>
#include "core_data_access/Feature.h"
#include "core_comms_structure/CoreObjectConstants.h"

namespace
{
    const int INVALID_TYPE = -1;

    Sim::Number GetRequiredNumber(Comms::Object object, const char *property)
    {
        assert(object.IsValid());

        if (object.IsValid())
        {
            auto number_id = object.Numbers().Info().GetID(property);

            assert(number_id != Sim::INVALID_NUMBER);

            if (number_id != Sim::INVALID_NUMBER)
            {
                return object.Numbers().Store().Get(number_id);
            }
        }
        return Sim::Number();
    }

    int GetFeatureTypeID(Core::Database::Feature &feature, const std::string &feature_name)
    {
        try
        {
            return feature.GetFeatureType(feature_name).feature_type_id;
        }
        catch (CommonException &e)
        {
            Trace::GetLogger().STAMP(Trace::WARN) << e.what() << ". " << feature_name << " will not be functional." << Trace::EndLog();
        }
        return INVALID_TYPE;
    }

    int GetTypeOfObject(Comms::Object &obj)
    {
        if (obj.IsValid())
        {
            auto feature_type_id_property = obj.Numbers().Info().GetID(Core::ValueName::Feature::TYPE);
            return static_cast<int>(obj.Numbers().Store().Get(feature_type_id_property).value);
        }
        return INVALID_TYPE;
    }
}
