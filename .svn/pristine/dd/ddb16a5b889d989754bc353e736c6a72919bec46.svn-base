///
/// @file       InfractionRule.h
///
///             Declares the InfractionRule class, a base for all infraction
///             rules, along with the OngoingInfractionRule and
///             TooOftenChecker helper implementations
///
/// @ingroup    Integrated Scenarios, AC05-004
///
/// @author     James Errington
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2005
///

#ifndef INFRACTION_RULE_H
#define INFRACTION_RULE_H

#include "SessionAnalyserUnits/Utility.h"
#include "SessionAnalyserUnits/SimPropertyWatcher.h"
#include "SATrainPathWatcher.h"
#include "InterpretedTrainProperties.h"
#include "DataAccess/SessionTransactionalDataWriter.h"

#include <train_data_access/Train.h>
#include <world_api/WorldAccess.h>
#include <world_api/PathFeatureWatcher.h>
#include <world_api/PathPointsWatcher.h>

#include <list>
#include <functional>

#include "ScoringParameterProvider.h"

struct TimePosition
{
    double time;
    double position;
};


class InfractionUnit;

/// Base class for all infraction rules. Provides methods for derived classes to use for accessing
/// resources.

class InfractionRule
{
public:
    InfractionRule(InfractionUnit& punit, const std::string &rule_name, Scoring::ScoringParameterProvider& parameter_provider, double infraction_recording_delay = 0.0);
    virtual ~InfractionRule();

    static std::vector<int> GetFeatureTypeIDsInGroup(Common::DataAccess &data_access, const std::string &group_name);

    int GetRuleID() const;
    int GetScenarioId() const;
    double GetParameter(const std::string &parameter_name);

    // c/b is not called until all required are available, and then contains initial state
    void RequiresPath();
    void Requires(SimPropertyWatcher::Group group_id, const std::string &number_name, Sim::Number::Type *pnumber);
    void Requires(SimPropertyWatcher::Group group_id, const std::string &number_name, Sim::Number::Type *pnumber, std::function<void (Sim::Number::Type)> cb);
    void RequiresInterpretedTrainProperty(int property_id, Sim::Number::Type *pnumber, std::function<void (Sim::Number::Type)> cb);

    void WatchFeatureTypes(const std::vector<int>& feature_types);

    // Implementable
    virtual void RequiredAvailable() { }
    virtual void RequiredNotAvailable() { }
	virtual void SessionStopped() { }
	virtual void SessionProcessing() {}
	virtual void SessionSaved() {}
	virtual void SessionRunning() {}
	virtual void SessionPaused() {}

    virtual void FeaturePassed(WorldAPI::PathFeatureWatcher::PassedObject pobj) { }
    virtual void TimePositionChanged(TimePosition time_position) { }

    Comms::Gateway              &GetGateway();
    SATrainPathWatcher          &GetPathWatcher();
    WorldAPI::PathPointsWatcher &GetPathPointsWatcher();
    WorldAPI::WorldAccess       &GetWorldAccess();
    Common::DataAccess          &GetDataAccess();

    const Train::Data::ScenarioTrain &GetScenarioTrain();

    std::vector<Comms::Object> GetFeatureObjects();

    // Utility
    bool IsTrainInFeatureRegion(Comms::Object object);
    bool IsTrainNearToFeature(double distance_back = 0.0, double distance_front = 1.0);
	int GetVehicleCount() const;

    // Timing
    void StartTimer(double period, const Callback<void, void> &cb);
    void KillTimer(const Callback<void, void> &cb);

    TimePosition GetCurrentTimePosition();

    // Output
    void RecordInfraction(double penalty, double duration = 0.0);

    // Records an infraction that is calculated at the end of a session.
    void RecordPostSessionInfraction(double penalty);

    void SetRequiredAvailable(bool available);
    double CalculatePenalty(double current_value,
        double target_value,
        double full_penalty_value,
        double min_points,
        double max_points);

private:
    const Scoring::ScoringParameterProvider& m_parameter_provider;

    void InternalFeaturePassed(WorldAPI::PathFeatureWatcher::PassedObject pobj);

    InfractionUnit& m_punit;
    bool m_required_available;
    const int m_rule_id;
    const double m_infraction_recording_delay;

    WorldAPI::FeatureTypeFilter  m_filter;
    std::unique_ptr<WorldAPI::FeatureWatcher> m_pwatcher;
    std::unique_ptr<WorldAPI::PathFeatureWatcher> m_pfw;
};

/// Extra functionality for recording infractions that have a duration
class OngoingInfractionRule : public InfractionRule
{
public:
    OngoingInfractionRule(class InfractionUnit& punit, const std::string &rule_name, Scoring::ScoringParameterProvider& parameter_provider, bool accumulative = false);

    // Overridden response, call this if overriding
    void RequiredNotAvailable() override;

    void RecordInfractionStart(int rule_id, TimePosition time, double duration, double penalty, bool immediate, double hold_duration);
    void RecordInfractionEnd(int rule_id, TimePosition time);

    bool GetInfractionState(int rule_id);

    virtual double GetPenalty(TimePosition start, TimePosition current, double duration, double penalty);
    virtual double GetAccumulatedPenalty(TimePosition start, TimePosition current, double duration, double penalty);

private:
    // Configuration
    bool m_accumulative;

    // Run-time infractions
    struct OngoingInfraction
    {
        int          rule_id;
        TimePosition start;
        double       duration;
        double       penalty;
        bool         immediate;
        double       hold_duration;

        // For non-accumulative versions
        OngoingInfractionRule *prule;
        bool active;
        bool killed;

        bool hold_active;
        bool hold_killed;
        
        void StartTimer();
        void KillTimer();

        void OnTimer();

        void StartInfractionHoldTimer();
        void KillInfractionHoldTimer();
        void OnInfractionHoldTimer();

    };

    // Using a list so infraction addresses are constant for non-accumulative
    // timers
    std::list<OngoingInfraction> m_ongoing_infractions;
};

/// Encapsulates an infraction rule that has state. This allows an evaluator to simply call
/// SetState, not worrying about the other parameters.

class OngoingInfractionState
{
public:
    OngoingInfractionState(OngoingInfractionRule *prule, double duration, double penalty, bool immediate = true, double hold_duration = -1.0);

    bool SetState(bool state);

private:
    OngoingInfractionRule *m_prule;
    double m_duration;
    double m_penalty;
    bool   m_immediate;
    double m_hold_duration;
};

/// Helper class for checking if an event occurs too frequently within a set period.

class TooOftenChecker
{
public:
    TooOftenChecker(int limit, double duration);

    bool Check(double instance_time);

private:
    double m_duration;
    double m_limit;

    std::vector<double> m_instance_times;
};

template<typename T>
bool Change(T &lhs, T rhs)
{
	bool changed = (lhs != rhs);
	lhs = rhs;

	return changed;
}

#endif // INFRACTION_RULE_H
