/*
 * 
 * ================================================================== (C)
 * Copyright 2020 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * ==================================================================
 */
package com.sydac.mmrbem.dmi.backend.logic.handler;

import org.springframework.stereotype.Service;

import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.dmi.backend.comms.CommsBinding;
import com.sydac.mmrbem.dmi.backend.logic.AbstractFunctionalLogic;
import com.sydac.mmrbem.dmi.backend.logic.annotation.FunctionalLogicHandler;
import com.sydac.mmrbem.dmi.common.io.properties.IAppInputsProperties;
import com.sydac.mmrbem.dmi.common.io.properties.IAppInputsSettingsPopupProperties;
import com.sydac.mmrbem.dmi.common.io.properties.IAppOutputsMainScreenSettingsProperties;
import com.sydac.mmrbem.dmi.common.state.DMIAudioModeEnum;
import com.sydac.mmrbem.dmi.common.state.DMIBrightnessModeEnum;
import com.sydac.mmrbem.dmi.common.state.DMIConstants;

/**
 * This handler class is responsible for managing brightness and audio settings
 * in the main screen
 *
 * @author ext-vp
 */
@Service
@FunctionalLogicHandler(arguments = { CommsBinding.class })
public class DMISettingsHandler extends AbstractFunctionalLogic
{
  public DMISettingsHandler(CommsBinding commsBinding)
  {
    super(commsBinding, IAppInputsProperties.class);
  }

  @Override
  public void attachListeners()
  {
    super.attachListeners();
    setApplicationOutputsProperty(IAppOutputsMainScreenSettingsProperties.SELECTED_BRIGHTNESS_VALUE,
        DMIBrightnessModeEnum.BRIGHTNESS_AUTO.getId());
    setApplicationOutputsProperty(IAppOutputsMainScreenSettingsProperties.SELECTED_AUDIO_VALUE,
        DMIAudioModeEnum.AUDIO_100.getId());
  }

  @Override
  public <T> void appInputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue, int vehicleIndex)
  {
    if (getActiveVehicleIndex() == vehicleIndex)
    {
      if (IAppInputsSettingsPopupProperties.AUDIO_BUTTON_PRESS_REQUEST.equals(key) && (Integer)newValue > 0)
      {
        setApplicationOutputsProperty(IAppOutputsMainScreenSettingsProperties.SELECTED_SETTINGS_PANEL,
            DMIConstants.AUDIO_PANEL_ACTIVE);
      }
      else if (IAppInputsSettingsPopupProperties.BRIGHTNESS_BUTTON_PRESS_REQUEST.equals(key)
          && (Integer)newValue > 0)
      {
        setApplicationOutputsProperty(IAppOutputsMainScreenSettingsProperties.SELECTED_SETTINGS_PANEL,
            DMIConstants.BRIGHTNESS_PANEL_ACTIVE);
      }
      else if (IAppInputsSettingsPopupProperties.AUDIO_CLOSE_REQUEST.equals(key) && (Integer)newValue > 0)
      {
        setApplicationOutputsProperty(IAppOutputsMainScreenSettingsProperties.SELECTED_SETTINGS_PANEL,
            DMIConstants.NO_SETTING_PANEL_ACTIVE);
      }
      else if (IAppInputsSettingsPopupProperties.BRIGHTNESS_CLOSE_REQUEST.equals(key)
          && (Integer)newValue > 0)
      {
        setApplicationOutputsProperty(IAppOutputsMainScreenSettingsProperties.SELECTED_SETTINGS_PANEL,
            DMIConstants.NO_SETTING_PANEL_ACTIVE);
      }
      else if (IAppInputsSettingsPopupProperties.BRIGHTNESS_CHANGE_REQUEST.equals(key)
          && (Integer)newValue > -1)
      {
        setApplicationOutputsProperty(IAppOutputsMainScreenSettingsProperties.SELECTED_BRIGHTNESS_VALUE,
            (Integer)newValue);
      }
      else if (IAppInputsSettingsPopupProperties.AUDIO_CHANGE_REQUEST.equals(key) && (Integer)newValue > -1)
      {
        setApplicationOutputsProperty(IAppOutputsMainScreenSettingsProperties.SELECTED_AUDIO_VALUE,
            (Integer)newValue);
      }
    }
  }

}