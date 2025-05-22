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
import com.sydac.mmrbem.tcms.backend.vehicle.io.handlers.ITCMSVehicleInputsSpecialModesHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.io.properties.ITCMSVehicleOutputsSpecialModesProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppInputSpecialModesScreenProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppInputsProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsSpecialModesScreenProperties;
import com.sydac.mmrbem.tcms.common.state.TCMSConstants;

/**
 * This handler class is used for Special Modes screen handling.
 * 
 */

@Service
@FunctionalLogicHandler(arguments = { CommsBinding.class, SharedDataModel.class })
public class SpecialModesScreenHandler extends AbstractFunctionalLogic
{
  private final SharedDataModel sharedDataModel;

  private ITCMSVehicleInputsSpecialModesHandler vehicleInputsHandler;

  private int washingSpeed;

  private boolean hteActivated = true;

  private int shuntModeStatus = 0;

  private int atpLowModeStatus = 0;

  private int washModeStatus = 0;

  private int hteModeStatus = 0;

  private int hteReqValue = 0;

  private static final Integer WASHING_INACTIVE_VALUE = 0;

  private static final Integer WASHING_ACTIVE_VALUE = 1;

  private static final Integer HTE_ACTIVATED_VALUE = 2;

  public static final int WASHING_SPEED_3 = 3;

  public static final int WASHING_SPEED_4 = 4;

  public static final int WASHING_SPEED_5 = 5;

  private int currentShuntMinMaxSpeed = TCMSConstants.SHUNTING_MIN_SPEED_MAXLEVEL;

  private int currentShuntMaxSpeed = TCMSConstants.SHUNTING_MAX_SPEED;

  private int currentAtpMaxSpeed = TCMSConstants.ATP_MAX_SPEED;

  protected SpecialModesScreenHandler(CommsBinding commsBinding, SharedDataModel aShareDataModel)
  {
    super(commsBinding, IAppInputsProperties.class, ITCMSVehicleOutputsSpecialModesProperties.class);
    sharedDataModel = aShareDataModel;

    initalizeVehicleInputHandler();

  }

  @Override
  public <T> void tcmsVehicleOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue,
      int vehicleIndex)
  {
    if (key.equals(ITCMSVehicleOutputsSpecialModesProperties.HTE_REQUIRED))
    {
      hteReqValue = (Integer)newValue;
      updateHteActivatedStatus();
    }
    else if (key.equals(ITCMSVehicleOutputsSpecialModesProperties.WASHING_MODE_STATUS))
    {
      washModeStatus = (Integer)newValue;
      setApplicationOutputsProperty(IAppOutputsSpecialModesScreenProperties.WASHING_MODE_STATUS,
          (Integer)newValue);
    }
    else if (key.equals(ITCMSVehicleOutputsSpecialModesProperties.SHUNT_MODE_STATUS))
    {
      shuntModeStatus = (Integer)newValue;
      setApplicationOutputsProperty(IAppOutputsSpecialModesScreenProperties.SHUNT_MODE_STATUS,
          (Integer)newValue);
    }
    else if (key.equals(ITCMSVehicleOutputsSpecialModesProperties.ATP_LOW_SPEED_CUTOUT_STATUS))
    {
      atpLowModeStatus = (Integer)newValue;
      setApplicationOutputsProperty(IAppOutputsSpecialModesScreenProperties.ATP_LOW_SPEED_STATUS,
          (Integer)newValue);
    }
  }

  @Override
  public <T> void appInputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue, int vehicleIndex)
  {

    if (getActiveVehicleIndex() == vehicleIndex)
    {
      if (key.equals(IAppInputSpecialModesScreenProperties.ACTIVATE_HTE_REQ))
      {
        hteActivated = !hteActivated;
        updateHteActivatedStatus();
        updateHTEActivationReq(newValue);
      }
      else if (key.equals(IAppInputSpecialModesScreenProperties.ACTIVATE_WASHING_REQ)
          && (Integer)newValue > -1)
      {
        if (shuntModeStatus == 0 && atpLowModeStatus == 0)
        {
          if ((Integer)newValue == WASHING_ACTIVE_VALUE)
          {
            updateWashingActivationReq(WASHING_ACTIVE_VALUE);
          }
          else
          {
            updateWashingActivationReq(WASHING_INACTIVE_VALUE);
          }
        }
      }
      else if (key.equals(IAppInputSpecialModesScreenProperties.SPECIAL_MODE_ACTIVATE_ATP_LOW_BUTTON_REQUEST)
          && (Integer)newValue > -1)
      {
        if (shuntModeStatus == 0 && washModeStatus == 0)
        {
          vehicleInputsHandler = (ITCMSVehicleInputsSpecialModesHandler)getTCMSVehicleInputsSetter(
              getActiveVehicleIndex());
          vehicleInputsHandler.setAtpLowModeActivated((Integer)newValue);
          vehicleInputsHandler.setAtpLowModeMaxSpeed(currentAtpMaxSpeed);
        }
      }
      else if (key.equals(IAppInputSpecialModesScreenProperties.SPECIAL_MODE_ACTIVATE_SHUNTING_BUTTON_REQUEST)
          && (Integer)newValue > -1)
      {
        if (atpLowModeStatus == 0 && washModeStatus == 0)
        {
          vehicleInputsHandler = (ITCMSVehicleInputsSpecialModesHandler)getTCMSVehicleInputsSetter(
              getActiveVehicleIndex());
          vehicleInputsHandler.setShuntModeActivated((Integer)newValue);
          vehicleInputsHandler.setShuntModeMaxSpeed(currentShuntMaxSpeed);
          vehicleInputsHandler.setShuntModeMinSpeed(currentShuntMinMaxSpeed);
        }
      }
      else if (key.equals(IAppInputSpecialModesScreenProperties.SELECTED_WASHING_MODE_SPEED)
          && (Integer)newValue > -1)
      {
        updateWashingActivationReq(WASHING_INACTIVE_VALUE);
        washingSpeed = (Integer)newValue;
      }
      else if (key.equals(IAppInputSpecialModesScreenProperties.SPECIAL_MODE_SHUNT_MIN_SPEED_DECREASE_REQUEST)
          && (Integer)newValue > 0)
      {
        updateShuntMinDecreaseRequest();
      }
      else if (key.equals(IAppInputSpecialModesScreenProperties.SPECIAL_MODE_SHUNT_MIN_SPEED_INCREASE_REQUEST)
          && (Integer)newValue > 0)
      {
        updateShuntMinIncreaseRequest();
      }
      else if (key.equals(IAppInputSpecialModesScreenProperties.SPECIAL_MODE_SHUNT_MAX_SPEED_DECREASE_REQUEST)
          && (Integer)newValue > 0)
      {
        updateShuntMaxDecreaseRequest();
      }
      else if (key.equals(IAppInputSpecialModesScreenProperties.SPECIAL_MODE_SHUNT_MAX_SPEED_INCREASE_REQUEST)
          && (Integer)newValue > 0)
      {
        updateShuntMaxIncreaseRequest();
      }
      else if (key.equals(IAppInputSpecialModesScreenProperties.SPECIAL_MODE_ATP_MAX_SPEED_DECREASE_REQUEST)
          && (Integer)newValue > 0)
      {
        updateAtpMaxDecreaseRequest();
      }
      else if (key.equals(IAppInputSpecialModesScreenProperties.SPECIAL_MODE_ATP_MAX_SPEED_INCREASE_REQUEST)
          && (Integer)newValue > 0)
      {
        updateAtpMaxIncreaseRequest();
      }
      else if (key.equals(IAppInputSpecialModesScreenProperties.SPECIAL_MODE_SHUNT_SET_BUTTON_REQUEST)
          && (Integer)newValue > 0)
      {
        updateShuntModeSpeedSetting();
      }
      else if (key.equals(IAppInputSpecialModesScreenProperties.SPECIAL_MODE_ATP_SET_BUTTON_REQUEST)
          && (Integer)newValue > 0)
      {
        updateAtpLowModeSpeedSetting();
      }
    }
  }

  private void updateShuntModeSpeedSetting()
  {
    if (shuntModeStatus == 1)
    {
      vehicleInputsHandler = (ITCMSVehicleInputsSpecialModesHandler)getTCMSVehicleInputsSetter(
          getActiveVehicleIndex());
      vehicleInputsHandler.setShuntModeMaxSpeed(currentShuntMaxSpeed);
      vehicleInputsHandler.setShuntModeMinSpeed(currentShuntMinMaxSpeed);
      setApplicationOutputsProperty(IAppOutputsSpecialModesScreenProperties.SHUNT_MODE_SET_BUTTON_STATUS, 0);
    }
  }

  private void updateAtpLowModeSpeedSetting()
  {
    if (atpLowModeStatus == 1)
    {
      vehicleInputsHandler = (ITCMSVehicleInputsSpecialModesHandler)getTCMSVehicleInputsSetter(
          getActiveVehicleIndex());
      vehicleInputsHandler.setAtpLowModeMaxSpeed(currentAtpMaxSpeed);
      setApplicationOutputsProperty(IAppOutputsSpecialModesScreenProperties.ATP_LOW_MODE_SET_BUTTON_STATUS,
          0);
    }
  }

  private void updateHteActivatedStatus()
  {
    if (hteActivated)
    {
      setApplicationOutputsProperty(IAppOutputsSpecialModesScreenProperties.HTE_REQUIRED_STATUS,
          HTE_ACTIVATED_VALUE);
    }
    else
    {
      setApplicationOutputsProperty(IAppOutputsSpecialModesScreenProperties.HTE_REQUIRED_STATUS, hteReqValue);
    }
  }

  private <T> void updateHTEActivationReq(T newValue)
  {
    if (vehicleInputsHandler != null)
    {
      for (int carInd = 0; carInd < sharedDataModel.getTotalCar(); carInd++)
      {
        vehicleInputsHandler = (ITCMSVehicleInputsSpecialModesHandler)getTCMSVehicleInputsSetter(carInd);
        vehicleInputsHandler.setActivateHte((Integer)newValue);
      }
    }
  }

  private <T> void updateWashingActivationReq(int washingSpeedValue)
  {
    if (vehicleInputsHandler != null)
    {
      for (int carInd = 0; carInd < sharedDataModel.getTotalCar(); carInd++)
      {
        vehicleInputsHandler = (ITCMSVehicleInputsSpecialModesHandler)getTCMSVehicleInputsSetter(carInd);
        if (washingSpeed == WASHING_SPEED_3)
        {
          vehicleInputsHandler.setActivateWashing3Kmph(washingSpeedValue);
        }
        else if (washingSpeed == WASHING_SPEED_4)
        {
          vehicleInputsHandler.setActivateWashing4Kmph(washingSpeedValue);
        }
        else if (washingSpeed == WASHING_SPEED_5)
        {
          vehicleInputsHandler.setActivateWashing5Kmph(washingSpeedValue);
        }
      }
    }
  }

  private void initalizeVehicleInputHandler()
  {
    if (vehicleInputsHandler == null)
    {
      vehicleInputsHandler = (ITCMSVehicleInputsSpecialModesHandler)getTCMSVehicleInputsSetter(
          getActiveVehicleIndex());
    }
  }

  @Override
  public void attachListeners()
  {
    super.attachListeners();

    initalizeVehicleInputHandler();
  }

  private void updateShuntMinDecreaseRequest()
  {
    int updatedLevel = currentShuntMinMaxSpeed - 1;
    if (updatedLevel > 0)
    {
      currentShuntMinMaxSpeed = updatedLevel;
      setApplicationOutputsProperty(
          IAppOutputsSpecialModesScreenProperties.SPECIAL_MODE_SHUNT_MIN_SPEED_VALUE,
          currentShuntMinMaxSpeed);
      setApplicationOutputsProperty(IAppOutputsSpecialModesScreenProperties.SHUNT_MODE_SET_BUTTON_STATUS, 1);
    }
  }

  private void updateShuntMinIncreaseRequest()
  {
    int updatedLevel = currentShuntMinMaxSpeed + 1;
    if (updatedLevel <= TCMSConstants.SHUNTING_MIN_SPEED_MAXLEVEL)
    {
      currentShuntMinMaxSpeed = updatedLevel;
      setApplicationOutputsProperty(
          IAppOutputsSpecialModesScreenProperties.SPECIAL_MODE_SHUNT_MIN_SPEED_VALUE,
          currentShuntMinMaxSpeed);
      setApplicationOutputsProperty(IAppOutputsSpecialModesScreenProperties.SHUNT_MODE_SET_BUTTON_STATUS, 1);
    }
  }

  private void updateShuntMaxDecreaseRequest()
  {
    int updatedLevel = currentShuntMaxSpeed - 1;
    if (updatedLevel > 0)
    {
      currentShuntMaxSpeed = updatedLevel;
      setApplicationOutputsProperty(
          IAppOutputsSpecialModesScreenProperties.SPECIAL_MODE_SHUNT_MAX_SPEED_VALUE, currentShuntMaxSpeed);
      setApplicationOutputsProperty(IAppOutputsSpecialModesScreenProperties.SHUNT_MODE_SET_BUTTON_STATUS, 1);
    }
  }

  private void updateShuntMaxIncreaseRequest()
  {
    int updatedLevel = currentShuntMaxSpeed + 1;
    if (updatedLevel <= TCMSConstants.SHUNTING_MAX_SPEED)
    {
      currentShuntMaxSpeed = updatedLevel;
      setApplicationOutputsProperty(
          IAppOutputsSpecialModesScreenProperties.SPECIAL_MODE_SHUNT_MAX_SPEED_VALUE, currentShuntMaxSpeed);
      setApplicationOutputsProperty(IAppOutputsSpecialModesScreenProperties.SHUNT_MODE_SET_BUTTON_STATUS, 1);
    }
  }

  private void updateAtpMaxDecreaseRequest()
  {
    int updatedLevel = currentAtpMaxSpeed - 1;
    if (updatedLevel > 0)
    {
      currentAtpMaxSpeed = updatedLevel;
      setApplicationOutputsProperty(IAppOutputsSpecialModesScreenProperties.SPECIAL_MODE_ATP_MAX_SPEED_VALUE,
          currentAtpMaxSpeed);
      setApplicationOutputsProperty(IAppOutputsSpecialModesScreenProperties.ATP_LOW_MODE_SET_BUTTON_STATUS,
          1);
    }
  }

  private void updateAtpMaxIncreaseRequest()
  {
    int updatedLevel = currentAtpMaxSpeed + 1;
    if (updatedLevel <= TCMSConstants.ATP_MAX_SPEED)
    {
      currentAtpMaxSpeed = updatedLevel;
      setApplicationOutputsProperty(IAppOutputsSpecialModesScreenProperties.SPECIAL_MODE_ATP_MAX_SPEED_VALUE,
          currentAtpMaxSpeed);
      setApplicationOutputsProperty(IAppOutputsSpecialModesScreenProperties.ATP_LOW_MODE_SET_BUTTON_STATUS,
          1);
    }
  }

}
