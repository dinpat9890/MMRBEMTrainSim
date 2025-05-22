#ifndef SESSION_ACCESS_H
#define SESSION_ACCESS_H

#include "SessionDataAccessTypes.h"

#include "common/DataAccess.h"

#include <vector>

namespace Session
{
    namespace Database
    {
        class SessionAccess
        {
        public:
            explicit SessionAccess(Common::DataAccess &data_access);

            // Configuration, separate queries
            std::vector<Data::LogEvent> GetAllLogEvents() const;
            std::vector<Data::LogSummary> GetAllLogSummaries() const;

            void InsertPremiershipDetails(int session_id, int hub_id, const std::vector<Data::PremiershipDetail> &pds);
            std::vector<Data::PremiershipDetail> GetAllPremiershipDetails(int session_id, int hub_id) const;

            Data::SessionSnapshot GetSnapshot(int session_id, const std::string &tag) const;

            // Commands all occurring under the one transaction
            void InsertSimSession(const Data::SimSession &sim_session);
            void UpdateSimSession(const Data::SimSession &sim_session);

            void InsertSessionData(const Data::SessionData &data);
            void InsertSessionFeature(const Data::SessionFeature &feature);
            void InsertSessionInfraction(const Data::SessionInfraction &infraction);
            void InsertSessionSummary(const Data::SessionSummary &summary);

            void InsertSessionData(const std::vector<Data::SessionData> &data);
            void InsertSessionFeatures(const std::vector<Data::SessionFeature> &features);

            void Commit();
            void Rollback();

            // Cleaning up
            void DeleteSessionData(int session_id);

        private:
            class SessionDataImpl &m_impl;
        };
    }
}

#endif
