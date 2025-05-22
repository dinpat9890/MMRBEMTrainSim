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
import com.sydac.mmrbem.tcms.backend.app.io.handlers.IAppOutputsHVACSystemScreenHandler;
import com.sydac.mmrbem.tcms.common.data.Entry;
import com.sydac.mmrbem.tcms.common.data.VehicleSetPointTemperatureValueDO;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.SetPointTemperatureStatusList;

/**
 * This class handles HVAC 2 Set Point Temperature update from vehicle outputs.
 * 
 */
public class HVAC2SetPointTemperatureVehicleOutputRequestHandler implements
    ITCMSVehicleOutputsRequestHandler<TCMSOutputsHVACSystemScreenImpl<Integer, IAppOutputsHVACSystemScreenHandler>>
{

  private List<Entry<VehicleSetPointTemperatureValueDO>> setPointTemperatureStatus2 = new ArrayList<>();

  @Override
  public void handleRequest(
      TCMSOutputsHVACSystemScreenImpl<Integer, IAppOutputsHVACSystemScreenHandler> request)
  {
    try
    {
      VehicleSetPointTemperatureValueDO vehicleSetPointTemperatureValueDO = ITCMSVehicleOutputsRequestHandler
          .getVehicleStatusDo(setPointTemperatureStatus2, request.getCarIndex(),
              VehicleSetPointTemperatureValueDO.class);
      vehicleSetPointTemperatureValueDO.setSetPointTemperatureValue(request.newValue);
      ITCMSVehicleOutputsRequestHandler.updateVehicleStatusDOList(setPointTemperatureStatus2,
          vehicleSetPointTemperatureValueDO, request.getCarIndex());
      setSetPointTemperatureStatus(setPointTemperatureStatus2,
          builder -> request.getHandler().setSetPointTemperatureStatus2(builder.build().toByteArray()));
    }
    catch (InstantiationException e)
    {
      Tracer.getInstance().info(e);
    }
  }

  private void setSetPointTemperatureStatus(
      List<Entry<VehicleSetPointTemperatureValueDO>> setPointTemperatureValue,
      Consumer<TCMSProto.SetPointTemperatureStatusList.Builder> builderConsumer)
  {
    TCMSProto.SetPointTemperatureStatusList.Builder builder = TCMSProto.SetPointTemperatureStatusList
        .newBuilder();

    SetPointTemperatureStatusList.SetPointTemperatureStatus.Builder vehicleBuilder = SetPointTemperatureStatusList.SetPointTemperatureStatus
        .newBuilder();

    setPointTemperatureValue.forEach(setPointTemperatureVal -> {
      vehicleBuilder.setCarIndex(setPointTemperatureVal.getIndex());
      vehicleBuilder.setSetPointTemperature(setPointTemperatureVal.getData().getSetPointTemperatureValue());
      builder.addSetPointTemperatureStatus(vehicleBuilder.build());
    });

    builderConsumer.accept(builder);
  }
}