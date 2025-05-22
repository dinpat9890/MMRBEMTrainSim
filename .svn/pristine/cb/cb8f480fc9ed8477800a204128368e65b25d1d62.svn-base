/*
 * ================================================================== (C)
 * Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.radio.fe.gui.presenter;

import static com.sydac.project.runtimedata.ProjectObjectConstants.RadioInputs.MESSAGE_INBOX_BTN_REQUEST;
import static com.sydac.project.runtimedata.ProjectObjectConstants.RadioInputs.MESSAGE_OUTBOX_BTN_REQUEST;

import com.sydac.mmrbem.cabscreens.fe.common.NodePseudoClassProperty;
import com.sydac.mmrbem.radio.common.state.ApplicationConstants;
import com.sydac.mmrbem.radio.fe.base.RadioFactory;
import com.sydac.mmrbem.radio.fe.gui.AbstractRadioController;
import com.sydac.mmrbem.radio.fe.gui.binder.MessageScreenBinder;
import com.sydac.mmrbem.radio.fe.gui.model.MessageScreenModel;

import javafx.beans.value.ChangeListener;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;

public class MessageMainScreenController extends AbstractRadioController
{

  @FXML
  private Button inBoxBtn;

  @FXML
  private Button outBoxBtn;

  private MessageScreenModel messageScreenModel;

  private ChangeListener<Number> selectedBtnIdListener;

  private NodePseudoClassProperty inBoxBtnProperty;

  private NodePseudoClassProperty outBoxBtnProperty;

  @Override
  public void detachListeners()
  {
    messageScreenModel.getSelectedInBoxOutBoxBtnId().removeListener(selectedBtnIdListener);
  }

  @Override
  public void initializeImpl()
  {
    messageScreenModel = new MessageScreenModel(scenarioCarIndex);
    radioScreenBinders.add(new MessageScreenBinder(scenarioCarIndex, messageScreenModel));

    inBoxBtnProperty = new NodePseudoClassProperty(inBoxBtn);
    outBoxBtnProperty = new NodePseudoClassProperty(outBoxBtn);

    selectedBtnIdListener = ((observable, oldVal,
        newVal) -> updateSelectedBtn(messageScreenModel.getSelectedInBoxOutBoxBtnId().get()));
    messageScreenModel.getSelectedInBoxOutBoxBtnId().addListener(selectedBtnIdListener);

  }

  private void updateSelectedBtn(int buttonId)
  {
    String inBoxBtnState = buttonId == ApplicationConstants.INBOX ? ApplicationConstants.SELECTED_CSS
        : ApplicationConstants.UNSELECTED_CSS;

    String outBoxBtnState = buttonId == ApplicationConstants.OUTBOX ? ApplicationConstants.SELECTED_CSS
        : ApplicationConstants.UNSELECTED_CSS;

    inBoxBtnProperty.set(inBoxBtnState);
    outBoxBtnProperty.set(outBoxBtnState);

  }

  @FXML
  void onInBoxBtnAction(ActionEvent event)
  {
    RadioFactory.getServiceRequestHandler(scenarioCarIndex).sendButtonClickRequest(MESSAGE_INBOX_BTN_REQUEST);
  }

  @FXML
  void onOutBoxBtnAction(ActionEvent event)
  {
    RadioFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendButtonClickRequest(MESSAGE_OUTBOX_BTN_REQUEST);
  }

}
