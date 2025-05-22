/*
 * ================================================================== (C)
 * Copyright 2020 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.dmi.fe.gui.binder;

import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.dmi.common.io.properties.IAppOutputsMainScreenAreaCRightProperties;
import com.sydac.mmrbem.dmi.common.io.properties.IAppOutputsMainScreenProperties;
import com.sydac.mmrbem.dmi.fe.base.AbstractCommsListener;
import com.sydac.mmrbem.dmi.fe.gui.model.MainScreenAreaCRightModel;

/**
 * The Class MainScreenAreaCRightBinder used to read main screen Area C Right
 * values from comms and assign it to the model
 * {@link MainScreenAreaCRightModel}
 * 
 * @author mulukg
 */
public class MainScreenAreaCRightBinder extends AbstractCommsListener
{

  MainScreenAreaCRightModel mainScreenAreaCRightModel;

  public MainScreenAreaCRightBinder(MainScreenAreaCRightModel mainScreenAreaCRightModel)
  {
    propertyKeyDefinitions.add(IAppOutputsMainScreenProperties.class);
    propertyKeyDefinitions.add(IAppOutputsMainScreenAreaCRightProperties.class);
    this.mainScreenAreaCRightModel = mainScreenAreaCRightModel;
  }

  @Override
  protected <T> void appInputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue)
  {
    if (key == IAppOutputsMainScreenProperties.CURRENT_DRIVING_MODE)
    {
      mainScreenAreaCRightModel.setCurrentDrivingMode((Integer)newValue);
    }
    else if (key == IAppOutputsMainScreenAreaCRightProperties.LOCALISATION_STATUS)
    {
      mainScreenAreaCRightModel.setLocalisationStatus((Integer)newValue);
    }
    else if (key == IAppOutputsMainScreenAreaCRightProperties.AVAILABLE_MODES)
    {
      mainScreenAreaCRightModel.setAvailableModes((byte[])newValue);
    }
    else if (key == IAppOutputsMainScreenProperties.CURRENT_DATE_AND_TIME)
    {
      mainScreenAreaCRightModel.setFlashTime((Number)newValue);
    }
    else if (key == IAppOutputsMainScreenProperties.ATC_BYPASS_STATE)
    {
      mainScreenAreaCRightModel.setAtcBypassState((Boolean)newValue);
    }
  }
}
