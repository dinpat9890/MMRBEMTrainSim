///
/// @file       CommsInterface.cpp
///
///             Defines the comms object property's setter and getter, also
///             defines the callbacks mechanism for required comms object property
///
/// @ingroup    Mumbai L2-L7 CCTV
///
/// @author     Abhishek Rastogi
///
/// @copyright  (C) Copyright:  OKTAL SYDAC Pvt Ltd, 2022
///

#include "CommsInterface.h"

CommsInterface::CommsInterface(ICommsInterface &iCommsInterface)
    :m_CommsInterface(iCommsInterface)
{
}

CommsInterface::~CommsInterface(void)
{
}

void CommsInterface::SetOutputNumber(const std::string &number_name, double number_value)
{
    m_CommsInterface.SetOutputNumber(number_name, number_value);
}

void CommsInterface::SetOutputRaw(const std::string &raw_name, const std::string &raw_value)
{
    m_CommsInterface.SetOutputRaw(raw_name, raw_value);
}

double CommsInterface::GetInputNumber(const std::string &number_name)
{
    return m_CommsInterface.GetInputNumber(number_name);
}

std::string CommsInterface::GetInputRaw(const std::string &raw_name)
{
    return m_CommsInterface.GetInputRaw(raw_name);
}

void CommsInterface::AddRawCommsCallback(const std::string &raw_name, const Raw_Callback_t &cb)
{
    m_CommsInterface.AddRawCommsCallback(raw_name, cb);
}

void CommsInterface::AddNumberCommsCallback(const std::string &number_name, const Number_Callback_t &cb)
{
    m_CommsInterface.AddNumberCommsCallback(number_name, cb);
}

void CommsInterface::ResetCommsValues()
{
    m_CommsInterface.ResetCommsValues();
}

void CommsInterface::SetObjectPropertyNumber(Comms::Object& object, const char* property, double value)
{
    m_CommsInterface.SetObjectPropertyNumber(object, property, value);
}
Comms::Object CommsInterface::GetInputCommsObject()
{
    return m_CommsInterface.GetInputCommsObject();
}

void CommsInterface::AddDestroyVDUCallback(std::function<void()> cb)
{
    m_CommsInterface.AddDestroyVDUCallback(cb);
}

void CommsInterface::ClearCommsValues()
{
    m_CommsInterface.ClearCommsValues();
}

void CommsInterface::SetStationFeatureType(int station_feature_type)
{
    m_CommsInterface.SetStationFeatureType(station_feature_type);
}

const std::vector<Comms::Object> & CommsInterface::GetStationFeatureList()
{
    return m_CommsInterface.GetStationFeatureList();
}