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

import java.util.HashMap;
import java.util.Map;
import java.util.Objects;

import com.sydac.mmrbem.cabscreens.fe.common.NodePseudoClassProperty;
import com.sydac.mmrbem.cabscreens.fe.utils.timer.CommsTimer;
import com.sydac.mmrbem.tcms.common.ScreenId;
import com.sydac.mmrbem.tcms.common.state.ApplicationConstants;
import com.sydac.mmrbem.tcms.fe.base.TCMSFactory;
import com.sydac.mmrbem.tcms.fe.gui.AbstractTCMSController;
import com.sydac.mmrbem.tcms.fe.gui.binder.CCTVFooterPanelBinder;
import com.sydac.mmrbem.tcms.fe.gui.model.CCTVFooterPanelModel;
import com.sydac.mmrbem.tcms.fe.gui.state.AutoRotationStatus;
import com.sydac.mmrbem.tcms.fe.gui.state.CameraButtonSelectionId;
import com.sydac.mmrbem.tcms.fe.gui.state.EventModeStatus;
import com.sydac.mmrbem.tcms.fe.gui.state.InternalExternalViewStatus;
import com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs;

import javafx.animation.PauseTransition;
import javafx.animation.TranslateTransition;
import javafx.beans.value.ChangeListener;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.input.MouseEvent;
import javafx.scene.input.TouchEvent;
import javafx.scene.layout.GridPane;
import javafx.util.Duration;

public class CCTVFooterPanelController extends AbstractTCMSController
{
  private static final int NO_ACTIVE_ALARM = 0;

  @FXML
  private GridPane footerMainGrid;

  @FXML
  private GridPane innerGrid;

  @FXML
  private GridPane externalCameraButtonsGrid;

  @FXML
  private GridPane sixCarCameraButtonsGrid;

  @FXML
  private GridPane eightCarCameraButtonsGrid;

  @FXML
  private Label internalExternalSwitchLabel;

  @FXML
  private Label autoPlayPauseLbl;

  @FXML
  private Button sixCarDmc1Btn;

  @FXML
  private Button sixCarTc2Btn;

  @FXML
  private Button sixCarMc3Btn;

  @FXML
  private Button sixCarMc4Btn;

  @FXML
  private Button sixCarTc5Btn;

  @FXML
  private Button sixCarDmc6Btn;

  @FXML
  private Button dmc1Btn;

  @FXML
  private Button tc2Btn;

  @FXML
  private Button mc3Btn;

  @FXML
  private Button mc4Btn;

  @FXML
  private Button tc5Btn;

  @FXML
  private Button mc6Btn;

  @FXML
  private Button tc7Btn;

  @FXML
  private Button dmc8Btn;

  @FXML
  private Button ecamLBtn;

  @FXML
  private Button fcamBtn;

  @FXML
  private Button tcamBtn;

  @FXML
  private Button ocamBtn;

  @FXML
  private Button pcamBtn;

  @FXML
  private Button ecamRBtn;

  @FXML
  private Label eventSwitchLbl;

  @FXML
  private Label settingsIconLbl;

  private CCTVFooterPanelModel cctvFooterPanelModel;

  private ChangeListener<Number> internalOrExternalSelectionListener;

  private ChangeListener<Number> normalOrEventSelectionListener;

  private ChangeListener<Number> autoRotationListener;

  private ChangeListener<Number> noOfCarsListener;

  private ChangeListener<Number> selectedVehicleIndexListener;

  private ChangeListener<Number> cctvDisplayHangedFaultListener;

  private ChangeListener<Number> selectedExternalCameraListener;

  private NodePseudoClassProperty autoRotationProperty;

  private NodePseudoClassProperty internalExternalSelectionProperty;

  private NodePseudoClassProperty normalOrEventSelectionProperty;

  private NodePseudoClassProperty sixCarDmc1Property;

  private NodePseudoClassProperty sixCarTc2Property;

  private NodePseudoClassProperty sixCarMc3Property;

  private NodePseudoClassProperty sixCarMc4Property;

  private NodePseudoClassProperty sixCarTc5Property;

  private NodePseudoClassProperty sixCarDmc6Property;

  private NodePseudoClassProperty eightCarDmc1Property;

  private NodePseudoClassProperty eightCarTc2Property;

  private NodePseudoClassProperty eightCarMc3Property;

  private NodePseudoClassProperty eightCarMc4Property;

  private NodePseudoClassProperty eightCarTc5Property;

  private NodePseudoClassProperty eightCarMc6Property;

  private NodePseudoClassProperty eightCarTc7Property;

  private NodePseudoClassProperty eightCarDmc8Property;

  private NodePseudoClassProperty ecamLProperty;

  private NodePseudoClassProperty fcamProperty;

  private NodePseudoClassProperty tcamProperty;

  private NodePseudoClassProperty ocamProperty;

  private NodePseudoClassProperty pcamProperty;

  private NodePseudoClassProperty ecamRProperty;

  private Map<Integer, NodePseudoClassProperty> internalCamButtonMap = new HashMap<>();

  private Map<Integer, NodePseudoClassProperty> internalEightCamButtonMap = new HashMap<>();

  private Map<Integer, NodePseudoClassProperty> externalCamButtonMap = new HashMap<>();

  private boolean isCCTVDisplayHangFaultActive;

  private CommsTimer footerPopupTimer;

  private TranslateTransition transition;

  private boolean dragged = false;

  private ChangeListener<Number> settingPanelListener;
  
  private ChangeListener<Number> normalEventSwitchListener;

  /** Runnable to perform actions of start up sequence */
  private Runnable footerPanelPopupRunnable = () -> {
    if (footerPopupTimer != null)
    {
      footerPopupTimer.safeCancel();
      transition.setToY(90.0);
      transition.play();
      transition.stop();
      innerGrid.setVisible(false);
    }
  };

  @Override
  public void detachListeners()
  {
    cctvFooterPanelModel.getNumberOfCars().removeListener(noOfCarsListener);
    cctvFooterPanelModel.getInternalOrExternalViewProperty()
        .removeListener(internalOrExternalSelectionListener);
    cctvFooterPanelModel.getAutoRotationStatusProperty().removeListener(autoRotationListener);
    cctvFooterPanelModel.getSelectedVehicleIndexProperty().removeListener(selectedVehicleIndexListener);
    cctvFooterPanelModel.getAlarmModeProperty().removeListener(normalOrEventSelectionListener);
    cctvFooterPanelModel.getSelectedExternalCameraType().removeListener(selectedExternalCameraListener);
    cctvFooterPanelModel.getCctvDisplayHangedFault().removeListener(cctvDisplayHangedFaultListener);
    cctvFooterPanelModel.getSettingPanelState().removeListener(settingPanelListener);
    cctvFooterPanelModel.getNormalEventSwitchState().removeListener(normalEventSwitchListener);
  }

  @Override
  public void initializeImpl()
  {
    cctvFooterPanelModel = new CCTVFooterPanelModel(scenarioCarIndex);
    tcmsScreenBinders.add(new CCTVFooterPanelBinder(cctvFooterPanelModel));

    sixCarDmc1Property = new NodePseudoClassProperty(sixCarDmc1Btn);
    sixCarTc2Property = new NodePseudoClassProperty(sixCarTc2Btn);
    sixCarMc3Property = new NodePseudoClassProperty(sixCarMc3Btn);
    sixCarMc4Property = new NodePseudoClassProperty(sixCarMc4Btn);
    sixCarTc5Property = new NodePseudoClassProperty(sixCarTc5Btn);
    sixCarDmc6Property = new NodePseudoClassProperty(sixCarDmc6Btn);

    eightCarDmc1Property = new NodePseudoClassProperty(dmc1Btn);
    eightCarTc2Property = new NodePseudoClassProperty(tc2Btn);
    eightCarMc3Property = new NodePseudoClassProperty(mc3Btn);
    eightCarMc4Property = new NodePseudoClassProperty(mc4Btn);
    eightCarTc5Property = new NodePseudoClassProperty(tc5Btn);
    eightCarMc6Property = new NodePseudoClassProperty(mc6Btn);
    eightCarTc7Property = new NodePseudoClassProperty(tc7Btn);
    eightCarDmc8Property = new NodePseudoClassProperty(dmc8Btn);

    ecamLProperty = new NodePseudoClassProperty(ecamLBtn);
    fcamProperty = new NodePseudoClassProperty(fcamBtn);
    tcamProperty = new NodePseudoClassProperty(tcamBtn);
    ocamProperty = new NodePseudoClassProperty(ocamBtn);
    pcamProperty = new NodePseudoClassProperty(pcamBtn);
    ecamRProperty = new NodePseudoClassProperty(ecamRBtn);

    internalExternalSelectionProperty = new NodePseudoClassProperty(internalExternalSwitchLabel);
    autoRotationProperty = new NodePseudoClassProperty(autoPlayPauseLbl);
    normalOrEventSelectionProperty = new NodePseudoClassProperty(eventSwitchLbl);

    externalCameraButtonsGrid.setVisible(false);

    updateButtonStateList();

    cctvDisplayHangedFaultListener = (observable, oldVal,
        newVal) -> updateDisplayHangedFaultStatus((int)newVal);
    cctvFooterPanelModel.getCctvDisplayHangedFault().addListener(cctvDisplayHangedFaultListener);

    noOfCarsListener = (observable, oldVal, newVal) -> updateInterCameraGridActive((int)newVal);
    cctvFooterPanelModel.getNumberOfCars().addListener(noOfCarsListener);

    internalOrExternalSelectionListener = (observable, oldVal,
        newVal) -> updateExternalCameraGridActive(newVal.intValue());
    cctvFooterPanelModel.getInternalOrExternalViewProperty().addListener(internalOrExternalSelectionListener);

    autoRotationListener = (observable, oldVal, newVal) -> updateAutoRotationState(
        AutoRotationStatus.getStatusOf(newVal.intValue()).getStringValue());
    cctvFooterPanelModel.getAutoRotationStatusProperty().addListener(autoRotationListener);

    selectedVehicleIndexListener = (observable, oldVal,
        newVal) -> updateSelectedButtonState(newVal.intValue());
    cctvFooterPanelModel.getSelectedVehicleIndexProperty().addListener(selectedVehicleIndexListener);

    selectedExternalCameraListener = (observable, oldVal,
        newVal) -> updateSelectedExternalCameraButtonState(newVal.intValue());
    cctvFooterPanelModel.getSelectedExternalCameraType().addListener(selectedExternalCameraListener);

    normalOrEventSelectionListener = (observable, oldVal,
        newVal) -> updateNormalEventState(newVal.intValue());
    cctvFooterPanelModel.getAlarmModeProperty().addListener(normalOrEventSelectionListener);

    updateDisplayHangedFaultStatus(cctvFooterPanelModel.getCctvDisplayHangedFault().get());

    footerPopupTimer = CommsTimer.newScheduledTimer(footerPanelPopupRunnable, 500000);

    transition = new TranslateTransition();
    transition.setNode(footerMainGrid);
    transition.setDuration(Duration.seconds(0.1));
    transition.setAutoReverse(true);

    footerPopupTimer.start();

    settingPanelListener = (observable, oldVal, newVal) -> updateSettingState();
    cctvFooterPanelModel.getSettingPanelState().addListener(settingPanelListener);
    
    normalEventSwitchListener = (observable, oldVal, newVal) -> updateSwitchState();
    cctvFooterPanelModel.getNormalEventSwitchState().addListener(normalEventSwitchListener);
    updateSwitchState();
  }

  private void updateSwitchState()
  {
    CCTVFooterPanelModel.setEventSwitchButtonState(true);
    normalOrEventSelectionProperty.set(EventModeStatus.EVENT.getStringValue());
    PauseTransition visiblePause = new PauseTransition(Duration.seconds(2));
    visiblePause.setOnFinished(event1 -> {
      CCTVFooterPanelModel.setEventSwitchButtonState(false);
      normalOrEventSelectionProperty.set(EventModeStatus.NORMAL.getStringValue());
    });
    visiblePause.play();
  }

  private void updateSettingState()
  {
    if (cctvFooterPanelModel.getSettingPanelState().get() == 1)
    {
      CCTVFooterPanelModel.setSettingsPopupActive(true);
    }
    else
    {
      CCTVFooterPanelModel.setSettingsPopupActive(false);

    }

  }

  private void updateDisplayHangedFaultStatus(int faultActive)
  {
    isCCTVDisplayHangFaultActive = (faultActive == 1);
    if (isCCTVDisplayHangFaultActive
        && AutoRotationStatus.getStatusOf(cctvFooterPanelModel.getAutoRotationStatusProperty().get())
            .equals(AutoRotationStatus.ON))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendCCTVAutoRotationRequest(AutoRotationStatus.OFF);
    }
    else
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendCCTVAutoRotationRequest(AutoRotationStatus.ON);
    }
    if (!isCCTVDisplayHangFaultActive)
    {
      updateAutoRotationState(AutoRotationStatus
          .getStatusOf(cctvFooterPanelModel.getAutoRotationStatusProperty().get()).getStringValue());
      updateInterCameraGridActive(cctvFooterPanelModel.getNumberOfCars().get());
      updateExternalCameraGridActive(cctvFooterPanelModel.getInternalOrExternalViewProperty().get());
      updateSelectedButtonState(cctvFooterPanelModel.getSelectedVehicleIndexProperty().get());
      updateSelectedExternalCameraButtonState(cctvFooterPanelModel.getSelectedExternalCameraType().get());
      updateNormalEventState(cctvFooterPanelModel.getAlarmModeProperty().get());
    }
  }

  private void updateButtonStateList()
  {
    internalCamButtonMap.put(CameraButtonSelectionId.SIX_CAR_DMC_1.getSelectionId(), sixCarDmc1Property);
    internalCamButtonMap.put(CameraButtonSelectionId.SIX_CAR_TC_2.getSelectionId(), sixCarTc2Property);
    internalCamButtonMap.put(CameraButtonSelectionId.SIX_CAR_MC_3.getSelectionId(), sixCarMc3Property);
    internalCamButtonMap.put(CameraButtonSelectionId.SIX_CAR_MC_4.getSelectionId(), sixCarMc4Property);
    internalCamButtonMap.put(CameraButtonSelectionId.SIX_CAR_TC_5.getSelectionId(), sixCarTc5Property);
    internalCamButtonMap.put(CameraButtonSelectionId.SIX_CAR_DMC_6.getSelectionId(), sixCarDmc6Property);

    internalEightCamButtonMap.put(CameraButtonSelectionId.EIGHT_CAR_DMC_1.getSelectionId(),
        eightCarDmc1Property);
    internalEightCamButtonMap.put(CameraButtonSelectionId.EIGHT_CAR_TC_2.getSelectionId(),
        eightCarTc2Property);
    internalEightCamButtonMap.put(CameraButtonSelectionId.EIGHT_CAR_MC_3.getSelectionId(),
        eightCarMc3Property);
    internalEightCamButtonMap.put(CameraButtonSelectionId.EIGHT_CAR_TC_4.getSelectionId(),
        eightCarMc4Property);
    internalEightCamButtonMap.put(CameraButtonSelectionId.EIGHT_CAR_MC_5.getSelectionId(),
        eightCarTc5Property);
    internalEightCamButtonMap.put(CameraButtonSelectionId.EIGHT_CAR_MC_6.getSelectionId(),
        eightCarMc6Property);
    internalEightCamButtonMap.put(CameraButtonSelectionId.EIGHT_CAR_TC_7.getSelectionId(),
        eightCarTc7Property);
    internalEightCamButtonMap.put(CameraButtonSelectionId.EIGHT_CAR_DMC_8.getSelectionId(),
        eightCarDmc8Property);

    externalCamButtonMap.put(CameraButtonSelectionId.EXT_ECAM_L.getSelectionId(), ecamLProperty);
    externalCamButtonMap.put(CameraButtonSelectionId.EXT_FCAM.getSelectionId(), fcamProperty);
    externalCamButtonMap.put(CameraButtonSelectionId.EXT_TCAM.getSelectionId(), tcamProperty);
    externalCamButtonMap.put(CameraButtonSelectionId.EXT_OCAM.getSelectionId(), ocamProperty);
    externalCamButtonMap.put(CameraButtonSelectionId.EXT_PCAM.getSelectionId(), pcamProperty);
    externalCamButtonMap.put(CameraButtonSelectionId.EXT_ECAM_R.getSelectionId(), ecamRProperty);
  }

  private void updateSelectedButtonState(Integer cameraId)
  {
    // Un-select all button first
    int noOfCars = cctvFooterPanelModel.getNumberOfCars().get();
    if (noOfCars == ApplicationConstants.SIX_CAR_CONFIG)
    {
      for (Map.Entry<Integer, NodePseudoClassProperty> entry : internalCamButtonMap.entrySet())
      {
        Integer key = entry.getKey();

        internalCamButtonMap.get(key).set(ApplicationConstants.UNSELECTED_PSEUDO_CLASS);
      }

      // Apply selected pseudo class to select button
      for (Map.Entry<Integer, NodePseudoClassProperty> entry : internalCamButtonMap.entrySet())
      {
        Integer key = entry.getKey();
        if (Objects.equals(key, cameraId))
        {
          internalCamButtonMap.get(key).set(ApplicationConstants.SELECTED_PSEUDO_CLASS);
        }

      }
    }
    else if (noOfCars == ApplicationConstants.EIGHT_CAR_CONFIG)
    {
      for (Map.Entry<Integer, NodePseudoClassProperty> entry : internalEightCamButtonMap.entrySet())
      {
        Integer key = entry.getKey();

        internalEightCamButtonMap.get(key).set(ApplicationConstants.UNSELECTED_PSEUDO_CLASS);
      }

      // Apply selected pseudo class to select button
      for (Map.Entry<Integer, NodePseudoClassProperty> entry : internalEightCamButtonMap.entrySet())
      {
        Integer key = entry.getKey();
        if (Objects.equals(key, cameraId))
        {
          internalEightCamButtonMap.get(key).set(ApplicationConstants.SELECTED_PSEUDO_CLASS);
        }

      }
    }
  }

  private void updateSelectedExternalCameraButtonState(Integer cameraId)
  {
    // Un-select all button first
    for (Map.Entry<Integer, NodePseudoClassProperty> entry : externalCamButtonMap.entrySet())
    {
      Integer key = entry.getKey();
      externalCamButtonMap.get(key).set(ApplicationConstants.UNSELECTED_PSEUDO_CLASS);
    }

    // Apply selected pseudo class to select button
    for (Map.Entry<Integer, NodePseudoClassProperty> entry : externalCamButtonMap.entrySet())
    {
      Integer key = entry.getKey();
      if (Objects.equals(key, cameraId))
      {
        externalCamButtonMap.get(key).set(ApplicationConstants.SELECTED_PSEUDO_CLASS);
      }
    }

    // update internal cam buttons to disabled state
    for (Map.Entry<Integer, NodePseudoClassProperty> entry : internalCamButtonMap.entrySet())
    {
      Integer key = entry.getKey();
      internalCamButtonMap.get(key).set(ApplicationConstants.INACTIVE_PSUEDO_CLASS);
    }
  }

  private void updateAutoRotationState(String cssClass)
  {
    autoRotationProperty.set(cssClass);
  }

  private void updateInterCameraGridActive(int noOfCars)
  {
    sixCarCameraButtonsGrid.setVisible(noOfCars == ApplicationConstants.SIX_CAR_CONFIG);
    eightCarCameraButtonsGrid.setVisible(noOfCars == ApplicationConstants.EIGHT_CAR_CONFIG);
  }

  private void updateExternalCameraGridActive(int active)
  {
    if (active == ApplicationConstants.ACTIVE)
    {
      externalCameraButtonsGrid.setVisible(false);
      updateSelectedButtonState(ApplicationConstants.ACTIVE);
    }
    else
    {
      externalCameraButtonsGrid.setVisible(true);
      updateSelectedExternalCameraButtonState(ApplicationConstants.ACTIVE);

    }
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendScreenChangeRequest(ScreenId.CCTV_FOUR_FEED_SCREEN, frontend);
    internalExternalSelectionProperty.set(InternalExternalViewStatus.getStatusOf(active).getStringValue());
  }

  private void updateNormalEventState(int value)
  {
 
    normalOrEventSelectionProperty.set(EventModeStatus.getStatusOf(value).getStringValue());
  }

  /**
   * @param event
   *          unused
   */
  @FXML
  private void onInternalExternalSwitchMouseClicked(MouseEvent event)
  {
    if (cctvFooterPanelModel.getAlarmModeProperty().get() == NO_ACTIVE_ALARM && !isCCTVDisplayHangFaultActive)
    {
      if (InternalExternalViewStatus
          .getStatusOf(cctvFooterPanelModel.getInternalOrExternalViewProperty().get())
          .equals(InternalExternalViewStatus.INTERNAL_CAMERA_SELECTION))
      {
        TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
            .sendCCTVInternalExternalSelectionRequest(InternalExternalViewStatus.EXTERNAL_CAMERA_SELECTION);
      }
      else
      {
        TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
            .sendCCTVInternalExternalSelectionRequest(InternalExternalViewStatus.INTERNAL_CAMERA_SELECTION);
      }
    }
  }

  /**
   * @param event
   *          unused
   */
  @FXML
  private void onInternalExternalSwitchTouchPressed(TouchEvent event)
  {
    if (cctvFooterPanelModel.getAlarmModeProperty().get() == NO_ACTIVE_ALARM && !isCCTVDisplayHangFaultActive)
    {
      if (InternalExternalViewStatus
          .getStatusOf(cctvFooterPanelModel.getInternalOrExternalViewProperty().get())
          .equals(InternalExternalViewStatus.INTERNAL_CAMERA_SELECTION))
      {
        TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
            .sendCCTVInternalExternalSelectionRequest(InternalExternalViewStatus.EXTERNAL_CAMERA_SELECTION);
      }
      else
      {
        TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
            .sendCCTVInternalExternalSelectionRequest(InternalExternalViewStatus.INTERNAL_CAMERA_SELECTION);
      }
    }
  }

  /**
   * @param event
   *          unused
   */
  @FXML
  private void onEventSwitchMouseClicked(MouseEvent event)
  {
    if (!isCCTVDisplayHangFaultActive)
    {
      if (EventModeStatus.getStatusOf(cctvFooterPanelModel.getAlarmModeProperty().get())
          .equals(EventModeStatus.EVENT))
      {
        TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendButtonClickRequest(VDUInputs.ALARM_MODE);
        TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
            .sendScreenChangeRequest(ScreenId.CCTV_FOUR_FEED_SCREEN, frontend);
      }
      else
      {
        
        TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendButtonClickRequest(VDUInputs.CCTV_NORMAl_EVENT_SWITCH_REQUEST);
      
      }
    }
  }

  /**
   * @param event
   *          unused
   */
  @FXML
  private void onEventSwitchTouchPressed(TouchEvent event)
  {
    if (!isCCTVDisplayHangFaultActive)
    {
      if (EventModeStatus.getStatusOf(cctvFooterPanelModel.getAlarmModeProperty().get())
          .equals(EventModeStatus.EVENT))
      {
        TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendButtonClickRequest(VDUInputs.ALARM_MODE);
        TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
            .sendScreenChangeRequest(ScreenId.CCTV_FOUR_FEED_SCREEN, frontend);
      }
      else
      {
        CCTVFooterPanelModel.setEventSwitchButtonState(true);
        normalOrEventSelectionProperty.set(EventModeStatus.EVENT.getStringValue());
        PauseTransition visiblePause = new PauseTransition(Duration.seconds(2));
        visiblePause.setOnFinished(event1 -> {
          CCTVFooterPanelModel.setEventSwitchButtonState(false);
          normalOrEventSelectionProperty.set(EventModeStatus.NORMAL.getStringValue());
        });
        visiblePause.play();
      }
    }
  }

  /**
   * @param event
   *          unused
   */
  @FXML
  private void onAutoPlayPauseMouseClicked(MouseEvent event)
  {
    if (cctvFooterPanelModel.getAlarmModeProperty().get() == NO_ACTIVE_ALARM && !isCCTVDisplayHangFaultActive)
    {
      if (AutoRotationStatus.getStatusOf(cctvFooterPanelModel.getAutoRotationStatusProperty().get())
          .equals(AutoRotationStatus.OFF))
      {
        TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
            .sendCCTVAutoRotationRequest(AutoRotationStatus.ON);
      }
      else
      {
        TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
            .sendCCTVAutoRotationRequest(AutoRotationStatus.OFF);
      }
    }
  }

  /**
   * @param event
   *          unused
   */
  @FXML
  private void onAutoPlayPauseTouchPressed(TouchEvent event)
  {
    if (cctvFooterPanelModel.getAlarmModeProperty().get() == NO_ACTIVE_ALARM && !isCCTVDisplayHangFaultActive)
    {
      if (AutoRotationStatus.getStatusOf(cctvFooterPanelModel.getAutoRotationStatusProperty().get())
          .equals(AutoRotationStatus.OFF))
      {
        TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
            .sendCCTVAutoRotationRequest(AutoRotationStatus.ON);
      }
      else
      {
        TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
            .sendCCTVAutoRotationRequest(AutoRotationStatus.OFF);
      }
    }
  }

  /**
   * @param event
   *          unused
   */
  @FXML
  private void onSettingsMouseClicked(MouseEvent event)
  {
    if (!isCCTVDisplayHangFaultActive && !CCTVFooterPanelModel.getSettingsPopupActive().get())
    {
      CCTVFooterPanelModel.setSettingsPopupActive(true);

      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendRequest(VDUInputs.CCTV_SETTING_PANEL_REQUEST,1);
    }
  }

  /**
   * @param event
   *          unused
   */
  @FXML
  private void onSettingsTouchPressed(TouchEvent event)
  {
    if (!isCCTVDisplayHangFaultActive && !CCTVFooterPanelModel.getSettingsPopupActive().get())
    {
      CCTVFooterPanelModel.setSettingsPopupActive(true);

      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendButtonClickRequest(VDUInputs.CCTV_SETTING_PANEL_REQUEST);
    }
  }

  @FXML
  private void onSixCarInternalCamButtonAction(ActionEvent event)
  {
    if (cctvFooterPanelModel.getAlarmModeProperty().get() == NO_ACTIVE_ALARM && !isCCTVDisplayHangFaultActive)
    {
      if (event.getSource().equals(sixCarDmc1Btn))
      {
       
        TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
            .sendCCTVCameraVehicleIndexRequest(CameraButtonSelectionId.SIX_CAR_DMC_1);
      }
      else if (event.getSource().equals(sixCarTc2Btn))
      {
        TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
            .sendCCTVCameraVehicleIndexRequest(CameraButtonSelectionId.SIX_CAR_TC_2);
      }
      else if (event.getSource().equals(sixCarMc3Btn))
      {
        TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
            .sendCCTVCameraVehicleIndexRequest(CameraButtonSelectionId.SIX_CAR_MC_3);
      }
      else if (event.getSource().equals(sixCarMc4Btn))
      {
        TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
            .sendCCTVCameraVehicleIndexRequest(CameraButtonSelectionId.SIX_CAR_MC_4);
      }
      else if (event.getSource().equals(sixCarTc5Btn))
      {
        TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
            .sendCCTVCameraVehicleIndexRequest(CameraButtonSelectionId.SIX_CAR_TC_5);
      }
      else if (event.getSource().equals(sixCarDmc6Btn))
      {
        TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
            .sendCCTVCameraVehicleIndexRequest(CameraButtonSelectionId.SIX_CAR_DMC_6);
      }
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendScreenChangeRequest(ScreenId.CCTV_FOUR_FEED_SCREEN, frontend);
    }
  }

  @FXML
  private void onEightCarInternalCamButtonAction(ActionEvent event)
  {
    if (cctvFooterPanelModel.getAlarmModeProperty().get() == NO_ACTIVE_ALARM && !isCCTVDisplayHangFaultActive)
    {
      if (event.getSource().equals(dmc1Btn))
      {

        TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
            .sendCCTVCameraVehicleIndexRequest(CameraButtonSelectionId.EIGHT_CAR_DMC_1);
      }
      else if (event.getSource().equals(tc2Btn))
      {
        TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
            .sendCCTVCameraVehicleIndexRequest(CameraButtonSelectionId.EIGHT_CAR_TC_2);
      }
      else if (event.getSource().equals(mc3Btn))
      {
        TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
            .sendCCTVCameraVehicleIndexRequest(CameraButtonSelectionId.EIGHT_CAR_MC_3);
      }
      else if (event.getSource().equals(mc4Btn))
      {
        TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
            .sendCCTVCameraVehicleIndexRequest(CameraButtonSelectionId.EIGHT_CAR_TC_4);
      }
      else if (event.getSource().equals(tc5Btn))
      {
        TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
            .sendCCTVCameraVehicleIndexRequest(CameraButtonSelectionId.EIGHT_CAR_MC_5);
      }
      else if (event.getSource().equals(mc6Btn))
      {
        TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
            .sendCCTVCameraVehicleIndexRequest(CameraButtonSelectionId.EIGHT_CAR_MC_6);
      }
      else if (event.getSource().equals(tc7Btn))
      {
        TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
            .sendCCTVCameraVehicleIndexRequest(CameraButtonSelectionId.EIGHT_CAR_TC_7);
      }
      else if (event.getSource().equals(dmc8Btn))
      {
        TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
            .sendCCTVCameraVehicleIndexRequest(CameraButtonSelectionId.EIGHT_CAR_DMC_8);
      }
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendScreenChangeRequest(ScreenId.CCTV_FOUR_FEED_SCREEN, frontend);
    }
  }

  @FXML
  private void onExternalCamButtonAction(ActionEvent event)
  {
    if (cctvFooterPanelModel.getAlarmModeProperty().get() == NO_ACTIVE_ALARM && !isCCTVDisplayHangFaultActive)
    {
      if (event.getSource().equals(ecamLBtn))
      {
        TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
            .sendCCTVExteriorCameraTypeRequest(CameraButtonSelectionId.EXT_ECAM_L);
      }
      else if (event.getSource().equals(fcamBtn))
      {
        TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
            .sendCCTVExteriorCameraTypeRequest(CameraButtonSelectionId.EXT_FCAM);
      }
      else if (event.getSource().equals(tcamBtn))
      {
        TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
            .sendCCTVExteriorCameraTypeRequest(CameraButtonSelectionId.EXT_TCAM);
      }
      else if (event.getSource().equals(ocamBtn))
      {
        TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
            .sendCCTVExteriorCameraTypeRequest(CameraButtonSelectionId.EXT_OCAM);
      }
      else if (event.getSource().equals(pcamBtn))
      {
        TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
            .sendCCTVExteriorCameraTypeRequest(CameraButtonSelectionId.EXT_PCAM);
      }
      else if (event.getSource().equals(ecamRBtn))
      {
        TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
            .sendCCTVExteriorCameraTypeRequest(CameraButtonSelectionId.EXT_ECAM_R);
      }
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendScreenChangeRequest(ScreenId.CCTV_FOUR_FEED_SCREEN, frontend);
    }
  }

  @FXML
  private void mouseDragged(MouseEvent event)
  {
    dragged = event.getEventType().equals(MouseEvent.MOUSE_DRAGGED);
  }

  @FXML
  private void mouseReleased(MouseEvent event)
  {

    if (dragged && event.getEventType().equals(MouseEvent.MOUSE_RELEASED))
    {
      if (footerPopupTimer.isRunning())
      {
        footerPopupTimer.safeCancel();
      }
      if (!innerGrid.isVisible())
      {
        transition.setToY(0.0);
        transition.play();
        innerGrid.setVisible(true);
        footerPopupTimer.start();
      }
      else
      {
        transition.setToY(90.0);
        transition.play();
        transition.stop();
        innerGrid.setVisible(false);
      }

    }

    dragged = false;
  }

  @FXML
  private void touchMoved(TouchEvent event)
  {
    dragged = event.getEventType().equals(TouchEvent.TOUCH_MOVED);
  }

  @FXML
  private void touchReleased(TouchEvent event)
  {

    if (dragged && event.getEventType().equals(TouchEvent.TOUCH_RELEASED))
    {
      if (footerPopupTimer.isRunning())
      {
        footerPopupTimer.safeCancel();
      }
      if (!innerGrid.isVisible())
      {
        transition.setToY(0.0);
        transition.play();
        innerGrid.setVisible(true);
        footerPopupTimer.start();
      }
      else
      {
        transition.setToY(90.0);
        transition.play();
        transition.stop();
        innerGrid.setVisible(false);
      }
    }

    dragged = false;
  }

}
