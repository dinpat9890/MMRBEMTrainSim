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
import com.sydac.mmrbem.tcms.backend.app.io.handlers.IAppOutputsOperationScreenHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.io.properties.ITCMSVehicleOutputsOperationScreenProperties;
import com.sydac.mmrbem.tcms.common.data.Entry;
import com.sydac.mmrbem.tcms.common.data.VehicleBrakeStatusDO;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.ServiceBrakeStatusList;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.ServiceBrakeStatusList.ServiceBrakeState;

/**
 * This class handles Service Brake Status update from vehicle outputs.
 * 
 */
public class ServiceBrakeStatusVehicleOutputRequestHandler implements
    ITCMSVehicleOutputsRequestHandler<TCMSOutputsTrainViewScreenImpl<Integer, IAppOutputsOperationScreenHandler>>
{

  private List<Entry<VehicleBrakeStatusDO>> serviceBrakStatusList = new ArrayList<>();

  @Override
  public void handleRequest(
      TCMSOutputsTrainViewScreenImpl<Integer, IAppOutputsOperationScreenHandler> request)
  {
    try
    {
      VehicleBrakeStatusDO serviceBrakeStatusDO = ITCMSVehicleOutputsRequestHandler
          .getVehicleStatusDo(serviceBrakStatusList, request.getCarIndex(), VehicleBrakeStatusDO.class);
      setStatus(request.getPropertyKey(), request.getNewValue(), serviceBrakeStatusDO);
      ITCMSVehicleOutputsRequestHandler.updateVehicleStatusDOList(serviceBrakStatusList, serviceBrakeStatusDO,
          request.getCarIndex());
      setServiceBrakeStatus(serviceBrakStatusList,
          builder -> request.getHandler().setServiceBrakeStatus(builder.build().toByteArray()));
    }
    catch (InstantiationException e)
    {
      Tracer.getInstance().info(e);
    }
  }

  private void setStatus(PropertyKey<Integer> propertyKey, Integer newvalue,
      VehicleBrakeStatusDO serviceBrakeStatusDO)
  {
    if (propertyKey.equals(ITCMSVehicleOutputsOperationScreenProperties.BOGIE_1_SERVICE_BRAKE_FAULT))
    {
      serviceBrakeStatusDO.setBrakeFaultState1(newvalue);
    }
    else if (propertyKey.equals(ITCMSVehicleOutputsOperationScreenProperties.BOGIE_2_SERVICE_BRAKE_FAULT))
    {
      serviceBrakeStatusDO.setBrakeFaultState2(newvalue);
    }
    else if (propertyKey.equals(ITCMSVehicleOutputsOperationScreenProperties.SERVICE_BRAKE_ACTIVE))
    {
      serviceBrakeStatusDO.setBrakeAppliedState1(newvalue);
    }
  }

  private void setServiceBrakeStatus(List<Entry<VehicleBrakeStatusDO>> serviceBrakeStatusList,
      Consumer<TCMSProto.ServiceBrakeStatusList.Builder> builderConsumer)
  {
    TCMSProto.ServiceBrakeStatusList.Builder builder = TCMSProto.ServiceBrakeStatusList.newBuilder();

    ServiceBrakeStatusList.ServiceBrakeStatus.Builder vehicleBuilder = ServiceBrakeStatusList.ServiceBrakeStatus
        .newBuilder();
    VehicleBrakeStatusDO data;
    ServiceBrakeState state;
    for (int index = 0; index < serviceBrakeStatusList.size(); index++)
    {
      data = serviceBrakeStatusList.get(index).getData();
      if (data.getBrakeFaultState1() == 1 || data.getBrakeFaultState2() == 1)
      {
        state = ServiceBrakeState.FAULTY;
      }
      else if (data.getBrakeAppliedState1() == 1)
      {
        state = ServiceBrakeState.APPLIED;
      }
      else if (data.getBrakeAppliedState1() == 0)
      {
        state = ServiceBrakeState.NOT_APPLIED;
      }
      else
      {
        state = ServiceBrakeState.UNKNOWN;
      }
      vehicleBuilder.setCarIndex(serviceBrakeStatusList.get(index).getIndex());
      vehicleBuilder.setServiceBrakeState(state);
      builder.addServiceBrakeStatus(vehicleBuilder.build());
    }
    builderConsumer.accept(builder);
  }
}