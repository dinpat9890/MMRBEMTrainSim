/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.papis.fe.gui.binder;

import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.papis.common.io.properties.IAppOutputsCommonProperties;
import com.sydac.mmrbem.papis.fe.base.AbstractCommsListener;
import com.sydac.mmrbem.papis.fe.gui.model.SystemSettingsScreenModel;

public class SystemSettingsScreenBinder extends AbstractCommsListener
{

  private SystemSettingsScreenModel systemSettingsScreenModel;

  public SystemSettingsScreenBinder(SystemSettingsScreenModel systemSettingsScreenModel)
  {
    this.systemSettingsScreenModel = systemSettingsScreenModel;
    propertyKeyDefinitions.add(IAppOutputsCommonProperties.class);
  }

  @Override
  protected <T> void appOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue)
  {
    if (IAppOutputsCommonProperties.START_STATION_NAME.equals(key))
    {
      systemSettingsScreenModel.setStartStationProperty((byte[])newValue);
    }
    else if (IAppOutputsCommonProperties.NEXT_STATION_NAME.equals(key))
    {
      systemSettingsScreenModel.setNextStationProperty((byte[])newValue);
    }
    else if (IAppOutputsCommonProperties.TERMINAL_STATION_NAME.equals(key))
    {
      systemSettingsScreenModel.setTerminalStationProperty((byte[])newValue);
    }
    else if (IAppOutputsCommonProperties.CURRENT_LINE_NAME.equals(key))
    {
      systemSettingsScreenModel.setRouteProperty((byte[])newValue);
    }
    else if (IAppOutputsCommonProperties.ACTIVE_MODE.equals(key))
    {
      systemSettingsScreenModel.setModeSelectionProperty((Integer)newValue);
    }
    else if (IAppOutputsCommonProperties.TRAIN_ID.equals(key))
    {
      systemSettingsScreenModel.setTrainIdproperty((byte[])newValue);
    }
  }
}
