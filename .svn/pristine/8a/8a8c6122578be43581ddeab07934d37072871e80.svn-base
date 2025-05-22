/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.fe.gui.binder;

import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.cabscreens.fe.common.IFrontend;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsActiveFaultsScreenProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsScreenChangeProperties;
import com.sydac.mmrbem.tcms.fe.base.AbstractCommsListener;
import com.sydac.mmrbem.tcms.fe.common.Frontend;
import com.sydac.mmrbem.tcms.fe.gui.model.FooterPanelModel;

public class FooterPanelBinder extends AbstractCommsListener
{

  private FooterPanelModel footerPanelModel;

  public FooterPanelBinder(FooterPanelModel footerPanelModel, IFrontend frontend)
  {
    super();
    setFrontend(frontend);
    this.footerPanelModel = footerPanelModel;
    propertyKeyDefinitions.add(IAppOutputsScreenChangeProperties.class);
    propertyKeyDefinitions.add(IAppOutputsActiveFaultsScreenProperties.class);
  }

  @Override
  protected <T> void appOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue)
  {
    if (Frontend.TCMS == frontend && IAppOutputsScreenChangeProperties.TCMS_CURRENT_SCREEN_ID.equals(key))
    {
      footerPanelModel.setCurrentScreenId((Integer)newValue);
    }
    else if (Frontend.CCTV == frontend
        && IAppOutputsScreenChangeProperties.CCTV_CURRENT_SCREEN_ID.equals(key))
    {
      footerPanelModel.setCurrentScreenId((Integer)newValue);
    }
    else if (Frontend.TCMS == frontend && IAppOutputsScreenChangeProperties.TCMS_POPUP_SCREEN_ID.equals(key))
    {
      footerPanelModel.setCurrentPopupId((Integer)newValue);
    }
    else if (Frontend.CCTV == frontend && IAppOutputsScreenChangeProperties.CCTV_POPUP_SCREEN_ID.equals(key))
    {
      footerPanelModel.setCurrentPopupId((Integer)newValue);
    }
    else if (IAppOutputsActiveFaultsScreenProperties.NO_OF_ACTIVE_FAULTS.equals(key))
    {
      footerPanelModel.setNoOfFaults((Integer)newValue);
    }
    else if (IAppOutputsActiveFaultsScreenProperties.FAULTS_BUTTON_PRIORITY_STATE.equals(key))
    {
      footerPanelModel.setFaultPriorityState((Integer)newValue);
    }
  }
}
