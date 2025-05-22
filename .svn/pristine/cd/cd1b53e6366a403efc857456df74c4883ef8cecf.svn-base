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
import com.sydac.mmrbem.tcms.common.data.VehicleAkStatusDO;
import com.sydac.mmrbem.tcms.common.data.VehicleDetailModel;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.AKStatusList.AKState;
import com.sydac.mmrbem.tcms.common.state.ApplicationConstants;
import com.sydac.mmrbem.tcms.common.state.TCMSConstants;

/**
 * This class handles AK Status update from vehicle outputs
 * 
 */
public class AkStatusVehicleOutputsRequestHandler implements
    ITCMSVehicleOutputsRequestHandler<TCMSOutputsApsSystemScreenImpl<Integer, IAppOutputsApsScreenHandler>>
{

  protected final List<Entry<VehicleAkStatusDO>> akStatusList = new ArrayList<>();

  @Override
  public void handleRequest(TCMSOutputsApsSystemScreenImpl<Integer, IAppOutputsApsScreenHandler> request)
  {
    try
    {
      VehicleAkStatusDO vehicleAkStatusDO = ITCMSVehicleOutputsRequestHandler.getVehicleStatusDo(akStatusList,
          request.getCarIndex(), VehicleAkStatusDO.class);
      setStatus(request.getPropertyKey(), request.getNewValue(), vehicleAkStatusDO);
      ITCMSVehicleOutputsRequestHandler.updateVehicleStatusDOList(akStatusList, vehicleAkStatusDO,
          request.getCarIndex());
      setAkStatus(akStatusList, request.getVehicleDetailModelList(),
          builder -> request.getHandler().setAkStatus(builder.build().toByteArray()));
    }
    catch (InstantiationException e)
    {
      Tracer.getInstance().info(e);
    }
  }

  private void setStatus(PropertyKey<Integer> propertyKey, Integer newvalue,
      VehicleAkStatusDO vehicleAkStatusDO)
  {
    if (propertyKey.equals(ITCMSVehicleOutputsAPSSystemProperties.AK_1_STATUS))
    {
      vehicleAkStatusDO.setAkOpen1(newvalue);
    }
    else if (propertyKey.equals(ITCMSVehicleOutputsAPSSystemProperties.AK_2_STATUS))
    {
      vehicleAkStatusDO.setAkOpen2(newvalue);
    }
  }

  private void setAkStatus(List<Entry<VehicleAkStatusDO>> akStatusList,
      List<VehicleDetailModel> vehicleDetailModelList,
      Consumer<TCMSProto.AKStatusList.Builder> builderConsumer)
  {
    TCMSProto.AKStatusList.Builder builder = TCMSProto.AKStatusList.newBuilder();
    TCMSProto.AKStatusList.AKStatus.Builder vehicleBuilder = TCMSProto.AKStatusList.AKStatus.newBuilder();

    VehicleAkStatusDO data;
    for (int index = 0; index < akStatusList.size(); index++)
    {
      int carIndex = akStatusList.get(index).getIndex();
      AKState akState1 = AKState.AK_STATE_UNKNOWN;
      AKState akState2 = AKState.AK_STATE_UNKNOWN;

      if (vehicleDetailModelList != null && vehicleDetailModelList.size() > carIndex)
      {
        String carClassCode = vehicleDetailModelList.get(carIndex).getCarClassCode();
        if (TCMSConstants.T_CAR.equals(carClassCode))
        {
          data = akStatusList.get(index).getData();

          akState1 = getAkState1(data);
          akState2 = getAkState2(data);
        }
      }
      vehicleBuilder.setCarIndex(akStatusList.get(index).getIndex());
      vehicleBuilder.setAkState1(akState1);
      vehicleBuilder.setAkState2(akState2);
      builder.addAkStatus(vehicleBuilder.build());
    }
    builderConsumer.accept(builder);
  }

  private AKState getAkState1(VehicleAkStatusDO data)
  {
    AKState akState;
    if (data.getAkOpen1() == ApplicationConstants.AK_STATE_OPEN)
    {
      akState = AKState.AK_STATE_OPEN;
    }
    else if (data.getAkOpen1() == ApplicationConstants.AK_STATE_CLOSED)
    {
      akState = AKState.AK_STATE_CLOSED;
    }
    else
    {
      akState = AKState.AK_STATE_UNKNOWN;
    }
    return akState;
  }

  private AKState getAkState2(VehicleAkStatusDO data)
  {
    AKState akState;
    if (data.getAkOpen2() == ApplicationConstants.AK_STATE_OPEN)
    {
      akState = AKState.AK_STATE_OPEN;
    }
    else if (data.getAkOpen2() == ApplicationConstants.AK_STATE_CLOSED)
    {
      akState = AKState.AK_STATE_CLOSED;
    }
    else
    {
      akState = AKState.AK_STATE_UNKNOWN;
    }
    return akState;
  }
}
