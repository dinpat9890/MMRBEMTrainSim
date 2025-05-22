/*
 * ==================================================================
 *
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *
 * ==================================================================
 */
package com.sydac.mmrbem.papis.backend.vehicle.io.properties;

import static com.sydac.foundation.PropertyKey.create;

import com.sydac.common.febe.binding.CommsBinding;
import com.sydac.foundation.PropertyKey;
import com.sydac.project.runtimedata.ProjectObjectConstants.PISBEInputsValues;

public interface IPISBEInputsStationSettingScreensProperties
{
  @CommsBinding(property = PISBEInputsValues.START_STATION_ID)
  PropertyKey<Integer> START_STATION_ID = create();

  @CommsBinding(property = PISBEInputsValues.NEXT_STATION_ID)
  PropertyKey<Integer> NEXT_STATION_ID = create();

  @CommsBinding(property = PISBEInputsValues.TERMINAL_STATION_ID)
  PropertyKey<Integer> TERMINAL_STATION_ID = create();
}
