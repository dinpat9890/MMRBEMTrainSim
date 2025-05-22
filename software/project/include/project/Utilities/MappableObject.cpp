//******************************************************************************
//
//  File:           MappableObject.cpp
//
//  Description:    Defines the MappableObject class, which allows properties of
//                  an object to be mapped easily to local variables.
//
//  Reference:      Shanghai Metro Simulator
//
//  Author:         Andy Cooper
//
//  (C) Copyright:  SYDAC Pty Ltd, 2014
//
//******************************************************************************
#include "MappableObject.h"

#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>

using namespace std;

namespace
{
    template<typename T>
    bool Change(T &assigned_value, const T &value)
    {
        bool ret;
        if(ret = (value != assigned_value))
            assigned_value = value;

        return ret;
    }

    template <typename T>
    void ReadOptionalList(const std::vector<unsigned char> &data, std::vector<T> &list)
    {
        if(data.empty())
            list.clear();
        else
        {
            // No correctness checks on incoming data
            Comms::ReadEndian(&data[0], list, !Comms::IsMachineBigEndian());
        }
    }

    template <typename T>
    void WriteOptionalList(std::vector<unsigned char> &data, const std::vector<T> &list)
    {
        if(list.empty())
            data.clear();
        else
        {
            // No correctness checks on incoming data
            data.resize(Comms::GetCommsSize(list));
            Comms::WriteEndian(&data[0], list, !Comms::IsMachineBigEndian());
        }
    }

     //  Function:       RequestAndRetrieveNumbers
    //
    //  Description:    Performs a request and retrieve on a limited 
    //                  selection of properties.
    //
    //  Parameters:
    //      Comms::Object object - Object the numbers belong to
    //      std::vector<Simulator::Number::ID> &ids - IDs of the properties to request
    //      double frequency - Request frequency

    void RequestAndRetrieveNumbers(Comms::Object object, const std::vector<Sim::Number::ID> &ids, double frequency)
    {
        if(!ids.empty())
        {
            vector<Sim::NumberInfo> request_events;
            vector<Sim::Number>     retrieve_events;
            for (auto number_id : ids)
                request_events.push_back(object.Numbers().Info().GetInfo(number_id));
            copy(ids.begin(), ids.end(), back_inserter(retrieve_events));

            object.Numbers().Store().Request(request_events.begin(), request_events.end(), frequency);
            object.Numbers().Store().Retrieve(retrieve_events.begin(), retrieve_events.end());
        }
    }

    //  Function:       RequestAndRetrieveRaws
    //
    //  Description:    Performs a request and retrieve on a limited 
    //                  selection of properties.
    //
    //  Parameters:
    //      Comms::Object object - Object the Raws belong to
    //      std::vector<Sim::Raw::ID> &ids - IDs of the properties to request
    //      double frequency - Request frequency

    void RequestAndRetrieveRaws(Comms::Object object, const std::vector<Sim::Raw::ID> &ids, double frequency)
    {
        if(!ids.empty())
        {
            vector<Sim::RawInfo> request_events;
            vector<Sim::Raw>     retrieve_events;
            for (auto raw_id : ids)
                request_events.push_back(object.Raws().Info().GetInfo(raw_id));
            copy(ids.begin(), ids.end(), back_inserter(retrieve_events));

            object.Raws().Store().Request(request_events.begin(), request_events.end(), frequency);
            object.Raws().Store().Retrieve(retrieve_events.begin(), retrieve_events.end());
        }
    }

    //  Function:       RequestAndRetrieveTrays
    //
    //  Description:    Performs a request and retrieve on a limited 
    //                  selection of properties.
    //
    //  Parameters:
    //      Comms::Object object - Object the Trays belong to
    //      std::vector<Sim::Tray::ID> &ids - IDs of the properties to request
    //      double frequency - Request frequency

    void RequestAndRetrieveTrays(Comms::Object object, const std::vector<Sim::Tray::ID> &ids, double frequency)
    {
        if(!ids.empty())
        {
            vector<Sim::TrayInfo> request_events;
            vector<Sim::Tray>     retrieve_events;
            for (auto tray_id : ids)
                request_events.push_back(object.Trays().Info().GetInfo(tray_id));
            copy(ids.begin(), ids.end(), back_inserter(retrieve_events));

            object.Trays().Store().Request(request_events.begin(), request_events.end(), frequency);
            object.Trays().Store().Retrieve(retrieve_events.begin(), retrieve_events.end());
        }
    }
}

void MappableObject::MapObject(Comms::Object object, double request_frequency)
{
    m_number_ids.clear();
    m_numbers.clear();
    m_mapped_numbers.clear();
    m_mapped_numbers_int.clear();
    m_mapped_numbers_bool.clear();

    m_raws.clear();
    m_raw_ids.clear();
    m_mapped_raws_string.clear();
    m_mapped_raws_vector_string.clear();

    m_tray_ids.clear();

    m_object.Invalidate();

    m_request_frequency = request_frequency;
    m_object = object;
}

//  Function:       MappableObject::UnSetObject
//
//  Description:    Unsets the object that will be mapped. All mapping is cleared

void MappableObject::UnMapObject()
{
    m_object.Invalidate();

    m_number_ids.clear();
    m_numbers.clear();
    m_mapped_numbers.clear();
    m_mapped_numbers_int.clear();
    m_mapped_numbers_bool.clear();

    m_raws.clear();
    m_raw_ids.clear();
    m_mapped_raws_string.clear();
    m_mapped_raws_vector_string.clear();

    m_tray_ids.clear();
}

// Map the Number to a double and setup the request
int MappableObject::MapNumber(double *pvalue, const std::string &name)
{
    // Assert that the m_object_number has been correctly setup
    assert(m_object.IsValid());

    Sim::Number number = m_object.Numbers().Get(name);

    if(number.id != Sim::INVALID_NUMBER)
    {
        Sim::NumberInfo info = m_object.Numbers().Info().GetInfo(number.id);

        // Should use make_unique but <memory> does not seem to have it defined!
        m_numbers.push_back(unique_ptr<Sim::Number>(new Sim::Number(number)));
        m_number_ids.push_back(number.id);

        m_mapped_numbers.push_back(std::make_pair(m_numbers.back(), pvalue));
    }

    return number.id;
}

// Map the Number to an int and setup the request
int MappableObject::MapNumber(int *pvalue, const std::string &name)
{
    // Assert that the m_object_number has been correctly setup
    assert(m_object.IsValid());

    Sim::Number number = m_object.Numbers().Get(name);

    if(number.id != Sim::INVALID_NUMBER)
    {
        Sim::NumberInfo info = m_object.Numbers().Info().GetInfo(number.id);
        
        // Should use make_unique but <memory> does not seem to have it defined!
        m_numbers.push_back(unique_ptr<Sim::Number>(new Sim::Number(number)));
        m_number_ids.push_back(number.id);

        m_mapped_numbers_int.push_back(std::make_pair(m_numbers.back(), pvalue));
    }

    return number.id;
}

// Map the Number to a bool and setup the request
int MappableObject::MapNumber(bool *pvalue, const std::string &name)
{
    // Assert that the m_object_number has been correctly setup
    assert(m_object.IsValid());

    Sim::Number number = m_object.Numbers().Get(name);

    if(number.id != Sim::INVALID_NUMBER)
    {
        Sim::NumberInfo info = m_object.Numbers().Info().GetInfo(number.id);
        
        // Should use make_unique but <memory> does not seem to have it defined!
        m_numbers.push_back(unique_ptr<Sim::Number>(new Sim::Number(number)));
        m_number_ids.push_back(number.id);

        m_mapped_numbers_bool.push_back(std::make_pair(m_numbers.back(), pvalue));
    }

    return number.id;
}

// Map the Raw to a string and setup the request
int MappableObject::MapRaw(std::string *pvalue, const std::string &name)
{
    // Assert that the m_object_number has been correctly setup
    assert(m_object.IsValid());

    Sim::Raw raw = m_object.Raws().Get(name);

    if(raw.id != Sim::INVALID_NUMBER)
    {
        Sim::RawInfo info = m_object.Raws().Info().GetInfo(raw.id);
        
        // Should use make_unique but <memory> does not seem to have it defined!
        m_raws.push_back(unique_ptr<Sim::Raw>(new Sim::Raw(raw)));
        m_raw_ids.push_back(raw.id);

        m_mapped_raws_string.push_back(std::make_pair(m_raws.back(), pvalue));
    }

    return raw.id;
}

// Map the Raw to a vector of string and setup the request
int MappableObject::MapRaw(std::vector<std::string> *pvalue, const std::string &name)
{
    // Assert that the m_object_number has been correctly setup
    assert(m_object.IsValid());

    Sim::Raw raw = m_object.Raws().Get(name);

    if(raw.id != Sim::INVALID_NUMBER)
    {
        Sim::RawInfo info = m_object.Raws().Info().GetInfo(raw.id);
        
        // Should use make_unique but <memory> does not seem to have it defined!
        m_raws.push_back(unique_ptr<Sim::Raw>(new Sim::Raw(raw)));
        m_raw_ids.push_back(raw.id);

        m_mapped_raws_vector_string.push_back(std::make_pair(m_raws.back(), pvalue));
    }

    return raw.id;
}

// Trays are just registered for Updates - there is no actual variable that they map to
Sim::Tray MappableObject::MapTray(const std::string &name)
{
    // Assert that the m_object_number has been correctly setup
    assert(m_object.IsValid());

    Sim::Tray tray = m_object.Trays().Get(name);

    if(tray.id != Sim::INVALID_NUMBER)
    {
        Sim::TrayInfo info = m_object.Trays().Info().GetInfo(tray.id);
        m_tray_ids.push_back(tray.id);
    }

    return tray;

}

//  Function:       PositionObject::RequestAndRetrieve
//
//  Description:    Make a list of the id's of the numbers we are interrested in and setup the retrieve rate with 
//                  the Store
//
//  Parameters:
//      double request_frequency - The frequency in HZ to update the numbers at
//
void MappableObject::RequestAndRetrieve()
{ 
    if (!m_number_ids.empty())
        ::RequestAndRetrieveNumbers(m_object, m_number_ids, m_request_frequency);

    if (!m_raw_ids.empty())
        ::RequestAndRetrieveRaws(m_object, m_raw_ids, m_request_frequency);

    if (!m_tray_ids.empty())
        ::RequestAndRetrieveTrays(m_object, m_tray_ids, m_request_frequency);

    Get();
}

//  Function:       MappableObject::Get
//
//  Description:    Gets the values currently in comms and sets the mapped
//                  variables.
//
//  Notes:          If the object is invalid, does nothing

void MappableObject::Get()
{
    if(!m_object.IsValid())
        return;

    for(std::vector<std::pair<shared_ptr<Sim::Number>, double *> >::const_iterator i = m_mapped_numbers.begin(); i != m_mapped_numbers.end(); ++i)
    {
        m_object.Numbers().Store().Get(*i->first);
        *i->second = i->first->value;
    }

    for(std::vector<std::pair<shared_ptr<Sim::Number>, int *> >::const_iterator i = m_mapped_numbers_int.begin(); i != m_mapped_numbers_int.end(); ++i)
    {
        m_object.Numbers().Store().Get(*i->first);
        *i->second = static_cast<int>(i->first->value);
    }

    for(std::vector<std::pair<shared_ptr<Sim::Number>, bool *> >::const_iterator i = m_mapped_numbers_bool.begin(); i != m_mapped_numbers_bool.end(); ++i)
    {
        m_object.Numbers().Store().Get(*i->first);
        *i->second = (i->first->value != 0.0);
    }

    for(std::vector<std::pair<shared_ptr<Sim::Raw>, std::string *> >::const_iterator i = m_mapped_raws_string.begin(); i != m_mapped_raws_string.end(); ++i)
    {
        m_object.Raws().Store().Get(*i->first);
        i->second->assign(i->first->value.begin(), i->first->value.end());
    }

    for(std::vector<std::pair<shared_ptr<Sim::Raw>, std::vector<std::string> *> >::const_iterator i = m_mapped_raws_vector_string.begin(); i != m_mapped_raws_vector_string.end(); ++i)
    {
        m_object.Raws().Store().Get(*i->first);
        ReadOptionalList(i->first->value, *i->second);
    }
}

//  Function:       MappableObject::Set
//
//  Description:    Compares mapped variables with the local comms variable and
//                  if changed, updates it and sets the value in comms.
//                  All properties of the same type are set at once.
//
//  Notes:          If the object is invalid, does nothing.

void MappableObject::Set()
{
    if(!m_object.IsValid())
        return;

    std::vector<Sim::Raw> set_raws;
    std::vector<Sim::Number> set_numbers;

    for(std::vector<std::pair<shared_ptr<Sim::Number>, double *> >::const_iterator i = m_mapped_numbers.begin(); i != m_mapped_numbers.end(); ++i)
    {
        if(Change(i->first->value, *i->second))
            set_numbers.push_back(*i->first);
    }
    for(std::vector<std::pair<shared_ptr<Sim::Number>, int *> >::const_iterator i = m_mapped_numbers_int.begin(); i != m_mapped_numbers_int.end(); ++i)
    {
        if(Change(i->first->value, static_cast<double>(*i->second)))
            set_numbers.push_back(*i->first);
    }
    for(std::vector<std::pair<shared_ptr<Sim::Number>, bool *> >::const_iterator i = m_mapped_numbers_bool.begin(); i != m_mapped_numbers_bool.end(); ++i)
    {
        if(Change(i->first->value, *i->second ? 1.0 : 0.0))
            set_numbers.push_back(*i->first);
    }

    for(std::vector<std::pair<shared_ptr<Sim::Raw>, std::string *> >::const_iterator i = m_mapped_raws_string.begin(); i != m_mapped_raws_string.end(); ++i)
    {
        if(Change(i->first->value, Sim::Raw::Type(i->second->begin(), i->second->end())))
            set_raws.push_back(*i->first);
    }

    for(std::vector<std::pair<shared_ptr<Sim::Raw>, std::vector<std::string> *> >::const_iterator i = m_mapped_raws_vector_string.begin(); i != m_mapped_raws_vector_string.end(); ++i)
    {
        Sim::Raw::Type data;
        WriteOptionalList(data, *i->second);

        if(Change(i->first->value, data))
            set_raws.push_back(*i->first);
    }

    if(!set_numbers.empty())
        m_object.Numbers().Store().Set(set_numbers.begin(), set_numbers.end());

    if(!set_raws.empty())
        m_object.Raws().Store().Set(set_raws.begin(), set_raws.end());

}
