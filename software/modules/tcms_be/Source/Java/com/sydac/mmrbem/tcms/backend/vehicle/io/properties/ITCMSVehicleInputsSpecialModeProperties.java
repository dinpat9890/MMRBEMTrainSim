/*
 * *****************************************************************************
 * * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.backend.vehicle.io.properties;

import static com.sydac.foundation.PropertyKey.create;

import com.sydac.common.febe.binding.CommsBinding;
import com.sydac.foundation.PropertyKey;
import com.sydac.project.runtimedata.ProjectObjectConstants.TCMSVehicleInputs;

public interface ITCMSVehicleInputsSpecialModeProperties
{

  @CommsBinding(property = TCMSVehicleInputs.ACTIVATE_HTE)
  PropertyKey<Integer> ACTIVATE_HTE = create();

  @CommsBinding(property = TCMSVehicleInputs.ACTIVATE_WASHING_3_KMPH)
  PropertyKey<Integer> ACTIVATE_WASHING_3_KMPH = create();

  @CommsBinding(property = TCMSVehicleInputs.ACTIVATE_WASHING_4_KMPH)
  PropertyKey<Integer> ACTIVATE_WASHING_4_KMPH = create();

  @CommsBinding(property = TCMSVehicleInputs.ACTIVATE_WASHING_5_KMPH)
  PropertyKey<Integer> ACTIVATE_WASHING_5_KMPH = create();

  @CommsBinding(property = TCMSVehicleInputs.SHUNT_MODE_MAX_SPEED)
  PropertyKey<Integer> SHUNT_MODE_MAX_SPEED = create();

  @CommsBinding(property = TCMSVehicleInputs.SHUNT_MODE_MIN_SPEED)
  PropertyKey<Integer> SHUNT_MODE_MIN_SPEED = create();
  
  @CommsBinding(property = TCMSVehicleInputs.ATP_LOW_MODE_MAX_SPEED)
  PropertyKey<Integer> ATP_LOW_MODE_MAX_SPEED = create();
  
  @CommsBinding(property = TCMSVehicleInputs.ATP_LOW_MODE_ACTIVATED)
  PropertyKey<Integer> ATP_LOW_MODE_ACTIVATED = create();
  
  @CommsBinding(property = TCMSVehicleInputs.SHUNT_MODE_ACTIVATED)
  PropertyKey<Integer> SHUNT_MODE_ACTIVATED = create();
}
