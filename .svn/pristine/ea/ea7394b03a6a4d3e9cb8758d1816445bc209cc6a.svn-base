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

import java.util.ArrayList;
import java.util.List;

import org.springframework.stereotype.Service;

import com.sydac.foundation.IPropertySetter;
import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.tcms.backend.comms.CommsBinding;
import com.sydac.mmrbem.tcms.backend.logic.AbstractFunctionalLogic;
import com.sydac.mmrbem.tcms.backend.logic.SharedDataModel;
import com.sydac.mmrbem.tcms.backend.logic.annotation.FunctionalLogicHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.io.properties.IPISBEInputsProperties;
import com.sydac.mmrbem.tcms.backend.vehicle.io.properties.IPISBEInputsSystemSettingScreenProperties;
import com.sydac.mmrbem.tcms.common.ScreenId;
import com.sydac.mmrbem.tcms.common.data.StationDetailModel;
import com.sydac.mmrbem.tcms.common.io.properties.IAppInputsProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppInputsRouteScreenProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppInputsScreenChangeProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsRouteScreenProperties;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto;
import com.sydac.mmrbem.tcms.common.utils.XMLParser;

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

  private ListProperty<StationDetailModel> line2StationList = new SimpleListProperty<>(
      FXCollections.observableArrayList());
  
  private ListProperty<StationDetailModel> line7StationList = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private ListProperty<StationDetailModel> skipStationList = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  protected SkipStationSettingScreenHandler(CommsBinding commsBinding, SharedDataModel sharedDataModel)
  {
    super(commsBinding, IAppInputsProperties.class, IPISBEInputsProperties.class);
    this.commsBinding = commsBinding;
    this.sharedDataModel = sharedDataModel;
    this.xmlParser = new XMLParser();
  }

  @Override
  public <T> void appInputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue, int vehicleIndex)
  {
    IPropertySetter propertySetter = getPISBEInputsSetter(vehicleIndex);
    if (IAppInputsScreenChangeProperties.TCMS_SCREEN_CHANGE_REQUEST.equals(key)
        && (Integer)newValue == ScreenId.SKIP_STATION_SCREEN.getId())
    {
      
      routeId = sharedDataModel.getRouteId();
      updateLists();
    }

    else if (IAppInputsRouteScreenProperties.SKIP_STTAION_ID_REQ.equals(key) && (Integer)newValue > 0)
    {
     
      xmlParser.updateSkipStation((Integer)newValue);
      skippedStationIdList.add((Integer)newValue);
     
      System.out.println("SkipStationSettingScreenHandler.appInputsPropertyUpdated()" + skippedStationIdList.size());
      
      TCMSProto.SkipIDList.Builder skipIdList = TCMSProto.SkipIDList.newBuilder();
      for (int i = 0; i < skippedStationIdList.size(); i++)
      {
        TCMSProto.SkipIDList.SkipId.Builder skipStationId = TCMSProto.SkipIDList.SkipId.newBuilder();
        skipStationId.setStationId(skippedStationIdList.get(i));
        skipIdList.addIdList(skipStationId);
      }
      setInputData(propertySetter, IPISBEInputsSystemSettingScreenProperties.SKIP_STATION_LIST,
          skipIdList.build().toByteArray());
      setSkipList();
    }

  }

  private void updateLists()
  {
      setLine2List();
      setLine7List();
    
  }

  private List<StationDetailModel> getStationList()
  {
    List<String> sequence = xmlParser.getRouteList().get(routeId - 1).getStationSequece();
    return xmlParser.getUnskippedStationList(sequence);
  }
  
  
  private List<StationDetailModel> getLine2StationList()
  {
    List<String> sequence = xmlParser.getRouteList().get(3 - 1).getStationSequece();
    return xmlParser.getStationList(sequence);
  }
  
  private List<StationDetailModel> getLine7StationList()
  {
    List<String> sequence = xmlParser.getRouteList().get(1 - 1).getStationSequece();
    
    return xmlParser.getStationList(sequence);
  }

  private void setLine2List()
  {
    TCMSProto.StationList.Builder stationListBuilder = TCMSProto.StationList.newBuilder();
    this.line2StationList.clear();
    for (int i = 0; i < getLine2StationList().size(); i++)
    {
    
      this.line2StationList.add(getLine2StationList().get(i));
    }
    for (StationDetailModel station : this.line2StationList)
    {
      TCMSProto.StationList.StationDetail.Builder stationDetail = TCMSProto.StationList.StationDetail
          .newBuilder();
      stationDetail.setStationId(station.getStationId());
      stationDetail.setStationCode(station.getStationCode());
      stationDetail.setStationName(station.getStationName());
      stationListBuilder.addStationDetail(stationDetail);
    }
    setApplicationOutputsProperty(IAppOutputsRouteScreenProperties.LINE_2_STATION_LIST,
        stationListBuilder.build().toByteArray());
  }

  
  private void setLine7List()
  {
    TCMSProto.StationList.Builder stationListBuilder = TCMSProto.StationList.newBuilder();
    this.line7StationList.clear();
    for (int i = 0; i < getLine7StationList().size(); i++)
    {
      this.line7StationList.add(getLine7StationList().get(i));
    }
    for (StationDetailModel station : this.line7StationList)
    {
      TCMSProto.StationList.StationDetail.Builder stationDetail = TCMSProto.StationList.StationDetail
          .newBuilder();
      stationDetail.setStationId(station.getStationId());
      stationDetail.setStationCode(station.getStationCode());
      stationDetail.setStationName(station.getStationName());
      stationListBuilder.addStationDetail(stationDetail);
    }
    setApplicationOutputsProperty(IAppOutputsRouteScreenProperties.LINE_7_STATION_LIST,
        stationListBuilder.build().toByteArray());
  }
  
  
  private List<StationDetailModel> getSkipStationList()
  {
  
    List<String> skipSequence = xmlParser.getRouteList().get(routeId - 1).getStationSequece();
    
    System.out.println("SkipStationSettingScreenHandler.getSkipStationList()" + skipSequence);
    return xmlParser.getSkippedStationList(skipSequence);
  }

  


  private void setSkipList()
  {
//    TCMSProto.StationList.Builder skipStationListBuilder = TCMSProto.StationList.newBuilder();
//    this.skipStationList.clear();
//    for (int i = 0; i < skippedStationIdList.size(); i++)
//    {
//      this.skipStationList.add(skippedStationIdList.get(i));
//    }
//    for (StationDetailModel station : this.skipStationList)
//    {
//      TCMSProto.StationList.StationDetail.Builder skipstationDetail = TCMSProto.StationList.StationDetail
//          .newBuilder();
//      skipstationDetail.setStationId(station.getStationId());
//      skipstationDetail.setStationCode(station.getStationCode());
//      skipstationDetail.setStationName(station.getStationName());
//      skipStationListBuilder.addStationDetail(skipstationDetail);
//    }
//    setApplicationOutputsProperty(IAppOutputsRouteScreenProperties.SKIP_STATION_LIST,
//        skipStationListBuilder.build().toByteArray());
  }

  
}
