/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.papis.common.state;

public enum DoorStatusEnum
{
  LEFT(1, "Left"), //$NON-NLS-1$
  RIGHT(2, "Right"); //$NON-NLS-1$

  private int doorOpenSideId;

  private String doorOpenSide;

  DoorStatusEnum(int doorOpenSideId, String doorOpenSide)
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

  public static DoorStatusEnum valueOf(int intValue)
  {
    for (DoorStatusEnum doorOpenSide : values())
    {
      if (doorOpenSide.getDoorOpenSideId() == intValue)
      {
        return doorOpenSide;
      }
    }
    return null;
  }
}
