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
import com.sydac.mmrbem.tcms.common.data.VehicleExternalTemperatureValueDO;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.ExternalTemperatureStatusList;

/**
 * This class handles HVAC 1 External Temperature update from vehicle outputs.
 * 
 */
public class HVAC1ExternalTemperatureVehicleOutputRequestHandler implements
    ITCMSVehicleOutputsRequestHandler<TCMSOutputsHVACSystemScreenImpl<Integer, IAppOutputsHVACSystemScreenHandler>>
{

  private List<Entry<VehicleExternalTemperatureValueDO>> externalTemperatureStatus1 = new ArrayList<>();

  @Override
  public void handleRequest(
      TCMSOutputsHVACSystemScreenImpl<Integer, IAppOutputsHVACSystemScreenHandler> request)
  {
    try
    {
      VehicleExternalTemperatureValueDO vehicleExternalTemperatureValueDO = ITCMSVehicleOutputsRequestHandler
          .getVehicleStatusDo(externalTemperatureStatus1, request.getCarIndex(),
              VehicleExternalTemperatureValueDO.class);
      vehicleExternalTemperatureValueDO.setExternalTemperature(request.newValue);
      ITCMSVehicleOutputsRequestHandler.updateVehicleStatusDOList(externalTemperatureStatus1,
          vehicleExternalTemperatureValueDO, request.getCarIndex());
      setExternalTemperatureStatus(externalTemperatureStatus1,
          builder -> request.getHandler().setExternalTemperatureStatus1(builder.build().toByteArray()));
    }
    catch (InstantiationException e)
    {
      Tracer.getInstance().info(e);
    }
  }

  private void setExternalTemperatureStatus(
      List<Entry<VehicleExternalTemperatureValueDO>> externalTemperatureValue,
      Consumer<TCMSProto.ExternalTemperatureStatusList.Builder> builderConsumer)
  {
    TCMSProto.ExternalTemperatureStatusList.Builder builder = TCMSProto.ExternalTemperatureStatusList
        .newBuilder();

    ExternalTemperatureStatusList.ExternalTemperatureStatus.Builder vehicleBuilder = ExternalTemperatureStatusList.ExternalTemperatureStatus
        .newBuilder();

    externalTemperatureValue.forEach(externalTemperatureVal -> {
      vehicleBuilder.setCarIndex(externalTemperatureVal.getIndex());
      vehicleBuilder.setExternalTemperature(externalTemperatureVal.getData().getExternalTemperature());
      builder.addExternalTemperatureStatus(vehicleBuilder.build());
    });

    builderConsumer.accept(builder);
  }
}