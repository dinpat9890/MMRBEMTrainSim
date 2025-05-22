/* ==================================================================
 *
 *  (C) Copyright 2002 Sydac Pty Ltd., all rights reserved.
 *  This is unpublished proprietary source code of Sydac.
 *  The copyright notice above does not evidence any actual
 *  or intended publication of such source code.
 *
 * ==================================================================
 */
package com.sydac.mmrbem.scc.plugin.sessionsetup.replay;

import java.util.Collection;
import java.util.Collections;
import java.util.HashMap;
import java.util.Map;
import java.util.Set;

import com.sydac.common.dataobjects.DBPhysicalHub;
import com.sydac.common.dataobjects.DBSimSession;
import com.sydac.common.dataobjects.DBSimSessionHub;
import com.sydac.foundation.DataObject;
import com.sydac.foundation.Model;
import com.sydac.foundation.functional.Pair;

/**
 * This model contains the configuration for a replay session the user will
 * request.
 */
public final class ReplaySessionModel
  extends Model
{

  public enum Change
  {
    /** Identifies that the selected session has changed */
    SELECTED_SESSION_CHANGED,
    /** Identifies that the hub mapping has changed */
    HUB_MAPPING_CHANGED;
  } // Change

  private final Set<Integer> instructorHubIds;

  private DBSimSession selectedSession;
  private Collection<DBSimSessionHub> selectedSessionHubs;

  private Object HUB_MAPPING_MUTEX = new Object();
  private Map<Integer, Integer> hubMappings = new HashMap<>();


  public ReplaySessionModel()
  {
    this(Collections.<Integer>emptySet());
  } // ReplaySessionModel


  public ReplaySessionModel(Set<Integer> aInstructorHubIds)
  {
    instructorHubIds = aInstructorHubIds;
  } // ReplaySessionModel


  public Set<Integer> getInstructorHubIds()
  {
    return instructorHubIds;
  } // getInstructorHubIds

  /**
   * @see Model
   */
  @Override
  protected void onCreate()
  {
    // Do nothing
  } // onCreate

  /**
   * @see Model
   */
  @Override
  protected void onDestroy()
  {
    // Do nothing
  } // onDestroy

  /**
   * Sets the currently selected session.
   *
   * @param aSession The session ID and all of the information from its Hubs.
   */
  public void setSelectedSession(Pair<DBSimSession, Collection<DBSimSessionHub>> aSession)
  {
    setSelectedSession(aSession.getFirst(), aSession.getSecond());
  }

  /**
   * Clears the currently selected session.
   */
  public void clearSelectedSession()
  {
    setSelectedSession(null, null);
  }

  private void setSelectedSession(final DBSimSession aSession, final Collection<DBSimSessionHub> aSessionHubs)
  {
    if (!DataObject.keyEquals(aSession, selectedSession))
    {
      selectedSession = aSession;
      selectedSessionHubs = aSessionHubs;

      fireModelChangedEvent( Change.SELECTED_SESSION_CHANGED );
    }
  }

  public DBSimSession getSelectedSession()
  {
    return selectedSession;
  }

  /**
   * @return The ID of the selected Session.
   */
  public Integer getSelectedSessionId()
  {
    return selectedSession == null ? null : selectedSession.getSessionId();
  } // getSelectedSessionId

  /**
   * Returns the records from the hubs of the currently selected session.
   *
   * @return a list of <code>DBSessionSCC</code> objects, or <code>null</code>
   */
  public Collection<DBSimSessionHub> getSelectedSessionHubs()
  {
    return selectedSessionHubs == null ? null : Collections.unmodifiableCollection(selectedSessionHubs);
  } // getSelectedSessionHubs

  /**
   * Clears the existing mapping and maps each recorded hub to the same simulator hub.
   */
  public void restoreDefaultHubMappings()
  {
    synchronized(HUB_MAPPING_MUTEX)
    {
      hubMappings.clear();

      if (selectedSessionHubs != null)
      {
        for (DBSimSessionHub sessionHub : selectedSessionHubs)
        {
          int hubId = sessionHub.getHubId();

          // don't do anything with instructor hubs here
          if (!instructorHubIds.contains(hubId))
          {
            // map this hub to itself
            hubMappings.put(hubId, hubId);
          } // if
        } // for
      } // if
    } // synchronized

    fireModelChangedEvent(Change.HUB_MAPPING_CHANGED);
  } // restoreDefaultHubMappings

  /**
   * Adds a mapping from a source hub to a destination hub.
   * <p>
   * Currently this will overwrite existing mapping if either hub is already
   * mapped, however in the future we may allow a source hub to be mapped to
   * multiple destination hubs.
   *
   * @param sourceHubId
   * @param destHubId
   */
  public void addHubMapping(int sourceHubId, int destHubId)
  {
    synchronized(HUB_MAPPING_MUTEX)
    {
      removeHubMappingByDestUtil(destHubId);
      hubMappings.put(sourceHubId, destHubId);
    } // synchronized

    fireModelChangedEvent(Change.HUB_MAPPING_CHANGED);
  } // addHubMapping

  /**
   * Removes all mappings using a source hub.
   *
   * @param sourceHubId
   */
  public void removeHubMappingBySource(int sourceHubId)
  {
    synchronized(HUB_MAPPING_MUTEX)
    {
      hubMappings.remove(sourceHubId);
    } // synchronized

    fireModelChangedEvent(Change.HUB_MAPPING_CHANGED);
  } // removeHubMappingBySource

  /**
   * Removes the mapping for a destination hub.
   *
   * @param destHubId
   */
  public void removeHubMappingByDest(int destHubId)
  {
    removeHubMappingByDestUtil(destHubId);
    fireModelChangedEvent(Change.HUB_MAPPING_CHANGED);
  } // removeHubMappingByDest

  /**
   * Removes the mapping for a destination hub. <b>FOR INTERNAL USE ONLY</b>
   * <p>
   * Does not notify listeners of the change; calling methods must do this.
   *
   * @param destHubId
   */
  private void removeHubMappingByDestUtil(int destHubId)
  {
    synchronized(HUB_MAPPING_MUTEX)
    {
      boolean found = false;
      int removeId = -1;

      for (int sourceHubId : hubMappings.keySet())
      {
        if (hubMappings.get(sourceHubId) == destHubId)
        {
          removeId = sourceHubId;
          found = true;
          break;
        } // if
      } // for

      if (found)
      {
        hubMappings.remove(removeId);
      } // if
    } // synchronized
  } // removeHubMappingByDest

  /**
   * @return An unmodifiable map of the source-to-destination hub ID mappings.
   */
  public Map<Integer, Integer> getHubMappings()
  {
    synchronized(HUB_MAPPING_MUTEX)
    {
      return Collections.unmodifiableMap(hubMappings);
    } // synchronized
  } // getHubMappings

  /**
   * Removes all hub mappings for playback.
   */
  public final void removeAllHubMappings()
  {
    synchronized(HUB_MAPPING_MUTEX)
    {
      hubMappings.clear();
      fireModelChangedEvent(Change.HUB_MAPPING_CHANGED);
    } // synchronized
  } // removeAllHubMappings

  public boolean hubMappingsUseSimulator(int simulatorId)
  {
    synchronized(HUB_MAPPING_MUTEX)
    {
      for (Integer destHubId : hubMappings.values())
      {
        DBPhysicalHub destHub = new DBPhysicalHub(destHubId);

        if (destHub.getSimulatorId() == simulatorId)
        {
          return true;
        } // if
      } // for
    } // synchronized

    return false;
  } // configDataUsesSimulator

  /**
   * Clears all internal data.
   */
  public void clear()
  {
    selectedSession = null;
    selectedSessionHubs = null;

    fireModelChangedEvent(Change.SELECTED_SESSION_CHANGED);
    removeAllHubMappings();
  } // clear

} // class ReplaySessionModel

// -- EOF
