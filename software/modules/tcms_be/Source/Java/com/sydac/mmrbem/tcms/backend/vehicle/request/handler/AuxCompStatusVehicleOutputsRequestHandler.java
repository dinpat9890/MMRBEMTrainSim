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
import com.sydac.mmrbem.tcms.backend.app.io.handlers.IAppOutputsMediumVoltageSystemScreenHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.io.properties.ITCMSVehicleOutputsMediumVoltageSystemProperties;
import com.sydac.mmrbem.tcms.common.data.Entry;
import com.sydac.mmrbem.tcms.common.data.VehicleAuxCompStatusDO;
import com.sydac.mmrbem.tcms.common.data.VehicleDetailModel;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.AuxCompStatusList.AuxCompState;

/**
 * This class handles MV Aux Comp Status update from vehicle outputs
 * 
 */
public class AuxCompStatusVehicleOutputsRequestHandler implements
    ITCMSVehicleOutputsRequestHandler<TCMSOutputsMediumVoltageSystemScreenImpl<Integer, IAppOutputsMediumVoltageSystemScreenHandler>>
{

  protected final List<Entry<VehicleAuxCompStatusDO>> auxCompStatus = new ArrayList<>();

  @Override
  public void handleRequest(
      TCMSOutputsMediumVoltageSystemScreenImpl<Integer, IAppOutputsMediumVoltageSystemScreenHandler> request)
  {
    try
    {
      VehicleAuxCompStatusDO vehicleAuxCompStatusDO = ITCMSVehicleOutputsRequestHandler
          .getVehicleStatusDo(auxCompStatus, request.getCarIndex(), VehicleAuxCompStatusDO.class);
      setStatus(request.getPropertyKey(), request.getNewValue(), vehicleAuxCompStatusDO);
      ITCMSVehicleOutputsRequestHandler.updateVehicleStatusDOList(auxCompStatus, vehicleAuxCompStatusDO,
          request.getCarIndex());
      setAuxCompStatus(auxCompStatus, request.getVehicleDetailModelList(),
          builder -> request.getHandler().setMvAuxCompStatusList(builder.build().toByteArray()));
    }
    catch (InstantiationException e)
    {
      Tracer.getInstance().info(e);
    }
  }

  private void setStatus(PropertyKey<Integer> propertyKey, Integer newvalue,
      VehicleAuxCompStatusDO vehicleAuxCompStatusDO)
  {
    if (propertyKey.equals(ITCMSVehicleOutputsMediumVoltageSystemProperties.AUX_COMPRESSOR))
    {
      vehicleAuxCompStatusDO.setAuxCompStatus(newvalue);
    }
  }

  private void setAuxCompStatus(List<Entry<VehicleAuxCompStatusDO>> auxCompStatusList,
      List<VehicleDetailModel> vehicleDetailModelList,
      Consumer<TCMSProto.AuxCompStatusList.Builder> builderConsumer)
  {
    TCMSProto.AuxCompStatusList.Builder builder = TCMSProto.AuxCompStatusList.newBuilder();
    TCMSProto.AuxCompStatusList.AuxCompStatus.Builder vehicleBuilder = TCMSProto.AuxCompStatusList.AuxCompStatus
        .newBuilder();

    VehicleAuxCompStatusDO data;
    for (int index = 0; index < auxCompStatusList.size(); index++)
    {
      int carIndex = auxCompStatusList.get(index).getIndex();
      AuxCompState auxCompState = AuxCompState.AUX_COMP_INACTIVE;
      if (vehicleDetailModelList != null && vehicleDetailModelList.size() > carIndex)
      {
        data = auxCompStatusList.get(index).getData();
        auxCompState = getAuxCompState(data);
      }
      vehicleBuilder.setCarIndex(auxCompStatusList.get(index).getIndex());
      vehicleBuilder.setAuxCompState(auxCompState);
      builder.addAuxCompStatus(vehicleBuilder.build());
    }
    builderConsumer.accept(builder);
  }

  private AuxCompState getAuxCompState(VehicleAuxCompStatusDO data)
  {
    AuxCompState auxCompState;
    if (data.getAuxCompStatus() == AuxCompState.AUX_COMP_ACTIVE_VALUE)
    {
      auxCompState = AuxCompState.AUX_COMP_ACTIVE;
    }
    else
    {
      auxCompState = AuxCompState.AUX_COMP_INACTIVE;
    }
    return auxCompState;
  }
}
