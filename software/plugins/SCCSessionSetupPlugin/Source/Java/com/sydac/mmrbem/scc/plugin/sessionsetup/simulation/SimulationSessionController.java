/*
 * ==================================================================
 * 
 * (C) Copyright 2015 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.scc.plugin.sessionsetup.simulation;

import static com.sydac.simulatorcontroller.i18n.SimulatorControllerI18N.t;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Date;
import java.util.List;
import java.util.Map;
import java.util.Optional;

import javax.swing.JOptionPane;
import javax.swing.SwingUtilities;

import com.sydac.common.dataobjects.DBPhysicalHub;
import com.sydac.common.dataobjects.DBScenario;
import com.sydac.common.dataobjects.DBScenarioGroup;
import com.sydac.common.dataobjects.DBScenarioTrain;
import com.sydac.common.dataobjects.DBSessionSnapshot;
import com.sydac.common.dataobjects.DBSimInstructor;
import com.sydac.common.dataobjects.DBSimSession;
import com.sydac.common.dataobjects.DBSimSessionHub;
import com.sydac.common.dataobjects.DBSimTrainee;
import com.sydac.common.dataobjects.DBVirtualLocation;
import com.sydac.common.registry.Registry;
import com.sydac.common.sessiondata.BaseScenarioData;
import com.sydac.common.sessiondata.BaseSessionData;
import com.sydac.contentutils.scenario.gui.formatter.IScenarioDetailsFormatter;
import com.sydac.contentutils.scenario.gui.select.DBScenarioSelectionDialog;
import com.sydac.contentutils.scenario.gui.select.DBScenarioSelectionDialog.IDBScenarioCache;
import com.sydac.contentutils.session.gui.select.DBSessionSnapshotSelectionDialog;
import com.sydac.contentutils.session.gui.select.DBSessionSnapshotSelectionDialog.IDBSnapshotCache;
import com.sydac.foundation.functional.Pair;
import com.sydac.gui.components.table.IColumnConfig;
import com.sydac.mmrbem.scc.plugin.sessionsetup.MmrbemSessionSetupPlugin;
import com.sydac.mmrbem.scc.plugin.sessionsetup.model.SessionSnapshotManager;
import com.sydac.mmrbem.scc.plugin.sessionsetup.sessionsnapshot.SessionSnapshotSelectionDialog;
import com.sydac.mmrbem.scc.plugin.sessionsetup.sessionsnapshot.SessionSnapshotSelectionDialog.CofmowIDBSnapshotCache;
import com.sydac.persistence.timetables.Timetable;
import com.sydac.signaltrackviewer.gui.selection.SegmentPositionSelectionEditor;
import com.sydac.signaltrackviewer.gui.selection.SegmentPositionSelectionEditor.OrientationSelection;
import com.sydac.signaltrackviewer.model.Train;
import com.sydac.signaltrackviewer.model.TrainFactory;
import com.sydac.simulatorcontroller.common.ErrorManager;
import com.sydac.simulatorcontroller.common.RegistryConstants;
import com.sydac.simulatorcontroller.common.RegistryConstants.SCC;
import com.sydac.simulatorcontroller.gui.MainFrame;
import com.sydac.simulatorcontroller.model.ScenarioManager;
import com.sydac.simulatorcontroller.model.TrackManager;
import com.sydac.simulatorcontroller.session.request.HubConfig;
import com.sydac.simulatorcontroller.session.request.ScenarioDataBuilder;
import com.sydac.simulatorcontroller.session.request.SessionDataBuilder;
import com.sydac.simulatorcontroller.session.request.SessionRequester;
import com.sydac.simulatorcontroller.session.request.SessionRequester.ScenarioChangedException;
import com.sydac.simulatorcontroller.session.setup.gui.dialog.InstructorSelectionDialog;
import com.sydac.simulatorcontroller.session.setup.plugin.basic.BasicSessionSetupPlugin;
import com.sydac.simulatorcontroller.session.setup.plugin.basic.BasicSessionSetupPlugin.InstructorHubsRegistryConstants;
import com.sydac.simulatorcontroller.session.setup.plugin.basic.simulatedsession.training.ITrainingSessionController;
import com.sydac.simulatorcontroller.session.setup.plugin.common.SessionRequestGUIUtils;
import com.sydac.simulatorcontroller.session.setup.plugin.common.SessionRequestGUIUtils.SessionRequest;
import com.sydac.simulatorcontroller.session.setup.plugin.common.simulatedsession.LiveSessionModel;
import com.sydac.trackdatautils.model.SegmentPosition;
import com.sydac.trackdatautils.model.SegmentPosition.Orientation;
import com.sydac.trackdatautils.model.TrackNetwork;

public class SimulationSessionController implements ITrainingSessionController
{
  private static final String SCENARIO_SELECTION_FILTER_ENABLED_KEY = "scenarioselection.filter.enabled"; //$NON-NLS-1$

  private static final String SCENARIO_SELECTION_FILTER_CARCLASS_KEY = "scenarioselection.filter.carclass"; //$NON-NLS-1$

  private static final int NULL_TABLE_ID = -1;

  public static final String TRAIN_PARAMETER_DOMAIN = "trainparameter"; //$NON-NLS-1$

  private static final String USE_CUSTOM_VALUES_KEY = "usecustomvalues"; //$NON-NLS-1$

  public String USE_CUSTOM_VALUES_PROPERTY;

  private static Registry registry = Registry.getInstance();

  private static ErrorManager errorManager = ErrorManager.getInstance();

  private SimulationSessionModel simulationSessionModel;

  private SessionSnapshotSelectionDialog snapshotDialog;

  private DBScenarioSelectionDialog scenarioDialog;

  private SessionRequester sessionRequester;

//  private IdealRunSessionModel idealRunSessionModel;

  private boolean isUseCustomValues = false;

  private boolean idealRunEnabled = false;

  public SimulationSessionController(SessionRequester aSessionRequester,
      SimulationSessionModel aSimulationSessionModel)
  {
    sessionRequester = aSessionRequester;
    simulationSessionModel = aSimulationSessionModel;
    SwingUtilities.invokeLater(() -> snapshotDialog = createSnapshotSelectionDialog());
    SwingUtilities.invokeLater(() -> scenarioDialog = createScenarioSelectionDialog());
    idealRunEnabled = Registry.getInstance().getBoolean(RegistryConstants.SCC.DOMAIN,
        MmrbemSessionSetupPlugin.ENABLE_IDEAL_RUN_KEY, false);
    if (idealRunEnabled)
    {
      USE_CUSTOM_VALUES_PROPERTY = Registry.getInstance().getString(TRAIN_PARAMETER_DOMAIN,
          USE_CUSTOM_VALUES_KEY);
    }
    //idealRunSessionModel = new IdealRunSessionModel();
  }

  private SessionSnapshotSelectionDialog createSnapshotSelectionDialog()
  {
    final ScenarioManager scenarioManager = ScenarioManager.getInstance();
    final SessionSnapshotManager sessionSnapshotManager = SessionSnapshotManager.getInstance();
    final MainFrame mainFrame = MainFrame.getInstance();
    return new SessionSnapshotSelectionDialog(mainFrame, new CofmowIDBSnapshotCache() {
      @Override
      public Collection<DBSessionSnapshot> getSnapshots()
      {
        return sessionSnapshotManager.getSessionSnapshots();
      }

      @Override
      public DBScenario getScenario(DBSessionSnapshot snapshot)
      {
        return scenarioManager.getScenario(snapshot.getValue(DBSessionSnapshot.SCEN_SCENARIO_ID));
      }

      @Override
      public DBSimSession getSession(DBSessionSnapshot snapshot)
      {
        return new DBSimSession(snapshot.getValue(DBSessionSnapshot.SISE_SIMSESSION_ID));
      }

      @Override
      public Collection<DBSessionSnapshot> getSnapshots(DBScenario scenario)
      {
        return sessionSnapshotManager.getSessionSnapshots(scenario);
      }

      @Override
      public DBSimSessionHub getSessionHub(DBSessionSnapshot snapshot)
      {
        return sessionSnapshotManager.getSession(snapshot.getValue(DBSessionSnapshot.SISE_SIMSESSION_ID));
      }
    });
  }

  private DBScenarioSelectionDialog createScenarioSelectionDialog()
  {
    final ScenarioManager scenarioManager = ScenarioManager.getInstance();
    final MainFrame mainFrame = MainFrame.getInstance();
    final boolean filterScenarios = registry.getBoolean(SCC.DOMAIN, SCENARIO_SELECTION_FILTER_ENABLED_KEY,
        false);
    return new DBScenarioSelectionDialog(mainFrame, new IDBScenarioCache() {
      @Override
      public Collection<DBScenario> getAllScenarios()
      {
        List<DBScenario> allScenarios = scenarioManager.getSimulatorScenarios();
        if (filterScenarios)
        {
          return filterScenarios(allScenarios);
        }
        else
        {
          return allScenarios;
        }
      }

      @Override
      public Collection<DBScenario> getScenarios(DBScenarioGroup aGroup)
      {
        List<DBScenario> groupScenarios = scenarioManager.getSimulatorScenarios(aGroup);
        if (filterScenarios)
        {
          return filterScenarios(groupScenarios);
        }
        else
        {
          return groupScenarios;
        }
      }

      @Override
      public Collection<DBScenarioGroup> getScenarioGroups()
      {
        return scenarioManager.getScenarioGroups();
      }
    }, (DBScenario scenario) -> {
      return TrackManager.getInstance().getTrackMapTrack(scenario);
    }, Optional.empty(), Optional.of(s -> getScenarioDetailsFormatter(s)),
        Optional.of(getScenarioSelectionTableConfig()));
  }

  private List<DBScenario> filterScenarios(List<DBScenario> scenarios)
  {
    String carClassFiter = registry.getString(SCC.DOMAIN, SCENARIO_SELECTION_FILTER_CARCLASS_KEY);
    String[] carClassFilters = carClassFiter.split(":"); //$NON-NLS-1$
    List<DBScenario> filtered = new ArrayList<>();
    for (DBScenario scenario : scenarios)
    {
      Optional<DBScenarioTrain> train = scenario.getScenarioTrains().stream().filter(e -> e.isSimulated())
          .findFirst();
      if (train.isPresent())
      {
        DBScenarioTrain scenariotrain = train.get();
        for (String filter : carClassFilters)
        {
          if (scenariotrain.getTrain().getElements().stream()
              .anyMatch(k -> filter.equals(k.getCar().getClassType().getClassCode())))
          {
            filtered.add(scenario);
          }
        }
      }
    }
    return filtered;
  }

  /**
   * Allows the user to select an instructor for the session.
   */
  public final void selectInstructor()
  {
    InstructorSelectionDialog instructorDialog = new InstructorSelectionDialog(MainFrame.getInstance(), true);
    instructorDialog.setVisible(true);

    if (instructorDialog.isValidSelection() == true)
    {
      DBSimInstructor selectedInstructor = instructorDialog.getSelectedInstructor();
      simulationSessionModel.setInstructor(selectedInstructor);
    } // if
  } // selectInstructor

  public final void clearReferenceSession()
  {
    simulationSessionModel.clearReferenceSessionId();
  } // selectReferenceSession

  public final void selectReferenceSession(Integer session)
  {
    simulationSessionModel.setReferenceSessionId(session);
  } // selectReferenceSession

  public final void clearSimulatedLocation(Integer hubId)
  {
    simulationSessionModel.clearHubLocation(hubId);
  }

  public final void selectSimulatedLocation(Integer hubId, DBVirtualLocation location)
  {
    simulationSessionModel.setHubLocation(hubId, location);
  }

  /**
   * Sets the miscellaneous text items for a session.
   *
   * @param aCourseId
   *          a <code>String</code> containing the course identifier
   * @param aSessionCode
   *          a <code>String</code> containing the session code
   */
  public final void setTextItems(String aCourseId, String aSessionCode)
  {
    simulationSessionModel.setCourseId(aCourseId);
    simulationSessionModel.setSessionCode(aSessionCode);
  } // setTextItems

  /**
   * 
   */
  public void selectSnapshot()
  {
    snapshotDialog.updateData(simulationSessionModel.getScenario());
    snapshotDialog.setSelectedSnapshot(simulationSessionModel.getSnapshot());
    snapshotDialog.setVisible(true);
    simulationSessionModel.setSnapshot(snapshotDialog.getSelectedSnapshot());
  }

  /**
   * Loads the current scenario
   */
  public final void loadScenario()
  {
    final DBSimInstructor instructor = simulationSessionModel.getInstructor();

    SessionRequestGUIUtils.requestSessionWithWorkingDialog(new SessionRequest() {

      @Override
      public void doRequest() throws Exception
      {
        // First perform a few checks to make sure that the instructor has
        // selected everything that they need to.
        // These should never come up, if it does, someone's broken the GUI.
        if (instructor == null)
        {
          errorManager.showError(t("Input"), //$NON-NLS-1$
              t("An instructor must be selected")); //$NON-NLS-1$
        }
        else
        {
          Collection<HubConfig> traineeHubConfigs = createTraineeConfigData();

          try
          {
            BaseScenarioData scenarioData = ScenarioDataBuilder.createScenarioData(
                simulationSessionModel.getScenario(), traineeHubConfigs,
                createInstructorsHubConfigs(traineeHubConfigs));

            scenarioData = modifyScenarioData(scenarioData);

            DBSessionSnapshot snapshot = simulationSessionModel.getSnapshot();
            BaseSessionData sessionData = null;
            if (null == snapshot)
            {
              sessionData = SessionDataBuilder.createTrainingSessionData(scenarioData, instructor,
                  simulationSessionModel.getReferenceSessionId(), traineeHubConfigs,
                  createInstructorsHubConfigs(traineeHubConfigs),
                  simulationSessionModel.createStartPositions(), simulationSessionModel.getDateTime(),
                  simulationSessionModel.getSessionCode(), simulationSessionModel.getCourseId());
            }
            else
            {
              sessionData = SessionDataBuilder.createResumeSessionData(scenarioData, instructor,
                  simulationSessionModel.getReferenceSessionId(),
                  snapshot.getValue(DBSessionSnapshot.SISE_SIMSESSION_ID),
                  snapshot.getValue(DBSessionSnapshot.SESN_TAG), traineeHubConfigs,
                  createInstructorsHubConfigs(traineeHubConfigs),
                  simulationSessionModel.createStartPositions(), simulationSessionModel.getDateTime(),
                  simulationSessionModel.getSessionCode(), simulationSessionModel.getCourseId());
            }
            // sessionData = modifySessionData(sessionData);

            sessionRequester.requestSimulation(scenarioData, sessionData, traineeHubConfigs);
          }
          catch (ScenarioChangedException e)
          {
            handleScenarioChangedException(simulationSessionModel);
          }
        }
      }
    });
  }

  /*
   * private Collection<InitialNumberValues>
   * toInitalNumberValues(List<TrainParameter> trainParameters) { Integer
   * trainInstance = getScenarioTrain().getScenarioTrainId(); CObjectParentId
   * trainObjId = new CObjectParentId(null, CoreObjectConstants.ClassId.HUB,
   * trainInstance); Collection<InitialNumberValues> allInitialNumberValues =
   * new ArrayList<>(trainParameters.size());
   * trainParameters.forEach(trainParameter -> { NumberNameValue[] nnvs = new
   * NumberNameValue[] { new NumberNameValue(trainParameter.getCommsName(),
   * trainParameter.getValue()) }; CObjectAndValues coav = new
   * CObjectAndValues(trainObjId, nnvs, null, null); InitialNumberValues
   * initialNumberValues =
   * coav.asInitialNumberValues(SimulatorControllerConsoleApplication.
   * getRuntimeData());
   * 
   * if (initialNumberValues != null) { List<InitialNumberValue>
   * listOfInitialNumberValues =
   * Arrays.asList(initialNumberValues.getInitialValues());
   * 
   * for (InitialNumberValue inv : listOfInitialNumberValues) { // The first
   * identifier is the end of the path, although see below, we // should really
   * consider the whole path // if this is necessary. ObjectIdentifier oi =
   * initialNumberValues.getObjectIdentifiers()[0]; String property =
   * inv.getName(); if (oi != null && property != null) {
   * allInitialNumberValues.add(new
   * InitialNumberValues(initialNumberValues.getObjectIdentifiers(), new
   * InitialNumberValue[] { inv })); } } } }); return allInitialNumberValues;
   * 
   * }
   */

  /**
   * @param initalNumberValues
   */
  /*
   * private void addIdealRunConfigurationValues(Collection<InitialNumberValues>
   * initalNumberValues) { Integer timetableId =
   * idealRunSessionModel.getTimetableId(); if (null == timetableId) {
   * timetableId = NULL_TABLE_ID; } CObjectParentId cConfigObjId = new
   * CObjectParentId(null, ProjectObjectConstants.ClassId.IDEAL_RUN_CONFIG,
   * null); NumberNameValue[] nnvs = new NumberNameValue[] { new
   * NumberNameValue(ProjectObjectConstants.IdealRunConfig.TIMETABLE_ID,
   * timetableId) }; CObjectAndValues coav = new CObjectAndValues(cConfigObjId,
   * nnvs, null, null); initalNumberValues.add(coav.asInitialNumberValues(new
   * ProjectObjects())); // TODO A UI field should be added for user to select
   * allout. if (timetableId == NULL_TABLE_ID) { nnvs = new NumberNameValue[] {
   * new NumberNameValue(ProjectObjectConstants.IdealRunConfig.ALL_OUT, 1) }; }
   * else { nnvs = new NumberNameValue[] { new
   * NumberNameValue(ProjectObjectConstants.IdealRunConfig.ALL_OUT, 0) }; } coav
   * = new CObjectAndValues(cConfigObjId, nnvs, null, null);
   * initalNumberValues.add(coav.asInitialNumberValues(new ProjectObjects())); }
   * 
   *//**
      * @return list of {@link Timetable}
      *//*
         * private List<TrainParameter> loadTrainParameters(DBScenario
         * dbScenario) { return null; Collection<DBScenarioTrainParameterAssoc>
         * dbScenarioTrainParameterAssocs =
         * DBScenarioTrainManager.loadAll(dbScenario);
         * 
         * List<TrainParameter> trainParameters = new
         * ArrayList<>(dbScenarioTrainParameterAssocs.size());
         * dbScenarioTrainParameterAssocs.forEach(scenarioTrainParameterAssoc ->
         * { DBTrainParameter dbTrainParameter = new
         * DBTrainParameter(scenarioTrainParameterAssoc.getValue(
         * DBScenarioTrainParameterAssoc.TPAR_ID)); dbTrainParameter.load();
         * 
         * if (idealRunEnabled &&
         * USE_CUSTOM_VALUES_PROPERTY.equals(dbTrainParameter.getValue(
         * DBTrainParameter.TPAR_COMMS_NAME))) { int useCustomValues =
         * scenarioTrainParameterAssoc.getValue(DBScenarioTrainParameterAssoc.
         * STPA_VALUE).intValue(); isUseCustomValues = useCustomValues > 0 ?
         * true : false; }
         * 
         * TrainParameter trainParameter = new
         * TrainParameter(dbTrainParameter.getValue(DBTrainParameter.TPAR_ID),
         * dbTrainParameter.getValue(DBTrainParameter.TPAR_DISPLAY_NAME),
         * dbTrainParameter.getValue(DBTrainParameter.TPAR_COMMS_NAME),
         * scenarioTrainParameterAssoc.getValue(DBScenarioTrainParameterAssoc.
         * STPA_VALUE)); trainParameters.add(trainParameter); }); return
         * trainParameters;
         * 
         * }
         */

  private Collection<HubConfig> createTraineeConfigData()
  {
    Collection<HubConfig> traineeHubConfigs = new ArrayList<>();

    Map<Integer, DBSimTrainee> hubTrainees = simulationSessionModel.getHubTrainees();
    Map<Integer, DBVirtualLocation> hubLocations = simulationSessionModel.getHubLocations();

    for (Map.Entry<Integer, DBSimTrainee> entry : hubTrainees.entrySet())
    {
      traineeHubConfigs.add(new HubConfig(entry.getValue(), new DBPhysicalHub(entry.getKey()),
          hubLocations.get(entry.getKey())));
    }

    return traineeHubConfigs;
  }

  /**
   * Creates a set of {@link HubConfig}s for the instructors.
   * <p>
   * This method gives plugin writers a hook into customising this plugin
   * without needing to do lots of copy-paste.
   * <p>
   * The default implementation is to use
   * {@link HubConfig#createInstructorsHubConfigs(DBSimInstructor, Collection, Collection)}.
   *
   * @return The {@link HubConfig}s for the instructors' modules to use.
   */
  public Collection<HubConfig> createInstructorsHubConfigs(Collection<HubConfig> traineeHubConfigs)
  {
    Collection<Pair<String, String>> instructorHubTypeModePairs = new ArrayList<>();
    int instructorHubCount = registry.getInteger(InstructorHubsRegistryConstants.DOMAIN,
        InstructorHubsRegistryConstants.COUNT_KEY, 0);

    for (int i = 1; i <= instructorHubCount; i++)
    {
      String typeName = registry.getString(InstructorHubsRegistryConstants.DOMAIN,
          i + "." + InstructorHubsRegistryConstants.TYPE_KEY); //$NON-NLS-1$
      String modeName = registry.getString(InstructorHubsRegistryConstants.DOMAIN,
          i + "." + InstructorHubsRegistryConstants.MODE_KEY); //$NON-NLS-1$

      instructorHubTypeModePairs.add(new Pair<>(typeName, modeName));
    }

    return HubConfig.createInstructorsHubConfigs(simulationSessionModel.getInstructor(), traineeHubConfigs,
        instructorHubTypeModePairs);
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
   * @see BasicSessionSetupPlugin#createNewSessionController
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
   * @see BasicSessionSetupPlugin#createNewSessionController
   */
  /*
   * protected BaseSessionData modifySessionData(BaseSessionData sessionData) {
   * if (isUseCustomValues) { // set the initial values for train parameters
   * List<TrainParameter> trainParameters =
   * idealRunSessionModel.getTrainParameters(); Collection<InitialNumberValues>
   * initalNumberValues = toInitalNumberValues(trainParameters);
   * 
   * addIdealRunConfigurationValues(initalNumberValues);
   * 
   * sessionData.addAllInitialNumberValues(initalNumberValues); }
   * 
   * return sessionData; }
   * 
   */ /**
       * Clears all entered data.
       */
  public final void clear()
  {
    simulationSessionModel.setScenario(null);
    simulationSessionModel.setDateTime(null);
    simulationSessionModel.clearStartPositions();

    simulationSessionModel.setInstructor(null);
    simulationSessionModel.setSnapshot(null);
    simulationSessionModel.setCourseId(null);
    simulationSessionModel.setSessionCode(null);
    simulationSessionModel.clearHubTrainees();
    simulationSessionModel.clearHubLocations();
  }

  /**
   * Allows the user to select a scenario for the session.
   */
  public final void selectScenario()
  {
    refreshScenarioData();
    scenarioDialog.setVisible(true);
    DBScenario selectedScenario = scenarioDialog.getSelectedScenario();

    if (selectedScenario != null)
    {
      simulationSessionModel.setScenario(selectedScenario);
     // idealRunSessionModel.setScenario(selectedScenario);
      // idealRunSessionModel.setTrainParameters(loadTrainParameters(selectedScenario));
    }

  }

  /**
   * Displays a message to the user to tell them that the scenario was modified
   * after they loaded it and it will be reloaded, then does so when the user
   * presses Ok.
   * <p>
   * Usually this would be called after catching a
   * {@link ScenarioChangedException}.
   * <p>
   * Typical usage is something like:
   * 
   * <pre>
   * try
   * {
   *   // This may throw a ScenarioChangedException
   *   SessionData sessionData = sessionRequester.createSessionData(...);
   *   sessionRequester.requestSimulation(sessionData, traineeHubConfigs);
   * }
   * catch (ScenarioChangedException e)
   * {
   *   handleScenarioChangedException(model);
   * }
   * </pre>
   */
  protected void handleScenarioChangedException(LiveSessionModel model)
  {
    int scenarioId = model.getScenario().getScenarioId();
    refreshScenarioData();

    DBScenario scenario = null;

    for (DBScenario candidate : ScenarioManager.getInstance().getSimulatorScenarios())
    {
      if (candidate.getScenarioId() == scenarioId)
      {
        scenario = candidate;
        break;
      }
    }

    if (scenario == null)
    {
      JOptionPane.showMessageDialog(MainFrame.getInstance(), t(
          "The scenario has been modfied and is no longer usable for this simulator. Please select a different scenario."), //$NON-NLS-1$
          t("Scenario not usable"), JOptionPane.INFORMATION_MESSAGE); //$NON-NLS-1$
    }
    else
    {
      JOptionPane.showMessageDialog(MainFrame.getInstance(), t(
          "The scenario has been modfied after it was opened here, so your setup may no longer be valid.\nIt will now be reloaded and you will need to set your session up again."), //$NON-NLS-1$
          t("Scenario modified"), JOptionPane.INFORMATION_MESSAGE); //$NON-NLS-1$
    }

    model.setScenario(scenario);
  }

  private static void refreshScenarioData()
  {
    // Force a reload of all data associated with scenarios
    TrackManager.getInstance().clearCache();
    ScenarioManager.getInstance().refreshData();
  }

  /**
   * Sets the simulation date/time for the session.
   *
   * @param aDateTime
   *          the date/time to be simulated, relative to UTC
   */
  public final void setDateTime(Date aDateTime)
  {
    if (aDateTime != null)
    {
      simulationSessionModel.setDateTime(aDateTime);
    }
  }

  /**
   * Allows the user to select a trainee for the session.
   */
  @Override
  public final void selectStartPosition(int scenarioTrainID)
  {
    DBScenario scenario = simulationSessionModel.getScenario();
    if (scenario != null)
    {
      SegmentPositionSelectionEditor selectionEditor = new SegmentPositionSelectionEditor(
          OrientationSelection.DIRECTIONAL);
      SegmentPosition sp = simulationSessionModel.getStartPosition(scenarioTrainID);

      if (sp != null)
      {
        selectionEditor.setSelection(sp);
      }

      TrackManager.getInstance().getTrackMapDialog(scenario, createTrains()).show(MainFrame.getInstance(),
          selectionEditor);

      sp = selectionEditor.getSelection();

      if (sp != null)
      {
        simulationSessionModel.setStartPosition(scenarioTrainID, sp);
      }
    }
  }

  /**
   * Creates trains based on their currently configured positions, not the
   * positions in the database.
   */
  private Collection<Train> createTrains()
  {
    DBScenario scenario = simulationSessionModel.getScenario();
    TrackNetwork trackNetwork = new TrackNetwork(TrackManager.getInstance().getTrackMapTrack(scenario));
    Collection<DBScenarioTrain> dbTrains = scenario.getScenarioTrains();
    Collection<Train> trains = new ArrayList<>(dbTrains.size());

    for (DBScenarioTrain dbTrain : dbTrains)
    {
      SegmentPosition start = simulationSessionModel.getStartPosition(dbTrain.getScenarioTrainId());
      // start will be null if the position hasn't been set for this session
      Train train = start == null
          // get the position from the scenario
          ? TrainFactory.createTrain(dbTrain, trackNetwork.getSegment(dbTrain.getSegmentId()),
              dbTrain.getOffset(), dbTrain.isHeadingAlpha())
          : TrainFactory.createTrain(dbTrain, trackNetwork.getSegment(start.getSegment().getID()),
              start.getOffset(), start.getOrientation().equals(Orientation.ALPHA_TO_BETA));

      trains.add(train);
    }

    return trains;
  }

  /**
   * Returns a configuration for the {@link DBScenarioSelectionDialog}'s table.
   * <p>
   * Called during construction.
   * <p>
   * {@link DBScenarioSelectionDialog#createDefaultColumnConfigs()} is returned
   * by default.
   *
   * @return a configuration for the {@link DBScenarioSelectionDialog}'s table.
   */
  protected List<IColumnConfig<DBScenario, ?>> getScenarioSelectionTableConfig()
  {
    return DBScenarioSelectionDialog.createDefaultColumnConfigs();
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
    return new IScenarioDetailsFormatter() {};
  }

  /**
   * Returns a configuration for the {@link DBSessionSnapshotSelectionDialog}'s
   * table.
   * <p>
   * Called during construction.
   * <p>
   * {@link DBScenarioSelectionDialog#createDefaultColumnConfigs()} is returned
   * by default.
   *
   * @param aSnapshotCache
   *          A cache from which to fetch snapshots.
   *
   * @return a configuration for the {@link DBScenarioSelectionDialog}'s table.
   */
  protected List<IColumnConfig<DBSessionSnapshot, ?>> getSnapshotSelectionTableConfig(
      IDBSnapshotCache aSnapshotCache)
  {
    return DBSessionSnapshotSelectionDialog.createDefaultColumnConfigs(aSnapshotCache);
  }

  /**
   * Fetches a single simulated train from the scenario.
   * 
   * @return the DBScenarioTrain
   */
  public DBScenarioTrain getScenarioTrain()
  {
    for (DBScenarioTrain train : simulationSessionModel.getScenario().getScenarioTrains())
      if (train.isSimulated())
        return train;
    // I don't think users will see this - the SMC doesn't let you create a
    // scenario without a train
    throw new IllegalStateException("There aren't any simulated trains in this scenario"); //$NON-NLS-1$
  }

}
