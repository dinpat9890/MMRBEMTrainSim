///
/// @file       SATrainPathWatcherUnit.cpp
///
///             Defines the SATrainPathWatcher Unit unit, who manages the world's
///             environmental conditions.
///
/// @ingroup    Integrated Scenarios, AC05-004
///
/// @author     James Errington
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2005
///

#include "SATrainPathWatcherUnit.h"

namespace
{
    const double CYCLE_FREQUENCY = 20.0;
}

/// Returns a string describing this unit.

std::string SATrainPathWatcherUnit::GetName() const
{
    return "SATrainPathWatcher Unit";
}

double SATrainPathWatcherUnit::GetPeriod() const
{
    return 1.0 / CYCLE_FREQUENCY;
}

/// Constructor. Does nothing.
///
/// @param gateway  The gateway to use.

SATrainPathWatcherUnit::SATrainPathWatcherUnit(Comms::Gateway &gateway, SATrainPathWatcher &watcher)
: Comms::SteppingUnit(gateway), m_watcher(watcher)
{
}

/// Triggers the path watcher.

void SATrainPathWatcherUnit::Step(double new_time)
{
    // Just to be safe
    std::lock_guard<std::mutex> mutex_lock(m_mutex);
    const OS::Lock<Comms::Gateway> LOCK(GetGateway());
    m_watcher.NextPeriod();
}

/// Destructor. Does nothing.

SATrainPathWatcherUnit::~SATrainPathWatcherUnit()
{
}
