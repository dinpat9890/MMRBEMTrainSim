/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/

/**
 * @author ext-tambet
 **/
package com.sydac.mmrbem.radio.common.io.properties;

import static com.sydac.foundation.PropertyKey.create;

import com.sydac.common.febe.binding.CommsBinding;
import com.sydac.foundation.PropertyKey;
import com.sydac.project.runtimedata.ProjectObjectConstants.RadioInputs;

public interface IAppInputsCallRequestAndNavigationPanelProperties
{
  @CommsBinding(property = RadioInputs.LOG_ON_BTN_REQUEST)
  PropertyKey<Integer> BTN_LOGON_REQUEST = create();

  @CommsBinding(property = RadioInputs.MAIN_GROUP_BTN_REQUEST)
  PropertyKey<Integer> MAIN_GROUP_BTN_REQUEST = create();

  @CommsBinding(property = RadioInputs.DEPOT_GROUP_BTN_REQUEST)
  PropertyKey<Integer> DEPOT_GROUP_BTN_REQUEST = create();

  @CommsBinding(property = RadioInputs.TRAIN_GROUP_BTN_REQUEST)
  PropertyKey<Integer> TRAIN_GROUP_BTN_REQUEST = create();

  @CommsBinding(property = RadioInputs.SHUNT_GROUP_BTN_REQUEST)
  PropertyKey<Integer> SHUNT_GROUP_BTN_REQUEST = create();

  @CommsBinding(property = RadioInputs.RTT_BTN_REQUEST)
  PropertyKey<Integer> RTT_BTN_REQUEST = create();

  @CommsBinding(property = RadioInputs.PA_BTN_REQUEST)
  PropertyKey<Integer> PA_BTN_REQUEST = create();

  @CommsBinding(property = RadioInputs.MSG_BTN_REQUEST)
  PropertyKey<Integer> MSG_BTN_REQUEST = create();

  @CommsBinding(property = RadioInputs.TR_REAR_BTN_REQUEST)
  PropertyKey<Integer> TR_REAR_BTN_REQUEST = create();

  @CommsBinding(property = RadioInputs.ALARM_BTN_REQUEST)
  PropertyKey<Integer> ALARM_BTN_REQUEST = create();

}
