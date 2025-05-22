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
 * This interface holds variable for Status Screen of TCMSVehicleOutputs
 * variables.
 */
public interface ITCMSVehicleOutputsStatusScreenProperties
{
  @CommsBinding(property = TCMSVehicleOutputs.CCU_FAULT)
  PropertyKey<Integer> CCU_FAULT = create();

  @CommsBinding(property = TCMSVehicleOutputs.RIO1_FAULT)
  PropertyKey<Integer> RIO1_FAULT = create();

  @CommsBinding(property = TCMSVehicleOutputs.RIO1_RIO2_FAULT)
  PropertyKey<Integer> RIO1_RIO2_FAULT = create();

  @CommsBinding(property = TCMSVehicleOutputs.ER_FAULT)
  PropertyKey<Integer> ER_FAULT = create();
  
  @CommsBinding(property = TCMSVehicleOutputs.RIO1_STATUS)
  PropertyKey<Integer> RIO1_STATUS = create();
  
  @CommsBinding(property = TCMSVehicleOutputs.RIO2_STATUS)
  PropertyKey<Integer> RIO2_STATUS = create();
  
  @CommsBinding(property = TCMSVehicleOutputs.RIO2_FAULT)
  PropertyKey<Integer> RIO2_FAULT = create();
}
