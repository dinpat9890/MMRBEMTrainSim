/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.backend.vehicle.io.properties;

import static com.sydac.foundation.PropertyKey.create;

import com.sydac.common.febe.binding.CommsBinding;
import com.sydac.foundation.PropertyKey;
import com.sydac.project.runtimedata.ProjectObjectConstants.TCMSVehicleOutputs;

public interface ITCMSVehicleOutputsEBLoopInterlockScreenProperties
{
  @CommsBinding(property = TCMSVehicleOutputs.EB_BY_CC)
  PropertyKey<Integer> EB_BY_CC = create();

  @CommsBinding(property = TCMSVehicleOutputs.EB_DUE_TO_PUSH_BUTTON)
  PropertyKey<Integer> EB_DUE_TO_PUSH_BUTTON = create();

  @CommsBinding(property = TCMSVehicleOutputs.EB_DUE_TO_DEADMAN)
  PropertyKey<Integer> EB_DUE_TO_DEADMAN = create();

  @CommsBinding(property = TCMSVehicleOutputs.EB_FOR_NON_CAB_ENABLED)
  PropertyKey<Integer> EB_FOR_NON_CAB_ENABLED = create();

  @CommsBinding(property = TCMSVehicleOutputs.EB_FOR_NON_DIRECTION_SELECTED)
  PropertyKey<Integer> EB_FOR_NON_DIRECTION_SELECTED = create();

  @CommsBinding(property = TCMSVehicleOutputs.EB_BY_MC)
  PropertyKey<Integer> EB_BY_MC = create();

  @CommsBinding(property = TCMSVehicleOutputs.EB_BY_BRAKE_LOOP)
  PropertyKey<Integer> EB_BY_BRAKE_LOOP = create();

  @CommsBinding(property = TCMSVehicleOutputs.EB_DUE_TO_ATC_ZERO_SPEED)
  PropertyKey<Integer> EB_DUE_TO_ATC_ZERO_SPEED = create();

}
