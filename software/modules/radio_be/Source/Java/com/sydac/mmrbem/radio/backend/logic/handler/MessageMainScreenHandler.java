/*
 * ==================================================================
 * 
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.radio.backend.logic.handler;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.radio.backend.comms.CommsBinding;
import com.sydac.mmrbem.radio.backend.logic.AbstractFunctionalLogic;
import com.sydac.mmrbem.radio.backend.logic.SharedDataModel;
import com.sydac.mmrbem.radio.backend.logic.annotation.FunctionalLogicHandler;
import com.sydac.mmrbem.radio.backend.radiointercom.properties.IRadioIntercomOutputProperties;
import com.sydac.mmrbem.radio.common.ScreenId;
import com.sydac.mmrbem.radio.common.io.properties.IAppInputsKeyPadPanelProperties;
import com.sydac.mmrbem.radio.common.io.properties.IAppInputsMessageScreenProperties;
import com.sydac.mmrbem.radio.common.io.properties.IAppOutputMessageScreenProperties;
import com.sydac.mmrbem.radio.common.state.ApplicationConstants;

/**
 * This handler class is used for Message Logic
 * 
 * @author ext-tambet
 *
 */
@Service
@FunctionalLogicHandler(arguments = { CommsBinding.class, SharedDataModel.class })
public class MessageMainScreenHandler extends AbstractFunctionalLogic implements IScreenChangeListener
{

  private int selectedBtn = ApplicationConstants.NO_BUTTON;

  @Autowired
  private ScreenChangeHandler screenChangeHandler;

  @Autowired
  private SharedDataModel sharedDataModel;

  public MessageMainScreenHandler(CommsBinding commsBinding)
  {
    super(commsBinding, IRadioIntercomOutputProperties.class, IAppInputsMessageScreenProperties.class,
        IAppInputsKeyPadPanelProperties.class);

  }

  @Override
  public <T> void appInputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue, int vehicleIndex)
  {

    if (IAppInputsMessageScreenProperties.MESSAGE_INBOX_BTN_REQUEST.equals(key) && (Integer)newValue > 0)
    {
      selectedBtn = ApplicationConstants.INBOX;
      setSelectedBtn();
    }

    else if (IAppInputsMessageScreenProperties.MESSAGE_OUTBOX_BTN_REQUEST.equals(key)
        && (Integer)newValue > 0)
    {
      selectedBtn = ApplicationConstants.OUTBOX;
      setSelectedBtn();
    }
    else if (IAppInputsKeyPadPanelProperties.BTN_UP_ARROW_REQUEST.equals(key) && (Integer)newValue > 0)
    {
      if (selectedBtn == ApplicationConstants.OUTBOX)
      {
        selectedBtn = ApplicationConstants.INBOX;
      }
      setSelectedBtn();
    }
    else if (IAppInputsKeyPadPanelProperties.BTN_DOWN_ARROW_REQUEST.equals(key) && (Integer)newValue > 0)
    {
      if (selectedBtn == ApplicationConstants.INBOX)
      {
        selectedBtn = ApplicationConstants.OUTBOX;
      }
      setSelectedBtn();
    }
    else if (IAppInputsKeyPadPanelProperties.ENTER_START_CALL_BTN_REQUEST.equals(key) && (Integer)newValue > 0
        && sharedDataModel.getScreenId() == ScreenId.MESSAGE_SCREEN.getId())
    {
      if (selectedBtn == ApplicationConstants.INBOX)
      {
        screenChangeHandler.requestScreenChange(ScreenId.MESSAGE_INBOX_LIST_SCREEN);
      }
      else
      {
        screenChangeHandler.requestScreenChange(ScreenId.MESSAGE_OUTBOX_LIST_SCREEN);
      }
    }
  }

  private void setSelectedBtn()
  {
    setApplicationOutputsProperty(IAppOutputMessageScreenProperties.INBOX_OUTBOX_SELECTED_BTN, selectedBtn);
  }

  @Override
  public void onEnteringScreen(int screenId)
  {
    setSelectedBtn();
  }

  @Override
  public void onLeavingScreen(int screenId)
  {
    // do noting
  }

}
