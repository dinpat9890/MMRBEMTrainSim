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

#include "ICommsInterface.h"
#include "Utility/CallbackCollection.h"
#include "sim_comms/Gateway.h"

#ifndef SALOON_COMMS_INTERFACE_H
#define SALOON_COMMS_INTERFACE_H

class CCTVCommsInterface : public ICommsInterface 
{
public:
    CCTVCommsInterface(Comms::Gateway &gateway, Core::BaseScenarioData::HubData &hub_data, double frequency);
    ~CCTVCommsInterface();
    void Start();
    void ObjectCreated(Comms::Object object);
    void SetOutputNumber(const std::string &number_name, double number_value);
    void SetOutputRaw(const std::string &raw_name, const std::string &raw_value);
    void SetObjectPropertyNumber(Comms::Object& object, const char* property, double value);
    void RequestProperty(Comms::Object& object, const char* property);
    Comms::Object GetInputCommsObject() { return m_saloon_cctv_inputs_object; }

    private:
    Comms::Gateway &m_gateway;
    //Driver Hub Data
    Core::BaseScenarioData::HubData &m_hub_data;
    double m_frequency;


    Comms::Object m_saloon_cctv_outputs_object;
    Comms::Object m_saloon_cctv_inputs_object;
};


#endif
