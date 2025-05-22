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
 * This class hold data for RI01 and RI02 status. <br>
 * Note: Data can be hold as {@link Integer}
 */
public class VehicleTcmsStatusScreenDO
{

  /** The car index. */
  private int carIndex;

  private int ri01Status;

  private int ri01Fault;

  private int ri02Status;

  private int ri02Fault;

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

  public int getRi01Status()
  {
    return ri01Status;
  }

  public void setRi01Status(int bcgStatus1)
  {
    this.ri01Status = bcgStatus1;
  }

  public int getRi02Status()
  {
    return ri02Status;
  }

  public void setRi02Status(int bcgFault1)
  {
    this.ri02Status = bcgFault1;
  }

  public int getRi02Fault()
  {
    return ri02Fault;
  }

  public void setRi02Fault(int ri02Fault)
  {
    this.ri02Fault = ri02Fault;
  }

  public int getRi01Fault()
  {
    return ri01Fault;
  }

  public void setRi01Fault(int ri01Fault)
  {
    this.ri01Fault = ri01Fault;
  }
  
}