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

import com.sydac.foundation.IPropertySetter;
import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.radio.backend.comms.CommsBinding;
import com.sydac.mmrbem.radio.backend.logic.AbstractFunctionalLogic;
import com.sydac.mmrbem.radio.backend.logic.SharedDataModel;
import com.sydac.mmrbem.radio.backend.logic.annotation.FunctionalLogicHandler;
import com.sydac.mmrbem.radio.backend.radiointercom.properties.IRadioIntercomInputProperties;
import com.sydac.mmrbem.radio.common.ScreenId;
import com.sydac.mmrbem.radio.common.io.GroupName;
import com.sydac.mmrbem.radio.common.io.properties.IAppInputsCallRequestAndNavigationPanelProperties;
import com.sydac.mmrbem.radio.common.io.properties.IAppOutputCallInfoProperties;
import com.sydac.mmrbem.radio.common.state.ApplicationConstants;
import com.sydac.mmrbem.radio.common.state.CallGroup;

/**
 * This handler class is used for call request and navigation logic
 * 
 * @author ext-tambet
 *
 */
@Service
@FunctionalLogicHandler(arguments = { CommsBinding.class, SharedDataModel.class })
public class CallRequestAndNavHandler extends AbstractFunctionalLogic
{

  @Autowired
  private ScreenChangeHandler screenChangeHandler;

  @Autowired
  private StartupSequenceHandler startupSequenceHandler;

  public CallRequestAndNavHandler(CommsBinding commsBinding)
  {
    super(commsBinding, IAppInputsCallRequestAndNavigationPanelProperties.class);

  }

  @Override
  public <T> void appInputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue, int vehicleIndex)
  {

    if (vehicleIndex == getActiveVehicleIndex() && (Integer)newValue > 0
        && startupSequenceHandler.isRadioPowerOn())
    {

      IPropertySetter radioIntercomInputSetter = getRadioIntercomInputSetter(getActiveVehicleIndex());
      //Note - Commented this part as of now ,as customer dont want direct call ,just want change the chanel .
      //Moved this 2 button to CallInfoHandler.java
//      if (IAppInputsCallRequestAndNavigationPanelProperties.MAIN_GROUP_BTN_REQUEST.equals(key))
//      {
//        sendPulseRequest(radioIntercomInputSetter, IRadioIntercomInputProperties.RADIO_GROUP_CALL_REQ,
//            ApplicationConstants.RESET_VALUE, CallGroup.MAIN_GROUP_CALL.getValue());
//      }
//      else if (IAppInputsCallRequestAndNavigationPanelProperties.DEPOT_GROUP_BTN_REQUEST.equals(key))
//      {
//        sendPulseRequest(radioIntercomInputSetter, IRadioIntercomInputProperties.RADIO_GROUP_CALL_REQ,
//            ApplicationConstants.RESET_VALUE, CallGroup.DEPOT_GROUP_CALL.getValue());
//      }
//      else
      if (IAppInputsCallRequestAndNavigationPanelProperties.SHUNT_GROUP_BTN_REQUEST.equals(key))
      {
       // sendPulseRequest(radioIntercomInputSetter, IRadioIntercomInputProperties.RADIO_GROUP_CALL_REQ,
       //     ApplicationConstants.RESET_VALUE, CallGroup.SHUNT_GROUP_CALL.getValue());
        
        setApplicationOutputsProperty(IAppOutputCallInfoProperties.CALL_GROUP_NAME,  CallGroup.SHUNT_GROUP_CALL.getText().getBytes());
      }
      else if (IAppInputsCallRequestAndNavigationPanelProperties.TRAIN_GROUP_BTN_REQUEST.equals(key))
      {
        //sendPulseRequest(radioIntercomInputSetter, IRadioIntercomInputProperties.RADIO_GROUP_CALL_REQ,
        //    ApplicationConstants.RESET_VALUE, CallGroup.TRAIN_GROUP_CALL.getValue());
        setApplicationOutputsProperty(IAppOutputCallInfoProperties.CALL_GROUP_NAME,  CallGroup.TRAIN_GROUP_CALL.getText().getBytes());
      }
      else if (IAppInputsCallRequestAndNavigationPanelProperties.MSG_BTN_REQUEST.equals(key))
      {
        screenChangeHandler.requestScreenChange(ScreenId.MESSAGE_SCREEN);
      }
      else if (IAppInputsCallRequestAndNavigationPanelProperties.ALARM_BTN_REQUEST.equals(key))
      {
        screenChangeHandler.requestScreenChange(ScreenId.ALARM_SCREEN);
      }

    }
  }

}
