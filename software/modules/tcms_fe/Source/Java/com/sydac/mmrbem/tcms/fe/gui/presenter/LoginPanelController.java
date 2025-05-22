/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.fe.gui.presenter;

import com.sydac.mmrbem.tcms.fe.gui.AbstractTCMSController;
import com.sydac.mmrbem.tcms.fe.gui.binder.LoginPanelBinder;
import com.sydac.mmrbem.tcms.fe.gui.model.LoginPanelModel;

public class LoginPanelController extends AbstractTCMSController
{

  private LoginPanelModel loginPanelModel;

  @Override
  public void detachListeners()
  {
    // TODO Auto-generated method stub

  }

  @Override
  public void initializeImpl()
  {
    loginPanelModel = new LoginPanelModel(scenarioCarIndex);
    tcmsScreenBinders.add(new LoginPanelBinder(loginPanelModel));

  }

}
