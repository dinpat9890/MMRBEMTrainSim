/*
 * ================================================================== (C)
 * Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.radio.fe.gui.binder;

import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.radio.common.io.properties.IAppOutputsCommonProperties;
import com.sydac.mmrbem.radio.fe.base.AbstractCommsListener;
import com.sydac.mmrbem.radio.fe.gui.model.VolumeScreenModel;



public class VolumeScreenBinder extends AbstractCommsListener
{
  VolumeScreenModel volumeScreenModel;

  public VolumeScreenBinder(VolumeScreenModel voulmeModell)
  {
    propertyKeyDefinitions.add(IAppOutputsCommonProperties.class);
    this.volumeScreenModel = voulmeModell;
  }

  @Override
  protected <T> void appOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue)
  {
    if (IAppOutputsCommonProperties.DOWN_BUTTON_VALUE.equals(key))
    {
      volumeScreenModel.setDownBtnStatus((Integer)newValue);
    }else if (IAppOutputsCommonProperties.UP_BUTTON_VALUE.equals(key))
    {
      volumeScreenModel.setUpBtnStatus((Integer)newValue);
    }

  }
}
