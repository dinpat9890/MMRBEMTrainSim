//**************************************************************************************************
//
//  File:           MotionBaseParameters.cpp
//
//  Description:    Data from the model to be sent to the motion base controller
//
//  Reference:      KSRTC
//
//  Author:         Peter Byrne
//
//  (C) Copyright:  SYDAC Pty Ltd, 2018
//
//**************************************************************************************************

#include "MotionBaseParameters.h"

/// TODO - this is VC++ specific, but MSVC 2012 doesn't support std::isfinite.
/// Make this platform independent
#include <cfloat>
#define _IS_FINITE(d)       _finite(d)


/// Checks the parameters for the command are valid
///
/// TODO - this check isn't very strong, what other checks should we be making?
/// For example, checking the ranges of the values.
bool MotionBase::Parameters::Validate() const
{
    return
        _IS_FINITE(GetVehicleVelocityX()) &&
        _IS_FINITE(GetVehicleVelocityY()) &&
        _IS_FINITE(GetVehicleVelocityZ()) &&
        _IS_FINITE(GetVehicleAccelerationX()) &&
        _IS_FINITE(GetVehicleAccelerationY()) &&
        _IS_FINITE(GetVehicleAccelerationZ()) &&
        _IS_FINITE(GetRotationMatrix11()) &&
        _IS_FINITE(GetRotationMatrix12()) &&
        _IS_FINITE(GetRotationMatrix13()) &&
        _IS_FINITE(GetRotationMatrix21()) &&
        _IS_FINITE(GetRotationMatrix22()) &&
        _IS_FINITE(GetRotationMatrix23()) &&
        _IS_FINITE(GetRotationMatrix31()) &&
        _IS_FINITE(GetRotationMatrix32()) &&
        _IS_FINITE(GetRotationMatrix33()) &&
        _IS_FINITE(GetVehicleAngularVelocityX()) &&
        _IS_FINITE(GetVehicleAngularVelocityY()) &&
        _IS_FINITE(GetVehicleAngularVelocityZ()) &&
        _IS_FINITE(GetVehicleAngularAccelerationX()) &&
        _IS_FINITE(GetVehicleAngularAccelerationY()) &&
        _IS_FINITE(GetVehicleAngularAccelerationZ()) &&
        _IS_FINITE(GetSimulatorPlatformManualPositionX()) &&
        _IS_FINITE(GetSimulatorPlatformManualPositionY()) &&
        _IS_FINITE(GetSimulatorPlatformManualPositionZ()) &&
        _IS_FINITE(GetSimulatorPlatformManualOrientationYaw()) &&
        _IS_FINITE(GetSimulatorPlatformManualOrientationPitch()) &&
        _IS_FINITE(GetSimulatorPlatformManualOrientationRoll()) &&
        _IS_FINITE(GetVehicleGravityAccelerationProjectionX()) &&
        _IS_FINITE(GetVehicleGravityAccelerationProjectionY()) &&
        _IS_FINITE(GetVehicleGravityAccelerationProjectionZ());
}