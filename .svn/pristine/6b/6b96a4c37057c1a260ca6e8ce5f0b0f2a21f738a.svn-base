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

import java.util.List;

import org.springframework.stereotype.Service;

import com.sydac.foundation.IPropertySetter;
import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.papis.backend.comms.CommsBinding;
import com.sydac.mmrbem.papis.backend.logic.AbstractFunctionalLogic;
import com.sydac.mmrbem.papis.backend.logic.SharedDataModel;
import com.sydac.mmrbem.papis.backend.logic.annotation.FunctionalLogicHandler;
import com.sydac.mmrbem.papis.backend.vehicle.io.properties.IPISBEInputsProperties;
import com.sydac.mmrbem.papis.backend.vehicle.io.properties.IPISBEInputsStationSettingScreensProperties;
import com.sydac.mmrbem.papis.common.ScreenId;
import com.sydac.mmrbem.papis.common.data.StationDetailModel;
import com.sydac.mmrbem.papis.common.io.properties.IAppInputsPassengerAlarmScreenProperties;
import com.sydac.mmrbem.papis.common.io.properties.IAppInputsProperties;
import com.sydac.mmrbem.papis.common.io.properties.IAppInputsScreenChangeProperties;
import com.sydac.mmrbem.papis.common.io.properties.IAppInputsStationSettingScreensProperties;
import com.sydac.mmrbem.papis.common.io.properties.IAppOutputsCommonProperties;
import com.sydac.mmrbem.papis.common.io.properties.IAppOutputsStationSettingScreensProperties;
import com.sydac.mmrbem.papis.common.io.properties.XMLParser;
import com.sydac.mmrbem.papis.common.protos.PAPISProtos;
import com.sydac.mmrbem.papis.common.state.ApplicationConstants;

import javafx.beans.property.ListProperty;
import javafx.beans.property.SimpleListProperty;
import javafx.collections.FXCollections;

/**
 * This handler class is used for Start Station, Terminal Station and Next
 * Station Setting Screen handling.
 * 
 */
@Service
@FunctionalLogicHandler(arguments = { CommsBinding.class, SharedDataModel.class })
public class TerminalStationSelectionScreensHandler extends AbstractFunctionalLogic
    implements IScreenChangeListener
{

  CommsBinding commsBinding;

  SharedDataModel sharedDataModel;

  private XMLParser xmlParser;

  private int startIndex = 0;

  private int endIndex = 0;

  private Integer routeId;

  private Integer listSizePerPage = 8;

  private int terminalStationIndex = 0;

  private ListProperty<StationDetailModel> stationList = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  protected TerminalStationSelectionScreensHandler(CommsBinding commsBinding, SharedDataModel sharedDataModel)
  {
    super(commsBinding, IAppInputsProperties.class, IPISBEInputsProperties.class);
    this.commsBinding = commsBinding;
    this.sharedDataModel = sharedDataModel;
    xmlParser = new XMLParser();
    routeId = sharedDataModel.getRouteId();
  }

  @Override
  public <T> void appInputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue, int vehicleIndex)
  {
    IPropertySetter propertySetter = getPISBEInputsSetter(vehicleIndex);
    routeId = sharedDataModel.getRouteId();
    if (sharedDataModel.getScreenId() == ScreenId.TERMINAL_STATION_SELECTION_SCREEN.getId())
    {
      if (IAppInputsScreenChangeProperties.SCREEN_CHANGE_REQUEST.equals(key))
      {
        if (routeId > 0)
        {
          updateStationList();
        }
      }
      else if (IAppInputsStationSettingScreensProperties.STATION_SELECTION_SCREN_UP_PRESSED.equals(key)
          && (Integer)newValue == ApplicationConstants.UP_PRESSED)
      {
        prevPage();
      }
      else if (IAppInputsStationSettingScreensProperties.STATION_SELECTION_SCREN_DOWN_PRESSED.equals(key)
          && (Integer)newValue == ApplicationConstants.DOWN_PRESSED)
      {
        nextPage();
      }

      else if (IAppInputsStationSettingScreensProperties.SELECTED_TERMINAL_ST_ID_REQUEST.equals(key)
          && (Integer)newValue > 0)
      {
        setInputData(propertySetter, IPISBEInputsStationSettingScreensProperties.TERMINAL_STATION_ID,
            (Integer)newValue);
      }
      else if (IAppInputsPassengerAlarmScreenProperties.UP_ARROW_BUTTON.equals(key) && (Integer)newValue > 0)
      {
        decrementCounterMethod();
      }
      else if (IAppInputsPassengerAlarmScreenProperties.DOWN_ARROW_BUTTON.equals(key)
          && (Integer)newValue > 0)
      {
        incrementCounterMethod();
      }
      else if (IAppInputsStationSettingScreensProperties.TERMINAL_STATION_SELECTED.equals(key)
          && (Integer)newValue > 0)
      {
        terminalStationIndex = (Integer)newValue;
      }
    }
  }

  private void decrementCounterMethod()
  {
    if (terminalStationIndex > 0)
    {
      terminalStationIndex--;

    }
    else if (startIndex != 0)
    {
      terminalStationIndex = listSizePerPage - 1;
      prevPage();

    }
    setApplicationOutputsProperty(IAppOutputsCommonProperties.TERMINAL_STATION_SELECTED_BUTTON,
        terminalStationIndex);
  }

  private void incrementCounterMethod()
  {
    if (terminalStationIndex == listSizePerPage - 1)
    {
      terminalStationIndex = ApplicationConstants.RESET_SELECTED_INDEX;
      nextPage();
    }
    else if (terminalStationIndex < stationList.size() - 1)
    {
      terminalStationIndex++;
    }

    setApplicationOutputsProperty(IAppOutputsCommonProperties.TERMINAL_STATION_SELECTED_BUTTON,
        terminalStationIndex);
  }

  private List<StationDetailModel> getStationList()
  {
    List<String> sequence = xmlParser.getRouteList().get(routeId - 1).getStationSequece();
    return xmlParser.getStationList(sequence);
  }

  private void updateStationList()
  {
    startIndex = 0;
    endIndex = 0;
    if (getStationList() == null || getStationList().isEmpty())
    {
      setList();
    }
    else
    {
      if (getStationList().size() < listSizePerPage)
      {
        endIndex = getStationList().size();
      }
      else
      {
        endIndex = endIndex + listSizePerPage;
        // set Down Button enabled
      }
      setList();
    }
  }

  private void nextPage()
  {
    endIndex = endIndex + listSizePerPage;
    if (getStationList().size() < endIndex)
    {

      endIndex = getStationList().size();
      if (startIndex + listSizePerPage < endIndex)
      {
        startIndex = startIndex + listSizePerPage;
      }
      // Down Btn disabled
    }
    else
    {
      startIndex = startIndex + listSizePerPage;

    }
    // Up Button enabled

    setList();
  }

  private void prevPage()
  {
    if (startIndex > 0)
    {
      endIndex = startIndex;
      startIndex = startIndex - listSizePerPage;
    }
    else
    {
      // Up Btn disabled
    }
    setList();

  }

  private void setList()
  {
    PAPISProtos.StationList.Builder stationListBuilder = PAPISProtos.StationList.newBuilder();
    this.stationList.clear();
    for (int i = startIndex; i < endIndex; i++)
    {
      this.stationList.add(getStationList().get(i));
    }
    for (StationDetailModel station : this.stationList)
    {
      PAPISProtos.StationList.StationDetail.Builder stationDetail = PAPISProtos.StationList.StationDetail
          .newBuilder();
      stationDetail.setStationId(station.getStationId());
      stationDetail.setStationCode(station.getStationCode());
      stationDetail.setStationName(station.getStationName());
      stationListBuilder.addStationDetail(stationDetail);
    }
    setApplicationOutputsProperty(IAppOutputsStationSettingScreensProperties.STATION_LIST,
        stationListBuilder.build().toByteArray());
  }

  @Override
  public void onEnteringScreen(int screenId)
  {
    terminalStationIndex = ApplicationConstants.RESET_SELECTED_INDEX;

  }

  @Override
  public void onLeavingScreen(int screenId)
  {
    // TODO Auto-generated method stub

  }

}
