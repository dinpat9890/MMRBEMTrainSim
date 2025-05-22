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
import com.sydac.mmrbem.radio.common.io.properties.IAppOutputContactScreenProperties;
import com.sydac.mmrbem.radio.fe.base.AbstractCommsListener;
import com.sydac.mmrbem.radio.fe.gui.model.PowerMenuAndNavPanelModel;

/**
 * The Class PowerMenuAndNavPanelModel used to read info values from
 * comms and assign it to the model {@link PowerMenuAndNavPanelModel}
 * 
 * @author mulukg
 */
public class PowerMenuAndNavPanelBinder extends AbstractCommsListener
{
  private PowerMenuAndNavPanelModel powerMenuAndNavPanelModel;

  public PowerMenuAndNavPanelBinder(PowerMenuAndNavPanelModel powerMenuAndNavPanelModel)
  {
    propertyKeyDefinitions.add(IAppOutputContactScreenProperties.class);
    this.powerMenuAndNavPanelModel = powerMenuAndNavPanelModel;
  }

  @Override
  protected <T> void appOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue)
  {
    if (IAppOutputContactScreenProperties.CONTACT_SCREEN_SELECTED_BTN.equals(key))
    {
      powerMenuAndNavPanelModel.setContactNavBtnStatus((Integer)newValue);
    }

  }
}
