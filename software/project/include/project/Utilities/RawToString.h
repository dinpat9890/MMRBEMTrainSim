/// @file RawToString.h
/// Free-standing function to convert the contents of a Raw to a std::string.
///
/// @author    Simon Wade (simon.wade@sydac.com.au)
/// @copyright © SYDAC Pty Ltd, 2016
#pragma once
#include "sim_common/DataTypes.h"
#include <string>

namespace Comms
{
    namespace Project
    {
        static inline std::string RawToString(const Sim::Raw &raw)
        {
            return std::string(raw.value.cbegin(), raw.value.cend());
        }
    }
}
