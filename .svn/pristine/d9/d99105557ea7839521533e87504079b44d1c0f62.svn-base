//*****************************************************************************
//
//  File:           IPISData.h
//
//  Description:    This is the interface class  whose purpose is to retrieve values of properties updated by comms
//  callback.
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

#include "PISConstants.h"

#include <sim_common/DataTypes.h>

namespace pis
{

    class IPISData
    {
    public:
        virtual ~IPISData() {}

        virtual void SetDirection(TrainDirection direction) = 0;
        virtual void SetNextStationId(int id)               = 0;
        virtual void SetDvaMute(bool mute)                  = 0;
        virtual void SetDvaStop(bool stop)                  = 0;

        // DVA commands

        virtual void SendPlayDvaCommand(pis::DVAPlayCommand cmd) = 0;
        virtual void SendStopDvaCommand()                        = 0;
    };

}
