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

public class VehicleVcbStatusDO
{
  private int carIndex;

  private int vcbState;

  private int vcbFault;
  
  private int vcbIsolated;

  public int getCarIndex() {
      return carIndex;
  }

  public void setCarIndex(int carIndex) {
      this.carIndex = carIndex;
  }

  public int getVcbState() {
      return vcbState;
  }

  public void setVcbState(int vcbState) {
      this.vcbState = vcbState;
  }

  public int getVcbFault() {
      return vcbFault;
  }

  public void setVcbFault(int vcbFault) {
      this.vcbFault = vcbFault;
  }
  
  public int getVcbIsolated() {
    return vcbIsolated;
  }
  
  public void setVcbIsolated(int vcbIsolated) {
    this.vcbIsolated = vcbIsolated;
  }
}
