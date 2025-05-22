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
import com.sydac.mmrbem.tcms.common.data.VehicleDetailModel;
import com.sydac.mmrbem.tcms.common.data.VehiclePropulsionStatusDO;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.PropulsionStatusList;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.PropulsionStatusList.PropulsionState;
import com.sydac.mmrbem.tcms.common.state.TCMSConstants;

/**
 * This class handles Propulsion Status update from vehicle outputs.
 * 
 */
public class PropulsionStatusVehicleOutputRequestHandler implements
    ITCMSVehicleOutputsRequestHandler<TCMSOutputsTrainViewScreenImpl<Integer, IAppOutputsOperationScreenHandler>>
{

  private List<Entry<VehiclePropulsionStatusDO>> propulsionStatusList = new ArrayList<>();

  @Override
  public void handleRequest(
      TCMSOutputsTrainViewScreenImpl<Integer, IAppOutputsOperationScreenHandler> request)
  {
    try
    {
      VehiclePropulsionStatusDO propulsionStatusDO = ITCMSVehicleOutputsRequestHandler
          .getVehicleStatusDo(propulsionStatusList, request.getCarIndex(), VehiclePropulsionStatusDO.class);
      setStatus(request.getPropertyKey(), request.getNewValue(), propulsionStatusDO);
      ITCMSVehicleOutputsRequestHandler.updateVehicleStatusDOList(propulsionStatusList, propulsionStatusDO,
          request.getCarIndex());
      setPropulsionStatus(propulsionStatusList, request.getVehicleDetailModelList(),
          builder -> request.getHandler().setPropulsionStatus(builder.build().toByteArray()));
    }
    catch (InstantiationException e)
    {
      Tracer.getInstance().info(e);
    }
  }

  private void setStatus(PropertyKey<Integer> propertyKey, Integer newvalue,
      VehiclePropulsionStatusDO propulsionStatusDO)
  {
    if (propertyKey.equals(ITCMSVehicleOutputsOperationScreenProperties.PROPULSION_FAULT))
    {
      propulsionStatusDO.setPropulsionFault(newvalue);
    }
    else if (propertyKey.equals(ITCMSVehicleOutputsOperationScreenProperties.PROPULSION_ISOLATED))
    {
      propulsionStatusDO.setPropulsionIsolated(newvalue);
    }
    else if (propertyKey.equals(ITCMSVehicleOutputsOperationScreenProperties.PROPULSION_ACTIVE))
    {
      propulsionStatusDO.setPropulsionActive(newvalue);
    }
  }

  private void setPropulsionStatus(List<Entry<VehiclePropulsionStatusDO>> propulsionStatusList,
      List<VehicleDetailModel> vehicleDetailModelList,
      Consumer<TCMSProto.PropulsionStatusList.Builder> builderConsumer)
  {
    TCMSProto.PropulsionStatusList.Builder builder = TCMSProto.PropulsionStatusList.newBuilder();

    PropulsionStatusList.PropulsionStatus.Builder vehicleBuilder = PropulsionStatusList.PropulsionStatus
        .newBuilder();

    VehiclePropulsionStatusDO data;

    for (int index = 0; index < propulsionStatusList.size(); index++)
    {
      int carIndex = propulsionStatusList.get(index).getIndex();
      PropulsionState state = PropulsionState.UNKNOWN;
      if (vehicleDetailModelList != null && vehicleDetailModelList.size() > carIndex)
      {
        String carClassCode = vehicleDetailModelList.get(carIndex).getCarClassCode();
        if (TCMSConstants.DM_CAR.equals(carClassCode) || TCMSConstants.M_CAR.equals(carClassCode))
        {
          data = propulsionStatusList.get(index).getData();
          if (data.getPropulsionIsolated() == 1)
          {
            state = PropulsionState.ISOLATED;
          }
          else if (data.getPropulsionFault() == 1)
          {
            state = PropulsionState.FAULTY;
          }
          else if (data.getPropulsionActive() == 1)
          {
            state = PropulsionState.POWER_OR_BRAKE;
          }
          else if (data.getPropulsionActive() == 0)
          {
            state = PropulsionState.COASTING_OR_OFF;
          }
          else
          {
            state = PropulsionState.UNKNOWN;
          }
        }
      }

      vehicleBuilder.setCarIndex(carIndex);
      vehicleBuilder.setPropulsionState(state);
      builder.addPropulsionStatus(vehicleBuilder.build());
    }
    builderConsumer.accept(builder);
  }
}