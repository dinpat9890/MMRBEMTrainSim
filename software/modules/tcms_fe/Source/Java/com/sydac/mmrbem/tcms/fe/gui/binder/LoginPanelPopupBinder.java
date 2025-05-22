/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.fe.gui.binder;

import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsLoginPopupProperties;
import com.sydac.mmrbem.tcms.fe.base.AbstractCommsListener;
import com.sydac.mmrbem.tcms.fe.gui.model.LoginPanelPopupModel;

public class LoginPanelPopupBinder extends AbstractCommsListener
{

  private LoginPanelPopupModel loginPanelPopupModel;

  public LoginPanelPopupBinder(LoginPanelPopupModel loginPanelPopupModel)
  {
    this.loginPanelPopupModel = loginPanelPopupModel;
    propertyKeyDefinitions.add(IAppOutputsLoginPopupProperties.class);
  }

  @Override
  protected <T> void appOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue)
  {
    if (key.equals(IAppOutputsLoginPopupProperties.OPERATOR_BUTTON_SELECTED))
    {
      loginPanelPopupModel.setKeypadPanelVisible((Integer)newValue);
    }
    else if (key.equals(IAppOutputsLoginPopupProperties.USER_ID))
    {
      loginPanelPopupModel.setUserId((byte[])newValue);
    }
    else if (key.equals(IAppOutputsLoginPopupProperties.USER_LOGGED_IN))
    {
      loginPanelPopupModel.setLogoutPanelVisible((Integer)newValue);
    }
  }

}
