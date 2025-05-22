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
import com.sydac.gui.i18n.CommonStrings;
import com.sydac.mmrbem.papis.backend.comms.CommsBinding;
import com.sydac.mmrbem.papis.backend.logic.AbstractFunctionalLogic;
import com.sydac.mmrbem.papis.backend.logic.SharedDataModel;
import com.sydac.mmrbem.papis.backend.logic.annotation.FunctionalLogicHandler;
import com.sydac.mmrbem.papis.backend.vehicle.io.properties.IPAPISVehicleOutputsMainInterfaceScreenProperties;
import com.sydac.mmrbem.papis.backend.vehicle.io.properties.IPISBEOutputsMainInterfaceScreenProperties;
import com.sydac.mmrbem.papis.backend.vehicle.io.properties.IPISBEOutputsProperties;
import com.sydac.mmrbem.papis.common.ScreenId;
import com.sydac.mmrbem.papis.common.io.properties.IAppInputsPassengerAlarmScreenProperties;
import com.sydac.mmrbem.papis.common.io.properties.IAppInputsProperties;
import com.sydac.mmrbem.papis.common.io.properties.IAppInputsScreenChangeProperties;
import com.sydac.mmrbem.papis.common.io.properties.IAppOutputsCommonProperties;
import com.sydac.mmrbem.papis.common.io.properties.IAppOutputsScreenChangeProperties;
import com.sydac.mmrbem.papis.common.io.properties.XMLParser;
import com.sydac.mmrbem.papis.common.state.ApplicationConstants;

/**
 * This handler class is used for handling Main Interface Screen data
 * 
 */
@Service
@FunctionalLogicHandler(arguments = { CommsBinding.class, SharedDataModel.class })
public class MainInterfaceScreenHandler extends AbstractFunctionalLogic implements IScreenChangeListener
{
  private static final int MODE_CHANGE_REQUEST = -1;

  @Autowired
  CommsBinding commsBinding;

  @Autowired
  SharedDataModel sharedDataModel;

  private XMLParser xmlParser;

  private int indexCounter = 0;

  private Integer listSize = 7;

  protected MainInterfaceScreenHandler(CommsBinding commsBinding, SharedDataModel sharedDataModel)
  {
    super(commsBinding, IAppInputsProperties.class, IPISBEOutputsProperties.class,
        IPAPISVehicleOutputsMainInterfaceScreenProperties.class);
    this.commsBinding = commsBinding;
    this.sharedDataModel = sharedDataModel;
    this.xmlParser = new XMLParser();
  }

  @Override
  public <T> void appInputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue, int vehicleIndex)
  {
    if (sharedDataModel.getScreenId() == ScreenId.MAIN_INTERFACE_SCREEN.getId())
    {
      if (IAppInputsPassengerAlarmScreenProperties.UP_ARROW_BUTTON.equals(key) && (Integer)newValue > 0)
      {
        decrementCounterMethod();
      }
      else if (IAppInputsPassengerAlarmScreenProperties.DOWN_ARROW_BUTTON.equals(key)
          && (Integer)newValue > 0)
      {
        incrementCounterMethod();
      }
    }
    if (IAppInputsScreenChangeProperties.MUTE_BUTTON.equals(key))
    {
      setApplicationOutputsProperty(IAppOutputsScreenChangeProperties.HEADER_PANEL_STATUS_LABEL_ID,
          (Integer)newValue);
    }
  }

  private void decrementCounterMethod()
  {
    if (indexCounter > 0)
    {
      indexCounter--;
      setApplicationOutputsProperty(IAppOutputsCommonProperties.SELECT_BUTTON, indexCounter);
    }
  }

  private void incrementCounterMethod()
  {
    if (indexCounter < listSize)
    {
      indexCounter++;

      setApplicationOutputsProperty(IAppOutputsCommonProperties.SELECT_BUTTON, indexCounter);
    }
  }

  @Override
  public <T> void papisVehicleOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue,
      int vehicleIndex)
  {
    if (IPAPISVehicleOutputsMainInterfaceScreenProperties.DOOR_OPEN.equals(key) && (Integer)newValue == 1)
    {
      setApplicationOutputsProperty(IAppOutputsCommonProperties.DOOR_OPENING_SIDE,
          ApplicationConstants.DOOR_OPEN.getBytes());
    }
    else if (IPAPISVehicleOutputsMainInterfaceScreenProperties.DOOR_CLOSE.equals(key)
        && (Integer)newValue == 1)
    {
      setApplicationOutputsProperty(IAppOutputsCommonProperties.DOOR_OPENING_SIDE,
          ApplicationConstants.DOOR_CLOSE.getBytes());
    }
  }

  @Override
  public <T> void pisBeOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue, int vehicleIndex)
  {
    if (IPISBEOutputsMainInterfaceScreenProperties.SELECTED_CURRENT_STATION_ID.equals(key)
        && (Integer)newValue > 0)
    {
      setApplicationOutputsProperty(IAppOutputsCommonProperties.CURRENT_STATION_NAME,
          xmlParser.getStationName((Integer)newValue).getBytes());
      sharedDataModel.setCurrentStationId((Integer)newValue);
    }
    else if (IPISBEOutputsMainInterfaceScreenProperties.SELECTED_NEXT_STATION_ID.equals(key))
    {
      if ((Integer)newValue == MODE_CHANGE_REQUEST)
      {
        setApplicationOutputsProperty(IAppOutputsCommonProperties.NEXT_STATION_NAME,
            CommonStrings.BLANK.getBytes());
      }
      else if ((Integer)newValue > 0)
      {
        setApplicationOutputsProperty(IAppOutputsCommonProperties.NEXT_STATION_NAME,
            xmlParser.getStationName((Integer)newValue).getBytes());
        sharedDataModel.setNextStationId((Integer)newValue);
      }
    }
    else if (IPISBEOutputsMainInterfaceScreenProperties.SELECTED_TERMINAL_STATION_ID.equals(key))
    {
      if ((Integer)newValue == MODE_CHANGE_REQUEST)
      {
        setApplicationOutputsProperty(IAppOutputsCommonProperties.TERMINAL_STATION_NAME,
            CommonStrings.BLANK.getBytes());
      }
      else if ((Integer)newValue > 0)
      {
        setApplicationOutputsProperty(IAppOutputsCommonProperties.TERMINAL_STATION_NAME,
            xmlParser.getStationName((Integer)newValue).getBytes());
        sharedDataModel.setTerminalStationId((Integer)newValue);
      }
    }
    else if (IPISBEOutputsMainInterfaceScreenProperties.SELECTED_ROUTE_ID.equals(key))
    {
      if ((Integer)newValue < 1)
      {
        setApplicationOutputsProperty(IAppOutputsCommonProperties.CURRENT_LINE_NAME,
            ApplicationConstants.NO_LINE.getBytes());
      }
      else
      {
        setApplicationOutputsProperty(IAppOutputsCommonProperties.CURRENT_LINE_NAME,
            xmlParser.getCurrentLine((Integer)newValue).getBytes());
        sharedDataModel.setRouteId((Integer)newValue);
      }
    }
    else if (IPISBEOutputsMainInterfaceScreenProperties.SELECTED_MODE.equals(key) && (Integer)newValue > 0)
    {
      setApplicationOutputsProperty(IAppOutputsCommonProperties.ACTIVE_MODE, (Integer)newValue);
    }
    else if (IPISBEOutputsMainInterfaceScreenProperties.DOOR_OPENING_SIDE.equals(key)
        && (Integer)newValue > 0)
    {
      setApplicationOutputsProperty(IAppOutputsCommonProperties.DOOR_STATUS, (Integer)newValue);
    }
  }

  @Override
  public void onEnteringScreen(int screenId)
  {
    indexCounter = 0;

  }

  @Override
  public void onLeavingScreen(int screenId)
  {
    // TODO Auto-generated method stub

  }
}
