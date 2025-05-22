///
/// @file       LocomotiveTrainProperties.cpp
///
///             Defines a class for interpreting locomotive properties
///
/// @ingroup    Sydac Freight Train Simulator
///
/// @author     James Errington (modified by Dijon Page) (file, class name renamed by Raghu Gandi)
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2018
///

#include "LocomotiveTrainProperties.h"

/// Constructor. Initializes values to zero.

LocomotiveTrainProperties::LocomotiveTrainProperties(InfractionUnit *punit, InfractionRule *prule)
    : InterpretedTrainProperties(punit, prule)
{
    m_throttle_control = 0.0;
    m_automatic_brake_control.value = 0.0;
    m_direction_control_lever.value = 0.0;
    m_horn_control.value = 0.0;
}

/// Calls InterpreterRequires on each real property required for this particular property.
///
/// @param property  property required

void LocomotiveTrainProperties::UserRequires(int property)
{
    if (property == InterpretedValues::THROTTLE_POSITION)
    {
        InterpreterRequires(
            SimPropertyWatcher::Group::VEHICLE_INPUTS,
            "Throttle Position",
            &m_throttle_control,
            [this](auto x)
            {
                m_throttle_control = x;
                SetProperty(InterpretedValues::THROTTLE_POSITION, m_throttle_control);
            });
    }

    //if (property == InterpretedValues::THROTTLE_POSITION)
    //    InterpreterRequires(SimPropertyWatcher::OBJECT_VEHICLE_INPUTS, Freight::ValueName::VehicleInputs::POWER_THROTTLE_HANDLE, &m_throttle_control, MakeCallback(&LocomotiveTrainProperties::NumberChanged, this));
    //if (property == InterpretedValues::AUTOMATIC_BRAKE || property == InterpretedValues::IS_IN_EMERGENCY)
    //    InterpreterRequires(SimPropertyWatcher::OBJECT_VEHICLE_INPUTS, Freight::ValueName::VehicleInputs::AUTO_BRAKE_HANDLE, &m_automatic_brake_control, MakeCallback(&LocomotiveTrainProperties::NumberChanged, this));
    //if (property == InterpretedValues::DIRECTION_CONTROL)
    //    InterpreterRequires(SimPropertyWatcher::OBJECT_VEHICLE_INPUTS, Freight::ValueName::VehicleInputs::REVERSER_HANDLE, &m_direction_control_lever, MakeCallback(&LocomotiveTrainProperties::NumberChanged, this));
    //if (property == InterpretedValues::HORN)
    //{
    //    InterpreterRequires(SimPropertyWatcher::OBJECT_VEHICLE, Freight::ValueName::Vehicle::COUNTRY_HORN_USED,
    //        &m_horn_control, MakeCallback(&LocomotiveTrainProperties::NumberChanged, this));
    //    InterpreterRequires(SimPropertyWatcher::OBJECT_VEHICLE, Freight::ValueName::Vehicle::TOWN_HORN_USED,
    //        &m_horn_control, MakeCallback(&LocomotiveTrainProperties::NumberChanged, this));
    //}
}

/// Sets all interpreted properties to their calculated values.
///
/// @param property  property required

void LocomotiveTrainProperties::RequiredAvailable()
{
    // If a property is not requested, its value will be rubbish, but it is unused so that would be okay
    SetProperty(InterpretedValues::THROTTLE_POSITION, m_throttle_control);
    SetProperty(InterpretedValues::AUTOMATIC_BRAKE, m_automatic_brake_control.value);
    SetProperty(InterpretedValues::IS_IN_EMERGENCY, ((m_automatic_brake_control.value == 120.0) ? 1.0 : 0.0));
    SetProperty(InterpretedValues::HORN, m_horn_control.value);
    SetProperty(InterpretedValues::DIRECTION_CONTROL, m_direction_control_lever.value);
}
