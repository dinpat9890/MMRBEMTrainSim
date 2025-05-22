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

public interface IAppOutputsCommonProperties
{
  @CommsBinding(property = PAPISOutputs.START_STATION_NAME)
  PropertyKey<byte[]> START_STATION_NAME = create();

  @CommsBinding(property = PAPISOutputs.CURRENT_STATION_NAME)
  PropertyKey<byte[]> CURRENT_STATION_NAME = create();

  @CommsBinding(property = PAPISOutputs.TERMINAL_STATION_NAME)
  PropertyKey<byte[]> TERMINAL_STATION_NAME = create();

  @CommsBinding(property = PAPISOutputs.NEXT_STATION_NAME)
  PropertyKey<byte[]> NEXT_STATION_NAME = create();

  @CommsBinding(property = PAPISOutputs.DOOR_OPENING_SIDE)
  PropertyKey<byte[]> DOOR_OPENING_SIDE = create();

  @CommsBinding(property = PAPISOutputs.CURRENT_LINE_NAME)
  PropertyKey<byte[]> CURRENT_LINE_NAME = create();

  @CommsBinding(property = PAPISOutputs.CONNECTION_TYPE_NAME)
  PropertyKey<byte[]> CONNECTION_TYPE_NAME = create();

  @CommsBinding(property = PAPISOutputs.ACTIVE_MODE)
  PropertyKey<Integer> ACTIVE_MODE = create();

  @CommsBinding(property = PAPISOutputs.TRAIN_ID)
  PropertyKey<byte[]> TRAIN_ID = create();

  @CommsBinding(property = PAPISOutputs.DOOR_STATUS)
  PropertyKey<Integer> DOOR_STATUS = create();

  @CommsBinding(property = PAPISOutputs.SELECT_BUTTON)
  PropertyKey<Integer> SELECT_BUTTON = create();

  @CommsBinding(property = PAPISOutputs.START_STATION_SELECTED_BUTTON)
  PropertyKey<Integer> START_STATION_SELECTED_BUTTON = create();

  @CommsBinding(property = PAPISOutputs.TERMINAL_STATION_SELECTED_BUTTON)
  PropertyKey<Integer> TERMINAL_STATION_SELECTED_BUTTON = create();

  @CommsBinding(property = PAPISOutputs.NEXT_STATION_SELECTED_BUTTON)
  PropertyKey<Integer> NEXT_STATION_SELECTED_BUTTON = create();

  @CommsBinding(property = PAPISOutputs.SPECIAL_MESSAGE_SELECTED)
  PropertyKey<Integer> SPECIAL_MESSAGE_SELECTED = create();

  @CommsBinding(property = PAPISOutputs.EMERGENCY_MESSAGE_SELECTED)
  PropertyKey<Integer> EMERGENCY_MESSAGE_SELECTED = create();
  
  @CommsBinding(property = PAPISOutputs.NUMBER_OF_CARS)
  PropertyKey<Integer> NUMBER_OF_CARS = create();

}