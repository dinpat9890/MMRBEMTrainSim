/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.common.state;

public enum RouteDirectionEnum
{
  UP(0, "-UP"), //$NON-NLS-1$
  DOWN(1, "-DOWN"); //$NON-NLS-1$

  private int directionId;

  private String direction;

  RouteDirectionEnum(int directionId, String direction)
  {
    this.directionId = directionId;
    this.direction = direction;
  }

  public int getDirectionId()
  {
    return directionId;
  }

  public void setDirectionId(int directionId)
  {
    this.directionId = directionId;
  }

  public String getDirection()
  {
    return direction;
  }

  public void setDirection(String direction)
  {
    this.direction = direction;
  }

  public static RouteDirectionEnum valueOf(int intValue)
  {
    for (RouteDirectionEnum direction : values())
    {
      if (direction.getDirectionId() == intValue)
      {
        return direction;
      }
    }
    return null;
  }
}
