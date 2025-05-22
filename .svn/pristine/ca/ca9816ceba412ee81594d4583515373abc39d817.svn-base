/*
 * ==================================================================
 * (C)Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * ==================================================================
 */
package com.sydac.mmrbem.tcms.backend.logic.handler;

import java.util.HashMap;
import java.util.Map;

import org.springframework.stereotype.Service;

import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.tcms.backend.comms.CommsBinding;
import com.sydac.mmrbem.tcms.backend.logic.AbstractFunctionalLogic;
import com.sydac.mmrbem.tcms.backend.logic.annotation.FunctionalLogicHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.io.properties.ITCMSVehicleOutputsSpeedLimitInterlockScreenProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsSpeedLimitInterlockScreenProperties;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto;
import com.sydac.mmrbem.tcms.common.state.TCMSConstants;

/**
 * This handler class is used for handling Speed Limit Interlock Screen data
 * 
 */
@Service
@FunctionalLogicHandler(arguments = { CommsBinding.class })
public class SpeedLimitInterlockScreenHandler extends AbstractFunctionalLogic
{
  private Map<Integer, Integer> speedLimitMap = new HashMap<>();

  protected SpeedLimitInterlockScreenHandler(CommsBinding commsBinding)
  {
    super(commsBinding, ITCMSVehicleOutputsSpeedLimitInterlockScreenProperties.class);
  }

  @Override
  public <T> void tcmsVehicleOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue,
      int vehicleIndex)
  {
    if (ITCMSVehicleOutputsSpeedLimitInterlockScreenProperties.SPEED_LIMIT_AS_CUTOUT.equals(key))
    {
      updateSpeedLimitStatus(TCMSConstants.SPEED_LIMIT_MAP_ID_1, (Integer)newValue);
    }
    else if (ITCMSVehicleOutputsSpeedLimitInterlockScreenProperties.SPEED_LIMIT_BOGIE_ISOLATED.equals(key))
    {
      updateSpeedLimitStatus(TCMSConstants.SPEED_LIMIT_MAP_ID_2, (Integer)newValue);
    }
    else if (ITCMSVehicleOutputsSpeedLimitInterlockScreenProperties.SPEED_LIMIT_EPIC_CUTOUT.equals(key))
    {
      updateSpeedLimitStatus(TCMSConstants.SPEED_LIMIT_MAP_ID_3, (Integer)newValue);
    }
    else if (ITCMSVehicleOutputsSpeedLimitInterlockScreenProperties.SPEED_LIMIT_RPRESS_ISOLATED.equals(key))
    {
      updateSpeedLimitStatus(TCMSConstants.SPEED_LIMIT_MAP_ID_4, (Integer)newValue);
    }
    else if (ITCMSVehicleOutputsSpeedLimitInterlockScreenProperties.SPEED_LIMIT_SCS_MODE.equals(key))
    {
      updateSpeedLimitStatus(TCMSConstants.SPEED_LIMIT_MAP_ID_5, (Integer)newValue);
    }
    else if (ITCMSVehicleOutputsSpeedLimitInterlockScreenProperties.SPEED_LIMIT_JOG_MODE.equals(key))
    {
      updateSpeedLimitStatus(TCMSConstants.SPEED_LIMIT_MAP_ID_6, (Integer)newValue);
    }
    else if (ITCMSVehicleOutputsSpeedLimitInterlockScreenProperties.SPEED_LIMIT_LOW_SPEED_CUTOUT_MODE
        .equals(key))
    {
      updateSpeedLimitStatus(TCMSConstants.SPEED_LIMIT_MAP_ID_7, (Integer)newValue);
    }
    else if (ITCMSVehicleOutputsSpeedLimitInterlockScreenProperties.SPEED_LIMIT_EXCESSIVE_SLIP.equals(key))
    {
      updateSpeedLimitStatus(TCMSConstants.SPEED_LIMIT_MAP_ID_8, (Integer)newValue);
    }
    else if (ITCMSVehicleOutputsSpeedLimitInterlockScreenProperties.SPEED_LIMIT_NO_ED_AVAILABLE.equals(key))
    {
      updateSpeedLimitStatus(TCMSConstants.SPEED_LIMIT_MAP_ID_9, (Integer)newValue);
    }
    else if (ITCMSVehicleOutputsSpeedLimitInterlockScreenProperties.SPEED_LIMIT_BRAKE_FAILURE.equals(key))
    {
      updateSpeedLimitStatus(TCMSConstants.SPEED_LIMIT_MAP_ID_10, (Integer)newValue);
    }
    else if (ITCMSVehicleOutputsSpeedLimitInterlockScreenProperties.SPEED_LIMIT_OVERRIDE_TRACTION_BLOCK
        .equals(key))
    {
      updateSpeedLimitStatus(TCMSConstants.SPEED_LIMIT_MAP_ID_11, (Integer)newValue);
    }
    else if (ITCMSVehicleOutputsSpeedLimitInterlockScreenProperties.SPEED_LIMIT_AS_DEFLATED.equals(key))
    {
      updateSpeedLimitStatus(TCMSConstants.SPEED_LIMIT_MAP_ID_12, (Integer)newValue);
    }

  }

  private void updateSpeedLimitStatus(int id, int value)
  {
    speedLimitMap.put(id, value);
    TCMSProto.SpeedLimitData.Builder builder = TCMSProto.SpeedLimitData.newBuilder();
    TCMSProto.SpeedLimitData.SpeedLimitDataStatus.Builder countersBuilder = TCMSProto.SpeedLimitData.SpeedLimitDataStatus
        .newBuilder();
    for (Map.Entry<Integer, Integer> entry : speedLimitMap.entrySet())
    {
      countersBuilder.setLimitId(entry.getKey());
      countersBuilder.setSpeedLimitState(entry.getValue());
      builder.addSpeedLimitDataStatus(countersBuilder);
    }
    setApplicationOutputsProperty(IAppOutputsSpeedLimitInterlockScreenProperties.SPEED_LIMIT_STATUS,
        builder.build().toByteArray());
  }
}
