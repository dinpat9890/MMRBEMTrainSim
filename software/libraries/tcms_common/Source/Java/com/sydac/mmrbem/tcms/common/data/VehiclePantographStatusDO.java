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

public class VehiclePantographStatusDO
{
  private int carIndex;

  private int pantographPosition;

  private int pantographFault;
  
  private int pantographIsolated;

  public int getCarIndex() {
      return carIndex;
  }

  public void setCarIndex(int carIndex) {
      this.carIndex = carIndex;
  }

  public int getPantographPosition() {
      return pantographPosition;
  }

  public void setPantographPosition(int pantographPosition) {
      this.pantographPosition = pantographPosition;
  }

  public int getPantographFault() {
      return pantographFault;
  }

  public void setPantographFault(int pantographFault) {
      this.pantographFault = pantographFault;
  }
  
  public int getPantographIsolated() {
    return pantographIsolated;
  }
  
  public void setPantographIsolated(int pantographIsolated) {
    this.pantographIsolated = pantographIsolated;
  }
}
