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
import com.sydac.mmrbem.tcms.common.data.VehicleWFLStatusDO;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.WFLStatusList.WFLState;
import com.sydac.mmrbem.tcms.common.state.TCMSConstants;

/**
 * This class handles WFL Status update from vehicle outputs
 * 
 */
public class WFLStatusVehicleOutputsRequestHandler implements
    ITCMSVehicleOutputsRequestHandler<TCMSOutputsWFLSystemScreenImpl<Integer, IAppOutputsWFLSystemScreenHandler>>
{

  protected final List<Entry<VehicleWFLStatusDO>> wflStatus = new ArrayList<>();

  @Override
  public void handleRequest(
      TCMSOutputsWFLSystemScreenImpl<Integer, IAppOutputsWFLSystemScreenHandler> request)
  {
    try
    {
      VehicleWFLStatusDO vehicleWFLStatusDO = ITCMSVehicleOutputsRequestHandler.getVehicleStatusDo(wflStatus,
          request.getCarIndex(), VehicleWFLStatusDO.class);
      setStatus(request.getPropertyKey(), request.getNewValue(), vehicleWFLStatusDO);
      ITCMSVehicleOutputsRequestHandler.updateVehicleStatusDOList(wflStatus, vehicleWFLStatusDO,
          request.getCarIndex());
      setWFLStatus(wflStatus, request.getVehicleDetailModelList(),
          builder -> request.getHandler().setWflStatus(builder.build().toByteArray()));
    }
    catch (InstantiationException e)
    {
      Tracer.getInstance().info(e);
    }
  }

  private void setStatus(PropertyKey<Integer> propertyKey, Integer newvalue,
      VehicleWFLStatusDO vehicleWFLStatusDO)
  {
    if (propertyKey.equals(ITCMSVehicleOutputsWFLSystemProperties.WFL_FAULT))
    {
      vehicleWFLStatusDO.setWflFault(newvalue);
    }
    else if (propertyKey.equals(ITCMSVehicleOutputsWFLSystemProperties.WFL_STATUS))
    {
      vehicleWFLStatusDO.setWflStatus(newvalue);
    }
  }

  private void setWFLStatus(List<Entry<VehicleWFLStatusDO>> wflStatus,
      List<VehicleDetailModel> vehicleDetailModelList,
      Consumer<TCMSProto.WFLStatusList.Builder> builderConsumer)
  {
    TCMSProto.WFLStatusList.Builder builder = TCMSProto.WFLStatusList.newBuilder();
    TCMSProto.WFLStatusList.WFLStatus.Builder vehicleBuilder = TCMSProto.WFLStatusList.WFLStatus.newBuilder();

    VehicleWFLStatusDO data;
    for (int index = 0; index < wflStatus.size(); index++)
    {
      int carIndex = wflStatus.get(index).getIndex();
      WFLState wflState = WFLState.WFL_STATUS_BLANK;
      if (vehicleDetailModelList != null && vehicleDetailModelList.size() > carIndex)
      {
        String carClassCode = vehicleDetailModelList.get(carIndex).getCarClassCode();
        if (TCMSConstants.DM_CAR.equals(carClassCode))
        {
          data = wflStatus.get(index).getData();
          wflState = getWFLState(data);
        }
        else
        {
          wflState = WFLState.WFL_STATUS_BLANK;
        }
      }
      vehicleBuilder.setCarIndex(wflStatus.get(index).getIndex());
      vehicleBuilder.setWflState(wflState);
      builder.addWflStatus(vehicleBuilder.build());
    }
    builderConsumer.accept(builder);
  }

  private WFLState getWFLState(VehicleWFLStatusDO data)
  {
    WFLState wflState;
    if (data.getWflFault() == TCMSConstants.FAULTY)
    {
      wflState = WFLState.WFL_STATUS_FAULTY;
    }
    else if (data.getWflStatus() == TCMSConstants.OK)
    {
      wflState = WFLState.WFL_STATUS_OK;
    }
    else
    {
      wflState = WFLState.WFL_STATUS_UNKNOWN;
    }
    return wflState;
  }
}
