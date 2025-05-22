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
import com.sydac.mmrbem.tcms.common.data.VehicleHoldingBrakeEpicIsolationStatusDO;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.HoldingBrakeEpicIsolationStatusList.EpicIsolationState;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.HoldingBrakeEpicIsolationStatusList.HoldingBrakeState;

/**
 * This class handles Holding Brake status and EPIC Isolation update from
 * vehicle outputs
 * 
 */
public class HoldingBrakeEpicIsolationVehicleOutputRequestHandler implements
    ITCMSVehicleOutputsRequestHandler<TCMSOutputsBrakeSystemScreenImpl<Integer, IAppOutputsBrakeScreenHandler>>
{

  protected final List<Entry<VehicleHoldingBrakeEpicIsolationStatusDO>> holdingBrakeEpicIsolationStatusList = new ArrayList<>();

  @Override
  public void handleRequest(TCMSOutputsBrakeSystemScreenImpl<Integer, IAppOutputsBrakeScreenHandler> request)
  {
    try
    {
      VehicleHoldingBrakeEpicIsolationStatusDO vehicleHoldingBrakeEpicIsolationStatusDO = ITCMSVehicleOutputsRequestHandler
          .getVehicleStatusDo(holdingBrakeEpicIsolationStatusList, request.getCarIndex(),
              VehicleHoldingBrakeEpicIsolationStatusDO.class);
      setStatus(request.getPropertyKey(), request.getNewValue(), vehicleHoldingBrakeEpicIsolationStatusDO);
      ITCMSVehicleOutputsRequestHandler.updateVehicleStatusDOList(holdingBrakeEpicIsolationStatusList,
          vehicleHoldingBrakeEpicIsolationStatusDO, request.getCarIndex());
      setHoldingBrakeEpicIsolationStatusList(holdingBrakeEpicIsolationStatusList,
          builder -> request.getHandler().setHoldingBrakeEpicIsolationStatus(builder.build().toByteArray()));
    }
    catch (InstantiationException e)
    {
      Tracer.getInstance().info(e);
    }
  }

  protected void setStatus(PropertyKey<Integer> propertyKey, Integer newvalue,
      VehicleHoldingBrakeEpicIsolationStatusDO vehicleHoldingBrakeEpicIsolationStatusDO)
  {
    if (propertyKey.equals(ITCMSVehicleOutputsBrakeSystemProperties.HOLDING_BRAKE_STATUS))
    {
      vehicleHoldingBrakeEpicIsolationStatusDO.setHoldingBrakeApplied(newvalue);
    }
    else if (propertyKey.equals(ITCMSVehicleOutputsBrakeSystemProperties.EPIC_ISOLATION_STATUS))
    {
      vehicleHoldingBrakeEpicIsolationStatusDO.setEpicIsolated(newvalue);
    }
  }

  protected void setHoldingBrakeEpicIsolationStatusList(
      List<Entry<VehicleHoldingBrakeEpicIsolationStatusDO>> holdingBrakeEpicIsolationStatusList,
      Consumer<TCMSProto.HoldingBrakeEpicIsolationStatusList.Builder> builderConsumer)
  {
    TCMSProto.HoldingBrakeEpicIsolationStatusList.Builder builder = TCMSProto.HoldingBrakeEpicIsolationStatusList
        .newBuilder();
    TCMSProto.HoldingBrakeEpicIsolationStatusList.HoldingBrakeEpicIsolationStatus.Builder vehicleBuilder = TCMSProto.HoldingBrakeEpicIsolationStatusList.HoldingBrakeEpicIsolationStatus
        .newBuilder();

    VehicleHoldingBrakeEpicIsolationStatusDO data;
    for (int index = 0; index < holdingBrakeEpicIsolationStatusList.size(); index++)
    {
      data = holdingBrakeEpicIsolationStatusList.get(index).getData();

      HoldingBrakeState holdingBrakeState = getHoldingBrakeState(data);
      EpicIsolationState epicIsolationState = getEpicIsolationState(data);

      vehicleBuilder.setCarIndex(holdingBrakeEpicIsolationStatusList.get(index).getIndex());
      vehicleBuilder.setHoldingBrakeState(holdingBrakeState);
      vehicleBuilder.setEpicIsolationState(epicIsolationState);
      builder.addHoldingBrakeEpicIsolationStatus(vehicleBuilder.build());
    }
    builderConsumer.accept(builder);
  }

  private EpicIsolationState getEpicIsolationState(VehicleHoldingBrakeEpicIsolationStatusDO data)
  {
    EpicIsolationState epicIsolationState;
    if (data.getEpicIsolated() == 1)
    {
      epicIsolationState = EpicIsolationState.EPIC_ISOLATED;
    }
    else if (data.getEpicIsolated() == 0)
    {
      epicIsolationState = EpicIsolationState.EPIC_NOT_ISOLATED;
    }
    else
    {
      epicIsolationState = EpicIsolationState.EPIC_UNKNOWN;
    }
    return epicIsolationState;
  }

  private HoldingBrakeState getHoldingBrakeState(VehicleHoldingBrakeEpicIsolationStatusDO data)
  {
    HoldingBrakeState holdingBrakeState;
    if (data.getHoldingBrakeApplied() == 1)
    {
      holdingBrakeState = HoldingBrakeState.HLD_BRK_APPLIED;
    }
    else if (data.getHoldingBrakeApplied() == 0)
    {
      holdingBrakeState = HoldingBrakeState.HLD_BRK_NOT_APPLIED;
    }
    else
    {
      holdingBrakeState = HoldingBrakeState.HLD_BRK_UNKNOWN;
    }
    return holdingBrakeState;
  }
}