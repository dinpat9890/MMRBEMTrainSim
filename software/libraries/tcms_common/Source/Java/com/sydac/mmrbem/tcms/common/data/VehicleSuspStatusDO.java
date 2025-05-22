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
 * This class hold data for SUSP status. <br>
 * Note: Data can be hold as {@link Integer}
 */
public class VehicleSuspStatusDO
{

  /** The car index. */
  private int carIndex;

  private int suspActivatedState1;

  private int suspActivatedState2;
  
  private int suspFaultState2;
  
  private int suspFaultState1;

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

  public int getSuspActivatedState1()
  {
    return suspActivatedState1;
  }

  public void setSuspActivatedState1(int suspActivatedState1)
  {
    this.suspActivatedState1 = suspActivatedState1;
  }

  public int getSuspActivatedState2()
  {
    return suspActivatedState2;
  }

  public void setSuspActivatedState2(int suspActivatedState2)
  {
    this.suspActivatedState2 = suspActivatedState2;
  }
  
  public int getSuspFaultState2()
  {
    return suspFaultState2;
  }

  public void setSuspFaultState2(int suspFaultState2)
  {
    this.suspFaultState2 = suspFaultState2;
  }
  
  public int getSuspFaultState1()
  {
    return suspFaultState1;
  }

  public void setSuspFaultState1(int suspFaultState1)
  {
    this.suspFaultState1 = suspFaultState1;
  }
}