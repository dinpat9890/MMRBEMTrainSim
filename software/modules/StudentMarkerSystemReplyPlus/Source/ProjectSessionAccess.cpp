///
/// @file       ProjectSessionAccess.cpp
///
///             Provides a class and accessor functions that allow
///             clients to easily query the Oracle database for data.
///
/// @author     Pradeep Prajapati
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2016
///

#include "ProjectSessionAccess.h"
#include <Common/StandardLogging.h>
#include "OracleProxy.h"

namespace ProjectDataAccess
{
    ProjectSessionAccess::ProjectSessionAccess(Common::Data::DataAccess &data_access)
        : m_impl(data_access.Get<IOracleProxy>())
    {}

    void ProjectSessionAccess::InsertTimeStamp(const int SESSION_ID, const double time_stamp, const std::string device_id)
    {
        m_impl.InsertTimeStamp(SESSION_ID, time_stamp, device_id);
    }
}
