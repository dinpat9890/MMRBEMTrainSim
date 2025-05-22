/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.fe.gui.binder;

import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsBatterySystemScreenProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsTrainConfigurationProperties;
import com.sydac.mmrbem.tcms.fe.base.AbstractCommsListener;
import com.sydac.mmrbem.tcms.fe.gui.model.BatterySystemScreenModel;

public class BatterySystemScreenBinder extends AbstractCommsListener
{

  private BatterySystemScreenModel batterySystemScreenModel;

  public BatterySystemScreenBinder(BatterySystemScreenModel batterySystemScreenModel)
  {
    this.batterySystemScreenModel = batterySystemScreenModel;
    propertyKeyDefinitions.add(IAppOutputsBatterySystemScreenProperties.class);
    propertyKeyDefinitions.add(IAppOutputsTrainConfigurationProperties.class);
  }

  @Override
  protected <T> void appOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue)
  {
    if (IAppOutputsTrainConfigurationProperties.NUMBER_OF_CARS.equals(key))
    {
      batterySystemScreenModel.setTotalColumn((Integer)newValue);
    }
    else if (IAppOutputsBatterySystemScreenProperties.BCG_STATUS.equals(key))
    {
      batterySystemScreenModel.setBcgStatusList((byte[])newValue);
    }
    else if (IAppOutputsBatterySystemScreenProperties.BCG_OUTPUT_VOLTAGE_STATUS.equals(key))
    {
      batterySystemScreenModel.setBcgOutputVoltageStatusList((byte[])newValue);
    }
    else if (IAppOutputsBatterySystemScreenProperties.BATTERY_VOLTAGE_STATUS.equals(key))
    {
      batterySystemScreenModel.setBatteryVoltageStatusList((byte[])newValue);
    }
    else if (IAppOutputsBatterySystemScreenProperties.OUTPUT_CURRENT_STATUS.equals(key))
    {
      batterySystemScreenModel.setOutputCurrentStatusList((byte[])newValue);
    }
    else if (IAppOutputsBatterySystemScreenProperties.TOTAL_OUTPUT_CURRENT_STATUS.equals(key))
    {
      batterySystemScreenModel.setTotalOutputCurrentStatusList((byte[])newValue);
    }
    else if (IAppOutputsBatterySystemScreenProperties.BATTERY_CURRENT_STATUS.equals(key))
    {
      batterySystemScreenModel.setBatteryCurrentStatusList((byte[])newValue);
    }
    else if (IAppOutputsBatterySystemScreenProperties.BATTERY_TEMPERATURE_STATUS.equals(key))
    {
      batterySystemScreenModel.setBatteryTemperatureStatusList((byte[])newValue);
    }
  }
}
