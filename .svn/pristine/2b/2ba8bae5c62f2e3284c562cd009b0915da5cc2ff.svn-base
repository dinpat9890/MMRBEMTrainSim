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
import com.sydac.mmrbem.papis.fe.gui.model.TerminalStationSelectionScreenModel;

public class TerminalStationSelectionScreenBinder extends AbstractCommsListener
{

  private TerminalStationSelectionScreenModel terminalStationSelectionScreenModel;

  public TerminalStationSelectionScreenBinder(
      TerminalStationSelectionScreenModel terminalStationSelectionScreenModel)
  {
    super();
    this.terminalStationSelectionScreenModel = terminalStationSelectionScreenModel;
    propertyKeyDefinitions.add(IAppOutputsStationSettingScreensProperties.class);
    propertyKeyDefinitions.add(IAppOutputsCommonProperties.class);
  }

  @Override
  protected <T> void appOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue)
  {
    if (IAppOutputsStationSettingScreensProperties.STATION_LIST.equals(key))
    {
      terminalStationSelectionScreenModel.setStationList((byte[])newValue);
    }
    else if (IAppOutputsCommonProperties.TERMINAL_STATION_NAME.equals(key))
    {
      terminalStationSelectionScreenModel.setTerminalStationNameProperty((byte[])newValue);
    }
    else if (IAppOutputsCommonProperties.TERMINAL_STATION_SELECTED_BUTTON.equals(key))
    {
      terminalStationSelectionScreenModel.setTerminalStationSelected((Integer)newValue);
    }
  }
}
