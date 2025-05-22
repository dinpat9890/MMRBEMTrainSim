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
 * This class hold data for Internal Temperature Value. <br>
 * Note: Data can be hold as {@link Integer}
 */

public class VehicleInternalTemperatureValueDO
{

  /** The car index. */
  private int carIndex;

  private float internalTemperature;

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

  public float getInternalTemperature()
  {
    return internalTemperature;
  }

  public void setInternalTemperature(float internalTemperature)
  {
    this.internalTemperature = internalTemperature;
  }
}
