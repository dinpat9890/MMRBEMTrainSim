/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.fe.gui.presenter;

import com.sydac.mmrbem.cabscreens.fe.common.NodePseudoClassProperty;
import com.sydac.mmrbem.tcms.common.ScreenId;
import com.sydac.mmrbem.tcms.common.state.ApplicationConstants;
import com.sydac.mmrbem.tcms.common.state.HeaderPanelTitleEnum;
import com.sydac.mmrbem.tcms.common.state.OperatingModeEnum;
import com.sydac.mmrbem.tcms.fe.base.TCMSFactory;
import com.sydac.mmrbem.tcms.fe.gui.AbstractTCMSController;
import com.sydac.mmrbem.tcms.fe.gui.binder.FooterPanelBinder;
import com.sydac.mmrbem.tcms.fe.gui.binder.HeaderPanelBinder;
import com.sydac.mmrbem.tcms.fe.gui.model.FooterPanelModel;
import com.sydac.mmrbem.tcms.fe.gui.model.HeaderPanelModel;

import javafx.beans.value.ChangeListener;
import javafx.fxml.FXML;
import javafx.scene.control.Label;
import javafx.scene.input.MouseEvent;
import javafx.scene.input.TouchEvent;

public class HeaderBeforeLoginPanelController extends AbstractTCMSController
{

  @FXML
  private Label opModeLbl;

  @FXML
  private Label loginTitleInfoLbl;

  @FXML
  private Label dateLabel;

  @FXML
  private Label timeLabel;

  @FXML
  private Label userLoginIcon;

  @FXML
  private Label vduSettingsIcon;

  private HeaderPanelModel headerPanelModel;

  private ChangeListener<Number> operationModeListener;

  private ChangeListener<Number> loginTitleInfoListener;

  private ChangeListener<String> dateLabelListener;

  private ChangeListener<String> timeLabelListener;

  private NodePseudoClassProperty loginTitleInfoProperty;

  private FooterPanelModel footerPanelModel;

  private ChangeListener<Number> popupIdListener;

  private int currentPopupId = 0;

  @Override
  public void detachListeners()
  {
    this.headerPanelModel.getCurrentDate().removeListener(dateLabelListener);
    this.headerPanelModel.getCurrentTime().removeListener(timeLabelListener);
    headerPanelModel.getOperatingMode().removeListener(operationModeListener);
    headerPanelModel.getLoginTitleInfo().removeListener(loginTitleInfoListener);
    footerPanelModel.getCurrentPopupId().removeListener(popupIdListener);
  }

  @Override
  public void initializeImpl()
  {

    headerPanelModel = new HeaderPanelModel(scenarioCarIndex);
    tcmsScreenBinders.add(new HeaderPanelBinder(headerPanelModel));

    footerPanelModel = new FooterPanelModel(scenarioCarIndex);
    tcmsScreenBinders.add(new FooterPanelBinder(footerPanelModel, frontend));

    dateLabelListener = (observable, oldVal, newVal) -> updateDateLabel(newVal);
    this.headerPanelModel.getCurrentDate().addListener(dateLabelListener);

    timeLabelListener = (observable, oldVal, newVal) -> updateTimeLabel(newVal);
    this.headerPanelModel.getCurrentTime().addListener(timeLabelListener);

    operationModeListener = (observable, oldVal, newVal) -> updateOperatingMode((int)newVal);
    headerPanelModel.getOperatingMode().addListener(operationModeListener);

    loginTitleInfoProperty = new NodePseudoClassProperty(loginTitleInfoLbl);
    loginTitleInfoListener = (observable, oldVal, newVal) -> updateLoginTitleInfo((int)newVal);
    headerPanelModel.getLoginTitleInfo().addListener(loginTitleInfoListener);

    popupIdListener = ((observable, oldVal, newVal) -> currentPopupId = (Integer)newVal);
    footerPanelModel.getCurrentPopupId().addListener(popupIdListener);

    updateDateLabel(this.headerPanelModel.getCurrentDate().get());
    updateTimeLabel(this.headerPanelModel.getCurrentTime().get());
    updateOperatingMode(headerPanelModel.getOperatingMode().get());
    updateLoginTitleInfo(headerPanelModel.getLoginTitleInfo().get());

    currentPopupId = footerPanelModel.getCurrentPopupId().get();
  }

  private void updateDateLabel(String newVal)
  {
    this.dateLabel.setText(newVal);
  }

  private void updateTimeLabel(String newVal)
  {
    this.timeLabel.setText(newVal);
  }

  private void updateOperatingMode(int opMode)
  {
    OperatingModeEnum operatingMode = OperatingModeEnum.valueOf(opMode);
    opModeLbl.setText(operatingMode.getText());
  }

  private void updateLoginTitleInfo(int loginAccessState)
  {
    loginTitleInfoLbl.setText(HeaderPanelTitleEnum.valueOf(loginAccessState).getText());
    loginTitleInfoProperty.set(HeaderPanelTitleEnum.valueOf(loginAccessState).toString().toLowerCase());
  }

  @FXML
  void onUserLoginMouseClicked(MouseEvent event)
  {
    updatePopupScreen(ScreenId.LOGIN_PANEL_POPUP);
  }

  @FXML
  void onUserLoginTouchPressed(TouchEvent event)
  {
    if (ApplicationConstants.IS_TOUCH_ENABLED)
    {
      updatePopupScreen(ScreenId.LOGIN_PANEL_POPUP);
    }
  }

  @FXML
  void onVduSettingsMouseClicked(MouseEvent event)
  {
    updatePopupScreen(ScreenId.VDU_SETTINGS_POPUP);
  }

  @FXML
  void onVduSettingsTouchPressed(TouchEvent event)
  {
    if (ApplicationConstants.IS_TOUCH_ENABLED)
    {
      updatePopupScreen(ScreenId.VDU_SETTINGS_POPUP);
    }
  }

  private void updatePopupScreen(ScreenId popupId)
  {
    if (currentPopupId == popupId.getId())
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendPopupChangeRequest(ScreenId.BLANK_SCREEN,
          frontend);
    }
    else
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendPopupChangeRequest(popupId, frontend);
    }
  }
}
