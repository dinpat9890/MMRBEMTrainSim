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
import com.sydac.mmrbem.tcms.common.data.VehicleBrakeStatusDO;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.ServiceBrkStatusList.ServiceBrkState;

/**
 * This class handles parking brake status update from vehicle outputs
 * 
 */
public class ServiceBrakeVehicleOutputsRequestHandler implements
    ITCMSVehicleOutputsRequestHandler<TCMSOutputsBrakeSystemScreenImpl<Integer, IAppOutputsBrakeScreenHandler>>
{

  protected final List<Entry<VehicleBrakeStatusDO>> serviceBrakeStatusList = new ArrayList<>();

  @Override
  public void handleRequest(TCMSOutputsBrakeSystemScreenImpl<Integer, IAppOutputsBrakeScreenHandler> request)
  {
    try
    {
      VehicleBrakeStatusDO vehicleServiceBrake1DO = ITCMSVehicleOutputsRequestHandler
          .getVehicleStatusDo(serviceBrakeStatusList, request.getCarIndex(), VehicleBrakeStatusDO.class);
      setStatus(request.getPropertyKey(), request.getNewValue(), vehicleServiceBrake1DO);
      ITCMSVehicleOutputsRequestHandler.updateVehicleStatusDOList(serviceBrakeStatusList,
          vehicleServiceBrake1DO, request.getCarIndex());
      setServiceBrakeStatus(serviceBrakeStatusList,
          builder -> request.getHandler().setServiceBrkStatus(builder.build().toByteArray()));
    }
    catch (InstantiationException e)
    {
      Tracer.getInstance().info(e);
    }
  }

  private void setStatus(PropertyKey<Integer> propertyKey, Integer newvalue,
      VehicleBrakeStatusDO vehicleParkingBrakeDO)
  {
    if (propertyKey.equals(ITCMSVehicleOutputsBrakeSystemProperties.BOGIE_1_SERV_BRAKE_FAULT))
    {
      vehicleParkingBrakeDO.setBrakeFaultState1(newvalue);
    }
    else if (propertyKey.equals(ITCMSVehicleOutputsBrakeSystemProperties.BOGIE_1_SERVICE_BRAKE_STATUS))
    {
      vehicleParkingBrakeDO.setBrakeAppliedState1(newvalue);
    }
    else if (propertyKey.equals(ITCMSVehicleOutputsBrakeSystemProperties.BOGIE_1_SERVICE_BRAKE_ISOLATED))
    {
      vehicleParkingBrakeDO.setBrakeIsolationState1(newvalue);
    }
    else if (propertyKey.equals(ITCMSVehicleOutputsBrakeSystemProperties.BOGIE_2_SERV_BRAKE_FAULT))
    {
      vehicleParkingBrakeDO.setBrakeFaultState2(newvalue);
    }
    else if (propertyKey.equals(ITCMSVehicleOutputsBrakeSystemProperties.BOGIE_2_SERVICE_BRAKE_STATUS))
    {
      vehicleParkingBrakeDO.setBrakeAppliedState2(newvalue);
    }
    else if (propertyKey.equals(ITCMSVehicleOutputsBrakeSystemProperties.BOGIE_2_SERVICE_BRAKE_ISOLATED))
    {
      vehicleParkingBrakeDO.setBrakeIsolationState2(newvalue);
    }
  }

  private void setServiceBrakeStatus(List<Entry<VehicleBrakeStatusDO>> serviceBrakeStatusList,
      Consumer<TCMSProto.ServiceBrkStatusList.Builder> builderConsumer)
  {
    TCMSProto.ServiceBrkStatusList.Builder builder = TCMSProto.ServiceBrkStatusList.newBuilder();
    TCMSProto.ServiceBrkStatusList.ServiceBrkStatus.Builder vehicleBuilder = TCMSProto.ServiceBrkStatusList.ServiceBrkStatus
        .newBuilder();

    VehicleBrakeStatusDO data;
    for (int index = 0; index < serviceBrakeStatusList.size(); index++)
    {
      data = serviceBrakeStatusList.get(index).getData();

      ServiceBrkState serviceBrakeState1 = getServicebrakeState1(data);
      ServiceBrkState serviceBrakeState2 = getServicebrakeState2(data);

      vehicleBuilder.setCarIndex(serviceBrakeStatusList.get(index).getIndex());
      vehicleBuilder.setServiceBrkState1(serviceBrakeState1);
      vehicleBuilder.setServiceBrkState2(serviceBrakeState2);
      builder.addServiceBrkStatus(vehicleBuilder.build());
    }
    builderConsumer.accept(builder);
  }

  private ServiceBrkState getServicebrakeState2(VehicleBrakeStatusDO data)
  {
    ServiceBrkState serviceBrakeState;
    if (data.getBrakeIsolationState2() == 1)
    {
      serviceBrakeState = ServiceBrkState.SERV_BRK_ISOLATED;
    }
    else  if (data.getBrakeFaultState2() == 1)
    {
      serviceBrakeState = ServiceBrkState.SERV_BRK_FAULTY;
    }
    else if (data.getBrakeAppliedState2() == 1)
    {
      serviceBrakeState = ServiceBrkState.SERV_BRK_APPLIED;
    }
    else if (data.getBrakeAppliedState2() == 0)
    {
      serviceBrakeState = ServiceBrkState.SERV_BRK_NOT_APPLIED;
    }
    else
    {
      serviceBrakeState = ServiceBrkState.SERV_BRK_UNKNOWN;
    }
    return serviceBrakeState;
  }

  private ServiceBrkState getServicebrakeState1(VehicleBrakeStatusDO data)
  {
    ServiceBrkState serviceBrakeState;
    if (data.getBrakeFaultState1() == 1)
    {
      serviceBrakeState = ServiceBrkState.SERV_BRK_FAULTY;
    }
    else if (data.getBrakeIsolationState1() == 1)
    {
      serviceBrakeState = ServiceBrkState.SERV_BRK_ISOLATED;
    }
    else if (data.getBrakeAppliedState1() == 1)
    {
      serviceBrakeState = ServiceBrkState.SERV_BRK_APPLIED;
    }
    else if (data.getBrakeAppliedState1() == 0)
    {
      serviceBrakeState = ServiceBrkState.SERV_BRK_NOT_APPLIED;
    }
    else
    {
      serviceBrakeState = ServiceBrkState.SERV_BRK_UNKNOWN;
    }
    return serviceBrakeState;
  }

}
