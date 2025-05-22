///
/// @file       MotionBaseJournal.h
///
///             A threaded logging mechanism for the command / response interaction
///             with the CKAS controller
///
/// @ingroup    KSRTC Simulator
///
/// @author     Peter Byrne
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2018
///

#ifndef MOTION_BASE_JOURNAL_H
#define MOTION_BASE_JOURNAL_H

#include <memory>
#include <queue>
#include <fstream>
#include <string>
#include "common/OSThreadClasses.h"
#include "JournalEntryBase.h"

namespace ckas_interface
{
    /// A threaded logging class for the command / response interaction with the CKAS controller.
    /// Takes the work of formatting & writing the journal out of the main transmit and receive
    /// threads in the GenIIIClient.  Entries are queued and then written as batches on a timer
    /// thread.
    ///
    /// @remarks Currently appends to a fixed filename - "MotionBaseJournal.txt"
    class MotionBaseJournal : private Common::Unique
    {
    public:
        MotionBaseJournal();
        ~MotionBaseJournal();

        /// Add an element to the journal's queue.
        ///
        /// @param entry    The entry to add to the queue.  Note that the journal takes 
        ///                 ownership of the entries.
        void add(std::unique_ptr<journal_entry_base> entry);

        /// Mark a point in the journal where something happened
        ///
        /// @param message  Message to add to the journal
        void mark_point_of_interest(const std::string &message);

    private:
        /// The destination file.
        std::ofstream                       m_journal_file;
        
        typedef std::queue<std::unique_ptr<journal_entry_base>> CkasInteractionQueue;
        
        /// Entries ready to be pushed to the journal
        CkasInteractionQueue                m_pending_journal_buffer;
        
        /// Writes a queue of entries to the journal.
        ///
        /// @param queue    The sequence of entries to write.  At the end of the call the queue will
        ///                 be left empty.
        void                                write_to_journal(CkasInteractionQueue &queue);

        /// Worker thread for writing to the file
        std::unique_ptr<OS::Thread>         m_journal_thread;

        /// Process for the journal thread
        OS::ThreadReturnType                journal_thread_worker();

        /// Signal for ending the journal thread
        OS::Signaller                       m_thread_kill_signal;
        
        /// Timer that controls writing batches of entries out to the file.
        OS::Timer                           m_journal_timer;

        /// Lock for controlling access to the shared entry queues
        OS::CriticalSection                 m_journal_lock;
    };
}

#endif