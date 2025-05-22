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
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.RIO2StatusList.RIO2State;

/**
 * This class handles RI02 status update from vehicle outputs
 * 
 */
public class TcmsStatusRI02VehicleOutputsRequestHandler implements
    ITCMSVehicleOutputsRequestHandler<TCMSOutputsTcmsSystemScreenImpl<Integer, IAppOutputsTcmsStatusScreenHandler>>
{

  protected final List<Entry<VehicleTcmsStatusScreenDO>> ri02StatusList = new ArrayList<>();

  @Override
  public void handleRequest(
      TCMSOutputsTcmsSystemScreenImpl<Integer, IAppOutputsTcmsStatusScreenHandler> request)
  {
    try
    {
      VehicleTcmsStatusScreenDO vehicleStatusDO = ITCMSVehicleOutputsRequestHandler
          .getVehicleStatusDo(ri02StatusList, request.getCarIndex(), VehicleTcmsStatusScreenDO.class);
      setStatus(request.getPropertyKey(), request.getNewValue(), vehicleStatusDO);
      ITCMSVehicleOutputsRequestHandler.updateVehicleStatusDOList(ri02StatusList, vehicleStatusDO,
          request.getCarIndex());
      setRi02StatusList(ri02StatusList, request.getVehicleDetailModelList(),
          builder -> request.getHandler().setRio2Status(builder.build().toByteArray()));
    }
    catch (InstantiationException e)
    {
      Tracer.getInstance().info(e);
    }
  }

  private void setStatus(PropertyKey<Integer> propertyKey, Integer newvalue,
      VehicleTcmsStatusScreenDO vehicleStatusDO)
  {
    if (propertyKey.equals(ITCMSVehicleOutputsStatusScreenProperties.RIO2_FAULT))
    {
      vehicleStatusDO.setRi02Fault(newvalue);
    }
    else if (propertyKey.equals(ITCMSVehicleOutputsStatusScreenProperties.RIO2_STATUS))
    {
      vehicleStatusDO.setRi02Status(newvalue);
    }

  }

  private void setRi02StatusList(List<Entry<VehicleTcmsStatusScreenDO>> rio2StatusList,
      List<VehicleDetailModel> vehicleDetailModelList,
      Consumer<TCMSProto.RIO2StatusList.Builder> builderConsumer)
  {
    TCMSProto.RIO2StatusList.Builder builder = TCMSProto.RIO2StatusList.newBuilder();
    TCMSProto.RIO2StatusList.RIO2Status.Builder vehicleBuilder = TCMSProto.RIO2StatusList.RIO2Status
        .newBuilder();

    VehicleTcmsStatusScreenDO data;
    for (int index = 0; index < rio2StatusList.size(); index++)
    {
      int carIndex = rio2StatusList.get(index).getIndex();

      RIO2State ri02State = RIO2State.RIO2_UNKNOW;
      if (vehicleDetailModelList != null && vehicleDetailModelList.size() > carIndex)
      {

        data = rio2StatusList.get(index).getData();

        ri02State = getRio2StatusList(data);

      }
      vehicleBuilder.setCarIndex(rio2StatusList.get(index).getIndex());
      vehicleBuilder.setRio2State(ri02State);

      builder.addRio2Status(vehicleBuilder.build());
    }
    builderConsumer.accept(builder);
  }

  private RIO2State getRio2StatusList(VehicleTcmsStatusScreenDO data)
  {
    RIO2State rIO2State;
    if (data.getRi02Fault() == 1)
    {
      rIO2State = RIO2State.RIO2_FAULTY;
    }
    else if (data.getRi02Status() == 1)
    {
      rIO2State = RIO2State.RIO2_OK;
    }

    else
    {
      rIO2State = RIO2State.RIO2_UNKNOW;
    }
    return rIO2State;
  }

}
