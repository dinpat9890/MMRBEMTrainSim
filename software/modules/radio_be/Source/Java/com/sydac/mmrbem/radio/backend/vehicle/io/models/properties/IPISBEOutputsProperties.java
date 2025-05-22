/*
 * *****************************************************************************
 * * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.radio.backend.vehicle.io.models.properties;

import static com.sydac.foundation.PropertyKey.create;

import com.sydac.common.febe.binding.CommsBinding;
import com.sydac.foundation.PropertyKey;
import com.sydac.project.runtimedata.ProjectObjectConstants.PISBEOutputs;

/**
 * This interface holds variable for TCMSVehicleOutputs.
 * 
 */
public interface IPISBEOutputsProperties 
{
  @CommsBinding(property = PISBEOutputs.SELECTED_ROUTE_ID_PSD)
  PropertyKey<Integer> SELECTED_ROUTE_ID_PSD = create();

 

}
