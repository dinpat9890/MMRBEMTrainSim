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

import com.sydac.mmrbem.tcms.common.proto.TCMSProto.VehicleDoorStatesList.DoorState;

/**
 * Holds state and vehicle index.
 */
public class VehicleDoorStatesDO implements Comparable<VehicleDoorStatesDO>
{
  private DoorState doorState;

  private int carIndex = 0;

  private static final int INIT_HASH_CODE = VehicleDoorStatesDO.class.getSimpleName().hashCode();

  /**
   * Gets the door state.
   *
   * @return the door state
   */
  public DoorState getDoorState()
  {
    return doorState;
  }

  /**
   * Sets the door state.
   *
   * @param doorState
   *          the new door state
   */
  public void setDoorState(DoorState doorState)
  {
    this.doorState = doorState;
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
  public int compareTo(VehicleDoorStatesDO o)
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
