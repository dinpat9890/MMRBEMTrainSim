/*
 * ==================================================================
 *
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *
 * ==================================================================
 */

package com.sydac.mmrbem.marshalling;

import java.util.Arrays;
import java.util.HashMap;
import java.util.List;

/**
 * Mumbai_TrainSim enumerates the different possible rake configurations for
 * for Mumbai L2 L7.
 *
 * @author joshian
 */
public enum Mumbai_TrainSim
{
   SIX_CAR(getConsists(6),6), EIGHT_CAR(getConsists(8),8);

  private static final java.util.Map<Integer, Mumbai_TrainSim> mappedByValue = new HashMap<>();

  static
  {
    // Avoid duplicate values (which is a risk, since they are assigned
    // manually)
    for (Mumbai_TrainSim rake : values())
    {
      if (mappedByValue.put(rake.coaches.size(), rake) != null)
      {

        throw new IllegalArgumentException("Value " + rake.coaches.size() + " has already been assigned!"); //$NON-NLS-1$ //$NON-NLS-2$
      }
    }
  }

  // list of coaches in this rake
  private final List<Mumbai_TrainSim.Coaches> coaches;

  /*
   * Creates an MetroRake
   */
  Mumbai_TrainSim(List<Mumbai_TrainSim.Coaches> coaches, int totalCouches)
  {
    this.coaches = coaches;
  }

  /**
   * Returns the list of {@link Coaches} in this rake.
   *
   * @return Number of coaches in this rake
   */
  public List<Mumbai_TrainSim.Coaches> getCoaches()
  {
    return coaches;
  }

  /**
   * Returns the count of {@link Coaches} in this rake.
   *
   * @return The length of this rake.
   */
  public int getCoachesCount()
  {
    return coaches.size();
  }

  /**
   * Finds the type of coach at this <code>vehicleIndex</code> and returns it.
   * If suppled <code>vehicleIndex</code> is out of bounds returns
   * <code>null</code>
   * <p>
   * <p>
   * <b>Note:</b> vehicleIndex starts from 0
   *
   * @param vehicleIndex
   *          The index of the vehicle in train
   * @return The type of coach at this vehicle index. Returns <code>null</code>
   *         if the vehicle index is out of bounds.
   */
  //DM1,T2,M3,M4,T5,DM6
  public Coaches getSixCarCoachType(int vehicleIndex)
  {
    // As we have fixed set of configuration we are comparing with hard coded
    // values
    // check for DM
    if (vehicleIndex == 0 || vehicleIndex == 5)
    {
      return Mumbai_TrainSim.Coaches.DM;
    } // check for T
    else if (vehicleIndex == 1 || vehicleIndex == 4)
    {
      return Mumbai_TrainSim.Coaches.T;
    } // check for M
    else if (vehicleIndex == 2 || vehicleIndex == 3)
    {
      return Mumbai_TrainSim.Coaches.M;
    }
    else
    {
      return null;
    }

  }
  
  
  //DM1,T2,M3,T4,M5,M6,T7,DM8
  public Coaches getEightCarCoachType(int vehicleIndex)
  {
    // As we have fixed set of configuration we are comparing with hard coded
    // values
    // check for DM
    if (vehicleIndex == 0 || vehicleIndex == 7)
    {
      return Mumbai_TrainSim.Coaches.DM;
    } // check for T
    else if (vehicleIndex == 1 || vehicleIndex == 3 ||vehicleIndex == 6)
    {
      return Mumbai_TrainSim.Coaches.T;
    } // check for M
    else if (vehicleIndex == 2 ||vehicleIndex == 4 ||vehicleIndex == 5)
    {
      return Mumbai_TrainSim.Coaches.M;
    }
    else
    {
      return null;
    }

  }


  

  /**
   * Finds the type of orientation at this <code>vehicleIndex</code> and returns
   * it. If suppled <code>vehicleIndex</code> is out of bounds returns
   * <code>null</code>
   * <p>
   * <p>
   * <b>Note:</b> vehicleIndex starts from 0
   *
   * @param vehicleIndex
   *          The index of the vehicle in train
   * @return The type of orientation at this vehicle index. Returns
   *         <code>null</code> if the vehicle index is out of bounds.
   */

  public Orientation getOrientationType(int vehicleIndex)
  {
    // For First 6 cars
    if (getCoachesCount() == SIX_CAR.getCoachesCount())
    {
      if (vehicleIndex > 2)
      {
        return Orientation.TWO_ONE;
      }
      else
      {
        return Orientation.ONE_TWO;
      }
    }

    // For 8 cars
    if (getCoachesCount() == EIGHT_CAR.getCoachesCount())
    {
      if (vehicleIndex > 4)
      {
        return Orientation.TWO_ONE;
      }
      else
      {
        return Orientation.ONE_TWO;
      }
    }

    return Orientation.ONE_TWO;
  }

  

  private static List<Mumbai_TrainSim.Coaches> getConsists(int i)
  {
    switch (i)
    {
    
    case 6:
      return Arrays.asList(Mumbai_TrainSim.Coaches.DM, Mumbai_TrainSim.Coaches.T,
          Mumbai_TrainSim.Coaches.M, Mumbai_TrainSim.Coaches.M,Mumbai_TrainSim.Coaches.T,Mumbai_TrainSim.Coaches.DM);
    case 8:
      return Arrays.asList(Mumbai_TrainSim.Coaches.DM, Mumbai_TrainSim.Coaches.T, Mumbai_TrainSim.Coaches.M,
          Mumbai_TrainSim.Coaches.T,Mumbai_TrainSim.Coaches.M,
          Mumbai_TrainSim.Coaches.M,Mumbai_TrainSim.Coaches.T,Mumbai_TrainSim.Coaches.DM);
    default:
      return java.util.Collections.emptyList();
    }
  }

  /**
   * Returns the instance of {@link Mumbai_TrainSim} with a train length
   * supplied by <code>length</code>
   *
   * @param length
   *          The length of the train.
   * @return Instance of MetroRake.
   */

  public static Mumbai_TrainSim getTramRake(int length)
  {
    return mappedByValue.get(length);
  }

  public enum Coaches
  {
   DM,T,M;
    
    //DM1,T2,M3,T4,M5,M6,T7,DM8
    //DM1,T2,M3,M4,T5,DM6
  }

  public enum Orientation
  {
    ONE_TWO("1-2"), TWO_ONE("2-1");

    private final String code;

    Orientation(String code)
    {
      this.code = code;
    }

    public String getCode()
    {
      return code;
    }
  }

}