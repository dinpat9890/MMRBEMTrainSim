/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.papis.fe.gui.binder;

import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.papis.common.io.properties.IAppOutputsPassengerAlarmScreenProperties;
import com.sydac.mmrbem.papis.fe.base.AbstractCommsListener;
import com.sydac.mmrbem.papis.fe.gui.model.PassengerAlarmScreenModel;

public class PassengerAlarmScreenBinder extends AbstractCommsListener
{

  private PassengerAlarmScreenModel passengerAlarmScreenModel;

  public PassengerAlarmScreenBinder(PassengerAlarmScreenModel passengerAlarmScreenModel)
  {
    this.passengerAlarmScreenModel = passengerAlarmScreenModel;
    propertyKeyDefinitions.add(IAppOutputsPassengerAlarmScreenProperties.class);
  }

  @Override
  protected <T> void appOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue)
  {
    if (IAppOutputsPassengerAlarmScreenProperties.ALARM_STATUS.equals(key))
    {
      passengerAlarmScreenModel.setAlarmStatus((Integer)newValue);
    }
    else if (IAppOutputsPassengerAlarmScreenProperties.INTERCOM_STATUS.equals(key))
    {
      passengerAlarmScreenModel.setIntercomStatus((Integer)newValue);
    }
    else if (IAppOutputsPassengerAlarmScreenProperties.CALL_TYPE.equals(key))
    {
      passengerAlarmScreenModel.setActiveCallType((Integer)newValue);
    }
    else if (IAppOutputsPassengerAlarmScreenProperties.RECEIVED_PECU_ID.equals(key))
    {
      passengerAlarmScreenModel.setPecuId((Integer)newValue);
    }
    else if (IAppOutputsPassengerAlarmScreenProperties.PC_ALARM_LIST_UP_ARROW_PRESSED.equals(key))
    {
      passengerAlarmScreenModel.setUpArrowPressed((Integer)newValue);
    }
    else if (IAppOutputsPassengerAlarmScreenProperties.PC_ALARM_LIST_DOWN_ARROW_PRESSED.equals(key))
    {
      passengerAlarmScreenModel.setDownArrowPressed((Integer)newValue);
    }else if (IAppOutputsPassengerAlarmScreenProperties.PASSENGER_ALARM_SELECTED.equals(key))
    {
      passengerAlarmScreenModel.setSelectedAlarm((Integer)newValue);
    }else if (IAppOutputsPassengerAlarmScreenProperties.PASSENGER_ALARM_STATE.equals(key))
    {
      passengerAlarmScreenModel.setAlarmState((Integer)newValue);
    }else if (IAppOutputsPassengerAlarmScreenProperties.MULTIPLE_PECU_CALL_LIST.equals(key))
    {
      passengerAlarmScreenModel.setMultipleCallList((byte[])newValue);
    }else if (IAppOutputsPassengerAlarmScreenProperties.PECU_CALL_COUNT.equals(key))
    {
      passengerAlarmScreenModel.setCallCount((Integer)newValue);
    }
  }

}
