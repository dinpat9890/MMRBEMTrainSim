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

/**
 * This handler class is used for Crew Id Pop up input properties logic
 * 
 * @author potdars
 *
 */
public interface IAppInputsCrewIdPopupProperties
{

  @CommsBinding(property = DMIInputs.CREW_ID_POPUP_SCREEN_BUTTON_0_PRESSED)
  PropertyKey<Integer> CREW_ID_POPUP_SCREEN_BUTTON_0_PRESSED = create();

  @CommsBinding(property = DMIInputs.CREW_ID_POPUP_SCREEN_BUTTON_1_PRESSED)
  PropertyKey<Integer> CREW_ID_POPUP_SCREEN_BUTTON_1_PRESSED = create();

  @CommsBinding(property = DMIInputs.CREW_ID_POPUP_SCREEN_BUTTON_2_PRESSED)
  PropertyKey<Integer> CREW_ID_POPUP_SCREEN_BUTTON_2_PRESSED = create();

  @CommsBinding(property = DMIInputs.CREW_ID_POPUP_SCREEN_BUTTON_3_PRESSED)
  PropertyKey<Integer> CREW_ID_POPUP_SCREEN_BUTTON_3_PRESSED = create();

  @CommsBinding(property = DMIInputs.CREW_ID_POPUP_SCREEN_BUTTON_4_PRESSED)
  PropertyKey<Integer> CREW_ID_POPUP_SCREEN_BUTTON_4_PRESSED = create();

  @CommsBinding(property = DMIInputs.CREW_ID_POPUP_SCREEN_BUTTON_5_PRESSED)
  PropertyKey<Integer> CREW_ID_POPUP_SCREEN_BUTTON_5_PRESSED = create();

  @CommsBinding(property = DMIInputs.CREW_ID_POPUP_SCREEN_BUTTON_6_PRESSED)
  PropertyKey<Integer> CREW_ID_POPUP_SCREEN_BUTTON_6_PRESSED = create();

  @CommsBinding(property = DMIInputs.CREW_ID_POPUP_SCREEN_BUTTON_7_PRESSED)
  PropertyKey<Integer> CREW_ID_POPUP_SCREEN_BUTTON_7_PRESSED = create();

  @CommsBinding(property = DMIInputs.CREW_ID_POPUP_SCREEN_BUTTON_8_PRESSED)
  PropertyKey<Integer> CREW_ID_POPUP_SCREEN_BUTTON_8_PRESSED = create();

  @CommsBinding(property = DMIInputs.CREW_ID_POPUP_SCREEN_BUTTON_9_PRESSED)
  PropertyKey<Integer> CREW_ID_POPUP_SCREEN_BUTTON_9_PRESSED = create();

  @CommsBinding(property = DMIInputs.CREW_ID_POPUP_SCREEN_CLEAR_BUTTON_PRESSED)
  PropertyKey<Integer> CREW_ID_POPUP_SCREEN_CLEAR_BUTTON_PRESSED = create();

  @CommsBinding(property = DMIInputs.CREW_ID_POPUP_SCREEN_VALIDATE_BUTTON_PRESSED)
  PropertyKey<Integer> CREW_ID_POPUP_SCREEN_VALIDATE_BUTTON_PRESSED = create();

  @CommsBinding(property = DMIInputs.CREW_ID_POPUP_SCREEN_CANCEL_BUTTON_PRESSED)
  PropertyKey<Integer> CREW_ID_POPUP_SCREEN_CANCEL_BUTTON_PRESSED = create();

}
