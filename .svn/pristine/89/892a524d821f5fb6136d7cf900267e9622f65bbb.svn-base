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
import com.sydac.mmrbem.radio.backend.radiointercom.properties.IRadioIntercomInputProperties;
import com.sydac.mmrbem.radio.common.ScreenId;
import com.sydac.mmrbem.radio.common.io.properties.IAppInputsPowerMenuNavPanelProperties;
import com.sydac.mmrbem.radio.common.state.ApplicationConstants;

/**
 * This handler class is used for power menu navigtion logic
 * 
 * @author ext-tambet
 *
 */
@Service
@FunctionalLogicHandler(arguments = { CommsBinding.class, SharedDataModel.class })
public class PowerMenuAndNavHandler extends AbstractFunctionalLogic
{

  @Autowired
  private ScreenChangeHandler screenChangeHandler;

  @Autowired
  private StartupSequenceHandler startupSequenceHandler;

  public PowerMenuAndNavHandler(CommsBinding commsBinding)
  {
    super(commsBinding, IAppInputsPowerMenuNavPanelProperties.class);

  }

  @Override
  public <T> void appInputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue, int vehicleIndex)
  {

    if (vehicleIndex == getActiveVehicleIndex() && (Integer)newValue > 0
        && startupSequenceHandler.isRadioPowerOn())
    {
      if (IAppInputsPowerMenuNavPanelProperties.EMERGENCY_BTN_REQUEST.equals(key))
      {
        sendPulseRequest(getRadioIntercomInputSetter(getActiveVehicleIndex()),
            IRadioIntercomInputProperties.RADIO_EMRGNCY_CALL_REQ, ApplicationConstants.RESET_VALUE,
            ApplicationConstants.SET_VALUE);
      }
      else if (IAppInputsPowerMenuNavPanelProperties.MENU_BTN_REQUEST.equals(key))
      {
        // screenChangeHandler.requestScreenChange(ScreenId.MAIN_SCREEN);
        screenChangeHandler.requestScreenChange(ScreenId.CONTACT_SCREEN);
      }
      else if (IAppInputsPowerMenuNavPanelProperties.START_MSG_BTN_REQUEST.equals(key))
      {
        screenChangeHandler.requestScreenChange(ScreenId.MESSAGE_SCREEN);
      }

    }
  }

}
