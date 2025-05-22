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
import com.sydac.mmrbem.tcms.backend.app.io.handlers.IAppOutputsBrakeScreenHandler;
import com.sydac.mmrbem.tcms.common.data.Entry;
import com.sydac.mmrbem.tcms.common.data.VehicleEdBrakeRequestedValueDO;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.EDBrakeRequestedStatusList;
import com.sydac.mmrbem.tcms.common.utils.UnitConverterHelper;

/**
 * This class handles ED Brake Requested Value update from vehicle outputs.
 * 
 */
public class EdBrakeRequestedVehicleOutputRequestHandler implements
    ITCMSVehicleOutputsRequestHandler<TCMSOutputsBrakeSystemScreenImpl<Integer, IAppOutputsBrakeScreenHandler>>
{

  private List<Entry<VehicleEdBrakeRequestedValueDO>> edBrakeRequestedValueList = new ArrayList<>();

  @Override
  public void handleRequest(TCMSOutputsBrakeSystemScreenImpl<Integer, IAppOutputsBrakeScreenHandler> request)
  {
    try
    {
      VehicleEdBrakeRequestedValueDO vehicleEdBrakeRequestedValueDO = ITCMSVehicleOutputsRequestHandler
          .getVehicleStatusDo(edBrakeRequestedValueList, request.getCarIndex(),
              VehicleEdBrakeRequestedValueDO.class);
      vehicleEdBrakeRequestedValueDO.setEdBrakeRequested(request.newValue);
      ITCMSVehicleOutputsRequestHandler.updateVehicleStatusDOList(edBrakeRequestedValueList,
          vehicleEdBrakeRequestedValueDO, request.getCarIndex());
      setEdBrakeRequestedValueList(edBrakeRequestedValueList,
          builder -> request.getHandler().setEdBrakeRequestedStatus(builder.build().toByteArray()));
    }
    catch (InstantiationException e)
    {
      Tracer.getInstance().info(e);
    }
  }

  private void setEdBrakeRequestedValueList(
      List<Entry<VehicleEdBrakeRequestedValueDO>> edBrakeRequestedValueList,
      Consumer<TCMSProto.EDBrakeRequestedStatusList.Builder> builderConsumer)
  {
    TCMSProto.EDBrakeRequestedStatusList.Builder builder = TCMSProto.EDBrakeRequestedStatusList.newBuilder();
    EDBrakeRequestedStatusList.EDBrakeRequestedStatus.Builder vehicleBuilder = EDBrakeRequestedStatusList.EDBrakeRequestedStatus
        .newBuilder();

    {
      edBrakeRequestedValueList.forEach(edBrakeRequestedValueEntry -> {

        vehicleBuilder.setCarIndex(edBrakeRequestedValueEntry.getIndex());
        vehicleBuilder.setEdBrakeRequestedEffort(
            UnitConverterHelper.convertNToKN(edBrakeRequestedValueEntry.getData().getEdBrakeRequested()));
        builder.addEdBrakeRequestedStatus(vehicleBuilder.build());

      });
    }

    builderConsumer.accept(builder);
  }
}