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
import com.sydac.mmrbem.tcms.common.data.VehicleEpBrakeDeliveredValueDO;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.EPBrakeDeliveredStatusList;
import com.sydac.mmrbem.tcms.common.utils.UnitConverterHelper;

/**
 * This class handles ED Brake Delivered Value update from vehicle outputs.
 * 
 */
public class EpBrakeDeliveredVehicleOutputRequestHandler implements
    ITCMSVehicleOutputsRequestHandler<TCMSOutputsBrakeSystemScreenImpl<Integer, IAppOutputsBrakeScreenHandler>>
{

  private List<Entry<VehicleEpBrakeDeliveredValueDO>> epBrakeDeliveredValueList = new ArrayList<>();

  @Override
  public void handleRequest(TCMSOutputsBrakeSystemScreenImpl<Integer, IAppOutputsBrakeScreenHandler> request)
  {
    try
    {
      VehicleEpBrakeDeliveredValueDO vehicleEdBrakeDeliveredValueDO = ITCMSVehicleOutputsRequestHandler
          .getVehicleStatusDo(epBrakeDeliveredValueList, request.getCarIndex(),
              VehicleEpBrakeDeliveredValueDO.class);
      vehicleEdBrakeDeliveredValueDO.setEdBrakeDelivered(request.newValue);
      ITCMSVehicleOutputsRequestHandler.updateVehicleStatusDOList(epBrakeDeliveredValueList,
          vehicleEdBrakeDeliveredValueDO, request.getCarIndex());
      setEpBrakeDelivered(epBrakeDeliveredValueList,
          builder -> request.getHandler().setEpBrakeDeliveredStatus(builder.build().toByteArray()));
    }
    catch (InstantiationException e)
    {
      Tracer.getInstance().info(e);
    }
  }

  private void setEpBrakeDelivered(List<Entry<VehicleEpBrakeDeliveredValueDO>> epBrakeDeliveredValueList,
      Consumer<TCMSProto.EPBrakeDeliveredStatusList.Builder> builderConsumer)
  {
    TCMSProto.EPBrakeDeliveredStatusList.Builder builder = TCMSProto.EPBrakeDeliveredStatusList.newBuilder();
    EPBrakeDeliveredStatusList.EPBrakeDeliveredStatus.Builder vehicleBuilder = EPBrakeDeliveredStatusList.EPBrakeDeliveredStatus
        .newBuilder();

    {
      epBrakeDeliveredValueList.forEach(edBrakeDeliveredValueEntry -> {

        vehicleBuilder.setCarIndex(edBrakeDeliveredValueEntry.getIndex());
        vehicleBuilder.setEpBrakeDeliveredEffort(
            UnitConverterHelper.convertNToKN(edBrakeDeliveredValueEntry.getData().getEdBrakeDelivered()));
        builder.addEpBrakeDeliveredStatus(vehicleBuilder.build());

      });
    }

    builderConsumer.accept(builder);
  }
}