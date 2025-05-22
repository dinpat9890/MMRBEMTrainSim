#pragma once

// Include core aspects so that we can pull in the name space below
#include "core_data_access/CoreDataAccess.h"

namespace Common
{
    namespace Data
    {
        class DataAccess;
    }
}

namespace Session
{
    namespace Database
    {
        // Make all core aspects available just using the Session::Database namespace
        using namespace Core::Database;

        void RegisterSessionAspects(Common::Data::DataAccess &data_access);
        void DeregisterSessionAspects(Common::Data::DataAccess &data_access);

        /// An RAII wrapper for the registering the session aspects.
        class SessionDataAccess final
        {
        public:
            explicit SessionDataAccess(Common::Data::DataAccess &data_access);
            ~SessionDataAccess();

        private:
            SessionDataAccess(const SessionDataAccess &);
            SessionDataAccess& operator=(const SessionDataAccess &);

            Common::Data::DataAccess &m_data_access;
        };
    }
}
