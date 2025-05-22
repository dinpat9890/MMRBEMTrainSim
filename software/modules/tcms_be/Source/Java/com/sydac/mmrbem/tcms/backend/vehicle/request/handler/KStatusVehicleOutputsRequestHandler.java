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
import com.sydac.mmrbem.tcms.common.data.VehicleDetailModel;
import com.sydac.mmrbem.tcms.common.data.VehicleKStatusDO;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.KStatusList.KState;
import com.sydac.mmrbem.tcms.common.state.ApplicationConstants;
import com.sydac.mmrbem.tcms.common.state.TCMSConstants;

/**
 * This class handles K Status update from vehicle outputs
 * 
 */
public class KStatusVehicleOutputsRequestHandler implements
    ITCMSVehicleOutputsRequestHandler<TCMSOutputsApsSystemScreenImpl<Integer, IAppOutputsApsScreenHandler>>
{

  protected final List<Entry<VehicleKStatusDO>> kStatusList = new ArrayList<>();

  @Override
  public void handleRequest(TCMSOutputsApsSystemScreenImpl<Integer, IAppOutputsApsScreenHandler> request)
  {
    try
    {
      VehicleKStatusDO vehicleAkStatusDO = ITCMSVehicleOutputsRequestHandler.getVehicleStatusDo(kStatusList,
          request.getCarIndex(), VehicleKStatusDO.class);
      setStatus(request.getPropertyKey(), request.getNewValue(), vehicleAkStatusDO);
      ITCMSVehicleOutputsRequestHandler.updateVehicleStatusDOList(kStatusList, vehicleAkStatusDO,
          request.getCarIndex());
      setAkStatus(kStatusList, request.getVehicleDetailModelList(),
          builder -> request.getHandler().setKStatus(builder.build().toByteArray()));
    }
    catch (InstantiationException e)
    {
      Tracer.getInstance().info(e);
    }
  }

  private void setStatus(PropertyKey<Integer> propertyKey, Integer newvalue,
      VehicleKStatusDO vehicleAkStatusDO)
  {
    if (propertyKey.equals(ITCMSVehicleOutputsAPSSystemProperties.K_1_STATUS))
    {
      vehicleAkStatusDO.setkOpen1(newvalue);
    }
    else if (propertyKey.equals(ITCMSVehicleOutputsAPSSystemProperties.K_2_STATUS))
    {
      vehicleAkStatusDO.setkOpen2(newvalue);
    }
  }

  private void setAkStatus(List<Entry<VehicleKStatusDO>> kStatusList,
      List<VehicleDetailModel> vehicleDetailModelList,
      Consumer<TCMSProto.KStatusList.Builder> builderConsumer)
  {
    TCMSProto.KStatusList.Builder builder = TCMSProto.KStatusList.newBuilder();
    TCMSProto.KStatusList.KStatus.Builder vehicleBuilder = TCMSProto.KStatusList.KStatus.newBuilder();

    VehicleKStatusDO data;
    for (int index = 0; index < kStatusList.size(); index++)
    {
      int carIndex = kStatusList.get(index).getIndex();
      KState kState1 = KState.K_STATE_UNKNOWN;
      KState kState2 = KState.K_STATE_UNKNOWN;

      if (vehicleDetailModelList != null && vehicleDetailModelList.size() > carIndex)
      {
        String carClassCode = vehicleDetailModelList.get(carIndex).getCarClassCode();
        if (TCMSConstants.T_CAR.equals(carClassCode))
        {
          data = kStatusList.get(index).getData();

          kState1 = getKState1(data);
          kState2 = getKState2(data);
        }
      }
      vehicleBuilder.setCarIndex(kStatusList.get(index).getIndex());
      vehicleBuilder.setKState1(kState1);
      vehicleBuilder.setKState2(kState2);
      builder.addKStatus(vehicleBuilder.build());
    }
    builderConsumer.accept(builder);
  }

  private KState getKState1(VehicleKStatusDO data)
  {
    KState kState;
    if (data.getkOpen1() == ApplicationConstants.K_STATE_OPEN)
    {
      kState = KState.K_STATE_OPEN;
    }
    else if (data.getkOpen1() == ApplicationConstants.K_STATE_CLOSED)
    {
      kState = KState.K_STATE_CLOSED;
    }
    else
    {
      kState = KState.K_STATE_UNKNOWN;
    }
    return kState;
  }

  private KState getKState2(VehicleKStatusDO data)
  {
    KState kState;
    if (data.getkOpen2() == ApplicationConstants.K_STATE_OPEN)
    {
      kState = KState.K_STATE_OPEN;
    }
    else if (data.getkOpen2() == ApplicationConstants.K_STATE_CLOSED)
    {
      kState = KState.K_STATE_CLOSED;
    }
    else
    {
      kState = KState.K_STATE_UNKNOWN;
    }
    return kState;
  }
}
