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
import com.sydac.mmrbem.tcms.backend.app.io.handlers.IAppOutputsTcmsStatusScreenHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.io.properties.ITCMSVehicleOutputsStatusScreenProperties;
import com.sydac.mmrbem.tcms.common.data.Entry;
import com.sydac.mmrbem.tcms.common.data.VehicleDetailModel;
import com.sydac.mmrbem.tcms.common.data.VehicleTcmsStatusScreenDO;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.RIO1StatusList.RIO1State;

/**
 * This class handles RI01 status update from vehicle outputs
 * 
 */
public class TcmsStatusRI01VehicleOutputsRequestHandler implements
    ITCMSVehicleOutputsRequestHandler<TCMSOutputsTcmsSystemScreenImpl<Integer, IAppOutputsTcmsStatusScreenHandler>>
{

  protected final List<Entry<VehicleTcmsStatusScreenDO>> ri01StatusList = new ArrayList<>();

  @Override
  public void handleRequest(
      TCMSOutputsTcmsSystemScreenImpl<Integer, IAppOutputsTcmsStatusScreenHandler> request)
  {
    try
    {
      VehicleTcmsStatusScreenDO vehicleStatusDO = ITCMSVehicleOutputsRequestHandler
          .getVehicleStatusDo(ri01StatusList, request.getCarIndex(), VehicleTcmsStatusScreenDO.class);
      setStatus(request.getPropertyKey(), request.getNewValue(), vehicleStatusDO);
      ITCMSVehicleOutputsRequestHandler.updateVehicleStatusDOList(ri01StatusList, vehicleStatusDO,
          request.getCarIndex());
      setRi01StatusList(ri01StatusList, request.getVehicleDetailModelList(),
          builder -> request.getHandler().setRio1Status(builder.build().toByteArray()));
    }
    catch (InstantiationException e)
    {
      Tracer.getInstance().info(e);
    }
  }

  private void setStatus(PropertyKey<Integer> propertyKey, Integer newvalue,
      VehicleTcmsStatusScreenDO vehicleStatusDO)
  {
    if (propertyKey.equals(ITCMSVehicleOutputsStatusScreenProperties.RIO1_FAULT))
    {
      vehicleStatusDO.setRi01Fault(newvalue);
    }
    else if (propertyKey.equals(ITCMSVehicleOutputsStatusScreenProperties.RIO1_STATUS))
    {
      vehicleStatusDO.setRi01Status(newvalue);
    }

  }

  private void setRi01StatusList(List<Entry<VehicleTcmsStatusScreenDO>> rio1StatusList,
      List<VehicleDetailModel> vehicleDetailModelList,
      Consumer<TCMSProto.RIO1StatusList.Builder> builderConsumer)
  {
    TCMSProto.RIO1StatusList.Builder builder = TCMSProto.RIO1StatusList.newBuilder();
    TCMSProto.RIO1StatusList.RIO1Status.Builder vehicleBuilder = TCMSProto.RIO1StatusList.RIO1Status
        .newBuilder();

    VehicleTcmsStatusScreenDO data;
    for (int index = 0; index < rio1StatusList.size(); index++)
    {
      int carIndex = rio1StatusList.get(index).getIndex();

      RIO1State ri01State = RIO1State.RIO1_UNKNOW;
      if (vehicleDetailModelList != null && vehicleDetailModelList.size() > carIndex)
      {

        data = rio1StatusList.get(index).getData();

        ri01State = getRio1StatusList(data);

      }
      vehicleBuilder.setCarIndex(rio1StatusList.get(index).getIndex());
      vehicleBuilder.setRio1State(ri01State);

      builder.addRio1Status(vehicleBuilder.build());
    }
    builderConsumer.accept(builder);
  }

  private RIO1State getRio1StatusList(VehicleTcmsStatusScreenDO data)
  {
    RIO1State rIO1State;
    if (data.getRi01Fault() == 1)
    {
      rIO1State = RIO1State.RIO1_FAULTY;
    }
    else if (data.getRi01Status() == 1)
    {
      rIO1State = RIO1State.RIO1_OK;
    }

    else
    {
      rIO1State = RIO1State.RIO1_UNKNOW;
    }
    return rIO1State;
  }

}
