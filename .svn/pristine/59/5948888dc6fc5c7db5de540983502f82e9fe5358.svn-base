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

public interface IAppOutputsPassengerAlarmScreenProperties
{
  @CommsBinding(property = PAPISOutputs.ALARM_STATUS)
  PropertyKey<Integer> ALARM_STATUS = create();

  @CommsBinding(property = PAPISOutputs.FLASH_STATUS)
  PropertyKey<Integer> FLASH_STATUS = create();

  @CommsBinding(property = PAPISOutputs.INTERCOM_STATUS)
  PropertyKey<Integer> INTERCOM_STATUS = create();

  @CommsBinding(property = PAPISOutputs.CALL_TYPE)
  PropertyKey<Integer> CALL_TYPE = create();

  @CommsBinding(property = PAPISOutputs.RECEIVED_PECU_ID)
  PropertyKey<Integer> RECEIVED_PECU_ID = create();

  @CommsBinding(property = PAPISOutputs.PC_ALARM_LIST_UP_ARROW_PRESSED)
  PropertyKey<Integer> PC_ALARM_LIST_UP_ARROW_PRESSED = create();

  @CommsBinding(property = PAPISOutputs.PC_ALARM_LIST_DOWN_ARROW_PRESSED)
  PropertyKey<Integer> PC_ALARM_LIST_DOWN_ARROW_PRESSED = create();
  
  @CommsBinding(property = PAPISOutputs.PASSENGER_ALARM_SELECTED)
  PropertyKey<Integer> PASSENGER_ALARM_SELECTED = create();
  
  @CommsBinding(property = PAPISOutputs.PASSENGER_ALARM_STATE)
  PropertyKey<Integer> PASSENGER_ALARM_STATE = create();
  
  @CommsBinding(property = PAPISOutputs.MULTIPLE_PECU_CALL_LIST)
  PropertyKey<byte[]> MULTIPLE_PECU_CALL_LIST = create();
  
  @CommsBinding(property = PAPISOutputs.PECU_CALL_COUNT)
  PropertyKey<Integer> PECU_CALL_COUNT = create();
}
