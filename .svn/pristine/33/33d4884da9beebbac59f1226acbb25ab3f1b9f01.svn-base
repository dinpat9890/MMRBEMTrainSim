#ifndef SCORING_DATA_ACCESS_H
#define SCORING_DATA_ACCESS_H

// Include core aspects so that we can pull in the name space below
#include "core_data_access/CoreDataAccess.h"

namespace Sydac
{
    namespace Data
    {
        class DataAccess;
    }
}

namespace Scoring
{
    namespace Database
    {
        // Make all core aspects available just using the Scoring::Database namespace
        using namespace Core::Database;

        void RegisterScoringAspects(Common::Data::DataAccess &data_access);
        void DeregisterScoringAspects(Common::Data::DataAccess &data_access);

        /// An RAII wrapper for the registering the scoring aspects.
        class ScoringDataAccess final
        {
        public:
            explicit ScoringDataAccess(Common::Data::DataAccess &data_access);
            ~ScoringDataAccess();

        private:
            ScoringDataAccess(const ScoringDataAccess &);
            ScoringDataAccess& operator=(const ScoringDataAccess &);

            Common::Data::DataAccess &m_data_access;
        };
    }
}

#endif
