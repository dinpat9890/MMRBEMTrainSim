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
import com.sydac.mmrbem.papis.backend.vehicle.io.properties.IPISBEInputsManualAnnouncementScreenProperties;
import com.sydac.mmrbem.papis.backend.vehicle.io.properties.IPISBEInputsProperties;
import com.sydac.mmrbem.papis.common.ScreenId;
import com.sydac.mmrbem.papis.common.data.StationDetailModel;
import com.sydac.mmrbem.papis.common.io.properties.IAppInputsManualModeSettingScreenProperties;
import com.sydac.mmrbem.papis.common.io.properties.IAppInputsProperties;
import com.sydac.mmrbem.papis.common.io.properties.IAppInputsScreenChangeProperties;
import com.sydac.mmrbem.papis.common.io.properties.IAppOutputsManualModeSettingScreenProperties;
import com.sydac.mmrbem.papis.common.io.properties.XMLParser;
import com.sydac.mmrbem.papis.common.protos.PAPISProtos;
import com.sydac.mmrbem.papis.common.protos.PAPISProtos.ManualAnnouncement.Door;
import com.sydac.mmrbem.papis.common.protos.PAPISProtos.ManualAnnouncement.MessageType;
import com.sydac.mmrbem.papis.common.state.ApplicationConstants;
import com.sydac.mmrbem.papis.common.state.DoorOpeningSideEnum;
import com.sydac.mmrbem.papis.common.state.ManualAnnouncementMessageType;

import javafx.beans.property.ListProperty;
import javafx.beans.property.SimpleListProperty;
import javafx.collections.FXCollections;

/**
 * This handler class is used for Manual Mode Announcement Screen handling.
 * 
 */
@Service
@FunctionalLogicHandler(arguments = { CommsBinding.class, SharedDataModel.class })
public class ManualModeAnnouncementScreenHandler extends AbstractFunctionalLogic
{

  CommsBinding commsBinding;

  SharedDataModel sharedDataModel;

  private XMLParser xmlParser;

  private IPropertySetter propertySetter;

  private Integer routeId;

  private int startIndex = 0;

  private int endIndex = 0;

  private int listSizePerPage = 6;

  private DoorOpeningSideEnum doorOpenSide = DoorOpeningSideEnum.LEFT;

  private ManualAnnouncementMessageType messageType;

  private Integer selectedCurrentStationId;

  private ListProperty<StationDetailModel> stationList = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  protected ManualModeAnnouncementScreenHandler(CommsBinding commsBinding, SharedDataModel sharedDataModel)
  {
    super(commsBinding, IAppInputsProperties.class, IPISBEInputsProperties.class);
    this.commsBinding = commsBinding;
    this.sharedDataModel = sharedDataModel;
    this.xmlParser = new XMLParser();
  }

  @Override
  public <T> void appInputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue, int vehicleIndex)
  {
    propertySetter = getPISBEInputsSetter(vehicleIndex);
    if (IAppInputsScreenChangeProperties.SCREEN_CHANGE_REQUEST.equals(key)
        && (Integer)newValue == ScreenId.MANUAL_MODE_SETTING_SCREEN.getId())
    {
      routeId = sharedDataModel.getRouteId();

      if (routeId > 0)
      {
        updateStationList();
      }
    }
    else if (IAppInputsManualModeSettingScreenProperties.MANUAL_MODE_STATION_LIST_UP_PRESSED.equals(key)
        && (Integer)newValue == ApplicationConstants.UP_PRESSED)
    {
      prevPage();
    }
    else if (IAppInputsManualModeSettingScreenProperties.MANUAL_MODE_STATION_LIST_DOWN_PRESSED.equals(key)
        && (Integer)newValue == ApplicationConstants.DOWN_PRESSED)
    {
      nextPage();
    }
    else if (IAppInputsManualModeSettingScreenProperties.MANUAL_MODE_SELECTED_CURRENT_STATION_ID.equals(key)
        && (Integer)newValue > 0)
    {
      selectedCurrentStationId = (Integer)newValue;
    }
    else if (IAppInputsManualModeSettingScreenProperties.MANUAL_MODE_SELECTED_DOOR_OPENING_SIDE.equals(key)
        && (Integer)newValue > -1)
    {
      doorOpenSide = DoorOpeningSideEnum.valueOf((Integer)newValue);
    }
    else if (IAppInputsManualModeSettingScreenProperties.MANUAL_MODE_SELECTED_MESSAGE_TYPE.equals(key)
        && (Integer)newValue > -1)
    {
      messageType = ManualAnnouncementMessageType.valueOf((Integer)newValue);
      updateManualAnnouncementRequest();
    }
  }

  private void updateManualAnnouncementRequest()
  {

    if (selectedCurrentStationId != null)
    {
      PAPISProtos.ManualAnnouncement.Builder manualAnnouncementBuilder = PAPISProtos.ManualAnnouncement
          .newBuilder();
      int lastStationId = getStationList().get(getStationList().size() - 1).getStationId();
      manualAnnouncementBuilder.setStartStationId(selectedCurrentStationId);
      if (lastStationId == selectedCurrentStationId)
      {
        manualAnnouncementBuilder.setNextStationId(selectedCurrentStationId);
      }
      else
      {
        manualAnnouncementBuilder.setNextStationId(selectedCurrentStationId + 1);
      }

      if (doorOpenSide.equals(DoorOpeningSideEnum.LEFT))
      {
        manualAnnouncementBuilder.setDoorSideOpen(Door.LEFT_DOOR);
      }
      else
      {
        manualAnnouncementBuilder.setDoorSideOpen(Door.RIGHT_DOOR);
      }
      if (messageType.equals(ManualAnnouncementMessageType.ARRIVAL))
      {
        manualAnnouncementBuilder.setArrivalDepartureType(MessageType.ARRIVAL_TYP);
      }
      else
      {
        manualAnnouncementBuilder.setArrivalDepartureType(MessageType.DEPARTURE_TYP);
      }
      setInputData(propertySetter, IPISBEInputsManualAnnouncementScreenProperties.ARRIVE_DEPART_MSG,
          manualAnnouncementBuilder.build().toByteArray());
    }

  }

  private List<StationDetailModel> getStationList()
  {
    List<String> sequence = xmlParser.getRouteList().get(routeId - 1).getStationSequece();
    return xmlParser.getUnskippedStationList(sequence);
  }

  private void updateStationList()
  {
    if (!getStationList().isEmpty())
    {
      setApplicationOutputsProperty(IAppOutputsManualModeSettingScreenProperties.LAST_STATION_ID,
          getStationList().get(getStationList().size() - 1).getStationId());
      startIndex = 0;
      endIndex = 0;
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

    setApplicationOutputsProperty(
        IAppOutputsManualModeSettingScreenProperties.MANUAL_MODE_SCREEN_STATION_LIST,
        stationListBuilder.build().toByteArray());
  }
}
