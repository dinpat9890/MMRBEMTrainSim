/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.common.state;

public enum DoorOpeningSideEnum
{
  LEFT(0, "left"), //$NON-NLS-1$
  RIGHT(1, "right"); //$NON-NLS-1$

  private int doorOpenSideId;

  private String doorOpenSide;

  DoorOpeningSideEnum(int doorOpenSideId, String doorOpenSide)
  {
    this.doorOpenSideId = doorOpenSideId;
    this.doorOpenSide = doorOpenSide;
  }

  public int getDoorOpenSideId()
  {
    return doorOpenSideId;
  }

  public void setDoorOpenSideId(int doorOpenSideId)
  {
    this.doorOpenSideId = doorOpenSideId;
  }

  public String getDoorOpenSide()
  {
    return doorOpenSide;
  }

  public void setDoorOpenSide(String doorOpenSide)
  {
    this.doorOpenSide = doorOpenSide;
  }

  public static DoorOpeningSideEnum valueOf(int intValue)
  {
    for (DoorOpeningSideEnum doorOpenSide : values())
    {
      if (doorOpenSide.getDoorOpenSideId() == intValue)
      {
        return doorOpenSide;
      }
    }
    return null;
  }
}
