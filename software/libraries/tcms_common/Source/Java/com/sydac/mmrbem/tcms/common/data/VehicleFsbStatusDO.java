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
 * This class hold data for FSB Status. <br>
 * Note: Data can be hold as {@link Integer}
 */
public class VehicleFsbStatusDO
{

  /** The car index. */
  private int carIndex;

  private int fsb1Energized;

  private int fsb2Energized;

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

  public int getFsb1Energized()
  {
    return fsb1Energized;
  }

  public void setFsb1Energized(int fsb1Energized)
  {
    this.fsb1Energized = fsb1Energized;
  }

  public int getFsb2Energized()
  {
    return fsb2Energized;
  }

  public void setFsb2Energized(int fsb2Energized)
  {
    this.fsb2Energized = fsb2Energized;
  }
}