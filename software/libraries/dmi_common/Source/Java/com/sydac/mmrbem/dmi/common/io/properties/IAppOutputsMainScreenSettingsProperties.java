/*******************************************************************************
 * (C) Copyright 2020 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.dmi.common.io.properties;

import static com.sydac.foundation.PropertyKey.create;

import com.sydac.common.febe.binding.CommsBinding;
import com.sydac.foundation.PropertyKey;
import com.sydac.project.runtimedata.ProjectObjectConstants.DMIOutputs;

/**
 * This interface defines {@link PropertyKey} instances for Main Screen Area A
 * Application Outputs.
 *
 */
public interface IAppOutputsMainScreenSettingsProperties
{
  @CommsBinding(property = DMIOutputs.SELECTED_BRIGHTNESS_VALUE)
  PropertyKey<Integer> SELECTED_BRIGHTNESS_VALUE = create();

  @CommsBinding(property = DMIOutputs.SELECTED_AUDIO_VALUE)
  PropertyKey<Integer> SELECTED_AUDIO_VALUE = create();

  @CommsBinding(property = DMIOutputs.SELECTED_SETTINGS_PANEL)
  PropertyKey<Integer> SELECTED_SETTINGS_PANEL = create();
}
