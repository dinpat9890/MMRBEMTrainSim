#pragma once
#include "DataConnection.h"
#include <string>
#include <memory>

class DataConnectionFactory
{
    public:
        DataConnectionFactory() {};
        virtual ~DataConnectionFactory(void) {};

        static bool IsIPAddress(const std::string &ip_address);

        virtual std::unique_ptr<DataConnection> GetDataConnection() = 0;
};

