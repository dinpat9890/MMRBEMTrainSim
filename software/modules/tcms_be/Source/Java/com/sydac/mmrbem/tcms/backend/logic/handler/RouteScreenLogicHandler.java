/*
 * ==================================================================
 * 
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.tcms.backend.logic.handler;

import java.util.List;

import org.springframework.stereotype.Service;

import com.sydac.foundation.IPropertySetter;
import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.tcms.backend.comms.CommsBinding;
import com.sydac.mmrbem.tcms.backend.logic.AbstractFunctionalLogic;
import com.sydac.mmrbem.tcms.backend.logic.SharedDataModel;
import com.sydac.mmrbem.tcms.backend.logic.annotation.FunctionalLogicHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.io.properties.IPAPISVehicleOutputsOperatingScreenProperties;
import com.sydac.mmrbem.tcms.backend.vehicle.io.properties.IPISBEInputsProperties;
import com.sydac.mmrbem.tcms.backend.vehicle.io.properties.IPISBEInputsSystemSettingScreenProperties;
import com.sydac.mmrbem.tcms.backend.vehicle.io.properties.IPISBEOutputsOperatingScreenProperties;
import com.sydac.mmrbem.tcms.backend.vehicle.io.properties.IPISBEOutputsProperties;
import com.sydac.mmrbem.tcms.common.data.StationDetailModel;
import com.sydac.mmrbem.tcms.common.io.properties.IAppInputsProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppInputsRouteScreenProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsOperatingScreenProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsRouteScreenProperties;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto;
import com.sydac.mmrbem.tcms.common.state.ApplicationConstants;
import com.sydac.mmrbem.tcms.common.state.KeyPadEnum;
import com.sydac.mmrbem.tcms.common.state.TCMSConstants;
import com.sydac.mmrbem.tcms.common.state.TCMSModeEnum;
import com.sydac.mmrbem.tcms.common.utils.XMLParser;

import javafx.beans.property.ListProperty;
import javafx.beans.property.SimpleListProperty;
import javafx.collections.FXCollections;

/**
 * This handler class is used for Route Screen change handling.
 * 
 */
@Service
@FunctionalLogicHandler(arguments = { CommsBinding.class, SharedDataModel.class })
public class RouteScreenLogicHandler extends AbstractFunctionalLogic
{
  private SharedDataModel sharedModel;

  private XMLParser xmlParser;

  private Integer routeId;

  private boolean startStationSelected;

  private boolean destStationSelected;

  private String selectedStationName;

  private ListProperty<StationDetailModel> stationList = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private ListProperty<StationDetailModel> allStationList = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  public RouteScreenLogicHandler(CommsBinding commsBinding, SharedDataModel aSharedModel)
  {
    super(commsBinding, IAppInputsProperties.class, IPISBEInputsProperties.class,
        IPISBEOutputsProperties.class, IPAPISVehicleOutputsOperatingScreenProperties.class);
    this.sharedModel = aSharedModel;
    xmlParser = new XMLParser();

    routeId = sharedModel.getRouteId();
  }

  @Override
  public <T> void appInputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue, int vehicleIndex)
  {
    IPropertySetter propertySetter = getPISBEInputsSetter(vehicleIndex);

    routeId = sharedModel.getRouteId();
    
 
    if (routeId > 0)
    {
      allStationList();
    }
    if (IAppInputsRouteScreenProperties.ROUTE_SCREEN_MODE_SELECTION_REQUEST.equals(key)
        && (Integer)newValue > -1)
    {

      setInputData(propertySetter, IPISBEInputsSystemSettingScreenProperties.STATION_ANNOUNCEMENT_MODE,
          (Integer)newValue);
    }
    else if (IAppInputsRouteScreenProperties.ROUTE_SCREEN_KEYPAD_BUTTON_REQUEST.equals(key)
        && (Integer)newValue > -1)
    {
      updateTrainId((Integer)newValue);
    }
    else if (IAppInputsRouteScreenProperties.STATION_ENTER_REQ.equals(key) && (Integer)newValue > -1)
    {
      updateStations();
    }
    else if (IAppInputsRouteScreenProperties.DEST_STATION_BUTTON_REQ.equals(key) && (Integer)newValue > -1)
    {
      destStationSelected = true;
      startStationSelected = false;
    }
    else if (IAppInputsRouteScreenProperties.START_STATION_BUTTON_REQ.equals(key) && (Integer)newValue > -1)
    {
      startStationSelected = true;
      destStationSelected = false;
    }
    else if (IAppInputsRouteScreenProperties.START_STATION_SElECTED_REQ.equals(key) && (Integer)newValue > 0)
    {

      if (xmlParser.getStationName((Integer)newValue).getBytes() != null)
      {
        selectedStationName = xmlParser.getStationName((Integer)newValue);
        setApplicationOutputsProperty(IAppOutputsRouteScreenProperties.SELECTED_STATION_NAME,
            selectedStationName.getBytes());
      }
    }
    else if (IAppInputsRouteScreenProperties.TRAIN_UNDER_EVAC_SET_BUTTON_REQ.equals(key)
        && (Integer)newValue > -1)
    {
      if ((Integer)newValue == TCMSConstants.ACTIVE)
      {

        setInputData(propertySetter, IPISBEInputsSystemSettingScreenProperties.INSTRUCTOR_ANNOUNCEMENT_ID,
            ApplicationConstants.TRAIN_UNDER_EVAC);
      }
      else
      {

        setInputData(propertySetter, IPISBEInputsSystemSettingScreenProperties.INSTRUCTOR_ANNOUNCEMENT_ID, 0);
        setInputData(propertySetter, IPISBEInputsSystemSettingScreenProperties.STOP_SPECIAL_ANNOUNCEMNT, 1);
      }

      setApplicationOutputsProperty(IAppOutputsRouteScreenProperties.TRAIN_UNDER_EVAC_SET_BUTTON_STATE,
          (Integer)newValue);

    }
    else if (IAppInputsRouteScreenProperties.TRAIN_OUT_OF_SERVICE_SET_BUTTON_REQ.equals(key)
        && (Integer)newValue > -1)
    {
      if ((Integer)newValue == TCMSConstants.ACTIVE)
      {

        setInputData(propertySetter, IPISBEInputsSystemSettingScreenProperties.INSTRUCTOR_ANNOUNCEMENT_ID,
            ApplicationConstants.TRAIN_OUT_OF_SERVICE);

      }
      else
      {
        setInputData(propertySetter, IPISBEInputsSystemSettingScreenProperties.INSTRUCTOR_ANNOUNCEMENT_ID, 0);
        setInputData(propertySetter, IPISBEInputsSystemSettingScreenProperties.STOP_SPECIAL_ANNOUNCEMNT, 1);
      }
      setApplicationOutputsProperty(IAppOutputsRouteScreenProperties.TRAIN_OUT_OF_SERVICE_SET_BUTTON_STATE,
          (Integer)newValue);

    }
    else if (IAppInputsRouteScreenProperties.DELAY_IN_SERVICE_BUTTON_REQ.equals(key)
        && (Integer)newValue > -1)
    {
      if ((Integer)newValue == TCMSConstants.ACTIVE)
      {
        setInputData(propertySetter, IPISBEInputsSystemSettingScreenProperties.INSTRUCTOR_ANNOUNCEMENT_ID,
            ApplicationConstants.DELAY_IN_SERVICE);
      }
      else
      {
        setInputData(propertySetter, IPISBEInputsSystemSettingScreenProperties.INSTRUCTOR_ANNOUNCEMENT_ID, 0);
        setInputData(propertySetter, IPISBEInputsSystemSettingScreenProperties.STOP_SPECIAL_ANNOUNCEMNT, 1);
      }
      setApplicationOutputsProperty(IAppOutputsRouteScreenProperties.DELAY_IN_SERVICE_BUTTON_STATE,
          (Integer)newValue);

    }
    else if (IAppInputsRouteScreenProperties.TRAIN_HOLD_BUTTON_REQ.equals(key) && (Integer)newValue > -1)
    {
      if ((Integer)newValue == TCMSConstants.ACTIVE)
      {
        setInputData(propertySetter, IPISBEInputsSystemSettingScreenProperties.INSTRUCTOR_ANNOUNCEMENT_ID,
            ApplicationConstants.TRAIN_HOLD);

      }
      else
      {
        setInputData(propertySetter, IPISBEInputsSystemSettingScreenProperties.INSTRUCTOR_ANNOUNCEMENT_ID, 0);
        setInputData(propertySetter, IPISBEInputsSystemSettingScreenProperties.STOP_SPECIAL_ANNOUNCEMNT, 1);
      }
      setApplicationOutputsProperty(IAppOutputsRouteScreenProperties.TRAIN_HOLD_BUTTON_STATE,
          (Integer)newValue);

    }
    else if (IAppInputsRouteScreenProperties.START_SERVICE_BUTTON_REQ.equals(key) && (Integer)newValue > -1)
    {
      setApplicationOutputsProperty(IAppOutputsRouteScreenProperties.START_SERVICE_BUTTON_STATE,
          (Integer)newValue);
      if ((Integer)newValue == TCMSConstants.NOT_ACTIVE)
      {
        setInputData(propertySetter, IPISBEInputsSystemSettingScreenProperties.STOP_SPECIAL_ANNOUNCEMNT, 1);

      }

    }
    else if (IAppInputsRouteScreenProperties.SKIP_STATION_BUTTON_REQ.equals(key) && (Integer)newValue > -1)
    {

    }

  }

  private void updateStations()
  {
    if (startStationSelected)
    {
      setApplicationOutputsProperty(IAppOutputsRouteScreenProperties.ROUTE_SCREEN_START_ST_ID,
          selectedStationName.getBytes());

    }
    else if (destStationSelected)
    {
      setApplicationOutputsProperty(IAppOutputsRouteScreenProperties.ROUTE_SCREEN_DEST_ST_ID,
          selectedStationName.getBytes());
    }

  }

  @Override
  public <T> void pisBeOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue, int vehicleIndex)
  {
    if (IPISBEOutputsOperatingScreenProperties.SELECTED_START_STATION_ID.equals(key))
    {
      if ((Integer)newValue > 0)
      {
        String stationId = newValue + TCMSConstants.ROUTE_SCREEN_HYPHEN_STRING
            + xmlParser.getStationName((Integer)newValue);
        setApplicationOutputsProperty(IAppOutputsRouteScreenProperties.ROUTE_SCREEN_START_ST_ID,
            stationId.getBytes());
        sharedModel.setStartStationId((Integer)newValue);
      }
      else
      {
        setApplicationOutputsProperty(IAppOutputsOperatingScreenProperties.START_STATION,
            (ApplicationConstants.STATION_DETAIL_NO_DATA).getBytes());
        sharedModel.setCurrentStationId(0);
      }
    }
    else if (IPISBEOutputsOperatingScreenProperties.SELECTED_TERMINAL_STATION_ID.equals(key))
    {
      if ((Integer)newValue > 0)
      {
        String stationId = newValue + TCMSConstants.ROUTE_SCREEN_HYPHEN_STRING
            + xmlParser.getStationName((Integer)newValue);
        setApplicationOutputsProperty(IAppOutputsRouteScreenProperties.ROUTE_SCREEN_DEST_ST_ID,
            stationId.getBytes());
        sharedModel.setTerminalStationId((Integer)newValue);
      }
      else
      {
        setApplicationOutputsProperty(IAppOutputsOperatingScreenProperties.DESTINATION_STATION,
            (ApplicationConstants.STATION_DETAIL_NO_DATA).getBytes());
        sharedModel.setTerminalStationId(0);
      }
    }
    else if (IPISBEOutputsOperatingScreenProperties.SELECTED_ROUTE_ID_PSD.equals(key))
    {
      sharedModel.setRouteId((Integer)newValue);
    }
    else if (IPISBEOutputsOperatingScreenProperties.SELECTED_MODE.equals(key) && (Integer)newValue > 0)
    {
      setApplicationOutputsProperty(IAppOutputsRouteScreenProperties.TCMS_PAPIS_SELECTED_MODE,
          TCMSModeEnum.valueOf((Integer)newValue).getModeId());
    }
    else if (IPISBEOutputsOperatingScreenProperties.SELECTED_TRAIN_ID.equals(key))
    {
      String trainId;
      if ((Integer)newValue <= 0)
      {
        trainId = TCMSConstants.NO_TRAIN_ID_SELECTED;
      }
      else
      {
        trainId = String.valueOf(newValue);
      }
      setApplicationOutputsProperty(IAppOutputsRouteScreenProperties.ROUTE_SCREEN_TRAIN_ID,
          trainId.getBytes());
    }
  }

  private void updateTrainId(Integer keyPress)
  {
    switch (KeyPadEnum.valueOf(keyPress))
    {
    case DELETE:
      removeUserIdDigit();
      break;
    case CLEAR:
      sharedModel.setRouteTrainId(ApplicationConstants.BLANK);
      setApplicationOutputsProperty(IAppOutputsRouteScreenProperties.ROUTE_SCREEN_TRAIN_ID,
          ApplicationConstants.BLANK.getBytes());
      break;
    case ENTER:
      validateLoginUserId();
      break;
    default:
      updateUserIdText(keyPress);
      break;
    }
  }

  private void removeUserIdDigit()
  {
    if (sharedModel.getRouteTrainId().length() > 0)
    {
      String id = sharedModel.getRouteTrainId();
      id = id.substring(0, id.length() - 1);
      setApplicationOutputsProperty(IAppOutputsRouteScreenProperties.SEMI_AUTO_TRAIN_ID,
          (id.equals(ApplicationConstants.BLANK) ? "0" : id).getBytes()); //$NON-NLS-1$
      sharedModel.setRouteTrainId(id);
    }
  }

  private void validateLoginUserId()
  {
    if (sharedModel.getRouteTrainId().length() == ApplicationConstants.USER_ID_LENGTH)
    {

      setApplicationOutputsProperty(IAppOutputsRouteScreenProperties.ROUTE_SCREEN_TRAIN_ID,
          sharedModel.getRouteTrainId().getBytes());
    }

    // sharedModel.setUserId(ApplicationConstants.BLANK);
  }

  private void updateUserIdText(Integer keyPress)
  {
    if (sharedModel.getRouteTrainId().length() < ApplicationConstants.DIGIT_LENGTH)
    {
      String id = sharedModel.getRouteTrainId().concat(String.valueOf(keyPress));
      setApplicationOutputsProperty(IAppOutputsRouteScreenProperties.SEMI_AUTO_TRAIN_ID, id.getBytes());
      sharedModel.setRouteTrainId(id);
    }
  }

  private void allStationList()
  {

    TCMSProto.StationList.Builder stationListBuilder = TCMSProto.StationList.newBuilder();
    this.allStationList.clear();
    allStationList.addAll(getStationList());
    for (StationDetailModel station : this.allStationList)
    {
      TCMSProto.StationList.StationDetail.Builder stationDetail = TCMSProto.StationList.StationDetail
          .newBuilder();
      stationDetail.setStationId(station.getStationId());
      stationDetail.setStationCode(station.getStationCode());
      stationDetail.setStationName(station.getStationName());
      stationListBuilder.addStationDetail(stationDetail);
    }

    setApplicationOutputsProperty(IAppOutputsRouteScreenProperties.STATION_LIST,
        stationListBuilder.build().toByteArray());
  }

  private List<StationDetailModel> getStationList()
  {
    List<String> sequence = xmlParser.getRouteList().get(routeId - 1).getStationSequece();
    return xmlParser.getStationList(sequence);
  }

}
