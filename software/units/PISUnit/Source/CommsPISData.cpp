//*****************************************************************************
//
//  File:           CommsPISData.cpp
//
//  Description:    This is the concrete class  whose purpose is to retrieve values of properties updated by comms
//  callback.
//
//  ingroup         PIS Unit
//
//  Author:         Nand Kumar Sharma
//
//  copyright  (C) Copyright:  SYDAC Pty Ltd, 2020
//
//*****************************************************************************

#include "CommsPISData.h"

#include "source/protobuf/PISprotos.pb.h"

#include "project_comms_structure/ProjectObjectConstants.h"

#include "Common/StandardLogging.h"

namespace
{
    ///  @Function:       EncodeDVAPlayCommand
    ///
    ///  @Description:    Serializes a DVAPlayCommand from an array of bytes.
    ///
    ///  @Param:          play_command Object.
    ///
    ///  @Return:         std::vector dva_playlist.ByteSize -
    ///                   The array of bytes.

    std::vector<unsigned char> EncodeDVAPlayCommand(pis::DVAPlayCommand& play_command)
    {
        dva::DvaPlayList dva_playlist;

        dva_playlist.set_loop(play_command.loop);
        dva_playlist.set_pid_text(play_command.title);

        for (auto audio_id : play_command.audio_ids)
        {
            dva_playlist.add_message_ids(audio_id);
        }

        std::vector<unsigned char> ret(dva_playlist.ByteSize());
        if (!dva_playlist.SerializeToArray(&ret[0], ret.size()))
            Trace::GetLogger().STAMP(Trace::VERBOSE) << "Playlist serialization failed" << Trace::EndLog();
        return ret;
    }
}

namespace pis
{
    CommsPISData::CommsPISData(Comms::Object object) : m_object(object)
    {
        m_direction_number_id = m_object.Numbers().Info().GetID(Project::ValueName::PISOutputs::DIRECTION);
        m_next_station_number_id = m_object.Numbers().Info().GetID(Project::ValueName::PISOutputs::NEXT_STATION_ID);
        m_dva_mute_number_id = m_object.Numbers().Info().GetID(Project::ValueName::PISOutputs::DVA_MUTE);
        m_dva_stop_number_id = m_object.Numbers().Info().GetID(Project::ValueName::PISOutputs::DVA_STOP);
        m_dva_tray_id = m_object.Trays().Info().GetID(Project::ValueName::PISOutputs::DVA_COMMAND_QUEUE);
    }

    void CommsPISData::SetDirection(TrainDirection direction)
    {
        m_object.Numbers().Store().Set(Sim::Number(static_cast<int>(direction), m_direction_number_id));
    }

    void CommsPISData::SetNextStationId(int id)
    {
        m_object.Numbers().Store().Set(Sim::Number(id, m_next_station_number_id));
    }

    void CommsPISData::SetDvaMute(bool mute)
    {
        m_object.Numbers().Store().Set(Sim::Number(mute, m_dva_mute_number_id));
    }

    void CommsPISData::SetDvaStop(bool stop)
    {
        m_object.Numbers().Store().Set(Sim::Number(stop, m_dva_stop_number_id));
    }

    void CommsPISData::SendPlayDvaCommand(pis::DVAPlayCommand cmd)
    {
        Sim::Message msg;
        msg.type = pis::DVACommandType::PLAY_MSG;
        msg.id   = 0;
        msg.data = EncodeDVAPlayCommand(cmd);

        m_object.Trays().Store().Send(m_dva_tray_id, msg);
    }

    void CommsPISData::SendStopDvaCommand()
    {
        Sim::Message msg;
        msg.type = pis::DVACommandType::STOP_MSG;
        msg.id   = 0;

        m_object.Trays().Store().Send(m_dva_tray_id, msg);
    }
}
