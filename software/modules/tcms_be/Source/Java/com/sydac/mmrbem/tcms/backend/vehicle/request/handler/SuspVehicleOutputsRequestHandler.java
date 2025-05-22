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
import com.sydac.mmrbem.tcms.common.data.VehicleSuspStatusDO;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.SUSPStatusList.SUSPState;

/**
 * This class handles SUSP status update from vehicle outputs
 * 
 */
public class SuspVehicleOutputsRequestHandler implements
    ITCMSVehicleOutputsRequestHandler<TCMSOutputsBrakeSystemScreenImpl<Integer, IAppOutputsBrakeScreenHandler>>
{

  protected final List<Entry<VehicleSuspStatusDO>> suspStatusList = new ArrayList<>();

  @Override
  public void handleRequest(TCMSOutputsBrakeSystemScreenImpl<Integer, IAppOutputsBrakeScreenHandler> request)
  {
    try
    {
      VehicleSuspStatusDO vehicleSuspStatusDO = ITCMSVehicleOutputsRequestHandler
          .getVehicleStatusDo(suspStatusList, request.getCarIndex(), VehicleSuspStatusDO.class);
      setStatus(request.getPropertyKey(), request.getNewValue(), vehicleSuspStatusDO);
      ITCMSVehicleOutputsRequestHandler.updateVehicleStatusDOList(suspStatusList, vehicleSuspStatusDO,
          request.getCarIndex());
      setSuspStatus(suspStatusList,
          builder -> request.getHandler().setSuspStatus(builder.build().toByteArray()));
    }
    catch (InstantiationException e)
    {
      Tracer.getInstance().info(e);
    }
  }

  protected void setStatus(PropertyKey<Integer> propertyKey, Integer newvalue,
      VehicleSuspStatusDO vehicleSuspStatusDO)
  {
    if (propertyKey.equals(ITCMSVehicleOutputsBrakeSystemProperties.BOGIE_1_SUSP_STATUS))
    {
      vehicleSuspStatusDO.setSuspActivatedState1(newvalue);
    }
    else if (propertyKey.equals(ITCMSVehicleOutputsBrakeSystemProperties.BOGIE_2_SUSP_STATUS))
    {
      vehicleSuspStatusDO.setSuspActivatedState2(newvalue);
    }
    else if (propertyKey.equals(ITCMSVehicleOutputsBrakeSystemProperties.BOGIE_1_SUSP_FAULT))
    {
      vehicleSuspStatusDO.setSuspFaultState1(newvalue);
    }
    else if (propertyKey.equals(ITCMSVehicleOutputsBrakeSystemProperties.BOGIE_2_SUSP_FAULT))
    {
      vehicleSuspStatusDO.setSuspFaultState2(newvalue);
    }
  }

  protected void setSuspStatus(List<Entry<VehicleSuspStatusDO>> suspStatusList,
      Consumer<TCMSProto.SUSPStatusList.Builder> builderConsumer)
  {
    TCMSProto.SUSPStatusList.Builder builder = TCMSProto.SUSPStatusList.newBuilder();
    TCMSProto.SUSPStatusList.SUSPStatus.Builder vehicleBuilder = TCMSProto.SUSPStatusList.SUSPStatus
        .newBuilder();

    VehicleSuspStatusDO data;
    for (int index = 0; index < suspStatusList.size(); index++)
    {
      data = suspStatusList.get(index).getData();
      SUSPState suspState1 = getSuspState1(data);
      SUSPState suspState2 = getSuspState2(data);

      vehicleBuilder.setCarIndex(suspStatusList.get(index).getIndex());
      vehicleBuilder.setSuspState1(suspState1);
      vehicleBuilder.setSuspState2(suspState2);
      builder.addSuspStatus(vehicleBuilder.build());
    }
    builderConsumer.accept(builder);
  }

  private SUSPState getSuspState1(VehicleSuspStatusDO data)
  {
    SUSPState suspState;
    if (data.getSuspFaultState1() == 1)
    {
      suspState = SUSPState.SUSP_FAULTY;
    }
    else if (data.getSuspActivatedState1() == 1)
    {
      suspState = SUSPState.SUSP_ACTIVATED;
    }
    else if (data.getSuspActivatedState1() == 0)
    {
      suspState = SUSPState.SUSP_NOT_ACTIVATED;
    }
    else
    {
      suspState = SUSPState.SUSP_UNKNOWN;
    }
    return suspState;
  }

  private SUSPState getSuspState2(VehicleSuspStatusDO data)
  {
    SUSPState suspState;
    if (data.getSuspFaultState2() == 1)
    {
      suspState = SUSPState.SUSP_FAULTY;
    }
    else  if (data.getSuspActivatedState2() == 1)
    {
      suspState = SUSPState.SUSP_ACTIVATED;
    }
    else if (data.getSuspActivatedState2() == 0)
    {
      suspState = SUSPState.SUSP_NOT_ACTIVATED;
    }
    else
    {
      suspState = SUSPState.SUSP_UNKNOWN;
    }
    return suspState;
  }

}
