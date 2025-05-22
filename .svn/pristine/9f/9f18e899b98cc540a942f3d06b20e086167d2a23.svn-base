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
 * This interface defines {@link PropertyKey} instances for Main Screen Area
 * Text Message Application Outputs.
 *
 */

public interface IAppOutputsMainScreenAreaTextMessageProperties
{
  @CommsBinding(property = DMIOutputs.ACTIVE_TEXT_MESSAGES)
  PropertyKey<byte[]> ACTIVE_TEXT_MESSAGES = create();

  @CommsBinding(property = DMIOutputs.TEXT_MESSAGE_UP_BUTTON_STATUS)
  PropertyKey<Boolean> TEXT_MESSAGE_UP_BUTTON_STATUS = create();

  @CommsBinding(property = DMIOutputs.TEXT_MESSAGE_DOWN_BUTTON_STATUS)
  PropertyKey<Boolean> TEXT_MESSAGE_DOWN_BUTTON_STATUS = create();

  @CommsBinding(property = DMIOutputs.NEW_MESSAGE_INDICATION)
  PropertyKey<Boolean> NEW_MESSGAE_INDICATION = create();
}
