/*
 * ==================================================================
 * 
 * (C) Copyright 2020 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */

package com.sydac.mmrbem.dmi.fe.gui.presenter;

import static com.sydac.project.runtimedata.ProjectObjectConstants.DMIInputs.CREW_ID_POPUP_SCREEN_BUTTON_0_PRESSED;
import static com.sydac.project.runtimedata.ProjectObjectConstants.DMIInputs.CREW_ID_POPUP_SCREEN_BUTTON_1_PRESSED;
import static com.sydac.project.runtimedata.ProjectObjectConstants.DMIInputs.CREW_ID_POPUP_SCREEN_BUTTON_2_PRESSED;
import static com.sydac.project.runtimedata.ProjectObjectConstants.DMIInputs.CREW_ID_POPUP_SCREEN_BUTTON_3_PRESSED;
import static com.sydac.project.runtimedata.ProjectObjectConstants.DMIInputs.CREW_ID_POPUP_SCREEN_BUTTON_4_PRESSED;
import static com.sydac.project.runtimedata.ProjectObjectConstants.DMIInputs.CREW_ID_POPUP_SCREEN_BUTTON_5_PRESSED;
import static com.sydac.project.runtimedata.ProjectObjectConstants.DMIInputs.CREW_ID_POPUP_SCREEN_BUTTON_6_PRESSED;
import static com.sydac.project.runtimedata.ProjectObjectConstants.DMIInputs.CREW_ID_POPUP_SCREEN_BUTTON_7_PRESSED;
import static com.sydac.project.runtimedata.ProjectObjectConstants.DMIInputs.CREW_ID_POPUP_SCREEN_BUTTON_8_PRESSED;
import static com.sydac.project.runtimedata.ProjectObjectConstants.DMIInputs.CREW_ID_POPUP_SCREEN_BUTTON_9_PRESSED;
import static com.sydac.project.runtimedata.ProjectObjectConstants.DMIInputs.CREW_ID_POPUP_SCREEN_CANCEL_BUTTON_PRESSED;
import static com.sydac.project.runtimedata.ProjectObjectConstants.DMIInputs.CREW_ID_POPUP_SCREEN_CLEAR_BUTTON_PRESSED;
import static com.sydac.project.runtimedata.ProjectObjectConstants.DMIInputs.CREW_ID_POPUP_SCREEN_VALIDATE_BUTTON_PRESSED;

import com.sydac.mmrbem.cabscreens.fe.base.CommsNumber;
import com.sydac.mmrbem.dmi.common.state.ApplicationConstants;
import com.sydac.mmrbem.dmi.fe.base.DMIFactory;
import com.sydac.mmrbem.dmi.fe.gui.AbstractDMIController;
import com.sydac.mmrbem.dmi.fe.gui.binder.CrewIdPopupBinder;
import com.sydac.mmrbem.dmi.fe.gui.model.CrewIdPopupModel;

import javafx.beans.value.ChangeListener;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.Pane;

/**
 * A controller for Crew Id popup dialog
 * 
 * @author potdars
 */
public class CrewIdPopupController extends AbstractDMIController
{

  @FXML
  private GridPane mainGrid;

  @FXML
  private Pane crewPane;

  @FXML
  private GridPane crewGrid;
  
  @FXML
  @CommsNumber(CREW_ID_POPUP_SCREEN_BUTTON_8_PRESSED)
  private Button keyPadNum8;

  @FXML
  @CommsNumber(CREW_ID_POPUP_SCREEN_BUTTON_9_PRESSED)
  private Button keyPadNum9;

  @FXML
  @CommsNumber(CREW_ID_POPUP_SCREEN_BUTTON_5_PRESSED)
  private Button keyPadNum5;

  @FXML
  @CommsNumber(CREW_ID_POPUP_SCREEN_BUTTON_4_PRESSED)
  private Button keyPadNum4;

  @FXML
  @CommsNumber(CREW_ID_POPUP_SCREEN_BUTTON_3_PRESSED)
  private Button keyPadNum3;

  @FXML
  @CommsNumber(CREW_ID_POPUP_SCREEN_BUTTON_6_PRESSED)
  private Button keyPadNum6;

  @FXML
  @CommsNumber(CREW_ID_POPUP_SCREEN_BUTTON_1_PRESSED)
  private Button keyPadNum1;

  @FXML
  @CommsNumber(CREW_ID_POPUP_SCREEN_BUTTON_2_PRESSED)
  private Button keyPadNum2;

  @FXML
  @CommsNumber(CREW_ID_POPUP_SCREEN_BUTTON_7_PRESSED)
  private Button keyPadNum7;

  @FXML
  @CommsNumber(CREW_ID_POPUP_SCREEN_CLEAR_BUTTON_PRESSED)
  private Button clearCrewNumberButton;

  @FXML
  @CommsNumber(CREW_ID_POPUP_SCREEN_BUTTON_0_PRESSED)
  private Button keyPadNum0;

  @FXML
  @CommsNumber(CREW_ID_POPUP_SCREEN_VALIDATE_BUTTON_PRESSED)
  private Button keyPadValidateButton;

  @FXML
  @CommsNumber(CREW_ID_POPUP_SCREEN_CANCEL_BUTTON_PRESSED)
  private Button keyPadCancelButton;

  @FXML
  private Label keyPadInputLabel;

  @FXML
  private Label enterCrewIdLabel;

  @FXML
  private TextField crewNumberText;

  private CrewIdPopupModel crewIdPopupModel;

  private ChangeListener<String> crewIdPanelEnteredNumberListener;

  @Override
  public void initializeImpl()
  {

    AbstractDMIController.updateScaledPrefSize(mainGrid, mainGrid.getPrefWidth(), mainGrid.getPrefHeight());

    AbstractDMIController.updateScaledPrefSize(crewPane, crewPane.getPrefWidth(),
        crewPane.getPrefHeight());

    AbstractDMIController.updateScaledPrefSize(crewGrid, crewGrid.getPrefWidth(), crewGrid.getPrefHeight());
    
    crewGrid.setLayoutX(ApplicationConstants.CREW_GRID_LAYOUT_X * AbstractDMIController.WIDTH_SCALE);
    
    AbstractDMIController.updateScaledPrefSize(crewNumberText, crewNumberText.getPrefWidth(), crewNumberText.getPrefHeight());

    crewIdPopupModel = new CrewIdPopupModel(scenarioCarIndex);
    dmiScreenBinders.add(new CrewIdPopupBinder(crewIdPopupModel));

    keyPadNum0.setText("0");
    keyPadNum1.setText("1");
    keyPadNum2.setText("2");
    keyPadNum3.setText("3");
    keyPadNum4.setText("4");
    keyPadNum5.setText("5");
    keyPadNum6.setText("6");
    keyPadNum7.setText("7");
    keyPadNum8.setText("8");
    keyPadNum9.setText("9");

    initalizeCrewIdPanelEnteredNumberListner();

  }

  private void initalizeCrewIdPanelEnteredNumberListner()
  {
    crewIdPanelEnteredNumberListener = (observable, oldVal,
        newVal) -> updateCrewNumberText(crewIdPopupModel.getCrewIdPanelEnteredNumber().get());

    crewIdPopupModel.getCrewIdPanelEnteredNumber().addListener(crewIdPanelEnteredNumberListener);

    updateCrewNumberText(crewIdPopupModel.getCrewIdPanelEnteredNumber().get());
  }

  private void updateCrewNumberText(String crewNum)
  {
    crewNumberText.setText(crewNum);
  }

  @FXML
  void buttonClicked(MouseEvent event)
  {
    if (event.getSource().equals(keyPadNum0))
    {
      DMIFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendButtonClickRequest(CREW_ID_POPUP_SCREEN_BUTTON_0_PRESSED);
    }
    else if (event.getSource().equals(keyPadNum1))
    {
      DMIFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendButtonClickRequest(CREW_ID_POPUP_SCREEN_BUTTON_1_PRESSED);
      // sendButtonRequest(IAppInputsCrewIdPopupProperties.CREW_ID_POPUP_SCREEN_BUTTON_1_PRESSED,
      // 1);
    }
    else if (event.getSource().equals(keyPadNum2))
    {
      DMIFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendButtonClickRequest(CREW_ID_POPUP_SCREEN_BUTTON_2_PRESSED);
    }
    else if (event.getSource().equals(keyPadNum3))
    {
      DMIFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendButtonClickRequest(CREW_ID_POPUP_SCREEN_BUTTON_3_PRESSED);
    }
    else if (event.getSource().equals(keyPadNum4))
    {
      DMIFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendButtonClickRequest(CREW_ID_POPUP_SCREEN_BUTTON_4_PRESSED);
    }
    else if (event.getSource().equals(keyPadNum5))
    {
      DMIFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendButtonClickRequest(CREW_ID_POPUP_SCREEN_BUTTON_5_PRESSED);
    }
    else if (event.getSource().equals(keyPadNum6))
    {
      DMIFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendButtonClickRequest(CREW_ID_POPUP_SCREEN_BUTTON_6_PRESSED);
    }
    else if (event.getSource().equals(keyPadNum7))
    {
      DMIFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendButtonClickRequest(CREW_ID_POPUP_SCREEN_BUTTON_7_PRESSED);
    }
    else if (event.getSource().equals(keyPadNum8))
    {
      DMIFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendButtonClickRequest(CREW_ID_POPUP_SCREEN_BUTTON_8_PRESSED);
    }
    else if (event.getSource().equals(keyPadNum9))
    {
      DMIFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendButtonClickRequest(CREW_ID_POPUP_SCREEN_BUTTON_9_PRESSED);
    }
    else if (event.getSource().equals(clearCrewNumberButton))
    {
      DMIFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendButtonClickRequest(CREW_ID_POPUP_SCREEN_CLEAR_BUTTON_PRESSED);
    }
    else if (event.getSource().equals(keyPadValidateButton))
    {
      DMIFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendButtonClickRequest(CREW_ID_POPUP_SCREEN_VALIDATE_BUTTON_PRESSED);
    }
    else if (event.getSource().equals(keyPadCancelButton))
    {
      DMIFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendButtonClickRequest(CREW_ID_POPUP_SCREEN_CANCEL_BUTTON_PRESSED);
    }
  }

  @Override
  public void detachListeners()
  {
    crewIdPopupModel.getCrewIdPanelEnteredNumber().removeListener(crewIdPanelEnteredNumberListener);
  }

}