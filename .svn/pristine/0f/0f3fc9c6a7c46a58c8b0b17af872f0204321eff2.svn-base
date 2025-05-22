#pragma once
#include <string>

class DataConnection
{
public:
    virtual ~DataConnection(void) {}

    virtual bool IsOpen()=0;
    virtual bool Open()=0;
    virtual bool Close() =0;
    virtual bool Send(const std::string& string_to_send) =0;
    virtual std::string Receive()=0;
};

