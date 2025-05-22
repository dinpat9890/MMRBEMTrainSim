/*
 * ==================================================================
 *
 * (C) Copyright 2015 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *
 * ==================================================================
 */
package com.sydac.mmrbem.scc.plugin.sessionsetup.replay;

import static com.sydac.simulatorcontroller.i18n.SimulatorControllerI18N.t;

import java.awt.Dialog.ModalityType;
import java.util.ArrayList;
import java.util.Collection;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

import javax.swing.JOptionPane;

import com.sydac.common.dataobjects.DBPhysicalHub;
import com.sydac.common.dataobjects.DBScenario;
import com.sydac.common.dataobjects.DBSimSession;
import com.sydac.common.dataobjects.DBSimSessionHub;
import com.sydac.common.dataobjects.DBSimulator;
import com.sydac.common.registry.Registry;
import com.sydac.common.sessiondata.BaseScenarioData;
import com.sydac.common.sessiondata.BaseSessionData;
import com.sydac.contentutils.scenario.gui.formatter.IScenarioDetailsFormatter;
import com.sydac.foundation.functional.Pair;
import com.sydac.gui.components.table.IColumnConfig;
import com.sydac.simulatorcontroller.common.RegistryConstants.SCC;
import com.sydac.simulatorcontroller.gui.MainFrame;
import com.sydac.simulatorcontroller.session.request.ScenarioDataBuilder;
import com.sydac.simulatorcontroller.session.request.SessionDataBuilder;
import com.sydac.simulatorcontroller.session.request.SessionRequester;
import com.sydac.simulatorcontroller.session.setup.plugin.basic.BasicSessionSetupPlugin;
import com.sydac.simulatorcontroller.session.setup.plugin.common.SessionRequestGUIUtils;
import com.sydac.simulatorcontroller.session.setup.plugin.common.SessionRequestGUIUtils.SessionRequest;
import com.sydac.simulatorcontroller.session.setup.plugin.multihub.MultipleHubSessionSetupPlugin;

/**
 * This class contains all of the methods used to handle input from an arbitrary
 * Replay Session screen.
 * <p>
 * It may be extended to:
 * <ul>
 * <li>make project-specific changes to the {@link BaseScenarioData} before
 * requesting the session, see {@link #modifyScenarioData(BaseScenarioData)}
 * <li>make project-specific changes to the {@link BaseSessionData} before
 * requesting the session, see {@link #modifySessionData(BaseSessionData)}
 * <li>supply project-specific details for displaying in Scenario summaries, see
 * {@link #getScenarioDetailsFormatter(DBScenario)}
 * </ul>
 *
 * @see ReplaySessionView
 * @see ReplaySessionHubMappingView
 */
public class ReplaySessionController
{
  private static final String HIDE_IDEAL_RUNS_KEY = "replaysession.hideidealruns";//$NON-NLS-1$

  public static final boolean HIDE_IDEAL_RUNS = Registry.getInstance().getBoolean(SCC.DOMAIN, HIDE_IDEAL_RUNS_KEY, true); 

  protected SessionRequester sessionRequester;

  private ReplaySessionModel replaySessionModel;

  public ReplaySessionController(SessionRequester aSessionRequester, ReplaySessionModel aModel)
  {
    sessionRequester = aSessionRequester;
    replaySessionModel = aModel;
  }

  /**
   * Allows the user to select a session to replay, using a dialog.
   */
  public final void selectSession()
  {
    SessionSelectionDialog sessionDialog = new SessionSelectionDialog(MainFrame.getInstance(), ModalityType.APPLICATION_MODAL, s -> getScenarioDetailsFormatter(s), getSessionSelectionTableConfig());
    sessionDialog.setVisible(true);

    if (sessionDialog.isValidSelection())
    {
      Pair<DBSimSession, Collection<DBSimSessionHub>> selectedSession = sessionDialog.getSelectedSession();
      setSelectedSession(selectedSession);
    }
  }

  /**
   * Clears the currently selected session.
   */
  public final void clearSelectedSession()
  {
    replaySessionModel.clear();
    replaySessionModel.clearSelectedSession();
    replaySessionModel.restoreDefaultHubMappings();
  }

  /**
   * Sets the currently selected session.
   *
   * @param aSession
   *          a session ID - session hub list pair.
   */
  public final void setSelectedSession(Pair<DBSimSession, Collection<DBSimSessionHub>> aSession)
  {
    replaySessionModel.clear();
    replaySessionModel.setSelectedSession(aSession);
    replaySessionModel.restoreDefaultHubMappings();
  }

  /**
   * Adds a mapping for the given source hub to be replayed on the given
   * destination hub.
   *
   * @param sourceHubId
   * @param destHubId
   */
  public final void addHubMapping(int sourceHubId, int destHubId)
  {
    boolean proceed = true;

    boolean sourceUsed = replaySessionModel.getHubMappings().containsKey(sourceHubId);
    boolean destUsed = replaySessionModel.getHubMappings().containsValue(destHubId);

    if (sourceUsed && destUsed)
    {
      proceed = JOptionPane.showOptionDialog(MainFrame.getInstance(), t("The selected Simulator Stations are already assigned to Configurations.\nDo you wish to overwrite?"), //$NON-NLS-1$
          t("Overwrite Configurations"), JOptionPane.YES_NO_OPTION, JOptionPane.INFORMATION_MESSAGE, null, null, null) //$NON-NLS-1$
      == JOptionPane.YES_OPTION;
    }
    else if (sourceUsed)
    {
      proceed = JOptionPane.showOptionDialog(MainFrame.getInstance(), t("The selected Recorded Simulator Station is already assigned to a Configuration.\nDo you wish to overwrite?"), //$NON-NLS-1$
          t("Overwrite Configuration"), JOptionPane.YES_NO_OPTION, JOptionPane.INFORMATION_MESSAGE, null, null, null) //$NON-NLS-1$
      == JOptionPane.YES_OPTION;
    }
    else if (destUsed)
    {
      proceed = JOptionPane.showOptionDialog(MainFrame.getInstance(), t("The selected Simulator Station is already assigned to a Configuration.\nDo you wish to overwrite?"), //$NON-NLS-1$
          t("Overwrite Configuration"), JOptionPane.YES_NO_OPTION, JOptionPane.INFORMATION_MESSAGE, null, null, null) //$NON-NLS-1$
      == JOptionPane.YES_OPTION;
    }

    if (proceed)
    {
      replaySessionModel.addHubMapping(sourceHubId, destHubId);
    }
  }

  /**
   * Removes all mappings from the given source hub.
   *
   * @param sourceHubId
   */
  public final void removeHubMappingBySource(int sourceHubId)
  {
    replaySessionModel.removeHubMappingBySource(sourceHubId);
  }

  /**
   * Removes the mappings to the given destination hub.
   *
   * @param destHubId
   */
  public final void removeHubMappingByDest(int destHubId)
  {
    replaySessionModel.removeHubMappingByDest(destHubId);
  }

  /**
   * Removes all mappings for playback.
   */
  public final void removeAllHubMappings()
  {
    replaySessionModel.removeAllHubMappings();
  }

  /**
   * Deletes all of the current settings and restores the default setup for a
   * replay of the currently selected session. This will mean that all hubs will
   * be set up to show what they showed during the original session.
   */
  public final void restoreDefaultHubMappings()
  {
    replaySessionModel.restoreDefaultHubMappings();
  }

  /**
   * Clears all user selections.
   */
  public final void clear()
  {
    replaySessionModel.clear();
  }

  /**
   * Loads the currently selected session as a replay.
   */
  public final void loadReplay()
  {
    SessionRequestGUIUtils.requestSessionWithWorkingDialog(new SessionRequest()
    {
      @Override
      public void doRequest() throws Exception
      {
        Map<Integer, Integer> hubIdMappings = new HashMap<>(replaySessionModel.getHubMappings());
        hubIdMappings.putAll(createInstructorsHubMappings());
        Integer sessionId = replaySessionModel.getSelectedSessionId();

        BaseScenarioData scenarioData = ScenarioDataBuilder.createReplayScenarioData(sessionId, hubIdMappings);
        scenarioData = modifyScenarioData(scenarioData);

        BaseSessionData sessionData = SessionDataBuilder.createReplaySessionData(sessionId, hubIdMappings);
        sessionData = modifySessionData(sessionData);

        sessionRequester.requestReplay(scenarioData, sessionData);
      }
    });
  }

  /**
   * Creates a set of mappings for the instructors' hubs based on the mappings
   * for trainee hubs selected by the user.
   * <p>
   * This method gives plugin writers a hook into customising this screen
   * without needing to do lots of copy-paste.
   * <p>
   * The default implementation is to look at the mapping of trainee hubs and
   * infer the required mapping of instructor hubs, unless any instructor hubs
   * are already mapped.
   * <p>
   * This method currently does not handle complex hub/replay setups well,
   * particularly if a replay is set up to replay multiple hubs on one hub. See
   * <a href=
   * "http://bugzilla.sydac.com.au/cgi-bin/bugzilla/show_bug.cgi?id=24788"> bug
   * 24788</a>.
   *
   * @return A map of source to destination instructor hub IDs.
   */
  public Map<Integer, Integer> createInstructorsHubMappings()
  {
    final Set<Integer> instructorHubIds = replaySessionModel.getInstructorHubIds();
    final Map<Integer, Integer> hubIdMappings = replaySessionModel.getHubMappings();
    final Collection<Integer> hubsInUseIds = hubIdMappings.values();
    Collection<DBPhysicalHub> traineeHubsInUse = new ArrayList<>();
    Set<Integer> simsInUseIDs = new HashSet<>();
    Collection<DBSimulator> searchSims = new ArrayList<>();

    Map<Integer, DBPhysicalHub> reverseHubMappings = new HashMap<>();

    for (Integer key : hubIdMappings.keySet())
    {
      Integer value = hubIdMappings.get(key);
      reverseHubMappings.put(value, new DBPhysicalHub(key));
    }

    // A source-destination sim mappings
    // these are implicitly defined in the hub mappings
    Map<Integer, Integer> simMapping = new HashMap<>();

    // find the sims that are used for replay
    for (Integer hubId : hubsInUseIds)
    {
      if (!instructorHubIds.contains(hubId))
      {
        DBPhysicalHub hub = new DBPhysicalHub(hubId);
        traineeHubsInUse.add(hub);
        int simId = hub.getSimulatorId();

        if (!simsInUseIDs.contains(simId))
        {
          simsInUseIDs.add(simId);

          // add this as a sim of interest
          searchSims.add(new DBSimulator(simId));

          DBPhysicalHub sourceHub = reverseHubMappings.get(hubId);

          // store the mapping from the original sim to the replay sim
          // TODO what about conflicting mappings?
          simMapping.put(sourceHub.getSimulatorId(), simId);
        }
      }
      else
      {
        // Instructor hubs have been mapped elsewhere, no need to do anything
        // here.
        return null;
      }
    }

    // mark the source sims as interesting
    for (Integer hubId : hubIdMappings.keySet())
    {
      searchSims.add(new DBPhysicalHub(hubId).getSimulator());
    }

    // instructor hubs indexed by sim
    Map<Integer, DBPhysicalHub> instructorHubs = new HashMap<>();

    // index the instructor hubs of the interesting sims
    for (DBSimulator sim : searchSims)
    {
      for (DBPhysicalHub simHub : sim.getPhysicalHubs())
      {
        // FIXME assuming one hub per sim
        if (instructorHubIds.contains(simHub.getPhysicalHubId()))
        {
          instructorHubs.put(sim.getSimulatorId(), simHub);
        }
      }
    }

    Map<Integer, Integer> instructorHubMapping = new HashMap<>();

    // map the instructor hubs
    for (Integer sourceSimId : simMapping.keySet())
    {
      // FIXME assuming one hub per sim
      DBPhysicalHub sourceHub = instructorHubs.get(sourceSimId);

      if (sourceHub != null)
      {
        Integer destHubId = simMapping.get(sourceSimId);

        if (destHubId != null)
        {
          DBPhysicalHub destHub = instructorHubs.get(destHubId);

          if (destHub != null)
          {
            instructorHubMapping.put(sourceHub.getPhysicalHubId(), destHub.getPhysicalHubId());
          }
        }
      }
    }

    return instructorHubMapping;
  }

  /**
   * Modifies the {@link BaseScenarioData} before the session is requested.
   * <p>
   * This method gives plugin writers a hook into customising this plugin
   * without needing to implement a whole new GUI (or copy-paste this one).
   *
   * @param scenarioData
   *          The scenario data that is to be modified.
   *
   * @return The scenario data to run with. This may be a
   *         {@link BaseScenarioData} or an extension.
   *
   * @see BasicSessionSetupPlugin#createReplaySessionController
   * @see MultipleHubSessionSetupPlugin#createReplaySessionController
   */
  protected BaseScenarioData modifyScenarioData(BaseScenarioData scenarioData)
  {
    return scenarioData;
  }

  /**
   * Modifies the {@link BaseSessionData} before the session is requested.
   * <p>
   * This method gives plugin writers a hook into customising this plugin
   * without needing to implement a whole new GUI (or copy-paste this one).
   *
   * @param sessionData
   *          The session data that is to be modified.
   *
   * @return The session data to run with. This may be a {@link BaseSessionData}
   *         or an extension.
   *
   * @see BasicSessionSetupPlugin#createReplaySessionController
   * @see MultipleHubSessionSetupPlugin#createReplaySessionController
   */
  protected BaseSessionData modifySessionData(BaseSessionData sessionData)
  {
    return sessionData;
  }

  /**
   * Supplies a formatter for the project-specific metadata in a Scenario.
   * <p>
   * Called while users are browsing available scenarios.
   * <p>
   * Default implementation returns a default {@link IScenarioDetailsFormatter}.
   *
   * @param scenario
   *          the scenario whose metadata formatter is desired.
   *
   * @return a formatter for the project-specific metadata in a Scenario.
   */
  protected IScenarioDetailsFormatter getScenarioDetailsFormatter(DBScenario scenario)
  {
    return new IScenarioDetailsFormatter()
    {};
  }

  /**
   * Returns a configuration for the {@link SessionSelectionDialog}'s table.
   * <p>
   * Called during construction.
   * <p>
   * {@link SessionSelectionDialog#createDefaultColumnConfigs()} is returned by
   * default.
   *
   * @return a configuration for the {@link SessionSelectionDialog}'s table.
   */
  protected List<IColumnConfig<Pair<DBSimSession, Collection<DBSimSessionHub>>, ?>> getSessionSelectionTableConfig()
  {
    return SessionSelectionDialog.createDefaultColumnConfigs();
  }

}
