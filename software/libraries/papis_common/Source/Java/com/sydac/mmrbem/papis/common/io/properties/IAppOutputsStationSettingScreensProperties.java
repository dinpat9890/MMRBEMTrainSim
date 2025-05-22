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

public interface IAppOutputsStationSettingScreensProperties
{
  @CommsBinding(property = PAPISOutputs.STATION_LIST)
  PropertyKey<byte[]> STATION_LIST = create();

  @CommsBinding(property = PAPISOutputs.STATION_OPTIONS_UP_ENABLED)
  PropertyKey<byte[]> STATION_OPTIONS_UP_ENABLED = create();

  @CommsBinding(property = PAPISOutputs.STATION_OPTIONS_DOWN_ENABLED)
  PropertyKey<byte[]> STATION_OPTIONS_DOWN_ENABLED = create();
}
