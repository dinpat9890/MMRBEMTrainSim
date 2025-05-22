/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.fe.gui.binder;

import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.cabscreens.fe.common.IFrontend;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsVduSettingsPopupProperties;
import com.sydac.mmrbem.tcms.fe.base.AbstractCommsListener;
import com.sydac.mmrbem.tcms.fe.common.Frontend;
import com.sydac.mmrbem.tcms.fe.gui.model.VduSettingsPopupModel;

public class VduSettingsPopupBinder extends AbstractCommsListener
{

  public VduSettingsPopupBinder(VduSettingsPopupModel vduSettingsPopupModel, IFrontend frontend)
  {
    this.vduSettingsPopupModel = vduSettingsPopupModel;
    setFrontend(frontend);
    propertyKeyDefinitions.add(IAppOutputsVduSettingsPopupProperties.class);
  }

  private VduSettingsPopupModel vduSettingsPopupModel;

  @Override
  protected <T> void appOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue)
  {
    if (Frontend.TCMS == frontend
        && key.equals(IAppOutputsVduSettingsPopupProperties.TCMS_BRIGHTNESS_BUTTON_SELECTED))
    {
      vduSettingsPopupModel.setCurrentBrightnessSetting((Integer)newValue);
    }
    else if (Frontend.CCTV == frontend
        && key.equals(IAppOutputsVduSettingsPopupProperties.CCTV_BRIGHTNESS_BUTTON_SELECTED))
    {
      vduSettingsPopupModel.setCurrentBrightnessSetting((Integer)newValue);
    }
  }

}
