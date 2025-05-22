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
import com.sydac.mmrbem.tcms.common.data.VehicleBatteryTemperatureValueDO;
import com.sydac.mmrbem.tcms.common.data.VehicleDetailModel;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.BatteryTemperatureStatusList;
import com.sydac.mmrbem.tcms.common.state.ApplicationConstants;
import com.sydac.mmrbem.tcms.common.state.TCMSConstants;

/**
 * This class handles Battery Temperature update from vehicle outputs
 * 
 */
public class BatteryTemperatureVehicleOutputsRequestHandler implements
    ITCMSVehicleOutputsRequestHandler<TCMSOutputsBatterySystemScreenImpl<Integer, IAppOutputsBatteryScreenHandler>>
{

  protected final List<Entry<VehicleBatteryTemperatureValueDO>> batteryTemperatureList = new ArrayList<>();

  @Override
  public void handleRequest(
      TCMSOutputsBatterySystemScreenImpl<Integer, IAppOutputsBatteryScreenHandler> request)
  {
    try
    {
      VehicleBatteryTemperatureValueDO vehicleBatteryCurrentValueDO = ITCMSVehicleOutputsRequestHandler
          .getVehicleStatusDo(batteryTemperatureList, request.getCarIndex(),
              VehicleBatteryTemperatureValueDO.class);
      vehicleBatteryCurrentValueDO.setBatteryTemperature(request.newValue);
      ITCMSVehicleOutputsRequestHandler.updateVehicleStatusDOList(batteryTemperatureList,
          vehicleBatteryCurrentValueDO, request.getCarIndex());
      setBatteryTemperatureList(batteryTemperatureList, request.getVehicleDetailModelList(),
          builder -> request.getHandler().setBatteryTemperatureStatus(builder.build().toByteArray()));
    }
    catch (InstantiationException e)
    {
      Tracer.getInstance().info(e);
    }
  }

  private void setBatteryTemperatureList(List<Entry<VehicleBatteryTemperatureValueDO>> batteryTemperatureList,
      List<VehicleDetailModel> vehicleDetailModelList,
      Consumer<TCMSProto.BatteryTemperatureStatusList.Builder> builderConsumer)
  {
    TCMSProto.BatteryTemperatureStatusList.Builder builder = TCMSProto.BatteryTemperatureStatusList
        .newBuilder();

    BatteryTemperatureStatusList.BatteryTemperature.Builder vehicleBuilder = BatteryTemperatureStatusList.BatteryTemperature
        .newBuilder();

    for (int index = 0; index < batteryTemperatureList.size(); index++)
    {
      int carIndex = batteryTemperatureList.get(index).getIndex();
      int value = ApplicationConstants.VALUE_NOT_APPLICABLE;
      if (vehicleDetailModelList != null && vehicleDetailModelList.size() > carIndex)
      {
        String carClassCode = vehicleDetailModelList.get(carIndex).getCarClassCode();
        if (TCMSConstants.M_CAR.equals(carClassCode))
        {
          value = batteryTemperatureList.get(carIndex).getData().getBatteryTemperature();
        }
      }
      vehicleBuilder.setCarIndex(carIndex);
      vehicleBuilder.setBatteryTemperature(value);
      builder.addBatteryTemperature(vehicleBuilder.build());
    }
    builderConsumer.accept(builder);
  }
}
