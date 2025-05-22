#pragma once
#include <map>
#include "DVAAudioConfigHandler.h"
class IXMLHandler
{
public:
    virtual PIS::Message GetEmergencyMessageData(int emergency_id)=0;
    virtual PIS::Message GetOCCMessageData(int occ_id)=0;
    virtual PIS::StationData GetStationData(int stationID)=0;
};

