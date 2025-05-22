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
import com.sydac.mmrbem.tcms.common.data.VehicleFDUStatusDO;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.FDUFaultStatusList.FDUFaultState;
import com.sydac.mmrbem.tcms.common.state.TCMSConstants;

/**
 * This class handles FDU Status update from vehicle outputs
 * 
 */
public class FDUStatusVehicleOutputsRequestHandler implements
    ITCMSVehicleOutputsRequestHandler<TCMSOutputsFireDetectionSystemScreenImpl<Integer, IAppOutputsFireDetectionSystemScreenHandler>>
{

  protected final List<Entry<VehicleFDUStatusDO>> fduStatus = new ArrayList<>();

  @Override
  public void handleRequest(
      TCMSOutputsFireDetectionSystemScreenImpl<Integer, IAppOutputsFireDetectionSystemScreenHandler> request)
  {
    try
    {
      VehicleFDUStatusDO vehicleFDUStatusDO = ITCMSVehicleOutputsRequestHandler.getVehicleStatusDo(fduStatus,
          request.getCarIndex(), VehicleFDUStatusDO.class);
      setStatus(request.getPropertyKey(), request.getNewValue(), vehicleFDUStatusDO);
      ITCMSVehicleOutputsRequestHandler.updateVehicleStatusDOList(fduStatus, vehicleFDUStatusDO,
          request.getCarIndex());
      setFDUStatus(fduStatus, request.getVehicleDetailModelList(),
          builder -> request.getHandler().setFduSystemFaultStatus(builder.build().toByteArray()));
    }
    catch (InstantiationException e)
    {
      Tracer.getInstance().info(e);
    }
  }

  private void setStatus(PropertyKey<Integer> propertyKey, Integer newvalue,
      VehicleFDUStatusDO vehicleFDUStatusDO)
  {
    if (propertyKey.equals(ITCMSVehicleOutputsFireDetectionSystemProperties.FDU_FAULT))
    {
      vehicleFDUStatusDO.setFduFault(newvalue);
    }
    else if (propertyKey.equals(ITCMSVehicleOutputsFireDetectionSystemProperties.FIRE_DETECTION_UNIT))
    {
      vehicleFDUStatusDO.setFduStatus(newvalue);
    }
  }

  private void setFDUStatus(List<Entry<VehicleFDUStatusDO>> fduStatus,
      List<VehicleDetailModel> vehicleDetailModelList,
      Consumer<TCMSProto.FDUFaultStatusList.Builder> builderConsumer)
  {
    TCMSProto.FDUFaultStatusList.Builder builder = TCMSProto.FDUFaultStatusList.newBuilder();
    TCMSProto.FDUFaultStatusList.FDUFaultStatus.Builder vehicleBuilder = TCMSProto.FDUFaultStatusList.FDUFaultStatus
        .newBuilder();

    VehicleFDUStatusDO data;
    for (int index = 0; index < fduStatus.size(); index++)
    {
      int carIndex = fduStatus.get(index).getIndex();
      FDUFaultState fduFaultState = FDUFaultState.FDU_FAULT_NOT_AVAILABLE;
      if (vehicleDetailModelList != null && vehicleDetailModelList.size() > carIndex)
      {
        String carClassCode = vehicleDetailModelList.get(carIndex).getCarClassCode();
        if (TCMSConstants.DM_CAR.equals(carClassCode))
        {
          data = fduStatus.get(index).getData();
          fduFaultState = getFDUState(data);
        }
        else
        {
          fduFaultState = FDUFaultState.FDU_FAULT_NOT_AVAILABLE;
        }
      }
      vehicleBuilder.setCarIndex(fduStatus.get(index).getIndex());
      vehicleBuilder.setFduFaultState(fduFaultState);
      builder.addFduFaultStatus(vehicleBuilder.build());
    }
    builderConsumer.accept(builder);
  }

  private FDUFaultState getFDUState(VehicleFDUStatusDO data)
  {
    FDUFaultState fduState;
    if (data.getFduFault() == TCMSConstants.FAULTY)
    {
      fduState = FDUFaultState.FDU_FAULT_NOT_ENERGIZED;
    }
    else if (data.getFduStatus() == TCMSConstants.OK)
    {
      fduState = FDUFaultState.FDU_FAULT_ENERGIZED;
    }
    else
    {
      fduState = FDUFaultState.FDU_FAULT_UNKNOWN;
    }
    return fduState;
  }
}
