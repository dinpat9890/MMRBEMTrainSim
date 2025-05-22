/// @file      CommsPropertyAccessors.cpp
///            Useful common to cpp units functions/definitions.
///
/// @copyright (C) Copyright:  OKTAL SYDAC Pvt Ltd, 2022

#include "CommsPropertyAccessors.h"

#include "sim_comms/Object.h"
#include "common/StandardLogging.h"

namespace CTSProjectUtility
{

    void RequestProperty(Comms::Object& object, const char* property)
    {
        if (object.IsValid() && property != nullptr)
        {
            object.Numbers().Store().Request(
                object.Numbers().Info().GetInfo(object.Numbers().Info().GetID(property)),
                REQUEST_FREQ);
        }
        else
        {
            Trace::GetLogger().STAMP(Trace::ERR) << "Invalid comms object or null property." << Trace::EndLog();
        }
    }

    void SetObjectPropertyNumber(Comms::Object& object, const char* property, double value)
    {
        if (!object.IsValid() || property == nullptr)
        {
            Trace::GetLogger().STAMP(Trace::ERR) << "Invalid comms object or null property ." << Trace::EndLog();

            return;
        }

        try {
            auto number = object.Numbers().Get(property);
            number.value = value;
            object.Numbers().Store().Set(number);
        }
        catch (CommonException &e)
        {
            Trace::GetLogger().STAMP(Trace::ERR) << e.what() << Trace::EndLog();
        }
    }

}
