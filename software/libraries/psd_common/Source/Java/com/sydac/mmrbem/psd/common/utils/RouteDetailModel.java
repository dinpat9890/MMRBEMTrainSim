/*
 * ================================================================== (C)
 * Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.psd.common.utils;

public class RouteDetailModel
{
  private int routeId;

  private String routeCode;

  public RouteDetailModel(RouteDetailModel model)
  {
    this.routeId = model.routeId;
    this.routeCode = model.routeCode;
  }

  public RouteDetailModel()
  {
    // do nothing
  }

 
  public void setRouteId(int routeId)
  {
    this.routeId = routeId;
  }

  
  public void setRouteCode(String routeCode)
  {
    this.routeCode = routeCode;
  }

 
  public int getRouteId()
  {
    return routeId;
  }

  
  public String getRouteCode()
  {
    return routeCode;
  }
}
