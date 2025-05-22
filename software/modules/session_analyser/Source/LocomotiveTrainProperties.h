///
/// @file       LocomotiveTrainProperties.h
///
///             Declares a class for interpreting locomotive properties
///
/// @ingroup    Sydac Freight Train Simulator
///
/// @author     James Errington (modified by Dijon Page) (file, class name renamed by Raghu Gandi)
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2018
///

#ifndef Locomotive_TRAIN_PROPERTIES_H
#define Locomotive_TRAIN_PROPERTIES_H

#include "SessionAnalyserUnits/InterpretedTrainProperties.h"

/// Class for interpreting locomotive properties

class LocomotiveTrainProperties : public InterpretedTrainProperties
{
public:
    LocomotiveTrainProperties(class InfractionUnit *punit, InfractionRule *prule);

    void UserRequires(int property) override;
    void RequiredAvailable() override;

private:
    double m_throttle_control;
    Sim::Number m_automatic_brake_control;
    Sim::Number m_direction_control_lever;
    Sim::Number m_horn_control;
};

#endif //Locomotive_TRAIN_PROPERTIES_H
