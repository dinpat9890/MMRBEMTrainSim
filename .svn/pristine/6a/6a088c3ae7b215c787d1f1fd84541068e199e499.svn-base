#pragma once
#include "common/DataAccess.h"

namespace ProjectDataAccess
{
    /// Interface for the freight data aspect.
    class IOracleProxy : public Common::Data::Aspect
    {
    public:
        virtual void InsertTimeStamp(const int SESSION_ID, const double time_stamp, const std::string device_id) = 0;
    };
}