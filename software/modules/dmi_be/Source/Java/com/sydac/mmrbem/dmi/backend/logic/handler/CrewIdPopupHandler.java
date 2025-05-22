/*
 * ================================================================== (C)
 * Copyright 2020 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * ==================================================================
 */
package com.sydac.mmrbem.dmi.backend.logic.handler;

import org.springframework.stereotype.Service;

import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.dmi.backend.comms.CommsBinding;
import com.sydac.mmrbem.dmi.backend.logic.AbstractFunctionalLogic;
import com.sydac.mmrbem.dmi.backend.logic.annotation.FunctionalLogicHandler;
import com.sydac.mmrbem.dmi.common.io.properties.IAppInputsCrewIdPopupProperties;
import com.sydac.mmrbem.dmi.common.io.properties.IAppOutputsProperties;
import com.sydac.mmrbem.dmi.common.state.DMIConstants;

/**
 * This handler class is responsible for managing Crew Id pop up.
 * 
 * @author potdars
 */
@Service
@FunctionalLogicHandler(arguments = { CommsBinding.class })
public class CrewIdPopupHandler extends AbstractFunctionalLogic
{

  private String inputCrewNumber;

  public CrewIdPopupHandler(CommsBinding commsBinding)
  {
    super(commsBinding, IAppInputsCrewIdPopupProperties.class);
    this.inputCrewNumber = "";
  }

  @Override
  public <T> void appInputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue, int vehicleIndex)
  {

    if (IAppInputsCrewIdPopupProperties.CREW_ID_POPUP_SCREEN_CLEAR_BUTTON_PRESSED.equals(key)
        && (Integer)newValue > 0)
    {
      clearCrewNumber();
    }
    else if ((IAppInputsCrewIdPopupProperties.CREW_ID_POPUP_SCREEN_CANCEL_BUTTON_PRESSED.equals(key))
        && (Integer)newValue > 0)
    {
      setCrewIdPanelCancelRequest();
    }
    else if (IAppInputsCrewIdPopupProperties.CREW_ID_POPUP_SCREEN_VALIDATE_BUTTON_PRESSED.equals(key)
        && (Integer)newValue > 0)
    {

      if (!isValidCrewNumber())
      {
        setApplicationOutputsProperty(IAppOutputsProperties.CREW_NUMBER, "".getBytes());
      }
      else
      {

        StringBuilder crewNumber = new StringBuilder(DMIConstants.CREW_PREFIX);

        for (int i = 0; i < 3 - inputCrewNumber.trim().length(); i++)
        {
          crewNumber.append("0");
        }

        crewNumber.append(inputCrewNumber);

        setApplicationOutputsProperty(IAppOutputsProperties.CREW_NUMBER, crewNumber.toString().getBytes());
      }

      clearCrewNumber();

      hideCrewPanel();

    }
    else if ((Integer)newValue > 0)
    {
      recordInputCrewNumber(key);

      setKeyPadInputCrewNumber();

    }
  }

  private void hideCrewPanel()
  {
    setApplicationOutputsProperty(IAppOutputsProperties.CREW_ID_PANEL_STATUS, false);
  }

  private void setKeyPadInputCrewNumber()
  {
    setApplicationOutputsProperty(IAppOutputsProperties.CREW_ID_PANEL_ENTERED_NUMBER,
        inputCrewNumber.getBytes());
  }

  private boolean isValidCrewNumber()
  {
    if ("".equals(inputCrewNumber.trim()))
    {
      return false;
    }

    int inputCrewNumber1 = Integer.parseInt(inputCrewNumber.trim());

    return inputCrewNumber1 > 0 && inputCrewNumber1 < 1000;
  }

  private void setCrewIdPanelCancelRequest()
  {
    inputCrewNumber = "";
    setKeyPadInputCrewNumber();
    hideCrewPanel();
  }

  private void clearCrewNumber()
  {
    inputCrewNumber = "";
    setKeyPadInputCrewNumber();
  }

  private <T> void recordInputCrewNumber(PropertyKey<T> key)
  {

    if (inputCrewNumber.trim().length() < 3)
    {
      if (IAppInputsCrewIdPopupProperties.CREW_ID_POPUP_SCREEN_BUTTON_0_PRESSED.equals(key)
          && !"".equals(inputCrewNumber))
      {
        inputCrewNumber += "0";
      }
      else if (IAppInputsCrewIdPopupProperties.CREW_ID_POPUP_SCREEN_BUTTON_1_PRESSED.equals(key))
      {
        inputCrewNumber += "1";
      }
      else if (IAppInputsCrewIdPopupProperties.CREW_ID_POPUP_SCREEN_BUTTON_2_PRESSED.equals(key))
      {
        inputCrewNumber += "2";
      }
      else if (IAppInputsCrewIdPopupProperties.CREW_ID_POPUP_SCREEN_BUTTON_3_PRESSED.equals(key))
      {
        inputCrewNumber += "3";
      }
      else if (IAppInputsCrewIdPopupProperties.CREW_ID_POPUP_SCREEN_BUTTON_4_PRESSED.equals(key))
      {
        inputCrewNumber += "4";
      }
      else if (IAppInputsCrewIdPopupProperties.CREW_ID_POPUP_SCREEN_BUTTON_5_PRESSED.equals(key))
      {
        inputCrewNumber += "5";
      }
      else if (IAppInputsCrewIdPopupProperties.CREW_ID_POPUP_SCREEN_BUTTON_6_PRESSED.equals(key))
      {
        inputCrewNumber += "6";
      }
      else if (IAppInputsCrewIdPopupProperties.CREW_ID_POPUP_SCREEN_BUTTON_7_PRESSED.equals(key))
      {
        inputCrewNumber += "7";
      }
      else if (IAppInputsCrewIdPopupProperties.CREW_ID_POPUP_SCREEN_BUTTON_8_PRESSED.equals(key))
      {
        inputCrewNumber += "8";
      }
      else if (IAppInputsCrewIdPopupProperties.CREW_ID_POPUP_SCREEN_BUTTON_9_PRESSED.equals(key))
      {
        inputCrewNumber += "9";
      }
    }
  }

}