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

public class TrainDirectionStatusDO
{
  private int forwardDirection;

  private int reverseDirection;

  public int getForwardDirection()
  {
    return forwardDirection;
  }

  public void setForwardDirection(int forwardDirection)
  {
    this.forwardDirection = forwardDirection;
  }

  public int getReverseDirection()
  {
    return reverseDirection;
  }

  public void setReverseDirection(int reverseDirection)
  {
    this.reverseDirection = reverseDirection;
  }
}
