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
import com.sydac.mmrbem.tcms.common.ScreenId;
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

public class CCTVFourFeedScreenController extends AbstractTCMSController
{

  private static final int NO_ALARM = 0;

  private static final int INACTIVE = 0;

  private static final int NO_ACTIVE_ALARM = 0;

  @FXML
  private Label dateLbl1;

  @FXML
  private Label dateLbl2;

  @FXML
  private Label dateLbl3;

  @FXML
  private Label dateLbl4;

  @FXML
  private Label dayLbl1;

  @FXML
  private Label dayLbl2;

  @FXML
  private Label dayLbl3;

  @FXML
  private Label dayLbl4;

  @FXML
  private Label timeLbl1;

  @FXML
  private Label timeLbl2;

  @FXML
  private Label timeLbl3;

  @FXML
  private Label timeLbl4;

  @FXML
  private Label trainIdLbl1;

  @FXML
  private Label trainIdLbl2;

  @FXML
  private Label trainIdLbl3;

  @FXML
  private Label trainIdLbl4;

  @FXML
  private Label camIdLbl1;

  @FXML
  private Label camIdLbl2;

  @FXML
  private Label camIdLbl3;

  @FXML
  private Label camIdLbl4;

  @FXML
  private Label cLbl1;

  @FXML
  private Label cLbl2;

  @FXML
  private Label cLbl3;

  @FXML
  private Label cLbl4;

  @FXML
  private Label nLbl1;

  @FXML
  private Label nLbl2;

  @FXML
  private Label nLbl3;

  @FXML
  private Label nLbl4;

  @FXML
  private Label noActiveAlarmIconLbl;

  @FXML
  private Label noActiveAlarmLbl;

  @FXML
  private Button previousVehicleBtn;

  @FXML
  private Button nextVehicleBtn;

  @FXML
  private AnchorPane firstFeedView;

  @FXML
  private AnchorPane secondFeedView;

  @FXML
  private AnchorPane thirdFeedView;

  @FXML
  private AnchorPane fourthFeedView;

  @FXML
  private GridPane firstFeedViewGrid;

  @FXML
  private GridPane secondFeedViewGrid;

  @FXML
  private GridPane thirdFeedViewGrid;

  @FXML
  private GridPane fourthFeedViewGrid;

  @FXML
  private GridPane eventGrid;

  @FXML
  private GridPane settingsGrid;

  private ChangeListener<String> dayListener;

  private ChangeListener<String> dateListener;

  private ChangeListener<String> timeListener;

  private ChangeListener<Number> alarmModeListener;

  private ChangeListener<Boolean> alarmTypeListener;

  private ChangeListener<String> firstFeedCameraNameListener;

  private ChangeListener<String> secondFeedCameraNameListener;

  private ChangeListener<String> thirdFeedCameraNameListener;

  private ChangeListener<String> fourthFeedCameraNameListener;

  private ChangeListener<String> trainNameLabelListener;

  private ChangeListener<String> lineDirectionListener;

  private ChangeListener<String> currentLocationListener;

  private ChangeListener<String> nextLocationListener;

  private ChangeListener<Number> firstFeedCameraIdListener;

  private ChangeListener<Number> secondFeedCameraIdListener;

  private ChangeListener<Number> thirdFeedCameraIdListener;

  private ChangeListener<Number> fourthFeedCameraIdListener;

  private ChangeListener<Number> firstFeedCarIndexListener;

  private ChangeListener<Number> secondFeedCarIndexListener;

  private ChangeListener<Number> thirdFeedCarIndexListener;

  private ChangeListener<Number> fourthFeedCarIndexListener;

  private ChangeListener<Number> cctvDisplayHangedFaultListener;

  private ChangeListener<Boolean> settingsScreenActiveListener;

  private NodePseudoClassProperty firstFeedNodePseudoClassProperty;

  private NodePseudoClassProperty secondFeedNodePseudoClassProperty;

  private NodePseudoClassProperty thirdFeedNodePseudoClassProperty;

  private NodePseudoClassProperty fourthFeedNodePseudoClassProperty;

  private final DayDateTimeModel dayDateTimeModel = new DayDateTimeModel();

  private CCTVFooterPanelModel cctvFooterPanelModel;

  private Integer firstFeedSelectedCameraId;

  private Integer secondFeedSelectedCameraId;

  private Integer thirdFeedSelectedCameraId;

  private Integer fourthFeedSelectedCameraId;

  private Integer firstFeedSelectedCarId;

  private Integer secondFeedSelectedCarId;

  private Integer thirdFeedSelectedCarId;

  private Integer fourthFeedSelectedCarId;

  private boolean isCCTVDisplayHangFaultActive;
 
  private ChangeListener<Number> selectedVehicleIndexListener;
  
  private ChangeListener<Number> detrailmentCameraIdListener;

  private int count;

  @Override
  public void detachListeners()
  {
    dayDateTimeModel.getDate().removeListener(dateListener);
    dayDateTimeModel.getDay().removeListener(dayListener);
    dayDateTimeModel.getTime().removeListener(timeListener);
    cctvFooterPanelModel.getAlarmModeProperty().removeListener(alarmModeListener);
    cctvFooterPanelModel.getFirstFeedViewLable().removeListener(firstFeedCameraNameListener);
    cctvFooterPanelModel.getSecondFeedViewLable().removeListener(secondFeedCameraNameListener);
    cctvFooterPanelModel.getThirdFeedViewLable().removeListener(thirdFeedCameraNameListener);
    cctvFooterPanelModel.getFourthFeedViewLable().removeListener(fourthFeedCameraNameListener);
    cctvFooterPanelModel.getTrainId().removeListener(trainNameLabelListener);
    cctvFooterPanelModel.getCurrentLocation().removeListener(currentLocationListener);
    cctvFooterPanelModel.getNextLocation().removeListener(nextLocationListener);
    cctvFooterPanelModel.getFirstFeedCameraId().removeListener(firstFeedCameraIdListener);
    cctvFooterPanelModel.getFirstFeedCameraId().removeListener(secondFeedCameraIdListener);
    cctvFooterPanelModel.getFirstFeedCameraId().removeListener(thirdFeedCameraIdListener);
    cctvFooterPanelModel.getFirstFeedCameraId().removeListener(fourthFeedCameraIdListener);
    cctvFooterPanelModel.getFirstFeedCameraId().removeListener(firstFeedCarIndexListener);
    cctvFooterPanelModel.getFirstFeedCameraId().removeListener(secondFeedCarIndexListener);
    cctvFooterPanelModel.getFirstFeedCameraId().removeListener(thirdFeedCarIndexListener);
    cctvFooterPanelModel.getFirstFeedCameraId().removeListener(fourthFeedCarIndexListener);
    cctvFooterPanelModel.getLineDetail().removeListener(lineDirectionListener);
    CCTVFooterPanelModel.getEventSwitchButtonState().removeListener(alarmTypeListener);
    cctvFooterPanelModel.getCctvDisplayHangedFault().removeListener(cctvDisplayHangedFaultListener);
    CCTVFooterPanelModel.getSettingsPopupActive().removeListener(settingsScreenActiveListener);
   
    cctvFooterPanelModel.getSelectedVehicleIndexProperty().removeListener(selectedVehicleIndexListener);
    cctvFooterPanelModel.getDetraimentCameraId().removeListener(detrailmentCameraIdListener);
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

    firstFeedNodePseudoClassProperty = new NodePseudoClassProperty(firstFeedViewGrid);
    secondFeedNodePseudoClassProperty = new NodePseudoClassProperty(secondFeedViewGrid);
    thirdFeedNodePseudoClassProperty = new NodePseudoClassProperty(thirdFeedViewGrid);
    fourthFeedNodePseudoClassProperty = new NodePseudoClassProperty(fourthFeedViewGrid);

    cctvDisplayHangedFaultListener = (observable, oldVal,
        newVal) -> updateDisplayHangedFaultStatus((int)newVal);
    cctvFooterPanelModel.getCctvDisplayHangedFault().addListener(cctvDisplayHangedFaultListener);

    alarmTypeListener = (observable, oldVal, newVal) -> checkUpdateFaultsPopup(newVal.booleanValue());
    CCTVFooterPanelModel.getEventSwitchButtonState().addListener(alarmTypeListener);

    settingsScreenActiveListener = (observable, oldValue,
        newVal) -> updateSettingPopGrd(newVal.booleanValue());
    CCTVFooterPanelModel.getSettingsPopupActive().addListener(settingsScreenActiveListener);
    CCTVFooterPanelModel.setSettingsPopupActive(false);

    alarmModeListener = (observable, oldValue, newValue) -> updateEventPanelGrid(newValue.intValue());
    cctvFooterPanelModel.getAlarmModeProperty().addListener(alarmModeListener);

    firstFeedCameraNameListener = (observable, oldVal, newVal) -> updateFeedCamName(camIdLbl1, newVal);
    cctvFooterPanelModel.getFirstFeedViewLable().addListener(firstFeedCameraNameListener);

    secondFeedCameraNameListener = (observable, oldVal, newVal) -> updateFeedCamName(camIdLbl2, newVal);
    cctvFooterPanelModel.getSecondFeedViewLable().addListener(secondFeedCameraNameListener);

    thirdFeedCameraNameListener = (observable, oldVal, newVal) -> updateFeedCamName(camIdLbl3, newVal);
    cctvFooterPanelModel.getThirdFeedViewLable().addListener(thirdFeedCameraNameListener);

    fourthFeedCameraNameListener = (observable, oldVal, newVal) -> updateFeedCamName(camIdLbl4, newVal);
    cctvFooterPanelModel.getFourthFeedViewLable().addListener(fourthFeedCameraNameListener);

    trainNameLabelListener = (observable, oldVal, newVal) -> updateTrainNameLabel();
    cctvFooterPanelModel.getTrainId().addListener(trainNameLabelListener);

    lineDirectionListener = (observable, oldVal, newVal) -> updateTrainNameLabel();
    cctvFooterPanelModel.getLineDetail().addListener(lineDirectionListener);

    currentLocationListener = (observable, oldVal, newVal) -> updateCurrentLocationLabel(newVal);
    cctvFooterPanelModel.getCurrentLocation().addListener(currentLocationListener);

    nextLocationListener = (observable, oldVal, newVal) -> updateNextLocationLabel(newVal);
    cctvFooterPanelModel.getNextLocation().addListener(nextLocationListener);

    firstFeedCameraIdListener = (observable, oldVal, newVal) -> firstFeedSelectedCameraId = newVal.intValue();
    cctvFooterPanelModel.getFirstFeedCameraId().addListener(firstFeedCameraIdListener);
    firstFeedSelectedCameraId = cctvFooterPanelModel.getFirstFeedCameraId().get();

    secondFeedCameraIdListener = (observable, oldVal,
        newVal) -> secondFeedSelectedCameraId = newVal.intValue();
    cctvFooterPanelModel.getSecondFeedCameraId().addListener(secondFeedCameraIdListener);
    secondFeedSelectedCameraId = cctvFooterPanelModel.getSecondFeedCameraId().get();

    thirdFeedCameraIdListener = (observable, oldVal, newVal) -> thirdFeedSelectedCameraId = newVal.intValue();
    cctvFooterPanelModel.getThirdFeedCameraId().addListener(thirdFeedCameraIdListener);
    thirdFeedSelectedCameraId = cctvFooterPanelModel.getThirdFeedCameraId().get();

    fourthFeedCameraIdListener = (observable, oldVal,
        newVal) -> fourthFeedSelectedCameraId = newVal.intValue();
    cctvFooterPanelModel.getFourthFeedCameraId().addListener(fourthFeedCameraIdListener);
    fourthFeedSelectedCameraId = cctvFooterPanelModel.getFourthFeedCameraId().get();

    firstFeedCarIndexListener = (observable, oldVal, newVal) -> firstFeedSelectedCarId = newVal.intValue();
    cctvFooterPanelModel.getFirstFeedCarIndex().addListener(firstFeedCarIndexListener);
    firstFeedSelectedCarId = cctvFooterPanelModel.getFirstFeedCarIndex().get();

    secondFeedCarIndexListener = (observable, oldVal, newVal) -> secondFeedSelectedCarId = newVal.intValue();
    cctvFooterPanelModel.getSecondFeedCarIndex().addListener(secondFeedCarIndexListener);
    secondFeedSelectedCarId = cctvFooterPanelModel.getSecondFeedCarIndex().get();

    thirdFeedCarIndexListener = (observable, oldVal, newVal) -> thirdFeedSelectedCarId = newVal.intValue();
    cctvFooterPanelModel.getThirdFeedCarIndex().addListener(thirdFeedCarIndexListener);
    thirdFeedSelectedCarId = cctvFooterPanelModel.getThirdFeedCarIndex().get();

    fourthFeedCarIndexListener = (observable, oldVal, newVal) -> fourthFeedSelectedCarId = newVal.intValue();
    cctvFooterPanelModel.getFourthFeedCarIndex().addListener(fourthFeedCarIndexListener);
    fourthFeedSelectedCarId = cctvFooterPanelModel.getFourthFeedCarIndex().get();

   

    selectedVehicleIndexListener = (observable, oldVal, newVal) -> updatePreviousButtonState();
    cctvFooterPanelModel.getSelectedVehicleIndexProperty().addListener(selectedVehicleIndexListener);
    
    detrailmentCameraIdListener = (observable, oldVal, newVal) -> {
      
    };
    cctvFooterPanelModel.getDetraimentCameraId().addListener(detrailmentCameraIdListener);

    checkUpdateFaultsPopup(false);
    updateDisplayHangedFaultStatus(cctvFooterPanelModel.getCctvDisplayHangedFault().get());

  }

  private void updatePreviousButtonState()
  {
    int noOfCars = cctvFooterPanelModel.getNumberOfCars().get();

    if (noOfCars == ApplicationConstants.SIX_CAR_CONFIG)
    {
      if (cctvFooterPanelModel.getSelectedVehicleIndexProperty().get() == 1
          || cctvFooterPanelModel.getSelectedVehicleIndexProperty().get() == 6)
      {
        previousVehicleBtn.setVisible(Boolean.FALSE);
      }
      else
      {
        previousVehicleBtn.setVisible(Boolean.TRUE);
      }

    }
    else
    {
      if (cctvFooterPanelModel.getSelectedVehicleIndexProperty().get() == 1
          || cctvFooterPanelModel.getSelectedVehicleIndexProperty().get() == 8)
      {
        previousVehicleBtn.setVisible(Boolean.FALSE);
      }
      else
      {
        previousVehicleBtn.setVisible(Boolean.TRUE);
      }
    }

  }

  private void updateSettingPopGrd(boolean booleanValue)
  {
    if (cctvFooterPanelModel.getCctvDisplayHangedFault().get() != 1)
    {
      settingsGrid.setVisible(booleanValue);
    }
  }

  private void updateEventPanelGrid(int active)
  {
    if (cctvFooterPanelModel.getCctvDisplayHangedFault().get() != 1)
    {
      eventGrid.setVisible(active == ApplicationConstants.ACTIVE);
    }
  }

  private void updateDetrainmentDoorImage(int doorOpen, Label feedLabel)
  {
    if (feedLabel == camIdLbl1)
    {
      if (doorOpen == AssociatedView.FIRST_VIEW_VALUE
          && (cctvFooterPanelModel.getFirstFeedViewLable().get().equals(ApplicationConstants.DMC1_DCAM)
              || cctvFooterPanelModel.getFirstFeedViewLable().get().equals(ApplicationConstants.DMC6_DCAM)
              || cctvFooterPanelModel.getFirstFeedViewLable().get().equals(ApplicationConstants.DMC8_DCAM)))
      {
        firstFeedNodePseudoClassProperty.set(ApplicationConstants.DETRANMENT_DOOR_OPEN_CSS);
      }
      else
      {
        firstFeedNodePseudoClassProperty.set(ApplicationConstants.TRANSPARENT_CSS);
      }
    }
    else if (feedLabel == camIdLbl2)
    {
      if (doorOpen == AssociatedView.SECOND_VIEW_VALUE
          && (cctvFooterPanelModel.getSecondFeedViewLable().get().equals(ApplicationConstants.DMC1_DCAM)
              || cctvFooterPanelModel.getSecondFeedViewLable().get().equals(ApplicationConstants.DMC6_DCAM)
              || cctvFooterPanelModel.getSecondFeedViewLable().get().equals(ApplicationConstants.DMC8_DCAM)))
      {
        secondFeedNodePseudoClassProperty.set(ApplicationConstants.DETRANMENT_DOOR_OPEN_CSS);
      }
      else
      {
        secondFeedNodePseudoClassProperty.set(ApplicationConstants.TRANSPARENT_CSS);
      }
    }
    else if (feedLabel == camIdLbl3)
    {
      if (doorOpen == AssociatedView.THIRD_VIEW_VALUE && (cctvFooterPanelModel.getThirdFeedAlarmViewLable()
          .get().equals(ApplicationConstants.DMC1_DCAM)
          || cctvFooterPanelModel.getThirdFeedAlarmViewLable().get().equals(ApplicationConstants.DMC6_DCAM)
          || cctvFooterPanelModel.getThirdFeedAlarmViewLable().get().equals(ApplicationConstants.DMC8_DCAM)))
      {
        thirdFeedNodePseudoClassProperty.set(ApplicationConstants.DETRANMENT_DOOR_OPEN_CSS);
      }
      else
      {
        thirdFeedNodePseudoClassProperty.set(ApplicationConstants.TRANSPARENT_CSS);
      }
    }
    else if (feedLabel == camIdLbl4)
    {
      if (doorOpen == AssociatedView.FOURTH_VIEW_VALUE
          && (cctvFooterPanelModel.getFourthFeedViewLable().get().equals(ApplicationConstants.DMC1_DCAM)
              || cctvFooterPanelModel.getFourthFeedViewLable().get().equals(ApplicationConstants.DMC6_DCAM)
              || cctvFooterPanelModel.getFourthFeedViewLable().get().equals(ApplicationConstants.DMC8_DCAM)))
      {
        fourthFeedNodePseudoClassProperty.set(ApplicationConstants.DETRANMENT_DOOR_OPEN_CSS);
      }
      else
      {
        fourthFeedNodePseudoClassProperty.set(ApplicationConstants.TRANSPARENT_CSS);
      }
    }
  }

  private void updateDisplayHangedFaultStatus(int faultActive)
  {
    isCCTVDisplayHangFaultActive = (faultActive == 1);
    if (!isCCTVDisplayHangFaultActive)
    {
      updateFeedCamName(camIdLbl1, cctvFooterPanelModel.getFirstFeedViewLable().get());
      updateFeedCamName(camIdLbl2, cctvFooterPanelModel.getSecondFeedViewLable().get());
      updateFeedCamName(camIdLbl3, cctvFooterPanelModel.getThirdFeedViewLable().get());
      updateFeedCamName(camIdLbl4, cctvFooterPanelModel.getFourthFeedViewLable().get());
      updateTrainNameLabel();
      updateCurrentLocationLabel(cctvFooterPanelModel.getCurrentLocation().get());
      updateNextLocationLabel(cctvFooterPanelModel.getNextLocation().get());
      checkUpdateFaultsPopup(CCTVFooterPanelModel.getEventSwitchButtonState().get());
      updateEventPanelGrid(cctvFooterPanelModel.getAlarmModeProperty().get());
      updateSettingPopGrd(CCTVFooterPanelModel.getSettingsPopupActive().get());
    }
  }

  private void updateFeedCamName(Label feedLabel, String cameraName)
  {
    updateDetrainmentDoorImage(cctvFooterPanelModel.getDetrainmentDoorFault().get(), feedLabel);
    feedLabel.setText(cameraName);
  }

  private void updateTrainNameLabel()
  {
    String trainName = "Car" + cctvFooterPanelModel.getTrainId().get() + "/" //$NON-NLS-1$ //$NON-NLS-2$
        + (cctvFooterPanelModel.getLineDetail().get());
    trainIdLbl1.setText(trainName);
    trainIdLbl2.setText(trainName);
    trainIdLbl3.setText(trainName);
    trainIdLbl4.setText(trainName);
  }

  private void updateCurrentLocationLabel(String cLocationName)
  {
    cLbl1.setText(ApplicationConstants.C_LOCATION_LABEL.concat(cLocationName));
    cLbl2.setText(ApplicationConstants.C_LOCATION_LABEL.concat(cLocationName));
    cLbl3.setText(ApplicationConstants.C_LOCATION_LABEL.concat(cLocationName));
    cLbl4.setText(ApplicationConstants.C_LOCATION_LABEL.concat(cLocationName));
  }

  private void updateNextLocationLabel(String nLocationName)
  {
    nLbl1.setText(ApplicationConstants.N_LOCATION_LABEL.concat(nLocationName));
    nLbl2.setText(ApplicationConstants.N_LOCATION_LABEL.concat(nLocationName));
    nLbl3.setText(ApplicationConstants.N_LOCATION_LABEL.concat(nLocationName));
    nLbl4.setText(ApplicationConstants.N_LOCATION_LABEL.concat(nLocationName));
  }

  private void checkUpdateFaultsPopup(boolean isClicked)
  {
    if (isClicked)
    {
      boolean isVisible = cctvFooterPanelModel.getAlarmModeProperty().get() == NO_ALARM
          && cctvFooterPanelModel.getAlarmTypeActive().get() == INACTIVE;
      noActiveAlarmIconLbl.setVisible(isVisible);
      noActiveAlarmLbl.setVisible(isVisible);

    }
    else
    {
      noActiveAlarmIconLbl.setVisible(false);
      noActiveAlarmLbl.setVisible(false);
    }

  }

  private void updateTime(String time)
  {
    if (!isCCTVDisplayHangFaultActive)
    {
      timeLbl1.setText(time);
      timeLbl2.setText(time);
      timeLbl3.setText(time);
      timeLbl4.setText(time);
    }

  }

  private void updateDate(String date)
  {
    if (!isCCTVDisplayHangFaultActive)
    {
      dateLbl1.setText(date);
      dateLbl2.setText(date);
      dateLbl3.setText(date);
      dateLbl4.setText(date);
    }
  }

  private void updateDay(String day)
  {
    if (!isCCTVDisplayHangFaultActive)
    {
      dayLbl1.setText(Days.getDay(day).getText());
      dayLbl2.setText(Days.getDay(day).getText());
      dayLbl3.setText(Days.getDay(day).getText());
      dayLbl4.setText(Days.getDay(day).getText());
    }
  }

  private void firstFeedAction()
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex).onDoubbleClickOnCameraFeed(firstFeedSelectedCarId,
        firstFeedSelectedCameraId, ScreenId.CCTV_SINGLE_FEED_SCREEN, frontend);
  }

  private void secondFeedAction()
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex).onDoubbleClickOnCameraFeed(secondFeedSelectedCarId,
        secondFeedSelectedCameraId, ScreenId.CCTV_SINGLE_FEED_SCREEN, frontend);
  }

  private void thirdFeedAction()
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex).onDoubbleClickOnCameraFeed(thirdFeedSelectedCarId,
        thirdFeedSelectedCameraId, ScreenId.CCTV_SINGLE_FEED_SCREEN, frontend);
  }

  private void fourthFeedAction()
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex).onDoubbleClickOnCameraFeed(fourthFeedSelectedCarId,
        fourthFeedSelectedCameraId, ScreenId.CCTV_SINGLE_FEED_SCREEN, frontend);
  }

  private void onFourFeedAutoRotationAction()
  {
    if (AutoRotationStatus.getStatusOf(cctvFooterPanelModel.getAutoRotationStatusProperty().get())
        .equals(AutoRotationStatus.ON))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendCCTVAutoRotationRequest(AutoRotationStatus.OFF);
    }
  }

  private boolean isDoubleTouchEvent(TouchEvent event)
  {
    return event.getTouchCount() == ApplicationConstants.DOUBLE_CLICK;
  }

  private boolean isDoubleClickEvent(MouseEvent event)
  {
    return event.getClickCount() == ApplicationConstants.DOUBLE_CLICK;
  }

  @FXML
  private void onFirstFeedMouseClicked(MouseEvent event)
  {
    if (isDoubleClickEvent(event) && cctvFooterPanelModel.getAlarmModeProperty().get() == NO_ACTIVE_ALARM
        && !isCCTVDisplayHangFaultActive)
    {
      if (cctvFooterPanelModel.getDetraimentCameraId().get() == 1)
     {
       TCMSFactory.getServiceRequestHandler(scenarioCarIndex).onDoubbleClickOnCameraFeed(
            firstFeedSelectedCarId, 7, ScreenId.CCTV_SINGLE_FEED_SCREEN, frontend);
     }
      else
      {
        firstFeedAction();
      }
    }
  }

  @FXML
  private void onFirstFeedTouchPressed(TouchEvent event)
  {
    if (isDoubleTouchEvent(event) && cctvFooterPanelModel.getAlarmModeProperty().get() == NO_ACTIVE_ALARM
        && !isCCTVDisplayHangFaultActive)
    {
      if (cctvFooterPanelModel.getDetraimentCameraId().get() == 1)
      {
        TCMSFactory.getServiceRequestHandler(scenarioCarIndex).onDoubbleClickOnCameraFeed(
             firstFeedSelectedCarId, 7, ScreenId.CCTV_SINGLE_FEED_SCREEN, frontend);
      }
       else
       {
         firstFeedAction();
       }
    }
  }

  @FXML
  private void onSecondFeedMouseClicked(MouseEvent event)
  {
    if (isDoubleClickEvent(event) && cctvFooterPanelModel.getAlarmModeProperty().get() == NO_ACTIVE_ALARM
        && !isCCTVDisplayHangFaultActive)
    {
      secondFeedAction();
    }
  }

  @FXML
  private void onSecondFeedTouchPressed(TouchEvent event)
  {
    if (isDoubleTouchEvent(event) && cctvFooterPanelModel.getAlarmModeProperty().get() == NO_ACTIVE_ALARM
        && !isCCTVDisplayHangFaultActive)
    {
      secondFeedAction();
    }
  }

  @FXML
  private void onThirdFeedMouseClicked(MouseEvent event)
  {
    if (isDoubleClickEvent(event) && cctvFooterPanelModel.getAlarmModeProperty().get() == NO_ACTIVE_ALARM
        && !isCCTVDisplayHangFaultActive)
    {
      thirdFeedAction();
    }
  }

  @FXML
  private void onThirdFeedTouchPressed(TouchEvent event)
  {
    if (isDoubleTouchEvent(event) && cctvFooterPanelModel.getAlarmModeProperty().get() == NO_ACTIVE_ALARM
        && !isCCTVDisplayHangFaultActive)
    {
      thirdFeedAction();
    }
  }

  @FXML
  private void onFourthFeedMouseClicked(MouseEvent event)
  {
    if (isDoubleClickEvent(event) && cctvFooterPanelModel.getAlarmModeProperty().get() == NO_ACTIVE_ALARM
        && !isCCTVDisplayHangFaultActive)
    {
      fourthFeedAction();
    }
  }

  @FXML
  private void onFourthFeedTouchPressed(TouchEvent event)
  {
    if (isDoubleTouchEvent(event) && cctvFooterPanelModel.getAlarmModeProperty().get() == NO_ACTIVE_ALARM
        && !isCCTVDisplayHangFaultActive)
    {
      fourthFeedAction();
    }
  }

  /**
   * @param event
   *          unused
   */
  @FXML
  public void onPreviousVehicleButtonAction(ActionEvent event)
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
      int noOfCars = cctvFooterPanelModel.getNumberOfCars().get();

      if (noOfCars == ApplicationConstants.SIX_CAR_CONFIG)
      {
        updateForSixCars();

      }
      else
      {
        updateForEightCars();

      }

    }
  }

  private void updateForEightCars()
  {
    if (cctvFooterPanelModel.getSelectedVehicleIndexProperty().get() == 1
        || cctvFooterPanelModel.getSelectedVehicleIndexProperty().get() == 8)
    {

      count++;
      if (count == 1)
      {
        setInputVal(2);

      }
      else
      {
        setInputVal(1);
        count = 0;
      }

    }
    else
    {
      setInputVal(1);
      count = 0;
    }
  }

  private void updateForSixCars()
  {
    if (cctvFooterPanelModel.getSelectedVehicleIndexProperty().get() == 1
        || cctvFooterPanelModel.getSelectedVehicleIndexProperty().get() == 6)
    {

      count++;
      if (count == 1)
      {
        setInputVal(2);

      }
      else
      {
        setInputVal(1);
        count = 0;
      }

    }
    else
    {
      setInputVal(1);
      count = 0;
    }
  }

  private void setInputVal(int requestId)
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendCCtVNextVehicleRequest(requestId);
  }

  /**
   * @param event
   *          unused
   */
  @FXML
  private void onFourFeedTouchPressed(TouchEvent event)
  {
    if (!isCCTVDisplayHangFaultActive)
    {
      onFourFeedAutoRotationAction();
    }
  }

  /**
   * @param event
   *          unused
   */
  @FXML
  private void onFourFeedMouseClicked(MouseEvent event)
  {
    if (!isCCTVDisplayHangFaultActive)
    {
      onFourFeedAutoRotationAction();
    }
  }
}
