/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.papis.fe.gui.binder;

import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.papis.common.io.properties.IAppOutputsSkipStationSettingScreenProperties;
import com.sydac.mmrbem.papis.fe.base.AbstractCommsListener;
import com.sydac.mmrbem.papis.fe.gui.model.SkipStationSettingScreenModel;

public class SkipStationSettingScreenBinder extends AbstractCommsListener
{

  private SkipStationSettingScreenModel skipStationSettingScreenModel;

  public SkipStationSettingScreenBinder(SkipStationSettingScreenModel skipStationSettingScreenModel)
  {
    this.skipStationSettingScreenModel = skipStationSettingScreenModel;
    propertyKeyDefinitions.add(IAppOutputsSkipStationSettingScreenProperties.class);
  }

  @Override
  protected <T> void appOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue)
  {
    if (IAppOutputsSkipStationSettingScreenProperties.SKIP_SCREEN_STATION_LIST.equals(key))
    {
      skipStationSettingScreenModel.setStationList((byte[])newValue);
    }
    else if (IAppOutputsSkipStationSettingScreenProperties.SKIP_STATION_LIST.equals(key))
    {
      skipStationSettingScreenModel.setSkipStationList((byte[])newValue);
    }
  }
}
