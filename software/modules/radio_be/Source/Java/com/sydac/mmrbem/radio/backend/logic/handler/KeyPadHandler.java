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

import java.util.Date;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.sydac.foundation.IPropertySetter;
import com.sydac.foundation.PropertyKey;
import com.sydac.gui.i18n.CommonStrings;
import com.sydac.mmrbem.radio.backend.comms.CommsBinding;
import com.sydac.mmrbem.radio.backend.logic.AbstractFunctionalLogic;
import com.sydac.mmrbem.radio.backend.logic.SharedDataModel;
import com.sydac.mmrbem.radio.backend.logic.annotation.FunctionalLogicHandler;
import com.sydac.mmrbem.radio.backend.radiointercom.io.models.IRadioIntercomOutputsModel;
import com.sydac.mmrbem.radio.backend.radiointercom.properties.IRadioIntercomInputProperties;
import com.sydac.mmrbem.radio.common.ScreenId;
import com.sydac.mmrbem.radio.common.data.MessageDO;
import com.sydac.mmrbem.radio.common.io.properties.IAppInputsKeyPadPanelProperties;
import com.sydac.mmrbem.radio.common.io.properties.IAppInputsMessageScreenProperties;
import com.sydac.mmrbem.radio.common.io.properties.IAppOutputCallInfoProperties;
import com.sydac.mmrbem.radio.common.io.properties.IAppOutputMessageScreenProperties;
import com.sydac.mmrbem.radio.common.state.ApplicationConstants;
import com.sydac.mmrbem.radio.common.state.KeyPadEnum;
import com.sydac.mmrbem.radio.common.state.KeyPadKeysMap;
import com.sydac.radio.proto.RadioProtos.OutBoxMessage;

/**
 * This handler class is used for key pad input logic This handle will be used
 * for all screen For main screen only number keys and start call and end call
 * button are supported
 * 
 * @author ext-tambet
 *
 */
@Service
@FunctionalLogicHandler(arguments = { CommsBinding.class, SharedDataModel.class })
public class KeyPadHandler extends AbstractFunctionalLogic
{
  private String inputSsiId = CommonStrings.BLANK;

  private String outBoxMsgSsiId = CommonStrings.BLANK;

  private String outBoxStatusCode = CommonStrings.BLANK;

  private String outBoxMsgText = CommonStrings.BLANK;

  private int outBoxEditType = ApplicationConstants.OUTBOX_INPUT_SSI;

  @Autowired
  private SharedDataModel sharedDataModel;

  @Autowired
  private MessageOutBoxListScreenHandler messageOutBoxListScreenHandler;

  @Autowired
  private StartupSequenceHandler startupSequenceHandler;

  @Autowired
  private ScreenChangeHandler screenChangeHandler;

  public KeyPadHandler(CommsBinding commsBinding)
  {
    super(commsBinding, IAppInputsKeyPadPanelProperties.class, IAppInputsMessageScreenProperties.class);

  }

  @Override
  public <T> void appInputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue, int vehicleIndex)
  {

    if (vehicleIndex == getActiveVehicleIndex() && (Integer)newValue > 0
        && startupSequenceHandler.isRadioPowerOn())
    {
      IPropertySetter radioIntercomInputSetter = getRadioIntercomInputSetter(getActiveVehicleIndex());
      if (IAppInputsMessageScreenProperties.SSI_NUMBER_SELECTION_REQUEST.equals(key) && (Integer)newValue > 0)
      {
        outBoxEditType = ApplicationConstants.OUTBOX_INPUT_SSI;
      }
      else if (IAppInputsMessageScreenProperties.STATUS_CODE_SELECTION_REQUEST.equals(key)
          && (Integer)newValue > 0)
      {
        outBoxEditType = ApplicationConstants.OUTBOX_STATUS_CODE;
      }
      else if (IAppInputsMessageScreenProperties.MESSAGE_OUTBOX_SELECTION_REQUEST.equals(key)
          && (Integer)newValue > 0)
      {
        outBoxEditType = ApplicationConstants.OUTBOX_MSG_BOX;
      }
      else if (IAppInputsKeyPadPanelProperties.END_CALL_BTN_REQUEST.equals(key))
      {
        if (sharedDataModel.getScreenId() == ScreenId.MAIN_SCREEN.getId())
        {
          sendPulseRequest(radioIntercomInputSetter, IRadioIntercomInputProperties.RADIO_CAB_CANCEL,
              ApplicationConstants.SET_VALUE, ApplicationConstants.RESET_VALUE);
          inputSsiId = CommonStrings.BLANK;
          setApplicationOutputsProperty(IAppOutputCallInfoProperties.INPUT_SSI_ID,
              ApplicationConstants.RESET_VALUE);
        }
        else if (sharedDataModel.getScreenId() == ScreenId.CONTACT_SCREEN.getId())
        {
          screenChangeHandler.requestScreenChange(ScreenId.MAIN_SCREEN);
        }
        else if (sharedDataModel.getScreenId() == ScreenId.OUTBOX_MESSAGE_SCREEN.getId())
        {
          screenChangeHandler.requestScreenChange(ScreenId.MESSAGE_OUTBOX_LIST_SCREEN);

        }
        else if (sharedDataModel.getScreenId() == ScreenId.INBOX_MESSAGE_SCREEN.getId())
        {
          screenChangeHandler.requestScreenChange(ScreenId.MESSAGE_INBOX_LIST_SCREEN);

        }
        else if (sharedDataModel.getScreenId() == ScreenId.MESSAGE_INBOX_LIST_SCREEN.getId())
        {
          screenChangeHandler.requestScreenChange(ScreenId.MESSAGE_SCREEN);

        }
        else if (sharedDataModel.getScreenId() == ScreenId.MESSAGE_OUTBOX_LIST_SCREEN.getId())
        {
          screenChangeHandler.requestScreenChange(ScreenId.MESSAGE_SCREEN);

        }
        else if (sharedDataModel.getScreenId() == ScreenId.MESSAGE_SCREEN.getId())
        {
          screenChangeHandler.requestScreenChange(ScreenId.MAIN_SCREEN);

        } else if (sharedDataModel.getScreenId() == ScreenId.ALARM_SCREEN.getId())
        {
          screenChangeHandler.requestScreenChange(ScreenId.MAIN_SCREEN);

        }
      }
      else if (IAppInputsKeyPadPanelProperties.ENTER_START_CALL_BTN_REQUEST.equals(key)
          && sharedDataModel.getScreenId() == ScreenId.MAIN_SCREEN.getId())
      {
        IRadioIntercomOutputsModel model = (IRadioIntercomOutputsModel)getRadioIntercomOutputsModels(
            getActiveVehicleIndex());
        if (model.getCabScc() == 0)
        {
          sendPulseRequest(radioIntercomInputSetter, IRadioIntercomInputProperties.RADIO_FULL_DUPLEX_CALL_REQ,
              ApplicationConstants.RESET_VALUE, getInputSsiId());
        }else if (model.getCabScc() == 1)
        {
         
          sendPulseRequest(radioIntercomInputSetter, IRadioIntercomInputProperties.RADIO_FULL_DUPLEX_CALL_REQ,
              ApplicationConstants.RESET_VALUE, getInputSsiId());
        }
        else
        {
          sendPulseRequest(radioIntercomInputSetter, IRadioIntercomInputProperties.RADIO_CAB_INTERCOM,
              ApplicationConstants.SET_VALUE, ApplicationConstants.RESET_VALUE);
        }

      }
      else if (IAppInputsKeyPadPanelProperties.ENTER_START_CALL_BTN_REQUEST.equals(key)
          && sharedDataModel.getScreenId() == ScreenId.OUTBOX_MESSAGE_SCREEN.getId())
      {

        int msgId = getOutBoxMsgSsiId(); // $NON-NLS-1$//$NON-NLS-2$
        messageOutBoxListScreenHandler
            .addMessage(new MessageDO(outBoxMsgText, msgId, outBoxStatusCode, new Date().getTime()));

      }
      else
      {

        if (sharedDataModel.getScreenId() == ScreenId.MAIN_SCREEN.getId()
            || outBoxEditType == ApplicationConstants.OUTBOX_INPUT_SSI
                && sharedDataModel.getScreenId() == ScreenId.OUTBOX_MESSAGE_SCREEN.getId())
        {
          if ((Integer)newValue > KeyPadKeysMap.CLICK_COUNT_ONE
              || IAppInputsKeyPadPanelProperties.BTN_STAR_REQUEST.equals(key)
              || IAppInputsKeyPadPanelProperties.BTN_HASH_REQUEST.equals(key))
          {
            // for main screen only numeric values allowed
            return;
          }
        }
        @SuppressWarnings("unchecked")
        KeyPadEnum keyMap = KeyPadEnum.valueOf((PropertyKey<Integer>)key);

        if (keyMap != null && (Integer)newValue > 0 && !keyMap.getClickCountAndCharMap().isEmpty())
        {
          String character = keyMap.getClickCountAndCharMap().get(newValue);
          if (character != null)
          {
            if (sharedDataModel.getScreenId() == ScreenId.MAIN_SCREEN.getId())
            {
              if (inputSsiId.trim().length() < ApplicationConstants.SSI_ID_LENGTH)
              {
                inputSsiId += character;
              }

              setApplicationOutputsProperty(IAppOutputCallInfoProperties.INPUT_SSI_ID, getInputSsiId());

            }
            else if (sharedDataModel.getScreenId() == ScreenId.OUTBOX_MESSAGE_SCREEN.getId())
            {
              if (outBoxMsgSsiId.trim().length() < ApplicationConstants.SSI_ID_LENGTH
                  && outBoxEditType == ApplicationConstants.OUTBOX_INPUT_SSI)
              {
                outBoxMsgSsiId += character;
              }
              else if (outBoxEditType == ApplicationConstants.OUTBOX_STATUS_CODE)
              {
                outBoxStatusCode += character;
              }
              else if (outBoxEditType == ApplicationConstants.OUTBOX_MSG_BOX)
              {
                outBoxMsgText += character;
              }

              updateOutBoxMsg();

            }

          }
        }
      }
    }

  }

  private void updateOutBoxMsg()
  {
    OutBoxMessage.Builder message = OutBoxMessage.newBuilder();

    int msgId = getOutBoxMsgSsiId();

    message.setMessageId(msgId);
    message.setMessageText(outBoxMsgText);
    message.setStatusCode(outBoxStatusCode);

    setApplicationOutputsProperty(IAppOutputMessageScreenProperties.OUTBOX_MESSAGE,
        message.build().toByteArray());
  }

  private int getOutBoxMsgSsiId()
  {
    return Integer.parseInt(outBoxMsgSsiId.trim().equals(CommonStrings.BLANK) ? "0" : outBoxMsgSsiId.trim());
  }

  private int getInputSsiId()
  {
    return inputSsiId.trim().equals(CommonStrings.BLANK) ? 0 : Integer.parseInt(inputSsiId.trim());
  }

  @Override
  public void detachListeners()
  {
    super.detachListeners();
    inputSsiId = CommonStrings.BLANK;
    outBoxMsgSsiId = CommonStrings.BLANK;
    outBoxStatusCode = CommonStrings.BLANK;
    outBoxMsgText = CommonStrings.BLANK;
  }

  public void clearOuBoxMsg()
  {
    outBoxMsgSsiId = CommonStrings.BLANK;
    outBoxStatusCode = CommonStrings.BLANK;
    outBoxMsgText = CommonStrings.BLANK;
    updateOutBoxMsg();
  }

}
