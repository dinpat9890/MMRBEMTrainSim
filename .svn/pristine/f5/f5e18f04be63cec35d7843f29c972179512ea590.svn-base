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
import com.sydac.mmrbem.tcms.common.data.VehicleWFLOilLevelStatusDO;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.WFLOilLevelStatusList.WFLOilState;
import com.sydac.mmrbem.tcms.common.state.TCMSConstants;

/**
 * This class handles WFL Oil Level Status update from vehicle outputs
 * 
 */
public class WFLOilLevelStatusVehicleOutputsRequestHandler implements
    ITCMSVehicleOutputsRequestHandler<TCMSOutputsWFLSystemScreenImpl<Integer, IAppOutputsWFLSystemScreenHandler>>
{

  protected final List<Entry<VehicleWFLOilLevelStatusDO>> wflOilLevelStatus = new ArrayList<>();

  @Override
  public void handleRequest(
      TCMSOutputsWFLSystemScreenImpl<Integer, IAppOutputsWFLSystemScreenHandler> request)
  {
    try
    {
      VehicleWFLOilLevelStatusDO vehicleWFLOilLevelStatusDO = ITCMSVehicleOutputsRequestHandler
          .getVehicleStatusDo(wflOilLevelStatus, request.getCarIndex(), VehicleWFLOilLevelStatusDO.class);
      setStatus(request.getPropertyKey(), request.getNewValue(), vehicleWFLOilLevelStatusDO);
      ITCMSVehicleOutputsRequestHandler.updateVehicleStatusDOList(wflOilLevelStatus,
          vehicleWFLOilLevelStatusDO, request.getCarIndex());
      setWFLOilLevelStatus(wflOilLevelStatus, request.getVehicleDetailModelList(),
          builder -> request.getHandler().setWflOilLevelStatus(builder.build().toByteArray()));
    }
    catch (InstantiationException e)
    {
      Tracer.getInstance().info(e);
    }
  }

  private void setStatus(PropertyKey<Integer> propertyKey, Integer newvalue,
      VehicleWFLOilLevelStatusDO vehicleWFLOilLevelStatusDO)
  {
    if (propertyKey.equals(ITCMSVehicleOutputsWFLSystemProperties.WFL_OIL_LEVEL_STATUS))
    {
      vehicleWFLOilLevelStatusDO.setWflOilLevelStatus(newvalue);
    }
  }

  private void setWFLOilLevelStatus(List<Entry<VehicleWFLOilLevelStatusDO>> wflOilLevelStatus,
      List<VehicleDetailModel> vehicleDetailModelList,
      Consumer<TCMSProto.WFLOilLevelStatusList.Builder> builderConsumer)
  {
    TCMSProto.WFLOilLevelStatusList.Builder builder = TCMSProto.WFLOilLevelStatusList.newBuilder();
    TCMSProto.WFLOilLevelStatusList.WFLOilLevelStatus.Builder vehicleBuilder = TCMSProto.WFLOilLevelStatusList.WFLOilLevelStatus
        .newBuilder();

    VehicleWFLOilLevelStatusDO data;
    for (int index = 0; index < wflOilLevelStatus.size(); index++)
    {
      int carIndex = wflOilLevelStatus.get(index).getIndex();
      WFLOilState wflOilState = WFLOilState.WFL_OIL_LEVEL_STATUS_BLANK;
      if (vehicleDetailModelList != null && vehicleDetailModelList.size() > carIndex)
      {
        String carClassCode = vehicleDetailModelList.get(carIndex).getCarClassCode();
        if (TCMSConstants.DM_CAR.equals(carClassCode))
        {
          data = wflOilLevelStatus.get(index).getData();
          wflOilState = getWFLOilState(data);
        }
        else
        {
          wflOilState = WFLOilState.WFL_OIL_LEVEL_STATUS_BLANK;
        }
      }
      vehicleBuilder.setCarIndex(wflOilLevelStatus.get(index).getIndex());
      vehicleBuilder.setWflOilState(wflOilState);
      builder.addWflOilLevelStatus(vehicleBuilder.build());
    }
    builderConsumer.accept(builder);
  }

  private WFLOilState getWFLOilState(VehicleWFLOilLevelStatusDO data)
  {
    WFLOilState wflOilState;
    if (data.getWflOilLevelStatus() == WFLOilState.WFL_OIL_LEVEL_STATUS_HIGH_VALUE)
    {
      wflOilState = WFLOilState.WFL_OIL_LEVEL_STATUS_HIGH;
    }
    else if (data.getWflOilLevelStatus() == WFLOilState.WFL_OIL_LEVEL_STATUS_LOW_VALUE)
    {
      wflOilState = WFLOilState.WFL_OIL_LEVEL_STATUS_LOW;
    }
    else
    {
      wflOilState = WFLOilState.WFL_OIL_LEVEL_STATUS_UNKNOWN;
    }
    return wflOilState;
  }
}
