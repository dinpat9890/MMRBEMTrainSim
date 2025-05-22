/// @brief
/// @author    Dheeraj Jha
/// @copyright SYDAC Pty Ltd, 2015
#pragma once
#ifndef PROJECT_ORACLE_PROXY_H
#define PROJECT_ORACLE_PROXY_H

#include <memory>
#include "oracle_access/OracleProvider.h"
#include "common/DataAccess.h"
#include "OracleProxy.h"

namespace ProjectDataAccess
{
    class OracleProxyImpl : public IOracleProxy
    {
    public:
        OracleProxyImpl(Common::Data::OracleProvider& data_connection);
        ~OracleProxyImpl();
        void InsertTimeStamp(const int SESSION_ID, const double time_stamp, const std::string device_id) override;

    protected:
        Common::Data::OracleProvider& m_oracle_provider;
    };
}

#endif
