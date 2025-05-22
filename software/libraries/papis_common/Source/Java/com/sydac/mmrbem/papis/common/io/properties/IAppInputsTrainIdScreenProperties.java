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

public interface IAppInputsTrainIdScreenProperties
{
  @CommsBinding(property = PAPISInputs.TRAIN_ID_KEYPAD_BUTTON_REQUEST)
  PropertyKey<Integer> TRAIN_ID_KEYPAD_BUTTON_REQUEST = create();

  @CommsBinding(property = PAPISInputs.TRAIN_ID_SCREEN_OK_BUTTON)
  PropertyKey<Integer> TRAIN_ID_SCREEN_OK_BUTTON = create();

  @CommsBinding(property = PAPISInputs.TRAIN_ID_SCREEN_BACK_BUTTON)
  PropertyKey<Integer> TRAIN_ID_SCREEN_BACK_BUTTON = create();
}
