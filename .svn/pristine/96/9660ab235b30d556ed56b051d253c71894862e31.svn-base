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

#include "MotionBaseJournal.h"
#include <iostream>
#include <chrono>
#include <ctime>

namespace ckas_interface 
{
    namespace
    {
        /// Sane default limits for the Hardware polling rate
        const int           RECENT_INTERACTION_QUEUE_LENGTH = 10;

        /// Retry period for connecting
        const int           JOURNAL_WRITE_PERIOD_SECONDS = 10;

        /// Journal entry for adding markers, such as errors detected by the controller.
        class point_of_interest : public journal_entry_base
        {
        private:
            const std::string   m_message;

            /// Hidden constructor, create instances using the "create" function.
            point_of_interest(const std::string& message) : m_message(message) {}

        public:

            std::ostream&   format_for_output(std::ostream& os) const override
            {
                os << "** " << m_message;
                return os;
            }
        
            static std::unique_ptr<journal_entry_base> create(const std::string& message)
            {
                return std::unique_ptr<point_of_interest>(new point_of_interest(message));
            }
        };
    }

    MotionBaseJournal::MotionBaseJournal()
        :   m_thread_kill_signal(),
            m_journal_lock(),
            m_pending_journal_buffer()
    {
        auto create_time = std::time(nullptr);
        auto journal_name = std::stringstream();
        journal_name << "MotionBase." 
                     <<  std::put_time(std::localtime(&create_time), "%y%m%d%H%M%S")
                     << ".txt";

        m_journal_file.open(journal_name.str(), std::ofstream::app);

        {
            using std::chrono::system_clock;
            
            auto now_time = system_clock::to_time_t(system_clock::now());
            m_journal_file << "Session started at " << std::ctime(&now_time) << std::endl;
        }
        
        auto journal_period = OS::OSTime();
        journal_period.seconds = JOURNAL_WRITE_PERIOD_SECONDS;
        m_journal_timer.Set(journal_period, true, journal_period);

        m_journal_thread.reset(new OS::Thread(
            std::bind(&MotionBaseJournal::journal_thread_worker, this),
            "MotionBaseJournal"));
    }

    /// Signal the journal thread to shutdown and flush out the pending buffers.
    MotionBaseJournal::~MotionBaseJournal()
    {
        m_thread_kill_signal.Signal();
        m_journal_thread->Join();
        m_journal_timer.Cancel();

        // Flush the pending data if there is anything left
        const OS::SectionLock LOCK(m_journal_lock);

        write_to_journal(m_pending_journal_buffer);
        
        {
            using std::chrono::system_clock;
            
            auto now_time = system_clock::to_time_t(system_clock::now());
            m_journal_file << "End session at " << std::ctime(&now_time) << std::endl;
        }

        m_journal_file.close();
    }

    
    /// Add an element to the journal's queue.
    ///
    /// @param entry    The entry to add to the queue.  Note that the journal takes 
    ///                 ownership of the entries.
    void    MotionBaseJournal::add(std::unique_ptr<journal_entry_base> element)
    {
        const OS::SectionLock LOCK(m_journal_lock);

        m_pending_journal_buffer.push(std::move(element));
    }
     
    
    /// Mark a point in the journal where something happened
    ///
    /// @param message  Message to add to the journal
    void MotionBaseJournal::mark_point_of_interest(const std::string &message)
    {
        add(point_of_interest::create(message));
    }

    /// Journalling thread implementation. The thread loop will be controlled by two events: a timer
    /// and a kill signal. The timer throttles the rate that we send events and the kill signal ends
    /// the whole process.
    OS::ThreadReturnType    MotionBaseJournal::journal_thread_worker()
    {
        /// The Event Handles. 0 = Kill Event and 1 = the Polling Timer
        std::vector<OS::OSHandle> events; 
        events.push_back(m_thread_kill_signal.GetEvent().handle);
        events.push_back(m_journal_timer.handle);

        const int timer_event_index = 1;
        
        while (true)
        {
            // Wait for either the timer or kill signal events
            // If we got the timer event, we keep processing, but for any other result we exit this loop
            auto wait_result = OS::WaitForMultipleObjects(events, OS::INFINITE);
            if (wait_result != timer_event_index)
                break;

            // Time to write a batch of entries to the journal file. Because this could be a
            // relatively costly call, we minimize the time that we're in the critical section by
            // swapping the buffer with a local empty one and then writing out the local queue.

            auto elements_to_write = CkasInteractionQueue();
            
            {
                const OS::SectionLock LOCK(m_journal_lock);
                std::swap(elements_to_write, m_pending_journal_buffer);
            }

            write_to_journal(elements_to_write);
        }

        return OS::CastToReturnType(0UL);
    }

    /// Write the interactions to the journal file.
    ///
    /// @param queue    Entries to write to journal; queue is left empty.
    void    MotionBaseJournal::write_to_journal(CkasInteractionQueue &queue)
    {
        while (!queue.empty())
        {
            auto next_element = std::move(queue.front());
            if (next_element->should_write_to_journal())
            {
                m_journal_file << *next_element << std::endl;
            }
            queue.pop();
        }
    }
}