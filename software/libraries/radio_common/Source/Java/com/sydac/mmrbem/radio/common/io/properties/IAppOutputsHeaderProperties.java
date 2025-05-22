/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.radio.common.io.properties;

import static com.sydac.foundation.PropertyKey.create;

import com.sydac.common.febe.binding.CommsBinding;
import com.sydac.foundation.PropertyKey;
import com.sydac.project.runtimedata.ProjectObjectConstants.RadioOutputs;

public interface IAppOutputsHeaderProperties
{
  @CommsBinding(property = RadioOutputs.MESSAGE_COUNT)
  PropertyKey<Integer> MESSAGE_COUNT = create();

  @CommsBinding(property = RadioOutputs.RADIO_SIGNAL)
  PropertyKey<Integer> RADIO_SIGNAL = create();

  @CommsBinding(property = RadioOutputs.LINE_NAME)
  PropertyKey<byte[]> LINE_NAME = create();
}
