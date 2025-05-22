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
import com.sydac.mmrbem.tcms.common.data.TrainDirectionStatusDO;
import com.sydac.mmrbem.tcms.common.data.TrainSideViewStatusDO;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.DriverCabDirectionList;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.DriverCabDirectionList.DirectionState;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.TrainSideViewStatusList;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.TrainSideViewStatusList.ActiveCabState;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.TrainSideViewStatusList.BoogieIsolationState;

/**
 * This class handles Train cab active and boogie isolation status update from
 * vehicle outputs.
 * 
 */
public class TrainSideViewVehicleOutputRequestHandler implements
    ITCMSVehicleOutputsRequestHandler<TCMSOutputsTrainViewScreenImpl<Integer, IAppOutputsOperationScreenHandler>>
{

  private List<Entry<TrainSideViewStatusDO>> trainSideViewStatusList = new ArrayList<>();

  private List<Entry<TrainDirectionStatusDO>> trainDirectionStatusList = new ArrayList<>();

  @Override
  public void handleRequest(
      TCMSOutputsTrainViewScreenImpl<Integer, IAppOutputsOperationScreenHandler> request)
  {
    try
    {
      TrainSideViewStatusDO trainSideViewStatusDO = ITCMSVehicleOutputsRequestHandler
          .getVehicleStatusDo(trainSideViewStatusList, request.getCarIndex(), TrainSideViewStatusDO.class);
      setStatus(request.getPropertyKey(), request.getNewValue(), trainSideViewStatusDO);
      ITCMSVehicleOutputsRequestHandler.updateVehicleStatusDOList(trainSideViewStatusList,
          trainSideViewStatusDO, request.getCarIndex());
      setTrainSideViewStatus(trainSideViewStatusList,
          builder -> request.getHandler().setTrainSideViewStatus(builder.build().toByteArray()));

      TrainDirectionStatusDO directionStatusDO = ITCMSVehicleOutputsRequestHandler
          .getVehicleStatusDo(trainDirectionStatusList, request.getCarIndex(), TrainDirectionStatusDO.class);
      setDirectionStatus(request.getPropertyKey(), request.getNewValue(), directionStatusDO);
      ITCMSVehicleOutputsRequestHandler.updateVehicleStatusDOList(trainDirectionStatusList, directionStatusDO,
          request.getCarIndex());
      setTrainDirectionStatus(trainDirectionStatusList,
          builder -> request.getHandler().setDriverCabDirection(builder.build().toByteArray()));
    }
    catch (InstantiationException e)
    {
      Tracer.getInstance().info(e);
    }
  }

  private void setStatus(PropertyKey<Integer> propertyKey, Integer newvalue,
      TrainSideViewStatusDO sideViewStatusDO)
  {
    if (propertyKey.equals(ITCMSVehicleOutputsOperationScreenProperties.CAB_ACTIVE))
    {
      sideViewStatusDO.setActiveCabState(ActiveCabState.forNumber(newvalue));
    }
    else if (propertyKey.equals(ITCMSVehicleOutputsOperationScreenProperties.BOGIE_1_ISOLATION_STATUS))
    {
      sideViewStatusDO.setBogie1IsolationState(BoogieIsolationState.forNumber(newvalue));
    }
    else if (propertyKey.equals(ITCMSVehicleOutputsOperationScreenProperties.BOGIE_2_ISOLATION_STATUS))
    {
      sideViewStatusDO.setBogie2IsolationState(BoogieIsolationState.forNumber(newvalue));
    }
  }

  private void setDirectionStatus(PropertyKey<Integer> propertyKey, Integer newvalue,
      TrainDirectionStatusDO directionStatusDO)
  {
    if (propertyKey.equals(ITCMSVehicleOutputsOperationScreenProperties.FORWARD_DIRECTION))
    {
      directionStatusDO.setForwardDirection(newvalue);
    }
    else if (propertyKey.equals(ITCMSVehicleOutputsOperationScreenProperties.REVERSE_DIRECTION))
    {
      directionStatusDO.setReverseDirection(newvalue);
    }
  }

  private void setTrainSideViewStatus(List<Entry<TrainSideViewStatusDO>> sideViewStatusDOList,
      Consumer<TCMSProto.TrainSideViewStatusList.Builder> builderConsumer)
  {
    TCMSProto.TrainSideViewStatusList.Builder builder = TCMSProto.TrainSideViewStatusList.newBuilder();

    TrainSideViewStatusList.TrainSideViewStatus.Builder vehicleBuilder = TCMSProto.TrainSideViewStatusList.TrainSideViewStatus
        .newBuilder();
    for (int index = 0; index < sideViewStatusDOList.size(); index++)
    {
      TrainSideViewStatusDO data = sideViewStatusDOList.get(index).getData();
      vehicleBuilder.setCarIndex(sideViewStatusDOList.get(index).getIndex());
      vehicleBuilder.setActiveCabState(data.getActiveCabState());
      vehicleBuilder.setBoogie1IsolationState(data.getBogie1IsolationState());
      vehicleBuilder.setBoogie2IsolationState(data.getBogie2IsolationState());
      builder.addTrainSideViewStatus(vehicleBuilder.build());
    }
    builderConsumer.accept(builder);
  }

  private void setTrainDirectionStatus(List<Entry<TrainDirectionStatusDO>> directionStatusDOList,
      Consumer<TCMSProto.DriverCabDirectionList.Builder> builderConsumer)
  {
    TCMSProto.DriverCabDirectionList.Builder builder = TCMSProto.DriverCabDirectionList.newBuilder();

    DriverCabDirectionList.DriverCabDirection.Builder vehicleBuilder = TCMSProto.DriverCabDirectionList.DriverCabDirection
        .newBuilder();
    DirectionState state;
    TrainDirectionStatusDO data;
    int firstCarIndex = 0;
    int lastCarIndex = directionStatusDOList.size() - 1;
    DirectionState lastCarDirection = DirectionState.NO_DIRECTION;

    for (int index = 0; index < directionStatusDOList.size(); index++)
    {
      data = directionStatusDOList.get(index).getData();
      if (data.getForwardDirection() == 1)
      {
        state = DirectionState.FORWARD;
      }
      else if (data.getReverseDirection() == 1)
      {
        state = DirectionState.BACKWARD;
      }
      else
      {
        state = DirectionState.NO_DIRECTION;
      }

      if (index == firstCarIndex)
      {
        if (directionStatusDOList.get(lastCarIndex).getData().getReverseDirection() == 1
            || directionStatusDOList.get(firstCarIndex).getData().getForwardDirection() == 1)
        {
          state = DirectionState.FORWARD;
          lastCarDirection = DirectionState.NO_DIRECTION;
        }
        else if (directionStatusDOList.get(firstCarIndex).getData().getForwardDirection() == 0)
        {
          state = DirectionState.NO_DIRECTION;
        }
      }
      if (index == lastCarIndex)
      {
        state = lastCarDirection;
        if (directionStatusDOList.get(firstCarIndex).getData().getReverseDirection() == 1)
        {
          state = DirectionState.BACKWARD;
        }
        else if (directionStatusDOList.get(lastCarIndex).getData().getForwardDirection() == 1)
        {
          state = DirectionState.BACKWARD;
        }
      }

      vehicleBuilder.setCarIndex(directionStatusDOList.get(index).getIndex());
      vehicleBuilder.setDirectionState(state);
      builder.addDriverCabDirection(vehicleBuilder.build());
    }
    builderConsumer.accept(builder);
  }
}