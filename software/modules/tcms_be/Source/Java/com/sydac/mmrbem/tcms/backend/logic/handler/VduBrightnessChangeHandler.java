/*
 * ==================================================================
 * 
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.tcms.backend.logic.handler;

import org.springframework.stereotype.Service;

import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.tcms.backend.comms.CommsBinding;
import com.sydac.mmrbem.tcms.backend.logic.AbstractFunctionalLogic;
import com.sydac.mmrbem.tcms.backend.logic.SharedDataModel;
import com.sydac.mmrbem.tcms.backend.logic.annotation.FunctionalLogicHandler;
import com.sydac.mmrbem.tcms.common.io.properties.IAppInputsProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppInputsVDUBrightnessPopupProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsVduSettingsPopupProperties;
import com.sydac.mmrbem.tcms.common.state.VDUBrightnessModeEnum;

/**
 * This handler class is used for VDU Settings brightness change handling.
 * 
 */
@Service
@FunctionalLogicHandler(arguments = { CommsBinding.class, SharedDataModel.class })
public class VduBrightnessChangeHandler extends AbstractFunctionalLogic
{
  protected VduBrightnessChangeHandler(CommsBinding commsBinding, Class<?>[] propertyKeyDefinitions)
  {
    super(commsBinding, IAppInputsProperties.class);
  }

  @Override
  public void attachListeners()
  {
    super.attachListeners();
    setApplicationOutputsProperty(IAppOutputsVduSettingsPopupProperties.TCMS_BRIGHTNESS_BUTTON_SELECTED,
        VDUBrightnessModeEnum.BRIGHTNESS_AUTO.getId());
    setApplicationOutputsProperty(IAppOutputsVduSettingsPopupProperties.CCTV_BRIGHTNESS_BUTTON_SELECTED,
        VDUBrightnessModeEnum.BRIGHTNESS_AUTO.getId());
  }

  @Override
  public <T> void appInputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue, int vehicleIndex)
  {
    if (getActiveVehicleIndex() == vehicleIndex)
    {
      if (key.equals(IAppInputsVDUBrightnessPopupProperties.TCMS_BRIGHTNESS_BUTTON_REQUEST)
          && (Integer)newValue > -1)
      {
        setApplicationOutputsProperty(IAppOutputsVduSettingsPopupProperties.TCMS_BRIGHTNESS_BUTTON_SELECTED,
            (Integer)newValue);
      }
      else if (key.equals(IAppInputsVDUBrightnessPopupProperties.CCTV_BRIGHTNESS_BUTTON_REQUEST)
          && (Integer)newValue > -1)
      {
        setApplicationOutputsProperty(IAppOutputsVduSettingsPopupProperties.CCTV_BRIGHTNESS_BUTTON_SELECTED,
            (Integer)newValue);
      }
    }
  }
}
