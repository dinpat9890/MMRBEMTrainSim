package com.sydac.mmrbem.scc.plugin.sessionsetup.model;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import com.sydac.common.dataobjects.DBScenario;
import com.sydac.common.dataobjects.DBSessionSnapshot;
import com.sydac.common.dataobjects.DBSimSessionHub;
import com.sydac.common.dataobjects.DBSimSessionHubManager;
import com.sydac.foundation.Model;
import com.sydac.simulatorcontroller.model.ITerminateSessionListener;
import com.sydac.simulatorcontroller.model.LocalStateModel;
import com.sydac.simulatorcontroller.model.SimulationModel;

public class SessionSnapshotManager extends Model implements ITerminateSessionListener
{
  public enum Change
  {
    SESSION_SNAPSHOT_DATA_CHANGED, SESSION_DATA_CHANGED;
  }

  private static SessionSnapshotManager instance = null;
  
  /** The session database manager */
  private DBSimSessionHubManager dbSimSessionHubManager;

  /** A <code>HashMap</code> of sessions, keyed by session id */
  private Map<Integer, List<DBSimSessionHub>> simSessions = new HashMap<>();

  /** All session snapshots, keyed by identifier */
  private Map<Integer, DBSessionSnapshot> sessionSnapshots = new HashMap<>();

  /** session snapshots, belonging to same scenario */
  private Map<Integer, List<DBSessionSnapshot>> scenarioSessionSnapshots = new HashMap<>();

  /**
   * Default private constructor.
   */
  private SessionSnapshotManager()
  {

  } // SessionSnapshotManager

  /**
   * Returns the single instance of this class.
   *
   * @return a <code>SessionSnapshotManager</code>
   */
  public static synchronized SessionSnapshotManager getInstance()
  {
    if (instance == null)
    {
      instance = new SessionSnapshotManager();
      instance.create();
    } // if
    return instance;
  } // getInstance

  /*
   * (non-Javadoc)
   * 
   * @see com.sydac.foundation.Model#onCreate()
   */

  @Override
  public void onCreate()
  {    
    dbSimSessionHubManager = new DBSimSessionHubManager();
    refreshSessionData();
    refreshSessionSnapshotData();
    LocalStateModel.getInstance(). addTerminateSessionListener(this);
  }

  /*
   * (non-Javadoc)
   * 
   * @see com.sydac.foundation.Model#onDestroy()
   */
  @Override
  public void onDestroy()
  {
    sessionSnapshots.clear();
    scenarioSessionSnapshots.clear();
    simSessions.clear();
    sessionSnapshots = null;
    scenarioSessionSnapshots = null;
    simSessions = null;    
    dbSimSessionHubManager = null;
    LocalStateModel.getInstance().removeTerminateSessionListener(this);
    instance = null;
  }

  @Override
  public void terminateSession()
  {
    // Refresh the session list
    if (SimulationModel.getInstance().isReplay() == false)
    {
      refreshSessionData();
      refreshSessionSnapshotData();
    } // if
  }

  /**
   * Refresh the session snapshot data from the database.
   */
  public synchronized void refreshSessionSnapshotData()
  {
    sessionSnapshots.clear();
    scenarioSessionSnapshots.clear();
    
    for (DBSessionSnapshot dbSessionSnapshot : DBSessionSnapshot.loadAll())
    {
      Integer sessionSnapshotId = dbSessionSnapshot.getValue(DBSessionSnapshot.SESN_SNAPSHOT_ID);
      sessionSnapshots.put(sessionSnapshotId, dbSessionSnapshot);
      Integer scenarioId = dbSessionSnapshot.getValue(DBSessionSnapshot.SCEN_SCENARIO_ID);
      List<DBSessionSnapshot> snapshotsList = scenarioSessionSnapshots.get(scenarioId);
      if (null == snapshotsList)
      {
        snapshotsList = new ArrayList<>();
        snapshotsList.add(dbSessionSnapshot);
        scenarioSessionSnapshots.put(scenarioId, snapshotsList);
      }
      else
      {
        snapshotsList.add(dbSessionSnapshot);
      }
    }
    fireModelChangedEvent(Change.SESSION_SNAPSHOT_DATA_CHANGED);
  }

  /**
   * Refresh the session data from the database.
   */
  public void refreshSessionData()
  {
    simSessions.clear();
    dbSimSessionHubManager.reload();

    for (DBSimSessionHub simSession : dbSimSessionHubManager)
    {
      List<DBSimSessionHub> simSessionsPerHub = simSessions.get(simSession.getSessionId());
      if (simSessionsPerHub == null)
      {
        simSessionsPerHub = new ArrayList<>();
        simSessions.put(simSession.getSessionId(), simSessionsPerHub);
        simSessionsPerHub.add(simSession);
      } // if
    } // for

    fireModelChangedEvent(Change.SESSION_DATA_CHANGED);

  }

  /**
   * Returns a session snapshot object by providing its id.
   * 
   * @param sessionSnapshotId
   *          The Id of the session snapshot.
   * @return an instance of {@link DBSessionSnapshot} if a mapping found with
   *         <code>sessionSnapshotId</code> as key, otherwise returns
   *         <code>null</code>
   */
  public DBSessionSnapshot getSessionSnapshot(Integer sessionSnapshotId)
  {
    return sessionSnapshots.get(sessionSnapshotId);
  }

  /**
   * Returns a list of session snapshot objects.
   * 
   * @return list of session snapshot objects
   */
  public List<DBSessionSnapshot> getSessionSnapshots()
  {
    return Collections.unmodifiableList(new ArrayList<>(sessionSnapshots.values()));
  }

  /**
   * Returns a list of session snapshot objects associated with the scenario
   * specified by <code>scenarioId</code>. An empty list is returned if there
   * are no snapshots associated with the scenario.
   * 
   * @return a list of session snapshot objects
   */
  public List<DBSessionSnapshot> getSessionSnapshots(DBScenario scenario)
  {
    List<DBSessionSnapshot> snapshotsList = scenarioSessionSnapshots.get(scenario.getScenarioId());
    if (null != snapshotsList)
    {
      return Collections.unmodifiableList(snapshotsList);
    }
    else
    {
      return Collections.emptyList();
    }
  }

  /**
   * Checks if this scenario has session snapshots associated with it.
   * 
   * @param scenario
   *          - The scenario to be checked for session snapshot associations.
   * @return Returns <code>true</code> if session snapshots are associated with
   *         the <code>DBScenario</code> instance passed. Returns
   *         <code>false</code> otherwise.
   */
  public boolean hasSessionSnapshots(DBScenario scenario)
  {
    return scenarioSessionSnapshots.containsKey(scenario.getScenarioId());
  }

  /**
   * Returns the session hubs for the given session. There will be a
   * DBSimSession object for each hub that was used in that session.
   *
   * @param sessionId
   *          the identifier of the sessions to return
   *
   * @return a <code>Collection</code> of <code>DBSimSession</code> objects, or
   *         <code>Collections.emptyList()</code> if the session cannot be found
   */
  public List<DBSimSessionHub> getSessionHubs(Integer sessionId)
  {
    List<DBSimSessionHub> sessionHubs = simSessions.get(sessionId);
    if (null != sessionHubs)
    {
      return Collections.unmodifiableList(sessionHubs);
    }
    else
    {
      return Collections.emptyList();
    }
  } // getSessionHubs

  /**
   * 
   * @param sessionId
   * @return an instance of <code>DBSimSessionHub</code> or <code>null</code> if
   *         the session cannot be found
   */
  public DBSimSessionHub getSession(Integer sessionId)
  {
    List<DBSimSessionHub> sessionHubs = simSessions.get(sessionId);
    if (null == sessionHubs)
    {
      return null;
    }
    else
    {
      return sessionHubs.iterator().next();
    }
  }

}
