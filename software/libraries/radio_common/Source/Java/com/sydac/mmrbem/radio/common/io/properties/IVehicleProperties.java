/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.radio.common.io.properties;

import static com.sydac.foundation.PropertyKey.create;

import com.sydac.common.febe.binding.CommsBinding;
import com.sydac.foundation.PropertyKey;
import com.sydac.project.runtimedata.ProjectObjectConstants.Vehicle;

/**
 * This interface defines {@link PropertyKey} instances for Vehicle.
 * 
 */
public interface IVehicleProperties
{
  @CommsBinding(property = Vehicle.FLT_TRAIN_RADIO_FAILURE)
  PropertyKey<Integer> FLT_TRAIN_RADIO_FAILURE = create();
}
