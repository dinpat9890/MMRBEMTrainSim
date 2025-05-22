/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.papis.fe.gui.binder;

import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.papis.common.io.properties.IAppOutputsCommonProperties;
import com.sydac.mmrbem.papis.fe.base.AbstractCommsListener;
import com.sydac.mmrbem.papis.fe.gui.model.MainInterfaceScreenModel;

public class MainInterfaceScreenBinder extends AbstractCommsListener
{

  private MainInterfaceScreenModel mainInterfaceScreenModel;

  public MainInterfaceScreenBinder(MainInterfaceScreenModel mainInterfaceScreenModel)
  {
    this.mainInterfaceScreenModel = mainInterfaceScreenModel;
    propertyKeyDefinitions.add(IAppOutputsCommonProperties.class);
  }

  @Override
  protected <T> void appOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue)
  {
    if (IAppOutputsCommonProperties.ACTIVE_MODE.equals(key))
    {
      mainInterfaceScreenModel.setActiveMode((Integer)newValue);
    }
    else if (IAppOutputsCommonProperties.CURRENT_LINE_NAME.equals(key))
    {
      mainInterfaceScreenModel.setCurrentLine((byte[])newValue);
    }
    else if (IAppOutputsCommonProperties.CURRENT_STATION_NAME.equals(key))
    {
      mainInterfaceScreenModel.setCurrentStation((byte[])newValue);
    }
    else if (IAppOutputsCommonProperties.NEXT_STATION_NAME.equals(key))
    {
      mainInterfaceScreenModel.setNextStation((byte[])newValue);
    }
    else if (IAppOutputsCommonProperties.TERMINAL_STATION_NAME.equals(key))
    {
      mainInterfaceScreenModel.setTerminalStation((byte[])newValue);
    }
    else if (IAppOutputsCommonProperties.DOOR_OPENING_SIDE.equals(key))
    {
      mainInterfaceScreenModel.setDoorOpenSide((byte[])newValue);
    }
    else if (IAppOutputsCommonProperties.CONNECTION_TYPE_NAME.equals(key))
    {
      mainInterfaceScreenModel.setCurrentConnection((byte[])newValue);
    }
    else if (IAppOutputsCommonProperties.DOOR_STATUS.equals(key))
    {
      mainInterfaceScreenModel.setDoorStatus((Integer)newValue);
    }
    else if (IAppOutputsCommonProperties.SELECT_BUTTON.equals(key))
    {
      mainInterfaceScreenModel.setSelectedButton((Integer)newValue);
    }
  }

}
