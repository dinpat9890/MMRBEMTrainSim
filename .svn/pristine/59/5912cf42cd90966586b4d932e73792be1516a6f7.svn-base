//*****************************************************************************
//
//  File:           CommsPISData.h
//
//  Description:    This is the concrete class  whose purpose is to retrieve values of properties updated by comms
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

#include "IPISData.h"
#include "sim_comms/Gateway.h"
#include <vector>

namespace pis
{

    class CommsPISData : public IPISData
    {
    public:
        explicit CommsPISData(Comms::Object object);

    private:
        // Inherited via IPISData
        virtual void SetDirection(TrainDirection direction) override;
        virtual void SetNextStationId(int id) override;
        virtual void SetDvaMute(bool mute) override;
        virtual void SetDvaStop(bool stop) override;
        virtual void SendPlayDvaCommand(pis::DVAPlayCommand cmd) override;
        virtual void SendStopDvaCommand() override;

    private:
        Comms::Object m_object;

        Sim::Number::ID m_direction_number_id;
        Sim::Number::ID m_next_station_number_id;
        Sim::Number::ID m_dva_mute_number_id;
        Sim::Number::ID m_dva_stop_number_id;
        Sim::Tray::ID   m_dva_tray_id;

        std::map<uint8_t, Sim::Number::ID> m_dva_command_queue_id_map; // VehicleID, DVA command queue id sim number
        std::map<uint8_t, Comms::Object>   m_pis_outputs_object_map;   // VehicleID, PISObject
        std::vector<Comms::Object>         m_platform_stopping_feature_vec;
        std::vector<Sim::Message>          m_dva_messages;
    };

}
