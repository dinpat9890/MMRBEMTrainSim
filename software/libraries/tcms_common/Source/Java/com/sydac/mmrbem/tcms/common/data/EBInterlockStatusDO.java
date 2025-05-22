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

public class EBInterlockStatusDO
{
  private int carIndex;

  private int ebByCcState;

  private int ebByPushButtonState;

  private int ebByDeadmanState;

  private int ebByNonCabEnabledState;

  private int ebByNonDirectionSelectedState;

  private int ebByMcState;

  private int ebByBrakeLoopState;

  private int ebByAtcZeroSpeedState;

  private int masterControllerInFSBState;

  public int getEbByCcState()
  {
    return ebByCcState;
  }

  public void setEbByCcState(int ebByCcState)
  {
    this.ebByCcState = ebByCcState;
  }

  public int getEbByPushButtonState()
  {
    return ebByPushButtonState;
  }

  public void setEbByPushButtonState(int ebByPushButtonState)
  {
    this.ebByPushButtonState = ebByPushButtonState;
  }

  public int getEbByDeadmanState()
  {
    return ebByDeadmanState;
  }

  public void setEbByDeadmanState(int ebByDeadmanState)
  {
    this.ebByDeadmanState = ebByDeadmanState;
  }

  public int getEbByNonCabEnabledState()
  {
    return ebByNonCabEnabledState;
  }

  public void setEbByNonCabEnabledState(int ebByNonCabEnabledState)
  {
    this.ebByNonCabEnabledState = ebByNonCabEnabledState;
  }

  public int getEbByNonDirectionSelectedState()
  {
    return ebByNonDirectionSelectedState;
  }

  public void setEbByNonDirectionSelectedState(int ebByNonDirectionSelectedState)
  {
    this.ebByNonDirectionSelectedState = ebByNonDirectionSelectedState;
  }

  public int getEbByMcState()
  {
    return ebByMcState;
  }

  public void setEbByMcState(int ebByMcState)
  {
    this.ebByMcState = ebByMcState;
  }

  public int getEbByBrakeLoopState()
  {
    return ebByBrakeLoopState;
  }

  public void setEbByBrakeLoopState(int ebByBrakeLoopState)
  {
    this.ebByBrakeLoopState = ebByBrakeLoopState;
  }

  public int getEbByAtcZeroSpeedState()
  {
    return ebByAtcZeroSpeedState;
  }

  public void setEbByAtcZeroSpeedState(int ebByAtcZeroSpeedState)
  {
    this.ebByAtcZeroSpeedState = ebByAtcZeroSpeedState;
  }

  public int getCarIndex()
  {
    return carIndex;
  }

  public void setCarIndex(int carIndex)
  {
    this.carIndex = carIndex;
  }

  public int getMasterControllerInFSBState()
  {
    return masterControllerInFSBState;
  }

  public void setMasterControllerInFSBState(int masterControllerInFSBState)
  {
    this.masterControllerInFSBState = masterControllerInFSBState;
  }

}
