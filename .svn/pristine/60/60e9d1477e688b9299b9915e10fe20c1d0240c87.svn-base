/*
 * ==================================================================
 *
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *
 * ==================================================================
 */
package com.sydac.mmrbem.papis.backend.logic.handler;

import java.util.HashMap;
import java.util.Map;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.papis.backend.comms.CommsBinding;
import com.sydac.mmrbem.papis.backend.logic.AbstractFunctionalLogic;
import com.sydac.mmrbem.papis.backend.logic.SharedDataModel;
import com.sydac.mmrbem.papis.backend.logic.annotation.FunctionalLogicHandler;
import com.sydac.mmrbem.papis.common.ScreenId;
import com.sydac.mmrbem.papis.common.data.MultiplePecuCallModel;
import com.sydac.mmrbem.papis.common.io.properties.IAppInputsPassengerAlarmScreenProperties;
import com.sydac.mmrbem.papis.common.io.properties.IAppOutputsPassengerAlarmScreenProperties;
import com.sydac.mmrbem.papis.common.io.properties.IIntercomInputsProperties;
import com.sydac.mmrbem.papis.common.io.properties.IIntercomOutputsProperties;
import com.sydac.mmrbem.papis.common.io.properties.IOhpOutputsProperties;
import com.sydac.mmrbem.papis.common.protos.PAPISProtos;
import com.sydac.mmrbem.papis.common.state.ApplicationConstants;
import com.sydac.mmrbem.papis.common.state.MultiplePecuCallIdEnum;

import javafx.beans.property.ListProperty;
import javafx.beans.property.SimpleListProperty;
import javafx.collections.FXCollections;

/**
 * This handler class is used for handling Passenger Emergency Alarm Screen (PC
 * or PECU)
 * 
 */
@Service
@FunctionalLogicHandler(arguments = { CommsBinding.class, SharedDataModel.class })
public class PassengerAlarmScreenHandler extends AbstractFunctionalLogic
{
  @Autowired
  SharedDataModel sharedDataModel;

  private boolean multiPecuCall = false;

  private int pecuId = 0;

  private int selectedPecuId = 0;

  private int ohpCallId = 5;

  private Map<Integer, String> multiAlarmMap = new HashMap<>();

  @Autowired
  private ScreenChangeHandler screenChangeHandler;

  private ListProperty<MultiplePecuCallModel> pecuCallList = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  protected PassengerAlarmScreenHandler(CommsBinding commsBinding, SharedDataModel sharedDataModel)
  {
    super(commsBinding, IOhpOutputsProperties.class, IAppInputsPassengerAlarmScreenProperties.class,
        IIntercomOutputsProperties.class);
    this.sharedDataModel = sharedDataModel;
    initializeMultiAlarmMap();
    setCallList();
  }

  @Override
  public <T> void ohpOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue, int ohpIndex)
  {
    if (IOhpOutputsProperties.STATUS.equals(key))
    {
      setApplicationOutputsProperty(IAppOutputsPassengerAlarmScreenProperties.ALARM_STATUS,
          (Integer)newValue);
    }
    else if (IOhpOutputsProperties.PE_ID.equals(key))
    {
      pecuId = (Integer)newValue;
      updatePecuId();
    }
    else if (IOhpOutputsProperties.OHP_ID.equals(key))
    {
      multiPecuCall = (Integer)newValue == ohpCallId;
      
    
      if (!multiPecuCall)
      {
        pecuId = 0;
      }
      
      if(multiPecuCall)
      {
        multiAlarmMap.clear();
        initializeMultiAlarmMap();
        setCallList();
      }
      updatePecuId();
    }
  }

  private void initializeMultiAlarmMap()
  {
    multiAlarmMap.put(MultiplePecuCallIdEnum.PECU_1.getId(), MultiplePecuCallIdEnum.PECU_1.getPecuName());
    multiAlarmMap.put(MultiplePecuCallIdEnum.PECU_2.getId(), MultiplePecuCallIdEnum.PECU_2.getPecuName());
    multiAlarmMap.put(MultiplePecuCallIdEnum.PECU_3.getId(), MultiplePecuCallIdEnum.PECU_3.getPecuName());
    multiAlarmMap.put(MultiplePecuCallIdEnum.PECU_4.getId(), MultiplePecuCallIdEnum.PECU_4.getPecuName());
  }

  private void updatePecuId()
  {
    if (multiPecuCall)
    {
      setApplicationOutputsProperty(IAppOutputsPassengerAlarmScreenProperties.RECEIVED_PECU_ID,
          ApplicationConstants.MULTIPLE_PECU_CALL_ID);

    }
    else
    {
      setApplicationOutputsProperty(IAppOutputsPassengerAlarmScreenProperties.RECEIVED_PECU_ID, pecuId);
    }
  }

  @Override
  public <T> void intercomOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue, int ohpIndex)
  {
    if (IIntercomOutputsProperties.INTERCOM.equals(key))
    {
      setApplicationOutputsProperty(IAppOutputsPassengerAlarmScreenProperties.INTERCOM_STATUS,
          (Integer)newValue);
    }
    else if (IIntercomOutputsProperties.ACTIVE_CALL_TYPE.equals(key))
    {
      setApplicationOutputsProperty(IAppOutputsPassengerAlarmScreenProperties.CALL_TYPE, (Integer)newValue);
    }
  }

  @Override
  public <T> void appInputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue, int vehicleIndex)
  {
    if (IAppInputsPassengerAlarmScreenProperties.PASSENGER_ALARM_CONNECT_REQUEST.equals(key))
    {

      sendPulseRequest(getIntercomHandler(), IIntercomInputsProperties.CAB_INTERCOM_BUTTON,
          ApplicationConstants.SET_VALUE, ApplicationConstants.RESET_VALUE);
      setApplicationOutputsProperty(IAppOutputsPassengerAlarmScreenProperties.PASSENGER_ALARM_STATE,
          (Integer)newValue);
      if (multiPecuCall)
      {

        if (!multiAlarmMap.isEmpty() && multiAlarmMap.containsKey(selectedPecuId))
        {
          multiAlarmMap.remove(selectedPecuId);
        }

        setCallList();
      }
    }
    else if (IAppInputsPassengerAlarmScreenProperties.PASSENGER_ALARM_DISCONNECT_REQUEST.equals(key)
        && (Integer)newValue > 0)
    {
      sendPulseRequest(getIntercomHandler(), IIntercomInputsProperties.CAB_CANCEL_BUTTON,
          ApplicationConstants.SET_VALUE, ApplicationConstants.RESET_VALUE);
    }
    else if (IAppInputsPassengerAlarmScreenProperties.PASSENGER_ALARM_CLEAR_ALL_REQUEST.equals(key)
        && (Integer)newValue > 0)
    {
      sendPulseRequest(getIntercomHandler(), IIntercomInputsProperties.CAB_CANCEL_BUTTON,
          ApplicationConstants.SET_VALUE, ApplicationConstants.RESET_VALUE);
    }
    else if (IAppInputsPassengerAlarmScreenProperties.PASSENGER_ALARM_RESET_REQUEST.equals(key)
        && (Integer)newValue > 0)
    {
      sendPulseRequest(getIntercomHandler(), IIntercomInputsProperties.CAB_CANCEL_BUTTON,
          ApplicationConstants.SET_VALUE, ApplicationConstants.RESET_VALUE);
    }
    else if (IAppInputsPassengerAlarmScreenProperties.CC_BUTTON.equals(key) && (Integer)newValue > 0)
    {
      sendPulseRequest(getIntercomHandler(), IIntercomInputsProperties.CAB_INTERCOM_BUTTON,
          ApplicationConstants.SET_VALUE, ApplicationConstants.RESET_VALUE);
      setApplicationOutputsProperty(IAppOutputsPassengerAlarmScreenProperties.CALL_TYPE,
          ApplicationConstants.CALL_TYPE_CTC);
      setApplicationOutputsProperty(IAppOutputsPassengerAlarmScreenProperties.INTERCOM_STATUS,
          ApplicationConstants.CALL_REQUEST);
    }else if (IAppInputsPassengerAlarmScreenProperties.CAB_TO_CAB_CAll_DISCONNECT_REQUEST.equals(key) && (Integer)newValue > 0)
    {
      sendPulseRequest(getIntercomHandler(), IIntercomInputsProperties.CAB_CANCEL_BUTTON,
          ApplicationConstants.SET_VALUE, ApplicationConstants.RESET_VALUE);
    
    }
    else if (IAppInputsPassengerAlarmScreenProperties.CH_CHG_BUTTON.equals(key) && (Integer)newValue > 0)
    {
      // As per latest comment from client,commented code to disconnect call.And
      // Navigate to Main Interface.
      // sendPulseRequest(getOhpOutputHandler(),
      // IIntercomInputsProperties.CAB_CANCEL_BUTTON,
      // ApplicationConstants.SET_VALUE, ApplicationConstants.RESET_VALUE);
      screenChangeHandler.requestScreenChange(ScreenId.MAIN_INTERFACE_SCREEN);
    }
    else if (IAppInputsPassengerAlarmScreenProperties.PASSENGER_ALARM_SELECTED_REQUEST.equals(key)
        && (Integer)newValue > -1)
    {
      setApplicationOutputsProperty(IAppOutputsPassengerAlarmScreenProperties.PASSENGER_ALARM_SELECTED,
          (Integer)newValue);
      selectedPecuId = (Integer)newValue;
      if (multiPecuCall)
      {

        setCallList();
      }

    }
    else if (IAppInputsPassengerAlarmScreenProperties.NUMBER_OF_PECU_CALLS.equals(key))
    {
      setApplicationOutputsProperty(IAppOutputsPassengerAlarmScreenProperties.PECU_CALL_COUNT,
          (Integer)newValue);
    }

    if (sharedDataModel.getScreenId() == ScreenId.PASSENGER_ALARM_SCREEN.getId())
    {
      if (IAppInputsPassengerAlarmScreenProperties.UP_ARROW_BUTTON.equals(key))
      {
        setApplicationOutputsProperty(
            IAppOutputsPassengerAlarmScreenProperties.PC_ALARM_LIST_UP_ARROW_PRESSED, (Integer)newValue);
      }
      else if (IAppInputsPassengerAlarmScreenProperties.DOWN_ARROW_BUTTON.equals(key))
      {
        setApplicationOutputsProperty(
            IAppOutputsPassengerAlarmScreenProperties.PC_ALARM_LIST_DOWN_ARROW_PRESSED, (Integer)newValue);
      }
    }
  }

  private void setCallList()
  {
    PAPISProtos.MultiplePecuCallList.Builder callListBuilder = PAPISProtos.MultiplePecuCallList.newBuilder();
    this.pecuCallList.clear();
    for (Map.Entry<Integer, String> carIndexMap : multiAlarmMap.entrySet())
    {

      this.pecuCallList.add(new MultiplePecuCallModel(carIndexMap.getKey(), carIndexMap.getValue()));

    }
    for (MultiplePecuCallModel lines : this.pecuCallList)
    {

      PAPISProtos.MultiplePecuCallList.MultiplePecuCall.Builder callDetail = PAPISProtos.MultiplePecuCallList.MultiplePecuCall
          .newBuilder();
      callDetail.setPecuId(lines.getPecuId());
      callDetail.setPecuName(lines.getPecuName());
      callListBuilder.addMultiplePecuCall(callDetail.build());
    }
    setApplicationOutputsProperty(IAppOutputsPassengerAlarmScreenProperties.MULTIPLE_PECU_CALL_LIST,
        callListBuilder.build().toByteArray());
  }
}
