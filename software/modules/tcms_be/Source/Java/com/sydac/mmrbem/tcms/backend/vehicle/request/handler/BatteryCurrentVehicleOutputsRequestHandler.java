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
import com.sydac.mmrbem.tcms.common.data.VehicleBatteryCurrentValueDO;
import com.sydac.mmrbem.tcms.common.data.VehicleDetailModel;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.BatteryCurrentStatusList;
import com.sydac.mmrbem.tcms.common.state.ApplicationConstants;
import com.sydac.mmrbem.tcms.common.state.TCMSConstants;

/**
 * This class handles Battery Current update from vehicle outputs
 * 
 */
public class BatteryCurrentVehicleOutputsRequestHandler implements
    ITCMSVehicleOutputsRequestHandler<TCMSOutputsBatterySystemScreenImpl<Integer, IAppOutputsBatteryScreenHandler>>
{

  protected final List<Entry<VehicleBatteryCurrentValueDO>> batteryCurrentList = new ArrayList<>();

  @Override
  public void handleRequest(
      TCMSOutputsBatterySystemScreenImpl<Integer, IAppOutputsBatteryScreenHandler> request)
  {
    try
    {
      VehicleBatteryCurrentValueDO vehicleBatteryCurrentValueDO = ITCMSVehicleOutputsRequestHandler
          .getVehicleStatusDo(batteryCurrentList, request.getCarIndex(), VehicleBatteryCurrentValueDO.class);
      vehicleBatteryCurrentValueDO.setBatteryCurrent(request.newValue);
      ITCMSVehicleOutputsRequestHandler.updateVehicleStatusDOList(batteryCurrentList,
          vehicleBatteryCurrentValueDO, request.getCarIndex());
      setBatteryCurrentList(batteryCurrentList, request.getVehicleDetailModelList(),
          builder -> request.getHandler().setBatteryCurrentStatus(builder.build().toByteArray()));
    }
    catch (InstantiationException e)
    {
      Tracer.getInstance().info(e);
    }
  }

  private void setBatteryCurrentList(List<Entry<VehicleBatteryCurrentValueDO>> batteryCurrentList,
      List<VehicleDetailModel> vehicleDetailModelList,
      Consumer<TCMSProto.BatteryCurrentStatusList.Builder> builderConsumer)
  {
    TCMSProto.BatteryCurrentStatusList.Builder builder = TCMSProto.BatteryCurrentStatusList.newBuilder();

    BatteryCurrentStatusList.BatteryCurrent.Builder vehicleBuilder = BatteryCurrentStatusList.BatteryCurrent
        .newBuilder();

    for (int index = 0; index < batteryCurrentList.size(); index++)
    {
      int carIndex = batteryCurrentList.get(index).getIndex();
      int value = ApplicationConstants.VALUE_NOT_APPLICABLE;
      if (vehicleDetailModelList != null && vehicleDetailModelList.size() > carIndex)
      {
        String carClassCode = vehicleDetailModelList.get(carIndex).getCarClassCode();
        if (TCMSConstants.M_CAR.equals(carClassCode))
        {
          value = batteryCurrentList.get(carIndex).getData().getBatteryCurrent();
        }
      }
      vehicleBuilder.setCarIndex(carIndex);
      vehicleBuilder.setBatteryCurrent(value);
      builder.addBatteryCurrent(vehicleBuilder.build());
    }
    builderConsumer.accept(builder);
  }
}
