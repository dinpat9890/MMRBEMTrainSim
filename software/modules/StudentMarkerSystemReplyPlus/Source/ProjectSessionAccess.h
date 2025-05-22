///
/// @file       ProjectSessionAccess.h
///
///             Provides a class and accessor functions that allow
///             clients to easily query the Oracle database for data.
///
/// @author     Pradeep Prajapati
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2016
///

#ifndef PROJECT_SESSION_ACCESS_H
#define PROJECT_SESSION_ACCESS_H

#include <Common/Utilities.h>
#include "common/DataAccess.h"
#include <string>

namespace ProjectDataAccess
{
    class ProjectSessionAccess
    {
    public:
        ProjectSessionAccess(Common::Data::DataAccess &data_access);

        void InsertTimeStamp(const int SESSION_ID, const double time_stamp, const std::string device_id);

    private:
        class IOracleProxy &m_impl;
    };
}


#endif //PROJECT_SESSION_ACCESS_H