/*
 * ==================================================================
 * 
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.radio.common.io;

/**
 * This Enum store the Line code with GroupName
 * @author ext-jadhalp
 *
 */
public enum GroupName
{
  
  ROUTE_1("L7", "Mainline AOC-1"), //$NON-NLS-1$
  ROUTE_3("L2A", "AOC-2"), //$NON-NLS-1$
  ROUTE_6("L2B-DOWN", "Mainline AOC-3"), //$NON-NLS-1$
  ROUTE_DEPOT("CHARKOP DEPOT", "CHARKOP DEPOT"); //$NON-NLS-1$

  private final String lineCode;

  private final String groupName;

  private GroupName(String routeCode, String name)
  {
    this.lineCode = routeCode;
    this.groupName = name;
  }

  public String getCode()
  {
    return lineCode;
  }

  public String getName()
  {
    return groupName;
  }

  public static GroupName valueByRouteCode(String linecode)
  {
    for (GroupName groupName : GroupName.values())
    {
      if (groupName.getCode().equalsIgnoreCase(linecode))
      {
        return groupName;
      }
    }
    throw new IllegalArgumentException(linecode);
  }
  
 
}
