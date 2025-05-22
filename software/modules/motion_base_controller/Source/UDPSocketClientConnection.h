#pragma once
#include "dataconnection.h"
#include <winsock2.h>
#include "common/Profiler.h"

class UDPSocketClientConnection :    public DataConnection
{

protected:
    void ThrowSocketException(const std::string &info, int wsa_error);
    void ThrowSocketException(const std::string &info);

protected:
    SOCKET                          m_socket;
    std::string                     m_destination_address;
    unsigned short                  m_destination_port;
    unsigned short                  m_local_port;
    Common::Profiler                 m_profiler;
    bool                            m_is_open;
public:
    UDPSocketClientConnection(const std::string &destination_address, unsigned short destination_port, unsigned short local_port, double connection_timeout);
    UDPSocketClientConnection(void);
    ~UDPSocketClientConnection(void);
    bool IsOpen() override;
    bool Open() override;
    bool Close() override;
    bool Send(const std::string& string_to_send) override;
    std::string Receive() override;
};

