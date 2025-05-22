/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.common.io.properties;

import static com.sydac.foundation.PropertyKey.create;

import com.sydac.common.febe.binding.CommsBinding;
import com.sydac.foundation.PropertyKey;
import com.sydac.project.runtimedata.ProjectObjectConstants.VDUOutputs;

public interface IAppOutputsRouteScreenProperties
{
  @CommsBinding(property = VDUOutputs.TCMS_PAPIS_SELECTED_MODE)
  PropertyKey<Integer> TCMS_PAPIS_SELECTED_MODE = create();

  @CommsBinding(property = VDUOutputs.ROUTE_SCREEN_TRAIN_ID)
  PropertyKey<byte[]> ROUTE_SCREEN_TRAIN_ID = create();

  @CommsBinding(property = VDUOutputs.ROUTE_SCREEN_START_ST_ID)
  PropertyKey<byte[]> ROUTE_SCREEN_START_ST_ID = create();

  @CommsBinding(property = VDUOutputs.ROUTE_SCREEN_DEST_ST_ID)
  PropertyKey<byte[]> ROUTE_SCREEN_DEST_ST_ID = create();

  @CommsBinding(property = VDUOutputs.ROUTE_SCREEN_SLCTD_START_PLATFORM)
  PropertyKey<Integer> ROUTE_SCREEN_SLCTD_START_PLATFORM = create();

  @CommsBinding(property = VDUOutputs.ROUTE_SCREEN_SLCTD_DEST_PLATFORM)
  PropertyKey<Integer> ROUTE_SCREEN_SLCTD_DEST_PLATFORM = create();
  
  @CommsBinding(property = VDUOutputs.SEMI_AUTO_TRAIN_ID)
  PropertyKey<byte[]> SEMI_AUTO_TRAIN_ID = create();
  
  
  @CommsBinding(property = VDUOutputs.STATION_LIST)
  PropertyKey<byte[]> STATION_LIST = create();
  
  @CommsBinding(property = VDUOutputs.STATION_ENTER_BUTTON_STATE)
  PropertyKey<Integer> STATION_ENTER_BUTTON_STATE = create();
  
  @CommsBinding(property = VDUOutputs.SELECTED_STATION_NAME)
  PropertyKey<byte[]> SELECTED_STATION_NAME = create();
  
  
  
  @CommsBinding(property = VDUOutputs.TRAIN_UNDER_EVAC_SET_BUTTON_STATE)
  PropertyKey<Integer> TRAIN_UNDER_EVAC_SET_BUTTON_STATE = create();
  
  @CommsBinding(property = VDUOutputs.TRAIN_OUT_OF_SERVICE_SET_BUTTON_STATE)
  PropertyKey<Integer> TRAIN_OUT_OF_SERVICE_SET_BUTTON_STATE = create();
  
  @CommsBinding(property = VDUOutputs.TRAIN_HOLD_BUTTON_STATE)
  PropertyKey<Integer> TRAIN_HOLD_BUTTON_STATE = create();
  
  @CommsBinding(property = VDUOutputs.DELAY_IN_SERVICE_BUTTON_STATE)
  PropertyKey<Integer> DELAY_IN_SERVICE_BUTTON_STATE = create();
  
  @CommsBinding(property = VDUOutputs.START_SERVICE_BUTTON_STATE)
  PropertyKey<Integer> START_SERVICE_BUTTON_STATE = create();
  
  @CommsBinding(property = VDUOutputs.SKIP_STATION_LIST)
  PropertyKey<byte[]> SKIP_STATION_LIST = create();
  
  @CommsBinding(property = VDUOutputs.LINE_2_STATION_LIST)
  PropertyKey<byte[]> LINE_2_STATION_LIST = create();
  
  @CommsBinding(property = VDUOutputs.LINE_7_STATION_LIST)
  PropertyKey<byte[]> LINE_7_STATION_LIST = create();
}
