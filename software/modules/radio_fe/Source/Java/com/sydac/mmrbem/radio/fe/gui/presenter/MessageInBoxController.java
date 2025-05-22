/*
 * ================================================================== (C)
 * Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.radio.fe.gui.presenter;

import com.sydac.mmrbem.radio.fe.gui.AbstractRadioController;
import com.sydac.mmrbem.radio.fe.gui.binder.MessageScreenBinder;
import com.sydac.mmrbem.radio.fe.gui.model.MessageScreenModel;

import javafx.beans.value.ChangeListener;
import javafx.fxml.FXML;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;

public class MessageInBoxController extends AbstractRadioController
{

  @FXML
  private TextField ssiNumberLbl;

  @FXML
  private TextField statusCodeLbl;

  @FXML
  private Label statusMsgLbl;

  private MessageScreenModel messageScreenModel;

  private ChangeListener<String> messageTextListener;

  private ChangeListener<Number> inBoxMessageIdListener;

  @Override
  public void detachListeners()
  {
    messageScreenModel.getInBoxMessageText().removeListener(messageTextListener);
    messageScreenModel.getInBoxMessageId().removeListener(inBoxMessageIdListener);
  }

  @Override
  public void initializeImpl()
  {
    messageScreenModel = new MessageScreenModel(scenarioCarIndex);
    radioScreenBinders.add(new MessageScreenBinder(scenarioCarIndex, messageScreenModel));

    inBoxMessageIdListener = ((observable, oldVal, newVal) -> updateMessageId(newVal.intValue()));
    messageScreenModel.getInBoxMessageId().addListener(inBoxMessageIdListener);

    messageTextListener = ((observable, oldVal, newVal) -> updateMessageText(newVal));
    messageScreenModel.getInBoxMessageText().addListener(messageTextListener);

    updateMessageText(messageScreenModel.getInBoxMessageText().get());

    updateMessageId(messageScreenModel.getInBoxMessageId().get());

  }

  private void updateMessageId(int id)
  {
    ssiNumberLbl.setText(String.valueOf(id));

  }

  private void updateMessageText(String text)
  {
    statusMsgLbl.setText(text);
  }

}
