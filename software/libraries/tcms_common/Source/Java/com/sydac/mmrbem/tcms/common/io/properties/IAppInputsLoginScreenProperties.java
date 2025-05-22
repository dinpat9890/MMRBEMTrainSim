/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.common.io.properties;

import static com.sydac.foundation.PropertyKey.create;

import com.sydac.common.febe.binding.CommsBinding;
import com.sydac.foundation.PropertyKey;
import com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs;

/**
 * This interface defines {@link PropertyKey} instances for login screen
 * ApplicaitonInputs.
 * 
 */
public interface IAppInputsLoginScreenProperties
{
  @CommsBinding(property = VDUInputs.OPERATOR_BUTTON_PRESSED)
  PropertyKey<Integer> OPERATOR_BUTTON_PRESSED = create();
  
  @CommsBinding(property = VDUInputs.LOGOUT_BUTTON_PRESSED)
  PropertyKey<Integer> LOGOUT_BUTTON_PRESSED = create();
  
  @CommsBinding(property = VDUInputs.KEYPAD_BUTTON_REQUEST)
  PropertyKey<Integer> KEYPAD_BUTTON_REQUEST = create();
}
