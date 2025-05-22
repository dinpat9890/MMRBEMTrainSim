/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.fe.gui.binder;

import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsDoorSystemScreenProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsTrainConfigurationProperties;
import com.sydac.mmrbem.tcms.fe.base.AbstractCommsListener;
import com.sydac.mmrbem.tcms.fe.gui.model.DoorSystemScreenModel;

public class DoorSystemScreenBinder extends AbstractCommsListener
{

  private DoorSystemScreenModel doorSystemScreenModel;

  public DoorSystemScreenBinder(DoorSystemScreenModel doorSystemScreenModel)
  {
    super();
    this.doorSystemScreenModel = doorSystemScreenModel;
    propertyKeyDefinitions.add(IAppOutputsDoorSystemScreenProperties.class);
    propertyKeyDefinitions.add(IAppOutputsTrainConfigurationProperties.class);
  }

  @Override
  protected <T> void appOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue)
  {
    if (IAppOutputsDoorSystemScreenProperties.DCU_STATUS_1.equals(key))
    {
      doorSystemScreenModel.setDcu1State((byte[])newValue);
    }
    else if (IAppOutputsDoorSystemScreenProperties.DCU_STATUS_2.equals(key))
    {
      doorSystemScreenModel.setDcu2State((byte[])newValue);
    }
    else if (IAppOutputsDoorSystemScreenProperties.DCU_STATUS_3.equals(key))
    {
      doorSystemScreenModel.setDcu3State((byte[])newValue);
    }
    else if (IAppOutputsDoorSystemScreenProperties.DCU_STATUS_4.equals(key))
    {
      doorSystemScreenModel.setDcu4State((byte[])newValue);
    }
    else if (IAppOutputsDoorSystemScreenProperties.DCU_STATUS_5.equals(key))
    {
      doorSystemScreenModel.setDcu5State((byte[])newValue);
    }
    else if (IAppOutputsDoorSystemScreenProperties.DCU_STATUS_6.equals(key))
    {
      doorSystemScreenModel.setDcu6State((byte[])newValue);
    }
    else if (IAppOutputsDoorSystemScreenProperties.DCU_STATUS_7.equals(key))
    {
      doorSystemScreenModel.setDcu7State((byte[])newValue);
    }
    else if (IAppOutputsDoorSystemScreenProperties.DCU_STATUS_8.equals(key))
    {
      doorSystemScreenModel.setDcu8State((byte[])newValue);
    }
  }

}
