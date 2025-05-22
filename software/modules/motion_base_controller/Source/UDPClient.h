//**************************************************************************************************
//
//  File:           UDPClient.h
//
//  Description:    Declares the UDPClient class - encapsulating a UDP datagram socket to be used as
//                  a client.
//
//  Reference:      AC07-015 - PPP
//
//  Author:         Dijon Page
//
//  (C) Copyright:  SYDAC Pty Ltd, 2008
//
//**************************************************************************************************

#ifndef UDP_CLIENT_H
#define UDP_CLIENT_H

#include "GenericClient.h"
#include <winsock.h>
#include <queue>
#include <vector>
#include <string>

//  Class:          UDPClient
//
//  Description:    Encapsulates a UDP socket intended as a client in a UDP connection.

class UDPClient : public GenericClient
{
public:
    UDPClient(const std::string &dest_address, unsigned short dest_port, unsigned short local_port);
    UDPClient();
    ~UDPClient();

    virtual bool IsOpen() const;
    bool IsResponding() const;
    void OpenPort(const std::string &dest_address, unsigned short dest_port, unsigned short local_port);
    void ClosePort();

    size_t      ProcessIncomingMessages();
    MessageType RX();
    bool        TX(MotionBaseData &data);

private:
    void Init();

private:
    SOCKET                  m_socket;
    std::queue<MessageType> m_waiting;
    bool                    m_is_open;
    bool                    m_is_responding;
};

#endif // UDP_CLIENT_H