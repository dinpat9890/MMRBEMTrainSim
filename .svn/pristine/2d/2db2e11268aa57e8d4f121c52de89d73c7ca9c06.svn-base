///
/// @file       InfractionUnit.cpp
///
///             Declares the InfractionUnit unit, who manages infractions.
///
/// @ingroup    Integrated Scenarios, AC05-004
///
/// @author     James Errington
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2005
///

#include "InfractionUnit.h"
#include "SessionAnalyserProperties.h"
#include "ProjectConfig.h"

#include <common/StandardLogging.h>
#include <utility/Utilities.h>

#include "train_comms_structure/TrainObjectConstants.h"
#include "core_comms_structure/CoreObjectConstants.h"

namespace
{
    const double REQUEST_FREQUENCY = 20.0;

    const auto M_TO_KM = 1000.0;
    // For easier requirement coding we assign the path a property ID!
    const int PATH_PROPERTY_ID = -1;

    Comms::Object GetSafeRootObject(Comms::Gateway &gateway)
    {
        OS::Lock<Comms::Gateway> LOCK(gateway);
        return gateway.GetRootObject();
    }
}

/// Constructor. Gets all configuration information from the database.
///
/// @param gateway  The gateway to use.

InfractionUnit::InfractionUnit(Comms::Gateway &gateway, Common::DataAccess &data_access,
                               WorldAPI::WorldAccess &world_access, SATrainPathWatcher &tpw,
                               WorldAPI::PathPointsWatcher &ppw, WorldAPI::PointsWatcher &points_watcher,
                               DataAccess::SessionTransactionalDataWriter &transaction_data_access, int hub_id,
                               int vehicle_index, const std::string &car_class, const std::string &hub_mode,
                               int session_id, int scenario_id, int scenario_train_id,
                               const Project::SessionAnalyserProperties &props)
    : Comms::SessionUnit(gateway)
    , m_property_watcher(GetSafeRootObject(gateway))
    , m_have_path(false)
    , m_data_access(data_access)
    , m_world_access(world_access)
    , m_tpw(tpw)
    , m_ppw(ppw)
    , m_transaction_data_access(transaction_data_access)
    , m_car_class(car_class)
    , m_session_state(Comms::State::UNKNOWN)
    , m_reached_stopped(false)
    , m_parameter_provider(Scoring::DBScoringParameterProvider(data_access))
	,m_vehicle_count(-1)
    , m_scenario_id(scenario_id)
{
    // Initialize infraction data structure, first infraction will have ID 1
    m_session_infraction.sim_session_id = session_id;
    m_session_infraction.hub_id         = hub_id;
    m_session_infraction.infraction_id  = 1;

    Train::Database::Train train(data_access);
    m_scenario_train = train.GetScenarioTrain(scenario_id, scenario_train_id);
    m_vehicle_index  = vehicle_index;

    Scoring::Database::ScoringParameter scoring_parameter(m_data_access);
    m_parameters = scoring_parameter.GetAllScoringParameters();

    Scoring::Database::ScoringRule scoring_rule(m_data_access);
    m_rules = scoring_rule.GetAllScoringRules();

    // These must be created after the rules are extracted above since
    // the infraction rules request rule info from us.
    m_infraction_rules = Project::CreateInfractionRules(this, props, car_class, hub_mode);

    const OS::Lock<Comms::Gateway> LOCK(GetGateway());

	AddCreationCallback(GetGateway().GetRootObject(), [&](Comms::Object object) { ObjectCreated(object); });

    // We also need the lock of the path watcher while we add callbacks and simulate a changed route
    {
        std::lock_guard<WorldAPI::PathWatcher> path_watcher_lock(m_tpw);

        m_route_change_cb_id = m_tpw.AddRouteChangeCallback(MakeCallback(&InfractionUnit::RouteChanged, this));
        m_tpw.AddTimePositionCallback(MakeCallback(&InfractionUnit::PositionChanged, this));

        // Trigger a change in route
        RouteChanged();
    }

    m_property_watcher.AddPropertyChangedCallback(MakeCallback(&InfractionUnit::PropertyChanged, this));
    m_property_watcher.SetProperties(m_properties_required);
    m_property_watcher.Start();
   
}

/// Timer information is deleted, the property watcher is stopped, and all rules are deleted.

InfractionUnit::~InfractionUnit()
{
    const OS::Lock<Comms::Gateway> LOCK(GetGateway());

    {
        std::lock_guard<WorldAPI::PathWatcher> path_watcher_lock(m_tpw);
        m_tpw.RemoveRouteChangeCallback(m_route_change_cb_id);
        m_tpw.RemoveTimePositionCallback(MakeCallback(&InfractionUnit::PositionChanged, this));
    }

    for (auto &timer : m_timers)
    {
        delete timer.pcb;
    }

    m_property_watcher.Stop();

    for (auto &infraction_rule_train_property : m_infraction_rule_train_properties)
    {
        delete infraction_rule_train_property.second;
    }
}

/// Returns a string describing this unit.

std::string InfractionUnit::GetName() const
{
    return "Infraction Unit";
}

int InfractionUnit::GetScenarioId() const
{
    return m_scenario_id;
}

TimePosition InfractionUnit::GetCurrentTimePosition()
{
    std::lock_guard<std::recursive_mutex> lock(m_mutex);

    return m_current_time_position;
}

Scoring::ScoringParameterProvider& InfractionUnit::GetParameterProvider()
{
    return m_parameter_provider;
}

void InfractionUnit::ObjectCreated(Comms::Object object)
{
	std::lock_guard<std::recursive_mutex> lock(m_mutex);

	int class_id = Core::GetClassID(object);
	if (class_id == Core::ClassID::WORLD)
	{
		AddCreationCallback(object, [&](Comms::Object object) { ObjectCreated(object); });
	}
	else if (class_id == Core::ClassID::HUB)
	{
		// Is this our hub?
		if (m_session_infraction.hub_id == object.Numbers().Store().Get(object.Numbers().Info().GetID(Core::ValueName::Hub::HUB_ID)))
		{
			AddCreationCallback(object, [&](Comms::Object object) { ObjectCreated(object); });

			/// from here we can set the value of the active cab index...
			m_property_watcher.SetActiveCabVehicleIndex(static_cast<int>(object.Numbers().Get(Core::ValueName::Hub::VEHICLE_INDEX).value));
			//// Create an object for reporting under hub
			//Sim::ObjectDefinition def = Project::GetObjectDefinition(Project::ClassID::REPORTING);
			//object.CreateChild(def);
		}
	}
	else if (class_id == Train::ClassID::TRAIN)
	{
        Train::Database::Train train(m_data_access);
        auto elements = train.GetTrainElements(m_scenario_train.train_id);
        m_vehicle_count = elements.size();
	}
}

int InfractionUnit::GetVehicleCount() const
{
	return m_vehicle_count;
}
/// State has changed. If it has changed to STOPPED for the first time then all infraction rules
/// are notified that their requirements are no longer satisfied, to avoid writing infractions
/// after saving.
///
/// @param new_state  New session state

void InfractionUnit::StateChanged(Comms::State new_state)
{
    const auto LOCK = m_tpw.Lock();
    std::lock_guard<std::recursive_mutex> lock(m_mutex);

    m_session_state = new_state;

    if (m_session_state == Comms::State::RESETTING && !m_reached_stopped)
    {
        // Set required not avaiable for every rule by adding a huge number to properties required
        // Infractions may be written as a result of this
        for (auto& infraction_rule : m_infraction_rules)
        {
            if (m_properties_still_required[infraction_rule.get()] != 0)
            {
                infraction_rule->SetRequiredAvailable(false);
            }

            m_properties_still_required[infraction_rule.get()] += std::numeric_limits<int>::max() / 2;

			infraction_rule->SessionStopped();
        }

        // No more infractions written after this
        m_reached_stopped = true;
    }
	else if (new_state == Comms::State::RUNNING)
	{
		for (auto& infraction_rule : m_infraction_rules)
		{
			infraction_rule->SessionRunning();
		}
	}
	else if (new_state == Comms::State::PAUSED)
	{
		for (auto& infraction_rule : m_infraction_rules)
		{
			infraction_rule->SessionPaused();
		}
	}

}

void InfractionUnit::StateChanging(Comms::State new_state)
{
	const auto LOCK = m_tpw.Lock();
	std::lock_guard<std::recursive_mutex> lock(m_mutex);

	if (new_state == Comms::State::PROCESSING)
	{
		for (auto& infraction_rule : m_infraction_rules)
		{
			infraction_rule->SessionProcessing();
		}
	}
}

/// Gets the ID of an infraction rule. This is normally a combination of category and rule, but in
/// dealing with the InfractionUnit, it is simplified as the index of the rule.
///
/// @param rule_name  Name of the rule
///
/// @return ID of the rule for use with RecordInfraction

int InfractionUnit::GetRuleID(const std::string &rule_name)
{
    std::lock_guard<std::recursive_mutex> lock(m_mutex);

    std::vector<Scoring::Data::ScoringRule>::const_iterator rule
        = std::find_if(m_rules.begin(), m_rules.end(),
                       [&rule_name](Scoring::Data::ScoringRule &rule){ return rule.name == rule_name; });

    if (rule == m_rules.end())
    {
        throw CommonException(FLSTAMP, ("Rule '" + rule_name + "' unknown").c_str());
    }

    return rule->rule_id;
}

/// Gets the value of a parameter.
///
/// @note
///     Will throw a CommonException if the parameter is unknown
///
/// @param parameter_name  Name of the parameter
///
/// @return Value of the parameter

double InfractionUnit::GetParameter(const std::string &parameter_name)
{
    std::lock_guard<std::recursive_mutex> lock(m_mutex);

    std::vector<Scoring::Data::ScoringParameter>::const_iterator iter
        = std::find_if(m_parameters.begin(), m_parameters.end(),
                       [&parameter_name](Scoring::Data::ScoringParameter &parameter){ return parameter.name == parameter_name; });

    if (iter == m_parameters.end())
    {
        throw CommonException(FLSTAMP, ("Parameter '" + parameter_name + "' unknown").c_str());
    }

    return iter->si_value;
}

/// Records an infraction using the transaction data writer
///
/// @param rule_id   Infraction rule ID according to the Infraction Unit
/// @param penalty   number of penalty points incurred
/// @param duration  For ongoing infractions, this duration is the time the infraction was active.
///                  For instantaneous infractions, this duration is 0.

void InfractionUnit::RecordInfraction(int rule_id, double penalty, double duration, bool ignore_session_state)
{
    std::lock_guard<std::recursive_mutex> lock(m_mutex);

    if (!ignore_session_state && m_session_state != Comms::State::RUNNING)
    {
        return;
    }

    auto rule = std::find_if(m_rules.begin(), m_rules.end(), 
        [&rule_id] (const Scoring::Data::ScoringRule &rule) { return (rule.rule_id == rule_id); });
 
    if (rule == m_rules.end())
        throw CommonException(FLSTAMP, ("Rule ID '" + std::to_string(rule_id) + "' unknown").c_str());

    // Infractions not accepted after scenario has stopped
    if (!m_reached_stopped)
    {
        m_session_infraction.category_id  = rule->category_id;
        m_session_infraction.rule_id      = rule->rule_id;

        auto time_position = GetCurrentTimePosition();
        m_session_infraction.elapsed_time = time_position.time;
        m_session_infraction.position     = time_position.position / M_TO_KM;
        m_session_infraction.demerits     = penalty;

        Trace::g_plog->STAMP(Trace::INFO) << "INFRACTION: " << rule->name << ", demerits = " << penalty << Trace::EndLog();

        m_transaction_data_access.InsertSessionInfraction(m_session_infraction);

        // Autonumber infraction IDs
        ++m_session_infraction.infraction_id;
    }
}

/// Called when the route of the train's path changes. Concerned here about whether or not there
/// actually is a path. When this changes, infraction rules requiring a path are notified if this
/// changes whether their requirements are now all available.

void InfractionUnit::RouteChanged()
{
    assert(m_tpw.HasLock());
    std::lock_guard<std::recursive_mutex> lock(m_mutex);

    if (m_tpw.HasPath() != m_have_path)
    {
        m_have_path = m_tpw.HasPath();

        for (auto iter = m_property_requirement.lower_bound(PATH_PROPERTY_ID);
             iter != m_property_requirement.upper_bound(PATH_PROPERTY_ID);
             ++iter)
        {
            if (m_have_path)
            {
                if (--m_properties_still_required[iter->second.second.first] == 0)
                {
                    iter->second.second.first->SetRequiredAvailable(true);
                }
                // Can't call TP changed as it could be in construction still
            }
            else
            {
                if (m_properties_still_required[iter->second.second.first]++ == 0)
                {
                    iter->second.second.first->SetRequiredAvailable(false);
                }
            }
        }
    }
}

/// Called when a sim property changes. If it has been found or lost this affects whether the
/// requirements of infractions are satisfied. On change the infractions are notified if their
/// requirements are currently satisfied.
///
/// @param pn  Property just changed

void InfractionUnit::PropertyChanged(SimPropertyWatcher::PropertyNumber pn)
{
        const auto LOCK = m_tpw.Lock();
        std::lock_guard<std::recursive_mutex> lock(m_mutex);

        // TODO: We want to be able to filter these based on the vehicle we
        // are watching, which may not be the first vehicle. The test just below
        // will not work in that case, because feature IDs can coincide with
        // valid vehicle index numbers.

        if ((pn.group_id == SimPropertyWatcher::Group::TRAIN)
            || (pn.group_id == SimPropertyWatcher::Group::ENVIRONMENT)
            || (pn.group_id == SimPropertyWatcher::Group::CBTC_VEHICLE_INPUTS && pn.element == m_property_watcher.GetActiveCabVehicleIndex())
            || (pn.group_id == SimPropertyWatcher::Group::CBTC_VEHICLE_OUTPUTS && pn.element == m_property_watcher.GetActiveCabVehicleIndex())
            || (pn.group_id == SimPropertyWatcher::Group::CBTC_ONBOARD_INPUTS && pn.element == m_property_watcher.GetActiveCabVehicleIndex())
            || (pn.group_id == SimPropertyWatcher::Group::VEHICLE_AUDIO_OUTPUT && pn.element == m_property_watcher.GetActiveCabVehicleIndex())
            || (pn.group_id == SimPropertyWatcher::Group::CBTC_ONBOARD_OUTPUTS && pn.element == m_property_watcher.GetActiveCabVehicleIndex())
            || (pn.group_id == SimPropertyWatcher::Group::CBTC_PLATFORM_OUTPUTS && pn.element == m_property_watcher.GetActiveCabVehicleIndex())
            || (pn.group_id == SimPropertyWatcher::Group::TCMS_VEHICLE_OUTPUT && pn.element == m_property_watcher.GetActiveCabVehicleIndex())
            || (((pn.group_id == SimPropertyWatcher::Group::VEHICLE)
                || (pn.group_id == SimPropertyWatcher::Group::VEHICLE_INPUTS)
                || (pn.group_id == SimPropertyWatcher::Group::VEHICLE_OUTPUTS))
                && (pn.element == m_vehicle_index)))
        {

            for (auto iter = m_property_requirement.lower_bound(pn.property_id);
                iter != m_property_requirement.upper_bound(pn.property_id);
                ++iter)
            {
                if (pn.reason == SimPropertyWatcher::PropertyNumber::Found)
                {
                    if (--m_properties_still_required[iter->second.second.first] == 0)
                    {
                        {
                            // Notify helpers first
                            std::map<InfractionRule*, InterpretedTrainProperties*>::iterator iter2 = m_infraction_rule_train_properties.find(iter->second.second.first);
                            if (iter2 != m_infraction_rule_train_properties.end())
                            {
                                iter2->second->RequiredAvailable();
                            }
                        }

                        iter->second.second.first->SetRequiredAvailable(true);
                    }
                }
                else if (pn.reason == SimPropertyWatcher::PropertyNumber::Lost)
                {
                    if (m_properties_still_required[iter->second.second.first]++ == 0)
                    {
                        iter->second.second.first->SetRequiredAvailable(false);
                    }
                }
                else
                {
                    // Notify callbacks on change if all requirements are satisfied
                    if (m_properties_still_required[iter->second.second.first] == 0)
                    {
                        if (iter->second.second.second)
                        {
                            iter->second.second.second(pn.value);
                        }
                    }
                }

                if (iter->second.first)
                {
                    (*iter->second.first) = pn.value;
                }
            }
        }
}

/// Tells the unit that this rule requires the train to have a path.
///
/// @param prule  rule having this requirement.

void InfractionUnit::RequiresPath(InfractionRule *prule)
{
    std::lock_guard<std::recursive_mutex> lock(m_mutex);

    m_property_requirement.insert(make_pair(PATH_PROPERTY_ID, std::pair<Sim::Number::Type*, std::pair<InfractionRule *, PropertyCallback> >(0, std::pair<InfractionRule *, PropertyCallback>(prule, {}))));
    m_properties_still_required[prule]++;
}

/// Tells the unit that this rule requires a particular property
///
/// @param prule        rule heaving
/// @param group_id     Group the property belongs to
/// @param number_name  Name of the property
/// @param pnumber      A number that is updated when the property changes value, prior to change
///                     callbacks

void InfractionUnit::Requires(InfractionRule *prule, SimPropertyWatcher::Group group_id, const std::string &number_name, Sim::Number::Type *pnumber)
{
    std::lock_guard<std::recursive_mutex> lock(m_mutex);

    int property_id = m_property_watcher.GetPropertyID(group_id, number_name);

    m_properties_required.push_back(property_id);

    m_property_requirement.insert(make_pair(property_id, make_pair(pnumber, std::pair<InfractionRule *, PropertyCallback>(prule, {}))));
    m_properties_still_required[prule]++;
}

/// Tells the unit that this rule requires a particular property
///
/// @param prule        rule heaving
/// @param group_id     Group the property belongs to
/// @param number_name  Name of the property
/// @param pnumber      A number that is updated when the property changes value, prior to change
///                     callbacks
/// @param cb           A callback that is called when the property changes value, the number is
///                     updated when the callback returns.

void InfractionUnit::Requires(InfractionRule *prule, SimPropertyWatcher::Group group_id, const std::string &number_name, Sim::Number::Type *pnumber, PropertyCallback cb)
{
    std::lock_guard<std::recursive_mutex> lock(m_mutex);

    int property_id = m_property_watcher.GetPropertyID(group_id, number_name);

    m_properties_required.push_back(property_id);

    m_property_requirement.insert(std::make_pair(property_id, std::make_pair(pnumber, std::make_pair(prule, cb))));
    m_properties_still_required[prule]++;
}

/// Tells the unit that this rule requires a particular interpreted train property
///
/// @param prule        rule heaving
/// @param property_id  Interpreted train property ID
/// @param pnumber      A number that is updated when the property changes value, prior to change
///                     callbacks
/// @param cb           A callback that is called when the property changes value, the number is
///                     updated when the callback returns.

void InfractionUnit::RequiresInterpretedTrainProperty(InfractionRule *prule, int property_id, Sim::Number::Type *pnumber, PropertyCallback cb)
{
    std::lock_guard<std::recursive_mutex> lock(m_mutex);

    std::map<InfractionRule*, InterpretedTrainProperties*>::iterator iter = m_infraction_rule_train_properties.find(prule);
    if (iter == m_infraction_rule_train_properties.end())
    {
        iter = m_infraction_rule_train_properties.insert(std::make_pair(prule, Project::CreateInterpretedTrainProperties(this, prule, m_car_class).release())).first;
    }
    iter->second->Requires(property_id, pnumber, cb);
}

/// Starts a periodic system timer, which executes a callback. Its information is added into the
/// timer queue
///
/// @param period  Period of the timer
/// @param cb      callback to notify each cycle

void InfractionUnit::StartTimer(double period, const Callback<void, void> &cb)
{
    std::lock_guard<std::recursive_mutex> lock(m_mutex);

    assert(period > 0.0);

    TimerInfo next_timer_info;
    next_timer_info.interval  = period;
    next_timer_info.next_time = m_tpw.GetTime() + period;
    next_timer_info.pcb       = cb.Clone();

    m_timers.insert(lower_bound(m_timers.begin(), m_timers.end(), next_timer_info), next_timer_info);
}

/// Stops a periodic system timer. Its information is removed from the timer queue.
///
/// @param cb  callback being notified each cycle

void InfractionUnit::KillTimer(const Callback<void, void> &cb)
{
    std::lock_guard<std::recursive_mutex> lock(m_mutex);

    for (std::vector<TimerInfo>::iterator iter = m_timers.begin(); iter != m_timers.end(); ++iter)
    {
        if (*iter->pcb == cb)
        {
            delete iter->pcb;
            m_timers.erase(iter);
            break;
        }
    }
}

/// Called when the time or lead loco position changes. Based on the synchronized path watcher
/// time, calls all timers until all are waiting for a future time. Implementation allows the same
/// callback to be called multiple times. Each infraction rule is notified that the time/position
/// has changed if their requirements are satisfied.

void InfractionUnit::PositionChanged()
{
    std::lock_guard<std::recursive_mutex> lock(m_mutex);

    double t = m_tpw.GetTime();

    while (!m_timers.empty() && m_timers.front().next_time <= t)
    {
        // Pop off and erase
        TimerInfo next_timer_info = m_timers.front();
        m_timers.erase(m_timers.begin());

        // Reinsert if it has an interval
        if (next_timer_info.interval != 0.0)
        {
            next_timer_info.next_time += next_timer_info.interval;
            m_timers.insert(lower_bound(m_timers.begin(), m_timers.end(), next_timer_info), next_timer_info);

            // Engage callback (note this is allowed to kill the callback)
            Trace::g_plog->STAMP(Trace::VERBOSE) << "Calling timer (T=" << next_timer_info.interval << "), TP time = " << t << "module time = " << GetGateway().GetTiming().GetCurrentModuleTime() << Trace::EndLog();
            (*next_timer_info.pcb)();
        }
        else
        {
            (*next_timer_info.pcb)();
            delete next_timer_info.pcb;
        }
    }

    m_current_time_position.time = t;
    m_current_time_position.position = m_tpw.HasPath() ? m_tpw.GetPosition() : 0;

    // Callbacks are notified 
    for (auto& infraction_rule : m_infraction_rules)
    {
        if (m_properties_still_required[infraction_rule.get()] == 0)
        {
            infraction_rule->TimePositionChanged(m_current_time_position);
        }
    }
}
