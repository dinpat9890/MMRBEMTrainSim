///
/// @file       SATrainPathWatcherUnit.h
///
///             Declares the SATrainPathWatcherUnit unit that triggers a
///             a train path watcher to update its time regularly.
///
/// @ingroup    Integrated Scenarios, AC05-004
///
/// @author     James Errington
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2005
///

#ifndef SA_TRAIN_PATH_WATCHER_UNIT_H
#define SA_TRAIN_PATH_WATCHER_UNIT_H

#include "SATrainPathWatcher.h"

#include "sim_comms/Unit.h"

/// The SATrainPathWatcherUnit class triggers a a train path watcher to update its time regularly.

class SATrainPathWatcherUnit : public Comms::SteppingUnit
{
public:
    // Constructor
    SATrainPathWatcherUnit(Comms::Gateway &gateway, SATrainPathWatcher &watcher);
    ~SATrainPathWatcherUnit();

    std::string GetName() const override;

    double GetPeriod() const override;
    void   Step(double new_time) override;

private:
    // Just to be safe, mutex this
    std::mutex          m_mutex;
    SATrainPathWatcher &m_watcher;
};

#endif // SA_TRAIN_PATH_WATCHER_UNIT_H
