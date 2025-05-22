/// @file      CommsPropertyAccessors.h
///            Useful common to cpp units functions/definitions.
///
/// @copyright (C) Copyright:  OKTAL SYDAC Pvt Ltd, 2022

#include "sim_comms/Object.h"

#ifndef COMMS_PROPERTY_ACCESSORS_UTILITY_H
#define COMMS_PROPERTY_ACCESSORS_UTILITY_H

namespace CTSProjectUtility
{
    const double REQUEST_FREQ = 20.0; // In Hz

    void RequestProperty(Comms::Object& object, const char* property);

    template <class T>
    T GetObjectPropertyNumber(const Comms::Object& object, const char* property)
    {
        double ret = 0.0;

        if (object.IsValid() && property != nullptr)
        {
            try {
                auto number = object.Numbers().Get(property);
                ret = number.value;
            }
            catch (CommonException &e)
            {
                Trace::GetLogger().STAMP(Trace::ERR) << e.what() << Trace::EndLog();
            }
        }
        else
        {
                Trace::GetLogger().STAMP(Trace::ERR) << "Invalid comms object or null property." << Trace::EndLog();
        }

        return static_cast<T>(ret);
    }

    void SetObjectPropertyNumber(Comms::Object& object, const char* property, double value);

    template <class T>
    void SetObjectPropertyRaw(Comms::Object& object, const char* property, const T& new_value)
    {
        if (!object.IsValid() || property == nullptr)
        {
            Trace::GetLogger().STAMP(Trace::ERR) << "invalid comms object or null property." << Trace::EndLog();

            return;
        }

        try {
            Sim::Raw raw = object.Raws().Get(property);
            raw.value.clear();
            raw.value.insert(raw.value.begin(), new_value.begin(), new_value.end());
            object.Raws().Store().Set(raw);
        }
        catch (CommonException &e)
        {
            Trace::GetLogger().STAMP(Trace::ERR) << e.what() << Trace::EndLog();
        }
    }

    template <class T>
    void CopyCommsPropertyValue(const Comms::Object& from_object, const char* from_property, Comms::Object& to_object, const char* to_property)
    {
        SetObjectPropertyNumber(to_object, to_property, GetObjectPropertyNumber<T>(from_object, from_property));
    }

}

#endif