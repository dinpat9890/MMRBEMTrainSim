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
import com.sydac.mmrbem.tcms.common.data.VehicleALGStatusDO;
import com.sydac.mmrbem.tcms.common.data.VehicleDetailModel;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.ALGStatusList.ALGState;
import com.sydac.mmrbem.tcms.common.state.TCMSConstants;

/**
 * This class handles ECN ALG Status update from vehicle outputs
 * 
 */
public class ECNAlgStatusVehicleOutputsRequestHandler implements
    ITCMSVehicleOutputsRequestHandler<TCMSOutputsECNScreenImpl<Integer, IAppOutputsECNScreenHandler>>
{

  protected final List<Entry<VehicleALGStatusDO>> algStatus = new ArrayList<>();

  @Override
  public void handleRequest(TCMSOutputsECNScreenImpl<Integer, IAppOutputsECNScreenHandler> request)
  {
    try
    {
      VehicleALGStatusDO vehicleALGStatusDO = ITCMSVehicleOutputsRequestHandler.getVehicleStatusDo(algStatus,
          request.getCarIndex(), VehicleALGStatusDO.class);
      setStatus(request.getPropertyKey(), request.getNewValue(), vehicleALGStatusDO);
      ITCMSVehicleOutputsRequestHandler.updateVehicleStatusDOList(algStatus, vehicleALGStatusDO,
          request.getCarIndex());
      setComponentSwitchStatus(algStatus, request.getVehicleDetailModelList(),
          builder -> request.getHandler().setEcnAlgStatusList(builder.build().toByteArray()));
    }
    catch (InstantiationException e)
    {
      Tracer.getInstance().info(e);
    }
  }

  private void setStatus(PropertyKey<Integer> propertyKey, Integer newvalue,
      VehicleALGStatusDO vehicleALGStatusDO)
  {
    if (propertyKey.equals(ITCMSVehicleOutputsProperties.DUMMY_FAULT_SIGNAL))
    {
      vehicleALGStatusDO.setAlgFault(newvalue);
    }
    else if (propertyKey.equals(ITCMSVehicleOutputsECNScreenProperties.ECN_ALG_STATUS))
    {
      vehicleALGStatusDO.setAlgStatus(newvalue);
    }
  }

  private void setComponentSwitchStatus(List<Entry<VehicleALGStatusDO>> componentSwitchStatus,
      List<VehicleDetailModel> vehicleDetailModelList,
      Consumer<TCMSProto.ALGStatusList.Builder> builderConsumer)
  {
    TCMSProto.ALGStatusList.Builder builder = TCMSProto.ALGStatusList.newBuilder();
    TCMSProto.ALGStatusList.ALGStatus.Builder vehicleBuilder = TCMSProto.ALGStatusList.ALGStatus.newBuilder();

    VehicleALGStatusDO data;
    for (int index = 0; index < componentSwitchStatus.size(); index++)
    {
      int carIndex = componentSwitchStatus.get(index).getIndex();
      ALGState algState = ALGState.ALG_NOT_AVAILABLE;
      if (vehicleDetailModelList != null && vehicleDetailModelList.size() > carIndex)
      {
        data = componentSwitchStatus.get(index).getData();
        algState = getAlgState(data);
      }
      vehicleBuilder.setCarIndex(componentSwitchStatus.get(index).getIndex());
      vehicleBuilder.setAlgState(algState);
      builder.addAlgStatus(vehicleBuilder.build());
    }
    builderConsumer.accept(builder);
  }

  private ALGState getAlgState(VehicleALGStatusDO data)
  {
    ALGState algState;
    if (data.getAlgFault() == TCMSConstants.ECN_COMPONENT_FAULTY)
    {
      algState = ALGState.ALG_FAULTY;
    }
    else if (data.getAlgStatus() == TCMSConstants.ECN_COMPONENT_OK)
    {
      algState = ALGState.ALG_OK;
    }
    else
    {
      algState = ALGState.ALG_NOT_AVAILABLE;
    }
    return algState;
  }
}
