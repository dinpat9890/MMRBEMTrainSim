/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.papis.fe.gui.binder;

import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.papis.common.io.properties.IAppOutputsCommonProperties;
import com.sydac.mmrbem.papis.common.io.properties.IAppOutputsStationSettingScreensProperties;
import com.sydac.mmrbem.papis.fe.base.AbstractCommsListener;
import com.sydac.mmrbem.papis.fe.gui.model.NextStationSelectionScreenModel;

public class NextStationSelectionScreenBinder extends AbstractCommsListener
{

  private NextStationSelectionScreenModel nextStationSelectionScreenModel;

  public NextStationSelectionScreenBinder(NextStationSelectionScreenModel nextStationSelectionScreenModel)
  {
    super();
    this.nextStationSelectionScreenModel = nextStationSelectionScreenModel;
    propertyKeyDefinitions.add(IAppOutputsStationSettingScreensProperties.class);
    propertyKeyDefinitions.add(IAppOutputsCommonProperties.class);
  }

  @Override
  protected <T> void appOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue)
  {
    if (IAppOutputsStationSettingScreensProperties.STATION_LIST.equals(key))
    {
      nextStationSelectionScreenModel.setStationList((byte[])newValue);
    }
    else if (IAppOutputsCommonProperties.START_STATION_NAME.equals(key))
    {
      nextStationSelectionScreenModel.setNextStationNameProperty((byte[])newValue);
    }
    else if (IAppOutputsCommonProperties.NEXT_STATION_SELECTED_BUTTON.equals(key))
    {
      nextStationSelectionScreenModel.setNextStationSelected((Integer)newValue);
    }
  }
}
