///
/// @file       SessionTransactionalDataWriter.h
///
///             Declares the SessionTransactionalDataWriter that allows
///             transactional data to be written in a background thread
///
/// @ingroup    Integrated Scenarios, AC05-004
///
/// @author     James Errington
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2005
///

#ifndef SESSION_TRANSACTIONAL_DATA_WRITER_H
#define SESSION_TRANSACTIONAL_DATA_WRITER_H

#include "session_data_access/SessionAccess.h"

#include <common/OSThreadClasses.h>
#include <utility/CallbackCollection.h>

namespace DataAccess
{
    /// Allows transactional data to be written in a background thread
    
    class SessionTransactionalDataWriter
    {
    public:
        typedef CallbackCollection<void, void>::CallbackID FinalizeCallbackID;

        explicit SessionTransactionalDataWriter(Session::Database::SessionAccess &access);
        ~SessionTransactionalDataWriter();

        // Registration for data that is on finalization
        FinalizeCallbackID AddFinalizationCallback(CallbackCollection<void, void>::CallbackType cb);
        void RemoveFinalizationCallback(FinalizeCallbackID id);

        // Activation
        void EnableWriting(bool enable = true);
        void Finalize();

        void InsertSessionData(const Session::Data::SessionData &data);
        void InsertSessionSummary(const Session::Data::SessionSummary &summary);
        void InsertSessionFeature(const Session::Data::SessionFeature &feature);
        void InsertSessionInfraction(const Session::Data::SessionInfraction &infraction);

    private:
        SessionTransactionalDataWriter(const SessionTransactionalDataWriter&);
        SessionTransactionalDataWriter& operator=(const SessionTransactionalDataWriter&);

        Session::Database::SessionAccess &m_access;

        // Data pending
        std::vector<Session::Data::SessionData>       m_data;
        std::vector<Session::Data::SessionSummary>    m_summary;
        std::vector<Session::Data::SessionFeature>    m_feature;
        std::vector<Session::Data::SessionInfraction> m_infraction;

        // Callbacks to gather data for finalization
        CallbackCollection<void, void> m_finalize_callbacks;

        OS::Mutex  m_writer_mutex;

        // Writer thread and signalling
        unsigned long WriterThread();

        OS::Event  m_writer_kill;
        OS::Event  m_writer_killed;

        // Writer state
        bool       m_writer_enabled;
        OS::Mutex  m_writing_mutex;

        // Thread must be constructed after all resources
        OS::Thread *m_pwriter_thread;
    };
}

#endif // SESSION_TRANSACTIONAL_DATA_WRITER_H
