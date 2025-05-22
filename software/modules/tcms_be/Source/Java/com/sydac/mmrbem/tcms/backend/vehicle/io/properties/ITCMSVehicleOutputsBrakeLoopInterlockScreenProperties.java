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

public interface ITCMSVehicleOutputsBrakeLoopInterlockScreenProperties
{
  @CommsBinding(property = TCMSVehicleOutputs.MAIN_RESERVOIR_PRESSURE_LOW)
  PropertyKey<Integer> MAIN_RESERVOIR_PRESSURE_LOW = create();

  @CommsBinding(property = TCMSVehicleOutputs.ADD_INTERVENTION)
  PropertyKey<Integer> ADD_INTERVENTION = create();

  
  @CommsBinding(property = TCMSVehicleOutputs.BRAKE_LOOP_CB_TRIPPED)
  PropertyKey<Integer> BRAKE_LOOP_CB_TRIPPED = create();

  

 
}
