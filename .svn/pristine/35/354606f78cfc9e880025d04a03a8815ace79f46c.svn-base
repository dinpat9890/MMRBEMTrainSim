/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.fe.gui.binder;

import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsSpecialModesScreenProperties;
import com.sydac.mmrbem.tcms.fe.base.AbstractCommsListener;
import com.sydac.mmrbem.tcms.fe.gui.model.SpecialModesScreenModel;

public class SpecialModesScreenBinder extends AbstractCommsListener
{

  private SpecialModesScreenModel specialModesScreenModel;

  public SpecialModesScreenBinder(SpecialModesScreenModel specialModesScreenModel)
  {
    super();
    this.specialModesScreenModel = specialModesScreenModel;
    propertyKeyDefinitions.add(IAppOutputsSpecialModesScreenProperties.class);
  }

  @Override
  protected <T> void appOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue)
  {
    if (key.equals(IAppOutputsSpecialModesScreenProperties.HTE_REQUIRED_STATUS))
    {
      specialModesScreenModel.setHteStatusProperty((Integer)newValue);
    }
    else if (key.equals(IAppOutputsSpecialModesScreenProperties.WASHING_MODE_STATUS))
    {
      specialModesScreenModel.setWashingStatusProperty((Integer)newValue);
    }
    else if (key.equals(IAppOutputsSpecialModesScreenProperties.WASHING_SELECTED_SPEED))
    {
      specialModesScreenModel.setSpeedProperty((Integer)newValue);
    }
    else if (key.equals(IAppOutputsSpecialModesScreenProperties.SPECIAL_MODE_SHUNT_MIN_SPEED_VALUE))
    {
      specialModesScreenModel.setShuntMinSpeedProperty((Integer)newValue);
    }
    else if (key.equals(IAppOutputsSpecialModesScreenProperties.SPECIAL_MODE_SHUNT_MAX_SPEED_VALUE))
    {
      specialModesScreenModel.setShuntMaxSpeedProperty((Integer)newValue);
    }
    else if (key.equals(IAppOutputsSpecialModesScreenProperties.SPECIAL_MODE_ATP_MAX_SPEED_VALUE))
    {
      specialModesScreenModel.setAtpMaxSpeedProperty((Integer)newValue);
    }
    else if (key.equals(IAppOutputsSpecialModesScreenProperties.SHUNT_MODE_STATUS))
    {
      specialModesScreenModel.setShuntModeStatusProperty((Integer)newValue);
    }
    else if (key.equals(IAppOutputsSpecialModesScreenProperties.ATP_LOW_SPEED_STATUS))
    {
      specialModesScreenModel.setAtpLowSpeedStatusProperty((Integer)newValue);
    }
    else if (key.equals(IAppOutputsSpecialModesScreenProperties.SHUNT_MODE_SET_BUTTON_STATUS))
    {
      specialModesScreenModel.setShuntModeButtonStatusProperty((Integer)newValue);
    }
    else if (key.equals(IAppOutputsSpecialModesScreenProperties.ATP_LOW_MODE_SET_BUTTON_STATUS))
    {
      specialModesScreenModel.setAtpModeSetButtonStatusProperty((Integer)newValue);
    }
  }
}
