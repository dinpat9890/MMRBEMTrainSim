/*******************************************************************************
 * (C) Copyright 2020 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.dmi.common.io.properties;

import static com.sydac.foundation.PropertyKey.create;

import com.sydac.common.febe.binding.CommsBinding;
import com.sydac.foundation.PropertyKey;
import com.sydac.project.runtimedata.ProjectObjectConstants.DMIInputs;

public interface IAppInputsSettingsPopupProperties
{
  @CommsBinding(property = DMIInputs.AUDIO_BUTTON_PRESS_REQUEST)
  PropertyKey<Integer> AUDIO_BUTTON_PRESS_REQUEST = create();

  @CommsBinding(property = DMIInputs.BRIGHTNESS_BUTTON_PRESS_REQUEST)
  PropertyKey<Integer> BRIGHTNESS_BUTTON_PRESS_REQUEST = create();

  @CommsBinding(property = DMIInputs.AUDIO_CLOSE_REQUEST)
  PropertyKey<Integer> AUDIO_CLOSE_REQUEST = create();

  @CommsBinding(property = DMIInputs.BRIGHTNESS_CLOSE_REQUEST)
  PropertyKey<Integer> BRIGHTNESS_CLOSE_REQUEST = create();

  @CommsBinding(property = DMIInputs.BRIGHTNESS_CHANGE_REQUEST)
  PropertyKey<Integer> BRIGHTNESS_CHANGE_REQUEST = create();

  @CommsBinding(property = DMIInputs.AUDIO_CHANGE_REQUEST)
  PropertyKey<Integer> AUDIO_CHANGE_REQUEST = create();
}
