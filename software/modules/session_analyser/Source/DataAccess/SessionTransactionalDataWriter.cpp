///
/// @file       SessionTransactionalDataWriter.cpp
///
///             Defines the SessionTransactionalDataWriter that allows
///             transactional data to be written in a background thread. This was previously
///             done by having a query open for the entire session, but this is not advisable
///             as it locks part of the database. The number of rows to be inserted is large,
///             so doing this in one transaction at the end of a session could be prone to
///             trouble if it grows beyond what is expected, but the worst case seen is for a
///             20 Hz update of lead loco position for over an hour, 72000 updates. Tests run
///             on 144000 rows took 2.6 seconds to insert and commit.
///             If more rows are required in the future, partial commits will be required.
///             Previous code updated every 500ms to avoid excessive CPU usage, but that was
///             because it was inserting every row individually.
///
/// @ingroup    Integrated Scenarios, AC05-004
///
/// @author     James Errington
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2005
///
#include "SessionTransactionalDataWriter.h"

#include <common/StandardLogging.h>

#include <functional>

namespace
{
    // According to previous code,

    // * Records are added to a queue when they need to be written to the
    // * database, and once every interval (500ms) the thread runs and
    // * inserts the records into the database.
    // *
    // * Some testing and profiling has been done, and it has been prooven
    // * that by inserting the records in a batch and pausing between the inserts
    // * allows for a much reduced cpu load.  The interval between the batch
    // * saves can be modified, but should be set in the range of (100ms- 2000ms).

    // Unused now.
    //const int WRITE_INTERVAL = 500; // ms
}

namespace DataAccess
{
    /// Constructor. Starts writer thread.
    ///
    /// @param access  Transactional Data to write to in the background thread
    
    SessionTransactionalDataWriter::SessionTransactionalDataWriter(Session::Database::SessionAccess &access)
        : m_access(access)
    {
        m_writer_enabled = false;
        m_pwriter_thread = new OS::Thread(std::bind(&SessionTransactionalDataWriter::WriterThread, this));
    }

    /// Destructor. Signals the thread to die, then waits for it . This allows all pending data to
    /// be flushed.
    
    SessionTransactionalDataWriter::~SessionTransactionalDataWriter()
    {
        // Disable writing because this should not be done as a result of destruction
        m_writer_enabled = false;

        Finalize();
    }

    /// Enables / disables writing to the database by the background thread
    ///
    /// @param enable  true enables, false disables
    
    void SessionTransactionalDataWriter::EnableWriting(bool enable)
    {
        const OS::MutexLock LOCK(m_writing_mutex);
        m_writer_enabled = enable;
    }

    /// Closes the thread. This has the effect of flushing all pending data out to the database.
    ///
    /// @note
    ///     Any data inserted after this function has been called will be silently
    ///     ignored. This function however is intended to be called at the end of
    ///     a session (after which point no more data should be inserted anyway).
    
    void SessionTransactionalDataWriter::Finalize()
    {
        if (m_writer_enabled)
        {
            // Some can register to be able to save at the same time as finalizing
            const OS::MutexLock LOCK(m_writing_mutex);
            m_finalize_callbacks.Call();
        }

        if (m_pwriter_thread)
        {
            m_writer_kill.Set();
            m_writer_killed.Wait();

            delete m_pwriter_thread;
            m_pwriter_thread = 0;
        }
    }

    //
    // INSERTION METHODS AS PER SessionTransactionalData
    //

    void SessionTransactionalDataWriter::InsertSessionData(const Session::Data::SessionData &data)
    {
        if (!m_pwriter_thread)
        {
            return; 
        }

        const OS::MutexLock LOCK(m_writer_mutex);
        m_data.push_back(data);
    }

    void SessionTransactionalDataWriter::InsertSessionSummary(const Session::Data::SessionSummary &summary)
    {
        if (!m_pwriter_thread)
        {
            return;
        }

        const OS::MutexLock LOCK(m_writer_mutex);
        m_summary.push_back(summary);
    }

    void SessionTransactionalDataWriter::InsertSessionFeature(const Session::Data::SessionFeature &feature)
    {
        if (!m_pwriter_thread)
        {
            return; 
        }

        const OS::MutexLock LOCK(m_writer_mutex);
        m_feature.push_back(feature);
    }

    void SessionTransactionalDataWriter::InsertSessionInfraction(const Session::Data::SessionInfraction &infraction)
    {
        if (!m_pwriter_thread)
        {
            return; 
        }

        const OS::MutexLock LOCK(m_writer_mutex);
        m_infraction.push_back(infraction);
    }

    /// The background writer thread entry. Every write interval , pending data is flushed to the
    /// database, if writing is enabled.
    
    unsigned long SessionTransactionalDataWriter::WriterThread()
    {
        while (true)
        {
            // Used to write every WRITE_INTERVAL, but this has been abandoned
            // Now we wait for the end.
            bool kill_thread = m_writer_kill.Wait();
        
            const OS::MutexLock LOCK_WRITING(m_writing_mutex);

            std::vector<Session::Data::SessionData> data;
            std::vector<Session::Data::SessionSummary> summary;
            std::vector<Session::Data::SessionFeature> feature;
            std::vector<Session::Data::SessionInfraction> infraction;

            if (m_writer_enabled)
            {
                {
                    const OS::MutexLock LOCK(m_writer_mutex);

                    data.swap(m_data);
                    summary.swap(m_summary);
                    feature.swap(m_feature);
                    infraction.swap(m_infraction);
                }

                try
                {
                    m_access.InsertSessionData(data);
                    m_access.InsertSessionFeatures(feature);

                    for_each(summary.begin(), summary.end(), [&](Session::Data::SessionSummary &summary){ m_access.InsertSessionSummary(summary); });
                    for_each(infraction.begin(), infraction.end(), [&](Session::Data::SessionInfraction &infraction){ m_access.InsertSessionInfraction(infraction); });
                }
                catch (CommonException &e)
                {
                    e.AddStackTrace(FLSTAMP, "Inserting rows");
                    Trace::g_plog->LogException(e);
                }
                catch (...)
                {
                    Trace::g_plog->STAMP(Trace::ERR) << "Unknown exception caught in writer thread!" << Trace::EndLog();
                }
            }

            if (kill_thread)
            {
                break; 
            }
        }

        m_writer_killed.Set();
        return 0;
    }

    SessionTransactionalDataWriter::FinalizeCallbackID SessionTransactionalDataWriter::AddFinalizationCallback(CallbackCollection<void, void>::CallbackType cb)
    {
        const OS::MutexLock LOCK(m_writing_mutex);
        return m_finalize_callbacks.AddCallback(cb);
    }

    void SessionTransactionalDataWriter::RemoveFinalizationCallback(FinalizeCallbackID id)
    {
        const OS::MutexLock LOCK(m_writing_mutex);
        m_finalize_callbacks.RemoveCallback(id);
    }
}
