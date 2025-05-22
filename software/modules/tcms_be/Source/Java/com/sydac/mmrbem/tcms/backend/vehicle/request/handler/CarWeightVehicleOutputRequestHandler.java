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
import com.sydac.mmrbem.tcms.common.data.VehicleCarWeightValueDO;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.CarWeightStatusList;
import com.sydac.mmrbem.tcms.common.utils.UnitConverterHelper;

/**
 * This class handles Car Weight Value update from vehicle outputs.
 * 
 */
public class CarWeightVehicleOutputRequestHandler implements
    ITCMSVehicleOutputsRequestHandler<TCMSOutputsBrakeSystemScreenImpl<Integer, IAppOutputsBrakeScreenHandler>>
{

  private List<Entry<VehicleCarWeightValueDO>> carWeightValueList = new ArrayList<>();

  @Override
  public void handleRequest(TCMSOutputsBrakeSystemScreenImpl<Integer, IAppOutputsBrakeScreenHandler> request)
  {
    try
    {
      VehicleCarWeightValueDO vehicleCarWeightValueDO = ITCMSVehicleOutputsRequestHandler
          .getVehicleStatusDo(carWeightValueList, request.getCarIndex(), VehicleCarWeightValueDO.class);
      vehicleCarWeightValueDO.setCarWeightValue(request.newValue);
      ITCMSVehicleOutputsRequestHandler.updateVehicleStatusDOList(carWeightValueList, vehicleCarWeightValueDO,
          request.getCarIndex());
      setCarWeightValueList(carWeightValueList,
          builder -> request.getHandler().setCarWeightStatus(builder.build().toByteArray()));
    }
    catch (InstantiationException e)
    {
      Tracer.getInstance().info(e);
    }
  }

  private void setCarWeightValueList(List<Entry<VehicleCarWeightValueDO>> carWeightValueList,
      Consumer<TCMSProto.CarWeightStatusList.Builder> builderConsumer)
  {
    TCMSProto.CarWeightStatusList.Builder builder = TCMSProto.CarWeightStatusList.newBuilder();

    CarWeightStatusList.CarWeightStatus.Builder vehicleBuilder = CarWeightStatusList.CarWeightStatus
        .newBuilder();

    {
      carWeightValueList.forEach(carWeightValueEntry -> {

        vehicleBuilder.setCarIndex(carWeightValueEntry.getIndex());
        vehicleBuilder.setCarWeight(
            UnitConverterHelper.getWeightInTon(carWeightValueEntry.getData().getCarWeightValue()));
        builder.addCarWeightStatus(vehicleBuilder.build());

      });
    }

    builderConsumer.accept(builder);
  }
}