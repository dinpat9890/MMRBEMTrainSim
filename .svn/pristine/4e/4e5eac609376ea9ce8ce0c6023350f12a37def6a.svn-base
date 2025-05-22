/*
 * ==================================================================
 *
 * (C) Copyright 2022 Oktal Sydac Pvt Ltd., all rights reserved. This is
 * unpublished proprietary source code of Sydac. The copyright notice above does
 * not evidence any actual or intended publication of such source code.
 * ==================================================================
 */

package com.sydac.mmrbem.tcms.fe.gui.binder;

import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsHeaderPanelProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsScreenChangeProperties;
import com.sydac.mmrbem.tcms.fe.base.AbstractCommsListener;
import com.sydac.mmrbem.tcms.fe.gui.model.HeaderPanelModel;

public class HeaderPanelBinder extends AbstractCommsListener
{

  private HeaderPanelModel headerPanelModel;

  public HeaderPanelBinder(HeaderPanelModel headerPanelModel)
  {
    this.headerPanelModel = headerPanelModel;
    propertyKeyDefinitions.add(IAppOutputsHeaderPanelProperties.class);
    propertyKeyDefinitions.add(IAppOutputsScreenChangeProperties.class);
  }

  @Override
  protected <T> void appOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue)
  {
    if (key.equals(IAppOutputsHeaderPanelProperties.OPERATING_MODE))
    {
      headerPanelModel.setOperatingMode((Integer)newValue);
    }
    else if (key.equals(IAppOutputsHeaderPanelProperties.DRIVING_MODE))
    {
      headerPanelModel.setDrivingMode((Integer)newValue);
    }
    else if (key.equals(IAppOutputsHeaderPanelProperties.TRAIN_CURRENT_SPEED))
    {
      headerPanelModel.setTrainSpeed((Double)newValue);
    }
    else if (key.equals(IAppOutputsHeaderPanelProperties.TRAIN_SPEED_LIMIT))
    {
      headerPanelModel.setSpeedLimit((Double)newValue);
    }
    else if (key.equals(IAppOutputsHeaderPanelProperties.PASSENGERS_COUNT))
    {
      headerPanelModel.setPassengerCount((Integer)newValue);
    }
    else if (key.equals(IAppOutputsHeaderPanelProperties.LOGIN_INFO_TITLE))
    {
      headerPanelModel.setLoginTitleInfo((Integer)newValue);
    }
    else if (key.equals(IAppOutputsScreenChangeProperties.TCMS_CURRENT_SCREEN_ID))
    {
      headerPanelModel.setCurrentScreenId((Integer)newValue);
    }
    else if (key.equals(IAppOutputsScreenChangeProperties.CCTV_CURRENT_SCREEN_ID))
    {
      headerPanelModel.setCurrentCctvScreenId((Integer)newValue);
    }
  }

}
