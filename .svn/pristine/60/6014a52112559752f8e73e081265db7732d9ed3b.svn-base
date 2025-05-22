///******************************************************************************
///
/// @File: ProjectOracleProxy.cpp
///
/// @Description: writes in DB.
/// @Reference:
///
/// @Author: Dheeraj Jha
///
/// @ Copyright: SYDAC Pty Ltd, 2015
///
///******************************************************************************
#include "ProjectOracleProxy.h"
#include "oracle_access/OracleQuery.h"
#include "SMSApplication.h"
#include "ProjectOracleProxy.h"
#include "Common/DataAccess.h"
#include <iostream>

using namespace std;



/// @Function: OracleProxyImpl
///
/// @Description: Constructor
/// @param connection_string
/// @param username: database user name
/// @param password: database user password
ProjectDataAccess::OracleProxyImpl::OracleProxyImpl(Common::Data::OracleProvider& provider)
    : m_oracle_provider(provider)
{

}


/// @Function: InsertTimeStamp
///
/// @Description:Inserts time stamp and session id to SESSIONTIMESTAMP table
///
/// @param session_id - current session id
/// @param time_stamp - time stamp to save

void ProjectDataAccess::OracleProxyImpl::InsertTimeStamp(const int session_id,const double time_stamp, const std::string device_id)
{
    Common::Data::OracleQuery q(m_oracle_provider.GetConnection(), Common::Data::OracleQuery::EXEC_AUTOCOMMIT);

    stringstream sql;
    sql << "INSERT INTO SESSIONTIMESTAMP(SSE_SIMSESSION_ID, STS_TIMESTAMP, STS_LABEL) VALUES(";
    sql << session_id << ",";
    sql << time_stamp << ",";
    sql << device_id << ")";
    q.Prepare(sql.str());
    q.Execute();
}

ProjectDataAccess::OracleProxyImpl::~OracleProxyImpl()
{
}


