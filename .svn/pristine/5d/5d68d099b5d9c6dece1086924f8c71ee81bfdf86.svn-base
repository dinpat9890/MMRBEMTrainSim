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
import com.sydac.mmrbem.radio.common.io.properties.IAppOutputsHeaderProperties;
import com.sydac.mmrbem.radio.fe.base.AbstractCommsListener;
import com.sydac.mmrbem.radio.fe.gui.model.HeaderPanelModel;

/**
 * The Class HeaderPanelBinder used to read header panel values from comms and
 * assign it to the model {@link HeaderPanelModel}
 * 
 * @author ext-tambet
 */
public class HeaderPanelBinder extends AbstractCommsListener
{
  HeaderPanelModel headerPanelModel;

  public HeaderPanelBinder(HeaderPanelModel headerPanelModel)
  {
    propertyKeyDefinitions.add(IAppOutputsHeaderProperties.class);
    this.headerPanelModel = headerPanelModel;
  }

  @Override
  protected <T> void appOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue)
  {
    if (IAppOutputsHeaderProperties.LINE_NAME.equals(key))
    {
      headerPanelModel.setLineName(new String((byte[])newValue));
    }
    else if (IAppOutputsHeaderProperties.MESSAGE_COUNT.equals(key))
    {
      headerPanelModel.setMessageCount((Integer)newValue);
    }
    else if (IAppOutputsHeaderProperties.RADIO_SIGNAL.equals(key))
    {
      headerPanelModel.setRadioSignal((Integer)newValue);
    }

  }

}
