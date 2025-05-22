/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/

/**
 * @author ext-naikp
 **/

package com.sydac.mmrbem.radio.fe.gui.presenter;

import static com.sydac.project.runtimedata.ProjectObjectConstants.RadioInputs.BTN_0_REQUEST;
import static com.sydac.project.runtimedata.ProjectObjectConstants.RadioInputs.BTN_1_REQUEST;
import static com.sydac.project.runtimedata.ProjectObjectConstants.RadioInputs.BTN_2_ABC_REQUEST;
import static com.sydac.project.runtimedata.ProjectObjectConstants.RadioInputs.BTN_3_DEF_REQUEST;
import static com.sydac.project.runtimedata.ProjectObjectConstants.RadioInputs.BTN_4_GHI_REQUEST;
import static com.sydac.project.runtimedata.ProjectObjectConstants.RadioInputs.BTN_5_JKL_REQUEST;
import static com.sydac.project.runtimedata.ProjectObjectConstants.RadioInputs.BTN_6_MNO_REQUEST;
import static com.sydac.project.runtimedata.ProjectObjectConstants.RadioInputs.BTN_7_PQRS_REQUEST;
import static com.sydac.project.runtimedata.ProjectObjectConstants.RadioInputs.BTN_8_TUV_REQUEST;
import static com.sydac.project.runtimedata.ProjectObjectConstants.RadioInputs.BTN_9_WXYZ_REQUEST;
import static com.sydac.project.runtimedata.ProjectObjectConstants.RadioInputs.BTN_HASH_REQUEST;
import static com.sydac.project.runtimedata.ProjectObjectConstants.RadioInputs.BTN_STAR_REQUEST;
import static com.sydac.project.runtimedata.ProjectObjectConstants.RadioInputs.END_CALL_BTN_REQUEST;
import static com.sydac.project.runtimedata.ProjectObjectConstants.RadioInputs.ENTER_START_CALL_BTN_REQUEST;
import static com.sydac.project.runtimedata.ProjectObjectConstants.RadioInputs.BTN_UP_ARROW_REQUEST;
import static com.sydac.project.runtimedata.ProjectObjectConstants.RadioInputs.BTN_DOWN_ARROW_REQUEST;
import com.sydac.mmrbem.radio.common.state.ApplicationConstants;
import com.sydac.mmrbem.radio.fe.base.RadioFactory;
import com.sydac.mmrbem.radio.fe.gui.AbstractRadioController;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.input.MouseEvent;
import javafx.scene.input.TouchEvent;

/**
 * Provides common infrastructure like grid pane containers and labels for Key
 * Pad Panel This class used for All Panel For main screen only number keys and
 * start call and end call button are supported
 * 
 * @author ext-tambet
 */
public class KeyPadPanelController extends AbstractRadioController
{

  @FXML
  private Button buttonTwo;

  @FXML
  private Button buttonOne;

  @FXML
  private Button buttonThree;

  @FXML
  private Button buttonFour;

  @FXML
  private Button buttonFive;

  @FXML
  private Button buttonSix;

  @FXML
  private Button buttonSeven;

  @FXML
  private Button buttonEight;

  @FXML
  private Button buttonNine;

  @FXML
  private Button asteriskButton;

  @FXML
  private Button buttonZero;

  @FXML
  private Button hashButton;

  @FXML
  private Button leftButton;

  @FXML
  private Button spaceButton;

  @FXML
  private Button upButton;

  @FXML
  private Button rightButton;

  @FXML
  private Button downButton;

  @FXML
  private Button enterButton;

  @FXML
  void onMousePressedAction(MouseEvent event)
  {
    if (!ApplicationConstants.IS_TOUCH_ENABLED)
    {
      setButtonState((Button)event.getSource(), event.getClickCount());
    }
  }

  private String getButtonKey(Button button)
  {
    String key = null;
    if (button.equals(buttonOne))
    {
      key = BTN_1_REQUEST;
    }
    else if (button.equals(buttonTwo))
    {
      key = BTN_2_ABC_REQUEST;
    }

    else if (button.equals(buttonThree))
    {
      key = BTN_3_DEF_REQUEST;
    }
    else if (button.equals(buttonFour))
    {
      key = BTN_4_GHI_REQUEST;
    }
    else if (button.equals(buttonFive))
    {
      key = BTN_5_JKL_REQUEST;
    }
    else if (button.equals(buttonSix))
    {
      key = BTN_6_MNO_REQUEST;
    }
    else if (button.equals(buttonSeven))
    {
      key = BTN_7_PQRS_REQUEST;
    }
    else if (button.equals(buttonEight))
    {
      key = BTN_8_TUV_REQUEST;
    }
    else if (button.equals(buttonNine))
    {
      key = BTN_9_WXYZ_REQUEST;
    }
    else if (button.equals(buttonZero))
    {
      key = BTN_0_REQUEST;
    }
    else if (button.equals(asteriskButton))
    {
      key = BTN_STAR_REQUEST;
    }
    else if (button.equals(hashButton))
    {
      key = BTN_HASH_REQUEST;
    }

    return key;
  }

  @FXML
  void onMouseReleasedAction(MouseEvent event)
  {
    if (!ApplicationConstants.IS_TOUCH_ENABLED)
    {
      resetButtonState((Button)event.getSource());
    }
  }

  @FXML
  void onTouchPressedAction(TouchEvent event)
  {
    if (ApplicationConstants.IS_TOUCH_ENABLED)
    {
      setButtonState((Button)event.getSource(), event.getTouchCount());
    }
  }

  private void setButtonState(Button button, int count)
  {
    String key = getButtonKey(button);
    if (key != null)
    {
      RadioFactory.getServiceRequestHandler(scenarioCarIndex).sendRequest(key, count);
    }
  }

  @FXML
  void onTouchReleasedAction(TouchEvent event)
  {
    if (ApplicationConstants.IS_TOUCH_ENABLED)
    {
      resetButtonState((Button)event.getSource());
    }
  }

  private void resetButtonState(Button button)
  {
    String key = getButtonKey(button);
    if (key != null)
    {
      RadioFactory.getServiceRequestHandler(scenarioCarIndex).sendRequest(key,
          ApplicationConstants.RESET_VALUE);
    }
  }

  @FXML
  void onClickLeftButtonAction(ActionEvent event)
  {}

  @FXML
  void onClickRightButtonAction(ActionEvent event)
  {

  }

  @FXML
  void onClickSpaceButtonAction(ActionEvent event)
  {

  }

  @FXML
  void onClickUpButtonAction(ActionEvent event)
  {
    RadioFactory.getServiceRequestHandler(scenarioCarIndex).sendButtonClickRequest(BTN_UP_ARROW_REQUEST);
  }

  @FXML
  void onClickDownButtonAction(ActionEvent event)
  {
    RadioFactory.getServiceRequestHandler(scenarioCarIndex).sendButtonClickRequest(BTN_DOWN_ARROW_REQUEST);
  }

  @FXML
  void onEndCallBtnAction(ActionEvent event)
  {
    RadioFactory.getServiceRequestHandler(scenarioCarIndex).sendButtonClickRequest(END_CALL_BTN_REQUEST);

  }

  @FXML
  void onClickEnterButtonAction(ActionEvent event)
  {
    RadioFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendButtonClickRequest(ENTER_START_CALL_BTN_REQUEST);
  }

  @Override
  public void detachListeners()
  {

  }

  @Override
  public void initializeImpl()
  {

  }

}
