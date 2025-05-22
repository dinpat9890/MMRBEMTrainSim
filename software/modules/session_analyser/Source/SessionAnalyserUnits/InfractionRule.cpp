///
/// @file       InfractionRule.cpp
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

#include "InfractionRule.h"
#include "SessionAnalyserUnits/InfractionUnit.h"
#include <core_data_access/Feature.h>
#include <network_definition/Boundaries/ConvexPolygonBoundary.h> // For region testing
#include <common/StandardLogging.h>

namespace
{
    const auto REQUEST_FREQUENCY            = 20.0;
    const double INVALID_MARKER_DISTANCE    = -1.0;

    const double KM_POST_THRESHOLD          = 2000;
    const double KM_TO_METER                = 1000;
    const std::string KM_POST_LABEL         = "Label";
    const char * const FETY_KM_POST         = "KM Post";
}

/// Constructor. Does nothing. Requirements are not satisified initially.
///
/// @param punit  the infraction unit to obtain resources from

InfractionRule::InfractionRule(InfractionUnit& punit, const std::string& rule_name, Scoring::ScoringParameterProvider& parameter_provider, double infraction_recording_delay)
    : m_parameter_provider(parameter_provider)
    , m_punit(punit)
    , m_required_available(false)
    , m_rule_id(punit.GetRuleID(rule_name))
    , m_infraction_recording_delay(infraction_recording_delay)
{
    // empty
}

/// Destructor. Deletes the feature and path feature watchers

InfractionRule::~InfractionRule()
{
    OS::Lock<Comms::Gateway> LOCK(GetGateway());
    m_pfw.reset();
    m_pwatcher.reset();
}

std::vector<int> InfractionRule::GetFeatureTypeIDsInGroup(Common::DataAccess &data_access, const std::string &group_name)
{
    Core::Database::Feature feature(data_access);
    std::vector<Core::Data::FeatureType> feature_types = feature.GetAllFeatureTypes();

    std::vector<int> ret;
    for (auto &feature_type : feature_types)
    {
        if (feature_type.feature_type_group_name == group_name)
        {
            ret.push_back(feature_type.feature_type_id);
        }
    }

    return ret;
}

int InfractionRule::GetRuleID() const
{
    return m_rule_id;
}

int InfractionRule::GetScenarioId() const
{
    return m_punit.GetScenarioId();
}

//
// Reflections through to the InfractionUnit
//

double InfractionRule::GetParameter(const std::string &parameter_name)
{
    return m_parameter_provider.GetParameterValue(parameter_name);
}

void InfractionRule::RequiresPath()
{
    m_punit.RequiresPath(this);
}

void InfractionRule::Requires(SimPropertyWatcher::Group group_id, const std::string &number_name, Sim::Number::Type *pnumber)
{
    m_punit.Requires(this, group_id, number_name, pnumber);
}

void InfractionRule::Requires(SimPropertyWatcher::Group group_id, const std::string &number_name, Sim::Number::Type *pnumber, InfractionUnit::PropertyCallback cb)
{
    m_punit.Requires(this, group_id, number_name, pnumber, cb);
}

void InfractionRule::RequiresInterpretedTrainProperty(int property_id, Sim::Number::Type *pnumber, InfractionUnit::PropertyCallback cb)
{
    m_punit.RequiresInterpretedTrainProperty(this, property_id, pnumber, cb);
}

void InfractionRule::StartTimer(double period, const Callback<void, void> &cb)
{
    m_punit.StartTimer(period, cb);
}

void InfractionRule::KillTimer(const Callback<void, void> &cb)
{
    m_punit.KillTimer(cb);
}

TimePosition InfractionRule::GetCurrentTimePosition()
{
    return m_punit.GetCurrentTimePosition();
}

void InfractionRule::RecordInfraction(double penalty, double duration)
{
    if ((m_infraction_recording_delay - GetCurrentTimePosition().time) <= 0.0)
    {
        m_punit.RecordInfraction(m_rule_id, penalty, duration);
    }
}

void InfractionRule::RecordPostSessionInfraction(double penalty)
{
    if ((m_infraction_recording_delay - GetCurrentTimePosition().time) <= 0.0)
    {
        m_punit.RecordInfraction(m_rule_id, penalty, 0.0, true);
    }
}


SATrainPathWatcher &InfractionRule::GetPathWatcher()
{
    return m_punit.GetPathWatcher();
}

WorldAPI::WorldAccess &InfractionRule::GetWorldAccess()
{
    return m_punit.GetWorldAccess();
}

Common::DataAccess &InfractionRule::GetDataAccess()
{
    return m_punit.GetDataAccess();
}

WorldAPI::PathPointsWatcher &InfractionRule::GetPathPointsWatcher()
{
    return m_punit.GetPathPointsWatcher();
}

Comms::Gateway &InfractionRule::GetGateway()
{
    return m_punit.GetTheGateway();
}

const Train::Data::ScenarioTrain &InfractionRule::GetScenarioTrain()
{
    return m_punit.GetScenarioTrain();
}

/// Sets up the watching of feature types, and the passing of them.
///
/// @param feature_types  types to watch

void InfractionRule::WatchFeatureTypes(const std::vector<int>& feature_types)
{
    // This will copy the contents of feature_types.
    m_filter.SetAcceptableTypes(feature_types);

    assert(m_pwatcher == 0);
    m_pwatcher = std::unique_ptr<WorldAPI::FeatureWatcher>(new WorldAPI::FeatureWatcher());
    m_pwatcher->SetFeatureTypeFilter(CreateFilterCallback(m_filter));
    m_pwatcher->SetRequestFrequency(REQUEST_FREQUENCY);

    OS::Lock<Comms::Gateway> LOCK(GetGateway());
    assert(m_pfw == 0);
    m_pfw = std::unique_ptr<WorldAPI::PathFeatureWatcher>(new WorldAPI::PathFeatureWatcher(GetWorldAccess(), GetPathWatcher(), *m_pwatcher));
    m_pfw->AddFeaturePassedCallback(MakeCallback(&InfractionRule::InternalFeaturePassed, this));

    m_pwatcher->Attach(GetGateway().GetRootObject());
}

/// Called when a feature being watched is passed. Calls FeaturePassed if requirements are
/// available.
///
/// @param pobj  object passed

void InfractionRule::InternalFeaturePassed(WorldAPI::PathFeatureWatcher::PassedObject pobj)
{
    if (m_required_available)
    {
        FeaturePassed(pobj);
    }
}

/// Gets feature objects being watched without needing to know the internals.

std::vector<Comms::Object> InfractionRule::GetFeatureObjects()
{
    assert(m_pwatcher);

    return Core::Locked<WorldAPI::FeatureWatcher>(*m_pwatcher)->GetObjects();
}

/// Called by the InfractionUnit to notify the rule that there has been a change to the
/// availability of its requirements.
///
/// @param available  if true, all requirements are satisfied

void InfractionRule::SetRequiredAvailable(bool available)
{
    if (m_required_available != available)
    {
        m_required_available = available;

        if (m_required_available)
        {
            RequiredAvailable();
        }
        else
        {
            RequiredNotAvailable();
        }
    }
}


/// Works out if a train is in the region of a live comms object
///
/// @note
///     Only convex polygon boundaries are supported
///
/// @param object  object that has a region
///
/// @return true if the train has a path and is in the region
/// If there is no path, returns false

bool InfractionRule::IsTrainInFeatureRegion(Comms::Object object)
{
    NetworkDefinition::MultiConvexPolygonBoundaryTest test(GetWorldAccess().GetFeatureGeometryData(object));

    if (GetPathWatcher().HasPath())
    {
        return test.IsPointInsideBoundary(GetWorldAccess().GetSegmentPathGeometry(GetPathWatcher().GetPath()).GetGeometricPoint(0.0));
    }

    return false;
}

/// Works out if there is any of interested feature from the list within the given range.
///
/// @param distance_back ..looking for any interested features in this distance from the train lead car and backward.
/// @param distance_front  looking for any interested features in this distance from the train lead car and forward.
///
/// @return true if the train has a path and if there is any of interested feature from the list within the given range.
/// If there is no path, returns false

bool InfractionRule::IsTrainNearToFeature(double distance_back, double distance_front)
{
    if (GetPathWatcher().HasPath())
    {
        return !GetWorldAccess().GetPathFeatures(GetPathWatcher().GetPath(),
            GetFeatureObjects(), true, false, distance_back, distance_front).empty();
    }
    return false;
}

int InfractionRule::GetVehicleCount() const
{
	return m_punit.GetVehicleCount();
}

/// Calculates the penalty based on the min and max values 
/// and map to the points range
///
/// @param current_value  object that has a region
/// @param limit  not used
/// @param min_value  minimum value from where the penalty applied
/// @param max_value  maximum value till full penalty is applied
/// @param min_points  minimum points/penalty
/// @param max_points  maximum points 
///
/// @return calculated penalty

double InfractionRule::CalculatePenalty(double current_value,
    double target_value,
    double full_penalty_value,
    double min_points,
    double max_points)
{
    double penalty = 0.0;
    if (((target_value < full_penalty_value) && (current_value >= target_value)) || ((target_value > full_penalty_value) && (current_value < target_value)))
    {
        penalty = std::min(((current_value - target_value) / (full_penalty_value - target_value))*(max_points - min_points) + min_points, max_points);
    }
    return std::abs(penalty);
}

//
// OngoingInfractionRule
//

/// Constructor. Does nothing.
///
/// @param punit         the infraction unit to obtain resources from
/// @param rule_name     the name of the infraction rule
/// @param accumulative  if true, one infraction is recorded per duration with demerits based on
///                      the penalty.

OngoingInfractionRule::OngoingInfractionRule(InfractionUnit& punit, const std::string &rule_name, Scoring::ScoringParameterProvider& parameter_provider, bool accumulative)
    : InfractionRule(punit, rule_name, parameter_provider)
    , m_accumulative(accumulative)
{
}

void OngoingInfractionRule::OngoingInfraction::StartTimer()
{
    killed = false;
    prule->StartTimer(duration, MakeCallback(&OngoingInfractionRule::OngoingInfraction::OnTimer, this));
}

void OngoingInfractionRule::OngoingInfraction::KillTimer()
{
    killed = true;
    prule->KillTimer(MakeCallback(&OngoingInfractionRule::OngoingInfraction::OnTimer, this));
}

void OngoingInfractionRule::OngoingInfraction::OnTimer()
{
    if (!active)
    {
        KillTimer();
    }
    else
    {
        //infraction is logged with penalty
        if(!hold_active)
        {
            auto time_position = prule->GetCurrentTimePosition();
            prule->RecordInfraction(prule->GetPenalty(start, time_position, duration, penalty));

            // Activate the hold infraction timer if duration is provided
            if(hold_duration != -1)
            {
                StartInfractionHoldTimer();
                KillTimer();
            }
        }

    }
}

void OngoingInfractionRule::OngoingInfraction::StartInfractionHoldTimer()
{
    prule->StartTimer(hold_duration, MakeCallback(&OngoingInfractionRule::OngoingInfraction::OnInfractionHoldTimer, this));
    hold_active = true;
}

void OngoingInfractionRule::OngoingInfraction::KillInfractionHoldTimer()
{
    prule->KillTimer(MakeCallback(&OngoingInfractionRule::OngoingInfraction::OnInfractionHoldTimer, this));
}

void OngoingInfractionRule::OngoingInfraction::OnInfractionHoldTimer()
{
    KillInfractionHoldTimer();
    hold_active = false;
}

/// Called when not all required resources are available. Recording of all infractions is ended.

void OngoingInfractionRule::RequiredNotAvailable()
{
    TimePosition time_position = GetCurrentTimePosition();

    // Equivalent of RecordInfractionEnd on all infractions
    if (m_accumulative)
    {
        while (!m_ongoing_infractions.empty())
        {
            RecordInfractionEnd(m_ongoing_infractions.front().rule_id, time_position);
        }
    }
    else
    {
        for (auto &ongoing_infraction : m_ongoing_infractions)
        {
            ongoing_infraction.active = false;
        }
    }
}

/// Marks the start of a new instance of an infraction. If non-accumulative, this means recording
/// an initial infraction, and starting a periodic timer. It also means removing any previous
/// infractions that 'timed-out'
///
/// @param rule_id    ID of this infraction rule
/// @param time_position         Recorded start time and position of the infraction
/// @param duration   infraction is logged if required condition is met for atleast this much time.
/// @param penalty    penalty points.
//  @param immediate  log immedaitely if required condition is met for atleast duration time.
void OngoingInfractionRule::RecordInfractionStart(int rule_id, TimePosition time_position, double duration, double penalty, bool immediate, double hold_duration)
{
    // Check if already started
    bool already_started = false;

    for (std::list<OngoingInfraction>::iterator iter = m_ongoing_infractions.begin(); iter != m_ongoing_infractions.end(); ++iter)
    {
        if (iter->rule_id == rule_id)
        {
            if (!m_accumulative && iter->killed)
            {
                m_ongoing_infractions.erase(iter);
            }
            else
            {
                already_started = true;
                iter->active = true;
            }

            break;
        }
    }

    if (!already_started)
    {
        OngoingInfraction oi;
        oi.rule_id   = rule_id;
        oi.start     = time_position;
        oi.duration  = duration;
        oi.penalty   = penalty;
        oi.immediate = immediate;
        oi.hold_duration = hold_duration;
        oi.prule     = nullptr;
        oi.active    = true;
        oi.killed    = false;
        oi.hold_active = false;

        m_ongoing_infractions.push_back(oi);

        //log as soon as the required condition is met with penalty points.
        if (immediate)
        {
            m_ongoing_infractions.back().prule = this;
            m_ongoing_infractions.back().StartTimer();
        }
    }
}

/// Marks the end of an instance of an infraction. If accumulative, this means recording an
/// infraction to cover the entire period, otherwise it means just killing the periodic timer
///
/// @param rule_id    ID of this infraction rule
/// @param time_position         end time and position of the infraction

void OngoingInfractionRule::RecordInfractionEnd(int rule_id, TimePosition time_position)
{
    for (std::list<OngoingInfraction>::iterator iter = m_ongoing_infractions.begin(); iter != m_ongoing_infractions.end(); ++iter)
    {
        if (iter->rule_id == rule_id)
        {
            if (m_accumulative)
            {
                double duration = time_position.time - iter->start.time; //This is the time the infraction is active.
                // Record an infraction to cover the entire period
                RecordInfraction(GetAccumulatedPenalty(iter->start, time_position, iter->duration, iter->penalty), duration);
                m_ongoing_infractions.erase(iter);
            }
            else
            {
                iter->active = false;
            }

            break;
        }
    }
}

///This is called by OnTimer.
///This just returns the penalty points that are alloted to this infraction.
///As this function is virtual, derived class can override this function and 
///apply its own logic to calculate penalty points.
//This function is called for every duration seconds if conditions are still active.
double OngoingInfractionRule::GetPenalty(TimePosition start, TimePosition current, double duration, double penalty)
{
    return penalty;
}

///This is called by RecordInfractionEnd.
///This returns calculated penalty points based on infraction penalty points 
///and the duration for which this infraction is active.
///
///This function is called only once in the life time of this infraction.
///
///As this function is virtual, derived class can override this function and 
///apply its own logic to calculate penalty points.
///
///This function is called only once in the life time of this infraction.
///
double OngoingInfractionRule::GetAccumulatedPenalty(TimePosition start, TimePosition current, double duration, double penalty)
{
    return ((current.time - start.time) / duration) * penalty;
}

/// Determines whether an infraction rule is active. This is the case if an instance is found.
///
/// @param rule_id  ID of the rule to check

bool OngoingInfractionRule::GetInfractionState(int rule_id)
{
    for (auto &ongoing_infraction : m_ongoing_infractions)
    {
        if (ongoing_infraction.rule_id == rule_id && ongoing_infraction.active)
        {
            return true;
        }
    }

    return false;
}

//
// OngoingInfractionState
//

/// Constructor. Does nothing.
///
/// @param prule      Rule this object belongs to
/// @param rule_id    ID of this infraction rule
/// @param penalty    Ongoing penalty
/// @param demerits  demerit points that need to be applied for an occurance.
/// @param immediate  if true, a demerit is incurred just for the occurrence as well as its duration

OngoingInfractionState::OngoingInfractionState(OngoingInfractionRule *prule, double duration, double penalty, bool immediate, double hold_duration)
    : m_prule(prule)
    , m_duration(duration)
    , m_penalty(penalty)
    , m_immediate(immediate)
    , m_hold_duration(hold_duration)
{
}

/// Sets the state of the infraction. If this is different from the current state, an infraction
/// is recorded as being started or ended.
///
/// @param state  true if an infraction started recording

bool OngoingInfractionState::SetState(bool state)
{
    auto rule_id = m_prule->GetRuleID();
    bool current_state = m_prule->GetInfractionState(rule_id);
    bool ret = ((current_state != state) && state);

    if (current_state != state)
    {
        if (state)
        {
            m_prule->RecordInfractionStart(rule_id, m_prule->GetCurrentTimePosition(), m_duration, m_penalty, m_immediate, m_hold_duration);
        }
        else
        {
            m_prule->RecordInfractionEnd(rule_id, m_prule->GetCurrentTimePosition());
        }
    }

    return ret;
}

//
// TooOftenChecker
//

/// Constructor. Does nothing.
///
/// @param limit     Maximum number of times event can occur.
/// @param duration  Period of which events are to be checked.

TooOftenChecker::TooOftenChecker(int limit, double duration)
    : m_duration(duration)
    , m_limit(limit)
{
}

/// Removes times out of the specified duration. Adds this time.
///
/// @param instance_time  time of event
///
/// @return true if the event has occurred too often

bool TooOftenChecker::Check(double instance_time)
{
    // Remove old times
    m_instance_times.erase(m_instance_times.begin(), lower_bound(m_instance_times.begin(), m_instance_times.end(), instance_time - m_duration));
    m_instance_times.push_back(instance_time);

    // Useful log for debugging repetition infractions
    // Trace::g_plog->STAMP(Trace::INFO) << "Event at " << instance_time << "s, " << m_instance_times.size() << "/" << m_limit << " (" << m_duration << "s)" << Trace::EndLog();

    return static_cast<int>(m_instance_times.size()) > m_limit;
}
