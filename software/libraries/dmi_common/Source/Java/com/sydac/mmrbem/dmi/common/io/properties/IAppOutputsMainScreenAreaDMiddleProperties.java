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
 * This interface defines {@link PropertyKey} instances for Main Screen Area D
 * Application Outputs.
 *
 */
public interface IAppOutputsMainScreenAreaDMiddleProperties
{
  @CommsBinding(property = DMIOutputs.PSD_DOOR_STATUS)
  PropertyKey<Integer> PSD_DOOR_STATUS = create();

  @CommsBinding(property = DMIOutputs.TRAIN_DOCKING_STATUS)
  PropertyKey<Integer> TRAIN_DOCKING_STATUS = create();

  @CommsBinding(property = DMIOutputs.OPERATIONAL_SERVICE_STOPPING_DISTANCE)
  PropertyKey<byte[]> OPERATIONAL_SERVICE_STOPPING_DISTANCE = create();

  @CommsBinding(property = DMIOutputs.DEPARTURE_ORDER)
  PropertyKey<Integer> DEPARTURE_ORDER = create();

  @CommsBinding(property = DMIOutputs.DEPARTURE_INFORMATION_STATUS)
  PropertyKey<Integer> DEPARTURE_INFORMATION_STATUS = create();

  @CommsBinding(property = DMIOutputs.REMAINING_TIME_BEFORE_DEPARTURE)
  PropertyKey<byte[]> REMAINING_TIME_BEFORE_DEPARTURE = create();

  @CommsBinding(property = DMIOutputs.REMAINING_TIME_IN_MINUTE_STATUS)
  PropertyKey<Boolean> REMAINING_TIME_IN_MINUTE_STATUS = create();

  @CommsBinding(property = DMIOutputs.TRAIN_DOOR_STATUS)
  PropertyKey<Integer> TRAIN_DOOR_STATUS = create();
  
  @CommsBinding(property = DMIOutputs.DETRAINMENT_DOOR_STATUS)
  PropertyKey<Integer> DETRAINMENT_DOOR_STATUS = create();

}
