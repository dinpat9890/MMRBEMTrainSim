/*
 * ==================================================================
 * (C)Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * ==================================================================
 */

package com.sydac.mmrbem.psd.backend.logic.handler;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.google.protobuf.InvalidProtocolBufferException;
import com.sydac.foundation.IPropertySetter;
import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.psd.backend.comms.CommsBinding;
import com.sydac.mmrbem.psd.backend.data.RouteDirection;
import com.sydac.mmrbem.psd.backend.logic.AbstractFunctionalLogic;
import com.sydac.mmrbem.psd.backend.logic.annotation.FunctionalLogicHandler;
import com.sydac.mmrbem.psd.backend.vehicle.io.models.ICBTCPlatformOutputsModel;
import com.sydac.mmrbem.psd.backend.vehicle.io.properties.ICBTCOnboardOutputsProperties;
import com.sydac.mmrbem.psd.backend.vehicle.io.properties.ICBTCPlatformInputsProperties;
import com.sydac.mmrbem.psd.backend.vehicle.io.properties.ICBTCPlatformOutputsProperties;
import com.sydac.mmrbem.psd.backend.vehicle.io.properties.IPISBEOutputsProperties;
import com.sydac.mmrbem.psd.common.data.ApplicationConstants;
import com.sydac.mmrbem.psd.common.io.properties.IAppInputsPSDProperties;
import com.sydac.mmrbem.psd.common.io.properties.IAppOutputsPSDProperties;
import com.sydac.mmrbem.psd.common.protos.PSDProtos;
import com.sydac.mmrbem.psd.common.utils.XMLParser;

@Service
@FunctionalLogicHandler(arguments = { CommsBinding.class })
public class PsdPanelHandler extends AbstractFunctionalLogic
{

  private CommsBinding commsBinding;

  private XMLParser routeParser;

  private ICBTCPlatformOutputsModel cbtcPlatformOutputsModel;

  @Autowired
  private ScreenChangeHandler screenChangeHandler;

  Double currentTrainSpeed;

  int interLockOverideStatus;

  

  protected PsdPanelHandler(CommsBinding commsBinding)
  {
    super(commsBinding, IAppInputsPSDProperties.class, IPISBEOutputsProperties.class,
        ICBTCPlatformOutputsProperties.class, ICBTCOnboardOutputsProperties.class);
    this.commsBinding = commsBinding;

    routeParser = new XMLParser();

    initalizeCbtcOutputModel();
  }

  @Override
  public <T> void cbtcPlatformOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue,
      int vehicleIndex)
  {
    initalizeCbtcOutputModel();

    if (getActiveVehicleIndex() == vehicleIndex)
    {

      if (key.equals(ICBTCPlatformOutputsProperties.PSD_DOOR_STATUS))
      {
        updateDoorStatusFromCbtc((Integer)newValue);

      }
      else if (key.equals(ICBTCPlatformOutputsProperties.TRAIN_DOCKING_INFO))
      {
        updateDockingInfo();
      }
      else if (key.equals(ICBTCPlatformOutputsProperties.PSD_INTERLOCK_OVERRIDE_STATUS))
      {
        updateInterlockInfo((Integer)newValue);
      }
    }

  }

  private void updateInterlockInfo(int interLockInfo)
  {

    setApplicationOutputsProperty(IAppOutputsPSDProperties.INTERLOCK_OVERRIDE_STATUS, interLockInfo);

  }

  private void updateDockingInfo()
  {

    byte[] dockingInfo = this.cbtcPlatformOutputsModel == null ? new byte[0]
        : this.cbtcPlatformOutputsModel.getTrainDockingInfo();
    int trainDockingStatus= 0;
    if (dockingInfo.length != 0)
    {

      try
      {
        PSDProtos.TrainDockingInfo trainDockingInfo = PSDProtos.TrainDockingInfo.parseFrom(dockingInfo);

        if (trainDockingInfo.getTrainDockingStatus()
            .equals(PSDProtos.TrainDockingInfo.TrainDockingStatus.CORRECTLY_DOCKED))
        {
          trainDockingStatus = trainDockingInfo.getTrainDockingStatus().getNumber();
        }

      }
      catch (InvalidProtocolBufferException e)
      {

      }
    }

    setApplicationOutputsProperty(IAppOutputsPSDProperties.TRAIN_DOCKING_STATUS, trainDockingStatus);

  }

  private void updateDoorStatusFromCbtc(Integer cbtcValue)
  {
    if (cbtcValue >= 0)
    {

      setApplicationOutputsProperty(IAppOutputsPSDProperties.PSD_DOOR_STATUS, cbtcValue);

    }
  }

  @Override
  public <T> void pisBeOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue, int vehicleIndex)
  {

    if (IPISBEOutputsProperties.PLATFORM_SIDE_PSD.equals(key))
    {
      setApplicationOutputsProperty(IAppOutputsPSDProperties.PLATFORM_SIDE, (Integer)newValue);

    }
    else if (IPISBEOutputsProperties.SELECTED_ROUTE_ID_PSD.equals(key) && (Integer)newValue > 0)
    {
      updateTrainDirection((Integer)newValue);
    }
  }

  private void initalizeCbtcOutputModel()
  {

    if (this.cbtcPlatformOutputsModel == null)
    {
      this.cbtcPlatformOutputsModel = (ICBTCPlatformOutputsModel)commsBinding.getCbtcPlatformOutputsModels()
          .get(getActiveVehicleIndex());
    }

  }

  /**
   * Get the route Code from route id .Based on the routecode set the screenId
   * 
   * @param routeId
   */
  private void updateTrainDirection(int routeId)
  {
    if (routeId > 0)
    {
      String routeCode = routeParser.getRouteCode(routeId);
      if (routeCode != null && !routeCode.trim().isEmpty())
      {
        screenChangeHandler
            .processScreenChangeRequest(RouteDirection.valueByRouteCode(routeCode).getSceen().getId());
      }
    }
  }

  @Override
  public <T> void appInputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue, int vehicleIndex)
  {
    IPropertySetter onboardInputSetter = getCbtcPlatoformInputsSetter(getActiveVehicleIndex());
    if (IAppInputsPSDProperties.PSE_ENABLE_BUTTON_PRESS_REQUEST.equals(key) && (Integer)newValue > -1)
    {

      setApplicationOutputsProperty(IAppOutputsPSDProperties.PSE_ENABLE_STATUS, (Integer)newValue);
    }
    else if (IAppInputsPSDProperties.INTERLOCK_OVERRIDE_BUTTON_PRESS_REQUEST.equals(key)
        && (Integer)newValue > 0)
    {

      // setApplicationOutputsProperty(IAppOutputsPSDProperties.INTERLOCK_OVERRIDE_STATUS,
      // (Integer)newValue);

      if (onboardInputSetter != null)
      {

        setInputData(onboardInputSetter, ICBTCPlatformInputsProperties.PLATFORM_DOOR_INTERLOCK_OVERRIDE,
            ApplicationConstants.SET_VALUE);

        

      }
    }
    else if (IAppInputsPSDProperties.LAMP_TEST_BUTTON_PRESS_REQUEST.equals(key) && (Integer)newValue > -1)
    {

      setApplicationOutputsProperty(IAppOutputsPSDProperties.LAMP_TEST_STATUS, (Integer)newValue);
    }
    else if (IAppInputsPSDProperties.PG_CLOSE_BUTTON_PRESS_REQUEST.equals(key) && (Integer)newValue > 0)
    {

      if (onboardInputSetter != null)
      {

        setInputData(onboardInputSetter, ICBTCPlatformInputsProperties.PLATFORM_DOOR_CLOSE_REQUEST,
            ApplicationConstants.SET_VALUE);
        setInputData(onboardInputSetter, ICBTCPlatformInputsProperties.PLATFORM_DOOR_OPEN_REQUEST,
            ApplicationConstants.RESET_VALUE);

      }
    }
    else if (IAppInputsPSDProperties.PG_OPEN_BUTTON_PRESS_REQUEST.equals(key) && (Integer)newValue > 0)
    {

      if (onboardInputSetter != null)
      {

        setInputData(onboardInputSetter, ICBTCPlatformInputsProperties.PLATFORM_DOOR_OPEN_REQUEST,
            ApplicationConstants.SET_VALUE);

        setInputData(onboardInputSetter, ICBTCPlatformInputsProperties.PLATFORM_DOOR_CLOSE_REQUEST,
            ApplicationConstants.RESET_VALUE);

      }

    }

  }

  @Override
  public <T> void cbtcOnboardOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue,
      int vehicleIndex)
  {
    IPropertySetter onboardInputSetter = getCbtcPlatoformInputsSetter(getActiveVehicleIndex());
    if (ICBTCOnboardOutputsProperties.CURRENT_TRAIN_SPEED.equals(key) )
    {
      currentTrainSpeed = (Double)newValue;
      if (currentTrainSpeed > 0 && interLockOverideStatus == 0 )
      {
       
        setInputData(onboardInputSetter, ICBTCPlatformInputsProperties.PLATFORM_DOOR_INTERLOCK_OVERRIDE,
            ApplicationConstants.RESET_VALUE);

        setInputData(onboardInputSetter, ICBTCPlatformInputsProperties.PLATFORM_DOOR_OPEN_REQUEST,
            ApplicationConstants.RESET_VALUE);
        setApplicationOutputsProperty(IAppOutputsPSDProperties.PSE_ENABLE_STATUS, 0);
      }
    }

  }
}
