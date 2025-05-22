/*
 * *****************************************************************************
 * * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.papis.backend.vehicle.io.properties;

import static com.sydac.foundation.PropertyKey.create;

import com.sydac.common.febe.binding.CommsBinding;
import com.sydac.foundation.PropertyKey;
import com.sydac.project.runtimedata.ProjectObjectConstants.PAPISVehicleOutputs;

/**
 * This interface holds variable for PAPIS Vehicle outputs.
 * 
 */
public interface IPAPISVehicleOutputsMainInterfaceScreenProperties
{
  @CommsBinding(property = PAPISVehicleOutputs.DOOR_OPEN)
  PropertyKey<Integer> DOOR_OPEN = create();

  @CommsBinding(property = PAPISVehicleOutputs.DOOR_CLOSE)
  PropertyKey<Integer> DOOR_CLOSE = create();
}