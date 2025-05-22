///
/// @file       TransactionLogUnit.cpp
///
///             Defines the Transaction Log Unit unit, who manages the world's
///             environmental conditions.
///
/// @ingroup    Integrated Scenarios, AC05-004
///
/// @author     James Errington
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2005
///

#include "TransactionLogUnit.h"

#include <core_types/SessionData.h>
#include <common/StandardLogging.h>

namespace
{
    const double REQUEST_FREQUENCY = 20.0;

    const int FUNCTION_FIRST = 1;
    const int FUNCTION_LAST  = 2;
    const int FUNCTION_COUNT = 3;
    const int FUNCTION_SUM   = 4;
    const int FUNCTION_AVG   = 5;
    const int FUNCTION_MIN   = 6;
    const int FUNCTION_MAX   = 7;

    const char * const FUNCTION_NAMES[] = {"FIRST", "LAST", "COUNT", "SUM", "AVG", "MIN", "MAX"};
    const int          FUNCTION_NAME_COUNT = sizeof(FUNCTION_NAMES) / sizeof(const char * const);

    const int SUMMARY_PERVEHICLE = 1;
    const int SUMMARY_PERTRAIN   = 2;

    const char * const SUMMARY_NAMES[] = {"PERVEHICLE", "PERTRAIN"};
    const int          SUMMARY_NAME_COUNT = sizeof(SUMMARY_NAMES) / sizeof(const char * const);

    Comms::Object GetSafeRootObject(Comms::Gateway &gateway)
    {
        OS::Lock<Comms::Gateway> LOCK(gateway);
        return gateway.GetRootObject();
    }
}

/// Adds a sample to a log summary info structure, based on the function type
///
/// @param lsi       summary to update
/// @param sample    new sample
/// @param time      time of sample
/// @param position  train position for sample

void TransactionLogUnit::AddSample(LogSummaryInfo &lsi, double sample, double time, double position)
{
    bool record_sample = false;

    if (lsi.sample_count == 0)
        record_sample = true;
    else
    {
        switch(lsi.function_type)
        {
        case FUNCTION_LAST:
            record_sample = true;
            break;
        case FUNCTION_MIN:
            record_sample = (sample < lsi.accumulator);
            break;
        case FUNCTION_MAX:
            record_sample = (sample > lsi.accumulator);
            break;
        case FUNCTION_SUM:
        case FUNCTION_AVG:
            lsi.accumulator += sample;
            break;
        }
    }

    if (record_sample)
    {
        lsi.accumulator = sample;
        lsi.time        = time;
        lsi.position    = position;
    }

    ++lsi.sample_count;
}

/// Populates a database entry from a summary info based on the function type. Only time, position
/// and value are written to .
///
/// @param lsi      summary info
/// @param summary  summary to write to

void TransactionLogUnit::GetResult(LogSummaryInfo &lsi, Session::Data::SessionSummary &summary)
{
    summary.time     = 0.0;
    summary.position = 0.0;
    summary.value    = 0.0;

    switch(lsi.function_type)
    {
    case FUNCTION_COUNT:
        summary.value = lsi.sample_count;
        break;
    case FUNCTION_AVG:
        summary.value = lsi.accumulator / static_cast<double>(lsi.sample_count);
        break;
    default:
        summary.value    = lsi.accumulator;
        summary.time     = lsi.time;
        summary.position = lsi.position;
    }
}

/// Returns a string describing this unit.

std::string TransactionLogUnit::GetName() const
{
    return "Transaction Log Unit";
}

/// Constructor. Works out properties to be logged, initializes the summaries, and starts the
/// watcher.

TransactionLogUnit::TransactionLogUnit(Comms::Gateway &gateway, Common::DataAccess &data_access,
                                       Session::Database::SessionAccess &transaction_data_access,
                                       DataAccess::SessionTransactionalDataWriter &transaction_data_writer,
                                       SATrainPathWatcher &tpw, const Core::BaseScenarioData &scenario_data,
                                       const Core::BaseSessionData &session_data, int hub_id)
    : Comms::SessionUnit(gateway)
    , m_transaction_data_writer(transaction_data_writer)
    , m_tpw(tpw)
    , m_property_watcher(GetSafeRootObject(gateway))
{
    // Fill in base data
    m_session_data.sim_session_id = session_data.session_id;
    m_session_data.hub_id         = hub_id;

    m_session_summary.sim_session_id = session_data.session_id;
    m_session_summary.hub_id         = hub_id;

    // Work out properties to request
    std::vector<int> props;

    std::vector<Session::Data::LogEvent> log_events = transaction_data_access.GetAllLogEvents();
    for (auto & log_event : log_events)
    {
        props.push_back(log_event.property_id);

        m_log_events[log_event.property_id] = log_event;
    }

    std::vector<Session::Data::LogSummary> log_summary = transaction_data_access.GetAllLogSummaries();
    for (auto &summary : log_summary)
    {
        size_t function_number = std::distance(&FUNCTION_NAMES[0], find(&FUNCTION_NAMES[0], &FUNCTION_NAMES[FUNCTION_NAME_COUNT], summary.function_type_name));
        size_t summary_number  = std::distance(&SUMMARY_NAMES[0], find(&SUMMARY_NAMES[0], &SUMMARY_NAMES[SUMMARY_NAME_COUNT], summary.summary_type_name));

        if (function_number != FUNCTION_NAME_COUNT && summary_number != SUMMARY_NAME_COUNT)
        {
            // Constants are offset by 1
            LogSummaryInfo lsi;
            lsi.property_id   = summary.property_id;
            lsi.summary_id    = summary.log_summary_id;
            lsi.function_type = static_cast<int>(function_number + 1);
            lsi.summary_type  = static_cast<int>(summary_number + 1);
            lsi.sample_count  = 0;
            lsi.accumulator   = 0.0;

            props.push_back(summary.property_id);

            m_log_summaries.insert(std::make_pair(summary.property_id, lsi));
        }
        else
        {
            Trace::g_plog->STAMP(Trace::WARN) << "Log summary has bad function/summary type: " << summary.function_type_name << "/" << summary.summary_type_name << Trace::EndLog(); 
        }
    }

    m_property_watcher.AddPropertyChangedCallback(MakeCallback(&TransactionLogUnit::LogEventPropertyChanged, this));
    m_property_watcher.AddPropertyChangedCallback(MakeCallback(&TransactionLogUnit::LogSummaryPropertyChanged, this));

    m_property_watcher.SetPropertyIDs(data_access);
    m_property_watcher.SetProperties(props);

    m_finalize_cb_id = m_transaction_data_writer.AddFinalizationCallback(std::bind(&TransactionLogUnit::FinalizeSessionData, this));

    OS::Lock<Comms::Gateway> lock(GetGateway());
    m_property_watcher.Start();
}

/// Stops the property watcher.

TransactionLogUnit::~TransactionLogUnit()
{
    m_transaction_data_writer.RemoveFinalizationCallback(m_finalize_cb_id);

    OS::Lock<Comms::Gateway> lock(GetGateway());
    m_property_watcher.Stop();
}

/// State has changed. If it has changed to STOPPED for the first time then all session summaries
/// are written to the database
///
/// @param new_state  New session state

void TransactionLogUnit::FinalizeSessionData()
{
    std::lock_guard<std::mutex> lock(m_mutex);

    for (auto &summary : m_running_summaries)
    {
        m_session_summary.log_summary_id = summary.first.first;
        m_session_summary.element        = summary.first.second;

        GetResult(summary.second, m_session_summary);

        m_transaction_data_writer.InsertSessionSummary(m_session_summary);
    }
}

/// A property has changed. If this is because of being found or changed, a log event entry is
/// written on the first instance, or upon applying the delta rule.
///
/// @param pn  property number that changed

void TransactionLogUnit::LogEventPropertyChanged(SimPropertyWatcher::PropertyNumber pn)
{
    std::lock_guard<std::mutex> lock(m_mutex);

    if (pn.reason == SimPropertyWatcher::PropertyNumber::Lost)
    {
        return; 
    }

    const double time = m_tpw.GetTime();

    // Set up the session data once, to save code duplication. 
    m_session_data.property_id = pn.property_id;
    m_session_data.element     = pn.element;
    m_session_data.position    = m_tpw.GetPosition();
    m_session_data.time        = time;
    m_session_data.value       = pn.value;

    if (pn.reason == SimPropertyWatcher::PropertyNumber::Found)
    {
        // If the simproperty has just been found, make sure that we don't already have it,
        std::map<std::pair<int, int>, LogEventInfo>::const_iterator property = m_last_values.find(std::make_pair(pn.property_id, pn.element));

        if (property == m_last_values.end())
        {
            // Make sure it's one that we actually care about.
            std::map<int, Session::Data::LogEvent>::const_iterator event = m_log_events.find(pn.property_id);

            if (event != m_log_events.end())
            {
                // If so, add the current data to the 'last values' map 
                // then insert the initial data into the session data.
                LogEventInfo lei;
                lei.log_event  = event->second;
                lei.last_time  = time;
                lei.last_value = pn.value;

                m_last_values.insert(std::make_pair(std::make_pair(pn.property_id, pn.element), lei));
                    
                m_transaction_data_writer.InsertSessionData(m_session_data);
            }
        }
    }
    else if (pn.reason == SimPropertyWatcher::PropertyNumber::Changed)
    {
        // A simproperty has changed. Determine whether it is one that we have previously
        // cared about.
        std::map<std::pair<int, int>, LogEventInfo>::iterator logevent = m_last_values.find(std::make_pair(pn.property_id, pn.element));

        if (logevent != m_last_values.end())
        {
            LogEventInfo &lei = logevent->second;

            // We want to record this change if it has changed by enough (delta_value) 
            // or it has been long enough since we last recorded it (delta_time)
            const double time_delta  = time - lei.last_time;
            const double value_delta = abs(pn.value - lei.last_value);

            const bool enough_time   = time_delta  > lei.log_event.delta_time;
            const bool enough_change = value_delta > lei.log_event.delta_value;

            if (enough_time || enough_change)
            {
                lei.last_value = pn.value;
                lei.last_time  = time;

                m_transaction_data_writer.InsertSessionData(m_session_data);
            }
        }
    }
}

/// A property has changed. If this is because of being found or changed, the log summary accounts
/// for this sample. Logs on a per train basis convert all incoming elements to -1
///
/// @param pn  property number that changed

void TransactionLogUnit::LogSummaryPropertyChanged(SimPropertyWatcher::PropertyNumber pn)
{
    std::lock_guard<std::mutex> lock(m_mutex);

    if (pn.reason == SimPropertyWatcher::PropertyNumber::Lost)
    {
        return; 
    }

    double time     = m_tpw.GetTime();
    double position = m_tpw.GetPosition();

    for (std::multimap<int, LogSummaryInfo>::const_iterator iter = m_log_summaries.lower_bound(pn.property_id); iter != m_log_summaries.upper_bound(pn.property_id); ++iter)
    {
        int translated_element = pn.element;

        if (iter->second.summary_type == SUMMARY_PERVEHICLE && pn.element == -1)
        {
            // Still capture it
            Trace::g_plog->STAMP(Trace::WARN) << "Log summary is on a per vehicle basis, but an element of -1 has been received: ID = " << iter->first << Trace::EndLog();
        }
        else if (iter->second.summary_type == SUMMARY_PERTRAIN && pn.element != -1)
        {
            // Capture all inputs
            translated_element = -1;
        }

        std::map<std::pair<int, int>, LogSummaryInfo>::iterator iter2 = m_running_summaries.find(std::make_pair(iter->second.summary_id, translated_element));
        if (iter2 == m_running_summaries.end())
        {
            m_running_summaries.insert(std::make_pair(std::make_pair(iter->second.summary_id, translated_element), iter->second));
            iter2 = m_running_summaries.find(std::make_pair(iter->second.summary_id, translated_element));
        }

        if (iter2 != m_running_summaries.end())
        {
            AddSample(iter2->second, pn.value, time, position); 
        }
    }
}


