/*
 * ==================================================================
 * 
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.tcms.backend.logic.handler;

import java.time.Duration;
import java.time.Instant;
import java.util.Objects;

import org.springframework.stereotype.Service;

import com.sydac.common.registry.Registry;
import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.tcms.backend.comms.CommsBinding;
import com.sydac.mmrbem.tcms.backend.logic.AbstractFunctionalLogic;
import com.sydac.mmrbem.tcms.backend.logic.DateTimeModel;
import com.sydac.mmrbem.tcms.backend.logic.SharedDataModel;
import com.sydac.mmrbem.tcms.backend.logic.annotation.FunctionalLogicHandler;
import com.sydac.mmrbem.tcms.common.ScreenId;
import com.sydac.mmrbem.tcms.common.io.properties.IAppInputsLoginScreenProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppInputsProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsHeaderPanelProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsLoginPopupProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsScreenChangeProperties;
import com.sydac.mmrbem.tcms.common.state.ApplicationConstants;
import com.sydac.mmrbem.tcms.common.state.HeaderPanelTitleEnum;
import com.sydac.mmrbem.tcms.common.state.KeyPadEnum;

/**
 * This handler class is used for login screen handling.
 * 
 */
@Service
@FunctionalLogicHandler(arguments = { CommsBinding.class, SharedDataModel.class })
public class LoginScreenHandler extends AbstractFunctionalLogic
{
  private final SharedDataModel shareDataModel;

  private Integer userId;

  private Instant lastActionTime;

  private boolean messageFlag = false;

  public LoginScreenHandler(CommsBinding commsBinding, SharedDataModel aShareDataModel)
  {
    super(commsBinding, IAppInputsProperties.class);

    shareDataModel = aShareDataModel;
    userId = Registry.getInstance().getInteger(ApplicationConstants.DOMAIN_NAME,
        ApplicationConstants.USER_ID);
    this.lastActionTime = Instant.now();
    DateTimeModel.getInstance().addModelListener((oldValue, newValue) -> updateMainScreenId(), true);
  }

  private void updateMainScreenId()
  {
    Duration dur = Duration.between(lastActionTime, Instant.now());
    long seconds = dur.toMillis() / 1000L;
    if (seconds >= ApplicationConstants.TWO_SECOND && messageFlag)
    {
      setApplicationOutputsProperty(IAppOutputsScreenChangeProperties.TCMS_CURRENT_SCREEN_ID,
          ScreenId.OPERATING_SCREEN.getId());
      setApplicationOutputsProperty(IAppOutputsScreenChangeProperties.CCTV_CURRENT_SCREEN_ID,
          ScreenId.CCTV_FOUR_FEED_SCREEN.getId());
      messageFlag = false;
      setApplicationOutputsProperty(IAppOutputsLoginPopupProperties.USER_LOGGED_IN, 1);
    }
  }

  @Override
  public <T> void appInputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue, int vehicleIndex)
  {
    if (getActiveVehicleIndex() == vehicleIndex)
    {
      if (key.equals(IAppInputsLoginScreenProperties.OPERATOR_BUTTON_PRESSED) && (Integer)newValue > 0)
      {
        setApplicationOutputsProperty(IAppOutputsLoginPopupProperties.OPERATOR_BUTTON_SELECTED,
            (Integer)newValue);
      }
      else if (key.equals(IAppInputsLoginScreenProperties.KEYPAD_BUTTON_REQUEST) && (Integer)newValue > -1)
      {
        updateUserId((Integer)newValue);
      }
      else if (key.equals(IAppInputsLoginScreenProperties.LOGOUT_BUTTON_PRESSED) && (Integer)newValue > 0)
      {
        shareDataModel.setTcmsScreenId(ScreenId.LOGIN_PANEL.getId());
        shareDataModel.setTcmsPopupId(ScreenId.BLANK_SCREEN.getId());
        setApplicationOutputsProperty(IAppOutputsScreenChangeProperties.TCMS_CURRENT_SCREEN_ID,
            ScreenId.LOGIN_PANEL.getId());
        setApplicationOutputsProperty(IAppOutputsScreenChangeProperties.TCMS_POPUP_SCREEN_ID,
            ScreenId.BLANK_SCREEN.getId());
        setApplicationOutputsProperty(IAppOutputsScreenChangeProperties.CCTV_CURRENT_SCREEN_ID,
            ScreenId.LOGIN_PANEL.getId());
        setApplicationOutputsProperty(IAppOutputsScreenChangeProperties.CCTV_POPUP_SCREEN_ID,
            ScreenId.BLANK_SCREEN.getId());
        setApplicationOutputsProperty(IAppOutputsHeaderPanelProperties.LOGIN_INFO_TITLE,
            HeaderPanelTitleEnum.EMPTY.getValue());
        setApplicationOutputsProperty(IAppOutputsLoginPopupProperties.USER_LOGGED_IN, 0);
      }
    }
  }

  private void updateUserId(Integer keyPress)
  {
    switch (KeyPadEnum.valueOf(keyPress))
    {
    case DELETE:
      removeUserIdDigit();
      break;
    case CLEAR:
      shareDataModel.setUserId(ApplicationConstants.BLANK);
      setApplicationOutputsProperty(IAppOutputsLoginPopupProperties.USER_ID,
          ApplicationConstants.BLANK.getBytes());
      break;
    case ENTER:
      validateLoginUserId();
      break;
    default:
      updateUserIdText(keyPress);
      break;
    }
  }

  private void validateLoginUserId()
  {
    if (shareDataModel.getUserId().length() == ApplicationConstants.USER_ID_LENGTH
        && Objects.equals(Integer.valueOf(shareDataModel.getUserId()), userId))
    {
      setApplicationOutputsProperty(IAppOutputsHeaderPanelProperties.LOGIN_INFO_TITLE,
          HeaderPanelTitleEnum.WELCOME.getValue());
      lastActionTime = Instant.now();
      messageFlag = true;
      setApplicationOutputsProperty(IAppOutputsLoginPopupProperties.USER_LOGGED_IN, 1);
      setApplicationOutputsProperty(IAppOutputsLoginPopupProperties.OPERATOR_BUTTON_SELECTED, 0);
    }
    else
    {
      setApplicationOutputsProperty(IAppOutputsHeaderPanelProperties.LOGIN_INFO_TITLE,
          HeaderPanelTitleEnum.ACCESS_DENIED.getValue());
    }
    setApplicationOutputsProperty(IAppOutputsScreenChangeProperties.TCMS_POPUP_SCREEN_ID,
        ScreenId.BLANK_SCREEN.getId());
    setApplicationOutputsProperty(IAppOutputsScreenChangeProperties.CCTV_POPUP_SCREEN_ID,
        ScreenId.BLANK_SCREEN.getId());
    shareDataModel.setUserId(ApplicationConstants.BLANK);
  }

  private void updateUserIdText(Integer keyPress)
  {
    if (shareDataModel.getUserId().length() < ApplicationConstants.DIGIT_LENGTH)
    {
      String id = shareDataModel.getUserId().concat(String.valueOf(keyPress));
      setApplicationOutputsProperty(IAppOutputsLoginPopupProperties.USER_ID, id.getBytes());
      shareDataModel.setUserId(id);
    }
  }

  private void removeUserIdDigit()
  {
    if (shareDataModel.getUserId().length() > 0)
    {
      String id = shareDataModel.getUserId();
      id = id.substring(0, id.length() - 1);
      setApplicationOutputsProperty(IAppOutputsLoginPopupProperties.USER_ID,
          (id.equals(ApplicationConstants.BLANK) ? "0" : id).getBytes()); //$NON-NLS-1$
      shareDataModel.setUserId(id);
    }
  }
}
