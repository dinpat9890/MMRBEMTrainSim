/*
 * ================================================================== (C)
 * Copyright 2020 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.dmi.fe.gui.binder;

import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.dmi.common.io.properties.IAppOutputsScreenSaverProperties;
import com.sydac.mmrbem.dmi.fe.base.AbstractCommsListener;
import com.sydac.mmrbem.dmi.fe.gui.model.ScreenSaverModel;

/**
 * The Class ScreenSaverBinder used to read software version from comms and
 * assign it to the model {@link ScreenSaverModel}
 * 
 * @author mulukg
 *
 */
public class ScreenSaverBinder extends AbstractCommsListener
{

  ScreenSaverModel screenSaverModel;

  public ScreenSaverBinder(ScreenSaverModel screenSaverModel)
  {
    propertyKeyDefinitions.add(IAppOutputsScreenSaverProperties.class);
    this.screenSaverModel = screenSaverModel;
  }

  @Override
  protected <T> void appInputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue)
  {
    if (key == IAppOutputsScreenSaverProperties.SOFTWARE_VERSION)
    {
      screenSaverModel.setSoftwareVersion(new String((byte[])newValue));
    }
  }
}
