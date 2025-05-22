/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.fe.gui.presenter;

import com.sydac.mmrbem.cabscreens.fe.common.NodePseudoClassProperty;
import com.sydac.mmrbem.tcms.common.ScreenId;
import com.sydac.mmrbem.tcms.common.state.ApplicationConstants;
import com.sydac.mmrbem.tcms.common.state.HybridPanelImageIdEnum;
import com.sydac.mmrbem.tcms.common.state.VDUModeEnum;
import com.sydac.mmrbem.tcms.fe.base.TCMSFactory;
import com.sydac.mmrbem.tcms.fe.common.TCMSUIConstants;
import com.sydac.mmrbem.tcms.fe.gui.AbstractTCMSController;
import com.sydac.mmrbem.tcms.fe.gui.binder.CCTVFooterPanelBinder;
import com.sydac.mmrbem.tcms.fe.gui.binder.HybridModeScreenBinder;
import com.sydac.mmrbem.tcms.fe.gui.model.CCTVFooterPanelModel;
import com.sydac.mmrbem.tcms.fe.gui.model.DayDateTimeModel;
import com.sydac.mmrbem.tcms.fe.gui.model.HybridModeScreenModel;
import com.sydac.mmrbem.tcms.fe.gui.state.Days;

import javafx.beans.value.ChangeListener;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.GridPane;

public class CCTVHybridRightPanelController extends AbstractTCMSController
{

  @FXML
  private GridPane rightHybridPanelGrid;

  @FXML
  private GridPane cctvViewGrid;

  @FXML
  private Button moveLeftBtn;

  @FXML
  private Button prevCamBtn;

  @FXML
  private Button nextCamBtn;

  @FXML
  private Button leftCloseBtn;

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

  private NodePseudoClassProperty currentImageProperty;

  private ChangeListener<Number> currentImageIdListener;

  private ChangeListener<Number> hybridPanelSideListener;

  private ChangeListener<String> dayListener;

  private ChangeListener<String> dateListener;

  private ChangeListener<String> timeListener;

  private ChangeListener<String> trainNameLabelListener;

  private ChangeListener<String> lineDirectionListener;

  private ChangeListener<String> currentLocationListener;

  private ChangeListener<String> nextLocationListener;

  private HybridModeScreenModel hybridModeScreenModel;

  private final DayDateTimeModel dayDateTimeModel = new DayDateTimeModel();

  private CCTVFooterPanelModel cctvFooterPanelModel;

  @Override
  public void detachListeners()
  {
    hybridModeScreenModel.getHybridPanelActiveSide().removeListener(hybridPanelSideListener);
    hybridModeScreenModel.getCurrentImageId().removeListener(currentImageIdListener);

    dayDateTimeModel.getDate().removeListener(dateListener);
    dayDateTimeModel.getDay().removeListener(dayListener);
    dayDateTimeModel.getTime().removeListener(timeListener);

    cctvFooterPanelModel.getTrainId().removeListener(trainNameLabelListener);
    cctvFooterPanelModel.getCurrentLocation().removeListener(currentLocationListener);
    cctvFooterPanelModel.getNextLocation().removeListener(nextLocationListener);
    cctvFooterPanelModel.getLineDetail().removeListener(lineDirectionListener);
  }

  @Override
  public void initializeImpl()
  {
    hybridModeScreenModel = new HybridModeScreenModel(scenarioCarIndex);
    tcmsScreenBinders.add(new HybridModeScreenBinder(hybridModeScreenModel));

    cctvFooterPanelModel = new CCTVFooterPanelModel(scenarioCarIndex);
    tcmsScreenBinders.add(new CCTVFooterPanelBinder(cctvFooterPanelModel));

    dayListener = (observable, oldVal, newVal) -> updateDay(newVal);
    dayDateTimeModel.getDay().addListener(dayListener);

    dateListener = (observable, oldVal, newVal) -> updateDate(newVal);
    dayDateTimeModel.getfeedDate().addListener(dateListener);

    timeListener = (observable, oldVal, newVal) -> updateTime(newVal);
    dayDateTimeModel.getTime().addListener(timeListener);

    hybridPanelSideListener = (observable, oldVal, newVal) -> updateRightHybridPanelActive(newVal.intValue());
    hybridModeScreenModel.getHybridPanelActiveSide().addListener(hybridPanelSideListener);

    currentImageProperty = new NodePseudoClassProperty(cctvViewGrid);

    currentImageIdListener = (observable, oldVal, newVal) -> updateHybridPanelImage(newVal.intValue());
    hybridModeScreenModel.getCurrentImageId().addListener(currentImageIdListener);

    trainNameLabelListener = (observable, oldVal, newVal) -> updateTrainNameLabel();
    cctvFooterPanelModel.getTrainId().addListener(trainNameLabelListener);

    lineDirectionListener = (observable, oldVal, newVal) -> updateTrainNameLabel();
    cctvFooterPanelModel.getLineDetail().addListener(lineDirectionListener);

    currentLocationListener = (observable, oldVal, newVal) -> updateCurrentLocationLabel(newVal);
    cctvFooterPanelModel.getCurrentLocation().addListener(currentLocationListener);

    nextLocationListener = (observable, oldVal, newVal) -> updateNextLocationLabel(newVal);
    cctvFooterPanelModel.getNextLocation().addListener(nextLocationListener);

    updateRightHybridPanelActive(hybridModeScreenModel.getHybridPanelActiveSide().get());
    updateHybridPanelImage(hybridModeScreenModel.getCurrentImageId().get());
    updateCurrentLocationLabel(cctvFooterPanelModel.getCurrentLocation().get());
    updateNextLocationLabel(cctvFooterPanelModel.getNextLocation().get());
    updateTrainNameLabel();
  }

  private void updateCamIdLabel()
  {
    int imageId = hybridModeScreenModel.getCurrentImageId().get();
    if (imageId == HybridPanelImageIdEnum.EXTERNAL_CAM_1.getImageId())
    {
      camIdLbl1.setText(ApplicationConstants.EXT_CAM_1);
      camIdLbl2.setText(ApplicationConstants.EXT_CAM_2);
      camIdLbl3.setText(ApplicationConstants.EXT_CAM_3);
      camIdLbl4.setText(ApplicationConstants.EXT_CAM_4);
    }
    else if (imageId == HybridPanelImageIdEnum.EXTERNAL_CAM_2.getImageId())
    {
      camIdLbl1.setText(ApplicationConstants.EXT_CAM_5);
      camIdLbl2.setText(ApplicationConstants.EXT_CAM_6);
      camIdLbl3.setText(ApplicationConstants.EXT_CAM_7);
      camIdLbl4.setText(ApplicationConstants.EXT_CAM_8);
    }
    else if (imageId == HybridPanelImageIdEnum.INTERNAL_CAM_1.getImageId())
    {
      camIdLbl1.setText(ApplicationConstants.INT_CAM_1);
      camIdLbl2.setText(ApplicationConstants.INT_CAM_2);
      camIdLbl3.setText(ApplicationConstants.INT_CAM_3);
      camIdLbl4.setText(ApplicationConstants.INT_CAM_4);
    }
    else if (imageId == HybridPanelImageIdEnum.INTERNAL_CAM_2.getImageId())
    {
      camIdLbl1.setText(ApplicationConstants.INT_CAM_5);
      camIdLbl2.setText(ApplicationConstants.INT_CAM_6);
      camIdLbl3.setText(ApplicationConstants.INT_CAM_7);
      camIdLbl4.setText(ApplicationConstants.INT_CAM_8);
    }
    else if (imageId == HybridPanelImageIdEnum.INTERNAL_CAM_3.getImageId())
    {
      camIdLbl1.setText(ApplicationConstants.INT_CAM_9);
      camIdLbl2.setText(ApplicationConstants.INT_CAM_10);
      camIdLbl3.setText(ApplicationConstants.INT_CAM_11);
      camIdLbl4.setText(ApplicationConstants.INT_CAM_12);
    }
  }

  private void updateTime(String time)
  {
    timeLbl1.setText(time);
    timeLbl2.setText(time);
    timeLbl3.setText(time);
    timeLbl4.setText(time);
  }

  private void updateDate(String date)
  {
    dateLbl1.setText(date);
    dateLbl2.setText(date);
    dateLbl3.setText(date);
    dateLbl4.setText(date);
  }

  private void updateDay(String day)
  {
    dayLbl1.setText(Days.getDay(day).getText());
    dayLbl2.setText(Days.getDay(day).getText());
    dayLbl3.setText(Days.getDay(day).getText());
    dayLbl4.setText(Days.getDay(day).getText());
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

  private void updateHybridPanelImage(int currentImageId)
  {
    currentImageProperty.set(HybridPanelImageIdEnum.valueOf(currentImageId).getPseudoClass());
    updateCamIdLabel();
  }

  private void updateRightHybridPanelActive(int leftActive)
  {
    rightHybridPanelGrid.setVisible(leftActive == TCMSUIConstants.RIGHT_PANEL_ACTIVE);
  }

  @FXML
  public void onCloseButtonAction(ActionEvent event)
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendVDUModeChangeRequest(VDUModeEnum.VDU_TCMS_MODE,
        frontend);
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendPopupChangeRequest(ScreenId.BLANK_SCREEN,
        frontend);
  }

  @FXML
  public void onNextCamButtonAction(ActionEvent event)
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendHybridPanelNextImageReq(TCMSUIConstants.BUTTON_PRESSED);
  }

  @FXML
  private void onPrevCamButtonAction(ActionEvent event)
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendHybridPanelPrevImageReq(TCMSUIConstants.BUTTON_PRESSED);
  }

  private void movePanelToLeft()
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendActiveHybridPanelSideReq(TCMSUIConstants.LEFT_PANEL_ACTIVE);
  }

  @FXML
  public void onMoveLeftButtonAction(ActionEvent event)
  {
    movePanelToLeft();
  }
}
