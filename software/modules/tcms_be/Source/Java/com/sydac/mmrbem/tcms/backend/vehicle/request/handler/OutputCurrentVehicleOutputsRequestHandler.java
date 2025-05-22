/*
 * ==================================================================
 * 
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.tcms.backend.vehicle.request.handler;

import java.util.ArrayList;
import java.util.List;
import java.util.function.Consumer;

import com.sydac.common.log.Tracer;
import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.tcms.backend.app.io.handlers.IAppOutputsBatteryScreenHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.io.properties.ITCMSVehicleOutputsBatterySystemProperties;
import com.sydac.mmrbem.tcms.common.data.Entry;
import com.sydac.mmrbem.tcms.common.data.VehicleDetailModel;
import com.sydac.mmrbem.tcms.common.data.VehicleOutputCurrentValueDO;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.OutputCurrentStatusList;
import com.sydac.mmrbem.tcms.common.state.ApplicationConstants;
import com.sydac.mmrbem.tcms.common.state.TCMSConstants;

/**
 * This class handles Output Current update from vehicle outputs
 * 
 */
public class OutputCurrentVehicleOutputsRequestHandler implements
    ITCMSVehicleOutputsRequestHandler<TCMSOutputsBatterySystemScreenImpl<Integer, IAppOutputsBatteryScreenHandler>>
{

  protected final List<Entry<VehicleOutputCurrentValueDO>> outputCurrentList = new ArrayList<>();

  @Override
  public void handleRequest(
      TCMSOutputsBatterySystemScreenImpl<Integer, IAppOutputsBatteryScreenHandler> request)
  {
    try
    {
      VehicleOutputCurrentValueDO vehicleBcgOutputVoltageValueDO = ITCMSVehicleOutputsRequestHandler
          .getVehicleStatusDo(outputCurrentList, request.getCarIndex(), VehicleOutputCurrentValueDO.class);
      setValue(request.getPropertyKey(), request.getNewValue(), vehicleBcgOutputVoltageValueDO);
      ITCMSVehicleOutputsRequestHandler.updateVehicleStatusDOList(outputCurrentList,
          vehicleBcgOutputVoltageValueDO, request.getCarIndex());
      setOutputCurrentList(outputCurrentList, request.getVehicleDetailModelList(),
          builder -> request.getHandler().setOutputCurrentStatus(builder.build().toByteArray()));
    }
    catch (InstantiationException e)
    {
      Tracer.getInstance().info(e);
    }
  }

  private void setValue(PropertyKey<Integer> propertyKey, Integer newvalue,
      VehicleOutputCurrentValueDO vehicleBcgOutputVoltageValueDO)
  {
    if (propertyKey.equals(ITCMSVehicleOutputsBatterySystemProperties.BCG_1_OUTPUT_CURRENT))
    {
      vehicleBcgOutputVoltageValueDO.setOutputCurrent1(newvalue);
    }
    else if (propertyKey.equals(ITCMSVehicleOutputsBatterySystemProperties.BCG_2_OUTPUT_CURRENT))
    {
      vehicleBcgOutputVoltageValueDO.setOutputCurrent2(newvalue);
    }
  }

  private void setOutputCurrentList(List<Entry<VehicleOutputCurrentValueDO>> outputCurrentList,
      List<VehicleDetailModel> vehicleDetailModelList,
      Consumer<TCMSProto.OutputCurrentStatusList.Builder> builderConsumer)
  {
    TCMSProto.OutputCurrentStatusList.Builder builder = TCMSProto.OutputCurrentStatusList.newBuilder();

    OutputCurrentStatusList.OutputCurrent.Builder vehicleBuilder = OutputCurrentStatusList.OutputCurrent
        .newBuilder();

    for (int index = 0; index < outputCurrentList.size(); index++)
    {
      int carIndex = outputCurrentList.get(index).getIndex();
      int value1 = ApplicationConstants.VALUE_NOT_APPLICABLE;
      int value2 = ApplicationConstants.VALUE_NOT_APPLICABLE;
      if (vehicleDetailModelList != null && vehicleDetailModelList.size() > carIndex)
      {
        String carClassCode = vehicleDetailModelList.get(carIndex).getCarClassCode();
        if (TCMSConstants.M_CAR.equals(carClassCode))
        {
          value1 = outputCurrentList.get(carIndex).getData().getOutputCurrent1();
          value2 = outputCurrentList.get(carIndex).getData().getOutputCurrent2();
        }
      }
      vehicleBuilder.setCarIndex(carIndex);
      vehicleBuilder.setOutputCurrent1(value1);
      vehicleBuilder.setOutputCurrent2(value2);
      builder.addOutputCurrent(vehicleBuilder.build());
    }
    builderConsumer.accept(builder);
  }
}
