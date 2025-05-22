/*
 * ==================================================================
 * (C)Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * ==================================================================
 */
package com.sydac.mmrbem.tcms.backend.vehicle.request.handler;

import java.util.ArrayList;
import java.util.List;
import java.util.function.Consumer;

import com.sydac.common.log.Tracer;
import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.tcms.backend.app.io.handlers.IAppOutputsBrakeScreenHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.io.properties.ITCMSVehicleOutputsBrakeSystemProperties;
import com.sydac.mmrbem.tcms.common.data.Entry;
import com.sydac.mmrbem.tcms.common.data.VehicleDetailModel;
import com.sydac.mmrbem.tcms.common.data.VehicleEmergencyBrakeStatusDO;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.EmergencyBrakeLineStatusList.EmergencyBrakeLineState;
import com.sydac.mmrbem.tcms.common.state.TCMSConstants;

/**
 * This class handles Emergency brake line status update from vehicle outputs
 * 
 */
public class EmergencyBrakeLineStatusVehicleOutputRequestHandler implements
    ITCMSVehicleOutputsRequestHandler<TCMSOutputsBrakeSystemScreenImpl<Integer, IAppOutputsBrakeScreenHandler>>
{

  protected final List<Entry<VehicleEmergencyBrakeStatusDO>> ebStatusList = new ArrayList<>();

  @Override
  public void handleRequest(TCMSOutputsBrakeSystemScreenImpl<Integer, IAppOutputsBrakeScreenHandler> request)
  {
    try
    {
      VehicleEmergencyBrakeStatusDO vehicleEmergencyBrakeStatusDO = ITCMSVehicleOutputsRequestHandler
          .getVehicleStatusDo(ebStatusList, request.getCarIndex(), VehicleEmergencyBrakeStatusDO.class);
      setStatus(request.getPropertyKey(), request.getNewValue(), vehicleEmergencyBrakeStatusDO);
      ITCMSVehicleOutputsRequestHandler.updateVehicleStatusDOList(ebStatusList, vehicleEmergencyBrakeStatusDO,
          request.getCarIndex());
      setEbStatus(ebStatusList, request.getVehicleDetailModelList(),
          builder -> request.getHandler().setEmergencyBrakelineStatus(builder.build().toByteArray()));
    }
    catch (InstantiationException e)
    {
      Tracer.getInstance().info(e);
    }
  }

  protected void setStatus(PropertyKey<Integer> propertyKey, Integer newvalue,
      VehicleEmergencyBrakeStatusDO vehicleEmergencyBrakeStatusDO)
  {
    if (propertyKey.equals(ITCMSVehicleOutputsBrakeSystemProperties.EB_1_LINE_STATUS))
    {
      vehicleEmergencyBrakeStatusDO.setEb1Energized(newvalue);
    }
    else if (propertyKey.equals(ITCMSVehicleOutputsBrakeSystemProperties.EB_2_LINE_STATUS))
    {
      vehicleEmergencyBrakeStatusDO.setEb2Energized(newvalue);
    }
  }

  protected void setEbStatus(List<Entry<VehicleEmergencyBrakeStatusDO>> ebStatusList,
      List<VehicleDetailModel> vehicleDetailModelList,
      Consumer<TCMSProto.EmergencyBrakeLineStatusList.Builder> builderConsumer)
  {
    TCMSProto.EmergencyBrakeLineStatusList.Builder builder = TCMSProto.EmergencyBrakeLineStatusList
        .newBuilder();
    TCMSProto.EmergencyBrakeLineStatusList.EmergencyBrakeLineStatus.Builder vehicleBuilder = TCMSProto.EmergencyBrakeLineStatusList.EmergencyBrakeLineStatus
        .newBuilder();

    VehicleEmergencyBrakeStatusDO data;
    for (int index = 0; index < ebStatusList.size(); index++)
    {
      int carIndex = ebStatusList.get(index).getIndex();
      EmergencyBrakeLineState emergencyBrakeLineState1 = EmergencyBrakeLineState.EB_LINE_UNKNOWN;
      EmergencyBrakeLineState emergencyBrakeLineState2 = EmergencyBrakeLineState.EB_LINE_UNKNOWN;

      if (vehicleDetailModelList != null && vehicleDetailModelList.size() > carIndex)
      {
        String carClassCode = vehicleDetailModelList.get(carIndex).getCarClassCode();
        if (TCMSConstants.DM_CAR.equals(carClassCode))
        {
          data = ebStatusList.get(index).getData();
          emergencyBrakeLineState1 = getEbState1(data);
          emergencyBrakeLineState2 = getEbState2(data);
        }
      }
      vehicleBuilder.setCarIndex(ebStatusList.get(index).getIndex());
      vehicleBuilder.setEmergencyBrakeLineState1(emergencyBrakeLineState1);
      vehicleBuilder.setEmergencyBrakeLineState2(emergencyBrakeLineState2);
      builder.addEmergencyBrakeLineStatus(vehicleBuilder.build());
    }
    builderConsumer.accept(builder);
  }

  private EmergencyBrakeLineState getEbState1(VehicleEmergencyBrakeStatusDO data)
  {
    EmergencyBrakeLineState emergencyBrakeLineState;
    if (data.getEb1Energized() == 1)
    {
      emergencyBrakeLineState = EmergencyBrakeLineState.EB_LINE_ENERGIZED;
    }
    else if (data.getEb1Energized() == 0)
    {
      emergencyBrakeLineState = EmergencyBrakeLineState.EB_LINE_NOT_ENERGIZED;
    }
    else
    {
      emergencyBrakeLineState = EmergencyBrakeLineState.EB_LINE_UNKNOWN;
    }
    return emergencyBrakeLineState;
  }

  private EmergencyBrakeLineState getEbState2(VehicleEmergencyBrakeStatusDO data)
  {
    EmergencyBrakeLineState emergencyBrakeLineState;
    if (data.getEb2Energized() == 1)
    {
      emergencyBrakeLineState = EmergencyBrakeLineState.EB_LINE_ENERGIZED;
    }
    else if (data.getEb2Energized() == 0)
    {
      emergencyBrakeLineState = EmergencyBrakeLineState.EB_LINE_NOT_ENERGIZED;
    }
    else
    {
      emergencyBrakeLineState = EmergencyBrakeLineState.EB_LINE_UNKNOWN;
    }
    return emergencyBrakeLineState;
  }
}
