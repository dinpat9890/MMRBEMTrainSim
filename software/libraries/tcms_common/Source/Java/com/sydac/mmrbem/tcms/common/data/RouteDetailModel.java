/*
 * ==================================================================
 *
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *
 * ==================================================================
 */
package com.sydac.mmrbem.tcms.common.data;

import java.util.ArrayList;

/**
 * RouteDetailModel acts as a buffer to store the data read from the XML files,
 * later same is used to populate the FE.
 */
public class RouteDetailModel
{
  private int routeId;

  private String routeCode;

  private String routeLineCode;

  private ArrayList<String> stationSequece = new ArrayList<String>();

  public RouteDetailModel(RouteDetailModel model)
  {
    this.routeId = model.routeId;
    this.routeCode = model.routeCode;
    this.routeLineCode = model.routeLineCode;
    this.stationSequece = model.stationSequece;
  }

  public RouteDetailModel()
  {
    // do nothing
  }

  public int getRouteId()
  {
    return routeId;
  }

  public void setRouteId(int routeId)
  {
    this.routeId = routeId;
  }

  public String getRouteCode()
  {
    return routeCode;
  }

  public void setRouteCode(String routeCode)
  {
    this.routeCode = routeCode;
  }

  public String getRouteLineCode()
  {
    return routeLineCode;
  }

  public void setRouteLineCode(String routeLineCode)
  {
    this.routeLineCode = routeLineCode;
  }

  public ArrayList<String> getStationSequece()
  {
    return stationSequece;
  }

  public void setStationSequece(ArrayList<String> stationSequece)
  {
    this.stationSequece = stationSequece;
  }
}