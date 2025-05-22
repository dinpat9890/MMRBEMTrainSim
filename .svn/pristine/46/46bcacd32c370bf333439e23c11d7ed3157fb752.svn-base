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
import com.sydac.mmrbem.tcms.common.data.VehicleWspStatusDO;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.WSPStatusList.WSPState;

/**
 * This class handles WSP status update from vehicle outputs
 * 
 */
public class WspVehicleOutputsRequestHandler implements
    ITCMSVehicleOutputsRequestHandler<TCMSOutputsBrakeSystemScreenImpl<Integer, IAppOutputsBrakeScreenHandler>>
{

  protected final List<Entry<VehicleWspStatusDO>> wspStatusList = new ArrayList<>();

  @Override
  public void handleRequest(TCMSOutputsBrakeSystemScreenImpl<Integer, IAppOutputsBrakeScreenHandler> request)
  {
    try
    {
      VehicleWspStatusDO vehicleWspstatusDO = ITCMSVehicleOutputsRequestHandler
          .getVehicleStatusDo(wspStatusList, request.getCarIndex(), VehicleWspStatusDO.class);
      setStatus(request.getPropertyKey(), request.getNewValue(), vehicleWspstatusDO);
      ITCMSVehicleOutputsRequestHandler.updateVehicleStatusDOList(wspStatusList, vehicleWspstatusDO,
          request.getCarIndex());
      setWspStatus(wspStatusList,
          builder -> request.getHandler().setWspStatus(builder.build().toByteArray()));
    }
    catch (InstantiationException e)
    {
      Tracer.getInstance().info(e);
    }
  }

  protected void setStatus(PropertyKey<Integer> propertyKey, Integer newvalue,
      VehicleWspStatusDO vehicleWspstatusDO)
  {
    if (propertyKey.equals(ITCMSVehicleOutputsBrakeSystemProperties.BOGIE_1_WSP_STATUS))
    {
      vehicleWspstatusDO.setWspActivatedState1(newvalue);
    }
    else if (propertyKey.equals(ITCMSVehicleOutputsBrakeSystemProperties.BOGIE_2_WSP_STATUS))
    {
      vehicleWspstatusDO.setWspActivatedState2(newvalue);
    }
  }

  protected void setWspStatus(List<Entry<VehicleWspStatusDO>> wspStatusList,
      Consumer<TCMSProto.WSPStatusList.Builder> builderConsumer)
  {
    TCMSProto.WSPStatusList.Builder builder = TCMSProto.WSPStatusList.newBuilder();
    TCMSProto.WSPStatusList.WSPStatus.Builder vehicleBuilder = TCMSProto.WSPStatusList.WSPStatus.newBuilder();

    VehicleWspStatusDO data;
    for (int index = 0; index < wspStatusList.size(); index++)
    {
      data = wspStatusList.get(index).getData();
      WSPState wspState1 = getWspState1(data);
      WSPState wspState2 = getWspState2(data);

      vehicleBuilder.setCarIndex(wspStatusList.get(index).getIndex());
      vehicleBuilder.setWspState1(wspState1);
      vehicleBuilder.setWspState2(wspState2);
      builder.addWspStatus(vehicleBuilder.build());
    }
    builderConsumer.accept(builder);
  }

  private WSPState getWspState1(VehicleWspStatusDO data)
  {
    WSPState wspState;
    if (data.getWspActivatedState1() == 1)
    {
      wspState = WSPState.WSP_ACTIVATED;
    }
    else if (data.getWspActivatedState1() == 0)
    {
      wspState = WSPState.WSP_NOT_ACTIVATED;
    }
    else
    {
      wspState = WSPState.WSP_UNKNOWN;
    }
    return wspState;
  }

  private WSPState getWspState2(VehicleWspStatusDO data)
  {
    WSPState wspState;
    if (data.getWspActivatedState2() == 1)
    {
      wspState = WSPState.WSP_ACTIVATED;
    }
    else if (data.getWspActivatedState2() == 0)
    {
      wspState = WSPState.WSP_NOT_ACTIVATED;
    }
    else
    {
      wspState = WSPState.WSP_UNKNOWN;
    }
    return wspState;
  }

}
