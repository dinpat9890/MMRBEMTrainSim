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

import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.FAULT_DETAILS_CLOSE_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.FAULT_DETAILS_DEVICE_INFO_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.FAULT_DETAILS_TSD_BUTTON;

import com.sydac.mmrbem.cabscreens.fe.base.CommsNumber;
import com.sydac.mmrbem.tcms.common.ScreenId;
import com.sydac.mmrbem.tcms.fe.base.TCMSFactory;
import com.sydac.mmrbem.tcms.fe.gui.AbstractTCMSController;
import com.sydac.mmrbem.tcms.fe.gui.binder.FaultDetailsScreenBinder;
import com.sydac.mmrbem.tcms.fe.gui.model.FaultDetailsScreenModel;

import javafx.beans.value.ChangeListener;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;

public class FaultDetailsScreenController extends AbstractTCMSController
{
  @FXML
  private Label systemLbl;

  @FXML
  private Label componentLbl;

  @FXML
  private Label carCodeLbl;

  @FXML
  private Label faultCodeLbl;

  @FXML
  private Label dateTimeLbl;

  @FXML
  private Label faultPriorityLbl;

  @FXML
  private Label faultDescriptionLbl;

  @FXML
  private Label operatorGuideLbl;

  @FXML
  @CommsNumber(FAULT_DETAILS_CLOSE_BUTTON)
  private Button closeBtn;

  @FXML
  @CommsNumber(FAULT_DETAILS_TSD_BUTTON)
  private Button tsdBtn;

  @FXML
  @CommsNumber(FAULT_DETAILS_DEVICE_INFO_BUTTON)
  private Button deviceInfoBtn;

  private ChangeListener<Number> previousScreenIdListener;

  private Integer previousScreenId;

  private FaultDetailsScreenModel faultDetailsScreenModel;

  @Override
  public void detachListeners()
  {

  }

  @Override
  public void initializeImpl()
  {
    faultDetailsScreenModel = new FaultDetailsScreenModel(scenarioCarIndex);
    tcmsScreenBinders.add(new FaultDetailsScreenBinder(faultDetailsScreenModel));

    previousScreenIdListener = (observable, oldVal, newVal) -> updatePreviousScreenId((Integer)newVal);
    faultDetailsScreenModel.getCloseToPreviousScreenId().addListener(previousScreenIdListener);

    systemLbl.textProperty().bind(faultDetailsScreenModel.getFaultSystem());
    componentLbl.textProperty().bind(faultDetailsScreenModel.getFaultComponent());
    carCodeLbl.textProperty().bind(faultDetailsScreenModel.getFaultCar());
    faultCodeLbl.textProperty().bind(faultDetailsScreenModel.getFaultCode());
    dateTimeLbl.textProperty().bind(faultDetailsScreenModel.getFaultDateTime());
    faultPriorityLbl.textProperty().bind(faultDetailsScreenModel.getFaultPriority());
    faultDescriptionLbl.textProperty().bind(faultDetailsScreenModel.getFaultDescription());
    operatorGuideLbl.textProperty().bind(faultDetailsScreenModel.getOperatorGuide());
  }

  private void updatePreviousScreenId(Integer screenId)
  {
    previousScreenId = screenId;
  }

  @FXML
  void onFaultDetailsCloseButtonAction()
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendScreenChangeRequest(ScreenId.valueOf(previousScreenId), frontend);
  }

}
