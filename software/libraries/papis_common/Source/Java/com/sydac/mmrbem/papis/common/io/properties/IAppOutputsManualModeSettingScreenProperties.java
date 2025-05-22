/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.papis.common.io.properties;

import static com.sydac.foundation.PropertyKey.create;

import com.sydac.common.febe.binding.CommsBinding;
import com.sydac.foundation.PropertyKey;
import com.sydac.project.runtimedata.ProjectObjectConstants.PAPISOutputs;

public interface IAppOutputsManualModeSettingScreenProperties
{
  @CommsBinding(property = PAPISOutputs.MANUAL_MODE_SCREEN_STATION_LIST)
  PropertyKey<byte[]> MANUAL_MODE_SCREEN_STATION_LIST = create();

  @CommsBinding(property = PAPISOutputs.LAST_STATION_ID)
  PropertyKey<Integer> LAST_STATION_ID = create();

  @CommsBinding(property = PAPISOutputs.MANUAL_MODE_SCREEN_ALL_STATION_LIST)
  PropertyKey<byte[]> MANUAL_MODE_SCREEN_ALL_STATION_LIST = create();

}
