/*
 * ==================================================================
 * 
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.tcms.fe.gui.data;

/**
 * Holds car component state's CSS name and vehicle index.
 */
public class CarComponentStatesDO implements Comparable<CarComponentStatesDO>
{
  private String componentState;

  private int carIndex = 0;

  private static final int INIT_HASH_CODE = CarComponentStatesDO.class.getSimpleName().hashCode();

  /**
   * Gets the component state's CSS name.
   *
   * @return the component state's CSS name.
   */
  public String getComponentState()
  {
    return componentState;
  }

  /**
   * Sets the component state's CSS name.
   *
   * @param componentState
   *          the new component state's CSS name
   */
  public void setComponentState(String componentState)
  {
    this.componentState = componentState;
  }

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

  @Override
  public int compareTo(CarComponentStatesDO o)
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
