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
 * This class hold data for all brake system status. <br>
 * Note: Data can be hold as {@link Integer}
 */
public class VehicleBrakeStatusDO
{

  /** The car index. */
  private int carIndex;

  private int brakeIsolationState1;

  private int brakeAppliedState1;

  private int brakeFaultState1;

  private int brakeIsolationState2;

  private int brakeAppliedState2;

  private int brakeFaultState2;

  /**
   * Gets the car index.
   *
   * @return the car index
   */
  public int getCarIndex()
  {
    return carIndex;
  }

  /**
   * Sets the car index.
   *
   * @param carIndex
   *          the new car index
   */
  public void setCarIndex(int carIndex)
  {
    this.carIndex = carIndex;
  }

  public int getBrakeIsolationState1()
  {
    return brakeIsolationState1;
  }

  public void setBrakeIsolationState1(int brakeIsolationState1)
  {
    this.brakeIsolationState1 = brakeIsolationState1;
  }

  public int getBrakeAppliedState1()
  {
    return brakeAppliedState1;
  }

  public void setBrakeAppliedState1(int brakeAppliedState1)
  {
    this.brakeAppliedState1 = brakeAppliedState1;
  }

  public int getBrakeFaultState1()
  {
    return brakeFaultState1;
  }

  public void setBrakeFaultState1(int brakeFaultState1)
  {
    this.brakeFaultState1 = brakeFaultState1;
  }

  public int getBrakeIsolationState2()
  {
    return brakeIsolationState2;
  }

  public void setBrakeIsolationState2(int brakeIsolationState2)
  {
    this.brakeIsolationState2 = brakeIsolationState2;
  }

  public int getBrakeAppliedState2()
  {
    return brakeAppliedState2;
  }

  public void setBrakeAppliedState2(int brakeAppliedState2)
  {
    this.brakeAppliedState2 = brakeAppliedState2;
  }

  public int getBrakeFaultState2()
  {
    return brakeFaultState2;
  }

  public void setBrakeFaultState2(int brakeFaultState2)
  {
    this.brakeFaultState2 = brakeFaultState2;
  }
}