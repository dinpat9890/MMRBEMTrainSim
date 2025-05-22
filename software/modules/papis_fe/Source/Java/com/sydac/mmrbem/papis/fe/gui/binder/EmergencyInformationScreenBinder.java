/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.papis.fe.gui.binder;

import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.papis.common.io.properties.IAppOutputsCommonProperties;
import com.sydac.mmrbem.papis.common.io.properties.IAppOutputsEmergencyInformationScreenProperties;
import com.sydac.mmrbem.papis.fe.base.AbstractCommsListener;
import com.sydac.mmrbem.papis.fe.gui.model.EmergencyInformationScreenModel;

public class EmergencyInformationScreenBinder extends AbstractCommsListener
{

  private EmergencyInformationScreenModel emergencyInformationScreenModel;

  public EmergencyInformationScreenBinder(EmergencyInformationScreenModel emergencyInformationScreenModel)
  {
    this.emergencyInformationScreenModel = emergencyInformationScreenModel;
    propertyKeyDefinitions.add(IAppOutputsEmergencyInformationScreenProperties.class);
    propertyKeyDefinitions.add(IAppOutputsCommonProperties.class);
  }

  @Override
  protected <T> void appOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue)
  {
    if (IAppOutputsEmergencyInformationScreenProperties.EMG_INFO_LIST.equals(key))
    {
      emergencyInformationScreenModel.setEmgInfoList((byte[])newValue);
    }
    else if (IAppOutputsCommonProperties.EMERGENCY_MESSAGE_SELECTED.equals(key))
    {
      emergencyInformationScreenModel.setEmergencyInformationSelected((Integer)newValue);
    }
  }
}
