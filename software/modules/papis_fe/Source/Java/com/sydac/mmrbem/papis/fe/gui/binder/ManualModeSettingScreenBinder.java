/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.papis.fe.gui.binder;

import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.papis.common.io.properties.IAppOutputsManualModeSettingScreenProperties;
import com.sydac.mmrbem.papis.fe.base.AbstractCommsListener;
import com.sydac.mmrbem.papis.fe.gui.model.ManualModeSettingScreenModel;

public class ManualModeSettingScreenBinder extends AbstractCommsListener
{

  private ManualModeSettingScreenModel manualModeSettingScreenModel;

  public ManualModeSettingScreenBinder(ManualModeSettingScreenModel manualModeSettingScreenModel)
  {
    this.manualModeSettingScreenModel = manualModeSettingScreenModel;
    propertyKeyDefinitions.add(IAppOutputsManualModeSettingScreenProperties.class);
  }

  @Override
  protected <T> void appOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue)
  {
    if (IAppOutputsManualModeSettingScreenProperties.MANUAL_MODE_SCREEN_STATION_LIST.equals(key))
    {
      manualModeSettingScreenModel.setStationList((byte[])newValue);
    }
    else if (IAppOutputsManualModeSettingScreenProperties.LAST_STATION_ID.equals(key))
    {
      manualModeSettingScreenModel.setLastStationId((Integer)newValue);
    }
    else if (IAppOutputsManualModeSettingScreenProperties.MANUAL_MODE_SCREEN_ALL_STATION_LIST.equals(key))
    {
      manualModeSettingScreenModel.setAllStationList((byte[])newValue);
    }
  }
}
