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

import com.sydac.common.dataobjects.DBVirtualLocation;
import com.sydac.common.registry.Registry;
import com.sydac.mmrbem.scc.plugin.sessionsetup.MmrbemSessionSetupPlugin;

/**
 * Class defining the filtering that can be applied to hub locations.
 */
public class HubLocationFilter
{
  /**
   * Enum with supported filters.
   */
  enum HubLocation
  {
    ShowAll, EndCars, LeadCars;
  }

  /**
   * Application-level flag for enabling filtering of virtual locations, default
   * is to show all (no filtering). It would be nicer if the registry would have
   * support for enums, so conversions to / from strings are not required. The
   * registry could also make sure the configuration parameter matches the enum
   * vales. See
   * <a href="https://adl-atlassian.corp.knorr-bremse.com/jira/browse/CORE-140">
   * CORE-140</a> for details.
   */
  private static final HubLocation VIRTUAL_LOCATION_FILTER = HubLocation
      .valueOf(Registry.getInstance().getString(MmrbemSessionSetupPlugin.PLUGIN_DOMAIN,
          MmrbemSessionSetupPlugin.VIRTUAL_LOCATION_FILTER, HubLocation.ShowAll.name()));

  public HubLocationFilter()
  {
    // empty
  }

  public boolean allowSelection(DBVirtualLocation loc)
  {
    int vehicleIndex = loc.getVehicleIndex();
    int lastVehicleIndex = loc.getScenarioTrain().getTrain().getElements().size() - 1;
    return isShowAll() || isEndCars(vehicleIndex, lastVehicleIndex) || isLeadCars(vehicleIndex);
  }
  
  /**
   * Checks if is show all.
   *
   * @return true, if is show all
   */
  private boolean isShowAll()
  {
    boolean isShowAll = false;
    if(VIRTUAL_LOCATION_FILTER == HubLocation.ShowAll)
    {
      isShowAll = true;
    }
    return isShowAll;
  }
  
  /**
   * Checks if is end cars.
   *
   * @param vehicleIndex the vehicle index
   * @param lastVehicleIndex the last vehicle index
   * @return true, if is end cars
   */
  private boolean isEndCars(int vehicleIndex, int lastVehicleIndex)
  {
    boolean isEndCars = false;
    if (VIRTUAL_LOCATION_FILTER == HubLocation.EndCars
        && (vehicleIndex == 0 || vehicleIndex == lastVehicleIndex))
    {
      isEndCars = true;
    }
    return isEndCars;
  }
  
  /**
   * Checks if is lead cars.
   *
   * @param vehicleIndex the vehicle index
   * @return true, if is lead cars
   */
  private boolean isLeadCars(int vehicleIndex)
  {
    boolean isLeadCars = false;
    if (VIRTUAL_LOCATION_FILTER == HubLocation.LeadCars && vehicleIndex == 0)
    {
      isLeadCars = true;
    }
    return isLeadCars;
  }
}