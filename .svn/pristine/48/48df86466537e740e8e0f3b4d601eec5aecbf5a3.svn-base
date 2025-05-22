/// @file StringToRaw.h
/// Free-standing function to convert a std::string to a Raw.
///
/// @author    Simon Wade (simon.wade@sydac.com.au)
/// @copyright © SYDAC Pty Ltd, 2016
#pragma once
#include "SimCommon/DataTypes.h"
#include <string>

namespace Comms
{
    namespace Project
    {
        static inline Sim::Raw::Type StringToRaw(const std::string &s)
        {
            return Sim::Raw::Type(s.cbegin(), s.cend());
        }
    }
}
