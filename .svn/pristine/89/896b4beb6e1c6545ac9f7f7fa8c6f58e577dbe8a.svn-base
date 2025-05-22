/*
 * ==================================================================
 *
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *
 * ==================================================================
 */
package com.sydac.mmrbem.tcms.fe.gui.model;

import com.sydac.mmrbem.tcms.common.state.TCMSConstants;

import javafx.beans.property.IntegerProperty;
import javafx.beans.property.SimpleIntegerProperty;
import javafx.beans.property.SimpleStringProperty;
import javafx.beans.property.StringProperty;

/**
 * The Class VehicleDetailModel.
 */
public class CarConfigurationModel implements Comparable<CarConfigurationModel>
{
  private static final int INIT_HASH_CODE = CarConfigurationModel.class.getSimpleName().hashCode();

  /** The car name */
  private StringProperty carDisplayName = new SimpleStringProperty();

  /** The car index. */
  private IntegerProperty carIndex = new SimpleIntegerProperty();

  /** The car type. */
  private StringProperty carType = new SimpleStringProperty();

  /** The car class code. */
  private StringProperty carClassCode = new SimpleStringProperty();

  /** The car orientation. */
  private IntegerProperty carOrientation = new SimpleIntegerProperty();

  /**
   * Gets the car index.
   *
   * @return the car index
   */
  public IntegerProperty carIndexProperty()
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
    this.carIndex.set(carIndex);
  }

  /**
   * Gets the car type.
   *
   * @return the car type
   */
  public StringProperty carTypeProperty()
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
    this.carType.set(carType);
  }

  /**
   * Gets the car class code.
   *
   * @return the car class code
   */
  public StringProperty carClassCodeProperty()
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
    this.carClassCode.set(carClassCode);
  }

  /**
   * Gets the car orientation property.
   *
   * @return the car orientation property
   */
  public IntegerProperty carOrientationProperty()
  {
    return carOrientation;
  }

  /**
   * Gets the car orientation.
   *
   * @return the car orientation
   */
  public String getCarOrientation()
  {
    if (carOrientation.get() == 180)
    {
      return TCMSConstants.CAR_ORIENTATION_2_1;
    }
    return TCMSConstants.CAR_ORIENTATION_1_2;
  }

  /**
   * Sets the car orientation.
   *
   * @param carOrientation
   *          the new car orientation
   */
  public void setCarOrientation(String carOrientation)
  {
    if (!TCMSConstants.CAR_ORIENTATION_1_2.equals(carOrientation))
    {
      this.carOrientation.set(180);
    }
    else
    {
      this.carOrientation.set(0);
    }
  }

  /**
   * Gets the vehicle number.
   *
   * @return the vehicle number
   */
  public StringProperty carDisplayNameProperty()
  {
    return carDisplayName;
  }

  /**
   * Sets the vehicle number.
   *
   * @param aVehicleNumber
   *          the new vehicle number
   */
  public void setCarDisplayName(String aVehicleNumber)
  {
    carDisplayName.set(aVehicleNumber);
  }

  @Override
  public int compareTo(CarConfigurationModel o)
  {
    return Integer.compare(this.carIndex.get(), o.carIndex.get());
  }

  @Override
  public boolean equals(Object obj)
  {
    return this == obj;
  }

  @Override
  public int hashCode()
  {
    return INIT_HASH_CODE + this.carIndex.get();
  }
}
