/*******************************************************************************
 * (C) Copyright 2023 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.papis.fe.gui.presenter;

import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.FAULT_SCREEN_BACK_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.FAULT_SCREEN_DOWN_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.FAULT_SCREEN_UP_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.FAULT_SELECT_TEST_BUTTON;

import com.sydac.mmrbem.cabscreens.fe.base.CommsNumber;
import com.sydac.mmrbem.papis.common.ScreenId;
import com.sydac.mmrbem.papis.fe.base.PAPISFactory;
import com.sydac.mmrbem.papis.fe.gui.AbstractPAPISController;
import com.sydac.mmrbem.papis.fe.gui.model.HeaderDateTimeModel;

import javafx.beans.value.ChangeListener;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;

public class PapisFaultScreenController extends AbstractPAPISController
{

  @FXML
  private Label timeLbl;

  @FXML
  private Label dateLbl;

  @FXML
  @CommsNumber(FAULT_SELECT_TEST_BUTTON)
  private Button selectTestBtn;

  @FXML
  @CommsNumber(FAULT_SCREEN_UP_BUTTON)
  private Button upBtn;

  @FXML
  @CommsNumber(FAULT_SCREEN_DOWN_BUTTON)
  private Button downBtn;

  @FXML
  @CommsNumber(FAULT_SCREEN_BACK_BUTTON)
  private Button backBtn;

  private ChangeListener<String> dateLabelListener;

  private ChangeListener<String> timeLabelListener;

  private HeaderDateTimeModel headerDateTimeModel;

  @Override
  public void detachListeners()
  {
    headerDateTimeModel.getCurrentDate().removeListener(dateLabelListener);
    headerDateTimeModel.getCurrentTime().removeListener(timeLabelListener);
  }

  @Override
  public void initializeImpl()
  {
    headerDateTimeModel = new HeaderDateTimeModel(scenarioCarIndex);

    dateLabelListener = (observable, oldVal, newVal) -> updateDateLabel(newVal);
    this.headerDateTimeModel.getCurrentDate().addListener(dateLabelListener);

    timeLabelListener = (observable, oldVal, newVal) -> updateTimeLabel(newVal);
    this.headerDateTimeModel.getCurrentTime().addListener(timeLabelListener);

    updateDateLabel(this.headerDateTimeModel.getCurrentDate().get());
    updateTimeLabel(this.headerDateTimeModel.getCurrentTime().get());
  }

  private void updateDateLabel(String newVal)
  {
    this.dateLbl.setText(newVal);
  }

  private void updateTimeLabel(String newVal)
  {
    this.timeLbl.setText(newVal);
  }

  /**
   * @param event
   *          unused
   */
  @FXML
  private void onSeltTestButtonAction(ActionEvent event)
  {
    // TODO Functionality to be added when data is available.
  }

  /**
   * @param event
   *          unused
   */
  @FXML
  private void onUpButtonAction(ActionEvent event)
  {
    // TODO Functionality to be added when data is available.
  }

  /**
   * @param event
   *          unused
   */
  @FXML
  private void onDownButtonAction(ActionEvent event)
  {
    // TODO Functionality to be added when data is available.
  }

  /**
   * @param event
   *          unused
   */
  @FXML
  private void onBackButtonAction(ActionEvent event)
  {
    PAPISFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendScreenChangeRequest(ScreenId.MAIN_INTERFACE_SCREEN);
  }

}
