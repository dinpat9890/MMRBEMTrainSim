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
import com.sydac.mmrbem.tcms.backend.app.io.handlers.IAppOutputsBatteryScreenHandler;
import com.sydac.mmrbem.tcms.common.data.Entry;
import com.sydac.mmrbem.tcms.common.data.VehicleBcgOutputVoltageValueDO;
import com.sydac.mmrbem.tcms.common.data.VehicleDetailModel;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.BCGOutputVoltageStatusList;
import com.sydac.mmrbem.tcms.common.state.ApplicationConstants;
import com.sydac.mmrbem.tcms.common.state.TCMSConstants;

/**
 * This class handles BCG Output Voltage update from vehicle outputs
 * 
 */
public class BcgOutputVoltageVehicleOutputsRequestHandler implements
    ITCMSVehicleOutputsRequestHandler<TCMSOutputsBatterySystemScreenImpl<Integer, IAppOutputsBatteryScreenHandler>>
{

  protected final List<Entry<VehicleBcgOutputVoltageValueDO>> bcgOutVoltageList = new ArrayList<>();

  @Override
  public void handleRequest(
      TCMSOutputsBatterySystemScreenImpl<Integer, IAppOutputsBatteryScreenHandler> request)
  {
    try
    {
      VehicleBcgOutputVoltageValueDO vehicleBcgOutputVoltageValueDO = ITCMSVehicleOutputsRequestHandler
          .getVehicleStatusDo(bcgOutVoltageList, request.getCarIndex(), VehicleBcgOutputVoltageValueDO.class);
      vehicleBcgOutputVoltageValueDO.setBcgOutputVoltage(request.newValue);
      ITCMSVehicleOutputsRequestHandler.updateVehicleStatusDOList(bcgOutVoltageList,
          vehicleBcgOutputVoltageValueDO, request.getCarIndex());
      setBcgOutputVoltageList(bcgOutVoltageList, request.getVehicleDetailModelList(),
          builder -> request.getHandler().setBcgOutputVoltageStatus(builder.build().toByteArray()));
    }
    catch (InstantiationException e)
    {
      Tracer.getInstance().info(e);
    }
  }

  private void setBcgOutputVoltageList(List<Entry<VehicleBcgOutputVoltageValueDO>> bcgOutVoltageList,
      List<VehicleDetailModel> vehicleDetailModelList,
      Consumer<TCMSProto.BCGOutputVoltageStatusList.Builder> builderConsumer)
  {
    TCMSProto.BCGOutputVoltageStatusList.Builder builder = TCMSProto.BCGOutputVoltageStatusList.newBuilder();

    BCGOutputVoltageStatusList.BCGOutputVoltage.Builder vehicleBuilder = BCGOutputVoltageStatusList.BCGOutputVoltage
        .newBuilder();

    for (int index = 0; index < bcgOutVoltageList.size(); index++)
    {
      int carIndex = bcgOutVoltageList.get(index).getIndex();
      int value = ApplicationConstants.VALUE_NOT_APPLICABLE;
      if (vehicleDetailModelList != null && vehicleDetailModelList.size() > carIndex)
      {
        String carClassCode = vehicleDetailModelList.get(carIndex).getCarClassCode();
        if (TCMSConstants.M_CAR.equals(carClassCode))
        {
          value = bcgOutVoltageList.get(carIndex).getData().getBcgOutputVoltage();
        }
      }
      vehicleBuilder.setCarIndex(carIndex);
      vehicleBuilder.setBcgOutputVoltage(value);
      builder.addBcgOutputVoltage(vehicleBuilder.build());
    }
    builderConsumer.accept(builder);
  }
}
