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

public class VehiclePropulsionStatusDO
{
  private int propulsionActive;

  private int propulsionFault;

  private int propulsionIsolated;

  public int getPropulsionActive()
  {
    return propulsionActive;
  }

  public void setPropulsionActive(int propulsionActive)
  {
    this.propulsionActive = propulsionActive;
  }

  public int getPropulsionFault()
  {
    return propulsionFault;
  }

  public void setPropulsionFault(int propulsionFault)
  {
    this.propulsionFault = propulsionFault;
  }

  public int getPropulsionIsolated()
  {
    return propulsionIsolated;
  }

  public void setPropulsionIsolated(int propulsionIsolated)
  {
    this.propulsionIsolated = propulsionIsolated;
  }
}
