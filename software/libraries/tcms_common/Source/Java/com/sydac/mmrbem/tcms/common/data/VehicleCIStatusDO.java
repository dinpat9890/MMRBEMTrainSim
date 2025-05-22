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

public class VehicleCIStatusDO
{
  private int carIndex;

  private int ciState;

  private int ciFault;
  
  private int ciIsolated;

  public int getCarIndex() {
      return carIndex;
  }

  public void setCarIndex(int carIndex) {
      this.carIndex = carIndex;
  }

  public int getCiState() {
      return ciState;
  }

  public void setCiState(int vcbState) {
      this.ciState = vcbState;
  }

  public int getCiFault() {
      return ciFault;
  }

  public void setCiFault(int ciFault) {
      this.ciFault = ciFault;
  }
  
  public int getCiIsolated() {
    return ciIsolated;
  }
  
  public void setCiIsolated(int ciIsolated) {
    this.ciIsolated = ciIsolated;
  }
}
