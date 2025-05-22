/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.papis.fe.gui.presenter;

import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.KEYPAD_0_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.KEYPAD_1_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.KEYPAD_2_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.KEYPAD_3_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.KEYPAD_4_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.KEYPAD_5_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.KEYPAD_6_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.KEYPAD_7_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.KEYPAD_8_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.KEYPAD_9_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.KEYPAD_CLEAR_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.KEYPAD_KB_BUTTON;

import java.util.ArrayList;
import java.util.List;

import com.sydac.mmrbem.cabscreens.fe.base.CommsNumber;
import com.sydac.mmrbem.papis.common.ScreenId;
import com.sydac.mmrbem.papis.common.state.ApplicationConstants;
import com.sydac.mmrbem.papis.common.state.KeyPadEnum;
import com.sydac.mmrbem.papis.fe.base.PAPISFactory;
import com.sydac.mmrbem.papis.fe.gui.AbstractPAPISController;
import com.sydac.mmrbem.papis.fe.gui.binder.TrainIdSettingsScreenBinder;
import com.sydac.mmrbem.papis.fe.gui.model.HeaderDateTimeModel;
import com.sydac.mmrbem.papis.fe.gui.model.TrainIdSettingScreenModel;
import com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs;

import javafx.beans.value.ChangeListener;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;

public class TrainIdSettingScreenController extends AbstractPAPISController
{
  @FXML
  private Label timeLbl;

  @FXML
  private Label dateLbl;

  @FXML
  @CommsNumber(KEYPAD_1_BUTTON)
  private Button num1Btn;

  @FXML
  @CommsNumber(KEYPAD_2_BUTTON)
  private Button num2Btn;

  @FXML
  @CommsNumber(KEYPAD_3_BUTTON)
  private Button num3Btn;

  @FXML
  @CommsNumber(KEYPAD_4_BUTTON)
  private Button num4Btn;

  @FXML
  @CommsNumber(KEYPAD_5_BUTTON)
  private Button num5Btn;

  @FXML
  @CommsNumber(KEYPAD_6_BUTTON)
  private Button num6Btn;

  @FXML
  @CommsNumber(KEYPAD_7_BUTTON)
  private Button num7Btn;

  @FXML
  @CommsNumber(KEYPAD_8_BUTTON)
  private Button num8Btn;

  @FXML
  @CommsNumber(KEYPAD_9_BUTTON)
  private Button num9Btn;

  @FXML
  @CommsNumber(KEYPAD_0_BUTTON)
  private Button num0Btn;

  @FXML
  @CommsNumber(KEYPAD_KB_BUTTON)
  private Button kbBtn;

  @FXML
  @CommsNumber(KEYPAD_CLEAR_BUTTON)
  private Button clearBtn;

  @FXML
  private Button trainIdScreenOkBtn;

  @FXML
  private Button trainIdScreenBackBtn;

  @FXML
  private Label trainIdLbl;

  private ChangeListener<String> dateLabelListener;

  private ChangeListener<String> timeLabelListener;

  private ChangeListener<String> trainIdListener;

  private TrainIdSettingScreenModel trainIdSettingScreenModel;

  private HeaderDateTimeModel headerDateTimeModel;

  private List<Button> buttonList = new ArrayList<>();

  @Override
  public void detachListeners()
  {
    headerDateTimeModel.getCurrentDate().removeListener(dateLabelListener);
    headerDateTimeModel.getCurrentTime().removeListener(timeLabelListener);
    trainIdSettingScreenModel.getTrainIdproperty().removeListener(trainIdListener);
  }

  @Override
  public void initializeImpl()
  {
    trainIdSettingScreenModel = new TrainIdSettingScreenModel(scenarioCarIndex);
    papisScreenBinders.add(new TrainIdSettingsScreenBinder(trainIdSettingScreenModel));
    buttonList.add(num0Btn);
    buttonList.add(num1Btn);
    buttonList.add(num2Btn);
    buttonList.add(num3Btn);
    buttonList.add(num4Btn);
    buttonList.add(num5Btn);
    buttonList.add(num6Btn);
    buttonList.add(num7Btn);
    buttonList.add(num8Btn);
    buttonList.add(num9Btn);
    buttonList.add(kbBtn);
    buttonList.add(clearBtn);

    headerDateTimeModel = new HeaderDateTimeModel(scenarioCarIndex);

    dateLabelListener = (observable, oldVal, newVal) -> updateDateLabel(newVal);
    this.headerDateTimeModel.getCurrentDate().addListener(dateLabelListener);

    timeLabelListener = (observable, oldVal, newVal) -> updateTimeLabel(newVal);
    this.headerDateTimeModel.getCurrentTime().addListener(timeLabelListener);

    updateDateLabel(this.headerDateTimeModel.getCurrentDate().get());
    updateTimeLabel(this.headerDateTimeModel.getCurrentTime().get());

    trainIdListener = (observable, oldVal, newVal) -> updateTrainId(newVal);
    trainIdSettingScreenModel.getTrainIdproperty().addListener(trainIdListener);
  }

  private void updateDateLabel(String newVal)
  {
    this.dateLbl.setText(newVal);
  }

  private void updateTimeLabel(String newVal)
  {
    this.timeLbl.setText(newVal);
  }

  private void updateTrainId(String trainId)
  {
    trainIdLbl.setText(trainId);
  }

  @FXML
  private void onTrainIdInputButtonAction(ActionEvent event)
  {
    if (event.getSource().equals(num1Btn))
    {
      PAPISFactory.getServiceRequestHandler(scenarioCarIndex).sendTrainIdKeypadButtonRequest(KeyPadEnum.NO_1);
      updateButtonStatus(num1Btn);
    }
    else if (event.getSource().equals(num2Btn))
    {
      PAPISFactory.getServiceRequestHandler(scenarioCarIndex).sendTrainIdKeypadButtonRequest(KeyPadEnum.NO_2);
      updateButtonStatus(num2Btn);
    }
    else if (event.getSource().equals(num3Btn))
    {
      PAPISFactory.getServiceRequestHandler(scenarioCarIndex).sendTrainIdKeypadButtonRequest(KeyPadEnum.NO_3);
      updateButtonStatus(num3Btn);
    }
    else if (event.getSource().equals(num4Btn))
    {
      PAPISFactory.getServiceRequestHandler(scenarioCarIndex).sendTrainIdKeypadButtonRequest(KeyPadEnum.NO_4);
      updateButtonStatus(num4Btn);
    }
    else if (event.getSource().equals(num5Btn))
    {
      PAPISFactory.getServiceRequestHandler(scenarioCarIndex).sendTrainIdKeypadButtonRequest(KeyPadEnum.NO_5);
      updateButtonStatus(num5Btn);
    }
    else if (event.getSource().equals(num6Btn))
    {
      PAPISFactory.getServiceRequestHandler(scenarioCarIndex).sendTrainIdKeypadButtonRequest(KeyPadEnum.NO_6);
      updateButtonStatus(num6Btn);

    }
    else if (event.getSource().equals(num7Btn))
    {
      PAPISFactory.getServiceRequestHandler(scenarioCarIndex).sendTrainIdKeypadButtonRequest(KeyPadEnum.NO_7);
      updateButtonStatus(num7Btn);
    }
    else if (event.getSource().equals(num8Btn))
    {
      PAPISFactory.getServiceRequestHandler(scenarioCarIndex).sendTrainIdKeypadButtonRequest(KeyPadEnum.NO_8);
      updateButtonStatus(num8Btn);
    }
    else if (event.getSource().equals(num9Btn))
    {
      PAPISFactory.getServiceRequestHandler(scenarioCarIndex).sendTrainIdKeypadButtonRequest(KeyPadEnum.NO_9);
      updateButtonStatus(num9Btn);
    }
    else if (event.getSource().equals(num0Btn))
    {
      PAPISFactory.getServiceRequestHandler(scenarioCarIndex).sendTrainIdKeypadButtonRequest(KeyPadEnum.NO_0);
      updateButtonStatus(num0Btn);
    }
    else if (event.getSource().equals(kbBtn))
    {
      PAPISFactory.getServiceRequestHandler(scenarioCarIndex).sendTrainIdKeypadButtonRequest(KeyPadEnum.KB);
      updateButtonStatus(kbBtn);
    }
    else if (event.getSource().equals(clearBtn))
    {
      PAPISFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendTrainIdKeypadButtonRequest(KeyPadEnum.CLEAR);
      updateButtonStatus(clearBtn);

    }
  }

  private void updateButtonStatus(Button num1Btn2)
  {
    for (int i = 0; i < buttonList.size(); i++)
    {
      buttonList.get(i).getStyleClass().clear();
      buttonList.get(i).getStyleClass().add(ApplicationConstants.ID_UNSELECTED_CSS);
    }
    num1Btn2.getStyleClass().add(ApplicationConstants.ID_SELECTED_CSS);

  }

  @FXML
  private void onTrainIdScreenOkButtonAction(ActionEvent event)
  {
    resetTrainIdButton();
    PAPISFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendButtonClickRequest(PAPISInputs.TRAIN_ID_SCREEN_OK_BUTTON);
    PAPISFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendScreenChangeRequest(ScreenId.SYSTEM_SETTINGS_SCREEN);
  }

  private void resetTrainIdButton()
  {
    for (int i = 0; i < buttonList.size(); i++)
    {
      buttonList.get(i).getStyleClass().clear();
      buttonList.get(i).getStyleClass().add(ApplicationConstants.ID_UNSELECTED_CSS);
    }

  }

  @FXML
  private void onTrainIdScreenBackButtonAction(ActionEvent event)
  {
    resetTrainIdButton();
    PAPISFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendButtonClickRequest(PAPISInputs.TRAIN_ID_SCREEN_BACK_BUTTON);
    PAPISFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendScreenChangeRequest(ScreenId.SYSTEM_SETTINGS_SCREEN);
  }
}
