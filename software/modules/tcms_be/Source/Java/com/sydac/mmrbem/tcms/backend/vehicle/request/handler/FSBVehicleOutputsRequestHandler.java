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
import com.sydac.mmrbem.tcms.common.data.VehicleFsbStatusDO;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.FullServiceBrakeLineStatusList.FullServiceBrakeLineState;
import com.sydac.mmrbem.tcms.common.state.TCMSConstants;

/**
 * This class handles FSB status update from vehicle outputs
 * 
 */
public class FSBVehicleOutputsRequestHandler implements
    ITCMSVehicleOutputsRequestHandler<TCMSOutputsBrakeSystemScreenImpl<Integer, IAppOutputsBrakeScreenHandler>>
{

  protected final List<Entry<VehicleFsbStatusDO>> fsbStatusList = new ArrayList<>();

  @Override
  public void handleRequest(TCMSOutputsBrakeSystemScreenImpl<Integer, IAppOutputsBrakeScreenHandler> request)
  {
    try
    {
      VehicleFsbStatusDO vehicleFsbStatusDO = ITCMSVehicleOutputsRequestHandler
          .getVehicleStatusDo(fsbStatusList, request.getCarIndex(), VehicleFsbStatusDO.class);
      setFsbStatus(request.getPropertyKey(), request.getNewValue(), vehicleFsbStatusDO);
      ITCMSVehicleOutputsRequestHandler.updateVehicleStatusDOList(fsbStatusList, vehicleFsbStatusDO,
          request.getCarIndex());
      setFsbStatus(fsbStatusList, request.getVehicleDetailModelList(),
          builder -> request.getHandler().setFullServiceBrakeLineStatus(builder.build().toByteArray()));
    }
    catch (InstantiationException e)
    {
      Tracer.getInstance().info(e);
    }
  }

  protected void setFsbStatus(PropertyKey<Integer> propertyKey, Integer newvalue,
      VehicleFsbStatusDO vehicleFsbStatusDO)
  {
    if (propertyKey.equals(ITCMSVehicleOutputsBrakeSystemProperties.FSB_1_LINE_STATUS))
    {
      vehicleFsbStatusDO.setFsb1Energized(newvalue);
    }
    else if (propertyKey.equals(ITCMSVehicleOutputsBrakeSystemProperties.FSB_2_LINE_STATUS))
    {
      vehicleFsbStatusDO.setFsb2Energized(newvalue);
    }
  }

  protected void setFsbStatus(List<Entry<VehicleFsbStatusDO>> fsbStatusList,
      List<VehicleDetailModel> vehicleDetailModelList,
      Consumer<TCMSProto.FullServiceBrakeLineStatusList.Builder> builderConsumer)
  {
    TCMSProto.FullServiceBrakeLineStatusList.Builder builder = TCMSProto.FullServiceBrakeLineStatusList
        .newBuilder();
    TCMSProto.FullServiceBrakeLineStatusList.FullServiceBrakeLineStatus.Builder vehicleBuilder = TCMSProto.FullServiceBrakeLineStatusList.FullServiceBrakeLineStatus
        .newBuilder();

    VehicleFsbStatusDO data;
    for (int index = 0; index < fsbStatusList.size(); index++)
    {
      int carIndex = fsbStatusList.get(index).getIndex();
      FullServiceBrakeLineState fullServiceBrakeLineState1 = FullServiceBrakeLineState.FSB_UNKNOWN;
      FullServiceBrakeLineState fullServiceBrakeLineState2 = FullServiceBrakeLineState.FSB_UNKNOWN;

      if (vehicleDetailModelList != null && vehicleDetailModelList.size() > carIndex)
      {
        String carClassCode = vehicleDetailModelList.get(carIndex).getCarClassCode();
        if (TCMSConstants.DM_CAR.equals(carClassCode))
        {
          data = fsbStatusList.get(index).getData();
          fullServiceBrakeLineState1 = getFsbState1(data);
          fullServiceBrakeLineState2 = getFsbState2(data);
        }
      }
      vehicleBuilder.setCarIndex(fsbStatusList.get(index).getIndex());
      vehicleBuilder.setFullServiceBrakeLineState1(fullServiceBrakeLineState1);
      vehicleBuilder.setFullServiceBrakeLineState2(fullServiceBrakeLineState2);
      builder.addFullServiceBrakeLineStatus(vehicleBuilder.build());
    }
    builderConsumer.accept(builder);
  }

  private FullServiceBrakeLineState getFsbState1(VehicleFsbStatusDO data)
  {
    FullServiceBrakeLineState fsbState;
    if (data.getFsb1Energized() == 1)
    {
      fsbState = FullServiceBrakeLineState.FSB_ENERGIZED;
    }
    else if (data.getFsb1Energized() == 0)
    {
      fsbState = FullServiceBrakeLineState.FSB_NOT_ENERGIZED;
    }
    else
    {
      fsbState = FullServiceBrakeLineState.FSB_UNKNOWN;
    }
    return fsbState;
  }

  private FullServiceBrakeLineState getFsbState2(VehicleFsbStatusDO data)
  {
    FullServiceBrakeLineState fsbState;
    if (data.getFsb2Energized() == 1)
    {
      fsbState = FullServiceBrakeLineState.FSB_ENERGIZED;
    }
    else if (data.getFsb2Energized() == 0)
    {
      fsbState = FullServiceBrakeLineState.FSB_NOT_ENERGIZED;
    }
    else
    {
      fsbState = FullServiceBrakeLineState.FSB_UNKNOWN;
    }
    return fsbState;
  }
}
