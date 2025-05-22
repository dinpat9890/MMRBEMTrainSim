///
/// @file       JournalEntryBase.h
///
///             Base class for items that can be written to the motion base journal file.
///
/// @ingroup    KSRTC Simulator
///
/// @author     Peter Byrne
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2018
///

#ifndef JOURNAL_ENTRY_BASE_H
#define JOURNAL_ENTRY_BASE_H

#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>

namespace ckas_interface 
{
    /// Base class for the command and response class hierarchies that represent
    /// the CKAS GenIII communication protocol.
    class journal_entry_base
    {
    private:
        std::time_t             m_create_time;
        bool                    m_write_to_journal;

    public:

        enum class EntryWriteType
        {
            TraceOnly,
            TraceAndJournal
        };

        journal_entry_base(EntryWriteType write_type = EntryWriteType::TraceAndJournal) 
            :   m_create_time(std::time(nullptr)),
                m_write_to_journal(write_type == EntryWriteType::TraceAndJournal)
        {}

        /// Virtual destructor to ensure we clean up derived type objects.
        ///
        /// @remarks    Because we now have a non-default destructor, derived 
        ///             classes will no longer get the automatically generated
        ///             copy and move constructors / assignment.  I *think* we
        ///             could solve this by declaring the virtual destructor as
        ///             using the default implementation (I'm not sure if just
        ///             making it virtual is enough for it to interfere with the
        ///             automatic generation) like so
        ///
        ///                 virtual ~journal_entry_base() = default;
        ///
        ///             but VisStudio 2012 doesn't support that part of the language.
        virtual ~journal_entry_base() {};

        /// @return     True if the entry should be written to the journal
        ///
        /// @remarks    This is true for all but a small number of entries, such
        ///             as the "no-op" command.
        bool                    should_write_to_journal() const { return m_write_to_journal; }
        
        /// Format the element for debug / logging output for the derived classes.
        /// We assume that we're doing this for human readers, not for serializing
        /// data etc.
        virtual std::ostream&   format_for_output(std::ostream& os) const = 0;

        /// Write the command or response out to an output stream.  Assumes that
        /// we're doing this for human readers, not for serializing data etc.
        friend std::ostream&    operator<<(std::ostream& os, const journal_entry_base& entry) 
        { 
            auto create_time = std::localtime(& entry.m_create_time);

            char buffer[32];
            std::strftime(buffer, 32, "%H:%M:%S", create_time);

            os << buffer << entry.m_create_time << " ";

            return entry.format_for_output(os); 
        }
    };
}

#endif