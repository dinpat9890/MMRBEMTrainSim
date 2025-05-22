/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/

package com.sydac.mmrbem.tcms.fe.gui.binder;

import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsFireDetectionSystemScreenProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsTrainConfigurationProperties;
import com.sydac.mmrbem.tcms.fe.base.AbstractCommsListener;
import com.sydac.mmrbem.tcms.fe.gui.model.FireDetectionSystemScreenModel;

public class FireDetectionSystemScreenBinder extends AbstractCommsListener
{

  private FireDetectionSystemScreenModel fireDetectionSystemScreenModel;

  public FireDetectionSystemScreenBinder(FireDetectionSystemScreenModel fireDetectionSystemScreenModel)
  {
    super();
    this.fireDetectionSystemScreenModel = fireDetectionSystemScreenModel;
    propertyKeyDefinitions.add(IAppOutputsFireDetectionSystemScreenProperties.class);
    propertyKeyDefinitions.add(IAppOutputsTrainConfigurationProperties.class);
  }

  @Override
  protected <T> void appOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue)
  {

    if (IAppOutputsFireDetectionSystemScreenProperties.FDU_SYSTEM_FAULT_STATUS.equals(key))
    {
      fireDetectionSystemScreenModel.setFDUFaultStatusList((byte[])newValue);
    }
    else if (IAppOutputsFireDetectionSystemScreenProperties.FIRE_SENSOR_FAULT_STATUS.equals(key))
    {
      fireDetectionSystemScreenModel.setFireSensorFaultStatusList((byte[])newValue);
    }
    else if (IAppOutputsFireDetectionSystemScreenProperties.FIRE_SENSOR_ALARM_STATUS.equals(key))
    {
      fireDetectionSystemScreenModel.setFireSensorAlarmStatusList((byte[])newValue);
    }
    else if (IAppOutputsFireDetectionSystemScreenProperties.FIRE_SENSOR_DISABLED_STATUS.equals(key))
    {
      fireDetectionSystemScreenModel.setFireSensorDisabledStatusList((byte[])newValue);
    }
    else if (IAppOutputsFireDetectionSystemScreenProperties.FIRE_SYSTEM_EXTERNAL_SMOKE_STATUS.equals(key))
    {
      fireDetectionSystemScreenModel.setExternalSmokeStatusList((byte[])newValue);
    }
    else if (IAppOutputsFireDetectionSystemScreenProperties.FIRE_SYSTEM_UNDER_FRAME_FIRE_STATUS.equals(key))
    {
      fireDetectionSystemScreenModel.setUnderFrameFireStatusList((byte[])newValue);
    }
    else if (IAppOutputsFireDetectionSystemScreenProperties.FIRE_SYSTEM_UFAR_STATUS.equals(key))
    {
      fireDetectionSystemScreenModel.setUFARStatusList((byte[])newValue);
    }
    else if (IAppOutputsFireDetectionSystemScreenProperties.FIRE_SYSTEM_INTERNAL_FIRE_STATUS.equals(key))
    {
      fireDetectionSystemScreenModel.setInternalFireStatusList((byte[])newValue);
    }
    else if (IAppOutputsFireDetectionSystemScreenProperties.FIRE_SYSTEM_SFAR_STATUS.equals(key))
    {
      fireDetectionSystemScreenModel.setSFARStatusList((byte[])newValue);
    }
    else if (key.equals(IAppOutputsTrainConfigurationProperties.NUMBER_OF_CARS))
    {
      fireDetectionSystemScreenModel.setTotalColumn((Integer)newValue);
    }
  }

}
