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

public interface IAppOutputsTrainConfigurationProperties
{
  @CommsBinding(property = VDUOutputs.TRAIN_CONFIGURATION_DATA)
  PropertyKey<byte[]> TRAIN_CONFIGURATION_DATA = create();

  @CommsBinding(property = VDUOutputs.NUMBER_OF_CARS)
  PropertyKey<Integer> NUMBER_OF_CARS = create();
}
