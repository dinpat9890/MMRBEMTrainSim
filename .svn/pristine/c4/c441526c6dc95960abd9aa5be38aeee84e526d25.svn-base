/*
 * ==================================================================
 * 
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.tcms.fe.gui.binder;

import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsRouteScreenProperties;
import com.sydac.mmrbem.tcms.fe.base.AbstractCommsListener;
import com.sydac.mmrbem.tcms.fe.gui.model.RouteScreenModel;

public class RouteScreenBinder extends AbstractCommsListener
{

  private RouteScreenModel routeScreenModel;

  public RouteScreenBinder(RouteScreenModel routeScreenModel)
  {
    super();
    this.routeScreenModel = routeScreenModel;
    propertyKeyDefinitions.add(IAppOutputsRouteScreenProperties.class);
  }

  @Override
  protected <T> void appOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue)
  {
    if (IAppOutputsRouteScreenProperties.TCMS_PAPIS_SELECTED_MODE.equals(key))
    {
      routeScreenModel.setPapisSelectedMode((Integer)newValue);
    }
    else if (IAppOutputsRouteScreenProperties.ROUTE_SCREEN_TRAIN_ID.equals(key))
    {
      routeScreenModel.setTrainId((byte[])newValue);
    }
    else if (IAppOutputsRouteScreenProperties.ROUTE_SCREEN_START_ST_ID.equals(key))
    {
      routeScreenModel.setStartStation((byte[])newValue);
    }
    else if (IAppOutputsRouteScreenProperties.ROUTE_SCREEN_DEST_ST_ID.equals(key))
    {
      routeScreenModel.setDestinationStation((byte[])newValue);
    }
    else if (IAppOutputsRouteScreenProperties.SEMI_AUTO_TRAIN_ID.equals(key))
    {
      routeScreenModel.setSemiAutoTrainId((byte[])newValue);
    }else if (IAppOutputsRouteScreenProperties.STATION_LIST.equals(key))
    {
      routeScreenModel.setStationList((byte[])newValue);
    }else if (IAppOutputsRouteScreenProperties.SELECTED_STATION_NAME.equals(key))
    {
      routeScreenModel.setSelectedStationName((byte[])newValue);
    }else if (IAppOutputsRouteScreenProperties.TRAIN_UNDER_EVAC_SET_BUTTON_STATE.equals(key))
    {
      routeScreenModel.setTrainEvac((Integer)newValue);
    }else if (IAppOutputsRouteScreenProperties.TRAIN_OUT_OF_SERVICE_SET_BUTTON_STATE.equals(key))
    {
      routeScreenModel.setTrainOutOfService((Integer)newValue);
    }
    else if (IAppOutputsRouteScreenProperties.TRAIN_HOLD_BUTTON_STATE.equals(key))
    {
      routeScreenModel.setTrainHoldState((Integer)newValue);
    }
    else if (IAppOutputsRouteScreenProperties.DELAY_IN_SERVICE_BUTTON_STATE.equals(key))
    {
      routeScreenModel.setTrainDelayState((Integer)newValue);
    }
    else if (IAppOutputsRouteScreenProperties.START_SERVICE_BUTTON_STATE.equals(key))
    {
      routeScreenModel.setServiceState((Integer)newValue);
    }else if (IAppOutputsRouteScreenProperties.LINE_2_STATION_LIST.equals(key))
    {
      routeScreenModel.setLine2StationList((byte[])newValue);
    }else if (IAppOutputsRouteScreenProperties.LINE_7_STATION_LIST.equals(key))
    {
      routeScreenModel.setLine7StationList((byte[])newValue);
    }
    
  }
}
