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
import com.sydac.mmrbem.tcms.common.data.VehicleDetailModel;
import com.sydac.mmrbem.tcms.common.data.VehicleTrainLineStatusDO;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.TrainLineStatusList.TrainLineState;
import com.sydac.mmrbem.tcms.common.state.TCMSConstants;

/**
 * This class handles parking brake status update from vehicle outputs
 * 
 */
public class TrainLineVehicleOutputsRequestHandler implements
    ITCMSVehicleOutputsRequestHandler<TCMSOutputsBrakeSystemScreenImpl<Integer, IAppOutputsBrakeScreenHandler>>
{

  protected final List<Entry<VehicleTrainLineStatusDO>> trainLineStatusList = new ArrayList<>();

  @Override
  public void handleRequest(TCMSOutputsBrakeSystemScreenImpl<Integer, IAppOutputsBrakeScreenHandler> request)
  {
    try
    {
      VehicleTrainLineStatusDO vehicleTrainLineStatusDO = ITCMSVehicleOutputsRequestHandler
          .getVehicleStatusDo(trainLineStatusList, request.getCarIndex(), VehicleTrainLineStatusDO.class);
      setStatus(request.getPropertyKey(), request.getNewValue(), vehicleTrainLineStatusDO);
      ITCMSVehicleOutputsRequestHandler.updateVehicleStatusDOList(trainLineStatusList,
          vehicleTrainLineStatusDO, request.getCarIndex());
      setTrainLineStatus(trainLineStatusList, request.getVehicleDetailModelList(),
          builder -> request.getHandler().setTrainLineStatus(builder.build().toByteArray()));
    }
    catch (InstantiationException e)
    {
      Tracer.getInstance().info(e);
    }
  }

  private void setStatus(PropertyKey<Integer> propertyKey, Integer newvalue,
      VehicleTrainLineStatusDO vehicleParkingBrakeDO)
  {
    if (propertyKey.equals(ITCMSVehicleOutputsBrakeSystemProperties.BRAKE_TRAIN_LINE_STATUS))
    {
      vehicleParkingBrakeDO.setBrakeTrainLineEnergized(newvalue);
    }
    else if (propertyKey.equals(ITCMSVehicleOutputsBrakeSystemProperties.MOTOR_TRAIN_LINE_STATUS))
    {
      vehicleParkingBrakeDO.setMotorTrainLineEnergized(newvalue);
    }
  }

  private void setTrainLineStatus(List<Entry<VehicleTrainLineStatusDO>> trainLineStatusList,
      List<VehicleDetailModel> vehicleDetailModelList,
      Consumer<TCMSProto.TrainLineStatusList.Builder> builderConsumer)
  {
    TCMSProto.TrainLineStatusList.Builder builder = TCMSProto.TrainLineStatusList.newBuilder();
    TCMSProto.TrainLineStatusList.TrainLineStatus.Builder vehicleBuilder = TCMSProto.TrainLineStatusList.TrainLineStatus
        .newBuilder();

    VehicleTrainLineStatusDO data;
    for (int index = 0; index < trainLineStatusList.size(); index++)
    {
      int carIndex = trainLineStatusList.get(index).getIndex();
      TrainLineState brakeTrainLineState = TrainLineState.TRN_LINE_UNKNOWN;
      TrainLineState motorTrainLineState = TrainLineState.TRN_LINE_UNKNOWN;

      if (vehicleDetailModelList != null && vehicleDetailModelList.size() > carIndex)
      {
        String carClassCode = vehicleDetailModelList.get(carIndex).getCarClassCode();
        if (TCMSConstants.DM_CAR.equals(carClassCode))
        {
          data = trainLineStatusList.get(index).getData();

          brakeTrainLineState = getBrakeTrainLineState(data);
          motorTrainLineState = getMotorTrainLineState(data);
        }
      }
      vehicleBuilder.setCarIndex(trainLineStatusList.get(index).getIndex());
      vehicleBuilder.setBrakeTrainLineState(brakeTrainLineState);
      vehicleBuilder.setMotorTrainLineState(motorTrainLineState);
      builder.addTrainLineStatus(vehicleBuilder.build());
    }
    builderConsumer.accept(builder);
  }

  private TrainLineState getBrakeTrainLineState(VehicleTrainLineStatusDO data)
  {
    TrainLineState brakeTrainLineState;
    if (data.getBrakeTrainLineEnergized() == 1)
    {
      brakeTrainLineState = TrainLineState.TRN_LINE_ENERGIZED;
    }
    else if (data.getBrakeTrainLineEnergized() == 0)
    {
      brakeTrainLineState = TrainLineState.TRN_LINE_NOT_ENERGIZED;
    }
    else
    {
      brakeTrainLineState = TrainLineState.TRN_LINE_UNKNOWN;
    }
    return brakeTrainLineState;
  }

  private TrainLineState getMotorTrainLineState(VehicleTrainLineStatusDO data)
  {
    TrainLineState motTrainLineState;
    if (data.getMotorTrainLineEnergized() == 1)
    {
      motTrainLineState = TrainLineState.TRN_LINE_ENERGIZED;
    }
    else if (data.getMotorTrainLineEnergized() == 0)
    {
      motTrainLineState = TrainLineState.TRN_LINE_NOT_ENERGIZED;
    }
    else
    {
      motTrainLineState = TrainLineState.TRN_LINE_UNKNOWN;
    }
    return motTrainLineState;
  }

}
