/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.fe.gui.binder;

import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.cabscreens.fe.common.IFrontend;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsVduSelectionPopupProperties;
import com.sydac.mmrbem.tcms.fe.base.AbstractCommsListener;
import com.sydac.mmrbem.tcms.fe.common.Frontend;
import com.sydac.mmrbem.tcms.fe.gui.model.VduSelectionPopupModel;

public class VduSelectionPopupBinder extends AbstractCommsListener
{

  private VduSelectionPopupModel vduSelectionPopupModel;

  public VduSelectionPopupBinder(VduSelectionPopupModel vduSelectionPopupModel, IFrontend frontend)
  {
    this.vduSelectionPopupModel = vduSelectionPopupModel;
    setFrontend(frontend);
    propertyKeyDefinitions.add(IAppOutputsVduSelectionPopupProperties.class);
  }

  @Override
  protected <T> void appOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue)
  {
    if (Frontend.TCMS == frontend
        && key.equals(IAppOutputsVduSelectionPopupProperties.TCMS_VDU_BUTTON_SELECTED))
    {
      vduSelectionPopupModel.setVduSelected((Integer)newValue);
    }
    else if (Frontend.CCTV == frontend
        && key.equals(IAppOutputsVduSelectionPopupProperties.CCTV_VDU_BUTTON_SELECTED))
    {
      vduSelectionPopupModel.setCurrentCctvVduMode((Integer)newValue);
    }
  }
}
