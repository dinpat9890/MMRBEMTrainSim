/*
 * ==================================================================
 * 
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.tcms.fe.gui.binder;

import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsTemperaturesScreenProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsTrainConfigurationProperties;
import com.sydac.mmrbem.tcms.fe.base.AbstractCommsListener;
import com.sydac.mmrbem.tcms.fe.gui.model.PropulsionSystemTemperaturesScreenModel;

public class PropulsionSystemTemperaturesScreenBinder extends AbstractCommsListener
{

  private PropulsionSystemTemperaturesScreenModel propulsionSystemTemperaturesScreenModel;

  public PropulsionSystemTemperaturesScreenBinder(
      PropulsionSystemTemperaturesScreenModel propulsionSystemTemperaturesScreenModel)
  {
    super();
    this.propulsionSystemTemperaturesScreenModel = propulsionSystemTemperaturesScreenModel;
    propertyKeyDefinitions.add(IAppOutputsTrainConfigurationProperties.class);
    propertyKeyDefinitions.add(IAppOutputsTemperaturesScreenProperties.class);
  }

  @Override
  protected <T> void appOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue)
  {
    if (IAppOutputsTrainConfigurationProperties.NUMBER_OF_CARS.equals(key))
    {
      propulsionSystemTemperaturesScreenModel.setTotalColumn((Integer)newValue);
    }
    else if (IAppOutputsTemperaturesScreenProperties.MOTOR_1_TEMPERATURE_LIST.equals(key))
    {
      propulsionSystemTemperaturesScreenModel.setMotor1TemperatureList((byte[])newValue);
    }
    else if (IAppOutputsTemperaturesScreenProperties.MOTOR_2_TEMPERATURE_LIST.equals(key))
    {
      propulsionSystemTemperaturesScreenModel.setMotor2TemperatureList((byte[])newValue);
    }
    else if (IAppOutputsTemperaturesScreenProperties.MOTOR_3_TEMPERATURE_LIST.equals(key))
    {
      propulsionSystemTemperaturesScreenModel.setMotor3TemperatureList((byte[])newValue);
    }
    else if (IAppOutputsTemperaturesScreenProperties.MOTOR_4_TEMPERATURE_LIST.equals(key))
    {
      propulsionSystemTemperaturesScreenModel.setMotor4TemperatureList((byte[])newValue);
    }
    else if (IAppOutputsTemperaturesScreenProperties.MAIN_TRANSFORMER_TEMPERATURE_LIST.equals(key))
    {
      propulsionSystemTemperaturesScreenModel.setMainTransformerTemperatureList((byte[])newValue);
    }
  }
}
