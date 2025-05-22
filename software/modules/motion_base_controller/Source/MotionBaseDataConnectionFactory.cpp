#include "MotionBaseDataConnectionFactory.h"
#include "UDPSocketClientConnection.h"
#include "SerialDeviceConnection.h"
#include "MotionBaseProperties.h"

MotionBaseDataConnectionFactory::MotionBaseDataConnectionFactory(const Project::MotionBaseProperties &properties)
  : DataConnectionFactory(),
    m_properties(properties)
{
}


MotionBaseDataConnectionFactory::~MotionBaseDataConnectionFactory(void)
{
}

std::unique_ptr<DataConnection> MotionBaseDataConnectionFactory::GetDataConnection()
{
    // check if property is a Serial connection then
    // init  SerialDeviceConnection
    // else if property is a Socket connection then
    // init SocketDeviceConnection

    std::unique_ptr<DataConnection> data_connection;
    std::string                     destAddress = m_properties.GetDestinationAddress();

    // check if is IPv4 IP address. Product never considers IPv6 :(
    if(IsIPAddress(destAddress))
    {
        data_connection.reset(new UDPSocketClientConnection(
            destAddress,
            m_properties.GetDestinationPort(),
            m_properties.GetLocalPort(),
            m_properties.GetConnectionTimeout()));
    }
    else 
    {
        data_connection.reset(new SerialDeviceConnection(destAddress));
    }

    return data_connection;
}