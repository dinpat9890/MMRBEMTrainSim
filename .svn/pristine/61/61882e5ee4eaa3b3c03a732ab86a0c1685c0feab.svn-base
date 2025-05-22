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
import com.sydac.mmrbem.tcms.backend.vehicle.io.properties.ITCMSVehicleOutputsProperties;
import com.sydac.mmrbem.tcms.common.data.Entry;
import com.sydac.mmrbem.tcms.common.data.VehicleDetailModel;
import com.sydac.mmrbem.tcms.common.data.VehicleUFARStatusDO;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.FireSystemWiredLineStatusList.FireSystemWireLineState;
import com.sydac.mmrbem.tcms.common.state.TCMSConstants;

/**
 * This class handles UFAR Status update from vehicle outputs
 * 
 */
public class UFARStatusVehicleOutputsRequestHandler implements
    ITCMSVehicleOutputsRequestHandler<TCMSOutputsFireDetectionSystemScreenImpl<Integer, IAppOutputsFireDetectionSystemScreenHandler>>
{

  protected final List<Entry<VehicleUFARStatusDO>> ufarStatus = new ArrayList<>();

  @Override
  public void handleRequest(
      TCMSOutputsFireDetectionSystemScreenImpl<Integer, IAppOutputsFireDetectionSystemScreenHandler> request)
  {
    try
    {
      VehicleUFARStatusDO vehicleUFARStatusDO = ITCMSVehicleOutputsRequestHandler
          .getVehicleStatusDo(ufarStatus, request.getCarIndex(), VehicleUFARStatusDO.class);
      setStatus(request.getPropertyKey(), request.getNewValue(), vehicleUFARStatusDO);
      ITCMSVehicleOutputsRequestHandler.updateVehicleStatusDOList(ufarStatus, vehicleUFARStatusDO,
          request.getCarIndex());
      setUFARStatus(ufarStatus, request.getVehicleDetailModelList(),
          builder -> request.getHandler().setFireSystemUfarStatus(builder.build().toByteArray()));
    }
    catch (InstantiationException e)
    {
      Tracer.getInstance().info(e);
    }
  }

  private void setStatus(PropertyKey<Integer> propertyKey, Integer newvalue,
      VehicleUFARStatusDO vehicleUFARStatusDO)
  {
    if (propertyKey.equals(ITCMSVehicleOutputsProperties.DUMMY_FAULT_SIGNAL))
    {
      vehicleUFARStatusDO.setUfarFaultStatus(newvalue);
    }
    else if (propertyKey
        .equals(ITCMSVehicleOutputsFireDetectionSystemProperties.UNDERFRAME_FIRE_ALARM_STATUS))
    {
      vehicleUFARStatusDO.setUfarStatus(newvalue);
    }
  }

  private void setUFARStatus(List<Entry<VehicleUFARStatusDO>> ufarStatus,
      List<VehicleDetailModel> vehicleDetailModelList,
      Consumer<TCMSProto.FireSystemWiredLineStatusList.Builder> builderConsumer)
  {
    TCMSProto.FireSystemWiredLineStatusList.Builder builder = TCMSProto.FireSystemWiredLineStatusList
        .newBuilder();
    TCMSProto.FireSystemWiredLineStatusList.FireSystemWiredLineStatus.Builder vehicleBuilder = TCMSProto.FireSystemWiredLineStatusList.FireSystemWiredLineStatus
        .newBuilder();

    VehicleUFARStatusDO data;
    for (int index = 0; index < ufarStatus.size(); index++)
    {
      int carIndex = ufarStatus.get(index).getIndex();
      FireSystemWireLineState fireSystemWiredLineState = FireSystemWireLineState.WIRED_LINE_UNKNOWN;
      if (vehicleDetailModelList != null && vehicleDetailModelList.size() > carIndex)
      {
        String carClassCode = vehicleDetailModelList.get(carIndex).getCarClassCode();
        if (TCMSConstants.DM_CAR.equals(carClassCode))
        {
          data = ufarStatus.get(index).getData();
          fireSystemWiredLineState = getUFARStatus(data);
        }
        else
        {
          fireSystemWiredLineState = FireSystemWireLineState.WIRED_LINE_NOT_AVAILABLE;
        }
      }
      vehicleBuilder.setCarIndex(ufarStatus.get(index).getIndex());
      vehicleBuilder.setFireSystemWireLineState(fireSystemWiredLineState);
      builder.addFireSystemWiredLineStatus(vehicleBuilder.build());
    }
    builderConsumer.accept(builder);
  }

  private FireSystemWireLineState getUFARStatus(VehicleUFARStatusDO data)
  {
    FireSystemWireLineState fireSystemWireLineState;
    if (data.getUfarFaultStatus() == TCMSConstants.FAULTY)
    {
      fireSystemWireLineState = FireSystemWireLineState.WIRED_LINE_FAULTY;
    }
    else if (data.getUfarStatus() == TCMSConstants.OK)
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
