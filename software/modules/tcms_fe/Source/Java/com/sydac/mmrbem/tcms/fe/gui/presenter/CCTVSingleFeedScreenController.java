/*
 * ==================================================================
 *
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *
 * ==================================================================
 */
package com.sydac.mmrbem.tcms.fe.gui.presenter;

import com.sydac.gui.control.NodePseudoClassProperty;
import com.sydac.mmrbem.salooncctv.common.protos.SaloonCCTVProtos.CameraViewButtons.AssociatedView;
import com.sydac.mmrbem.tcms.common.state.ApplicationConstants;
import com.sydac.mmrbem.tcms.fe.base.TCMSFactory;
import com.sydac.mmrbem.tcms.fe.gui.AbstractTCMSController;
import com.sydac.mmrbem.tcms.fe.gui.binder.CCTVFooterPanelBinder;
import com.sydac.mmrbem.tcms.fe.gui.model.CCTVFooterPanelModel;
import com.sydac.mmrbem.tcms.fe.gui.model.DayDateTimeModel;
import com.sydac.mmrbem.tcms.fe.gui.state.AutoRotationStatus;
import com.sydac.mmrbem.tcms.fe.gui.state.Days;

import javafx.beans.value.ChangeListener;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.input.MouseEvent;
import javafx.scene.input.TouchEvent;
import javafx.scene.layout.AnchorPane;
import javafx.scene.layout.GridPane;

public class CCTVSingleFeedScreenController extends AbstractTCMSController
{
  @FXML
  private GridPane footerGrid;

  @FXML
  private GridPane settingsGrid;

  @FXML
  private Label dateLbl;

  @FXML
  private Label dayLbl;

  @FXML
  private Label timeLbl;

  @FXML
  private Label trainIdLbl;

  @FXML
  private Label cameraIdLbl;

  @FXML
  private Label cLbl;

  @FXML
  private Label nLbl;

  @FXML
  private Label noActiveAlarmLbl;

  @FXML
  private Label noActiveAlarmIconLbl;

  @FXML
  private Button previousVehicleBtn;

  @FXML
  private Button nextVehicleBtn;

  @FXML
  private AnchorPane singleFeedView;

  @FXML
  private GridPane singleFeedViewGrid;

  private ChangeListener<String> dayListener;

  private ChangeListener<String> dateListener;

  private ChangeListener<String> timeListener;

  private final DayDateTimeModel dayDateTimeModel = new DayDateTimeModel();

  private ChangeListener<Number> alarmModeListener;

  private ChangeListener<Number> alarmTypeListener;

  private ChangeListener<String> trainNameLabelListener;

  private ChangeListener<String> lineDirectionListener;

  private ChangeListener<String> singleFeedCameraNameListener;

  private ChangeListener<String> currentLocationListener;

  private ChangeListener<String> nextLocationListener;

  private ChangeListener<Number> cctvDisplayHangedFaultListener;

  private ChangeListener<Number> detrainDoorOpenListener;

  private ChangeListener<Boolean> settingsScreenActiveListener;

  private NodePseudoClassProperty singleFeedGridNodePseudoClassProperty;

  private CCTVFooterPanelModel cctvFooterPanelModel;

  private boolean isCCTVDisplayHangFaultActive;

  @Override
  public void detachListeners()
  {
    dayDateTimeModel.getDate().removeListener(dateListener);
    dayDateTimeModel.getDay().removeListener(dayListener);
    dayDateTimeModel.getTime().removeListener(timeListener);
    cctvFooterPanelModel.getAlarmModeProperty().removeListener(alarmModeListener);
    cctvFooterPanelModel.getAlarmTypeActive().removeListener(alarmTypeListener);
    cctvFooterPanelModel.getTrainId().removeListener(trainNameLabelListener);
    cctvFooterPanelModel.getCurrentLocation().removeListener(currentLocationListener);
    cctvFooterPanelModel.getNextLocation().removeListener(nextLocationListener);
    cctvFooterPanelModel.getSingleFeedViewLable().removeListener(singleFeedCameraNameListener);
    cctvFooterPanelModel.getLineDetail().removeListener(lineDirectionListener);
    cctvFooterPanelModel.getCctvDisplayHangedFault().removeListener(cctvDisplayHangedFaultListener);
    cctvFooterPanelModel.getDetrainmentDoorFault().removeListener(detrainDoorOpenListener);
  }

  @Override
  public void initializeImpl()
  {
    cctvFooterPanelModel = new CCTVFooterPanelModel(scenarioCarIndex);
    tcmsScreenBinders.add(new CCTVFooterPanelBinder(cctvFooterPanelModel));

    dayListener = (observable, oldVal, newVal) -> updateDay(newVal);
    dayDateTimeModel.getDay().addListener(dayListener);

    dateListener = (observable, oldVal, newVal) -> updateDate(newVal);
    dayDateTimeModel.getfeedDate().addListener(dateListener);

    timeListener = (observable, oldVal, newVal) -> updateTime(newVal);
    dayDateTimeModel.getTime().addListener(timeListener);

    cctvDisplayHangedFaultListener = (observable, oldVal,
        newVal) -> updateDisplayHangedFaultStatus((int)newVal);
    cctvFooterPanelModel.getCctvDisplayHangedFault().addListener(cctvDisplayHangedFaultListener);

    singleFeedGridNodePseudoClassProperty = new NodePseudoClassProperty(singleFeedViewGrid);

    settingsScreenActiveListener = (observable, oldValue,
        newVal) -> updateSettingPopGrd(newVal.booleanValue());
    CCTVFooterPanelModel.getSettingsPopupActive().addListener(settingsScreenActiveListener);
    CCTVFooterPanelModel.setSettingsPopupActive(false);

    detrainDoorOpenListener = (observable, oldValue,
        newValue) -> updateDetrainmentDoorImage(newValue.intValue());
    cctvFooterPanelModel.getDetrainmentDoorFault().addListener(detrainDoorOpenListener);
    updateDetrainmentDoorImage(cctvFooterPanelModel.getDetrainmentDoorFault().get());

    trainNameLabelListener = (observable, oldVal, newVal) -> updateTrainNameLabel();
    cctvFooterPanelModel.getTrainId().addListener(trainNameLabelListener);

    lineDirectionListener = (observable, oldVal, newVal) -> updateTrainNameLabel();
    cctvFooterPanelModel.getLineDetail().addListener(lineDirectionListener);

    currentLocationListener = (observable, oldVal, newVal) -> updateCurrentLocationLabel(newVal);
    cctvFooterPanelModel.getCurrentLocation().addListener(currentLocationListener);

    nextLocationListener = (observable, oldVal, newVal) -> updateNextLocationLabel(newVal);
    cctvFooterPanelModel.getNextLocation().addListener(nextLocationListener);

    singleFeedCameraNameListener = (observable, oldVal, newVal) -> updateSingleFeedCameraName(newVal);
    cctvFooterPanelModel.getSingleFeedViewLable().addListener(singleFeedCameraNameListener);

    updateDisplayHangedFaultStatus(cctvFooterPanelModel.getCctvDisplayHangedFault().get());
  }

  private void updateSettingPopGrd(boolean booleanValue)
  {
    if (cctvFooterPanelModel.getCctvDisplayHangedFault().get() != 1)
    {
      settingsGrid.setVisible(booleanValue);
    }
  }

  private void updateDetrainmentDoorImage(int detrainmentDoorOpen)
  {
    if (detrainmentDoorOpen == AssociatedView.SINGLE_FEED_VIEW_VALUE
        && (cctvFooterPanelModel.getSingleFeedViewLable().get().equals(ApplicationConstants.DMC1_DCAM)
            || cctvFooterPanelModel.getSingleFeedViewLable().get().equals(ApplicationConstants.DMC6_DCAM)
            || cctvFooterPanelModel.getSingleFeedViewLable().get().equals(ApplicationConstants.DMC8_DCAM)))
    {
      singleFeedGridNodePseudoClassProperty.set(ApplicationConstants.DETRANMENT_DOOR_OPEN_CSS);
    }
    else
    {
      singleFeedGridNodePseudoClassProperty.set(ApplicationConstants.TRANSPARENT_CSS);
    }
  }

  private void updateDisplayHangedFaultStatus(int faultActive)
  {
    isCCTVDisplayHangFaultActive = (faultActive == 1);
    if (!isCCTVDisplayHangFaultActive)
    {
      updateTrainNameLabel();
      updateCurrentLocationLabel(cctvFooterPanelModel.getCurrentLocation().get());
      updateNextLocationLabel(cctvFooterPanelModel.getNextLocation().get());
      updateSingleFeedCameraName(cctvFooterPanelModel.getSingleFeedViewLable().get());
      updateSettingPopGrd(CCTVFooterPanelModel.getSettingsPopupActive().get());
    }
  }

  private void updateTrainNameLabel()
  {
    String trainName = "Car" + cctvFooterPanelModel.getTrainId().get() + "/" //$NON-NLS-1$ //$NON-NLS-2$
        + (cctvFooterPanelModel.getLineDetail().get());
    trainIdLbl.setText(trainName);
  }

  private void updateSingleFeedCameraName(String cameraName)
  {
    updateDetrainmentDoorImage(cctvFooterPanelModel.getDetrainmentDoorFault().get());
    cameraIdLbl.setText(cameraName);
  }

  private void updateCurrentLocationLabel(String cLocationName)
  {
    cLbl.setText(ApplicationConstants.C_LOCATION_LABEL.concat(cLocationName));
  }

  private void updateNextLocationLabel(String nLocationName)
  {
    nLbl.setText(ApplicationConstants.N_LOCATION_LABEL.concat(nLocationName));
  }

  private void updateTime(String time)
  {
    if (!isCCTVDisplayHangFaultActive)
    {
      timeLbl.setText(time);
    }
  }

  private void updateDate(String date)
  {
    if (!isCCTVDisplayHangFaultActive)
    {
      dateLbl.setText(date);
    }
  }

  private void updateDay(String day)
  {
    if (!isCCTVDisplayHangFaultActive)
    {
      dayLbl.setText(Days.getDay(day).getText());
    }
  }

  /**
   * @param event
   *          unused
   */
  @FXML
  private void onPreviousVehicleButtonAction(ActionEvent event)
  {
    if (!isCCTVDisplayHangFaultActive)
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendCCTVPreviousVehicleRequest(1);
    }
  }

  /**
   * @param event
   *          unused
   */
  @FXML
  private void onNextVehicleButtonAction(ActionEvent event)
  {
    if (!isCCTVDisplayHangFaultActive)
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendCCtVNextVehicleRequest(1);
    }
  }

  /**
   * @param event
   *          unused
   */
  @FXML
  private void onSingleFeedAreaTouchPressed(TouchEvent event)
  {
    if (AutoRotationStatus.getStatusOf(cctvFooterPanelModel.getAutoRotationStatusProperty().get())
        .equals(AutoRotationStatus.ON) && !isCCTVDisplayHangFaultActive)
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendCCTVAutoRotationRequest(AutoRotationStatus.OFF);
    }
  }

  /**
   * @param event
   *          unused
   */
  @FXML
  private void onSingleFeedAreaMouseClicked(MouseEvent event)
  {
    if (AutoRotationStatus.getStatusOf(cctvFooterPanelModel.getAutoRotationStatusProperty().get())
        .equals(AutoRotationStatus.ON) && !isCCTVDisplayHangFaultActive)
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendCCTVAutoRotationRequest(AutoRotationStatus.OFF);
    }
  }
}
