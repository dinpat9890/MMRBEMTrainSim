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
import com.sydac.mmrbem.papis.backend.vehicle.io.properties.IPISBEInputsRouteSettingScreenProperties;
import com.sydac.mmrbem.papis.common.ScreenId;
import com.sydac.mmrbem.papis.common.data.LineDetailModel;
import com.sydac.mmrbem.papis.common.data.RouteDetailModel;
import com.sydac.mmrbem.papis.common.io.properties.IAppInputsProperties;
import com.sydac.mmrbem.papis.common.io.properties.IAppInputsRouteScreenProperties;
import com.sydac.mmrbem.papis.common.io.properties.IAppInputsScreenChangeProperties;
import com.sydac.mmrbem.papis.common.io.properties.IAppOutputsRouteSettingScreenProperties;
import com.sydac.mmrbem.papis.common.io.properties.XMLParser;
import com.sydac.mmrbem.papis.common.protos.PAPISProtos;
import com.sydac.mmrbem.papis.common.state.ApplicationConstants;
import com.sydac.mmrbem.papis.common.state.RouteDirectionEnum;

import javafx.beans.property.ListProperty;
import javafx.beans.property.SimpleListProperty;
import javafx.collections.FXCollections;

/**
 * This handler class is used for Route screen handling.
 * 
 */
@Service
@FunctionalLogicHandler(arguments = { CommsBinding.class, SharedDataModel.class })
public class RouteSettingScreenHandler extends AbstractFunctionalLogic
{
  CommsBinding commsBinding;

  private XMLParser xmlParser;

  SharedDataModel sharedDataModel;

  private int startIndex = 0;

  private int endIndex = 0;

  private int lineListPerPage = 4;

  private int direction = RouteDirectionEnum.UP.getDirectionId();

  private ListProperty<LineDetailModel> lineList = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private ListProperty<RouteDetailModel> routeList = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  protected RouteSettingScreenHandler(CommsBinding commsBinding, SharedDataModel sharedDataModel)
  {
    super(commsBinding, IAppInputsProperties.class, IPISBEInputsProperties.class);
    this.commsBinding = commsBinding;
    this.sharedDataModel = sharedDataModel;
    xmlParser = new XMLParser();

  }

  @Override
  public <T> void appInputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue, int vehicleIndex)
  {
    if (IAppInputsRouteScreenProperties.SELECTED_ROUTE_ID_REQUEST.equals(key))
    {
      processRouteId((Integer)newValue);
    }
    else if (IAppInputsRouteScreenProperties.ROUTE_DIRECTION_REQUEST.equals(key) && (Integer)newValue > -1)
    {
      direction = (Integer)newValue;
    }
    else if (IAppInputsScreenChangeProperties.SCREEN_CHANGE_REQUEST.equals(key)
        && (Integer)newValue == ScreenId.ROUTE_SETTINGS_SCREEN.getId())
    {
      updateLineList();
    }
    else if (IAppInputsRouteScreenProperties.ROUTE_SCREEN_UP_PRESSED.equals(key)
        && (Integer)newValue == ApplicationConstants.UP_PRESSED)
    {
      prevPage();
    }
    else if (IAppInputsRouteScreenProperties.ROUTE_SCREEN_DOWN_PRESSED.equals(key)
        && (Integer)newValue == ApplicationConstants.DOWN_PRESSED)
    {
      nextPage();
    }
  }

  private void processRouteId(Integer lineId)
  {
    IPropertySetter propertySetter = getPISBEInputsSetter(getActiveVehicleIndex());
    if (lineId > 0 && propertySetter != null)
    {
      String lineCode = getLineList().get(lineId - 1).getLineCode()
          + (direction == RouteDirectionEnum.UP.getDirectionId() ? RouteDirectionEnum.UP.getDirection()
              : RouteDirectionEnum.DOWN.getDirection());
      routeList.addAll(getRoutList());
      for (RouteDetailModel route : routeList)
      {
        if (route.getRouteCode().equals(lineCode))
        {
          setInputData(propertySetter, IPISBEInputsRouteSettingScreenProperties.ROUTE_SELECTION_ID,
              route.getRouteId());
          sharedDataModel.setRouteId(route.getRouteId());
        }
      }
    }
  }

  private List<LineDetailModel> getLineList()
  {
    return xmlParser.getLineList();
  }

  private List<RouteDetailModel> getRoutList()
  {
    return xmlParser.getRouteList();
  }

  private void updateLineList()
  {
    startIndex = 0;
    endIndex = 0;
    if (getLineList().size() < lineListPerPage)
    {
      endIndex = getLineList().size();
    }
    else
    {
      endIndex = endIndex + lineListPerPage;
      // set Down Button enabled
    }
    setList();
  }

  private void nextPage()
  {
    endIndex = endIndex + lineListPerPage;
    if (getLineList().size() < endIndex)
    {
      endIndex = getLineList().size();
      if (startIndex + lineListPerPage < endIndex)
      {
        startIndex = startIndex + lineListPerPage;
      }
      // Down Btn disabled
    }
    else
    {
      startIndex = startIndex + lineListPerPage;
    }
    // Up Button enabled
    setList();
  }

  private void prevPage()
  {
    if (startIndex > 0)
    {
      endIndex = startIndex;
      startIndex = startIndex - lineListPerPage;
    }
    else
    {
      // Up Btn disabled
    }
    setList();
  }

  private void setList()
  {
    PAPISProtos.LineList.Builder lineListBuilder = PAPISProtos.LineList.newBuilder();
    this.lineList.clear();
    for (int i = startIndex; i < endIndex; i++)
    {
      this.lineList.add(getLineList().get(i));
    }
    for (LineDetailModel lines : this.lineList)
    {
      PAPISProtos.LineList.LineDetail.Builder lineDetail = PAPISProtos.LineList.LineDetail.newBuilder();
      lineDetail.setLineId(lines.getLineId());

      lineDetail.setLineName(xmlParser.getDisplayLineName(lines.getLineName()));
      lineDetail.setLineCode(lines.getLineCode());
      lineListBuilder.addLineDetail(lineDetail);
    }
    setApplicationOutputsProperty(IAppOutputsRouteSettingScreenProperties.LINE_LIST,
        lineListBuilder.build().toByteArray());
  }

  /**
   * Add the line Name and equivalnet display name. Cretaed this map because
   * ,there is difference in line name in Video provided by customer and PIS XML
   */

}
