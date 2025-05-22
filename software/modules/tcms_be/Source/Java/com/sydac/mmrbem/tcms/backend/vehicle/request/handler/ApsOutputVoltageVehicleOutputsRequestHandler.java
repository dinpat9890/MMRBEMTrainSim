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
import com.sydac.mmrbem.tcms.backend.app.io.handlers.IAppOutputsApsScreenHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.io.properties.ITCMSVehicleOutputsAPSSystemProperties;
import com.sydac.mmrbem.tcms.common.data.Entry;
import com.sydac.mmrbem.tcms.common.data.VehicleApsOutputVoltageValueDO;
import com.sydac.mmrbem.tcms.common.data.VehicleDetailModel;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.APSOutputVoltageStatusList;
import com.sydac.mmrbem.tcms.common.state.ApplicationConstants;
import com.sydac.mmrbem.tcms.common.state.TCMSConstants;

/**
 * This class handles Output Voltage update from vehicle outputs
 * 
 */
public class ApsOutputVoltageVehicleOutputsRequestHandler implements
    ITCMSVehicleOutputsRequestHandler<TCMSOutputsApsSystemScreenImpl<Integer, IAppOutputsApsScreenHandler>>
{

  protected final List<Entry<VehicleApsOutputVoltageValueDO>> outputVoltageList = new ArrayList<>();

  @Override
  public void handleRequest(TCMSOutputsApsSystemScreenImpl<Integer, IAppOutputsApsScreenHandler> request)
  {
    try
    {
      VehicleApsOutputVoltageValueDO vehicleApsOutputVoltageValueDO = ITCMSVehicleOutputsRequestHandler
          .getVehicleStatusDo(outputVoltageList, request.getCarIndex(), VehicleApsOutputVoltageValueDO.class);
      setValue(request.getPropertyKey(), request.getNewValue(), vehicleApsOutputVoltageValueDO);
      ITCMSVehicleOutputsRequestHandler.updateVehicleStatusDOList(outputVoltageList,
          vehicleApsOutputVoltageValueDO, request.getCarIndex());
      setOutputVoltageList(outputVoltageList, request.getVehicleDetailModelList(),
          builder -> request.getHandler().setApsOutputVoltageStatus(builder.build().toByteArray()));
    }
    catch (InstantiationException e)
    {
      Tracer.getInstance().info(e);
    }
  }

  private void setValue(PropertyKey<Integer> propertyKey, Integer newvalue,
      VehicleApsOutputVoltageValueDO vehicleApsOutputVoltageValueDO)
  {
    if (propertyKey.equals(ITCMSVehicleOutputsAPSSystemProperties.APS_1_OUTPUT_VOLTAGE))
    {
      vehicleApsOutputVoltageValueDO.setOutputVoltage1(newvalue);
    }
    else if (propertyKey.equals(ITCMSVehicleOutputsAPSSystemProperties.APS_2_OUTPUT_VOLTAGE))
    {
      vehicleApsOutputVoltageValueDO.setOutputVoltage2(newvalue);
    }
  }

  private void setOutputVoltageList(List<Entry<VehicleApsOutputVoltageValueDO>> outputVoltageList,
      List<VehicleDetailModel> vehicleDetailModelList,
      Consumer<TCMSProto.APSOutputVoltageStatusList.Builder> builderConsumer)
  {
    TCMSProto.APSOutputVoltageStatusList.Builder builder = TCMSProto.APSOutputVoltageStatusList.newBuilder();

    APSOutputVoltageStatusList.APSOutputVoltageStatus.Builder vehicleBuilder = APSOutputVoltageStatusList.APSOutputVoltageStatus
        .newBuilder();

    for (int index = 0; index < outputVoltageList.size(); index++)
    {
      int carIndex = outputVoltageList.get(index).getIndex();
      int value1 = ApplicationConstants.VALUE_NOT_APPLICABLE;
      int value2 = ApplicationConstants.VALUE_NOT_APPLICABLE;
      if (vehicleDetailModelList != null && vehicleDetailModelList.size() > carIndex)
      {
        String carClassCode = vehicleDetailModelList.get(carIndex).getCarClassCode();
        if (TCMSConstants.T_CAR.equals(carClassCode))
        {
          value1 = outputVoltageList.get(carIndex).getData().getOutputVoltage1();
          value2 = outputVoltageList.get(carIndex).getData().getOutputVoltage2();
        }
      }
      vehicleBuilder.setCarIndex(carIndex);
      vehicleBuilder.setApsOutputVoltage1(value1);
      vehicleBuilder.setApsOutputVoltage2(value2);
      builder.addApsOutputVoltageStatus(vehicleBuilder.build());
    }
    builderConsumer.accept(builder);
  }
}
