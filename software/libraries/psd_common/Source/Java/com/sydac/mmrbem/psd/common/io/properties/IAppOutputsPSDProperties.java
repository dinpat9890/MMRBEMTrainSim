/*******************************************************************************
 * (C) Copyright 2020 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.psd.common.io.properties;

import static com.sydac.foundation.PropertyKey.create;

import com.sydac.common.febe.binding.CommsBinding;
import com.sydac.foundation.PropertyKey;
import com.sydac.project.runtimedata.ProjectObjectConstants.PSDOutputs;

/**
 * This interface defines {@link PropertyKey} instances for PSD
 * Application Outputs.
 *
 */
public interface IAppOutputsPSDProperties
{

  @CommsBinding(property = PSDOutputs.PSE_ENABLE_STATUS)
  PropertyKey<Integer> PSE_ENABLE_STATUS = create();

  @CommsBinding(property = PSDOutputs.TRAIN_DOCKING_STATUS)
  PropertyKey<Integer> TRAIN_DOCKING_STATUS = create();

  @CommsBinding(property = PSDOutputs.INTERLOCK_OVERRIDE_STATUS)
  PropertyKey<Integer> INTERLOCK_OVERRIDE_STATUS = create();

  @CommsBinding(property = PSDOutputs.TRAIN_DIRECTION)
  PropertyKey<Integer> TRAIN_DIRECTION = create();

  @CommsBinding(property = PSDOutputs.PLATFORM_SIDE)
  PropertyKey<Integer> PLATFORM_SIDE = create();

  @CommsBinding(property = PSDOutputs.LAMP_TEST_STATUS)
  PropertyKey<Integer> LAMP_TEST_STATUS = create();

  @CommsBinding(property = PSDOutputs.PSD_DOOR_STATUS)
  PropertyKey<Integer> PSD_DOOR_STATUS = create();
}
