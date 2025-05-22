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
import com.sydac.mmrbem.tcms.common.data.VehiclePantographStatusDO;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.PantographStatusList;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.PantographStatusList.Pantograph;

/**
 * This class handles Panto graph status update from vehicle outputs.
 * 
 */
public class PantoVehicleOutputRequestHandler
    implements ITCMSVehicleOutputsRequestHandler<TCMSOutputsTrainViewScreenImpl<Integer, IAppOutputsOperationScreenHandler>>
{

  private List<Entry<VehiclePantographStatusDO>> pantoStatusList = new ArrayList<>();

  @Override
  public void handleRequest(TCMSOutputsTrainViewScreenImpl<Integer, IAppOutputsOperationScreenHandler> request)
  {
    try
    {
      VehiclePantographStatusDO pantographStatusDo = ITCMSVehicleOutputsRequestHandler
          .getVehicleStatusDo(pantoStatusList, request.getCarIndex(), VehiclePantographStatusDO.class);
      setStatus(request.getPropertyKey(), request.getNewValue(), pantographStatusDo);
      ITCMSVehicleOutputsRequestHandler.updateVehicleStatusDOList(pantoStatusList, pantographStatusDo,
          request.getCarIndex());
      setPantoStatus(pantoStatusList,
          builder -> request.getHandler().setPantographStatus(builder.build().toByteArray()));
    }
    catch (InstantiationException e)
    {
      Tracer.getInstance().info(e);
    }
  }

  private void setStatus(PropertyKey<Integer> propertyKey, Integer newvalue,
      VehiclePantographStatusDO pantographStatusDo)
  {
    if (propertyKey.equals(ITCMSVehicleOutputsOperationScreenProperties.PANTOGRAPH_POSITION))
    {
      pantographStatusDo.setPantographPosition(newvalue);
    }
    else if (propertyKey
        .equals(ITCMSVehicleOutputsOperationScreenProperties.PANTOGRAPH_FAULT))
    {
      pantographStatusDo.setPantographFault(newvalue);
    }
    else if (propertyKey
        .equals(ITCMSVehicleOutputsOperationScreenProperties.PANTOGRAPH_ISOLATED))
    {
      pantographStatusDo.setPantographIsolated(newvalue);
    }
  }

  private void setPantoStatus(List<Entry<VehiclePantographStatusDO>> pantographStatusList,
      Consumer<TCMSProto.PantographStatusList.Builder> builderConsumer)
  {
    TCMSProto.PantographStatusList.Builder builder = TCMSProto.PantographStatusList.newBuilder();

    PantographStatusList.PantographStatus.Builder vehicleBuilder = TCMSProto.PantographStatusList.PantographStatus
        .newBuilder();
    VehiclePantographStatusDO data;
    Pantograph panto;
    for (int index = 0; index < pantographStatusList.size(); index++)
    {
      data = pantographStatusList.get(index).getData();
      if (data.getPantographIsolated() == 1)
      {
        panto = Pantograph.ISOLATED;
      }
      else if (data.getPantographPosition() == 0 && data.getPantographFault() == 1)
      {
        panto = Pantograph.LOWERED_FAULTY;
      }
      else if (data.getPantographPosition() == 1 && data.getPantographFault() == 1)
      {
        panto = Pantograph.RAISED_FAULTY;
      }
      else if (data.getPantographPosition() == 1)
      {
        panto = Pantograph.RAISED;
      }
      else if (data.getPantographPosition() == 0)
      {
        panto = Pantograph.LOWERED;
      }
      else
      {
        panto = Pantograph.UNKNOWN;
      }
      vehicleBuilder.setCarIndex(pantographStatusList.get(index).getIndex());
      vehicleBuilder.setPantograhState(panto);
      builder.addPantographStatus(vehicleBuilder.build());
    }
    builderConsumer.accept(builder);
  }
}