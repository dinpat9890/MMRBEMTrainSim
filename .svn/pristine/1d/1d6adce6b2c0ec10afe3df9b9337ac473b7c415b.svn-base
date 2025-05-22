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
import com.sydac.mmrbem.tcms.common.data.VehicleMainPipePressureValueDO;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.MainPipePressureStatusList;
import com.sydac.mmrbem.tcms.common.utils.UnitConverterHelper;

/**
 * This class handles Main Pipe Pressure Status update from vehicle outputs.
 * 
 */
public class MainPipePressureVehicleOutputRequestHandler implements
    ITCMSVehicleOutputsRequestHandler<TCMSOutputsBrakeSystemScreenImpl<Integer, IAppOutputsBrakeScreenHandler>>
{

  private List<Entry<VehicleMainPipePressureValueDO>> mainPipePressureValueList = new ArrayList<>();

  @Override
  public void handleRequest(TCMSOutputsBrakeSystemScreenImpl<Integer, IAppOutputsBrakeScreenHandler> request)
  {
    try
    {
      VehicleMainPipePressureValueDO vehicleMainPipePressureValueDO = ITCMSVehicleOutputsRequestHandler
          .getVehicleStatusDo(mainPipePressureValueList, request.getCarIndex(),
              VehicleMainPipePressureValueDO.class);
      vehicleMainPipePressureValueDO.setMainPipePressure(request.newValue);
      ITCMSVehicleOutputsRequestHandler.updateVehicleStatusDOList(mainPipePressureValueList,
          vehicleMainPipePressureValueDO, request.getCarIndex());
      setMainPipepressureValueList(mainPipePressureValueList,
          builder -> request.getHandler().setMainPipePressureStatus(builder.build().toByteArray()));
    }
    catch (InstantiationException e)
    {
      Tracer.getInstance().info(e);
    }
  }

  private void setMainPipepressureValueList(
      List<Entry<VehicleMainPipePressureValueDO>> mainPipePressureValueList,
      Consumer<TCMSProto.MainPipePressureStatusList.Builder> builderConsumer)
  {
    TCMSProto.MainPipePressureStatusList.Builder builder = TCMSProto.MainPipePressureStatusList.newBuilder();

    MainPipePressureStatusList.MainPipePressureStatus.Builder vehicleBuilder = MainPipePressureStatusList.MainPipePressureStatus
        .newBuilder();

    {
      mainPipePressureValueList.forEach(mainPipePressureValueEntry -> {

        vehicleBuilder.setCarIndex(mainPipePressureValueEntry.getIndex());
        vehicleBuilder.setMainPipePressure(UnitConverterHelper
            .convertPascalToBar(mainPipePressureValueEntry.getData().getMainPipePressure()));
        builder.addMainPipePressureStatus(vehicleBuilder.build());

      });
    }

    builderConsumer.accept(builder);
  }
}