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
import com.sydac.mmrbem.tcms.common.data.VehicleEdCutoutRpressIsolationStatusDO;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.EDCutOutRPRESSIsolationStatusList.EDCutOutState;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.EDCutOutRPRESSIsolationStatusList.RPRESSIsolationState;
import com.sydac.mmrbem.tcms.common.state.TCMSConstants;

/**
 * This class handles ED cutout Status status and RPRESS Isolation update from
 * vehicle outputs
 * 
 */
public class EdCutoutRpessIsolationVehicleOutputRequestHandler implements
    ITCMSVehicleOutputsRequestHandler<TCMSOutputsBrakeSystemScreenImpl<Integer, IAppOutputsBrakeScreenHandler>>
{

  protected final List<Entry<VehicleEdCutoutRpressIsolationStatusDO>> edCutoutRpressisolationStatusList = new ArrayList<>();

  @Override
  public void handleRequest(TCMSOutputsBrakeSystemScreenImpl<Integer, IAppOutputsBrakeScreenHandler> request)
  {
    try
    {
      VehicleEdCutoutRpressIsolationStatusDO vehicleEdCutoutRpressIsolationStatusDO = ITCMSVehicleOutputsRequestHandler
          .getVehicleStatusDo(edCutoutRpressisolationStatusList, request.getCarIndex(),
              VehicleEdCutoutRpressIsolationStatusDO.class);
      setStatus(request.getPropertyKey(), request.getNewValue(), vehicleEdCutoutRpressIsolationStatusDO);
      ITCMSVehicleOutputsRequestHandler.updateVehicleStatusDOList(edCutoutRpressisolationStatusList,
          vehicleEdCutoutRpressIsolationStatusDO, request.getCarIndex());
      setEdCutoutRpressIsolatedStatus(edCutoutRpressisolationStatusList,
          builder -> request.getHandler().setEdCutOutRpressIsolationStatus(builder.build().toByteArray()));
    }
    catch (InstantiationException e)
    {
      Tracer.getInstance().info(e);
    }
  }

  private void setStatus(PropertyKey<Integer> propertyKey, Integer newvalue,
      VehicleEdCutoutRpressIsolationStatusDO vehicleEdCutoutRpressIsolationStatusDO)
  {
    if (propertyKey.equals(ITCMSVehicleOutputsBrakeSystemProperties.ED_CUTOUT_STATUS))
    {
      vehicleEdCutoutRpressIsolationStatusDO.setEdCutoutActive(newvalue);
    }
    else if (propertyKey.equals(ITCMSVehicleOutputsBrakeSystemProperties.RPRESS_ISOLATION_STATUS))
    {
      vehicleEdCutoutRpressIsolationStatusDO.setRpressIsolated(newvalue);
    }
  }

  private void setEdCutoutRpressIsolatedStatus(
      List<Entry<VehicleEdCutoutRpressIsolationStatusDO>> edCutoutRpressisolationStatusList,
      Consumer<TCMSProto.EDCutOutRPRESSIsolationStatusList.Builder> builderConsumer)
  {
    TCMSProto.EDCutOutRPRESSIsolationStatusList.Builder builder = TCMSProto.EDCutOutRPRESSIsolationStatusList
        .newBuilder();
    TCMSProto.EDCutOutRPRESSIsolationStatusList.EDCutOutRpressIsolationStatus.Builder vehicleBuilder = TCMSProto.EDCutOutRPRESSIsolationStatusList.EDCutOutRpressIsolationStatus
        .newBuilder();

    VehicleEdCutoutRpressIsolationStatusDO data;
    for (int index = 0; index < edCutoutRpressisolationStatusList.size(); index++)
    {
      data = edCutoutRpressisolationStatusList.get(index).getData();

      EDCutOutState edCutOutState = getEdCutoutState(data);
      RPRESSIsolationState rpressIsolationState = getRpressIsolationState(data);

      if (edCutoutRpressisolationStatusList.size() == TCMSConstants.SIX_CAR
          && (index == TCMSConstants.T2_CAR || index == TCMSConstants.T5_CAR))
      {
        vehicleBuilder.setEdCutOutState(EDCutOutState.ED_CUT_OUT_UNKNOWN);
      }
      else if (edCutoutRpressisolationStatusList.size() == TCMSConstants.EIGHT_CAR
          && (index == TCMSConstants.T2_CAR || index == TCMSConstants.T4_CAR
              || index == TCMSConstants.T7_CAR))
      {
        vehicleBuilder.setEdCutOutState(EDCutOutState.ED_CUT_OUT_UNKNOWN);
      }
      else
      {
        vehicleBuilder.setEdCutOutState(edCutOutState);
      }

      vehicleBuilder.setCarIndex(edCutoutRpressisolationStatusList.get(index).getIndex());
      vehicleBuilder.setRpressIsolationState(rpressIsolationState);
      builder.addEdCutOutRpressIsolationStatus(vehicleBuilder.build());
    }
    builderConsumer.accept(builder);
  }

  private EDCutOutState getEdCutoutState(VehicleEdCutoutRpressIsolationStatusDO data)
  {
    EDCutOutState edCutOutState;
    if (data.getEdCutoutActive() == 1)
    {
      edCutOutState = EDCutOutState.ED_CUT_OUT_ACTIVE;
    }
    else if (data.getEdCutoutActive() == 0)
    {
      edCutOutState = EDCutOutState.ED_CUT_OUT_NOT_ACTIVE;
    }
    else
    {
      edCutOutState = EDCutOutState.ED_CUT_OUT_UNKNOWN;
    }
    return edCutOutState;
  }

  private RPRESSIsolationState getRpressIsolationState(VehicleEdCutoutRpressIsolationStatusDO data)
  {
    RPRESSIsolationState rpressIsolationState;
    if (data.getRpressIsolated() == 1)
    {
      rpressIsolationState = RPRESSIsolationState.RPRESS_ISOLATED;
    }
    else if (data.getRpressIsolated() == 0)
    {
      rpressIsolationState = RPRESSIsolationState.RPRESS_NOT_ISOLATED;
    }
    else
    {
      rpressIsolationState = RPRESSIsolationState.RPRESS_UNKNOWN;
    }
    return rpressIsolationState;
  }
}