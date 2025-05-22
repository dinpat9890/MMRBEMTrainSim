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

public interface IAppOutputsSpecialModesScreenProperties
{
  @CommsBinding(property = VDUOutputs.HTE_REQUIRED_STATUS)
  PropertyKey<Integer> HTE_REQUIRED_STATUS = create();

  @CommsBinding(property = VDUOutputs.WASHING_MODE_STATUS)
  PropertyKey<Integer> WASHING_MODE_STATUS = create();

  @CommsBinding(property = VDUOutputs.WASHING_SELECTED_SPEED)
  PropertyKey<Integer> WASHING_SELECTED_SPEED = create();
  
  @CommsBinding(property = VDUOutputs.SPECIAL_MODE_SHUNT_STATE)
  PropertyKey<Integer> SPECIAL_MODE_SHUNT_STATE = create();
  
  @CommsBinding(property = VDUOutputs.SPECIAL_MODE_ATP_LOW_SPEED_STATE)
  PropertyKey<Integer> SPECIAL_MODE_ATP_LOW_SPEED_STATE = create();
  
  @CommsBinding(property = VDUOutputs.SPECIAL_MODE_SHUNT_MIN_SPEED_VALUE)
  PropertyKey<Integer> SPECIAL_MODE_SHUNT_MIN_SPEED_VALUE = create();
  
  @CommsBinding(property = VDUOutputs.SPECIAL_MODE_SHUNT_MAX_SPEED_VALUE)
  PropertyKey<Integer> SPECIAL_MODE_SHUNT_MAX_SPEED_VALUE = create();
  
  @CommsBinding(property = VDUOutputs.SPECIAL_MODE_ATP_MAX_SPEED_VALUE)
  PropertyKey<Integer> SPECIAL_MODE_ATP_MAX_SPEED_VALUE = create();
  
  @CommsBinding(property = VDUOutputs.SHUNT_MODE_STATUS)
  PropertyKey<Integer> SHUNT_MODE_STATUS = create();
  
  @CommsBinding(property = VDUOutputs.ATP_LOW_SPEED_STATUS)
  PropertyKey<Integer> ATP_LOW_SPEED_STATUS = create();
  
  @CommsBinding(property = VDUOutputs.SHUNT_MODE_SET_BUTTON_STATUS)
  PropertyKey<Integer> SHUNT_MODE_SET_BUTTON_STATUS = create();
  
  @CommsBinding(property = VDUOutputs.ATP_LOW_MODE_SET_BUTTON_STATUS)
  PropertyKey<Integer> ATP_LOW_MODE_SET_BUTTON_STATUS = create();
  
}
