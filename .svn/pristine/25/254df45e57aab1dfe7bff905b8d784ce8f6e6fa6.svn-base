///
/// @file       InfractionUnit.h
///
///             Declares the InfractionUnit unit, who manages infractions.
///
/// @ingroup    Integrated Scenarios, AC05-004
///
/// @author     James Errington
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2005
///

#ifndef INFRACTION_UNIT_H
#define INFRACTION_UNIT_H

#include "ScoringParameterProvider.h"
#include "DBScoringParameterProvider.h"
#include "SimPropertyWatcher.h"
#include "SessionAnalyserUnits/SATrainPathWatcher.h"
#include "SessionAnalyserUnits/InfractionRule.h"
#include "SessionAnalyserUnits/InterpretedTrainProperties.h"

#include "DataAccess/SessionTransactionalDataWriter.h"

#include "train_data_access/Train.h"
#include "scoring_data_access/ScoringParameter.h"
#include "scoring_data_access/ScoringRule.h"

#include "common/Callback.h"
#include "common/Properties.h"
#include "sim_comms/ProcessingInterfaces.h"
#include "sim_comms/Unit.h"
#include <world_api/WorldAccess.h>
#include "world_api/PathFeatureWatcher.h"
#include <world_api/PathPointsWatcher.h>
#include <functional>
#include <memory>

namespace Project { class SessionAnalyserProperties; }

/// Provides resources for infraction rules.

class InfractionUnit : public Comms::SessionUnit, public Comms::ActiveProcessing
{
public:
    // Constructor
    InfractionUnit(Comms::Gateway &gateway, Common::DataAccess &data_access, WorldAPI::WorldAccess &world_access,
        SATrainPathWatcher &tpw, WorldAPI::PathPointsWatcher &ppw, WorldAPI::PointsWatcher &points_watcher,
        DataAccess::SessionTransactionalDataWriter &transaction_data_access, int hub_id, int vehicle_index,
        const std::string &car_class, const std::string &hub_mode, int session_id, int scenario_id,
        int scenario_train_id, const Project::SessionAnalyserProperties &props);
    ~InfractionUnit();

    std::string GetName() const override;

    void StateChanged(Comms::State new_state) override;
	void StateChanging(Comms::State new_state) override;

    // Infraction Rule resources
    typedef std::function<void (Sim::Number::Type)> PropertyCallback;

    // Configuration
    int    GetRuleID(const std::string &rule_name);
    double GetParameter(const std::string &parameter_name);

    const Train::Data::ScenarioTrain &GetScenarioTrain() { return m_scenario_train; }

    // Resource demands
    void RequiresPath(InfractionRule *prule);
    void Requires(InfractionRule *prule, SimPropertyWatcher::Group group_id, const std::string &number_name, Sim::Number::Type *pnumber);
    void Requires(InfractionRule *prule, SimPropertyWatcher::Group group_id, const std::string &number_name, Sim::Number::Type *pnumber, PropertyCallback cb);
    void RequiresInterpretedTrainProperty(InfractionRule *prule, int property_id, Sim::Number::Type *pnumber, PropertyCallback cb);

    // Timers
    void StartTimer(double period, const Callback<void, void> &cb);
    void KillTimer(const Callback<void, void> &cb);

    // Recording infractions
    void RecordInfraction(int rule_id, double penalty, double duration = 0.0, bool ignore_session_state = false);

    // Access to many helper objects
    Comms::Gateway &GetTheGateway() { return GetGateway(); }

    SATrainPathWatcher          &GetPathWatcher()       { return m_tpw; }
    WorldAPI::WorldAccess       &GetWorldAccess()       { return m_world_access; }
    Common::DataAccess          &GetDataAccess()        { return m_data_access; }
    WorldAPI::PathPointsWatcher &GetPathPointsWatcher() { return m_ppw; }

    TimePosition GetCurrentTimePosition();

    Scoring::ScoringParameterProvider& GetParameterProvider();

	int GetVehicleCount() const;
    int GetScenarioId() const;
private:
    // Timer mechanism
    struct TimerInfo
    {
        double next_time;
        double interval;

        Callback<void, void> *pcb;

        bool operator<(const TimerInfo &info) const
        {
            return next_time < info.next_time;
        }
    };

    // Callbacks
    void RouteChanged();
    void PositionChanged();
	void ObjectCreated(Comms::Object object);
    void PropertyChanged(SimPropertyWatcher::PropertyNumber pn);

    std::vector<TimerInfo> m_timers;

    // Property watching
    SimPropertyWatcher m_property_watcher;
    std::vector<int>   m_properties_required;

    // Requirements as property ID -> rule, and count not found yet
    std::multimap<int, std::pair<Sim::Number::Type *, std::pair<InfractionRule *, PropertyCallback>>> m_property_requirement;
    std::map<InfractionRule *, int> m_properties_still_required;

    bool m_have_path;

    std::recursive_mutex m_mutex;

    Common::DataAccess          &m_data_access;
    WorldAPI::WorldAccess       &m_world_access;
    SATrainPathWatcher          &m_tpw;
    WorldAPI::PathPointsWatcher &m_ppw;

    DataAccess::SessionTransactionalDataWriter &m_transaction_data_access;

    // Runtime configuration
    Train::Data::ScenarioTrain m_scenario_train;
    std::string                m_car_class;
    int                        m_vehicle_index;

    std::vector<Scoring::Data::ScoringParameter> m_parameters;
    std::vector<Scoring::Data::ScoringRule>      m_rules;

    // State
    Comms::State m_session_state;
    bool m_reached_stopped;

    TimePosition m_current_time_position;

    // Rule helpers
    std::map<InfractionRule*, InterpretedTrainProperties*> m_infraction_rule_train_properties;

    // Base database structures
    Session::Data::SessionInfraction m_session_infraction;

    // Active rules
    std::vector<std::unique_ptr<InfractionRule>> m_infraction_rules;

    // Remember our callbacks to remove. Eventually we should convert the SATrainPathWatcher to
    // use callback IDs for the time position callback to, in which case we would need to store that
    // here too.
    Comms::CallbackID m_route_change_cb_id;

    Scoring::DBScoringParameterProvider m_parameter_provider;

	int m_vehicle_count;

    int m_scenario_id;
};

#endif // INFRACTION_UNIT_H
