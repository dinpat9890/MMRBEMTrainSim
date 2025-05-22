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
import com.sydac.mmrbem.tcms.common.data.VehicleInternalFireStatusDO;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.FireSystemWiredLineStatusList.FireSystemWireLineState;
import com.sydac.mmrbem.tcms.common.state.TCMSConstants;

/**
 * This class handles Internal Fire Train Line Status update from vehicle
 * outputs
 * 
 */
public class InternalFireStatusVehicleOutputsRequestHandler implements
    ITCMSVehicleOutputsRequestHandler<TCMSOutputsFireDetectionSystemScreenImpl<Integer, IAppOutputsFireDetectionSystemScreenHandler>>
{

  protected final List<Entry<VehicleInternalFireStatusDO>> internalFireStatus = new ArrayList<>();

  @Override
  public void handleRequest(
      TCMSOutputsFireDetectionSystemScreenImpl<Integer, IAppOutputsFireDetectionSystemScreenHandler> request)
  {
    try
    {
      VehicleInternalFireStatusDO vehicleInternalFireStatusDO = ITCMSVehicleOutputsRequestHandler
          .getVehicleStatusDo(internalFireStatus, request.getCarIndex(), VehicleInternalFireStatusDO.class);
      setStatus(request.getPropertyKey(), request.getNewValue(), vehicleInternalFireStatusDO);
      ITCMSVehicleOutputsRequestHandler.updateVehicleStatusDOList(internalFireStatus,
          vehicleInternalFireStatusDO, request.getCarIndex());
      setInternalFireStatus(internalFireStatus, request.getVehicleDetailModelList(),
          builder -> request.getHandler().setFireSystemInternalFireStatus(builder.build().toByteArray()));
    }
    catch (InstantiationException e)
    {
      Tracer.getInstance().info(e);
    }
  }

  private void setStatus(PropertyKey<Integer> propertyKey, Integer newvalue,
      VehicleInternalFireStatusDO vehicleInternalFireStatusDO)
  {
    if (propertyKey.equals(ITCMSVehicleOutputsProperties.DUMMY_FAULT_SIGNAL))
    {
      vehicleInternalFireStatusDO.setInternalFireFaultStatus(newvalue);
    }
    else if (propertyKey.equals(ITCMSVehicleOutputsFireDetectionSystemProperties.INTERNAL_FIRE))
    {
      vehicleInternalFireStatusDO.setInternalFireStatus(newvalue);
    }
  }

  private void setInternalFireStatus(List<Entry<VehicleInternalFireStatusDO>> internalFireStatus,
      List<VehicleDetailModel> vehicleDetailModelList,
      Consumer<TCMSProto.FireSystemWiredLineStatusList.Builder> builderConsumer)
  {
    TCMSProto.FireSystemWiredLineStatusList.Builder builder = TCMSProto.FireSystemWiredLineStatusList
        .newBuilder();
    TCMSProto.FireSystemWiredLineStatusList.FireSystemWiredLineStatus.Builder vehicleBuilder = TCMSProto.FireSystemWiredLineStatusList.FireSystemWiredLineStatus
        .newBuilder();

    VehicleInternalFireStatusDO data;
    for (int index = 0; index < internalFireStatus.size(); index++)
    {
      int carIndex = internalFireStatus.get(index).getIndex();
      FireSystemWireLineState fireSystemWiredLineState = FireSystemWireLineState.WIRED_LINE_UNKNOWN;
      if (vehicleDetailModelList != null && vehicleDetailModelList.size() > carIndex)
      {
        String carClassCode = vehicleDetailModelList.get(carIndex).getCarClassCode();
        if (TCMSConstants.DM_CAR.equals(carClassCode))
        {
          data = internalFireStatus.get(index).getData();
          fireSystemWiredLineState = getInternalFireStatus(data);
        }
        else
        {
          fireSystemWiredLineState = FireSystemWireLineState.WIRED_LINE_NOT_AVAILABLE;
        }
      }
      vehicleBuilder.setCarIndex(internalFireStatus.get(index).getIndex());
      vehicleBuilder.setFireSystemWireLineState(fireSystemWiredLineState);
      builder.addFireSystemWiredLineStatus(vehicleBuilder.build());
    }
    builderConsumer.accept(builder);
  }

  private FireSystemWireLineState getInternalFireStatus(VehicleInternalFireStatusDO data)
  {
    FireSystemWireLineState fireSystemWireLineState;
    if (data.getInternalFireFaultStatus() == TCMSConstants.FAULTY)
    {
      fireSystemWireLineState = FireSystemWireLineState.WIRED_LINE_FAULTY;
    }
    else if (data.getInternalFireStatus() == TCMSConstants.OK)
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
