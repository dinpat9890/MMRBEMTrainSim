/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.radio.common.io.properties;

import static com.sydac.foundation.PropertyKey.create;

import com.sydac.common.febe.binding.CommsBinding;
import com.sydac.foundation.PropertyKey;
import com.sydac.project.runtimedata.ProjectObjectConstants.RadioInputs;

public interface IAppInputsPowerMenuNavPanelProperties
{

  @CommsBinding(property = RadioInputs.POWER_BTN_REQUEST)
  PropertyKey<Integer> POWER_BTN_REQUEST = create();

  @CommsBinding(property = RadioInputs.EMERGENCY_BTN_REQUEST)
  PropertyKey<Integer> EMERGENCY_BTN_REQUEST = create();

  @CommsBinding(property = RadioInputs.START_MSG_BTN_REQUEST)
  PropertyKey<Integer> START_MSG_BTN_REQUEST = create();

  @CommsBinding(property = RadioInputs.MENU_BTN_REQUEST)
  PropertyKey<Integer> MENU_BTN_REQUEST = create();

  @CommsBinding(property = RadioInputs.CONTACT_BTN_REQUEST)
  PropertyKey<Integer> CONTACT_BTN_REQUEST = create();

  @CommsBinding(property = RadioInputs.NAVIGATION_UP_ARROW_REQUEST)
  PropertyKey<Integer> NAVIGATION_UP_ARROW_REQUEST = create();

  @CommsBinding(property = RadioInputs.NAVIGATION_DOWN_ARROW_REQUEST)
  PropertyKey<Integer> NAVIGATION_DOWN_ARROW_REQUEST = create();
}
