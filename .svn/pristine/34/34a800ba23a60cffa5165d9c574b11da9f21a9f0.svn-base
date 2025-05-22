/*
 * ================================================================== (C)
 * Copyright 2020 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * ==================================================================
 */
package com.sydac.mmrbem.dmi.backend.logic.handler;

import org.springframework.stereotype.Service;

import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.dmi.backend.comms.CommsBinding;
import com.sydac.mmrbem.dmi.backend.logic.AbstractFunctionalLogic;
import com.sydac.mmrbem.dmi.backend.logic.annotation.FunctionalLogicHandler;
import com.sydac.mmrbem.dmi.common.io.properties.IAppInputsMenuPopupProperties;
import com.sydac.mmrbem.dmi.common.io.properties.IAppOutputsPopupMenuProperties;

/**
 * This handler class is responsible for managing Menu pop up.
 * 
 */
@Service
@FunctionalLogicHandler(arguments = { CommsBinding.class })
public class MenuPopupHandler extends AbstractFunctionalLogic
{

  private CommsBinding commsBinding;

  public MenuPopupHandler(CommsBinding commsBinding)
  {
    super(commsBinding, IAppInputsMenuPopupProperties.class);
    this.commsBinding = commsBinding;
  }

  @Override
  public <T> void appInputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue, int vehicleIndex)
  {
    if (key.equals(IAppInputsMenuPopupProperties.MENU_BUTTON_PRESS_REQUEST))
    {
      if ((Integer)newValue > 0)
      {
        setApplicationOutputsProperty(IAppOutputsPopupMenuProperties.MENU_PANEL_STATUS, true);
      }
    }

    else if (key.equals(IAppInputsMenuPopupProperties.MENU_CLOSE_BUTTON_PRESS_REQUEST))
    {
      if ((Integer)newValue > 0)
      {
        setApplicationOutputsProperty(IAppOutputsPopupMenuProperties.MENU_PANEL_STATUS, false);
      }
    }
  }

}
