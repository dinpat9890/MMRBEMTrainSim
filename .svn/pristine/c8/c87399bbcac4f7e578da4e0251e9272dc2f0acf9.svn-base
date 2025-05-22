///
/// @file       InterpretedTrainProperties.cpp
///
///             Defines the base class for properties that have a standard
///             definition, but based on the actual properties of a train
///
/// @ingroup    Scot Rail Simulators, AC06-007
///
/// @author     James Errington
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2006
///

#include "InterpretedTrainProperties.h"
#include "SessionAnalyserUnits/InfractionUnit.h"

/// Constructor. Does nothing.

InterpretedTrainProperties::InterpretedTrainProperties(InfractionUnit *punit, InfractionRule *prule)
    : m_punit(punit)
    , m_prule(prule)
{
}

/// Destructor. Deletes all callbacks.

InterpretedTrainProperties::~InterpretedTrainProperties()
{
}

/// Tells the train property interpreter that this rule requires a particular interpreted property
///
/// @param property  interpreted property required
/// @param pnumber   A number that is updated when the property changes value, prior to change
///                  callbacks
/// @param cb        A callback that is called when the property changes value, the number is
///                  updated when the callback returns.

void InterpretedTrainProperties::Requires(int property, Sim::Number::Type *pnumber, std::function<void (Sim::Number::Type)> cb)
{
    m_infraction_properties.insert(std::make_pair(property, std::make_pair(pnumber, cb)));
    UserRequires(property);
}

/// Tells the unit that this interpreter requires a particular property
///
/// @param group_id     Group the property belongs to
/// @param number_name  Name of the property
/// @param pnumber      A number that is updated when the property changes value, prior to change
///                     callbacks
/// @param cb           A callback that is called when the property changes value, the number is
///                     updated when the callback returns.

void InterpretedTrainProperties::InterpreterRequires(SimPropertyWatcher::Group group_id, const std::string &number_name, Sim::Number::Type *pnumber, std::function<void (Sim::Number::Type)> cb)
{
    m_punit->Requires(m_prule, group_id, number_name, pnumber, cb);
}

/// Sets a property's value by calling all of the callbacks registered on it.
///
/// @param property  interpreted property
/// @param value     the property's value, to be supplied to callbacks.

void InterpretedTrainProperties::SetProperty(int property, double value)
{
    auto iter = m_infraction_properties.lower_bound(property);
    for (; iter != m_infraction_properties.upper_bound(property); ++iter)
    {
        if(const auto &callback =iter->second.second)
            callback(value);

        if (iter->second.first != 0)
        {
            (*iter->second.first) = value;
        }
    }
}


/// Empty implementation.
///
/// @param property  property required

void InterpretedTrainProperties::UserRequires(int property)
{
}
