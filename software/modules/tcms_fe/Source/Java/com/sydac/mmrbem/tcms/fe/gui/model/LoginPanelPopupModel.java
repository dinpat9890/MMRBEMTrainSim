/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.fe.gui.model;

import com.sydac.mmrbem.cabscreens.fe.gui.model.AbstractScreenModel;
import com.sydac.mmrbem.tcms.common.state.ApplicationConstants;
import com.sydac.mmrbem.tcms.fe.common.TCMSUIConstants;
import java.util.Objects;

import javafx.beans.property.BooleanProperty;
import javafx.beans.property.SimpleBooleanProperty;
import javafx.beans.property.SimpleStringProperty;
import javafx.beans.property.StringProperty;

public class LoginPanelPopupModel extends AbstractScreenModel
{
  private StringProperty userId = new SimpleStringProperty();

  private BooleanProperty keypadPanelVisible = new SimpleBooleanProperty();

  private BooleanProperty logoutPanelVisible = new SimpleBooleanProperty();

  public LoginPanelPopupModel(int carIndex)
  {
    super(carIndex);
  }

  public StringProperty getUserId()
  {
    return userId;
  }

  public void setUserId(byte[] userId)
  {
    String id = new String(userId);
    this.userId.set(Objects.equals(id, ApplicationConstants.BLANK) ? TCMSUIConstants.BLANK_STRING : id);
  }

  public BooleanProperty getKeypadPanelVisible()
  {
    return keypadPanelVisible;
  }

  public void setKeypadPanelVisible(Integer keypadPanelVisible)
  {
    this.keypadPanelVisible.set(keypadPanelVisible != 0);
  }

  public BooleanProperty getLogoutPanelVisible()
  {
    return logoutPanelVisible;
  }

  public void setLogoutPanelVisible(Integer logoutPanelVisible)
  {
    this.logoutPanelVisible.set(logoutPanelVisible != 0);
  }
}
