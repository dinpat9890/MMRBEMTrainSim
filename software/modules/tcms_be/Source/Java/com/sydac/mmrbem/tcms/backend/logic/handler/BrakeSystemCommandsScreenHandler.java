/*
 * ==================================================================
 * (C)Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * ==================================================================
 */
package com.sydac.mmrbem.tcms.backend.logic.handler;

import org.springframework.stereotype.Service;

import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.tcms.backend.comms.CommsBinding;
import com.sydac.mmrbem.tcms.backend.logic.AbstractFunctionalLogic;
import com.sydac.mmrbem.tcms.backend.logic.SharedDataModel;
import com.sydac.mmrbem.tcms.backend.logic.annotation.FunctionalLogicHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.io.handlers.ITCMSVehicleInputsBrakeSystemCommandsHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.io.properties.ITCMSVehicleOutputsProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppInputBrakeSystemCommandsScreenProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppInputsProperties;
import com.sydac.mmrbem.tcms.common.state.ApplicationConstants;

/**
 * This handler class is used for Brake System Commands screen handling.
 * 
 */

@Service
@FunctionalLogicHandler(arguments = { CommsBinding.class, SharedDataModel.class })
public class BrakeSystemCommandsScreenHandler extends AbstractFunctionalLogic
{
  private ITCMSVehicleInputsBrakeSystemCommandsHandler vehicleInputsHandler;

  private Integer selectedPbIsolateCarIndex;

  private SharedDataModel sharedDataModel;

  protected BrakeSystemCommandsScreenHandler(CommsBinding commsBinding, SharedDataModel sharedDataModel)
  {
    super(commsBinding, IAppInputsProperties.class, ITCMSVehicleOutputsProperties.class);
    this.sharedDataModel = sharedDataModel;
    initalizeVehicleInputHandler();
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
      vehicleInputsHandler = (ITCMSVehicleInputsBrakeSystemCommandsHandler)getTCMSVehicleInputsSetter(
          carIndex);

      vehicleInputsHandler.setBogie1IsolateVduReq(ApplicationConstants.RESET_VALUE);
      vehicleInputsHandler.setBogie2IsolateVduReq(ApplicationConstants.RESET_VALUE);
    }

  }

  @Override
  public <T> void appInputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue, int vehicleIndex)
  {
    if ((Integer)newValue > -1)
    {
      vehicleInputsHandler = (ITCMSVehicleInputsBrakeSystemCommandsHandler)getTCMSVehicleInputsSetter(
          getActiveVehicleIndex());
      if (IAppInputBrakeSystemCommandsScreenProperties.PRKNG_BRAKE_APPLIED_REQ.equals(key))
      {
        updateParkingBrakeAppliedStatus((Integer)newValue);
      }
      else if (IAppInputBrakeSystemCommandsScreenProperties.PRKNG_BRAKE_RELEASE_REQ.equals(key))
      {
        updateParkingBrakeReleaseStatus((Integer)newValue);
      }
      else if (IAppInputBrakeSystemCommandsScreenProperties.PRKNG_BRAKE_BYPASS_REQ.equals(key))
      {
        updateParkingBrakeBypassStatus((Integer)newValue);
      }
      else if (IAppInputBrakeSystemCommandsScreenProperties.SELECTED_PB_ISOLATE_CAR.equals(key))
      {
        selectedPbIsolateCarIndex = (Integer)newValue;
      }
      else if (IAppInputBrakeSystemCommandsScreenProperties.PB_ISOLATE_BOGIE_1_REQ.equals(key))
      {
        vehicleInputsHandler = (ITCMSVehicleInputsBrakeSystemCommandsHandler)getTCMSVehicleInputsSetter(
            selectedPbIsolateCarIndex);
        vehicleInputsHandler.setBogie1IsolateVduReq((Integer)newValue);
      }
      else if (IAppInputBrakeSystemCommandsScreenProperties.PB_ISOLATE_BOGIE_2_REQ.equals(key))
      {
        vehicleInputsHandler = (ITCMSVehicleInputsBrakeSystemCommandsHandler)getTCMSVehicleInputsSetter(
            selectedPbIsolateCarIndex);
        vehicleInputsHandler.setBogie2IsolateVduReq((Integer)newValue);
      }
    }
  }

  private void updateParkingBrakeBypassStatus(Integer bypassValue)
  {
    for (int carIndex = 0; carIndex < sharedDataModel.getTotalCar(); carIndex++)
    {
      vehicleInputsHandler = (ITCMSVehicleInputsBrakeSystemCommandsHandler)getTCMSVehicleInputsSetter(
          carIndex);
      vehicleInputsHandler.setParkBrakeBypassVduReq(bypassValue);
    }
  }

  private void updateParkingBrakeReleaseStatus(Integer releasedValue)
  {
    for (int carIndex = 0; carIndex < sharedDataModel.getTotalCar(); carIndex++)
    {
      vehicleInputsHandler = (ITCMSVehicleInputsBrakeSystemCommandsHandler)getTCMSVehicleInputsSetter(
          carIndex);
      vehicleInputsHandler.setParkBrakeReleaseVduReq(releasedValue);
    }
  }

  private void updateParkingBrakeAppliedStatus(Integer appliedValue)
  {
    for (int carIndex = 0; carIndex < sharedDataModel.getTotalCar(); carIndex++)
    {
      vehicleInputsHandler = (ITCMSVehicleInputsBrakeSystemCommandsHandler)getTCMSVehicleInputsSetter(
          carIndex);
      vehicleInputsHandler.setParkBrakeApplyVduReq(appliedValue);
    }
  }

  private void initalizeVehicleInputHandler()
  {
    if (vehicleInputsHandler == null)
    {
      vehicleInputsHandler = (ITCMSVehicleInputsBrakeSystemCommandsHandler)getTCMSVehicleInputsSetter(
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
