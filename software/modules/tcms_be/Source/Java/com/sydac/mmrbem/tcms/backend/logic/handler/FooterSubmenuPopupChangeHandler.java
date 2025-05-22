/*
 * ==================================================================
 * 
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.tcms.backend.logic.handler;

import org.springframework.stereotype.Service;

import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.tcms.backend.comms.CommsBinding;
import com.sydac.mmrbem.tcms.backend.logic.AbstractFunctionalLogic;
import com.sydac.mmrbem.tcms.backend.logic.SharedDataModel;
import com.sydac.mmrbem.tcms.backend.logic.annotation.FunctionalLogicHandler;
import com.sydac.mmrbem.tcms.common.io.properties.IAppInputsFooterSubmenuPopupProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppInputsProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsFooterSubmenuPopupProperties;

/**
 * This handler class is used for Footer Submenu Popup change handling.
 * 
 */
@Service
@FunctionalLogicHandler(arguments = { CommsBinding.class, SharedDataModel.class })
public class FooterSubmenuPopupChangeHandler extends AbstractFunctionalLogic
{
  protected FooterSubmenuPopupChangeHandler(CommsBinding commsBinding, Class<?>[] propertyKeyDefinitions)
  {
    super(commsBinding, IAppInputsProperties.class);
  }

  @Override
  public <T> void appInputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue, int vehicleIndex)
  {
    if (getActiveVehicleIndex() == vehicleIndex)
    {
      if (key.equals(IAppInputsFooterSubmenuPopupProperties.FOOTER_SUBMENU_CHANGE_REQUEST)
          && (Integer)newValue > -1)
      {
        setApplicationOutputsProperty(IAppOutputsFooterSubmenuPopupProperties.FOOTER_POPUP_ID,
            (Integer)newValue);
      }
    }
  }
}
