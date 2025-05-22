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
import com.sydac.mmrbem.dmi.common.io.properties.IAppOutputsStartupScreenProperties;
import com.sydac.mmrbem.dmi.fe.base.AbstractCommsListener;
import com.sydac.mmrbem.dmi.fe.gui.model.StartupScreenModel;

/**
 * The Class StartupScreenBinder used to read progress value from comms and
 * assign it to the model {@link StartupScreenModel}
 * 
 * @author ext-savanjin
 *
 */
public class StartupScreenBinder extends AbstractCommsListener
{

  StartupScreenModel startupScreenModel;

  public StartupScreenBinder(StartupScreenModel startupScreenModel)
  {
    propertyKeyDefinitions.add(IAppOutputsStartupScreenProperties.class);
    this.startupScreenModel = startupScreenModel;
  }

  @Override
  protected <T> void appInputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue)
  {
    if (key == IAppOutputsStartupScreenProperties.PROGRESS_BAR_VALUE)
    {
      startupScreenModel.setProgressBarValue((Double)newValue);
    }
  }
}
