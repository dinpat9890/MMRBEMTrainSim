//*****************************************************************************
//
//  File:           PISConstants.h
//
//  Description:    Defines a pile of constants that are used throughout the PIS applications.
//
//  Reference:      https://adl-atlassian.simulation.lan/confluence/display/BJSNA/PIS+-+Implementation
//
//  ingroup        Beijing PIS Unit
//
//  Author:        Yogesh Warad
//
//  copyright  (C) Copyright:  SYDAC Pty Ltd, 2017
//
//*****************************************************************************

#pragma once

#include <string>
#include <vector>

namespace pis
{
    struct DVAPlayCommand
    {
        std::string      title;        // Optional - For Debugging
        bool             loop;
        std::vector<int> audio_ids;
    };

    namespace DVACommandType
    {
        const int PLAY_MSG      = 1;
        const int STOP_MSG      = 2;
    }

    enum class ANNOUNCEMENT_MODE
    {
        AUTOMATIC_ANNOUCEMENT   = 1,
        SEMI_AUTOMATIC          = 2,
    };

    enum class ANNOUNCEMENT_TYPE
    {
        NONE                    = 0,
        STATION_ANNOUCEMENT     = 1,
        EMERGENCY_ANNOUCEMENT   = 2,
    };

    enum class TrainDirection
    {
        DOWN    = 0,
        UP      = 1,
    };
}
