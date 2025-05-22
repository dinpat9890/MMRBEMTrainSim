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

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.papis.backend.comms.CommsBinding;
import com.sydac.mmrbem.papis.backend.logic.AbstractFunctionalLogic;
import com.sydac.mmrbem.papis.backend.logic.SharedDataModel;
import com.sydac.mmrbem.papis.backend.logic.annotation.FunctionalLogicHandler;
import com.sydac.mmrbem.papis.common.ScreenId;
import com.sydac.mmrbem.papis.common.io.properties.IAppInputsPassengerAlarmScreenProperties;
import com.sydac.mmrbem.papis.common.io.properties.IAppOutputsCommonProperties;
import com.sydac.mmrbem.papis.common.io.properties.IOhpInputsProperties;
import com.sydac.mmrbem.papis.common.io.properties.IOhpOutputsProperties;

/**
 * This handler class is used for handling Passenger Emergency Alarm Screen (PC
 * or PECU)
 * 
 */
@Service
@FunctionalLogicHandler(arguments = { CommsBinding.class, SharedDataModel.class })
public class PecuIsolateScreenHandler extends AbstractFunctionalLogic
{
  @Autowired
  SharedDataModel sharedDataModel;

  protected PecuIsolateScreenHandler(CommsBinding commsBinding, SharedDataModel sharedDataModel)
  {
    super(commsBinding,  IAppInputsPassengerAlarmScreenProperties.class);
    this.sharedDataModel = sharedDataModel;
    
  }
  
  @Override
  public void attachListeners()
  {
    super.attachListeners();
    setApplicationOutputsProperty(IAppOutputsCommonProperties.NUMBER_OF_CARS,
        sharedDataModel.getTotalCar());   
  }


  @Override
  public <T> void appInputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue, int vehicleIndex)
  {
    if (IAppInputsPassengerAlarmScreenProperties.PECU_ISOLATE_ID_REQ.equals(key))
    {

      setInputData(getOhpHandler(), IOhpInputsProperties.PECU_ISOLATE_REQ,
          (Integer)newValue);

    }
    else if (IAppInputsPassengerAlarmScreenProperties.PECU_DEISOLATE_ID_REQ.equals(key))
    {
      setInputData(getOhpHandler(), IOhpInputsProperties.PECU_DE_ISOLATE_REQ,
          (Integer)newValue);
    }

  }

}
