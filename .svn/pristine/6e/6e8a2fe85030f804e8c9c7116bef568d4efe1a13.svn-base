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
import com.sydac.mmrbem.radio.common.io.properties.IAppOutputCallInfoProperties;
import com.sydac.mmrbem.radio.fe.base.AbstractCommsListener;
import com.sydac.mmrbem.radio.fe.gui.model.CallInfoPanelModel;
import com.sydac.mmrbem.radio.fe.gui.model.MainMenuModel;

/**
 * The Class CallInfoPanelBinder used to read call info values from comms and
 * assign it to the model {@link CallInfoPanelModel}
 * 
 * @author ext-tambet
 */
public class MainMenuBinder extends AbstractCommsListener
{

  private MainMenuModel mainMenuModel;

  public MainMenuBinder(MainMenuModel mainMenuModel)
  {
    this.mainMenuModel = mainMenuModel;
    propertyKeyDefinitions.add(IAppOutputCallInfoProperties.class);
  }

  @Override
  protected <T> void appOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue)
  {

    if (IAppOutputCallInfoProperties.INCOMING_CALL_TYPE.equals(key))
    {
      mainMenuModel.setCallType((Integer)newValue);
    }
    

  }

}
