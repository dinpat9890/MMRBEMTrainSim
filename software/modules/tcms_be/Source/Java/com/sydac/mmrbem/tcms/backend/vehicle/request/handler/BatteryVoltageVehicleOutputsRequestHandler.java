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
import com.sydac.mmrbem.tcms.common.data.VehicleBatteryVoltageValueDO;
import com.sydac.mmrbem.tcms.common.data.VehicleDetailModel;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.BatteryVoltageStatusList;

/**
 * This class handles Battery Voltage update from vehicle outputs
 * 
 */
public class BatteryVoltageVehicleOutputsRequestHandler implements
    ITCMSVehicleOutputsRequestHandler<TCMSOutputsBatterySystemScreenImpl<Integer, IAppOutputsBatteryScreenHandler>>
{

  protected final List<Entry<VehicleBatteryVoltageValueDO>> batteryVoltageList = new ArrayList<>();

  @Override
  public void handleRequest(
      TCMSOutputsBatterySystemScreenImpl<Integer, IAppOutputsBatteryScreenHandler> request)
  {
    try
    {
      VehicleBatteryVoltageValueDO vehicleBcgOutputVoltageValueDO = ITCMSVehicleOutputsRequestHandler
          .getVehicleStatusDo(batteryVoltageList, request.getCarIndex(), VehicleBatteryVoltageValueDO.class);
      vehicleBcgOutputVoltageValueDO.setBatteryVoltage(request.newValue);
      ITCMSVehicleOutputsRequestHandler.updateVehicleStatusDOList(batteryVoltageList,
          vehicleBcgOutputVoltageValueDO, request.getCarIndex());
      setBatteryVoltageList(batteryVoltageList, request.getVehicleDetailModelList(),
          builder -> request.getHandler().setBatteryVoltageStatus(builder.build().toByteArray()));
    }
    catch (InstantiationException e)
    {
      Tracer.getInstance().info(e);
    }
  }

  private void setBatteryVoltageList(List<Entry<VehicleBatteryVoltageValueDO>> batteryVoltageList,
      List<VehicleDetailModel> vehicleDetailModelList,
      Consumer<TCMSProto.BatteryVoltageStatusList.Builder> builderConsumer)
  {
    TCMSProto.BatteryVoltageStatusList.Builder builder = TCMSProto.BatteryVoltageStatusList.newBuilder();

    BatteryVoltageStatusList.BatteryVoltage.Builder vehicleBuilder = BatteryVoltageStatusList.BatteryVoltage
        .newBuilder();

    for (int index = 0; index < batteryVoltageList.size(); index++)
    {
      int carIndex = batteryVoltageList.get(index).getIndex();
      int value = batteryVoltageList.get(carIndex).getData().getBatteryVoltage();
      vehicleBuilder.setCarIndex(carIndex);
      vehicleBuilder.setBatteryVoltage(value);
      builder.addBatteryVoltage(vehicleBuilder.build());
    }
    builderConsumer.accept(builder);
  }
}
