/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.papis.common.io.properties;

import static com.sydac.foundation.PropertyKey.create;

import com.sydac.common.febe.binding.CommsBinding;
import com.sydac.foundation.PropertyKey;
import com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs;

public interface IAppInputsStationSettingScreensProperties
{
  @CommsBinding(property = PAPISInputs.SELECTED_START_ST_ID_REQUEST)
  PropertyKey<Integer> SELECTED_START_ST_ID_REQUEST = create();

  @CommsBinding(property = PAPISInputs.SELECTED_TERMINAL_ST_ID_REQUEST)
  PropertyKey<Integer> SELECTED_TERMINAL_ST_ID_REQUEST = create();

  @CommsBinding(property = PAPISInputs.SELECTED_NEXT_ST_ID_REQUEST)
  PropertyKey<Integer> SELECTED_NEXT_ST_ID_REQUEST = create();

  @CommsBinding(property = PAPISInputs.STATION_SELECTION_SCREN_UP_PRESSED)
  PropertyKey<Integer> STATION_SELECTION_SCREN_UP_PRESSED = create();

  @CommsBinding(property = PAPISInputs.STATION_SELECTION_SCREN_DOWN_PRESSED)
  PropertyKey<Integer> STATION_SELECTION_SCREN_DOWN_PRESSED = create();

  @CommsBinding(property = PAPISInputs.START_STATION_SELECTED)
  PropertyKey<Integer> START_STATION_SELECTED = create();

  @CommsBinding(property = PAPISInputs.TERMINAL_STATION_SELECTED)
  PropertyKey<Integer> TERMINAL_STATION_SELECTED = create();

  @CommsBinding(property = PAPISInputs.NEXT_STATION_SELECTED)
  PropertyKey<Integer> NEXT_STATION_SELECTED = create();
}
