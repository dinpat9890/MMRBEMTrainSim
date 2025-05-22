#pragma once
#include "Dataconnection.h"
#include "Winsock2.h"
#include <Windows.h>

class SerialDeviceConnection : public DataConnection
{
protected:
    std::string m_destination_address;
    HANDLE      m_com_port_handle;
    HANDLE      com_port_handle;
    bool        m_is_open;

    std::string GetLastErrorMessage();

public:
    SerialDeviceConnection(const std::string &destination_address);
    SerialDeviceConnection(void);
    ~SerialDeviceConnection(void);

    bool IsOpen() override;
    bool Open() override;
    bool Close() override;

    bool Send(const std::string& string_to_send) override;

    std::string Receive() override;
};

