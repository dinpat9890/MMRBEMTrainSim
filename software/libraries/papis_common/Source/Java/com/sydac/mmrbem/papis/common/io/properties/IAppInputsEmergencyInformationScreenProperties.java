/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.papis.common.io.properties;

import static com.sydac.foundation.PropertyKey.create;

import com.sydac.common.febe.binding.CommsBinding;
import com.sydac.foundation.PropertyKey;
import com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs;

public interface IAppInputsEmergencyInformationScreenProperties
{
  @CommsBinding(property = PAPISInputs.EMG_INFO_ID_REQ)
  PropertyKey<Integer> EMG_INFO_ID_REQ = create();

  @CommsBinding(property = PAPISInputs.EMG_INFO_NO_OF_TIMES)
  PropertyKey<Integer> EMG_INFO_NO_OF_TIMES = create();

  @CommsBinding(property = PAPISInputs.EMG_INFO_SCREEN_OK_BUTTON_PRESSED)
  PropertyKey<Integer> EMG_INFO_SCREEN_OK_BUTTON_PRESSED = create();

  @CommsBinding(property = PAPISInputs.EMG_INFO_SCREEN_UP_BUTTON_PRESSED)
  PropertyKey<Integer> EMG_INFO_SCREEN_UP_BUTTON_PRESSED = create();

  @CommsBinding(property = PAPISInputs.EMG_INFO_SCREEN_DOWN_BUTTON_PRESSED)
  PropertyKey<Integer> EMG_INFO_SCREEN_DOWN_BUTTON_PRESSED = create();

  @CommsBinding(property = PAPISInputs.EMG_INFO_SCREEN_STOP_BUTTON_PRESSED)
  PropertyKey<Integer> EMG_INFO_SCREEN_STOP_BUTTON_PRESSED = create();

  @CommsBinding(property = PAPISInputs.CURRENT_EMERGENCY_MESSAGE)
  PropertyKey<Integer> CURRENT_EMERGENCY_MESSAGE = create();
}
