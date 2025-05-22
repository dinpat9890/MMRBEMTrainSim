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
import com.sydac.mmrbem.tcms.backend.app.io.handlers.IAppOutputsFireDetectionSystemScreenHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.io.properties.ITCMSVehicleOutputsFireDetectionSystemProperties;
import com.sydac.mmrbem.tcms.common.data.Entry;
import com.sydac.mmrbem.tcms.common.data.VehicleDetailModel;
import com.sydac.mmrbem.tcms.common.data.VehicleFireSensorAlarmStatusDO;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.FireSensorAlarmStatusList.FireSensorAlarmState;

/**
 * This class handles Fire Sensor Alarm Status update from vehicle outputs
 * 
 */
public class FireSensorAlarmStatusVehicleOutputsRequestHandler implements
    ITCMSVehicleOutputsRequestHandler<TCMSOutputsFireDetectionSystemScreenImpl<Integer, IAppOutputsFireDetectionSystemScreenHandler>>
{

  protected final List<Entry<VehicleFireSensorAlarmStatusDO>> fireSensorAlarmStatus = new ArrayList<>();

  @Override
  public void handleRequest(
      TCMSOutputsFireDetectionSystemScreenImpl<Integer, IAppOutputsFireDetectionSystemScreenHandler> request)
  {
    try
    {
      VehicleFireSensorAlarmStatusDO vehicleFireSensorAlarmStatusDO = ITCMSVehicleOutputsRequestHandler
          .getVehicleStatusDo(fireSensorAlarmStatus, request.getCarIndex(),
              VehicleFireSensorAlarmStatusDO.class);
      setStatus(request.getPropertyKey(), request.getNewValue(), vehicleFireSensorAlarmStatusDO);
      ITCMSVehicleOutputsRequestHandler.updateVehicleStatusDOList(fireSensorAlarmStatus,
          vehicleFireSensorAlarmStatusDO, request.getCarIndex());
      setFireSensorAlarmStatus(fireSensorAlarmStatus, request.getVehicleDetailModelList(),
          builder -> request.getHandler().setFireSensorAlarmStatus(builder.build().toByteArray()));
    }
    catch (InstantiationException e)
    {
      Tracer.getInstance().info(e);
    }
  }

  private void setStatus(PropertyKey<Integer> propertyKey, Integer newvalue,
      VehicleFireSensorAlarmStatusDO vehicleFireSensorAlarmStatusDO)
  {
    if (propertyKey.equals(ITCMSVehicleOutputsFireDetectionSystemProperties.SENSOR_FIRE_ALARM_STATUS))
    {
      vehicleFireSensorAlarmStatusDO.setFireSensorAlarmStatus(newvalue);
    }
  }

  private void setFireSensorAlarmStatus(List<Entry<VehicleFireSensorAlarmStatusDO>> fireSensorAlrmStatus,
      List<VehicleDetailModel> vehicleDetailModelList,
      Consumer<TCMSProto.FireSensorAlarmStatusList.Builder> builderConsumer)
  {
    TCMSProto.FireSensorAlarmStatusList.Builder builder = TCMSProto.FireSensorAlarmStatusList.newBuilder();
    TCMSProto.FireSensorAlarmStatusList.FireSensorAlarmStatus.Builder vehicleBuilder = TCMSProto.FireSensorAlarmStatusList.FireSensorAlarmStatus
        .newBuilder();

    VehicleFireSensorAlarmStatusDO data;
    for (int index = 0; index < fireSensorAlrmStatus.size(); index++)
    {
      int carIndex = fireSensorAlrmStatus.get(index).getIndex();
      FireSensorAlarmState fireSensorAlarmState = FireSensorAlarmState.FIRE_SENSOR_ALARM_UNKNOWN;
      if (vehicleDetailModelList != null && vehicleDetailModelList.size() > carIndex)
      {
        data = fireSensorAlrmStatus.get(index).getData();
        fireSensorAlarmState = getFireSensorFaultStatus(data);
      }
      vehicleBuilder.setCarIndex(fireSensorAlrmStatus.get(index).getIndex());
      vehicleBuilder.setFireSensorAlarmState(fireSensorAlarmState);
      builder.addFireSensorAlarmStatus(vehicleBuilder.build());
    }
    builderConsumer.accept(builder);
  }

  private FireSensorAlarmState getFireSensorFaultStatus(VehicleFireSensorAlarmStatusDO data)
  {
    FireSensorAlarmState fireSensorAlarmState;
    if (data.getFireSensorAlarmStatus() == FireSensorAlarmState.FIRE_SENSOR_ALARM_NORMAL_VALUE)
    {
      fireSensorAlarmState = FireSensorAlarmState.FIRE_SENSOR_ALARM_NORMAL;
    }
    else if (data.getFireSensorAlarmStatus() == FireSensorAlarmState.FIRE_SENSOR_ALARM_HEAT_SMOKE_VALUE)
    {
      fireSensorAlarmState = FireSensorAlarmState.FIRE_SENSOR_ALARM_HEAT_SMOKE;
    }
    else if (data.getFireSensorAlarmStatus() == FireSensorAlarmState.FIRE_SENSOR_ALARM_PRE_ALARM_VALUE)
    {
      fireSensorAlarmState = FireSensorAlarmState.FIRE_SENSOR_ALARM_PRE_ALARM;
    }
    else
    {
      fireSensorAlarmState = FireSensorAlarmState.FIRE_SENSOR_ALARM_UNKNOWN;
    }
    return fireSensorAlarmState;
  }
}
