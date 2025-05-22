///
/// @file       MotionBaseData.h
///
///             Declares the MotionBaseData class. Currently this is a hard coded solution
///             We could make this more generic
///
/// @ingroup    MTM Train Sim
///
/// @author     Andy Cooper
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2013
///
#pragma once
#include "MotionBaseParameters.h"
#include <vector>

/// @return True if the parameters are okay to use.
extern bool MotionBaseParametersAreOkay(const MotionBase::Parameters &parameters);

/// @return Data buffer to send to the motion base.
/// @pre MotionBaseParametersAreOkay() returns true for the parameters argument.
extern std::vector<unsigned char> CreateMotionBaseBuffer(const MotionBase::Parameters &parameters);

/// @return Data buffer to send to a Gen III motion base.
/// @pre MotionBaseParametersAreOkay() returns true for the parameters argument.
extern std::vector<unsigned char> CreateGenIIIMotionBaseBuffer(const MotionBase::Parameters &parameters);