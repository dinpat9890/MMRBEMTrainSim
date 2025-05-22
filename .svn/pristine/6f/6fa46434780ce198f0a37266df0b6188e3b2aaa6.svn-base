///
/// @file       TransactionLogUnit.h
///
///             Declares the TransactionLogUnit unit, that logs event
///             changes and summaries.
///
/// @ingroup    Integrated Scenarios, AC05-004
///
/// @author     James Errington
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2005
///

#ifndef TRANSACTION_LOG_UNIT_H
#define TRANSACTION_LOG_UNIT_H

#include "SimPropertyWatcher.h"
#include "SessionAnalyserUnits/SATrainPathWatcher.h"
#include "DataAccess/SessionTransactionalDataWriter.h"

#include <world_api/WorldAccess.h>
#include <sim_comms/ProcessingInterfaces.h>
#include <sim_comms/Unit.h>

namespace Core
{
    struct BaseScenarioData;
    struct BaseSessionData;
}

/// Logs events as they change as well as summaries of events

class TransactionLogUnit : public Comms::SessionUnit, public Comms::ActiveProcessing
{
public:
    // Constructor
    TransactionLogUnit(Comms::Gateway &gateway, Common::DataAccess &data_access,
        Session::Database::SessionAccess &transaction_data_access,
        DataAccess::SessionTransactionalDataWriter &transaction_data_writer, SATrainPathWatcher &tpw,
        const Core::BaseScenarioData &scenario_data, const Core::BaseSessionData &session_data, int hub_id);
    ~TransactionLogUnit();

    std::string GetName() const override;

    void FinalizeSessionData();

private:
    // Callbacks
    void LogEventPropertyChanged(SimPropertyWatcher::PropertyNumber pn);
    void LogSummaryPropertyChanged(SimPropertyWatcher::PropertyNumber pn);

private:
    struct LogEventInfo
    {
        Session::Data::LogEvent log_event;
        double last_time;
        double last_value;
    };

    struct LogSummaryInfo
    {
        int property_id;
        int summary_id;
        int function_type;
        int summary_type;

        int    sample_count;
        double accumulator;

        double time;
        double position;
    };

    // Operations on the log summary structure
    static void AddSample(LogSummaryInfo &lsi, double sample, double time, double position);
    static void GetResult(LogSummaryInfo &lsi, Session::Data::SessionSummary &summary);

private:
    std::mutex  m_mutex;

    // Configuration
    DataAccess::SessionTransactionalDataWriter &m_transaction_data_writer;
    SATrainPathWatcher &m_tpw;

    SimPropertyWatcher m_property_watcher;

    std::map<int, Session::Data::LogEvent>      m_log_events;
    std::map<std::pair<int, int>, LogEventInfo> m_last_values;

    std::multimap<int, LogSummaryInfo>    m_log_summaries;
    std::map<std::pair<int, int>, LogSummaryInfo> m_running_summaries;

    // Base data for each record
    Session::Data::SessionData    m_session_data;
    Session::Data::SessionSummary m_session_summary;

    DataAccess::SessionTransactionalDataWriter::FinalizeCallbackID m_finalize_cb_id;
};

#endif // TRANSACTION_LOG_UNIT_H
