//**************************************************************************************************
//
//  File:           GenericClient.h
//
//  Description:    Declares the GenericClient class - the base class for both UDP datagram socket
//                  and Gen III.
//
//  Reference:      AC07-015 - PPP
//
//  Author:         Robert Wolf
//
//  (C) Copyright:  SYDAC Pty Ltd, 2015
//
//**************************************************************************************************

#ifndef GENERIC_CLIENT_H
#define GENERIC_CLIENT_H

#include "MotionBaseParameters.h"
#include <winsock2.h>
#include <queue>
#include <vector>
#include <string>
#include "DataConnection.h"
//  Class:          GenericClient
//
//  Description:    Base class for both UDP socket connection and Gen III

class GenericClient
{

public:
    typedef std::vector<unsigned char> MessageType;
    virtual bool IsOpen() const = 0;
    virtual void OpenPort(const std::string &dest_address, unsigned short dest_port, unsigned short local_port) = 0;
    virtual void ClosePort() = 0;
    virtual MessageType RX() = 0;
    virtual std::string GetTX(const MotionBase::Parameters &parameters) = 0;
    virtual std::string GetProfileCommand (std :: string & command) = 0;
};

#endif // GENERIC_CLIENT_H