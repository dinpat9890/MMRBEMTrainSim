/*
 * ==================================================================
 * 
 * (C) Copyright 2010 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.scc.plugin.sessionsetup.simulation;

import java.util.Collections;
import java.util.Date;
import java.util.HashMap;
import java.util.Map;

import com.sydac.common.dataobjects.DBScenario;
import com.sydac.common.dataobjects.DBSessionSnapshot;
import com.sydac.common.dataobjects.DBSimInstructor;
import com.sydac.common.dataobjects.DBSimSession;
import com.sydac.common.dataobjects.DBSimTrainee;
import com.sydac.common.dataobjects.DBVirtualLocation;
import com.sydac.foundation.IModelListener;
import com.sydac.foundation.Model;
import com.sydac.simulatorcontroller.session.setup.plugin.basic.simulatedsession.HubLocationModel;
import com.sydac.simulatorcontroller.session.setup.plugin.basic.simulatedsession.IHubLocationModel;
import com.sydac.simulatorcontroller.session.setup.plugin.basic.simulatedsession.training.ITrainingSessionModel;
import com.sydac.simulatorcontroller.session.setup.plugin.common.simulatedsession.training.AbstractNewSessionModel;

public final class SimulationSessionModel extends AbstractNewSessionModel implements IHubLocationModel, ITrainingSessionModel
{
  public enum Change
  {
    SNAPSHOT_CHANGED;
  }

  private DBSessionSnapshot snapshot;

  private Map<Integer, DBSimTrainee> trainees = new HashMap<>();

  IHubLocationModel hubLocationModel = new HubLocationModel();

  public SimulationSessionModel()
  {
    // forward updates
    hubLocationModel.addModelListener(new IModelListener()
    {
      @Override
      public void update(Model model, Enum<?> whatChanged)
      {
        fireModelChangedEvent(whatChanged);
      }
    }, false);
  }

  @Override
  protected void onCreate()
  {
    super.onCreate();
    hubLocationModel.create();
  }

  @Override
  protected void onDestroy()
  {
    hubLocationModel.destroy();
    super.onDestroy();
  }

  @Override
  public void setInstructor(DBSimInstructor aInstructor)
  {
    super.setInstructor(aInstructor);
  }

  public void setSnapshot(DBSessionSnapshot aSnapshot)
  {
    if (aSnapshot != snapshot)
    {
      clearHubLocations();
      snapshot = aSnapshot;
      if (null != snapshot)
      {
        DBSimSession session = new DBSimSession(snapshot.getValue(DBSessionSnapshot.SISE_SIMSESSION_ID));
        setDateTime(new Date(session.getSimStartDateUTC().getTime() + snapshot.getElapsedTimeMillis()));
      }
      fireModelChangedEvent(Change.SNAPSHOT_CHANGED);
    }
  }

  public DBSessionSnapshot getSnapshot()
  {
    return snapshot;
  }

  @Override
  public void setScenario(DBScenario aScenario)
  {
    if (aScenario != getScenario())
    {
      clearHubLocations();
      clearSelectedSessionSnapshot();
      super.setScenario(aScenario);
    }
  }

  @Override
  public void setHubTrainee(int hubId, DBSimTrainee trainee)
  {
    trainees.put(hubId, trainee);
    fireModelChangedEvent(ITrainingSessionModel.Change.HUB_TRAINEE_CHANGED);
  }

  public Map<Integer, DBSimTrainee> getHubTrainees()
  {
    return Collections.unmodifiableMap(trainees);
  }

  @Override
  public DBSimTrainee getHubTrainee(Integer hubId)
  {
    return trainees.get(hubId);
  }

  public void clearHubTrainee(Integer hubId)
  {
    trainees.remove(hubId);
    fireModelChangedEvent(ITrainingSessionModel.Change.HUB_TRAINEE_CHANGED);
  }

  public void clearHubTrainees()
  {
    trainees.clear();
    fireModelChangedEvent(ITrainingSessionModel.Change.HUB_TRAINEE_CHANGED);
  }

  @Override
  public void clearHubLocation(Integer hubId)
  {
    hubLocationModel.clearHubLocation(hubId);
  }

  @Override
  public void clearHubLocations()
  {
    hubLocationModel.clearHubLocations();
  }

  @Override
  public DBVirtualLocation getHubLocation(Integer hubId)
  {
    return hubLocationModel.getHubLocation(hubId);
  }

  @Override
  public Map<Integer, DBVirtualLocation> getHubLocations()
  {
    return hubLocationModel.getHubLocations();
  }

  @Override
  public void setHubLocation(Integer hubId, DBVirtualLocation location)
  {
    hubLocationModel.setHubLocation(hubId, location);
  }

  @Override
  public void clearHubSettings(Integer hubId)
  {
    clearHubTrainee(hubId);
    clearHubLocation(hubId);
  }

  /**
   * Clear the selected snapshot.
   */
  public void clearSelectedSessionSnapshot()
  {
    setSnapshot(null);
  }
}
