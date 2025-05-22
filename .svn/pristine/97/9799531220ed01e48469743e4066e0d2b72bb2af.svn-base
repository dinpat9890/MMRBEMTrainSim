/*
 * ================================================================== (C)
 * Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.radio.fe.gui.presenter;

import static com.sydac.project.runtimedata.ProjectObjectConstants.RadioInputs.MESSAGE_OUTBOX_SELECTION_REQUEST;
import static com.sydac.project.runtimedata.ProjectObjectConstants.RadioInputs.SSI_NUMBER_SELECTION_REQUEST;
import static com.sydac.project.runtimedata.ProjectObjectConstants.RadioInputs.STATUS_CODE_SELECTION_REQUEST;

import com.sydac.gui.i18n.CommonStrings;
import com.sydac.mmrbem.radio.common.state.ApplicationConstants;
import com.sydac.mmrbem.radio.fe.base.RadioFactory;
import com.sydac.mmrbem.radio.fe.gui.AbstractRadioController;
import com.sydac.mmrbem.radio.fe.gui.binder.MessageScreenBinder;
import com.sydac.mmrbem.radio.fe.gui.model.MessageScreenModel;

import javafx.beans.value.ChangeListener;
import javafx.fxml.FXML;
import javafx.scene.control.Label;
import javafx.scene.input.MouseEvent;
import javafx.scene.input.TouchEvent;

public class MessageOutBoxController extends AbstractRadioController
{

  @FXML
  private Label ssiNumberLbl;

  @FXML
  private Label statusCodeLbl;

  @FXML
  private Label statusMsgLbl;

  private MessageScreenModel messageScreenModel;

  private ChangeListener<String> messageTextListener;

  private ChangeListener<String> statusCodeListener;

  private ChangeListener<Number> OutBoxMessageIdListener;

  @Override
  public void detachListeners()
  {
    messageScreenModel.getOutBoxMessageCode().removeListener(statusCodeListener);
    messageScreenModel.getOutBoxMessageText().removeListener(messageTextListener);
    messageScreenModel.getOutBoxMessageId().removeListener(OutBoxMessageIdListener);
  }

  @Override
  public void initializeImpl()
  {
    messageScreenModel = new MessageScreenModel(scenarioCarIndex);
    radioScreenBinders.add(new MessageScreenBinder(scenarioCarIndex, messageScreenModel));

    OutBoxMessageIdListener = ((observable, oldVal, newVal) -> updateMessageId(newVal.intValue()));
    messageScreenModel.getOutBoxMessageId().addListener(OutBoxMessageIdListener);

    messageTextListener = ((observable, oldVal, newVal) -> updateMessageText(newVal));
    messageScreenModel.getOutBoxMessageText().addListener(messageTextListener);

    statusCodeListener = ((observable, oldVal, newVal) -> updateMessageCode(newVal));
    messageScreenModel.getOutBoxMessageCode().addListener(statusCodeListener);

    updateMessageText(messageScreenModel.getOutBoxMessageText().get());

    updateMessageId(messageScreenModel.getOutBoxMessageId().get());

    updateMessageCode(messageScreenModel.getOutBoxMessageCode().get());

  }

  private void updateMessageCode(String code)
  {
    statusCodeLbl.setText(code);
  }

  private void updateMessageId(int id)
  {

    ssiNumberLbl.setText(id == 0 ? CommonStrings.BLANK : String.valueOf(id));

  }

  private void updateMessageText(String text)
  {
    statusMsgLbl.setText(text);
  }

  @FXML
  void onSsiMousePressedAction(MouseEvent event)
  {
    if (!ApplicationConstants.IS_TOUCH_ENABLED)
    {
      setButtonState(SSI_NUMBER_SELECTION_REQUEST);
    }

  }

  @FXML
  void onSsiMouseReleasedAction(MouseEvent event)
  {
    if (!ApplicationConstants.IS_TOUCH_ENABLED)
    {
      resetButtonState(SSI_NUMBER_SELECTION_REQUEST);
    }
  }

  @FXML
  void onSsiTouchPressedAction(TouchEvent event)
  {
    if (ApplicationConstants.IS_TOUCH_ENABLED)
    {
      setButtonState(SSI_NUMBER_SELECTION_REQUEST);
    }
  }

  @FXML
  void onSsiTouchReleasedAction(TouchEvent event)
  {
    if (ApplicationConstants.IS_TOUCH_ENABLED)
    {
      resetButtonState(SSI_NUMBER_SELECTION_REQUEST);
    }
  }

  @FXML
  void onStatusCodeMousePressedAction(MouseEvent event)
  {
    if (!ApplicationConstants.IS_TOUCH_ENABLED)
    {
      setButtonState(STATUS_CODE_SELECTION_REQUEST);
    }

  }

  @FXML
  void onStatusCodeMouseReleasedAction(MouseEvent event)
  {
    if (!ApplicationConstants.IS_TOUCH_ENABLED)
    {
      resetButtonState(STATUS_CODE_SELECTION_REQUEST);
    }
  }

  @FXML
  void onStatusCodeTouchPressedAction(TouchEvent event)
  {
    if (ApplicationConstants.IS_TOUCH_ENABLED)
    {
      setButtonState(STATUS_CODE_SELECTION_REQUEST);
    }
  }

  @FXML
  void onStatusCodeTouchReleasedAction(TouchEvent event)
  {
    if (ApplicationConstants.IS_TOUCH_ENABLED)
    {
      resetButtonState(STATUS_CODE_SELECTION_REQUEST);
    }
  }

  @FXML
  void onStatusMsgMousePressedAction(MouseEvent event)
  {
    if (!ApplicationConstants.IS_TOUCH_ENABLED)
    {
      setButtonState(MESSAGE_OUTBOX_SELECTION_REQUEST);
    }
  }

  @FXML
  void onStatusMsgMouseReleasedAction(MouseEvent event)
  {
    if (!ApplicationConstants.IS_TOUCH_ENABLED)
    {
      resetButtonState(MESSAGE_OUTBOX_SELECTION_REQUEST);
    }
  }

  @FXML
  void onStatusMsgTouchPressedAction(TouchEvent event)
  {
    if (ApplicationConstants.IS_TOUCH_ENABLED)
    {
      setButtonState(MESSAGE_OUTBOX_SELECTION_REQUEST);
    }
  }

  @FXML
  void onStatusMsgTouchReleasedAction(TouchEvent event)
  {
    if (ApplicationConstants.IS_TOUCH_ENABLED)
    {
      resetButtonState(MESSAGE_OUTBOX_SELECTION_REQUEST);
    }
  }

  private void resetButtonState(String key)
  {

    RadioFactory.getServiceRequestHandler(scenarioCarIndex).sendRequest(key,
        ApplicationConstants.RESET_VALUE);

  }

  private void setButtonState(String key)
  {

    RadioFactory.getServiceRequestHandler(scenarioCarIndex).sendRequest(key, ApplicationConstants.SET_VALUE);

  }

}
