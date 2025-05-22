/*******************************************************************************
 * (C) Copyright 2020 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.backend.vehicle.io.handlers;

import static com.sydac.foundation.PropertyKey.create;

import com.sydac.common.febe.binding.CommsBinding;
import com.sydac.foundation.PropertyKey;
import com.sydac.project.runtimedata.ProjectObjectConstants.CBTCVehicleInputs;

/**
 * This interface holds variable for CBTCVehicleInputs.
 * 
 */
public interface ICBTCVehicleInputsProperties
{
  @CommsBinding(property = CBTCVehicleInputs.AUDIO_TCMS_HIGH_PRIORITY_FAULT)
  PropertyKey<Integer> AUDIO_TCMS_HIGH_PRIORITY_FAULT = create();
}
