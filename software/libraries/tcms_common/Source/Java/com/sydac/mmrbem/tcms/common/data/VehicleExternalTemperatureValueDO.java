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
 * This class hold data for External Temperature Value. <br>
 * Note: Data can be hold as {@link Integer}
 */

public class VehicleExternalTemperatureValueDO
{

  /** The car index. */
  private int carIndex;

  private float externalTemperature;

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

  public float getExternalTemperature()
  {
    return externalTemperature;
  }

  public void setExternalTemperature(float externalTemperature)
  {
    this.externalTemperature = externalTemperature;
  }
}
