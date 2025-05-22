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
 * This class hold data for AK Status. <br>
 * Note: Data can be hold as {@link Integer}
 */
public class VehicleAkStatusDO
{

  /** The car index. */
  private int carIndex;

  private int akOpen1;

  private int akOpen2;

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

  public int getAkOpen1()
  {
    return akOpen1;
  }

  public void setAkOpen1(int akOpen1)
  {
    this.akOpen1 = akOpen1;
  }

  public int getAkOpen2()
  {
    return akOpen2;
  }

  public void setAkOpen2(int akOpen2)
  {
    this.akOpen2 = akOpen2;
  }
}