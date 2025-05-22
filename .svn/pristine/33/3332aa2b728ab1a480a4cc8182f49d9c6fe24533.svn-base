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
import com.sydac.mmrbem.tcms.common.data.VehicleBrakeControlUnitStatusDO;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.BrakeControlUnitStatusList.BrakeControlUnitState;

/**
 * This class handles BECU status update from vehicle outputs
 * 
 */
public class BrakeControlUnitVehicleOutputsRequestHandler implements
    ITCMSVehicleOutputsRequestHandler<TCMSOutputsBrakeSystemScreenImpl<Integer, IAppOutputsBrakeScreenHandler>>
{

  protected final List<Entry<VehicleBrakeControlUnitStatusDO>> becuStatusList = new ArrayList<>();

  @Override
  public void handleRequest(TCMSOutputsBrakeSystemScreenImpl<Integer, IAppOutputsBrakeScreenHandler> request)
  {
    try
    {
      VehicleBrakeControlUnitStatusDO vehicleBrakeControlUnitStatusDO = ITCMSVehicleOutputsRequestHandler
          .getVehicleStatusDo(becuStatusList, request.getCarIndex(), VehicleBrakeControlUnitStatusDO.class);
      setStatus(request.getPropertyKey(), request.getNewValue(), vehicleBrakeControlUnitStatusDO);
      ITCMSVehicleOutputsRequestHandler.updateVehicleStatusDOList(becuStatusList,
          vehicleBrakeControlUnitStatusDO, request.getCarIndex());
      setBecuStatus(becuStatusList,
          builder -> request.getHandler().setBrakeControlUnitStatus(builder.build().toByteArray()));
    }
    catch (InstantiationException e)
    {
      Tracer.getInstance().info(e);
    }
  }

  protected void setStatus(PropertyKey<Integer> propertyKey, Integer newvalue,
      VehicleBrakeControlUnitStatusDO vehicleBrakeControlUnitStatusDO)
  {
    if (propertyKey.equals(ITCMSVehicleOutputsBrakeSystemProperties.BECU_STATUS))
    {
      vehicleBrakeControlUnitStatusDO.setBecuOk(newvalue);
    }
    else if (propertyKey.equals(ITCMSVehicleOutputsBrakeSystemProperties.BECU_MAJOR_FAULT))
    {
      vehicleBrakeControlUnitStatusDO.setBecuMajorFault(newvalue);
    }
    else if (propertyKey.equals(ITCMSVehicleOutputsBrakeSystemProperties.BECU_MINOR_FAULT))
    {
      vehicleBrakeControlUnitStatusDO.setBecuMinorFault(newvalue);
    }
  }

  protected void setBecuStatus(List<Entry<VehicleBrakeControlUnitStatusDO>> becuStatusList,
      Consumer<TCMSProto.BrakeControlUnitStatusList.Builder> builderConsumer)
  {
    TCMSProto.BrakeControlUnitStatusList.Builder builder = TCMSProto.BrakeControlUnitStatusList.newBuilder();
    TCMSProto.BrakeControlUnitStatusList.BrakeControlUnitStatus.Builder vehicleBuilder = TCMSProto.BrakeControlUnitStatusList.BrakeControlUnitStatus
        .newBuilder();

    VehicleBrakeControlUnitStatusDO data;
    for (int index = 0; index < becuStatusList.size(); index++)
    {
      data = becuStatusList.get(index).getData();
      BrakeControlUnitState brakeControlUnitState;
      if (data.getBecuMajorFault() == 1)
      {
        brakeControlUnitState = BrakeControlUnitState.BECU_MAJOR_FAULT;
      }
      else if (data.getBecuMinorFault() == 1)
      {
        brakeControlUnitState = BrakeControlUnitState.BECU_MINOR_FAULT;
      }
      else if (data.getBecuOk() == 1)
      {
        brakeControlUnitState = BrakeControlUnitState.BECU_OK;
      }
      else if (data.getBecuOk() == 0)
      {
        brakeControlUnitState = BrakeControlUnitState.BECU_NOT_OK;
      }
      else
      {
        brakeControlUnitState = BrakeControlUnitState.BECU_UNKNOWN;
      }
      vehicleBuilder.setCarIndex(becuStatusList.get(index).getIndex());
      vehicleBuilder.setBrakeControlUnitState(brakeControlUnitState);
      builder.addBrakeControlUnitStatus(vehicleBuilder.build());
    }
    builderConsumer.accept(builder);
  }
}