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
import com.sydac.mmrbem.tcms.backend.app.io.handlers.IAppOutputsHVACSystemScreenHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.io.properties.ITCMSVehicleOutputsHVACSystemScreenProperties;
import com.sydac.mmrbem.tcms.common.data.Entry;
import com.sydac.mmrbem.tcms.common.data.VehicleDetailModel;
import com.sydac.mmrbem.tcms.common.data.VehicleHVACOpModeStatusDO;
import com.sydac.mmrbem.tcms.common.data.VehicleHvacControlModeStatusDO;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.HVACControlModeStatusList.HVACControlState;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.HVACControlModeStatusList.HVACControlStatus;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.HVACOperationModeStatusList.HVACOperatingState;
import com.sydac.mmrbem.tcms.common.state.TCMSConstants;

/**
 * This class handles HVAC 1 Operating Mode Status update from vehicle outputs
 * 
 */
public class HVACOpModeStatus1VehicleOutputsRequestHandler implements
    ITCMSVehicleOutputsRequestHandler<TCMSOutputsHVACSystemScreenImpl<Integer, IAppOutputsHVACSystemScreenHandler>>
{

  protected final List<Entry<VehicleHVACOpModeStatusDO>> hvacOpModeStatus1 = new ArrayList<>();
  protected final List<Entry<VehicleHVACOpModeStatusDO>> hvacControltatus1 = new ArrayList<>();

  @Override
  public void handleRequest(
      TCMSOutputsHVACSystemScreenImpl<Integer, IAppOutputsHVACSystemScreenHandler> request)
  {
    try
    {
      VehicleHVACOpModeStatusDO vehicleHVACOpModeStatusDO = ITCMSVehicleOutputsRequestHandler
          .getVehicleStatusDo(hvacOpModeStatus1, request.getCarIndex(), VehicleHVACOpModeStatusDO.class);
      setStatus(request.getPropertyKey(), request.getNewValue(), vehicleHVACOpModeStatusDO);
      ITCMSVehicleOutputsRequestHandler.updateVehicleStatusDOList(hvacOpModeStatus1,
          vehicleHVACOpModeStatusDO, request.getCarIndex());
      ITCMSVehicleOutputsRequestHandler.updateVehicleStatusDOList(hvacControltatus1,
          vehicleHVACOpModeStatusDO, request.getCarIndex());
      
      setHVACOpModeStatus(hvacOpModeStatus1, request.getVehicleDetailModelList(),
          builder -> request.getHandler().setHvacOperatingModeStatus1(builder.build().toByteArray()));
  
      setHvacControlModeStatus(hvacControltatus1, request.getVehicleDetailModelList(),
          builder -> request.getHandler().setHvacControlModeStatus1(builder.build().toByteArray()));
    }
    catch (InstantiationException e)
    {
      Tracer.getInstance().info(e);
    }
  }

  private void setStatus(PropertyKey<Integer> propertyKey, Integer newvalue,
      VehicleHVACOpModeStatusDO vehicleHVACOpModeStatusDO)
  {
    if (propertyKey.equals(ITCMSVehicleOutputsHVACSystemScreenProperties.HVAC_1_FAULT))
    {
      vehicleHVACOpModeStatusDO.setHvacFault(newvalue);
    }
    else if (propertyKey.equals(ITCMSVehicleOutputsHVACSystemScreenProperties.HVAC_1_ISOLATED))
    {
      vehicleHVACOpModeStatusDO.setHvacIsolated(newvalue);
    }
    else if (propertyKey.equals(ITCMSVehicleOutputsHVACSystemScreenProperties.HVAC_1_STATUS))
    {
      vehicleHVACOpModeStatusDO.setHvacStatus(newvalue);
    }else if (propertyKey.equals(ITCMSVehicleOutputsHVACSystemScreenProperties.HVAC_1_REDUCED_MODE))
    {
      vehicleHVACOpModeStatusDO.setHvacReduced(newvalue);
    }
  }

  private void setHVACOpModeStatus(List<Entry<VehicleHVACOpModeStatusDO>> hvacStatus,
      List<VehicleDetailModel> vehicleDetailModelList,
      Consumer<TCMSProto.HVACOperationModeStatusList.Builder> builderConsumer)
  {
    TCMSProto.HVACOperationModeStatusList.Builder builder = TCMSProto.HVACOperationModeStatusList
        .newBuilder();
    TCMSProto.HVACOperationModeStatusList.HVACOperatingStatus.Builder vehicleBuilder = TCMSProto.HVACOperationModeStatusList.HVACOperatingStatus
        .newBuilder();

    VehicleHVACOpModeStatusDO data;
    for (int index = 0; index < hvacStatus.size(); index++)
    {
      int carIndex = hvacStatus.get(index).getIndex();
      HVACOperatingState hvacOperatingState = HVACOperatingState.HVAC_OPERATING_UNIT_OFF;
      if (vehicleDetailModelList != null && vehicleDetailModelList.size() > carIndex)
      {
        data = hvacStatus.get(index).getData();
        hvacOperatingState = getHVACStatus(data);
      }
      vehicleBuilder.setCarIndex(hvacStatus.get(index).getIndex());
      vehicleBuilder.setHvacOperatingState(hvacOperatingState);
      builder.addHvacOperatingStatus(vehicleBuilder.build());
    }
    builderConsumer.accept(builder);
  }

  private HVACOperatingState getHVACStatus(VehicleHVACOpModeStatusDO data)
  {
    HVACOperatingState hvacOperatingState;
    if (data.getHvacIsolated() == TCMSConstants.ISOLATED)
    {
      hvacOperatingState = HVACOperatingState.HVAC_OPERATING_ISOLATED;
    }
    else if (data.getHvacFault() == TCMSConstants.FAULTY)
    {
      hvacOperatingState = HVACOperatingState.HVAC_OPERATING_FAULT;
    }
   
    else if (data.getHvacStatus() == HVACOperatingState.HVAC_OPERATING_PRE_HEATING_VALUE)
    {
      hvacOperatingState = HVACOperatingState.HVAC_OPERATING_PRE_HEATING;
    }
    else if (data.getHvacStatus() == HVACOperatingState.HVAC_OPERATING_PRE_COOLING_VALUE)
    {
      hvacOperatingState = HVACOperatingState.HVAC_OPERATING_PRE_COOLING;
    }
    else if (data.getHvacStatus() == HVACOperatingState.HVAC_OPERATING_VENTILATION_VALUE)
    {
      hvacOperatingState = HVACOperatingState.HVAC_OPERATING_VENTILATION;
    }
    else if (data.getHvacStatus() == HVACOperatingState.HVAC_OPERATING_COOLING_VALUE)
    {
      hvacOperatingState = HVACOperatingState.HVAC_OPERATING_COOLING;
    }
    else if (data.getHvacStatus() == HVACOperatingState.HVAC_OPERATING_HEATING_VALUE)
    {
      hvacOperatingState = HVACOperatingState.HVAC_OPERATING_HEATING;
    }
    else if (data.getHvacStatus() == HVACOperatingState.HVAC_OPERATING_EMERGENCY_VENT_VALUE)
    {
      hvacOperatingState = HVACOperatingState.HVAC_OPERATING_EMERGENCY_VENT;
    }
    else
    {
      hvacOperatingState = HVACOperatingState.HVAC_OPERATING_UNIT_OFF;
    }
    return hvacOperatingState;
  }
  
  
  private HVACControlState getHVACControlModeStatus(VehicleHVACOpModeStatusDO data)
  {
    HVACControlState hvacControlState;
    if (data.getHvacReduced() == TCMSConstants.REDUCED)
    {
      hvacControlState = HVACControlState.HVAC_CONTROL_REDUCED;
    }
    else 
    {
      hvacControlState = HVACControlState.HVAC_CONTROL_AUTO;
    }
   
   
    return hvacControlState;
  }
  
  
  private void setHvacControlModeStatus(List<Entry<VehicleHVACOpModeStatusDO>> hvacControlStatus,
      List<VehicleDetailModel> vehicleDetailModelList,
      Consumer<TCMSProto.HVACControlModeStatusList.Builder> builderConsumer)
  {
    TCMSProto.HVACControlModeStatusList.Builder builder = TCMSProto.HVACControlModeStatusList
        .newBuilder();
    TCMSProto.HVACControlModeStatusList.HVACControlStatus.Builder vehicleBuilder = TCMSProto.HVACControlModeStatusList.HVACControlStatus
        .newBuilder();

    VehicleHVACOpModeStatusDO data;
    for (int index = 0; index < hvacControlStatus.size(); index++)
    {
      int carIndex = hvacControlStatus.get(index).getIndex();
      HVACControlState hvacControlState = HVACControlState.HVAC_CONTROL_AUTO;
      if (vehicleDetailModelList != null && vehicleDetailModelList.size() > carIndex)
      {
        data = hvacControlStatus.get(index).getData();
        hvacControlState = getHVACControlModeStatus(data);
      }
      vehicleBuilder.setCarIndex(hvacControlStatus.get(index).getIndex());
      vehicleBuilder.setHvacControlState(hvacControlState);
      builder.addHvacControlStatus(vehicleBuilder.build());
    }
    builderConsumer.accept(builder);
  }
}
