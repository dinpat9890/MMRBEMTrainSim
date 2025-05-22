/*
 * ==================================================================
 *
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *
 * ==================================================================
 */
package com.sydac.mmrbem.tcms.backend.vehicle.io.properties;

import static com.sydac.foundation.PropertyKey.create;

import com.sydac.common.febe.binding.CommsBinding;
import com.sydac.foundation.PropertyKey;
import com.sydac.project.runtimedata.ProjectObjectConstants.PISBEOutputs;

public interface IPISBEOutputsOperatingScreenProperties
{
  @CommsBinding(property = PISBEOutputs.SELECTED_START_STATION_ID)
  PropertyKey<Integer> SELECTED_START_STATION_ID = create();

  @CommsBinding(property = PISBEOutputs.SELECTED_CURRENT_STATION_ID)
  PropertyKey<Integer> SELECTED_CURRENT_STATION_ID = create();

  @CommsBinding(property = PISBEOutputs.SELECTED_TERMINAL_STATION_ID)
  PropertyKey<Integer> SELECTED_TERMINAL_STATION_ID = create();

  @CommsBinding(property = PISBEOutputs.SELECTED_NEXT_STATION_ID)
  PropertyKey<Integer> SELECTED_NEXT_STATION_ID = create();

  @CommsBinding(property = PISBEOutputs.SELECTED_MODE)
  PropertyKey<Integer> SELECTED_MODE = create();

  @CommsBinding(property = PISBEOutputs.SELECTED_ROUTE_ID)
  PropertyKey<Integer> SELECTED_ROUTE_ID = create();

  @CommsBinding(property = PISBEOutputs.SELECTED_TRAIN_ID)
  PropertyKey<Integer> SELECTED_TRAIN_ID = create();
  
  @CommsBinding(property = PISBEOutputs.SELECTED_ROUTE_ID_PSD)
  PropertyKey<Integer> SELECTED_ROUTE_ID_PSD = create();
}
