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
import com.sydac.mmrbem.tcms.common.data.VehicleApsControlUnitStatusDO;
import com.sydac.mmrbem.tcms.common.data.VehicleDetailModel;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.APSControlUnitStatusList.APSControlUnitState;
import com.sydac.mmrbem.tcms.common.state.TCMSConstants;

/**
 * This class handles APS Control unit Status update from vehicle outputs
 * 
 */
public class ApsControlUnitStatusVehicleOutputsRequestHandler implements
    ITCMSVehicleOutputsRequestHandler<TCMSOutputsApsSystemScreenImpl<Integer, IAppOutputsApsScreenHandler>>
{

  protected final List<Entry<VehicleApsControlUnitStatusDO>> apsControlUnitStatus = new ArrayList<>();

  @Override
  public void handleRequest(TCMSOutputsApsSystemScreenImpl<Integer, IAppOutputsApsScreenHandler> request)
  {
    try
    {
      VehicleApsControlUnitStatusDO vehicleApsControlUnitStatusDO = ITCMSVehicleOutputsRequestHandler
          .getVehicleStatusDo(apsControlUnitStatus, request.getCarIndex(),
              VehicleApsControlUnitStatusDO.class);
      setStatus(request.getPropertyKey(), request.getNewValue(), vehicleApsControlUnitStatusDO);
      ITCMSVehicleOutputsRequestHandler.updateVehicleStatusDOList(apsControlUnitStatus,
          vehicleApsControlUnitStatusDO, request.getCarIndex());
      setApsStatus(apsControlUnitStatus, request.getVehicleDetailModelList(),
          builder -> request.getHandler().setApsControlUnitStatus(builder.build().toByteArray()));
    }
    catch (InstantiationException e)
    {
      Tracer.getInstance().info(e);
    }
  }

  private void setStatus(PropertyKey<Integer> propertyKey, Integer newvalue,
      VehicleApsControlUnitStatusDO vehicleApsControlUnitStatusDO)
  {
    if (propertyKey.equals(ITCMSVehicleOutputsAPSSystemProperties.APS_1_STATUS))
    {
      vehicleApsControlUnitStatusDO.setApsStatus1(newvalue);
    }
    else if (propertyKey.equals(ITCMSVehicleOutputsAPSSystemProperties.APS_1_FAULT))
    {
      vehicleApsControlUnitStatusDO.setApsFault1(newvalue);
    }
    else if (propertyKey.equals(ITCMSVehicleOutputsAPSSystemProperties.APS_1_ISOLATED))
    {
      vehicleApsControlUnitStatusDO.setApsIsolated1(newvalue);
    }
    else if (propertyKey.equals(ITCMSVehicleOutputsAPSSystemProperties.APS_2_STATUS))
    {
      vehicleApsControlUnitStatusDO.setApsStatus2(newvalue);
    }
    else if (propertyKey.equals(ITCMSVehicleOutputsAPSSystemProperties.APS_2_FAULT))
    {
      vehicleApsControlUnitStatusDO.setApsFault2(newvalue);
    }
    else if (propertyKey.equals(ITCMSVehicleOutputsAPSSystemProperties.APS_2_ISOLATED))
    {
      vehicleApsControlUnitStatusDO.setApsIsolated2(newvalue);
    }
  }

  private void setApsStatus(List<Entry<VehicleApsControlUnitStatusDO>> apsControlUnitStatus,
      List<VehicleDetailModel> vehicleDetailModelList,
      Consumer<TCMSProto.APSControlUnitStatusList.Builder> builderConsumer)
  {
    TCMSProto.APSControlUnitStatusList.Builder builder = TCMSProto.APSControlUnitStatusList.newBuilder();
    TCMSProto.APSControlUnitStatusList.APSControlUnitStatus.Builder vehicleBuilder = TCMSProto.APSControlUnitStatusList.APSControlUnitStatus
        .newBuilder();

    VehicleApsControlUnitStatusDO data;
    for (int index = 0; index < apsControlUnitStatus.size(); index++)
    {
      int carIndex = apsControlUnitStatus.get(index).getIndex();
      APSControlUnitState apsControlUnitState1 = APSControlUnitState.APS_CU_BLANK;
      APSControlUnitState apsControlUnitState2 = APSControlUnitState.APS_CU_BLANK;
      if (vehicleDetailModelList != null && vehicleDetailModelList.size() > carIndex)
      {
        String carClassCode = vehicleDetailModelList.get(carIndex).getCarClassCode();
        if (TCMSConstants.T_CAR.equals(carClassCode))
        {
          data = apsControlUnitStatus.get(index).getData();
          apsControlUnitState1 = getApsControlUnitState1(data);
          apsControlUnitState2 = getApsControlUnitState2(data);
        }
      }
      vehicleBuilder.setCarIndex(apsControlUnitStatus.get(index).getIndex());
      vehicleBuilder.setApsControlUnitState1(apsControlUnitState1);
      vehicleBuilder.setApsControlUnitState2(apsControlUnitState2);
      builder.addApsControlUnitStatus(vehicleBuilder.build());
    }
    builderConsumer.accept(builder);
  }

  private APSControlUnitState getApsControlUnitState1(VehicleApsControlUnitStatusDO data)
  {
    APSControlUnitState apsControlUnitState;
    if (data.getApsFault1() == 1)
    {
      apsControlUnitState = APSControlUnitState.APS_CU_FAULTY;
    }
    else if (data.getApsIsolated1() == 1)
    {
      apsControlUnitState = APSControlUnitState.APS_CU_ISOLATED;
    }
    else if (data.getApsStatus1() == 1)
    {
      apsControlUnitState = APSControlUnitState.APS_CU_ACTIVE;
    }
    else if (data.getApsStatus1() == 0)
    {
      apsControlUnitState = APSControlUnitState.APS_CU_NOT_ACTIVE;
    }
    else
    {
      apsControlUnitState = APSControlUnitState.APS_CU_UNKNOWN;
    }
    return apsControlUnitState;
  }

  private APSControlUnitState getApsControlUnitState2(VehicleApsControlUnitStatusDO data)
  {
    APSControlUnitState apsControlUnitState;
    if (data.getApsFault2() == 1)
    {
      apsControlUnitState = APSControlUnitState.APS_CU_FAULTY;
    }
    else if (data.getApsIsolated2() == 1)
    {
      apsControlUnitState = APSControlUnitState.APS_CU_ISOLATED;
    }
    else if (data.getApsStatus2() == 1)
    {
      apsControlUnitState = APSControlUnitState.APS_CU_ACTIVE;
    }
    else if (data.getApsStatus2() == 0)
    {
      apsControlUnitState = APSControlUnitState.APS_CU_NOT_ACTIVE;
    }
    else
    {
      apsControlUnitState = APSControlUnitState.APS_CU_UNKNOWN;
    }
    return apsControlUnitState;
  }
}
