/*
 * ==================================================================
 * 
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.tcms.backend.vehicle.request.handler;

import java.util.ArrayList;
import java.util.List;
import java.util.function.Consumer;

import com.sydac.common.log.Tracer;
import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.tcms.backend.app.io.handlers.IAppOutputsWFLSystemScreenHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.io.properties.ITCMSVehicleOutputsWFLSystemProperties;
import com.sydac.mmrbem.tcms.common.data.Entry;
import com.sydac.mmrbem.tcms.common.data.VehicleDetailModel;
import com.sydac.mmrbem.tcms.common.data.VehicleWFLPumpStatusDO;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.WFLPumpStatusList.WFLPumpState;
import com.sydac.mmrbem.tcms.common.state.TCMSConstants;

/**
 * This class handles WFL Pump Status 1 update from vehicle outputs
 * 
 */
public class WFLPumpStatus1VehicleOutputsRequestHandler implements
    ITCMSVehicleOutputsRequestHandler<TCMSOutputsWFLSystemScreenImpl<Integer, IAppOutputsWFLSystemScreenHandler>>
{

  protected final List<Entry<VehicleWFLPumpStatusDO>> wflPumpStatus1 = new ArrayList<>();

  @Override
  public void handleRequest(
      TCMSOutputsWFLSystemScreenImpl<Integer, IAppOutputsWFLSystemScreenHandler> request)
  {
    try
    {
      VehicleWFLPumpStatusDO vehicleWFLPumpStatusDO = ITCMSVehicleOutputsRequestHandler
          .getVehicleStatusDo(wflPumpStatus1, request.getCarIndex(), VehicleWFLPumpStatusDO.class);
      setStatus(request.getPropertyKey(), request.getNewValue(), vehicleWFLPumpStatusDO);
      ITCMSVehicleOutputsRequestHandler.updateVehicleStatusDOList(wflPumpStatus1, vehicleWFLPumpStatusDO,
          request.getCarIndex());
      setWFLPumpStatus(wflPumpStatus1, request.getVehicleDetailModelList(),
          builder -> request.getHandler().setWflPumpStatus1(builder.build().toByteArray()));
    }
    catch (InstantiationException e)
    {
      Tracer.getInstance().info(e);
    }
  }

  private void setStatus(PropertyKey<Integer> propertyKey, Integer newvalue,
      VehicleWFLPumpStatusDO vehicleWFLPumpStatusDO)
  {
    if (propertyKey.equals(ITCMSVehicleOutputsWFLSystemProperties.WFL_PUMP_1))
    {
      vehicleWFLPumpStatusDO.setWflPumpStatus(newvalue);
    }
  }

  private void setWFLPumpStatus(List<Entry<VehicleWFLPumpStatusDO>> wflPumpStatus,
      List<VehicleDetailModel> vehicleDetailModelList,
      Consumer<TCMSProto.WFLPumpStatusList.Builder> builderConsumer)
  {
    TCMSProto.WFLPumpStatusList.Builder builder = TCMSProto.WFLPumpStatusList.newBuilder();
    TCMSProto.WFLPumpStatusList.WFLPumpStatus.Builder vehicleBuilder = TCMSProto.WFLPumpStatusList.WFLPumpStatus
        .newBuilder();

    VehicleWFLPumpStatusDO data;
    for (int index = 0; index < wflPumpStatus.size(); index++)
    {
      int carIndex = wflPumpStatus.get(index).getIndex();
      WFLPumpState wflPumpState = WFLPumpState.WFL_PUMP_STATUS_BLANK;
      if (vehicleDetailModelList != null && vehicleDetailModelList.size() > carIndex)
      {
        String carClassCode = vehicleDetailModelList.get(carIndex).getCarClassCode();
        if (TCMSConstants.DM_CAR.equals(carClassCode))
        {
          data = wflPumpStatus.get(index).getData();
          wflPumpState = getWFLPumpState(data);
        }
        else
        {
          wflPumpState = WFLPumpState.WFL_PUMP_STATUS_BLANK;
        }
      }
      vehicleBuilder.setCarIndex(wflPumpStatus.get(index).getIndex());
      vehicleBuilder.setWflPumpState(wflPumpState);
      builder.addWflPumpStatus(vehicleBuilder.build());
    }
    builderConsumer.accept(builder);
  }

  private WFLPumpState getWFLPumpState(VehicleWFLPumpStatusDO data)
  {
    WFLPumpState wflPumpState;
    if (data.getWflPumpStatus() == WFLPumpState.WFL_PUMP_STATUS_NOT_ACTIVE_VALUE)
    {
      wflPumpState = WFLPumpState.WFL_PUMP_STATUS_NOT_ACTIVE;
    }
    else
    {
      wflPumpState = WFLPumpState.WFL_PUMP_STATUS_ACTIVE;
    }
    return wflPumpState;
  }
}
