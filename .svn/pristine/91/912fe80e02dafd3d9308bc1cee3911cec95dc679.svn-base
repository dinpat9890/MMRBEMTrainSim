/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.papis.fe.gui.binder;

import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.papis.common.io.properties.IAppOutputsCommonProperties;
import com.sydac.mmrbem.papis.common.io.properties.IAppOutputsSpecialInformationScreenProperties;
import com.sydac.mmrbem.papis.fe.base.AbstractCommsListener;
import com.sydac.mmrbem.papis.fe.gui.model.SpecialInformationScreenModel;

public class SpecialInformationScreenBinder extends AbstractCommsListener
{

  private SpecialInformationScreenModel specialInformationScreenModel;

  public SpecialInformationScreenBinder(SpecialInformationScreenModel specialInformationScreenModel)
  {
    this.specialInformationScreenModel = specialInformationScreenModel;
    propertyKeyDefinitions.add(IAppOutputsSpecialInformationScreenProperties.class);
    propertyKeyDefinitions.add(IAppOutputsCommonProperties.class);
  }

  @Override
  protected <T> void appOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue)
  {
    if (IAppOutputsSpecialInformationScreenProperties.SPC_INFO_LIST.equals(key))
    {
      specialInformationScreenModel.setSpcInfoList((byte[])newValue);
    }
    else if (IAppOutputsCommonProperties.SPECIAL_MESSAGE_SELECTED.equals(key))
    {
      specialInformationScreenModel.setSpecialMessageSelected((Integer)newValue);
    }
  }
}
