//******************************************************************************
//
//  File:           PlatformPassengersUnit.h
//
//  Description:    Declares the PlatformPassengersUnit class.
//
//  Reference:      Chiltern Train Sim
//
//  Author:         Luke Errington
//
//  (C) Copyright:  SYDAC Pty Ltd, 2006
//
//******************************************************************************

#ifndef PLATFORM_PASSENGERS_UNIT_H
#define PLATFORM_PASSENGERS_UNIT_H

#include "PlatformPassengersProperties.h"

#include "Utility/Locking.h"
#include "world_api/TrainPathWatcher.h"

#include "sim_comms/Unit.h"
#include <map>
#include <set>

//  Class:          PlatformPassengersUnit
//
//  Description:    This unit is responsible for creating the objects holding
//                  animation state underneath all feature objects that are
//                  platform passengers. It is also responsible for adjusting
//                  these states as trains approach, passengers board, and
//                  trains leave station. Some addition functionality involves
//                  tracking these trains and opening their doors when
//                  appropriate (when they are parked at a station with
//                  passengers).

class PlatformPassengersUnit : public Comms::SteppingUnit, public Core::Locking<>
{
public:
    // Constructor and destructor
    PlatformPassengersUnit(Comms::Gateway &gateway, Common::Data::DataAccess &data_access, WorldAPI::WorldAccess &world_access, const PlatformPassengerProperties &properties);
    ~PlatformPassengersUnit();

    std::string GetName() const override { return "Platform Passengers Unit"; }

    void   Step(double new_time) override;
    double GetPeriod() const override;

private:
    void ObjectCreated(Comms::Object object);

    // Break out the destruction callbacks
    void PlatformDestroyed(Comms::Object object);
    void AnimationStateDestroyed(Comms::Object object);

private:
    // Store our world access for when we create train path watchers
    WorldAPI::WorldAccess &m_world_access;

    // Store the properties for use within RunCycle
    PlatformPassengerProperties m_properties;

    // We need a points watcher to create train path watchers too
    WorldAPI::PointsWatcher m_points_watcher;

    // Store the feature type IDs that we are interested in.
    int m_passengers_type_id;
    int m_platform_type_id;

    // Feature Type IDs for platform screen doors.
    std::set<int> m_platform_screen_doors_type_ids;

    // Maps from a Platform Feature ID to a boolean that is
    // true if the associated screen doors are open.
    std::map<int, bool> m_platform_feature_id_to_screen_doors_open;

    // We don't really want to store state across cycles - we just need some
    // objects that will ensure we have current information to work with.
    std::vector<WorldAPI::TrainPathWatcher *> m_trains;
    std::map<int, double>                     m_train_lengths;
    std::map<int, bool>                       m_stopped;

    // Track all of the platform features
    std::vector<Comms::Object> m_platforms;

    // The last number of platforms we saw
    int m_num_platforms;

    // Track all of our platform passenger animation state objects
    std::vector<Comms::Object> m_animation_states;
};

#endif // PLATFORM_PASSENGERS_UNIT_H
