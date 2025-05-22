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
import com.sydac.mmrbem.tcms.backend.app.io.handlers.IAppOutputsBatteryScreenHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.io.properties.ITCMSVehicleOutputsBatterySystemProperties;
import com.sydac.mmrbem.tcms.common.data.Entry;
import com.sydac.mmrbem.tcms.common.data.VehicleBcgStatusDO;
import com.sydac.mmrbem.tcms.common.data.VehicleDetailModel;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.BCGStatusList.BCGState;
import com.sydac.mmrbem.tcms.common.state.TCMSConstants;

/**
 * This class handles BCG status update from vehicle outputs
 * 
 */
public class BcgStatusVehicleOutputsRequestHandler implements
    ITCMSVehicleOutputsRequestHandler<TCMSOutputsBatterySystemScreenImpl<Integer, IAppOutputsBatteryScreenHandler>>
{

  protected final List<Entry<VehicleBcgStatusDO>> bcgStatusList = new ArrayList<>();

  @Override
  public void handleRequest(
      TCMSOutputsBatterySystemScreenImpl<Integer, IAppOutputsBatteryScreenHandler> request)
  {
    try
    {
      VehicleBcgStatusDO vehicleBcgStatusDO = ITCMSVehicleOutputsRequestHandler
          .getVehicleStatusDo(bcgStatusList, request.getCarIndex(), VehicleBcgStatusDO.class);
      setStatus(request.getPropertyKey(), request.getNewValue(), vehicleBcgStatusDO);
      ITCMSVehicleOutputsRequestHandler.updateVehicleStatusDOList(bcgStatusList, vehicleBcgStatusDO,
          request.getCarIndex());
      setBcgStatusList(bcgStatusList, request.getVehicleDetailModelList(),
          builder -> request.getHandler().setBcgStatus(builder.build().toByteArray()));
    }
    catch (InstantiationException e)
    {
      Tracer.getInstance().info(e);
    }
  }

  private void setStatus(PropertyKey<Integer> propertyKey, Integer newvalue,
      VehicleBcgStatusDO vehicleBcgStatusDO)
  {
    if (propertyKey.equals(ITCMSVehicleOutputsBatterySystemProperties.BCG_1_FAULT))
    {
      vehicleBcgStatusDO.setBcgFault1(newvalue);
    }
    else if (propertyKey.equals(ITCMSVehicleOutputsBatterySystemProperties.BCG_1_ISOLATED))
    {
      vehicleBcgStatusDO.setBcgIsolate1(newvalue);
    }
    else if (propertyKey.equals(ITCMSVehicleOutputsBatterySystemProperties.BCG_1_STATUS))
    {
      vehicleBcgStatusDO.setBcgStatus1(newvalue);
    }
    else if (propertyKey.equals(ITCMSVehicleOutputsBatterySystemProperties.BCG_2_FAULT))
    {
      vehicleBcgStatusDO.setBcgFault2(newvalue);
    }
    else if (propertyKey.equals(ITCMSVehicleOutputsBatterySystemProperties.BCG_2_ISOLATED))
    {
      vehicleBcgStatusDO.setBcgIsolate2(newvalue);
    }
    else if (propertyKey.equals(ITCMSVehicleOutputsBatterySystemProperties.BCG_2_STATUS))
    {
      vehicleBcgStatusDO.setBcgStatus2(newvalue);
    }
  }

  private void setBcgStatusList(List<Entry<VehicleBcgStatusDO>> bcgStatusList,
      List<VehicleDetailModel> vehicleDetailModelList,
      Consumer<TCMSProto.BCGStatusList.Builder> builderConsumer)
  {
    TCMSProto.BCGStatusList.Builder builder = TCMSProto.BCGStatusList.newBuilder();
    TCMSProto.BCGStatusList.BCGStatus.Builder vehicleBuilder = TCMSProto.BCGStatusList.BCGStatus.newBuilder();

    VehicleBcgStatusDO data;
    for (int index = 0; index < bcgStatusList.size(); index++)
    {
      int carIndex = bcgStatusList.get(index).getIndex();
      BCGState bcgState1 = BCGState.BCG_BLANK;
      BCGState bcgState2 = BCGState.BCG_BLANK;

      if (vehicleDetailModelList != null && vehicleDetailModelList.size() > carIndex)
      {
        String carClassCode = vehicleDetailModelList.get(carIndex).getCarClassCode();
        if (TCMSConstants.M_CAR.equals(carClassCode))
        {
          data = bcgStatusList.get(index).getData();

          bcgState1 = getBcgStatusList1(data);
          bcgState2 = getBcgStatusList2(data);
        }
      }
      vehicleBuilder.setCarIndex(bcgStatusList.get(index).getIndex());
      vehicleBuilder.setBcgState1(bcgState1);
      vehicleBuilder.setBcgState2(bcgState2);
      builder.addBcgStatus(vehicleBuilder.build());
    }
    builderConsumer.accept(builder);
  }

  private BCGState getBcgStatusList1(VehicleBcgStatusDO data)
  {
    BCGState bcgState;
    if (data.getBcgFault1() == 1)
    {
      bcgState = BCGState.BCG_FAULTY;
    }
    else if (data.getBcgIsolate1() == 1)
    {
      bcgState = BCGState.BCG_ISOLATED;
    }
    else if (data.getBcgStatus1() == 1)
    {
      bcgState = BCGState.BCG_OK;
    }
    else
    {
      bcgState = BCGState.BCG_UNKNOWN;
    }
    return bcgState;
  }

  private BCGState getBcgStatusList2(VehicleBcgStatusDO data)
  {
    BCGState bcgState;
    if (data.getBcgFault2() == 1)
    {
      bcgState = BCGState.BCG_FAULTY;
    }
    else if (data.getBcgIsolate2() == 1)
    {
      bcgState = BCGState.BCG_ISOLATED;
    }
    else if (data.getBcgStatus2() == 1)
    {
      bcgState = BCGState.BCG_OK;
    }
    else
    {
      bcgState = BCGState.BCG_UNKNOWN;
    }
    return bcgState;
  }

}
