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
import com.sydac.mmrbem.tcms.common.data.VehicleInternalTemperatureValueDO;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.InternalTemperatureStatusList;

/**
 * This class handles HVAC 1 Internal Temperature update from vehicle outputs.
 * 
 */
public class HVAC1InternalTemperatureVehicleOutputRequestHandler implements
    ITCMSVehicleOutputsRequestHandler<TCMSOutputsHVACSystemScreenImpl<Integer, IAppOutputsHVACSystemScreenHandler>>
{

  private List<Entry<VehicleInternalTemperatureValueDO>> internalTemperatureStatus1 = new ArrayList<>();

  @Override
  public void handleRequest(
      TCMSOutputsHVACSystemScreenImpl<Integer, IAppOutputsHVACSystemScreenHandler> request)
  {
    try
    {
      VehicleInternalTemperatureValueDO vehicleInternalTemperatureValueDO = ITCMSVehicleOutputsRequestHandler
          .getVehicleStatusDo(internalTemperatureStatus1, request.getCarIndex(),
              VehicleInternalTemperatureValueDO.class);
      vehicleInternalTemperatureValueDO.setInternalTemperature(request.newValue);
      ITCMSVehicleOutputsRequestHandler.updateVehicleStatusDOList(internalTemperatureStatus1,
          vehicleInternalTemperatureValueDO, request.getCarIndex());
      setInternalTemperatureStatus(internalTemperatureStatus1,
          builder -> request.getHandler().setInternalTemperatureStatus1(builder.build().toByteArray()));
    }
    catch (InstantiationException e)
    {
      Tracer.getInstance().info(e);
    }
  }

  private void setInternalTemperatureStatus(
      List<Entry<VehicleInternalTemperatureValueDO>> internalTemperatureValue,
      Consumer<TCMSProto.InternalTemperatureStatusList.Builder> builderConsumer)
  {
    TCMSProto.InternalTemperatureStatusList.Builder builder = TCMSProto.InternalTemperatureStatusList
        .newBuilder();

    InternalTemperatureStatusList.InternalTemperatureStatus.Builder vehicleBuilder = InternalTemperatureStatusList.InternalTemperatureStatus
        .newBuilder();

    internalTemperatureValue.forEach(internalTemperatureVal -> {
      vehicleBuilder.setCarIndex(internalTemperatureVal.getIndex());
      vehicleBuilder.setInternalTemperature(internalTemperatureVal.getData().getInternalTemperature());
      builder.addInternalTemperatureStatus(vehicleBuilder.build());
    });

    builderConsumer.accept(builder);
  }
}