#pragma once
///
/// @file       ICommsInterface.h
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

#include "core_types/SessionData.h"
#include "Utility/CallbackCollection.h"
#include "map"
#include <string>
#include <mutex>
#include "sim_comms/Gateway.h"
#include "Common/StandardLogging.h"

#ifndef ICOMMSINTERFACE_H
#define ICOMMSINTERFACE_H

typedef std::map<std::string, std::pair<Sim::Raw::ID, Sim::Raw>>        Raw_Container_t;
typedef std::map<std::string, std::pair<Sim::Number::ID, Sim::Number>>  Number_Container_t;

typedef Callback<void, Sim::Number>   Number_Callback_t;
typedef Callback<void, Sim::Raw>      Raw_Callback_t;

typedef std::map<std::string, std::vector<Number_Callback_t *>>   Number_Callback_Container_t;
typedef std::map<std::string, std::vector<Raw_Callback_t *>>      Raw_Callback_Container_t;

class ICommsInterface 
{
public:
    virtual void Start() = 0;

    virtual void AddRawCommsCallback(const std::string &raw_name, const Raw_Callback_t &cb) ;
    virtual void AddNumberCommsCallback(const std::string &number_name, const Number_Callback_t &cb) ;

    virtual std::string GetInputRaw(const std::string &raw_name) ;
    virtual double GetInputNumber(const std::string &number_name) ;

    virtual void SetOutputRaw(const std::string &raw_name, const std::string &raw_value)=0;
    virtual void SetOutputNumber(const std::string &number_name, double number_value)=0;

    virtual void ResetCommsValues();

    virtual void NumberChanged(Sim::Number number);
    virtual void NumberEventsChanged(Sim::Number number);
    virtual void RawChanged(Sim::Raw raw);
    virtual void SetObjectPropertyNumber(Comms::Object& object, const char* property, double value)=0;
    virtual Comms::Object GetInputCommsObject()= 0;

    template <class T>
    T GetObjectPropertyNumber(const Comms::Object& object, const char* property)
    {
        assert(property != nullptr);
        double ret = 0.0;

        if (object.IsValid())
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
            Trace::GetLogger().STAMP(Trace::ERR) << "Invalid comms object " << object.GetID() << " " << object.GetName() << Trace::EndLog();
        }

        return static_cast<T>(ret);
    }
    void AddDestroyVDUCallback(std::function<void()> cb) { destroy_clear_vdu = cb; }
    void DestroyVDUObjectsCallback(const Comms::Object& object);
    void ClearCommsValues();
    void SetStationFeatureType(int station_feature_type) { m_stopping_point = station_feature_type;}
    const std::vector<Comms::Object> & GetStationFeatureList() {return m_station_features_list;}

    using VehicleIdxToCommsObject = std::map<int, Comms::Object>;
    // comms objects for each Project::ClassID::PAPIS_VEHICLE_OUTPUTS. Model provides alarm state through that.
    VehicleIdxToCommsObject m_papis_vehicles_comms;
    VehicleIdxToCommsObject m_vehicles_comms;
    Comms::Object m_trains_comms;
    Comms::Object m_ohp_outputs_comms;
protected:
    Raw_Container_t    m_input_raws;
    Number_Container_t m_input_numbers;
    std::vector<std::pair<std::string, std::pair<Sim::Number::ID, Sim::Number>>> m_input_events_numbers;

    Raw_Container_t    m_output_raws;
    Number_Container_t m_output_numbers;

    Raw_Callback_Container_t    m_raw_callbacks;
    Number_Callback_Container_t m_number_callbacks;

    int m_stopping_point = -1;
    std::vector<Comms::Object> m_station_features_list;

    std::recursive_mutex m_mutex;

    std::function<void()> destroy_clear_vdu;

};
#endif