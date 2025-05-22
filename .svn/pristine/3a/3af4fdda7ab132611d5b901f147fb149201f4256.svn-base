///
/// @file       InterpretedTrainProperties.h
///
///             Declares the base class for properties that have a standard
///             definition, but based on the actual properties of a train
///
/// @ingroup    Scot Rail Simulators, AC06-007
///
/// @author     James Errington
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2006
///

#ifndef INTERPRETED_TRAIN_PROPERTIES_H
#define INTERPRETED_TRAIN_PROPERTIES_H

#include "InfractionRule.h"
#include "SimPropertyWatcher.h"

namespace InterpretedValues
{
    const int THROTTLE_POSITION = 1;
    const int AUTOMATIC_BRAKE   = 2;
    const int IS_IN_EMERGENCY   = 3;
    const int DIRECTION_CONTROL = 4;
    const int HORN              = 5;
}

/// Base class for properties that have a standard definition, but based on the actual properties
/// of a train

class InterpretedTrainProperties
{
public:
    InterpretedTrainProperties(class InfractionUnit *punit, class InfractionRule *prule);
    virtual ~InterpretedTrainProperties();

    using NumberCallbackType = std::function<void (Sim::Number::Type)>;

    void Requires(int property, Sim::Number::Type *pnumber, NumberCallbackType cb);
    virtual void RequiredAvailable() = 0;

protected:
    virtual void UserRequires(int property) = 0;

    void InterpreterRequires(SimPropertyWatcher::Group group_id, const std::string &number_name, Sim::Number::Type *pnumber, NumberCallbackType cb);

    void SetProperty(int property, double value);

private:
    InfractionUnit *m_punit;
    InfractionRule *m_prule;

    std::multimap<int, std::pair<Sim::Number::Type *, NumberCallbackType> > m_infraction_properties;
};

#endif //INTERPRETED_TRAIN_PROPERTIES_H
