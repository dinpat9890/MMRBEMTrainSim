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
import com.sydac.mmrbem.tcms.backend.app.io.handlers.IAppOutputsBrakeScreenHandler;
import com.sydac.mmrbem.tcms.common.data.Entry;
import com.sydac.mmrbem.tcms.common.data.VehicleAirSuspensionPressureValueDO;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.AirSuspensionPressureStatusList;
import com.sydac.mmrbem.tcms.common.utils.UnitConverterHelper;

/**
 * This class handles Air Suspension Pressure Status update from vehicle
 * outputs.
 * 
 */
public class AirSuspensionPressureVehicleOutputRequestHandler implements
    ITCMSVehicleOutputsRequestHandler<TCMSOutputsBrakeSystemScreenImpl<Integer, IAppOutputsBrakeScreenHandler>>
{

  private List<Entry<VehicleAirSuspensionPressureValueDO>> airSuspensionPressureValueList = new ArrayList<>();

  @Override
  public void handleRequest(TCMSOutputsBrakeSystemScreenImpl<Integer, IAppOutputsBrakeScreenHandler> request)
  {
    try
    {
      VehicleAirSuspensionPressureValueDO vehicleAirSuspensionPressureValueDO = ITCMSVehicleOutputsRequestHandler
          .getVehicleStatusDo(airSuspensionPressureValueList, request.getCarIndex(),
              VehicleAirSuspensionPressureValueDO.class);
      vehicleAirSuspensionPressureValueDO.setAirSuspensionPressure(request.newValue);
      ITCMSVehicleOutputsRequestHandler.updateVehicleStatusDOList(airSuspensionPressureValueList,
          vehicleAirSuspensionPressureValueDO, request.getCarIndex());
      setAirSuspensionPressureValueList(airSuspensionPressureValueList,
          builder -> request.getHandler().setAirSuspensionPressureStatus(builder.build().toByteArray()));
    }
    catch (InstantiationException e)
    {
      Tracer.getInstance().info(e);
    }
  }

  private void setAirSuspensionPressureValueList(
      List<Entry<VehicleAirSuspensionPressureValueDO>> airSuspensionPressureValueList,
      Consumer<TCMSProto.AirSuspensionPressureStatusList.Builder> builderConsumer)
  {
    TCMSProto.AirSuspensionPressureStatusList.Builder builder = TCMSProto.AirSuspensionPressureStatusList
        .newBuilder();

    AirSuspensionPressureStatusList.AirSuspensionPressureStatus.Builder vehicleBuilder = AirSuspensionPressureStatusList.AirSuspensionPressureStatus
        .newBuilder();

    {
      airSuspensionPressureValueList.forEach(airSuspensionPressureValueEntry -> {

        vehicleBuilder.setCarIndex(airSuspensionPressureValueEntry.getIndex());
        vehicleBuilder.setAirSuspensionPressure(UnitConverterHelper
            .convertPascalToBar(airSuspensionPressureValueEntry.getData().getAirSuspensionPressure()));
        builder.addAirSuspensionPressureStatus(vehicleBuilder.build());

      });
    }

    builderConsumer.accept(builder);
  }
}