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

public class SpeedLimitStatusDO
{
  private int speedLimitState;

  private int speedLimitId;

  public SpeedLimitStatusDO(int state, int id)
  {
    this.speedLimitState = state;
    this.speedLimitId = id;
  }

  public int getSpeedLimitState()
  {
    return speedLimitState;
  }

  public void setSpeedLimitState(int speedLimitState)
  {
    this.speedLimitState = speedLimitState;
  }

  public int getSpeedLimitId()
  {
    return speedLimitId;
  }

  public void setSpeedLimitId(int speedLimitId)
  {
    this.speedLimitId = speedLimitId;
  }

}
