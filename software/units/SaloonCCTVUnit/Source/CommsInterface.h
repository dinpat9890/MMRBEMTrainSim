///
/// @file       CCTVCommsInterface.h
///
///             Interface to Sydac Comms unit.
///             It is fetch propeties from Sydac::Comms using watcher & also update output to it.
///
/// @ingroup    Mumbai L2-L7 CCTV
///
/// @author     Yatendra Gupta
///
/// @copyright  (C) Copyright:  OKTAL SYDAC Pvt Ltd, 2022
///

#pragma once

#include "sim_comms/Gateway.h"
#include "Utility/CallbackCollection.h"
#include "map"
#include "ICommsInterface.h"

class CommsInterface : Common::Unique 
{
public:
    CommsInterface(ICommsInterface &iCommsInterface);
    ~CommsInterface();

    //void RawChanged(Sim::Raw raw);
    //void NumberChanged(Sim::Number number);

    void AddRawCommsCallback(const std::string &raw_name, const Raw_Callback_t &cb);
    void AddNumberCommsCallback(const std::string &number_name, const Number_Callback_t &cb);

    std::string GetInputRaw(const std::string &raw_name);
    double GetInputNumber(const std::string &number_name);

    void SetOutputRaw(const std::string &raw_name, const std::string &raw_value);
    void SetOutputNumber(const std::string &number_name, double number_value);

    void ResetCommsValues();

    void SetObjectPropertyNumber(Comms::Object& object, const char* property, double value);
    Comms::Object GetInputCommsObject();

    void AddDestroyVDUCallback(std::function<void()> cb);
    void ClearCommsValues();
    void SetStationFeatureType(int station_feature_type);
    const std::vector<Comms::Object> & GetStationFeatureList();

    template <class T>
    T GetObjectPropertyNumber(const Comms::Object& object, const char* property)
    {
        return m_CommsInterface.GetObjectPropertyNumber<T>(object, property);
    }

    const std::map<int, Comms::Object> & GetPAPISCommsMap() { return m_CommsInterface.m_papis_vehicles_comms; }
    const std::map<int, Comms::Object> & GetVehiclesCommsMap() { return m_CommsInterface.m_vehicles_comms; }
    const Comms::Object & GetTrainsCommsMap() { return m_CommsInterface.m_trains_comms; }
    const Comms::Object & GetOHPoutpusComms() { return m_CommsInterface.m_ohp_outputs_comms; }

private:
    ICommsInterface & m_CommsInterface;
};
