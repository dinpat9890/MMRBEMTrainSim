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
import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.tcms.backend.app.io.handlers.IAppOutputsBrakeScreenHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.io.properties.ITCMSVehicleOutputsBrakeSystemProperties;
import com.sydac.mmrbem.tcms.common.data.Entry;
import com.sydac.mmrbem.tcms.common.data.VehicleBrakeCylinderPressureValueDO;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.BrakeCylinderPressureStatusList;
import com.sydac.mmrbem.tcms.common.utils.UnitConverterHelper;

/**
 * This class handles Brake Cylinder Pressure Status update from vehicle
 * outputs.
 * 
 */
public class BrakeCylinderPressureVehicleOutputRequestHandler implements
    ITCMSVehicleOutputsRequestHandler<TCMSOutputsBrakeSystemScreenImpl<Integer, IAppOutputsBrakeScreenHandler>>
{

  private List<Entry<VehicleBrakeCylinderPressureValueDO>> brakeCyclinderPressureValueList = new ArrayList<>();

  @Override
  public void handleRequest(TCMSOutputsBrakeSystemScreenImpl<Integer, IAppOutputsBrakeScreenHandler> request)
  {
    try
    {
      VehicleBrakeCylinderPressureValueDO vehicleBrakeCylinderPressureValueDO = ITCMSVehicleOutputsRequestHandler
          .getVehicleStatusDo(brakeCyclinderPressureValueList, request.getCarIndex(),
              VehicleBrakeCylinderPressureValueDO.class);
      setValue(request.getPropertyKey(), request.getNewValue(), vehicleBrakeCylinderPressureValueDO);
      ITCMSVehicleOutputsRequestHandler.updateVehicleStatusDOList(brakeCyclinderPressureValueList,
          vehicleBrakeCylinderPressureValueDO, request.getCarIndex());
      setBrakeCylinderPressureValueList(brakeCyclinderPressureValueList,
          builder -> request.getHandler().setBrakeCylinderPressureStatus(builder.build().toByteArray()));
    }
    catch (InstantiationException e)
    {
      Tracer.getInstance().info(e);
    }
  }

  private void setValue(PropertyKey<Integer> propertyKey, Integer newvalue,
      VehicleBrakeCylinderPressureValueDO vehicleBrakeCylinderPressureValueDO)
  {
    if (propertyKey.equals(ITCMSVehicleOutputsBrakeSystemProperties.BOGIE_1_BRAKE_CYLINDER_PRESSURE))
    {
      vehicleBrakeCylinderPressureValueDO.setBogie1BrakeCylinderPressureValue(newvalue);
    }
    else if (propertyKey.equals(ITCMSVehicleOutputsBrakeSystemProperties.BOGIE_2_BRAKE_CYLINDER_PRESSURE))
    {
      vehicleBrakeCylinderPressureValueDO.setBogie2BrakeCylinderPressureValue(newvalue);
    }
  }

  private void setBrakeCylinderPressureValueList(
      List<Entry<VehicleBrakeCylinderPressureValueDO>> brakeCyclinderPressureValueList,
      Consumer<TCMSProto.BrakeCylinderPressureStatusList.Builder> builderConsumer)
  {
    TCMSProto.BrakeCylinderPressureStatusList.Builder builder = TCMSProto.BrakeCylinderPressureStatusList
        .newBuilder();

    BrakeCylinderPressureStatusList.BrakeCylinderPressureStatus.Builder vehicleBuilder = BrakeCylinderPressureStatusList.BrakeCylinderPressureStatus
        .newBuilder();

    brakeCyclinderPressureValueList.forEach(brakeCyclinderPressureValueEntry -> {

      vehicleBuilder.setCarIndex(brakeCyclinderPressureValueEntry.getIndex());
      vehicleBuilder.setBogie1BrakeCylinderPressure(UnitConverterHelper.convertPascalToBar(
          brakeCyclinderPressureValueEntry.getData().getBogie1BrakeCylinderPressureValue()));
      vehicleBuilder.setBogie2BrakeCylinderPressure(UnitConverterHelper.convertPascalToBar(
          brakeCyclinderPressureValueEntry.getData().getBogie2BrakeCylinderPressureValue()));
      builder.addBrakeCylinderPressureStatus(vehicleBuilder.build());

    });

    builderConsumer.accept(builder);
  }
}