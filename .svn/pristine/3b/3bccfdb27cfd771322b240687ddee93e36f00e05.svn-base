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
import com.sydac.mmrbem.tcms.backend.app.io.handlers.IAppOutputsOperationScreenHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.io.properties.ITCMSVehicleOutputsOperationScreenProperties;
import com.sydac.mmrbem.tcms.common.data.Entry;
import com.sydac.mmrbem.tcms.common.data.VehicleVcbStatusDO;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.VCBStatusList;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.VCBStatusList.VCBState;

/**
 * This class handles VCB status update from vehicle outputs.
 * 
 */
public class VcbVehicleOutputRequestHandler implements
    ITCMSVehicleOutputsRequestHandler<TCMSOutputsTrainViewScreenImpl<Integer, IAppOutputsOperationScreenHandler>>
{

  private List<Entry<VehicleVcbStatusDO>> vcbStatusList = new ArrayList<>();

  @Override
  public void handleRequest(
      TCMSOutputsTrainViewScreenImpl<Integer, IAppOutputsOperationScreenHandler> request)
  {
    try
    {
      VehicleVcbStatusDO vcbStatusDo = ITCMSVehicleOutputsRequestHandler.getVehicleStatusDo(vcbStatusList,
          request.getCarIndex(), VehicleVcbStatusDO.class);
      setStatus(request.getPropertyKey(), request.getNewValue(), vcbStatusDo);
      ITCMSVehicleOutputsRequestHandler.updateVehicleStatusDOList(vcbStatusList, vcbStatusDo,
          request.getCarIndex());
      setVcbStatus(vcbStatusList,
          builder -> request.getHandler().setVcbStatus(builder.build().toByteArray()));
    }
    catch (InstantiationException e)
    {
      Tracer.getInstance().info(e);
    }
  }

  private void setStatus(PropertyKey<Integer> propertyKey, Integer newvalue, VehicleVcbStatusDO vcbStatusDo)
  {
    if (propertyKey.equals(ITCMSVehicleOutputsOperationScreenProperties.VCB_STATE))
    {
      vcbStatusDo.setVcbState(newvalue);
    }
    else if (propertyKey.equals(ITCMSVehicleOutputsOperationScreenProperties.VCB_FAULT))
    {
      vcbStatusDo.setVcbFault(newvalue);
    }
    else if (propertyKey.equals(ITCMSVehicleOutputsOperationScreenProperties.VCB_ISOLATED))
    {
      vcbStatusDo.setVcbIsolated(newvalue);
    }
  }

  private void setVcbStatus(List<Entry<VehicleVcbStatusDO>> vcbStatusList,
      Consumer<TCMSProto.VCBStatusList.Builder> builderConsumer)
  {
    TCMSProto.VCBStatusList.Builder builder = TCMSProto.VCBStatusList.newBuilder();

    VCBStatusList.VCBStatus.Builder vehicleBuilder = TCMSProto.VCBStatusList.VCBStatus.newBuilder();
    VehicleVcbStatusDO data;
    VCBState state;
    for (int index = 0; index < vcbStatusList.size(); index++)
    {
      data = vcbStatusList.get(index).getData();
      if (data.getVcbIsolated() == 1)
      {
        state = VCBState.ISOLATED;
      }
      else if (data.getVcbState() == 1 && data.getVcbFault() == 1)
      {
        state = VCBState.CLOSED_AND_FAULTY;
      }
      else if (data.getVcbState() == 0 && data.getVcbFault() == 1)
      {
        state = VCBState.OPEN_AND_FAULTY;
      }
      else if (data.getVcbState() == 1)
      {
        state = VCBState.CLOSED;
      }
      else if (data.getVcbState() == 0)
      {
        state = VCBState.OPEN;
      }
      else
      {
        state = VCBState.UNKNOWN;
      }
      vehicleBuilder.setCarIndex(vcbStatusList.get(index).getIndex());
      vehicleBuilder.setVcbState(state);
      builder.addVcbStatus(vehicleBuilder.build());
    }
    builderConsumer.accept(builder);
  }
}