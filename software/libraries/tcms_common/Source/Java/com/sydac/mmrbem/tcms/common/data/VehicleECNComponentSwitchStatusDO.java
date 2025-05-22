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

/**
 * This class hold data for ECN Component Switch Status. <br>
 * Note: Data can be hold as {@link Integer}
 */
public class VehicleECNComponentSwitchStatusDO
{

  private int componentSwitchAStatus;

  private int componentSwitchBStatus;
  
  private int componentSwitchCStatus;
  
  private int componentSwitchAFault;

  private int componentSwitchBFault;
  
  private int componentSwitchCFault;

  public int getComponentSwitchAStatus()
  {
    return componentSwitchAStatus;
  }

  public void setComponentSwitchAStatus(int componentSwitchAStatus)
  {
    this.componentSwitchAStatus = componentSwitchAStatus;
  }

  public int getComponentSwitchBStatus()
  {
    return componentSwitchBStatus;
  }

  public void setComponentSwitchBStatus(int componentSwitchBStatus)
  {
    this.componentSwitchBStatus = componentSwitchBStatus;
  }

  public int getComponentSwitchCStatus()
  {
    return componentSwitchCStatus;
  }

  public void setComponentSwitchCStatus(int componentSwitchCStatus)
  {
    this.componentSwitchCStatus = componentSwitchCStatus;
  }

  public int getComponentSwitchAFault()
  {
    return componentSwitchAFault;
  }

  public void setComponentSwitchAFault(int componentSwitchAFault)
  {
    this.componentSwitchAFault = componentSwitchAFault;
  }

  public int getComponentSwitchBFault()
  {
    return componentSwitchBFault;
  }

  public void setComponentSwitchBFault(int componentSwitchBFault)
  {
    this.componentSwitchBFault = componentSwitchBFault;
  }

  public int getComponentSwitchCFault()
  {
    return componentSwitchCFault;
  }

  public void setComponentSwitchCFault(int componentSwitchCFault)
  {
    this.componentSwitchCFault = componentSwitchCFault;
  }
}