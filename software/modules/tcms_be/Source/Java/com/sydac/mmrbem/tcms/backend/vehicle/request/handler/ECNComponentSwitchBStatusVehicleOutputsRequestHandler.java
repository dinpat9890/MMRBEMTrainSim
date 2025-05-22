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
import com.sydac.mmrbem.tcms.backend.app.io.handlers.IAppOutputsECNScreenHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.io.properties.ITCMSVehicleOutputsECNScreenProperties;
import com.sydac.mmrbem.tcms.backend.vehicle.io.properties.ITCMSVehicleOutputsProperties;
import com.sydac.mmrbem.tcms.common.data.Entry;
import com.sydac.mmrbem.tcms.common.data.VehicleDetailModel;
import com.sydac.mmrbem.tcms.common.data.VehicleECNComponentSwitchStatusDO;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.ECNComponentSwitchStatusList.ECNComponentSwitchState;
import com.sydac.mmrbem.tcms.common.state.TCMSConstants;

/**
 * This class handles ECN Component Switch B Status update from vehicle outputs
 * 
 */
public class ECNComponentSwitchBStatusVehicleOutputsRequestHandler implements
    ITCMSVehicleOutputsRequestHandler<TCMSOutputsECNScreenImpl<Integer, IAppOutputsECNScreenHandler>>
{

  protected final List<Entry<VehicleECNComponentSwitchStatusDO>> componentSwitchBStatus = new ArrayList<>();

  @Override
  public void handleRequest(TCMSOutputsECNScreenImpl<Integer, IAppOutputsECNScreenHandler> request)
  {
    try
    {
      VehicleECNComponentSwitchStatusDO vehicleECNComponentSwitchStatusDO = ITCMSVehicleOutputsRequestHandler
          .getVehicleStatusDo(componentSwitchBStatus, request.getCarIndex(),
              VehicleECNComponentSwitchStatusDO.class);
      setStatus(request.getPropertyKey(), request.getNewValue(), vehicleECNComponentSwitchStatusDO);
      ITCMSVehicleOutputsRequestHandler.updateVehicleStatusDOList(componentSwitchBStatus,
          vehicleECNComponentSwitchStatusDO, request.getCarIndex());
      setComponentSwitchStatus(componentSwitchBStatus, request.getVehicleDetailModelList(),
          builder -> request.getHandler().setEcnCsBStatusList(builder.build().toByteArray()));
    }
    catch (InstantiationException e)
    {
      Tracer.getInstance().info(e);
    }
  }

  private void setStatus(PropertyKey<Integer> propertyKey, Integer newvalue,
      VehicleECNComponentSwitchStatusDO vehicleECNComponentSwitchStatusDO)
  {
    if (propertyKey.equals(ITCMSVehicleOutputsProperties.DUMMY_FAULT_SIGNAL))
    {
      vehicleECNComponentSwitchStatusDO.setComponentSwitchBFault(newvalue);
    }
    else if (propertyKey.equals(ITCMSVehicleOutputsECNScreenProperties.CONSIST_SWITCH_STATUS_B))
    {
      vehicleECNComponentSwitchStatusDO.setComponentSwitchBStatus(newvalue);
    }
  }

  private void setComponentSwitchStatus(List<Entry<VehicleECNComponentSwitchStatusDO>> componentSwitchStatus,
      List<VehicleDetailModel> vehicleDetailModelList,
      Consumer<TCMSProto.ECNComponentSwitchStatusList.Builder> builderConsumer)
  {
    TCMSProto.ECNComponentSwitchStatusList.Builder builder = TCMSProto.ECNComponentSwitchStatusList
        .newBuilder();
    TCMSProto.ECNComponentSwitchStatusList.ECNComponentSwitchStatus.Builder vehicleBuilder = TCMSProto.ECNComponentSwitchStatusList.ECNComponentSwitchStatus
        .newBuilder();

    VehicleECNComponentSwitchStatusDO data;
    for (int index = 0; index < componentSwitchStatus.size(); index++)
    {
      int carIndex = componentSwitchStatus.get(index).getIndex();
      ECNComponentSwitchState ecnComponentSwitchState = ECNComponentSwitchState.CS_NOT_AVAILABLE;
      if (vehicleDetailModelList != null && vehicleDetailModelList.size() > carIndex)
      {
        data = componentSwitchStatus.get(index).getData();
        ecnComponentSwitchState = getComponentSwitchState(data);
      }
      vehicleBuilder.setCarIndex(componentSwitchStatus.get(index).getIndex());
      vehicleBuilder.setEcnComponentSwitchState(ecnComponentSwitchState);
      builder.addEcnComponentSwitchStatus(vehicleBuilder.build());
    }
    builderConsumer.accept(builder);
  }

  private ECNComponentSwitchState getComponentSwitchState(VehicleECNComponentSwitchStatusDO data)
  {
    ECNComponentSwitchState ecnComponentSwitchState;
    if (data.getComponentSwitchBFault() == TCMSConstants.ECN_COMPONENT_FAULTY)
    {
      ecnComponentSwitchState = ECNComponentSwitchState.CS_FAULTY;
    }
    else if (data.getComponentSwitchBStatus() == TCMSConstants.ECN_COMPONENT_OK)
    {
      ecnComponentSwitchState = ECNComponentSwitchState.CS_OK;
    }
    else
    {
      ecnComponentSwitchState = ECNComponentSwitchState.CS_NOT_AVAILABLE;
    }
    return ecnComponentSwitchState;
  }
}
