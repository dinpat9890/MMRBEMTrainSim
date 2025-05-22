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
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.ParkingBrakeStatusList;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.ParkingBrakeStatusList.ParkingBrakeState;

/**
 * This class handles Service Brake Status update from vehicle outputs.
 * 
 */
public class ParkBrakeStatusVehicleOutputRequestHandler implements
    ITCMSVehicleOutputsRequestHandler<TCMSOutputsTrainViewScreenImpl<Integer, IAppOutputsOperationScreenHandler>>
{

  private List<Entry<VehicleBrakeStatusDO>> parkBrakStatusList = new ArrayList<>();

  @Override
  public void handleRequest(
      TCMSOutputsTrainViewScreenImpl<Integer, IAppOutputsOperationScreenHandler> request)
  {
    try
    {
      VehicleBrakeStatusDO parkBrakeStatusDO = ITCMSVehicleOutputsRequestHandler
          .getVehicleStatusDo(parkBrakStatusList, request.getCarIndex(), VehicleBrakeStatusDO.class);
      setStatus(request.getPropertyKey(), request.getNewValue(), parkBrakeStatusDO);
      ITCMSVehicleOutputsRequestHandler.updateVehicleStatusDOList(parkBrakStatusList, parkBrakeStatusDO,
          request.getCarIndex());
      setParkingBrakeStatus(parkBrakStatusList,
          builder -> request.getHandler().setParkingBrakeStatus(builder.build().toByteArray()));
    }
    catch (InstantiationException e)
    {
      Tracer.getInstance().info(e);
    }
  }

  private void setStatus(PropertyKey<Integer> propertyKey, Integer newvalue,
      VehicleBrakeStatusDO parkBrakeStatusDO)
  {
    if (propertyKey.equals(ITCMSVehicleOutputsOperationScreenProperties.PARK_BRAKE_ISOLATED))
    {
      parkBrakeStatusDO.setBrakeIsolationState1(newvalue);
    }
    else if (propertyKey.equals(ITCMSVehicleOutputsOperationScreenProperties.PARK_BRAKE_APPLIED))
    {
      parkBrakeStatusDO.setBrakeAppliedState1(newvalue);
    }
  }

  private void setParkingBrakeStatus(List<Entry<VehicleBrakeStatusDO>> parkBrakeStatusList,
      Consumer<TCMSProto.ParkingBrakeStatusList.Builder> builderConsumer)
  {
    TCMSProto.ParkingBrakeStatusList.Builder builder = TCMSProto.ParkingBrakeStatusList.newBuilder();

    ParkingBrakeStatusList.ParkingBrakeStatus.Builder vehicleBuilder = ParkingBrakeStatusList.ParkingBrakeStatus
        .newBuilder();
    VehicleBrakeStatusDO data;
    ParkingBrakeState state;
    for (int index = 0; index < parkBrakeStatusList.size(); index++)
    {
      data = parkBrakeStatusList.get(index).getData();
      if (data.getBrakeIsolationState1() == 1)
      {
        state = ParkingBrakeState.ISOLATED;
      }
      else if (data.getBrakeAppliedState1() == 1)
      {
        state = ParkingBrakeState.APPLIED;
      }
      else if (data.getBrakeAppliedState1() == 0)
      {
        state = ParkingBrakeState.NOT_APPLIED;
      }
      else
      {
        state = ParkingBrakeState.UNKNOWN;
      }
      vehicleBuilder.setCarIndex(parkBrakeStatusList.get(index).getIndex());
      vehicleBuilder.setParkingBrakeState(state);
      builder.addParkingBrakeStatus(vehicleBuilder.build());
    }
    builderConsumer.accept(builder);
  }
}