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
 * The Class VehicleDetailModel.
 */
public class VehicleDetailModel implements Comparable<VehicleDetailModel>
{

  /** The car index. */
  private int carIndex;

  /** The car type. */
  private String carType;

  /** The car class code. */
  private String carClassCode;

  /** The car orientation. */
  private String carOrientation;

  /** Name to display on car */
  private String carDisplayName;

  public static final String ORIENTATION_1_2 = "1-2";

  public static final String ORIENTATION_2_1 = "2-1";

  private static final int INIT_HASH_CODE = VehicleDetailModel.class.getSimpleName().hashCode();

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

  /**
   * Gets the car type.
   * 
   * @return the car type
   */
  public String getCarType()
  {
    return carType;
  }

  /**
   * Sets the car type.
   * 
   * @param carType
   *          the new car type
   */
  public void setCarType(String carType)
  {
    this.carType = carType;
  }

  /**
   * Gets the car class code.
   * 
   * @return the car class code
   */
  public String getCarClassCode()
  {
    return carClassCode;
  }

  /**
   * Sets the car class code.
   * 
   * @param carClassCode
   *          the new car class code
   */
  public void setCarClassCode(String carClassCode)
  {
    this.carClassCode = carClassCode;
  }

  /**
   * Gets the car orientation.
   * 
   * @return the car orientation
   */
  public String getCarOrientation()
  {
    return carOrientation;
  }

  /**
   * Sets the car orientation.
   * 
   * @param carOrientation
   *          the new car orientation
   */
  public void setCarOrientation(String carOrientation)
  {
    this.carOrientation = carOrientation;
  }

  /**
   * Gets the car name to display on car.
   * 
   * @return the car name
   */
  public String getCarDisplayName()
  {
    return carDisplayName;
  }

  /**
   * Sets the car name to display on car.
   * 
   * @param carDisplayName
   *          the new car orientation
   */
  public void setCarDisplayName(String carDisplayName)
  {
    this.carDisplayName = carDisplayName;
  }

  @Override
  public int compareTo(VehicleDetailModel o)
  {
    return this.carIndex - o.carIndex;
  }

  @Override
  public int hashCode()
  {
    return INIT_HASH_CODE + carIndex;
  }

  @Override
  public boolean equals(Object obj)
  {
    return this == obj;
  }

}
