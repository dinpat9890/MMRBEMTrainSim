/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.psd.fe.gui.binder;

import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.psd.common.io.properties.IAppOutputsPSDProperties;
import com.sydac.mmrbem.psd.fe.base.AbstractCommsListener;
import com.sydac.mmrbem.psd.fe.gui.model.PsdPanelModel;

public class PsdPanelBinder extends AbstractCommsListener
{

  private PsdPanelModel psdPanelModel;

  public PsdPanelBinder(PsdPanelModel psdPanelModel)
  {
    this.psdPanelModel = psdPanelModel;
    propertyKeyDefinitions.add(IAppOutputsPSDProperties.class);
  }

  @Override
  protected <T> void appOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue)
  {
    if (IAppOutputsPSDProperties.PSE_ENABLE_STATUS.equals(key))
    {
      psdPanelModel.setPseEnableState((Integer)newValue);
    }
    else if (IAppOutputsPSDProperties.INTERLOCK_OVERRIDE_STATUS.equals(key))
    {
      psdPanelModel.setInterlockOverrideStatus((Integer)newValue);
    }
    else if (IAppOutputsPSDProperties.LAMP_TEST_STATUS.equals(key))
    {
      psdPanelModel.setLampStatus((Integer)newValue);
    }
    else if (IAppOutputsPSDProperties.PSD_DOOR_STATUS.equals(key))
    {
      psdPanelModel.setPsdDoorStatus((Integer)newValue);
    }

  }

}
