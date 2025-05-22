package com.sydac.mmrbem.tcms.fe.gui.presenter;

import com.sydac.mmrbem.cabscreens.fe.common.NodePseudoClassProperty;
import com.sydac.mmrbem.tcms.common.ScreenId;
import com.sydac.mmrbem.tcms.common.state.ApplicationConstants;
import com.sydac.mmrbem.tcms.fe.base.TCMSFactory;
import com.sydac.mmrbem.tcms.fe.gui.AbstractTCMSController;
import com.sydac.mmrbem.tcms.fe.gui.binder.CCTVFooterPanelBinder;
import com.sydac.mmrbem.tcms.fe.gui.model.CCTVFooterPanelModel;
import com.sydac.mmrbem.tcms.fe.gui.state.CCTVAlarmTypeId;

import javafx.beans.value.ChangeListener;
import javafx.fxml.FXML;
import javafx.scene.control.Label;
import javafx.scene.layout.GridPane;

public class CCTVEventsPanelController extends AbstractTCMSController
{

  private static final int NO_ACTIVE_ALARM = 0;

  @FXML
  private GridPane activeEventStatusPanel;

  @FXML
  private Label fireSmokeAlarmLbl;

  @FXML
  private Label obsDetectedSaloonDoorLbl;

  @FXML
  private Label pecuAlarmLbl;

  @FXML
  private Label doorUnlockedLbl;

  @FXML
  private Label emergencyDoorOpeningLbl;

  @FXML
  private Label driverConsoleDeskOpeningLbl;

  @FXML
  private Label obstructionDeflectionDeviceLbl;

  @FXML
  private Label trackRelatedEventsLbl;

  @FXML
  private Label cctvEmergencyButtonLbl;

  @FXML
  private Label oheEventLbl;

  @FXML
  private Label pantographEventLbl;

  @FXML
  private Label activeEventLbl;

  @FXML
  private Label activeCamLbl;

  @FXML
  private Label activeEvent1Lbl;

  @FXML
  private Label activeEvent2Lbl;

  @FXML
  private Label activeEvent3Lbl;

  @FXML
  private Label activeEvent4Lbl;

  @FXML
  private Label activeCam1Lbl;

  @FXML
  private Label activeCam2Lbl;

  @FXML
  private Label activeCam3Lbl;

  @FXML
  private Label activeCam4Lbl;

  private ChangeListener<Number> alarmModeListener;

  private ChangeListener<Number> alarmTypeListener;

  private ChangeListener<Number> alarmFireListener;

  private ChangeListener<Number> alarmObstacleListener;

  private ChangeListener<Number> alarmPecuListener;

  private ChangeListener<Number> alarmDoorUnclockListener;

  private ChangeListener<Number> emergencyDoorOpeningListener;

  private ChangeListener<Number> driverConsoleDeskOpeningListener;

  private ChangeListener<Number> obstructionDeflectionDeviceListener;

  private ChangeListener<Number> trackRelatedEventsListener;

  private ChangeListener<Number> cctvEmergencyButtonListener;

  private ChangeListener<Number> oheEventListener;

  private ChangeListener<Number> pantographEventListener;

  private CCTVFooterPanelModel cctvFooterPanelModel;

  private NodePseudoClassProperty fireSmokeAlarmProperty;

  private NodePseudoClassProperty obstacleAlarmProperty;

  private NodePseudoClassProperty pecuAlarmProperty;

  private NodePseudoClassProperty doorUnlockAlarmProperty;

  private NodePseudoClassProperty emergencyDoorOpenAlarmProperty;

  private NodePseudoClassProperty driverDeskAlarmProperty;

  private NodePseudoClassProperty obstructionDeflectionProperty;

  private NodePseudoClassProperty trackRelatedEventsProperty;

  private NodePseudoClassProperty cctvEmergencyButtonProperty;

  private NodePseudoClassProperty oheEventProperty;

  private NodePseudoClassProperty pantographEventProperty;

  private ChangeListener<Number> firstActiveAlarmListener;

  private ChangeListener<Number> secondActiveAlarmListener;

  private ChangeListener<Number> thirdActiveAlarmListener;

  private ChangeListener<Number> fourthActiveAlarmListener;

  private ChangeListener<Number> cctvDisplayHangedFaultListener;

  @Override
  public void detachListeners()
  {
    cctvFooterPanelModel.getAlarmModeProperty().removeListener(alarmModeListener);
    cctvFooterPanelModel.getAlarmTypeActive().removeListener(alarmTypeListener);
    cctvFooterPanelModel.getFirstFeedAlarmViewIcon().removeListener(firstActiveAlarmListener);
    cctvFooterPanelModel.getSecondFeedAlarmViewIcon().removeListener(secondActiveAlarmListener);
    cctvFooterPanelModel.getThirdFeedAlarmViewIcon().removeListener(thirdActiveAlarmListener);
    cctvFooterPanelModel.getFourthFeedAlarmViewIcon().removeListener(fourthActiveAlarmListener);
    cctvFooterPanelModel.getAlarmFire().removeListener(alarmFireListener);
    cctvFooterPanelModel.getAlarmObstacle().removeListener(alarmObstacleListener);
    cctvFooterPanelModel.getAlarmPecu().removeListener(alarmPecuListener);
    cctvFooterPanelModel.getAlarmDoorUnlock().removeListener(alarmDoorUnclockListener);
    cctvFooterPanelModel.getAlarmEmegencyDoorOpening().removeListener(emergencyDoorOpeningListener);
    cctvFooterPanelModel.getAlarmDriverDesk().removeListener(driverConsoleDeskOpeningListener);
    cctvFooterPanelModel.getAlarmObstructionDeflection().removeListener(obstructionDeflectionDeviceListener);
    cctvFooterPanelModel.getAlarmTrackEvent().removeListener(trackRelatedEventsListener);
    cctvFooterPanelModel.getAlarmEmergencyEvent().removeListener(cctvEmergencyButtonListener);
    cctvFooterPanelModel.getAlarmOheEvent().removeListener(oheEventListener);
    cctvFooterPanelModel.getAlarmPantographEvent().removeListener(pantographEventListener);
    cctvFooterPanelModel.getCctvDisplayHangedFault().removeListener(cctvDisplayHangedFaultListener);
  }

  @Override
  public void initializeImpl()
  {
    cctvFooterPanelModel = new CCTVFooterPanelModel(scenarioCarIndex);
    tcmsScreenBinders.add(new CCTVFooterPanelBinder(cctvFooterPanelModel));

    fireSmokeAlarmProperty = new NodePseudoClassProperty(fireSmokeAlarmLbl);
    obstacleAlarmProperty = new NodePseudoClassProperty(obsDetectedSaloonDoorLbl);
    pecuAlarmProperty = new NodePseudoClassProperty(pecuAlarmLbl);
    doorUnlockAlarmProperty = new NodePseudoClassProperty(doorUnlockedLbl);
    emergencyDoorOpenAlarmProperty = new NodePseudoClassProperty(emergencyDoorOpeningLbl);
    driverDeskAlarmProperty = new NodePseudoClassProperty(driverConsoleDeskOpeningLbl);
    obstructionDeflectionProperty = new NodePseudoClassProperty(obstructionDeflectionDeviceLbl);
    trackRelatedEventsProperty = new NodePseudoClassProperty(trackRelatedEventsLbl);
    cctvEmergencyButtonProperty = new NodePseudoClassProperty(cctvEmergencyButtonLbl);
    oheEventProperty = new NodePseudoClassProperty(oheEventLbl);
    pantographEventProperty = new NodePseudoClassProperty(pantographEventLbl);

    cctvDisplayHangedFaultListener = (observable, oldVal,
        newVal) -> updateDisplayHangedFaultStatus((int)newVal);
    cctvFooterPanelModel.getCctvDisplayHangedFault().addListener(cctvDisplayHangedFaultListener);

    alarmModeListener = (observable, oldVal, newVal) -> updateEventsGridActive(newVal.intValue());
    cctvFooterPanelModel.getAlarmModeProperty().addListener(alarmModeListener);

    alarmFireListener = (observable, oldVal, newVal) -> updateAlarmFireState(newVal.intValue());
    cctvFooterPanelModel.getAlarmFire().addListener(alarmFireListener);

    alarmObstacleListener = (observable, oldVal, newVal) -> updateAlarmObstacleState(newVal.intValue());
    cctvFooterPanelModel.getAlarmObstacle().addListener(alarmObstacleListener);

    alarmPecuListener = (observable, oldVal, newVal) -> updateAlarmPecuState(newVal.intValue());
    cctvFooterPanelModel.getAlarmPecu().addListener(alarmPecuListener);

    alarmDoorUnclockListener = (observable, oldVal, newVal) -> updateDoorUnlockState(newVal.intValue());
    cctvFooterPanelModel.getAlarmDoorUnlock().addListener(alarmDoorUnclockListener);

    emergencyDoorOpeningListener = (observable, oldVal,
        newVal) -> updateEmergencyDoorOpeningState(newVal.intValue());
    cctvFooterPanelModel.getAlarmEmegencyDoorOpening().addListener(emergencyDoorOpeningListener);

    driverConsoleDeskOpeningListener = (observable, oldVal,
        newVal) -> updateDriverConsoleDeskOpeningState(newVal.intValue());
    cctvFooterPanelModel.getAlarmDriverDesk().addListener(driverConsoleDeskOpeningListener);

    obstructionDeflectionDeviceListener = (observable, oldVal,
        newVal) -> updateObstructionDeflectionDeviceState(newVal.intValue());
    cctvFooterPanelModel.getAlarmObstructionDeflection().addListener(obstructionDeflectionDeviceListener);

    trackRelatedEventsListener = (observable, oldVal,
        newVal) -> updateTrackRelatedEventsState(newVal.intValue());
    cctvFooterPanelModel.getAlarmTrackEvent().addListener(trackRelatedEventsListener);

    cctvEmergencyButtonListener = (observable, oldVal,
        newVal) -> updateCctvEmergencyButtonState(newVal.intValue());
    cctvFooterPanelModel.getAlarmEmergencyEvent().addListener(cctvEmergencyButtonListener);

    oheEventListener = (observable, oldVal, newVal) -> updateOheEventState(newVal.intValue());
    cctvFooterPanelModel.getAlarmOheEvent().addListener(oheEventListener);

    pantographEventListener = (observable, oldVal, newVal) -> updatePantographEventState(newVal.intValue());
    cctvFooterPanelModel.getAlarmPantographEvent().addListener(pantographEventListener);

    firstActiveAlarmListener = (observable, oldVal, newVal) -> updateFirstActiveAlarmState(newVal.intValue());
    cctvFooterPanelModel.getFirstFeedAlarmViewIcon().addListener(firstActiveAlarmListener);

    secondActiveAlarmListener = (observable, oldVal,
        newVal) -> updateSecondActiveAlarmState(newVal.intValue());
    cctvFooterPanelModel.getSecondFeedAlarmViewIcon().addListener(secondActiveAlarmListener);

    thirdActiveAlarmListener = (observable, oldVal, newVal) -> updateThirdActiveAlarmState(newVal.intValue());
    cctvFooterPanelModel.getThirdFeedAlarmViewIcon().addListener(thirdActiveAlarmListener);

    fourthActiveAlarmListener = (observable, oldVal,
        newVal) -> updateFourthActiveAlarmState(newVal.intValue());
    cctvFooterPanelModel.getFourthFeedAlarmViewIcon().addListener(fourthActiveAlarmListener);

    updateEventsGridActive(cctvFooterPanelModel.getAlarmModeProperty().get());
    updateAlarmFireState(cctvFooterPanelModel.getAlarmFire().get());
    updateAlarmObstacleState(cctvFooterPanelModel.getAlarmObstacle().get());
    updateAlarmPecuState(cctvFooterPanelModel.getAlarmPecu().get());
    updateDoorUnlockState(cctvFooterPanelModel.getAlarmDoorUnlock().get());
    updateEmergencyDoorOpeningState(cctvFooterPanelModel.getAlarmEmegencyDoorOpening().get());
    updateDriverConsoleDeskOpeningState(cctvFooterPanelModel.getAlarmDriverDesk().get());
    updateObstructionDeflectionDeviceState(cctvFooterPanelModel.getAlarmObstructionDeflection().get());
    updateTrackRelatedEventsState(cctvFooterPanelModel.getAlarmTrackEvent().get());
    updateCctvEmergencyButtonState(cctvFooterPanelModel.getAlarmEmergencyEvent().get());
    updateOheEventState(cctvFooterPanelModel.getAlarmOheEvent().get());
    updatePantographEventState(cctvFooterPanelModel.getAlarmPantographEvent().get());

    updateFirstActiveAlarmState(cctvFooterPanelModel.getFirstFeedAlarmViewIcon().get());
    updateSecondActiveAlarmState(cctvFooterPanelModel.getSecondFeedAlarmViewIcon().get());
    updateThirdActiveAlarmState(cctvFooterPanelModel.getThirdFeedAlarmViewIcon().get());
    updateFourthActiveAlarmState(cctvFooterPanelModel.getFourthFeedAlarmViewIcon().get());

  }

  private void updateDisplayHangedFaultStatus(int faultActive)
  {
    boolean isCCTVDisplayHangFaultActive = (faultActive == 1);
    if (!isCCTVDisplayHangFaultActive)
    {
      updateEventsGridActive(cctvFooterPanelModel.getAlarmModeProperty().get());
      updateAlarmFireState(cctvFooterPanelModel.getAlarmFire().get());
      updateAlarmObstacleState(cctvFooterPanelModel.getAlarmObstacle().get());
      updateAlarmPecuState(cctvFooterPanelModel.getAlarmPecu().get());
      updateDoorUnlockState(cctvFooterPanelModel.getAlarmDoorUnlock().get());
      updateEmergencyDoorOpeningState(cctvFooterPanelModel.getAlarmEmegencyDoorOpening().get());
      updateDriverConsoleDeskOpeningState(cctvFooterPanelModel.getAlarmDriverDesk().get());
      updateObstructionDeflectionDeviceState(cctvFooterPanelModel.getAlarmObstructionDeflection().get());
      updateTrackRelatedEventsState(cctvFooterPanelModel.getAlarmTrackEvent().get());
      updateCctvEmergencyButtonState(cctvFooterPanelModel.getAlarmEmergencyEvent().get());
      updateOheEventState(cctvFooterPanelModel.getAlarmOheEvent().get());
      updatePantographEventState(cctvFooterPanelModel.getAlarmPantographEvent().get());

      updateFirstActiveAlarmState(cctvFooterPanelModel.getFirstFeedAlarmViewIcon().get());
      updateSecondActiveAlarmState(cctvFooterPanelModel.getSecondFeedAlarmViewIcon().get());
      updateThirdActiveAlarmState(cctvFooterPanelModel.getThirdFeedAlarmViewIcon().get());
      updateFourthActiveAlarmState(cctvFooterPanelModel.getFourthFeedAlarmViewIcon().get());
    }
  }

  private void updateFourthActiveAlarmState(int value)
  {
    activeEvent4Lbl.getStyleClass().clear();
    activeEvent4Lbl.setVisible(false);
    activeCam4Lbl.setVisible(false);
    if (value > NO_ACTIVE_ALARM)
    {
      activeEvent4Lbl.setVisible(true);
      activeCam4Lbl.setVisible(true);
      activeEvent4Lbl.getStyleClass().add(CCTVAlarmTypeId.getAlarmIdof(value).getAlarmName());
      activeCam4Lbl.setText(cctvFooterPanelModel.getFourthFeedAlarmViewLable().get());
    }
    else
    {
      activeEvent4Lbl.setVisible(false);
      activeCam4Lbl.setVisible(false);
    }
  }

  private void updateThirdActiveAlarmState(int value)
  {
    activeEvent3Lbl.getStyleClass().clear();
    activeEvent3Lbl.setVisible(false);
    activeCam3Lbl.setVisible(false);
    if (value > NO_ACTIVE_ALARM)
    {
      activeEvent3Lbl.setVisible(true);
      activeCam3Lbl.setVisible(true);
      activeEvent3Lbl.getStyleClass().add(CCTVAlarmTypeId.getAlarmIdof(value).getAlarmName());
      activeCam3Lbl.setText(cctvFooterPanelModel.getThirdFeedAlarmViewLable().get());
    }
    else
    {
      activeEvent3Lbl.setVisible(false);
      activeCam3Lbl.setVisible(false);
    }
  }

  private void updateSecondActiveAlarmState(int value)
  {
    activeEvent2Lbl.getStyleClass().clear();
    activeEvent2Lbl.setVisible(false);
    activeCam2Lbl.setVisible(false);
    if (value > NO_ACTIVE_ALARM)
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendScreenChangeRequest(ScreenId.CCTV_FOUR_FEED_SCREEN, frontend);
      activeEvent2Lbl.setVisible(true);
      activeCam2Lbl.setVisible(true);
      activeEvent2Lbl.getStyleClass().add(CCTVAlarmTypeId.getAlarmIdof(value).getAlarmName());
      activeCam2Lbl.setText(cctvFooterPanelModel.getSecondFeedAlarmViewLable().get());

    }
    else
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendScreenChangeRequest(ScreenId.CCTV_SINGLE_FEED_SCREEN, frontend);
      activeEvent2Lbl.setVisible(false);
      activeCam2Lbl.setVisible(false);
    }
  }

  private void updateFirstActiveAlarmState(int value)
  {
    activeEvent1Lbl.getStyleClass().clear();
    activeEvent1Lbl.setVisible(false);
    activeCam1Lbl.setVisible(false);
    if (value > NO_ACTIVE_ALARM)
    {
      activeEvent1Lbl.setVisible(true);
      activeCam1Lbl.setVisible(true);
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendScreenChangeRequest(ScreenId.CCTV_SINGLE_FEED_SCREEN, frontend);
      activeEvent1Lbl.getStyleClass().add(CCTVAlarmTypeId.getAlarmIdof(value).getAlarmName());
      activeCam1Lbl.setText(cctvFooterPanelModel.getFirstFeedAlarmViewLable().get());
    }
    else
    {
      activeEvent1Lbl.setVisible(false);
      activeCam1Lbl.setVisible(false);
    }
  }

  private void updateCctvEmergencyButtonState(int active)
  {
    if (active == ApplicationConstants.ACTIVE)
    {
      cctvEmergencyButtonProperty.set(ApplicationConstants.ALARM_IS_ACTIVE);
    }
    else
    {
      cctvEmergencyButtonProperty.set(ApplicationConstants.ALARM_IS_NOT_ACTIVE);
    }
  }

  private void updateOheEventState(int active)
  {
    if (active == ApplicationConstants.ACTIVE)
    {
      oheEventProperty.set(ApplicationConstants.ALARM_IS_ACTIVE);
    }
    else
    {
      oheEventProperty.set(ApplicationConstants.ALARM_IS_NOT_ACTIVE);
    }
  }

  private void updatePantographEventState(int active)
  {
    if (active == ApplicationConstants.ACTIVE)
    {
      pantographEventProperty.set(ApplicationConstants.ALARM_IS_ACTIVE);
    }
    else
    {
      pantographEventProperty.set(ApplicationConstants.ALARM_IS_NOT_ACTIVE);
    }
  }

  private void updateTrackRelatedEventsState(int active)
  {
    if (active == ApplicationConstants.ACTIVE)
    {
      trackRelatedEventsProperty.set(ApplicationConstants.ALARM_IS_ACTIVE);
    }
    else
    {
      trackRelatedEventsProperty.set(ApplicationConstants.ALARM_IS_NOT_ACTIVE);
    }
  }

  private void updateObstructionDeflectionDeviceState(int active)
  {
    if (active == ApplicationConstants.ACTIVE)
    {
      obstructionDeflectionProperty.set(ApplicationConstants.ALARM_IS_ACTIVE);
    }
    else
    {
      obstructionDeflectionProperty.set(ApplicationConstants.ALARM_IS_NOT_ACTIVE);
    }
  }

  private void updateDriverConsoleDeskOpeningState(int active)
  {
    if (active == ApplicationConstants.ACTIVE)
    {
      driverDeskAlarmProperty.set(ApplicationConstants.ALARM_IS_ACTIVE);
    }
    else
    {
      driverDeskAlarmProperty.set(ApplicationConstants.ALARM_IS_NOT_ACTIVE);
    }
  }

  private void updateEmergencyDoorOpeningState(int active)
  {
    if (active == ApplicationConstants.ACTIVE)
    {
      emergencyDoorOpenAlarmProperty.set(ApplicationConstants.ALARM_IS_ACTIVE);
    }
    else
    {
      emergencyDoorOpenAlarmProperty.set(ApplicationConstants.ALARM_IS_NOT_ACTIVE);
    }
  }

  private void updateDoorUnlockState(int active)
  {
    if (active == ApplicationConstants.ACTIVE)
    {
      doorUnlockAlarmProperty.set(ApplicationConstants.ALARM_IS_ACTIVE);
    }
    else
    {
      doorUnlockAlarmProperty.set(ApplicationConstants.ALARM_IS_NOT_ACTIVE);
    }
  }

  private void updateAlarmPecuState(int active)
  {
    if (active == ApplicationConstants.ACTIVE)
    {
      pecuAlarmProperty.set(ApplicationConstants.ALARM_IS_ACTIVE);
    }
    else
    {
      pecuAlarmProperty.set(ApplicationConstants.ALARM_IS_NOT_ACTIVE);
    }
  }

  private void updateAlarmObstacleState(int active)
  {
    if (active == ApplicationConstants.ACTIVE)
    {
      obstacleAlarmProperty.set(ApplicationConstants.ALARM_IS_ACTIVE);
    }
    else
    {
      obstacleAlarmProperty.set(ApplicationConstants.ALARM_IS_NOT_ACTIVE);
    }
  }

  private void updateAlarmFireState(int active)
  {
    if (active == ApplicationConstants.ACTIVE)
    {
      fireSmokeAlarmProperty.set(ApplicationConstants.ALARM_IS_ACTIVE);
    }
    else
    {
      fireSmokeAlarmProperty.set(ApplicationConstants.ALARM_IS_NOT_ACTIVE);
    }
  }

  private void updateEventsGridActive(int active)
  {
    activeEventStatusPanel.setVisible(active == ApplicationConstants.ACTIVE);
  }

}
