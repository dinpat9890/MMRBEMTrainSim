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
import com.sydac.mmrbem.tcms.common.data.VehicleExternalSmokeStatusDO;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.FireSystemWiredLineStatusList.FireSystemWireLineState;
import com.sydac.mmrbem.tcms.common.state.TCMSConstants;

/**
 * This class handles External Smoke Train Line Status update from vehicle
 * outputs
 * 
 */
public class ExternalSmokeStatusVehicleOutputsRequestHandler implements
    ITCMSVehicleOutputsRequestHandler<TCMSOutputsFireDetectionSystemScreenImpl<Integer, IAppOutputsFireDetectionSystemScreenHandler>>
{

  protected final List<Entry<VehicleExternalSmokeStatusDO>> externalSmokeStatus = new ArrayList<>();

  @Override
  public void handleRequest(
      TCMSOutputsFireDetectionSystemScreenImpl<Integer, IAppOutputsFireDetectionSystemScreenHandler> request)
  {
    try
    {
      VehicleExternalSmokeStatusDO vehicleExternalSmokeStatusDO = ITCMSVehicleOutputsRequestHandler
          .getVehicleStatusDo(externalSmokeStatus, request.getCarIndex(), VehicleExternalSmokeStatusDO.class);
      setStatus(request.getPropertyKey(), request.getNewValue(), vehicleExternalSmokeStatusDO);
      ITCMSVehicleOutputsRequestHandler.updateVehicleStatusDOList(externalSmokeStatus,
          vehicleExternalSmokeStatusDO, request.getCarIndex());
      setExternalSmokeStatus(externalSmokeStatus, request.getVehicleDetailModelList(),
          builder -> request.getHandler().setFireSystemExternalSmokeStatus(builder.build().toByteArray()));
    }
    catch (InstantiationException e)
    {
      Tracer.getInstance().info(e);
    }
  }

  private void setStatus(PropertyKey<Integer> propertyKey, Integer newvalue,
      VehicleExternalSmokeStatusDO vehicleExternalSmokeStatusDO)
  {
    if (propertyKey.equals(ITCMSVehicleOutputsProperties.DUMMY_FAULT_SIGNAL))
    {
      vehicleExternalSmokeStatusDO.setExternalSmokeFaultStatus(newvalue);
    }
    else if (propertyKey.equals(ITCMSVehicleOutputsFireDetectionSystemProperties.EXTERNAL_SMOKE))
    {
      vehicleExternalSmokeStatusDO.setExternalSmokeStatus(newvalue);
    }
  }

  private void setExternalSmokeStatus(List<Entry<VehicleExternalSmokeStatusDO>> externalSmokeStatus,
      List<VehicleDetailModel> vehicleDetailModelList,
      Consumer<TCMSProto.FireSystemWiredLineStatusList.Builder> builderConsumer)
  {
    TCMSProto.FireSystemWiredLineStatusList.Builder builder = TCMSProto.FireSystemWiredLineStatusList
        .newBuilder();
    TCMSProto.FireSystemWiredLineStatusList.FireSystemWiredLineStatus.Builder vehicleBuilder = TCMSProto.FireSystemWiredLineStatusList.FireSystemWiredLineStatus
        .newBuilder();

    VehicleExternalSmokeStatusDO data;
    for (int index = 0; index < externalSmokeStatus.size(); index++)
    {
      int carIndex = externalSmokeStatus.get(index).getIndex();
      FireSystemWireLineState fireSystemWiredLineState = FireSystemWireLineState.WIRED_LINE_UNKNOWN;
      if (vehicleDetailModelList != null && vehicleDetailModelList.size() > carIndex)
      {
        data = externalSmokeStatus.get(index).getData();
        fireSystemWiredLineState = getExternalSmokeStatus(data);
      }
      vehicleBuilder.setCarIndex(externalSmokeStatus.get(index).getIndex());
      vehicleBuilder.setFireSystemWireLineState(fireSystemWiredLineState);
      builder.addFireSystemWiredLineStatus(vehicleBuilder.build());
    }
    builderConsumer.accept(builder);
  }

  private FireSystemWireLineState getExternalSmokeStatus(VehicleExternalSmokeStatusDO data)
  {
    FireSystemWireLineState fireSystemWireLineState;
    if (data.getExternalSmokeFaultStatus() == TCMSConstants.FAULTY)
    {
      fireSystemWireLineState = FireSystemWireLineState.WIRED_LINE_FAULTY;
    }
    else if (data.getExternalSmokeStatus() == TCMSConstants.OK)
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
