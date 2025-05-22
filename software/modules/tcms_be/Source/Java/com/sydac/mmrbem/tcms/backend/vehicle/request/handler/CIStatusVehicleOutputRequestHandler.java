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
import com.sydac.mmrbem.tcms.common.data.VehicleCIStatusDO;
import com.sydac.mmrbem.tcms.common.data.VehicleDetailModel;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.CIStatusList.CIState;
import com.sydac.mmrbem.tcms.common.state.TCMSConstants;

/**
 * This class handles Propulsion Status update from vehicle outputs.
 * 
 */
public class CIStatusVehicleOutputRequestHandler implements
    ITCMSVehicleOutputsRequestHandler<TCMSOutputsTrainViewScreenImpl<Integer, IAppOutputsOperationScreenHandler>>
{

  private List<Entry<VehicleCIStatusDO>> cIStatusList = new ArrayList<>();

  @Override
  public void handleRequest(
      TCMSOutputsTrainViewScreenImpl<Integer, IAppOutputsOperationScreenHandler> request)
  {
    try
    {

      VehicleCIStatusDO ciStatusDO = ITCMSVehicleOutputsRequestHandler.getVehicleStatusDo(cIStatusList,
          request.getCarIndex(), VehicleCIStatusDO.class);
      setStatus(request.getPropertyKey(), request.getNewValue(), ciStatusDO);
      ITCMSVehicleOutputsRequestHandler.updateVehicleStatusDOList(cIStatusList, ciStatusDO,
          request.getCarIndex());
      setCIStatus(cIStatusList, request.getVehicleDetailModelList(),
          builder -> request.getHandler().setCiStatus(builder.build().toByteArray()));
    }
    catch (InstantiationException e)
    {
      Tracer.getInstance().info(e);
    }
  }

  private void setStatus(PropertyKey<Integer> propertyKey, Integer newvalue,
      VehicleCIStatusDO propulsionStatusDO)
  {

    if (propertyKey.equals(ITCMSVehicleOutputsOperationScreenProperties.CI_ISOLATED))
    {
      propulsionStatusDO.setCiIsolated(newvalue);
    }else if (propertyKey.equals(ITCMSVehicleOutputsOperationScreenProperties.CI_FAULT))
    {
        propulsionStatusDO.setCiFault(newvalue);
      }
    else if (propertyKey.equals(ITCMSVehicleOutputsOperationScreenProperties.CI_STATUS))
    {
      propulsionStatusDO.setCiState(newvalue);
    }

  }

  private void setCIStatus(List<Entry<VehicleCIStatusDO>> ciStatusList,
      List<VehicleDetailModel> vehicleDetailModelList,
      Consumer<TCMSProto.CIStatusList.Builder> builderConsumer)
  {
    TCMSProto.CIStatusList.Builder builder = TCMSProto.CIStatusList.newBuilder();
    TCMSProto.CIStatusList.CIStatus.Builder vehicleBuilder = TCMSProto.CIStatusList.CIStatus.newBuilder();

    VehicleCIStatusDO data;

    for (int index = 0; index < ciStatusList.size(); index++)
    {
      int carIndex = ciStatusList.get(index).getIndex();
      CIState state = CIState.CI_OFF;
      if (vehicleDetailModelList != null && vehicleDetailModelList.size() > carIndex)
      {
        String carClassCode = vehicleDetailModelList.get(carIndex).getCarClassCode();
        if (TCMSConstants.DM_CAR.equals(carClassCode) || TCMSConstants.M_CAR.equals(carClassCode))
        {
          data = ciStatusList.get(index).getData();
          if (data.getCiIsolated() == 1)
          {
            state = CIState.CI_ISOLATED;
          }
          else if (data.getCiFault() == 1)
          {
            state = CIState.CI_FAULTY;
          }
          else if (data.getCiState() == 1)
          {
            state = CIState.CI_ACTIVE;
          }
          else
          {
            state = CIState.CI_OFF;
          }
        }
      }

      vehicleBuilder.setCarIndex(carIndex);
      vehicleBuilder.setCIState(state);
      builder.addCIStatus(vehicleBuilder.build());
    }
    builderConsumer.accept(builder);
  }
}