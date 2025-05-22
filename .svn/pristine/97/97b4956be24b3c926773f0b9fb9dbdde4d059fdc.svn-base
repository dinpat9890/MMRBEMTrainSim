///
/// @file       ICommsInterface.cpp
///
///             Store Input & Output Comms Properties.
///             It is abstract class for Production Comms Interface & Test Comms interface
///
/// @ingroup    Mumbai L2-L7 CCTV
///
/// @author     Yatendra Gupta
///
/// @copyright  (C) Copyright:  OKTAL SYDAC Pvt Ltd, 2022
///

#pragma once
#include "ICommsInterface.h"
#include "Common/StandardLogging.h"
#include "project_comms_structure/ProjectObjectDefinition.h"
#include "project_comms_structure/ProjectObjectConstants.h"

#include <algorithm>
void ICommsInterface::NumberChanged(Sim::Number number)
{
    std::lock_guard<std::recursive_mutex> local_lock(m_mutex);
    // Ignore front end reset value -1
    if(number.value >= 0)
    {
        auto input_nums_itr = std::find_if(m_input_numbers.begin(), m_input_numbers.end(),
                                [&](Number_Container_t::value_type item)
                                {
                                    return (item.second.first == number.id) && (item.second.second.object_id == number.object_id);
                                });

        if(input_nums_itr != m_input_numbers.end())
        {
            input_nums_itr->second.second = number;

            // Trigger the callbacks if any.
            auto key = input_nums_itr->first;
            //check if the key has '[' character.
            //if it is, then remove the extra substring that starts with [ and end with ].
            auto pos = key.find_first_of('[');
            if(pos != std::string::npos)
            {
                auto str = key;
                std::stringstream temp;
                temp << "[" << number.object_id << "]";
                auto substr = str.substr(pos);
                if(substr == temp.str())
                {
                    key = str.substr(0, pos);
                }
            }

            auto callback_data_itr = m_number_callbacks.find(key.c_str());
            if(callback_data_itr != m_number_callbacks.end())
                std::for_each(callback_data_itr->second.begin(), callback_data_itr->second.end(), [&](Number_Callback_t *cb) { if(cb)(*cb)(input_nums_itr->second.second); });
        }
        else
        {
            Trace::GetLogger().STAMP(Trace::ERR) << " Callback not found " << number << Trace::EndLog();
        }
    }
}

void ICommsInterface::NumberEventsChanged(Sim::Number number)
{
    std::lock_guard<std::recursive_mutex> local_lock(m_mutex);
    // Ignore front end reset value -1
    if (number.value >= 0)
    {
        auto input_nums_itr = std::find_if(m_input_events_numbers.begin(), m_input_events_numbers.end(),
            [&](std::pair<std::string, std::pair<Sim::Number::ID, Sim::Number>> item)
            {
                return (item.second.first == number.id) && (item.second.second.object_id == number.object_id);
            });

        if (input_nums_itr != m_input_events_numbers.end())
        {
            input_nums_itr->second.second = number;

            // Trigger the callbacks if any.
            auto key = input_nums_itr->first;
            //check if the key has '[' character.
            //if it is, then remove the extra substring that starts with [ and end with ].
            auto pos = key.find_first_of('[');
            if (pos != std::string::npos)
            {
                auto str = key;
                std::stringstream temp;
                temp << "[" << number.object_id << "]";
                auto substr = str.substr(pos);
                if (substr == temp.str())
                {
                    key = str.substr(0, pos);
                }
            }

            auto callback_data_itr = m_number_callbacks.find(key.c_str());
            if (callback_data_itr != m_number_callbacks.end())
                std::for_each(callback_data_itr->second.begin(), callback_data_itr->second.end(), [&](Number_Callback_t *cb) { if (cb)(*cb)(input_nums_itr->second.second); });
        }
        else
        {
            //Trace::GetLogger().STAMP(Trace::ERR) << "NumberEventsChanged, Callback not found " << number << Trace::EndLog();
        }
    }
}

void ICommsInterface::RawChanged(Sim::Raw raw)
{
    std::lock_guard<std::recursive_mutex> local_lock(m_mutex);

    auto input_raws_itr = std::find_if(m_input_raws.begin(), m_input_raws.end(),
                            [&](Raw_Container_t::value_type item)
                            {
                                return (item.second.first == raw.id);
                            });

    if(input_raws_itr != m_input_raws.end())
    {
        input_raws_itr->second.second.value = raw.value;

        // Trigger the callbacks if any.
        auto callback_data_itr = m_raw_callbacks.find(input_raws_itr->first);
        if(callback_data_itr != m_raw_callbacks.end())
            std::for_each(callback_data_itr->second.begin(), callback_data_itr->second.end(), [&](Raw_Callback_t *cb) { if(cb)(*cb)(input_raws_itr->second.second); });
    }
}

double ICommsInterface::GetInputNumber(const std::string &number_name)
{
    std::lock_guard<std::recursive_mutex> local_lock(m_mutex);

    double number_data = -1.0;

    auto num_data_itr = m_input_numbers.find(number_name);
    if(num_data_itr != m_input_numbers.end())
    {
        number_data = num_data_itr->second.second.value;
    }
    else
    {
        Trace::GetLogger().STAMP(Trace::ERR) << "GetInputNumber: Number property : [" << number_name << "] not found in any registered comms object." << Trace::EndLog();
    }

    return number_data;
}

std::string ICommsInterface::GetInputRaw(const std::string &raw_name)
{
    std::lock_guard<std::recursive_mutex> local_lock(m_mutex);

    std::string raw_data = "";

    auto raw_data_itr = m_input_raws.find(raw_name);
    if(raw_data_itr != m_input_raws.end())
    {
        raw_data.assign(raw_data_itr->second.second.value.begin(), raw_data_itr->second.second.value.end());
    }
    else
    {
        Trace::GetLogger().STAMP(Trace::ERR) << "GetInputRaw: Raw property : [" << raw_name << "] not found in any registered comms object." << Trace::EndLog();
    }

    return raw_data;
}

void ICommsInterface::AddRawCommsCallback(const std::string &raw_name, const Raw_Callback_t &cb)
{
    std::lock_guard<std::recursive_mutex> local_lock(m_mutex);

    auto callback_data_itr = m_raw_callbacks.find(raw_name);
    if(callback_data_itr == m_raw_callbacks.end())
    {
        std::vector<Raw_Callback_t *> callbacks;
        callbacks.push_back(cb.Clone());
        m_raw_callbacks.insert(std::make_pair(raw_name, callbacks));
    }
    else
    {
        m_raw_callbacks[raw_name].push_back(cb.Clone());
    }
}

void ICommsInterface::AddNumberCommsCallback(const std::string &number_name, const Number_Callback_t &cb)
{
    std::lock_guard<std::recursive_mutex> local_lock(m_mutex);

    auto callback_data_itr = m_number_callbacks.find(number_name);
    if(callback_data_itr == m_number_callbacks.end())
    {
        std::vector<Number_Callback_t *> callbacks;
        callbacks.push_back(cb.Clone());
        m_number_callbacks.insert(std::make_pair(number_name, callbacks));
    }
    else
    {
        m_number_callbacks[number_name].push_back(cb.Clone());
    }
}

void ICommsInterface::ResetCommsValues()
{
    std::for_each(m_input_numbers.begin(), m_input_numbers.end(),
                                [&](Number_Container_t::value_type item)
                                {
                                    item.second.second.value = 1.0;
                                });

    std::for_each(m_input_raws.begin(), m_input_raws.end(),
                                [&](Raw_Container_t::value_type item)
                                {
                                    item.second.second.value.clear();
                                });
}

void ICommsInterface::ClearCommsValues()
{
    auto itr = m_input_numbers.begin();
    for (;itr != m_input_numbers.end(); itr++)
    {
        if (itr->first == Project::ValueName::PAPISVehicleOutputs::PAPIS_CCTV_POWER)
            continue;

        Trace::GetLogger().STAMP(Trace::VERBOSE) << "Removing Comms object " << itr->first << Trace::EndLog();
        m_input_numbers.erase(itr);
    }

}

void ICommsInterface::DestroyVDUObjectsCallback(const Comms::Object& object) 
{
    Trace::GetLogger().STAMP(Trace::INFO) << "VDU Object Destroying " << object.GetID() << " " << object.GetName() << Trace::EndLog();
    destroy_clear_vdu();
}