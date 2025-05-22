/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.common.io.properties;

import static com.sydac.foundation.PropertyKey.create;

import com.sydac.common.febe.binding.CommsBinding;
import com.sydac.foundation.PropertyKey;
import com.sydac.project.runtimedata.ProjectObjectConstants.VDUOutputs;

public interface IAppOutputsHeaderPanelProperties
{

  @CommsBinding(property = VDUOutputs.OPERATING_MODE)
  PropertyKey<Integer> OPERATING_MODE = create();

  @CommsBinding(property = VDUOutputs.DRIVING_MODE)
  PropertyKey<Integer> DRIVING_MODE = create();

  @CommsBinding(property = VDUOutputs.TRAIN_SPEED_LIMIT)
  PropertyKey<Double> TRAIN_SPEED_LIMIT = create();

  @CommsBinding(property = VDUOutputs.TRAIN_CURRENT_SPEED)
  PropertyKey<Double> TRAIN_CURRENT_SPEED = create();

  @CommsBinding(property = VDUOutputs.LOGIN_INFO_TITLE)
  PropertyKey<Integer> LOGIN_INFO_TITLE = create();

  @CommsBinding(property = VDUOutputs.PASSENGERS_COUNT)
  PropertyKey<Integer> PASSENGERS_COUNT = create();

}
