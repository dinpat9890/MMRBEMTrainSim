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
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.ParkingBrkStatusList.ParkingBrkState;

/**
 * This class handles parking brake status update from vehicle outputs
 * 
 */
public class ParkingBrakeVehicleOutputsRequestHandler implements
    ITCMSVehicleOutputsRequestHandler<TCMSOutputsBrakeSystemScreenImpl<Integer, IAppOutputsBrakeScreenHandler>>
{

  protected final List<Entry<VehicleBrakeStatusDO>> parkingBrakeStatusList = new ArrayList<>();

  @Override
  public void handleRequest(TCMSOutputsBrakeSystemScreenImpl<Integer, IAppOutputsBrakeScreenHandler> request)
  {
    try
    {
      VehicleBrakeStatusDO vehicleServiceBrakeDO = ITCMSVehicleOutputsRequestHandler
          .getVehicleStatusDo(parkingBrakeStatusList, request.getCarIndex(), VehicleBrakeStatusDO.class);
      setStatus(request.getPropertyKey(), request.getNewValue(), vehicleServiceBrakeDO);
      ITCMSVehicleOutputsRequestHandler.updateVehicleStatusDOList(parkingBrakeStatusList,
          vehicleServiceBrakeDO, request.getCarIndex());
      setParkingBrakeStatus(parkingBrakeStatusList,
          builder -> request.getHandler().setParkingBrkStatus(builder.build().toByteArray()));
    }
    catch (InstantiationException e)
    {
      Tracer.getInstance().info(e);
    }
  }

  private void setStatus(PropertyKey<Integer> propertyKey, Integer newvalue,
      VehicleBrakeStatusDO vehicleParkingBrakeDO)
  {
    if (propertyKey.equals(ITCMSVehicleOutputsBrakeSystemProperties.BOGIE_1_PARKING_BRAKE_STATUS))
    {
      vehicleParkingBrakeDO.setBrakeAppliedState1(newvalue);
    }
    else if (propertyKey.equals(ITCMSVehicleOutputsBrakeSystemProperties.BOGIE_1_PARKING_BRAKE_ISOLATED))
    {
      vehicleParkingBrakeDO.setBrakeIsolationState1(newvalue);
    }
    else if (propertyKey.equals(ITCMSVehicleOutputsBrakeSystemProperties.BOGIE_2_PARKING_BRAKE_STATUS))
    {
      vehicleParkingBrakeDO.setBrakeAppliedState2(newvalue);
    }
    else if (propertyKey.equals(ITCMSVehicleOutputsBrakeSystemProperties.BOGIE_2_PARKING_BRAKE_ISOLATED))
    {
      vehicleParkingBrakeDO.setBrakeIsolationState2(newvalue);
    }
  }

  private void setParkingBrakeStatus(List<Entry<VehicleBrakeStatusDO>> parkingBrakeStatusList,
      Consumer<TCMSProto.ParkingBrkStatusList.Builder> builderConsumer)
  {
    TCMSProto.ParkingBrkStatusList.Builder builder = TCMSProto.ParkingBrkStatusList.newBuilder();
    TCMSProto.ParkingBrkStatusList.ParkingBrkStatus.Builder vehicleBuilder = TCMSProto.ParkingBrkStatusList.ParkingBrkStatus
        .newBuilder();

    VehicleBrakeStatusDO data;
    for (int index = 0; index < parkingBrakeStatusList.size(); index++)
    {
      data = parkingBrakeStatusList.get(index).getData();

      ParkingBrkState parkingBrakeState1 = getParkingBrakeState1(data);
      ParkingBrkState parkingBrakeState2 = getParkingBrakeState2(data);

      vehicleBuilder.setCarIndex(parkingBrakeStatusList.get(index).getIndex());
      vehicleBuilder.setParkingBrkState1(parkingBrakeState1);
      vehicleBuilder.setParkingBrkState2(parkingBrakeState2);
      builder.addParkingBrkStatus(vehicleBuilder.build());
    }
    builderConsumer.accept(builder);
  }

  private ParkingBrkState getParkingBrakeState2(VehicleBrakeStatusDO data)
  {
    ParkingBrkState parkingBrakeState;

    if (data.getBrakeIsolationState2() == 1)
    {
      parkingBrakeState = ParkingBrkState.PRKG_BRK_ISOLATED;
    }
    else if (data.getBrakeAppliedState2() == 1)
    {
      parkingBrakeState = ParkingBrkState.PRKG_BRK_APPLIED;
    }
    else if (data.getBrakeAppliedState2() == 0)
    {
      parkingBrakeState = ParkingBrkState.PRKG_BRK_NOT_APPLIED;
    }
    else
    {
      parkingBrakeState = ParkingBrkState.PRKG_BRK_UNKNOWN;
    }

    return parkingBrakeState;
  }

  private ParkingBrkState getParkingBrakeState1(VehicleBrakeStatusDO data)
  {
    ParkingBrkState parkingBrakeState;

    if (data.getBrakeIsolationState1() == 1)
    {
      parkingBrakeState = ParkingBrkState.PRKG_BRK_ISOLATED;
    }
    else if (data.getBrakeAppliedState1() == 1)
    {
      parkingBrakeState = ParkingBrkState.PRKG_BRK_APPLIED;
    }
    else if (data.getBrakeAppliedState1() == 0)
    {
      parkingBrakeState = ParkingBrkState.PRKG_BRK_NOT_APPLIED;
    }
    else
    {
      parkingBrakeState = ParkingBrkState.PRKG_BRK_UNKNOWN;
    }

    return parkingBrakeState;
  }
}
