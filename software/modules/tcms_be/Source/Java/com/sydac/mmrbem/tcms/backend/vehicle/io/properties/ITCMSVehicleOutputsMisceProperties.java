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
 * This interface holds variable for Miscellania system of TCMSVehicleOutputs
 * variables.
 */
public interface ITCMSVehicleOutputsMisceProperties
{
  @CommsBinding(property = TCMSVehicleOutputs.DERAILMENT_DETECTED_LEFT)
  PropertyKey<Integer> DERAILMENT_DETECTED_LEFT = create();

  @CommsBinding(property = TCMSVehicleOutputs.DERAILMENT_DETECTED_RIGHT)
  PropertyKey<Integer> DERAILMENT_DETECTED_RIGHT = create();

  @CommsBinding(property = TCMSVehicleOutputs.OBSTRUCTION_DETECTED_LEFT)
  PropertyKey<Integer> OBSTRUCTION_DETECTED_LEFT = create();

  @CommsBinding(property = TCMSVehicleOutputs.OBSTRUCTION_DETECTED_RIGHT)
  PropertyKey<Integer> OBSTRUCTION_DETECTED_RIGHT = create();
  
 
  

}
