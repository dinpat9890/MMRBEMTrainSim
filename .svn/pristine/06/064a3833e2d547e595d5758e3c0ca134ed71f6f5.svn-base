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
import com.sydac.mmrbem.dmi.common.io.properties.IAppOutputsCrewIdPopupProperties;
import com.sydac.mmrbem.dmi.common.io.properties.IAppOutputsMainScreenAreaBLeftProperties;
import com.sydac.mmrbem.dmi.common.io.properties.IAppOutputsMainScreenProperties;
import com.sydac.mmrbem.dmi.common.io.properties.IAppOutputsMainScreenSettingsProperties;
import com.sydac.mmrbem.dmi.common.io.properties.IAppOutputsPopupMenuProperties;
import com.sydac.mmrbem.dmi.fe.base.AbstractCommsListener;
import com.sydac.mmrbem.dmi.fe.gui.model.MainScreenModel;

/**
 * The Class MainScreenBinder used to read main screen values from comms and
 * assign it to the model {@link MainScreenModel}
 * 
 * @author mulukg
 */
public class MainScreenBinder extends AbstractCommsListener
{
  MainScreenModel mainScreenModel;

  public MainScreenBinder(MainScreenModel mainScreenModel)
  {
    propertyKeyDefinitions.add(IAppOutputsMainScreenProperties.class);
    propertyKeyDefinitions.add(IAppOutputsCrewIdPopupProperties.class);
    propertyKeyDefinitions.add(IAppOutputsPopupMenuProperties.class);
    propertyKeyDefinitions.add(IAppOutputsMainScreenAreaBLeftProperties.class);
    propertyKeyDefinitions.add(IAppOutputsMainScreenSettingsProperties.class);

    this.mainScreenModel = mainScreenModel;
  }

  @Override
  protected <T> void appInputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue)
  {
    if (key == IAppOutputsMainScreenProperties.CURRENT_DRIVING_MODE)
    {
      mainScreenModel.setCurrentDrivingMode((Integer)newValue);
    }
    else if (key == IAppOutputsMainScreenAreaBLeftProperties.CURRENT_TRAIN_SPEED)
    {
      mainScreenModel.setCurrentTrainSpeed(((Double)newValue).intValue());
    }
    else if (key == IAppOutputsMainScreenProperties.SAFETY_BRAKE_STATUS)
    {
      mainScreenModel.setSafetyBrakeStatus((Integer)newValue);
    }
    else if (key == IAppOutputsMainScreenProperties.LIFE_INDICATOR_STATUS)
    {
      mainScreenModel.setLifeIndicatorStatus((Integer)newValue);
    }
    else if (key == IAppOutputsMainScreenProperties.ADVISORY_SPEED)
    {
      mainScreenModel.setAdvisorySpeed(((Double)newValue).intValue());
    }
    else if (key == IAppOutputsMainScreenProperties.SERVICE_NUMBER_VALUE)
    {
      mainScreenModel.setServiceNumberValue(newValue.toString());
    }
    else if (key == IAppOutputsPopupMenuProperties.MENU_PANEL_STATUS)
    {
      mainScreenModel.setMenuPanelStatus((Boolean)newValue);
    }
    else if (key == IAppOutputsMainScreenProperties.CURRENT_DATE_AND_TIME)
    {
      mainScreenModel.setCurrentDateAndTime((Number)newValue);
    }
    else if (key == IAppOutputsCrewIdPopupProperties.CREW_ID_PANEL_STATUS)
    {
      mainScreenModel.setCrewIdPanelStatus((Boolean)newValue);
    }
    else if (key == IAppOutputsCrewIdPopupProperties.CREW_NUMBER)
    {
      mainScreenModel.setCrewNumber(new String((byte[])newValue));
    }
    else if (key == IAppOutputsMainScreenProperties.FINAL_DESTINATION_NAME)
    {
      mainScreenModel.setDestinationCode((byte[])newValue);
    }
    else if (key == IAppOutputsMainScreenProperties.WARNING_SPEED)
    {
      mainScreenModel.setWarningSpeed(((Double)newValue).intValue());
    }
    else if (key == IAppOutputsMainScreenProperties.DESTINATION_CODE)
    {
      mainScreenModel.setDestinationId((Integer)newValue);
    }
    else if (key == IAppOutputsMainScreenSettingsProperties.SELECTED_BRIGHTNESS_VALUE)
    {
      mainScreenModel.setSelectedBrightnessValue((Integer)newValue);
    }
    else if (key == IAppOutputsMainScreenSettingsProperties.SELECTED_AUDIO_VALUE)
    {
      mainScreenModel.setSelectedAudioValue((Integer)newValue);
    }
    else if (key == IAppOutputsMainScreenSettingsProperties.SELECTED_SETTINGS_PANEL)
    {
      mainScreenModel.setSelectedSettingsPanelId((Integer)newValue);
    }
  }

}
