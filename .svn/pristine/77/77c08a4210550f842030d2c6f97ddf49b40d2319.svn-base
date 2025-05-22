/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.fe.gui.binder;

import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsSpeedLimitInterlockScreenProperties;
import com.sydac.mmrbem.tcms.fe.base.AbstractCommsListener;
import com.sydac.mmrbem.tcms.fe.gui.model.SpeedLimitInterlockScreenModel;

public class SpeedLimitInterlockScreenBinder extends AbstractCommsListener
{

  private SpeedLimitInterlockScreenModel speedLimitInterlockScreenModel;

  public SpeedLimitInterlockScreenBinder(SpeedLimitInterlockScreenModel speedLimitInterlockScreenModel)
  {
    super();
    this.speedLimitInterlockScreenModel = speedLimitInterlockScreenModel;
    propertyKeyDefinitions.add(IAppOutputsSpeedLimitInterlockScreenProperties.class);
  }

  @Override
  protected <T> void appOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue)
  {
    if (IAppOutputsSpeedLimitInterlockScreenProperties.SPEED_LIMIT_STATUS.equals(key))
    {
      speedLimitInterlockScreenModel.setSpeedLimitStatus((byte[])newValue);
    }
  }

}
