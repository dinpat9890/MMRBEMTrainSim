/*
 * ==================================================================
 *
 * (C) Copyright 2021 Oktal Sydac Pvt Ltd., all rights reserved. This is
 * unpublished proprietary source code of Sydac. The copyright notice above does
 * not evidence any actual or intended publication of such source code.
 * ==================================================================
 */
package com.sydac.mmrbem.tcms.backend.vehicle.io.properties;

import static com.sydac.foundation.PropertyKey.create;

import com.sydac.common.febe.binding.CommsBinding;
import com.sydac.foundation.PropertyKey;
import com.sydac.project.runtimedata.ProjectObjectConstants.Vehicle;
import com.sydac.project.runtimedata.ProjectObjectConstants.VehicleInputs;

/**
 * This interface holds variable for Vehicle.
 */

public interface IVehicleInputProperties
{
  @CommsBinding(property = VehicleInputs.APSICB)
  PropertyKey<Integer> APSICB = create();
  
  @CommsBinding(property = VehicleInputs.FDSCB)
  PropertyKey<Integer> FDSCB = create();
  
  @CommsBinding(property = VehicleInputs.SAC1CCB)
  PropertyKey<Integer> SAC1CCB = create();
  
  @CommsBinding(property = VehicleInputs.SAC2CCB)
  PropertyKey<Integer> SAC2CCB = create();
}
