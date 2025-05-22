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

public interface IAppInputsTextMessageProperties
{
  @CommsBinding(property = DMIInputs.TEXT_MESSAGE_UP_BUTTON_REQUEST)
  PropertyKey<Boolean> TEXT_MESSAGE_UP_BUTTON_REQUEST = create();

  @CommsBinding(property = DMIInputs.TEXT_MESSAGE_DOWN_BUTTON_REQUEST)
  PropertyKey<Boolean> TEXT_MESSAGE_DOWN_BUTTON_REQUEST = create();

  @CommsBinding(property = DMIInputs.TEXT_MESSAGE_ACKNOWLEDGE_REQUEST)
  PropertyKey<Integer> TEXT_MESSAGE_ACKNOWLEDGE_REQUEST = create();

  @CommsBinding(property = DMIInputs.CREW_BUTTON_PRESS_REQUEST)
  PropertyKey<Integer> CREW_BUTTON_PRESS_REQUEST = create();
}
