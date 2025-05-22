/*
 * ==================================================================
 * (C)Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * ==================================================================
 */
package com.sydac.mmrbem.tcms.backend.logic.handler;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.tcms.backend.comms.CommsBinding;
import com.sydac.mmrbem.tcms.backend.logic.AbstractFunctionalLogic;
import com.sydac.mmrbem.tcms.backend.logic.SharedDataModel;
import com.sydac.mmrbem.tcms.backend.logic.annotation.FunctionalLogicHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.io.handlers.ITCMSVehicleInputsDoorsSystemCommandsHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.io.properties.ITCMSVehicleOutputsProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppInputDoorsSystemCommandsScreenProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppInputsProperties;
import com.sydac.mmrbem.tcms.common.state.ApplicationConstants;

/**
 * This handler class is used for Doors System Commands screen handling.
 * 
 */

@Service
@FunctionalLogicHandler(arguments = { CommsBinding.class, SharedDataModel.class })
public class DoorsSystemCommandsScreenHandler extends AbstractFunctionalLogic
{

  private ITCMSVehicleInputsDoorsSystemCommandsHandler vehicleInputsHandler;

  @Autowired
  private SharedDataModel sharedDataModel;

  protected DoorsSystemCommandsScreenHandler(CommsBinding commsBinding, SharedDataModel sharedDataModel)
  {
    super(commsBinding, IAppInputsProperties.class, ITCMSVehicleOutputsProperties.class);
    initalizeVehicleInputHandler();
    this.sharedDataModel = sharedDataModel;
  }

  @Override
  public <T> void tcmsVehicleOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue,
      int vehicleIndex)
  {
    if (ITCMSVehicleOutputsProperties.POWER_OFF_PRESSED.equals(key) && Boolean.TRUE.equals(newValue))
    {
      resetInputCommands();
    }
  }

  private void resetInputCommands()
  {
    for (int carIndex = 0; carIndex < sharedDataModel.getTotalCar(); carIndex++)
    {
      vehicleInputsHandler = (ITCMSVehicleInputsDoorsSystemCommandsHandler)getTCMSVehicleInputsSetter(
          carIndex);

      vehicleInputsHandler.setDoorA1IsolateVduReq(ApplicationConstants.RESET_VALUE);
      vehicleInputsHandler.setDoorA2IsolateVduReq(ApplicationConstants.RESET_VALUE);
      vehicleInputsHandler.setDoorA3IsolateVduReq(ApplicationConstants.RESET_VALUE);
      vehicleInputsHandler.setDoorA4IsolateVduReq(ApplicationConstants.RESET_VALUE);
      vehicleInputsHandler.setDoorB1IsolateVduReq(ApplicationConstants.RESET_VALUE);
      vehicleInputsHandler.setDoorB2IsolateVduReq(ApplicationConstants.RESET_VALUE);
      vehicleInputsHandler.setDoorB3IsolateVduReq(ApplicationConstants.RESET_VALUE);
      vehicleInputsHandler.setDoorB4IsolateVduReq(ApplicationConstants.RESET_VALUE);
    }
  }

  @Override
  public <T> void appInputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue, int vehicleIndex)
  {
    Integer selectedDoorIsolateCarIndex;
    if ((Integer)newValue > -1)
    {
      if (IAppInputDoorsSystemCommandsScreenProperties.SELECTED_DOOR_ISO_REINS_CAR.equals(key))
      {
        selectedDoorIsolateCarIndex = (Integer)newValue;
        vehicleInputsHandler = (ITCMSVehicleInputsDoorsSystemCommandsHandler)getTCMSVehicleInputsSetter(
            selectedDoorIsolateCarIndex);
      }
      else if (IAppInputDoorsSystemCommandsScreenProperties.DOOR_A1_ISO_REINS_REQ.equals(key))
      {
        vehicleInputsHandler.setDoorA1IsolateVduReq((Integer)newValue);
      }
      else if (IAppInputDoorsSystemCommandsScreenProperties.DOOR_A2_ISO_REINS_REQ.equals(key))
      {
        vehicleInputsHandler.setDoorA2IsolateVduReq((Integer)newValue);
      }
      else if (IAppInputDoorsSystemCommandsScreenProperties.DOOR_A3_ISO_REINS_REQ.equals(key))
      {
        vehicleInputsHandler.setDoorA3IsolateVduReq((Integer)newValue);
      }
      else if (IAppInputDoorsSystemCommandsScreenProperties.DOOR_A4_ISO_REINS_REQ.equals(key))
      {
        vehicleInputsHandler.setDoorA4IsolateVduReq((Integer)newValue);
      }
      else if (IAppInputDoorsSystemCommandsScreenProperties.DOOR_B1_ISO_REINS_REQ.equals(key))
      {
        vehicleInputsHandler.setDoorB1IsolateVduReq((Integer)newValue);
      }
      else if (IAppInputDoorsSystemCommandsScreenProperties.DOOR_B2_ISO_REINS_REQ.equals(key))
      {
        vehicleInputsHandler.setDoorB2IsolateVduReq((Integer)newValue);
      }
      else if (IAppInputDoorsSystemCommandsScreenProperties.DOOR_B3_ISO_REINS_REQ.equals(key))
      {
        vehicleInputsHandler.setDoorB3IsolateVduReq((Integer)newValue);
      }
      else if (IAppInputDoorsSystemCommandsScreenProperties.DOOR_B4_ISO_REINS_REQ.equals(key))
      {
        vehicleInputsHandler.setDoorB4IsolateVduReq((Integer)newValue);
      }
    }
  }

  private void initalizeVehicleInputHandler()
  {
    if (vehicleInputsHandler == null)
    {
      vehicleInputsHandler = (ITCMSVehicleInputsDoorsSystemCommandsHandler)getTCMSVehicleInputsSetter(
          getActiveVehicleIndex());
    }
  }

  @Override
  public void attachListeners()
  {
    super.attachListeners();
    initalizeVehicleInputHandler();
  }
}
