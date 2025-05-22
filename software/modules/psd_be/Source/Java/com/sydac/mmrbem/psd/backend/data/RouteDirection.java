/*
 * ==================================================================
 * 
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.psd.backend.data;

import com.sydac.mmrbem.psd.common.ScreenId;
/**
 * This Enum store the Route code with ScreenId
 * @author ext-jadhalp
 *
 */
public enum RouteDirection
{
 
//  ROUTE_1("L7-UP", ScreenId.PSD_L7_RIGHT_SCREEN), //$NON-NLS-1$
//  ROUTE_2("L7-DOWN", ScreenId.PSD_L7_LEFT_SCREEN), //$NON-NLS-1$
//  ROUTE_3("L2A-UP", ScreenId.PSD_L2_RIGHT_SCREEN), //$NON-NLS-1$
//  ROUTE_4("L2A-DOWN", ScreenId.PSD_L2_LEFT_SCREEN), //$NON-NLS-1$
//  ROUTE_5("L2B-UP", ScreenId.PSD_L2_RIGHT_SCREEN), //$NON-NLS-1$
//  ROUTE_6("L2A-DOWN", ScreenId.PSD_L2_LEFT_SCREEN); //$NON-NLS-1$
  
  
  ROUTE_1("L7-UP", ScreenId.PSD_L2_RIGHT_SCREEN), //$NON-NLS-1$
  ROUTE_2("L7-DOWN", ScreenId.PSD_L2_LEFT_SCREEN), //$NON-NLS-1$
  ROUTE_3("L2A-UP", ScreenId.PSD_L7_RIGHT_SCREEN), //$NON-NLS-1$
  ROUTE_4("L2A-DOWN", ScreenId.PSD_L7_LEFT_SCREEN), //$NON-NLS-1$
  ROUTE_5("L2B-UP", ScreenId.PSD_L7_RIGHT_SCREEN), //$NON-NLS-1$
  ROUTE_6("L2A-DOWN", ScreenId.PSD_L7_LEFT_SCREEN); //$NON-NLS-1$

  private final String routeCode;

  private final ScreenId screenId;

  private RouteDirection(String routeCode, ScreenId screenId)
  {
    this.routeCode = routeCode;
    this.screenId = screenId;
  }

  public String getRoute()
  {
    return routeCode;
  }

  public ScreenId getSceen()
  {
    return screenId;
  }

  public static RouteDirection valueByRouteCode(String routeCode)
  {
    for (RouteDirection routeDirection : RouteDirection.values())
    {
      if (routeDirection.getRoute().equalsIgnoreCase(routeCode))
      {
        return routeDirection;
      }
    }
    throw new IllegalArgumentException(routeCode);
  }
  
 
}
