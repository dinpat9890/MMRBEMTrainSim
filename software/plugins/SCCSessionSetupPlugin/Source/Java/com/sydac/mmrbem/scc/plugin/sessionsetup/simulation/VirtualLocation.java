/*
 * ==================================================================
 * 
 * (C) Copyright 2018 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.scc.plugin.sessionsetup.simulation;

import static com.sydac.simulatorcontroller.i18n.SimulatorControllerI18N.t;

import java.text.MessageFormat;

import com.sydac.common.dataobjects.DBScenarioTrain;
import com.sydac.common.dataobjects.DBVirtualLocation;
import com.sydac.content.i18n.TrainsI18N;
import com.sydac.gui.language.NaturalStringComparator;

/**
 * The Class VirtualLocation.
 */
public class VirtualLocation implements Comparable<VirtualLocation>
{
  private DBVirtualLocation location;

  public VirtualLocation(DBVirtualLocation aLocation)
  {
    location = aLocation;
  } // VirtualLocation
  
  /**
   * Gets the location.
   *
   * @return the location
   */
  public DBVirtualLocation getLocation()
  {
    return location;
  }

  @Override
  public int compareTo(VirtualLocation that)
  {
    DBScenarioTrain train1 = this.location.getScenarioTrain();
    DBScenarioTrain train2 = that.location.getScenarioTrain();

    final NaturalStringComparator comparator = new NaturalStringComparator();

    int trainNameComparisonResult = comparator.compare(train1.getScenarioTrainName(),
        train2.getScenarioTrainName());

    if (trainNameComparisonResult != 0)
    {
      return trainNameComparisonResult;
    } // if

    Integer car1 = this.location.getVehicleIndex();
    Integer car2 = that.location.getVehicleIndex();

    if (car1 == null && car2 == null)
    {
      return 0;
    } // if
    else if (car1 == null)
    {
      return -1;
    } // if
    else if (car2 == null)
    {
      return 1;
    } // if

    int carComparisonResult = car1.compareTo(car2);

    if (carComparisonResult != 0)
    {
      return carComparisonResult;
    } // if

    return comparator.compare(TrainsI18N.getText(this.location.getLocationType().getLocationTypeName()),
        TrainsI18N.getText(that.location.getLocationType().getLocationTypeName()));
  } // compareTo

  @Override
  public int hashCode()
  {
    // not sensible, but DataObjects are not sensible...
    return 0;
  } // hashCode

  @Override
  public boolean equals(Object obj)
  {
    if (this == obj)
      return true;
    if (obj == null)
      return false;
    if (getClass() != obj.getClass())
      return false;
    VirtualLocation other = (VirtualLocation)obj;
    if (location == null)
    {
      if (other.location != null)
        return false;
    }
    else if (!location.keyEquals(other.location))
      return false;
    return true;
  } // equals

  @Override
  public String toString()
  {
    return MessageFormat.format(t("{0} car {1}: {2}"), //$NON-NLS-1$
        location.getScenarioTrain().getScenarioTrainName(), location.getVehicleIndex() + 1,
        TrainsI18N.getText(location.getVirtualLocationDescription()));
  } // toString
}