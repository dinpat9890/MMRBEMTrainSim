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
import com.sydac.mmrbem.tcms.common.data.VehicleDetailModel;
import com.sydac.mmrbem.tcms.common.data.VehiclePECStatusDO;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.PECStatusList.PECState;

/**
 * This class handles MV PEC Status update from vehicle outputs
 * 
 */
public class PECStatusVehicleOutputsRequestHandler implements
    ITCMSVehicleOutputsRequestHandler<TCMSOutputsMediumVoltageSystemScreenImpl<Integer, IAppOutputsMediumVoltageSystemScreenHandler>>
{

  protected final List<Entry<VehiclePECStatusDO>> pecStatus = new ArrayList<>();

  @Override
  public void handleRequest(
      TCMSOutputsMediumVoltageSystemScreenImpl<Integer, IAppOutputsMediumVoltageSystemScreenHandler> request)
  {
    try
    {
      VehiclePECStatusDO vehiclePECStatusDO = ITCMSVehicleOutputsRequestHandler.getVehicleStatusDo(pecStatus,
          request.getCarIndex(), VehiclePECStatusDO.class);
      setStatus(request.getPropertyKey(), request.getNewValue(), vehiclePECStatusDO);
      ITCMSVehicleOutputsRequestHandler.updateVehicleStatusDOList(pecStatus, vehiclePECStatusDO,
          request.getCarIndex());
      setPECStatus(pecStatus, request.getVehicleDetailModelList(),
          builder -> request.getHandler().setMvPecSwitchStatusList(builder.build().toByteArray()));
    }
    catch (InstantiationException e)
    {
      Tracer.getInstance().info(e);
    }
  }

  private void setStatus(PropertyKey<Integer> propertyKey, Integer newvalue,
      VehiclePECStatusDO vehiclePECStatusDO)
  {
    if (propertyKey.equals(ITCMSVehicleOutputsMediumVoltageSystemProperties.POWER_EXTENSION_CONTACTOR))
    {
      vehiclePECStatusDO.setPecStatus(newvalue);
    }
  }

  private void setPECStatus(List<Entry<VehiclePECStatusDO>> pecStatusList,
      List<VehicleDetailModel> vehicleDetailModelList,
      Consumer<TCMSProto.PECStatusList.Builder> builderConsumer)
  {
    TCMSProto.PECStatusList.Builder builder = TCMSProto.PECStatusList.newBuilder();
    TCMSProto.PECStatusList.PECStatus.Builder vehicleBuilder = TCMSProto.PECStatusList.PECStatus.newBuilder();

    VehiclePECStatusDO data;
    for (int index = 0; index < pecStatusList.size(); index++)
    {
      int carIndex = pecStatusList.get(index).getIndex();
      PECState pecState = PECState.PEC_OPEN;
      if (vehicleDetailModelList != null && vehicleDetailModelList.size() > carIndex)
      {
        data = pecStatusList.get(index).getData();
        pecState = getPECStatus(data);
      }
      vehicleBuilder.setCarIndex(pecStatusList.get(index).getIndex());
      vehicleBuilder.setPecState(pecState);
      builder.addPecStatus(vehicleBuilder.build());
    }
    builderConsumer.accept(builder);
  }

  private PECState getPECStatus(VehiclePECStatusDO data)
  {
    PECState pecState;
    if (data.getPecStatus() == PECState.PEC_CLOSED_VALUE)
    {
      pecState = PECState.PEC_CLOSED;
    }
    else
    {
      pecState = PECState.PEC_OPEN;
    }
    return pecState;
  }
}
