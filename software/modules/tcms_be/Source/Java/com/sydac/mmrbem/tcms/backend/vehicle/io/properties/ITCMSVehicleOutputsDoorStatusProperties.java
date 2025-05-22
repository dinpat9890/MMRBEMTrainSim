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

/**
 * This interface holds variable for vehicle Door Status of TCMSVehicleOutputs
 * variables.
 */
public interface ITCMSVehicleOutputsDoorStatusProperties
{
  // Door x Open
  @CommsBinding(property = TCMSVehicleOutputs.DOOR_A1_OPEN)
  PropertyKey<Integer> DOOR_A1_OPEN = create();

  @CommsBinding(property = TCMSVehicleOutputs.DOOR_A2_OPEN)
  PropertyKey<Integer> DOOR_A2_OPEN = create();

  @CommsBinding(property = TCMSVehicleOutputs.DOOR_A3_OPEN)
  PropertyKey<Integer> DOOR_A3_OPEN = create();

  @CommsBinding(property = TCMSVehicleOutputs.DOOR_A4_OPEN)
  PropertyKey<Integer> DOOR_A4_OPEN = create();

  @CommsBinding(property = TCMSVehicleOutputs.DOOR_B1_OPEN)
  PropertyKey<Integer> DOOR_B1_OPEN = create();

  @CommsBinding(property = TCMSVehicleOutputs.DOOR_B2_OPEN)
  PropertyKey<Integer> DOOR_B2_OPEN = create();

  @CommsBinding(property = TCMSVehicleOutputs.DOOR_B3_OPEN)
  PropertyKey<Integer> DOOR_B3_OPEN = create();

  @CommsBinding(property = TCMSVehicleOutputs.DOOR_B4_OPEN)
  PropertyKey<Integer> DOOR_B4_OPEN = create();
  
  @CommsBinding(property = TCMSVehicleOutputs.EMERGENCY_ESCAPE_DOOR_OPEN)
  PropertyKey<Integer> EMERGENCY_ESCAPE_DOOR_OPEN = create();

  // Door x Isolated
  @CommsBinding(property = TCMSVehicleOutputs.DOOR_A1_ISOLATED)
  PropertyKey<Integer> DOOR_A1_ISOLATED = create();

  @CommsBinding(property = TCMSVehicleOutputs.DOOR_A2_ISOLATED)
  PropertyKey<Integer> DOOR_A2_ISOLATED = create();

  @CommsBinding(property = TCMSVehicleOutputs.DOOR_A3_ISOLATED)
  PropertyKey<Integer> DOOR_A3_ISOLATED = create();

  @CommsBinding(property = TCMSVehicleOutputs.DOOR_A4_ISOLATED)
  PropertyKey<Integer> DOOR_A4_ISOLATED = create();

  @CommsBinding(property = TCMSVehicleOutputs.DOOR_B1_ISOLATED)
  PropertyKey<Integer> DOOR_B1_ISOLATED = create();

  @CommsBinding(property = TCMSVehicleOutputs.DOOR_B2_ISOLATED)
  PropertyKey<Integer> DOOR_B2_ISOLATED = create();

  @CommsBinding(property = TCMSVehicleOutputs.DOOR_B3_ISOLATED)
  PropertyKey<Integer> DOOR_B3_ISOLATED = create();

  @CommsBinding(property = TCMSVehicleOutputs.DOOR_B4_ISOLATED)
  PropertyKey<Integer> DOOR_B4_ISOLATED = create();
  
  @CommsBinding(property = TCMSVehicleOutputs.EMERGENCY_ESCAPE_DOOR_ISOLATED)
  PropertyKey<Integer> EMERGENCY_ESCAPE_DOOR_ISOLATED = create();

  // Door x Fault
  @CommsBinding(property = TCMSVehicleOutputs.DOOR_A1_FAULT)
  PropertyKey<Integer> DOOR_A1_FAULT = create();

  @CommsBinding(property = TCMSVehicleOutputs.DOOR_A2_FAULT)
  PropertyKey<Integer> DOOR_A2_FAULT = create();

  @CommsBinding(property = TCMSVehicleOutputs.DOOR_A3_FAULT)
  PropertyKey<Integer> DOOR_A3_FAULT = create();

  @CommsBinding(property = TCMSVehicleOutputs.DOOR_A4_FAULT)
  PropertyKey<Integer> DOOR_A4_FAULT = create();

  @CommsBinding(property = TCMSVehicleOutputs.DOOR_B1_FAULT)
  PropertyKey<Integer> DOOR_B1_FAULT = create();

  @CommsBinding(property = TCMSVehicleOutputs.DOOR_B2_FAULT)
  PropertyKey<Integer> DOOR_B2_FAULT = create();

  @CommsBinding(property = TCMSVehicleOutputs.DOOR_B3_FAULT)
  PropertyKey<Integer> DOOR_B3_FAULT = create();

  @CommsBinding(property = TCMSVehicleOutputs.DOOR_B4_FAULT)
  PropertyKey<Integer> DOOR_B4_FAULT = create();

  @CommsBinding(property = TCMSVehicleOutputs.EMERGENCY_ESCAPE_DOOR_FAULT)
  PropertyKey<Integer> EMERGENCY_ESCAPE_DOOR_FAULT = create();

  // Door x Emergency Released
  @CommsBinding(property = TCMSVehicleOutputs.DOOR_A1_EMERGENCY_RELEASED)
  PropertyKey<Integer> DOOR_A1_EMERGENCY_RELEASED = create();

  @CommsBinding(property = TCMSVehicleOutputs.DOOR_A2_EMERGENCY_RELEASED)
  PropertyKey<Integer> DOOR_A2_EMERGENCY_RELEASED = create();

  @CommsBinding(property = TCMSVehicleOutputs.DOOR_A3_EMERGENCY_RELEASED)
  PropertyKey<Integer> DOOR_A3_EMERGENCY_RELEASED = create();

  @CommsBinding(property = TCMSVehicleOutputs.DOOR_A4_EMERGENCY_RELEASED)
  PropertyKey<Integer> DOOR_A4_EMERGENCY_RELEASED = create();

  @CommsBinding(property = TCMSVehicleOutputs.DOOR_B1_EMERGENCY_RELEASED)
  PropertyKey<Integer> DOOR_B1_EMERGENCY_RELEASED = create();

  @CommsBinding(property = TCMSVehicleOutputs.DOOR_B2_EMERGENCY_RELEASED)
  PropertyKey<Integer> DOOR_B2_EMERGENCY_RELEASED = create();

  @CommsBinding(property = TCMSVehicleOutputs.DOOR_B3_EMERGENCY_RELEASED)
  PropertyKey<Integer> DOOR_B3_EMERGENCY_RELEASED = create();

  @CommsBinding(property = TCMSVehicleOutputs.DOOR_B4_EMERGENCY_RELEASED)
  PropertyKey<Integer> DOOR_B4_EMERGENCY_RELEASED = create();

  @CommsBinding(property = TCMSVehicleOutputs.EMERGENCY_ESCAPE_DOOR_RELEASED)
  PropertyKey<Integer> EMERGENCY_ESCAPE_DOOR_RELEASED = create();

  // Door x Locked
  @CommsBinding(property = TCMSVehicleOutputs.DOOR_A1_LOCKED)
  PropertyKey<Integer> DOOR_A1_LOCKED = create();

  @CommsBinding(property = TCMSVehicleOutputs.DOOR_A2_LOCKED)
  PropertyKey<Integer> DOOR_A2_LOCKED = create();

  @CommsBinding(property = TCMSVehicleOutputs.DOOR_A3_LOCKED)
  PropertyKey<Integer> DOOR_A3_LOCKED = create();

  @CommsBinding(property = TCMSVehicleOutputs.DOOR_A4_LOCKED)
  PropertyKey<Integer> DOOR_A4_LOCKED = create();

  @CommsBinding(property = TCMSVehicleOutputs.DOOR_B1_LOCKED)
  PropertyKey<Integer> DOOR_B1_LOCKED = create();

  @CommsBinding(property = TCMSVehicleOutputs.DOOR_B2_LOCKED)
  PropertyKey<Integer> DOOR_B2_LOCKED = create();

  @CommsBinding(property = TCMSVehicleOutputs.DOOR_B3_LOCKED)
  PropertyKey<Integer> DOOR_B3_LOCKED = create();

  @CommsBinding(property = TCMSVehicleOutputs.DOOR_B4_LOCKED)
  PropertyKey<Integer> DOOR_B4_LOCKED = create();

  @CommsBinding(property = TCMSVehicleOutputs.EMERGENCY_ESCAPE_DOOR_LOCKED)
  PropertyKey<Integer> EMERGENCY_ESCAPE_DOOR_LOCKED = create();
}
