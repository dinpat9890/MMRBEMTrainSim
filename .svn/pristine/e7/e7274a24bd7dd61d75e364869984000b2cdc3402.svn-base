/*
 * ==================================================================
 *
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *
 * ==================================================================
 */
package com.sydac.mmrbem.utils;

import com.sydac.common.dataobjects.DBPhysicalHub;
import com.sydac.common.dataobjects.DBPhysicalHubManager;
import com.sydac.common.dataobjects.DBSimulator;
import com.sydac.common.dataobjects.DBSimulatorManager;
import com.sydac.common.log.Tracer;
import com.sydac.common.registry.Registry;
import com.sydac.common.sessiondata.BaseScenarioData;
import com.sydac.common.sessiondata.HubData;

/**
 * Collects helper methods for interacting with Hub configuration data.
 *
 */
public final class HubUtils
{

  // Helper class, can't construct
  private HubUtils()
  {}

  /**
   * Returns the logical hub ID, the ID of the Hub that your application should
   * use for this session (as opposed to the ID of the Hub it is physically
   * located on).
   *
   * @param sessionData
   *          Describes physical-to-logical hub mappings for this session.
   * @param registry
   *          A registry populated with properties
   *
   * @return The logical hub ID, or -1 if none could be determined.
   */
  public static int findLogicalHubId(BaseScenarioData sessionData, Registry registry)
  {
    return findLogicalHubId(sessionData,
        // registry.getString(HUB_DOMAIN, SIM_NAME_PROPERTY),
        // registry.getString(HUB_DOMAIN, HUB_NAME_PROPERTY));
        "Fixed Set Driver's Cab", "Driver's Cab");
  }

  /**
   * Returns the logical hub ID, the ID of the Hub that your application should
   * use for this session (as opposed to the ID of the Hub it is physically
   * located on).
   * <p>
   * It is recommended to use
   * {@link #findLogicalHubId(BaseScenarioData, Registry)} and share a common
   * properties file for your hub definition.
   *
   * @param scenarioData
   *          Describes physical-to-logical hub mappings for this scenario.
   * @param simName
   *          The name of the simulator your application belongs to. This should
   *          match an entry in the SIMULATOR table's SIM_SIMULATOR_NAME column.
   * @param hubName
   *          The name of the hub your application belongs to. This should match
   *          an entry in the PHYSICALHUB table's PHHU_HUB_NAME column.
   *
   * @return The logical hub ID, or -1 if none could be determined.
   */
  public static int findLogicalHubId(BaseScenarioData scenarioData, String simName, String hubName)
  {
    DBSimulator mySim = null;
    DBPhysicalHub myHub = null;

    DBSimulatorManager sims = new DBSimulatorManager();
    sims.load();

    for (DBSimulator sim : sims)
    {
      if (sim.getSimulatorName().equals(simName))
      {
        mySim = sim;
        break;
      }
    }

    int logicalHubId = -1;

    if (mySim != null)
    {
      DBPhysicalHubManager hubs = new DBPhysicalHubManager(mySim);
      hubs.load();

      for (DBPhysicalHub hub : hubs)
      {
        if (hub.getPhysicalHubName().equals(hubName))
        {
          myHub = hub;
          break;
        }
      }

      if (myHub != null)
      {
        for (HubData hub : scenarioData.getAllHubData())
        {
          if (hub.getHubId() == myHub.getPhysicalHubId())
          {
            logicalHubId = hub.getLogicalHubId();
            break;
          }
        }

        Tracer.getInstance().debugFmt("Logical Hub ID for Hub \"%s\" (%d) on Sim: \"%s\" (%d) is %d", //$NON-NLS-1$
            hubName, myHub.getPhysicalHubId(), simName, mySim.getSimulatorId(), logicalHubId);
      }
      else
      {
        Tracer.getInstance().warningFmt("Could not find hub with name \"%s\" on simulator \"%s\"", hubName, //$NON-NLS-1$
            simName);
      }
    }
    else
    {
      Tracer.getInstance().warningFmt("Could not find simulator with name \"%s\"", simName); //$NON-NLS-1$
    }

    return logicalHubId;
  }

  /**
   * Returns the ID of the Scenario Train which is associated with the given
   * hub.
   *
   * @param scenarioData
   *          Describes hub configuration for this scenario.
   * @param logicalHubId
   *          ID of the Hub object that we are interested in (not necessarily
   *          the ID of our Physical Hub). See
   *          {@link #findLogicalHubId(BaseScenarioData, Registry)}
   *
   * @return The ID of the scenario train for the given hub, or -1 if none can
   *         be found.
   */
  public static int findScenarioTrainId(BaseScenarioData scenarioData, int logicalHubId)
  {
    HubData hubData = scenarioData.getHubData(logicalHubId);
    return hubData != null ? hubData.getScenarioTrainId() : -1;
  }

  /**
   * Returns the index of the vehicle which is associated with the given hub.
   *
   * @param scenarioData
   *          Describes hub configuration for this session.
   * @param logicalHubId
   *          ID of the Hub object that we are interested in (not necessarily
   *          the ID of our Physical Hub). See
   *          {@link #findLogicalHubId(BaseScenarioData, Registry)}
   *
   * @return The ID of the scenario train for the given hub, or -1 if none can
   *         be found.
   */
  public static int findVehicleIndex(BaseScenarioData scenarioData, int logicalHubId)
  {
    HubData hubData = scenarioData.getHubData(logicalHubId);
    return hubData != null ? hubData.getVehicleIndex() : -1;
  }

}
