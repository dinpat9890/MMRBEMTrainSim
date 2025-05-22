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
import com.sydac.mmrbem.tcms.backend.app.io.handlers.IAppOutputsBatteryScreenHandler;
import com.sydac.mmrbem.tcms.common.data.Entry;
import com.sydac.mmrbem.tcms.common.data.VehicleDetailModel;
import com.sydac.mmrbem.tcms.common.data.VehicleTotalOutputCurrentValueDO;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.TotalOutputCurrentStatusList;
import com.sydac.mmrbem.tcms.common.state.ApplicationConstants;
import com.sydac.mmrbem.tcms.common.state.TCMSConstants;

/**
 * This class handles Total Output Current update from vehicle outputs
 * 
 */
public class TotalOutputCurrentVehicleOutputsRequestHandler implements
    ITCMSVehicleOutputsRequestHandler<TCMSOutputsBatterySystemScreenImpl<Integer, IAppOutputsBatteryScreenHandler>>
{

  protected final List<Entry<VehicleTotalOutputCurrentValueDO>> totalOutputCurrentList = new ArrayList<>();

  @Override
  public void handleRequest(
      TCMSOutputsBatterySystemScreenImpl<Integer, IAppOutputsBatteryScreenHandler> request)
  {
    try
    {
      VehicleTotalOutputCurrentValueDO vehicleTotalOutputCurrentValueDO = ITCMSVehicleOutputsRequestHandler
          .getVehicleStatusDo(totalOutputCurrentList, request.getCarIndex(),
              VehicleTotalOutputCurrentValueDO.class);
      vehicleTotalOutputCurrentValueDO.setTotalOutputCurrent(request.newValue);
      ITCMSVehicleOutputsRequestHandler.updateVehicleStatusDOList(totalOutputCurrentList,
          vehicleTotalOutputCurrentValueDO, request.getCarIndex());
      setTotalOutputCurrentList(totalOutputCurrentList, request.getVehicleDetailModelList(),
          builder -> request.getHandler().setTotalOutputCurrentStatus(builder.build().toByteArray()));
    }
    catch (InstantiationException e)
    {
      Tracer.getInstance().info(e);
    }
  }

  private void setTotalOutputCurrentList(List<Entry<VehicleTotalOutputCurrentValueDO>> totalOutputCurrentList,
      List<VehicleDetailModel> vehicleDetailModelList,
      Consumer<TCMSProto.TotalOutputCurrentStatusList.Builder> builderConsumer)
  {
    TCMSProto.TotalOutputCurrentStatusList.Builder builder = TCMSProto.TotalOutputCurrentStatusList
        .newBuilder();

    TotalOutputCurrentStatusList.TotalOutputCurrent.Builder vehicleBuilder = TotalOutputCurrentStatusList.TotalOutputCurrent
        .newBuilder();

    for (int index = 0; index < totalOutputCurrentList.size(); index++)
    {
      int carIndex = totalOutputCurrentList.get(index).getIndex();
      int value = ApplicationConstants.VALUE_NOT_APPLICABLE;
      if (vehicleDetailModelList != null && vehicleDetailModelList.size() > carIndex)
      {
        String carClassCode = vehicleDetailModelList.get(carIndex).getCarClassCode();
        if (TCMSConstants.M_CAR.equals(carClassCode))
        {
          value = totalOutputCurrentList.get(carIndex).getData().getTotalOutputCurrent();
        }
      }
      vehicleBuilder.setCarIndex(carIndex);
      vehicleBuilder.setTotalOutputCurrent(value);
      builder.addTotalOutputCurrent(vehicleBuilder.build());
    }
    builderConsumer.accept(builder);
  }
}
