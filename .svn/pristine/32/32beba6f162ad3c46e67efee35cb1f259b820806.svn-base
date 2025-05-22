/// @file IsLeadVehicle.h
/// Free-standing function to check if an object represents the lead vehicle
/// on a train.
///
/// @author    Simon Wade (simon.wade@sydac.com.au)
/// @copyright © SYDAC Pty Ltd, 2016
#pragma once
#include "sim_comms/Object.h"
#include "train_comms_structure\TrainObjectConstants.h"

#include <cassert>
#include <cstring>

namespace Sim
{
    namespace Project
    {
        /// @brief Determines if an object represents a leading vehicle.
        ///
        /// @param vehicle_object The object to query.
        ///
        /// @return True if the object is the leading vehicle for a train, false
        ///         if it's anything else.
        static bool IsLeadVehicle(const Comms::Object &object)
        {
            // Some assumptions regarding consistency between simulated and
            // automatic trains...
            assert(strcmp(Train::ValueName::Vehicle::VEHICLE, Train::ValueName::AutoVehicle::VEHICLE) == 0);
            assert(strcmp(Train::ValueName::Vehicle::INDEX, Train::ValueName::AutoVehicle::INDEX) == 0);

            return object.IsValid() &&
                   object.Statics().Tags().Exists(Train::ValueName::Vehicle::VEHICLE) &&
                   object.Numbers().Info().GetID(Train::ValueName::Vehicle::INDEX) != Sim::INVALID_NUMBER &&
                   object.Numbers().Info().GetInfo(object.Numbers().Info().GetID(Train::ValueName::Vehicle::INDEX)).initial == 0;
        }
    }
}