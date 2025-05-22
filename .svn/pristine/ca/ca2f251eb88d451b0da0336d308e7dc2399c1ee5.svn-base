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

import java.util.ArrayList;
import java.util.List;

import org.springframework.stereotype.Service;

import com.google.protobuf.InvalidProtocolBufferException;
import com.sydac.common.log.Tracer;
import com.sydac.foundation.IPropertySetter;
import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.cbtc.common.protos.CBTCProtos;

import com.sydac.mmrbem.papis.backend.comms.CommsBinding;
import com.sydac.mmrbem.papis.backend.logic.AbstractFunctionalLogic;
import com.sydac.mmrbem.papis.backend.logic.SharedDataModel;
import com.sydac.mmrbem.papis.backend.logic.annotation.FunctionalLogicHandler;
import com.sydac.mmrbem.papis.backend.vehicle.io.models.IPISBEMainInterfaceScreenModel;
import com.sydac.mmrbem.papis.backend.vehicle.io.models.IPISBEOutputsModel;
import com.sydac.mmrbem.papis.backend.vehicle.io.properties.IPISBEInputsProperties;
import com.sydac.mmrbem.papis.backend.vehicle.io.properties.IPISBEInputsSkipStationSettingScreenProperties;
import com.sydac.mmrbem.papis.backend.vehicle.io.properties.IPISBEOutputsMainInterfaceScreenProperties;
import com.sydac.mmrbem.papis.backend.vehicle.io.properties.IPISBEOutputsProperties;
import com.sydac.mmrbem.papis.common.ScreenId;
import com.sydac.mmrbem.papis.common.data.StationDetailModel;
import com.sydac.mmrbem.papis.common.io.properties.IAppInputsProperties;
import com.sydac.mmrbem.papis.common.io.properties.IAppInputsScreenChangeProperties;
import com.sydac.mmrbem.papis.common.io.properties.IAppInputsSkipStationSettingScreenProperties;
import com.sydac.mmrbem.papis.common.io.properties.IAppOutputsSkipStationSettingScreenProperties;
import com.sydac.mmrbem.papis.common.io.properties.XMLParser;
import com.sydac.mmrbem.papis.common.protos.PAPISProtos;
import com.sydac.mmrbem.papis.common.protos.PAPISProtos.SkipIDList;
import com.sydac.mmrbem.papis.common.protos.PAPISProtos.SkipIDList.SkipId;
import com.sydac.mmrbem.papis.common.protos.PAPISProtos.StationList.StationDetail;
import com.sydac.mmrbem.papis.common.state.ApplicationConstants;

import javafx.beans.property.ListProperty;
import javafx.beans.property.SimpleListProperty;
import javafx.collections.FXCollections;

/**
 * This handler class is used for Skip Station Setting Screen handling.
 * 
 */
@Service
@FunctionalLogicHandler(arguments = { CommsBinding.class, SharedDataModel.class })
public class SkipStationSettingScreenHandler extends AbstractFunctionalLogic
{

  IPISBEMainInterfaceScreenModel pisBeOutPutModel;

  CommsBinding commsBinding;

  SharedDataModel sharedDataModel;

  private XMLParser xmlParser;

  private Integer routeId;

  private int startIndex = 0;

  private int endIndex = 0;

  private int skipStartIndex = 0;

  private int skipEndIndex = 0;

  private int listSizePerPage = 6;

  private boolean stationSkippedOrUnskipped;

  private List<Integer> skippedStationIdList = new ArrayList<>();

  private List<Integer> unskippedStationIdList = new ArrayList<>();

  private ListProperty<StationDetailModel> stationList = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private ListProperty<StationDetailModel> skipStationList = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private SkipIDList skipIDList;

  protected SkipStationSettingScreenHandler(CommsBinding commsBinding, SharedDataModel sharedDataModel)
  {
    super(commsBinding, IAppInputsProperties.class, IPISBEInputsProperties.class,
        IPISBEOutputsProperties.class);
    this.commsBinding = commsBinding;
    this.sharedDataModel = sharedDataModel;

    initalizePisBeOutputModel();
    this.xmlParser = new XMLParser();
  }

  @Override
  public <T> void appInputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue, int vehicleIndex)
  {
    IPropertySetter propertySetter = getPISBEInputsSetter(vehicleIndex);
    if (IAppInputsScreenChangeProperties.SCREEN_CHANGE_REQUEST.equals(key)
        && (Integer)newValue == ScreenId.SKIP_STATION_SETTING_SCREEN.getId())
    {
      onEnteringScreen();
      routeId = sharedDataModel.getRouteId();
      updateLists();
    }
    else if (IAppInputsSkipStationSettingScreenProperties.SKIP_SCREEN_STATION_LIST_UP_PRESSED.equals(key)
        && (Integer)newValue == ApplicationConstants.UP_PRESSED)
    {
      prevPage();
    }
    else if (IAppInputsSkipStationSettingScreenProperties.SKIP_SCREEN_STATION_LIST_DOWN_PRESSED.equals(key)
        && (Integer)newValue == ApplicationConstants.DOWN_PRESSED)
    {
      nextPage();
    }
    else if (IAppInputsSkipStationSettingScreenProperties.SKIP_SCREEN_SKIP_LIST_UP_PRESSED.equals(key)
        && (Integer)newValue == ApplicationConstants.UP_PRESSED)
    {
      prevSkipPage();
    }
    else if (IAppInputsSkipStationSettingScreenProperties.SKIP_SCREEN_SKIP_LIST_DOWN_PRESSED.equals(key)
        && (Integer)newValue == ApplicationConstants.DOWN_PRESSED)
    {
      nextSkipPage();
    }
    else if (IAppInputsSkipStationSettingScreenProperties.STATION_ID_ADDED_TO_SKIP_LIST.equals(key)
        && (Integer)newValue > 0)
    {
      xmlParser.updateSkipStation((Integer)newValue);
      skippedStationIdList.add((Integer)newValue);
      updateLists();
    }
    else if (IAppInputsSkipStationSettingScreenProperties.STATION_ID_REMOVED_FROM_SKIP_LIST.equals(key)
        && (Integer)newValue > 0)
    {
      xmlParser.updateSkipStation((Integer)newValue);
      unskippedStationIdList.add((Integer)newValue);
      updateLists();
    }
    else if (IAppInputsSkipStationSettingScreenProperties.SKIP_SCREEN_OK_BUTTON_PRESSED.equals(key)
        && (Integer)newValue > 0)
    {
      PAPISProtos.SkipIDList.Builder skipIdList = PAPISProtos.SkipIDList.newBuilder();
      for (int i = 0; i < getSkipStationList().size(); i++)
      {
        PAPISProtos.SkipIDList.SkipId.Builder skipStationId = PAPISProtos.SkipIDList.SkipId.newBuilder();
        skipStationId.setStationId(getSkipStationList().get(i).getStationId());
        skipIdList.addIdList(skipStationId);
      }
      setInputData(propertySetter, IPISBEInputsSkipStationSettingScreenProperties.SKIP_STATION_LIST,
          skipIdList.build().toByteArray());
      stationSkippedOrUnskipped = true;
    }
    else if (IAppInputsSkipStationSettingScreenProperties.SKIP_SCREEN_BACK_BUTTON_PRESSED.equals(key)
        && (Integer)newValue > 0)
    {
      onLeavingScreen();
    }
  }

  private void updateLists()
  {
    if (routeId >= 0)
    {
      updateStationList();
      updateSkipStationList();
    }
  }

  private List<StationDetailModel> getStationList()
  {
    List<String> sequence = null;
    if (routeId >= 0)
    {
      sequence = xmlParser.getRouteList().get(routeId - 1).getStationSequece();
    }
    return xmlParser.getUnskippedStationList(sequence);

  }

  private void updateStationList()
  {
    startIndex = 0;
    endIndex = 0;
    if (getStationList().isEmpty())
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
    setApplicationOutputsProperty(IAppOutputsSkipStationSettingScreenProperties.SKIP_SCREEN_STATION_LIST,
        stationListBuilder.build().toByteArray());
  }

  private List<StationDetailModel> getSkipStationList()
  {

    List<String> skipSequence = xmlParser.getRouteList().get(routeId - 1).getStationSequece();

    return xmlParser.getSkippedStationList(skipSequence);
  }

  private void updateSkipStationList()
  {
    skipStartIndex = 0;
    skipEndIndex = 0;
    if (getSkipStationList().isEmpty())
    {
      setSkipList();
    }
    else
    {
      if (getSkipStationList().size() < listSizePerPage)
      {
        skipEndIndex = getSkipStationList().size();
      }
      else
      {
        skipEndIndex = skipEndIndex + listSizePerPage;
        // set Down Button enabled
      }
      setSkipList();
    }
  }

  private void nextSkipPage()
  {
    if (!getSkipStationList().isEmpty())
    {
      skipEndIndex = skipEndIndex + listSizePerPage;
      if (getSkipStationList().size() < skipEndIndex)
      {
        skipEndIndex = getSkipStationList().size();
        if (skipStartIndex + listSizePerPage < skipEndIndex)
        {
          skipStartIndex = skipStartIndex + listSizePerPage;
        }
        // Down Btn disabled
      }
      else
      {
        skipStartIndex = skipStartIndex + listSizePerPage;
      }
      // Up Button enabled
      setSkipList();
    }
  }

  private void prevSkipPage()
  {
    if (!getSkipStationList().isEmpty())
    {
      if (skipStartIndex > 0)
      {
        skipEndIndex = skipStartIndex;
        skipStartIndex = skipStartIndex - listSizePerPage;
      }
      else
      {
        // Up Btn disabled
      }
      setSkipList();
    }
  }

  private void setSkipList()
  {
    PAPISProtos.StationList.Builder skipStationListBuilder = PAPISProtos.StationList.newBuilder();
    this.skipStationList.clear();
    for (int i = skipStartIndex; i < skipEndIndex; i++)
    {
      this.skipStationList.add(getSkipStationList().get(i));
    }
    for (StationDetailModel station : this.skipStationList)
    {
      PAPISProtos.StationList.StationDetail.Builder skipstationDetail = PAPISProtos.StationList.StationDetail
          .newBuilder();
      skipstationDetail.setStationId(station.getStationId());
      skipstationDetail.setStationCode(station.getStationCode());
      skipstationDetail.setStationName(station.getStationName());
      skipStationListBuilder.addStationDetail(skipstationDetail);
    }
    setApplicationOutputsProperty(IAppOutputsSkipStationSettingScreenProperties.SKIP_STATION_LIST,
        skipStationListBuilder.build().toByteArray());
  }

  public void onEnteringScreen()
  {
    skippedStationIdList.clear();
    unskippedStationIdList.clear();
    stationSkippedOrUnskipped = false;
  }

  public void onLeavingScreen()
  {
    if (!stationSkippedOrUnskipped && !skippedStationIdList.isEmpty())
    {
      for (int index = 0; index < skippedStationIdList.size(); index++)
      {
        xmlParser.updateSkipStation(skippedStationIdList.get(index));
      }
    }
    if (!stationSkippedOrUnskipped && !unskippedStationIdList.isEmpty())
    {
      for (int index = 0; index < unskippedStationIdList.size(); index++)
      {
        xmlParser.updateSkipStation(unskippedStationIdList.get(index));
      }
    }
    skippedStationIdList.clear();
    unskippedStationIdList.clear();
  }

  @Override
  public <T> void pisBeOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue, int vehicleIndex)
  {
    initalizePisBeOutputModel();
    if (IPISBEOutputsMainInterfaceScreenProperties.SKIP_STATION_LIST.equals(key))
    {

      if (getActiveVehicleIndex() == vehicleIndex)
      {

        showSkipStationInfo();

        for (int index = 0; index < skippedStationIdList.size(); index++)
        {
          xmlParser.updateSkipStation(skippedStationIdList.get(index));
        }
        if (routeId != null)
        {
          setSkipFromTCMSList();
        }
      }

    }
  }

  private void showSkipStationInfo()
  {
    byte[] skipStationInfo = this.pisBeOutPutModel == null ? new byte[0]
        : this.pisBeOutPutModel.getSkipStationList();

    if (skipStationInfo.length != 0)
    {

      try
      {

        PAPISProtos.SkipIDList trainDockingInfo = PAPISProtos.SkipIDList.parseFrom(skipStationInfo);

        skippedStationIdList.clear();
        if (stationList != null)
        {

          for (SkipId stationDetail : trainDockingInfo.getIdListList())
          {

            skippedStationIdList.add(stationDetail.getStationId());
          }
        }

      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }

  }

  private void initalizePisBeOutputModel()
  {

    if (this.pisBeOutPutModel == null)
    {
      this.pisBeOutPutModel = (IPISBEOutputsModel)commsBinding.getPISBEOutputsModel()
          .get(getActiveVehicleIndex());
    }
  }

  private void setSkipFromTCMSList()
  {
    PAPISProtos.StationList.Builder skipStationListBuilder = PAPISProtos.StationList.newBuilder();
    this.skipStationList.clear();
    for (int index = 0; index < getSkipStationList().size(); index++)
    {
      this.skipStationList.add(getSkipStationList().get(index));
    }
    for (StationDetailModel station : this.skipStationList)
    {
      PAPISProtos.StationList.StationDetail.Builder skipstationDetail = PAPISProtos.StationList.StationDetail
          .newBuilder();
      skipstationDetail.setStationId(station.getStationId());
      skipstationDetail.setStationCode(station.getStationCode());
      skipstationDetail.setStationName(station.getStationName());
      skipStationListBuilder.addStationDetail(skipstationDetail);
    }
    setApplicationOutputsProperty(IAppOutputsSkipStationSettingScreenProperties.SKIP_STATION_LIST,
        skipStationListBuilder.build().toByteArray());
  }
}
