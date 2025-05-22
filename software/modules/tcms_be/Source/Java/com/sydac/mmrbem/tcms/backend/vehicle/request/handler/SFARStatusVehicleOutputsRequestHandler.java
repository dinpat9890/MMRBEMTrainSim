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
import com.sydac.mmrbem.tcms.backend.app.io.handlers.IAppOutputsFireDetectionSystemScreenHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.io.properties.ITCMSVehicleOutputsFireDetectionSystemProperties;
import com.sydac.mmrbem.tcms.common.data.Entry;
import com.sydac.mmrbem.tcms.common.data.VehicleDetailModel;
import com.sydac.mmrbem.tcms.common.data.VehicleSFARStatusDO;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.FireSystemWiredLineStatusList.FireSystemWireLineState;
import com.sydac.mmrbem.tcms.common.state.TCMSConstants;

/**
 * This class handles SFAR Status update from vehicle outputs
 * 
 */
public class SFARStatusVehicleOutputsRequestHandler implements
    ITCMSVehicleOutputsRequestHandler<TCMSOutputsFireDetectionSystemScreenImpl<Integer, IAppOutputsFireDetectionSystemScreenHandler>>
{

  protected final List<Entry<VehicleSFARStatusDO>> sfarStatus = new ArrayList<>();

  @Override
  public void handleRequest(
      TCMSOutputsFireDetectionSystemScreenImpl<Integer, IAppOutputsFireDetectionSystemScreenHandler> request)
  {
    try
    {
      VehicleSFARStatusDO vehicleSFARStatusDO = ITCMSVehicleOutputsRequestHandler
          .getVehicleStatusDo(sfarStatus, request.getCarIndex(), VehicleSFARStatusDO.class);
      setStatus(request.getPropertyKey(), request.getNewValue(), vehicleSFARStatusDO);
      ITCMSVehicleOutputsRequestHandler.updateVehicleStatusDOList(sfarStatus, vehicleSFARStatusDO,
          request.getCarIndex());
      setSFARStatus(sfarStatus, request.getVehicleDetailModelList(),
          builder -> request.getHandler().setFireSystemSfarStatus(builder.build().toByteArray()));
    }
    catch (InstantiationException e)
    {
      Tracer.getInstance().info(e);
    }
  }

  private void setStatus(PropertyKey<Integer> propertyKey, Integer newvalue,
      VehicleSFARStatusDO vehicleSFARStatusDO)
  {
    if (propertyKey.equals(ITCMSVehicleOutputsFireDetectionSystemProperties.SFAR_FAULT))
    {
      vehicleSFARStatusDO.setSfarFaultStatus(newvalue);
    }
    else if (propertyKey.equals(ITCMSVehicleOutputsFireDetectionSystemProperties.SALOON_FIRE_ALARM_STATUS))
    {
      vehicleSFARStatusDO.setSfarStatus(newvalue);
    }
  }

  private void setSFARStatus(List<Entry<VehicleSFARStatusDO>> sfarStatus,
      List<VehicleDetailModel> vehicleDetailModelList,
      Consumer<TCMSProto.FireSystemWiredLineStatusList.Builder> builderConsumer)
  {
    TCMSProto.FireSystemWiredLineStatusList.Builder builder = TCMSProto.FireSystemWiredLineStatusList
        .newBuilder();
    TCMSProto.FireSystemWiredLineStatusList.FireSystemWiredLineStatus.Builder vehicleBuilder = TCMSProto.FireSystemWiredLineStatusList.FireSystemWiredLineStatus
        .newBuilder();

    VehicleSFARStatusDO data;
    for (int index = 0; index < sfarStatus.size(); index++)
    {
      int carIndex = sfarStatus.get(index).getIndex();
      FireSystemWireLineState fireSystemWiredLineState = FireSystemWireLineState.WIRED_LINE_UNKNOWN;
      if (vehicleDetailModelList != null && vehicleDetailModelList.size() > carIndex)
      {
        String carClassCode = vehicleDetailModelList.get(carIndex).getCarClassCode();
        if (TCMSConstants.DM_CAR.equals(carClassCode))
        {
          data = sfarStatus.get(index).getData();
          fireSystemWiredLineState = getSFARStatus(data);
        }
        else
        {
          fireSystemWiredLineState = FireSystemWireLineState.WIRED_LINE_NOT_AVAILABLE;
        }
      }
      vehicleBuilder.setCarIndex(sfarStatus.get(index).getIndex());
      vehicleBuilder.setFireSystemWireLineState(fireSystemWiredLineState);
      builder.addFireSystemWiredLineStatus(vehicleBuilder.build());
    }
    builderConsumer.accept(builder);
  }

  private FireSystemWireLineState getSFARStatus(VehicleSFARStatusDO data)
  {
    FireSystemWireLineState fireSystemWireLineState;
    if (data.getSfarFaultStatus() == TCMSConstants.FAULTY)
    {
      fireSystemWireLineState = FireSystemWireLineState.WIRED_LINE_FAULTY;
    }
    else if (data.getSfarStatus() == TCMSConstants.OK)
    {
      fireSystemWireLineState = FireSystemWireLineState.WIRED_LINE_HEALTHY;
    }
    else
    {
      fireSystemWireLineState = FireSystemWireLineState.WIRED_LINE_UNKNOWN;
    }
    return fireSystemWireLineState;
  }
}
