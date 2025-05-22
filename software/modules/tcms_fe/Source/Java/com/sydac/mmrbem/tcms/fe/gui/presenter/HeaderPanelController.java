/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.fe.gui.presenter;

import com.sydac.mmrbem.tcms.common.ScreenId;
import com.sydac.mmrbem.tcms.common.state.ApplicationConstants;
import com.sydac.mmrbem.tcms.common.state.DrivingModeEnum;
import com.sydac.mmrbem.tcms.common.state.OperatingModeEnum;
import com.sydac.mmrbem.tcms.fe.base.TCMSFactory;
import com.sydac.mmrbem.tcms.fe.common.Frontend;
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

public class HeaderPanelController extends AbstractTCMSController
{

  @FXML
  private Label screenTitleLbl;

  @FXML
  private Label dateLbl;

  @FXML
  private Label timeLbl;

  @FXML
  private Label trainSpeedLbl;

  @FXML
  private Label speedLimitLbl;

  @FXML
  private Label operatingModeLbl;

  @FXML
  private Label drivingModeLbl;

  @FXML
  private Label passengerCountLbl;

  @FXML
  private Label vduSwitchIcon;

  @FXML
  private Label loginIcon;

  @FXML
  private Label vduSettingsIcon;

  private HeaderPanelModel headerPanelModel;

  private ChangeListener<Number> screenTitleListener;

  private ChangeListener<Number> cctvScreenTitleListener;

  private ChangeListener<Number> speedLimitListener;

  private ChangeListener<Number> trainSpeedListener;

  private ChangeListener<String> dateLabelListener;

  private ChangeListener<String> timeLabelListener;

  private ChangeListener<Number> operationModeListener;

  private ChangeListener<Number> drivingModeListener;

  private ChangeListener<Number> passengerCountListener;

  private FooterPanelModel footerPanelModel;

  private ChangeListener<Number> popupIdListener;

  private int currentPopupId = 0;

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

    screenTitleListener = (observable, oldVal, newVal) -> updateScreenTitle((int)newVal);
    headerPanelModel.getCurrentScreenId().addListener(screenTitleListener);

    cctvScreenTitleListener = (observable, oldVal, newVal) -> updateCctvScreenTitle((int)newVal);
    headerPanelModel.getCurrentCctvScreenId().addListener(cctvScreenTitleListener);

    speedLimitListener = (observable, oldVal, newVal) -> updateSpeedLimit((double)newVal);
    headerPanelModel.getSpeedLimit().addListener(speedLimitListener);

    trainSpeedListener = (observable, oldVal, newVal) -> updateTrainSpeed((double)newVal);
    headerPanelModel.getTrainSpeed().addListener(trainSpeedListener);

    passengerCountListener = (observable, oldVal, newVal) -> updatePassengerCount((int)newVal);
    headerPanelModel.getPassengerCount().addListener(passengerCountListener);

    operationModeListener = (observable, oldVal, newVal) -> updateOperatingMode((int)newVal);
    headerPanelModel.getOperatingMode().addListener(operationModeListener);

    drivingModeListener = (observable, oldVal, newVal) -> updateDrivingMode((int)newVal);
    headerPanelModel.getDrivingMode().addListener(drivingModeListener);

    popupIdListener = ((observable, oldVal, newVal) -> currentPopupId = (Integer)newVal);
    footerPanelModel.getCurrentPopupId().addListener(popupIdListener);

    updateDateLabel(this.headerPanelModel.getCurrentDate().get());
    updateTimeLabel(this.headerPanelModel.getCurrentTime().get());
    updateScreenTitle(headerPanelModel.getCurrentScreenId().get());
    updateOperatingMode(headerPanelModel.getOperatingMode().get());
    updateDrivingMode(headerPanelModel.getDrivingMode().get());
    updateSpeedLimit(headerPanelModel.getSpeedLimit().get());
    updateTrainSpeed(headerPanelModel.getTrainSpeed().get());
    updatePassengerCount(headerPanelModel.getPassengerCount().get());

    currentPopupId = footerPanelModel.getCurrentPopupId().get();
  }

  private void updateDateLabel(String newVal)
  {
    this.dateLbl.setText(newVal);
  }

  private void updateTimeLabel(String newVal)
  {
    this.timeLbl.setText(newVal);
  }

  private void updateScreenTitle(int screenId)
  {
    if (frontend == Frontend.TCMS)
    {
      screenTitleLbl.setText(ScreenId.valueOf(screenId).getScreenTitle());
    }
  }

  private void updateCctvScreenTitle(int screenId)
  {
    if (frontend == Frontend.CCTV)
    {
      screenTitleLbl.setText(ScreenId.valueOf(screenId).getScreenTitle());
    }
  }

  private void updateSpeedLimit(double speedLimit)
  {
    speedLimitLbl.setText(String.valueOf(((Double)Math.abs(speedLimit)).intValue()));
  }

  private void updateTrainSpeed(double trainSpeed)
  {
    trainSpeedLbl.setText(String.valueOf(((Double)Math.abs(trainSpeed)).intValue()));
  }

  private void updatePassengerCount(int passengerCount)
  {
    passengerCountLbl.setText(String.valueOf(passengerCount));
  }

  private void updateOperatingMode(int opMode)
  {
    OperatingModeEnum operatingMode = OperatingModeEnum.valueOf(opMode);
    operatingModeLbl.setText(operatingMode.getText());
  }

  private void updateDrivingMode(int driveMode)
  {
    drivingModeLbl.setText(DrivingModeEnum.OFF.getText());
    DrivingModeEnum drivingMode = DrivingModeEnum.valueOf(driveMode);
    drivingModeLbl.setText(drivingMode.getText());
  }

  @Override
  public void detachListeners()
  {
    this.headerPanelModel.getCurrentDate().removeListener(dateLabelListener);
    this.headerPanelModel.getCurrentTime().removeListener(timeLabelListener);
    headerPanelModel.getCurrentScreenId().removeListener(screenTitleListener);
    headerPanelModel.getOperatingMode().removeListener(operationModeListener);
    headerPanelModel.getDrivingMode().removeListener(drivingModeListener);
    headerPanelModel.getTrainSpeed().removeListener(trainSpeedListener);
    headerPanelModel.getSpeedLimit().removeListener(speedLimitListener);
    headerPanelModel.getPassengerCount().removeListener(passengerCountListener);
    footerPanelModel.getCurrentPopupId().removeListener(popupIdListener);
  }

  @FXML
  void onVduSwitchMouseClicked(MouseEvent event)
  {
    if (!ApplicationConstants.IS_TOUCH_ENABLED)
    {
      updatePopupScreen(ScreenId.VDU_SELECTION_POPUP);
    }
  }

  @FXML
  void onVduSwitchTouchPressed(TouchEvent event)
  {
    if (ApplicationConstants.IS_TOUCH_ENABLED)
    {
      updatePopupScreen(ScreenId.VDU_SELECTION_POPUP);
    }
  }

  @FXML
  void onLoginIconMouseClicked(MouseEvent event)
  {
    if (!ApplicationConstants.IS_TOUCH_ENABLED)
    {
      updatePopupScreen(ScreenId.LOGIN_PANEL_POPUP);
    }
  }

  @FXML
  void onLoginIconTouchPressed(TouchEvent event)
  {
    if (ApplicationConstants.IS_TOUCH_ENABLED)
    {
      updatePopupScreen(ScreenId.LOGIN_PANEL_POPUP);
    }
  }

  @FXML
  void onVduSettingsMouseClicked(MouseEvent event)
  {
    if (!ApplicationConstants.IS_TOUCH_ENABLED)
    {
      updatePopupScreen(ScreenId.VDU_SETTINGS_POPUP);
    }
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
