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
import com.sydac.mmrbem.tcms.common.data.VehicleMainCompStatusDO;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.MainCompStatusList.MainCompState;

/**
 * This class handles MV Main Comp Status update from vehicle outputs
 * 
 */
public class MainCompStatusVehicleOutputsRequestHandler implements
    ITCMSVehicleOutputsRequestHandler<TCMSOutputsMediumVoltageSystemScreenImpl<Integer, IAppOutputsMediumVoltageSystemScreenHandler>>
{

  protected final List<Entry<VehicleMainCompStatusDO>> mainCompStatus = new ArrayList<>();

  @Override
  public void handleRequest(
      TCMSOutputsMediumVoltageSystemScreenImpl<Integer, IAppOutputsMediumVoltageSystemScreenHandler> request)
  {
    try
    {
      VehicleMainCompStatusDO vehicleMainCompStatusDO = ITCMSVehicleOutputsRequestHandler
          .getVehicleStatusDo(mainCompStatus, request.getCarIndex(), VehicleMainCompStatusDO.class);
      setStatus(request.getPropertyKey(), request.getNewValue(), vehicleMainCompStatusDO);
      ITCMSVehicleOutputsRequestHandler.updateVehicleStatusDOList(mainCompStatus, vehicleMainCompStatusDO,
          request.getCarIndex());
      setMainCompStatus(mainCompStatus, request.getVehicleDetailModelList(),
          builder -> request.getHandler().setMvMainCompStatusList(builder.build().toByteArray()));
    }
    catch (InstantiationException e)
    {
      Tracer.getInstance().info(e);
    }
  }

  private void setStatus(PropertyKey<Integer> propertyKey, Integer newvalue,
      VehicleMainCompStatusDO vehicleMainCompStatusDO)
  {
    if (propertyKey.equals(ITCMSVehicleOutputsMediumVoltageSystemProperties.MAIN_COMPRESSOR))
    {
      vehicleMainCompStatusDO.setMainCompStatus(newvalue);
    }
  }

  private void setMainCompStatus(List<Entry<VehicleMainCompStatusDO>> mainCompStatusList,
      List<VehicleDetailModel> vehicleDetailModelList,
      Consumer<TCMSProto.MainCompStatusList.Builder> builderConsumer)
  {
    TCMSProto.MainCompStatusList.Builder builder = TCMSProto.MainCompStatusList.newBuilder();
    TCMSProto.MainCompStatusList.MainCompStatus.Builder vehicleBuilder = TCMSProto.MainCompStatusList.MainCompStatus
        .newBuilder();

    VehicleMainCompStatusDO data;
    for (int index = 0; index < mainCompStatusList.size(); index++)
    {
      int carIndex = mainCompStatusList.get(index).getIndex();
      MainCompState mainCompState = MainCompState.MAIN_COMP_INACTIVE;
      if (vehicleDetailModelList != null && vehicleDetailModelList.size() > carIndex)
      {
        data = mainCompStatusList.get(index).getData();
        mainCompState = getMainCompState(data);
      }
      vehicleBuilder.setCarIndex(mainCompStatusList.get(index).getIndex());
      vehicleBuilder.setMainCompState(mainCompState);
      builder.addMainCompStatus(vehicleBuilder.build());
    }
    builderConsumer.accept(builder);
  }

  private MainCompState getMainCompState(VehicleMainCompStatusDO data)
  {
    MainCompState mainCompState;
    if (data.getMainCompStatus() == MainCompState.MAIN_COMP_ACTIVE_VALUE)
    {
      mainCompState = MainCompState.MAIN_COMP_ACTIVE;
    }
    else
    {
      mainCompState = MainCompState.MAIN_COMP_INACTIVE;
    }
    return mainCompState;
  }
}
