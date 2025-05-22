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

import static com.sydac.gui.i18n.CommonStrings.BLANK;
import static com.sydac.simulatorcontroller.i18n.SimulatorControllerI18N.t;

import java.awt.Dimension;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Insets;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.text.MessageFormat;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Date;
import java.util.List;
import java.util.Map;
import java.util.Properties;
import java.util.Set;
import java.util.TreeMap;
import java.util.stream.Collectors;

import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.SwingUtilities;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;
import javax.swing.event.DocumentEvent;
import javax.swing.event.DocumentListener;

import com.sydac.common.dataobjects.DBHubType;
import com.sydac.common.dataobjects.DBHubTypeManager;
import com.sydac.common.dataobjects.DBPhysicalHub;
import com.sydac.common.dataobjects.DBPhysicalHubManager;
import com.sydac.common.dataobjects.DBScenario;
import com.sydac.common.dataobjects.DBSessionSnapshot;
import com.sydac.common.dataobjects.DBSimInstructor;
import com.sydac.common.dataobjects.DBSimSession;
import com.sydac.common.dataobjects.DBSimSessionHub;
import com.sydac.common.dataobjects.DBSimSessionManager;
import com.sydac.common.dataobjects.DBSimTrainee;
import com.sydac.common.dataobjects.DBSimUser;
import com.sydac.common.dataobjects.DBSimulator;
import com.sydac.common.dataobjects.DBSimulatorManager;
import com.sydac.common.dataobjects.DBTrainElement;
import com.sydac.common.log.Tracer;
import com.sydac.common.registry.Registry;
import com.sydac.content.i18n.TrackNetworksI18N;
import com.sydac.content.i18n.UnitConverters;
import com.sydac.contentutils.scenario.gui.formatter.DBSimUserFormatter;
import com.sydac.foundation.IModelListener;
import com.sydac.foundation.Model;
import com.sydac.gui.components.ComboBoxes;
import com.sydac.gui.components.DatePickerUTC;
import com.sydac.gui.components.LimitedTextField;
import com.sydac.gui.components.MessagePanel;
import com.sydac.gui.components.MessagePanel.IconType;
import com.sydac.gui.components.NonEditableTextField;
import com.sydac.gui.components.SizedButton;
import com.sydac.gui.components.SizedComboBox;
import com.sydac.gui.components.TimeField;
import com.sydac.gui.icon.EditingIcons;
import com.sydac.mmrbem.scc.plugin.sessionsetup.MmrbemSessionSetupPlugin;
import com.sydac.mmrbem.scc.plugin.sessionsetup.model.SessionSnapshotManager;
import com.sydac.mmrbem.scc.plugin.sessionsetup.model.SessionSnapshotManager.Change;
import com.sydac.simulatorcontroller.common.ErrorManager;
import com.sydac.simulatorcontroller.common.RegistryConstants;
import com.sydac.simulatorcontroller.gui.MainFrame;
import com.sydac.simulatorcontroller.gui.common.TooltipManager;
import com.sydac.simulatorcontroller.gui.icon.SessionIcons;
import com.sydac.simulatorcontroller.model.ConstantsModel;
import com.sydac.simulatorcontroller.model.SimulationModel;
import com.sydac.simulatorcontroller.session.setup.gui.dialog.TraineeSelectionDialog;
import com.sydac.simulatorcontroller.session.setup.plugin.basic.BasicSessionSetupPlugin;
import com.sydac.simulatorcontroller.session.setup.plugin.basic.simulatedsession.IHubLocationModel;
import com.sydac.simulatorcontroller.session.setup.plugin.basic.simulatedsession.training.ITrainingSessionModel;
import com.sydac.simulatorcontroller.session.setup.plugin.common.simulatedsession.LiveSessionModel;
import com.sydac.simulatorcontroller.session.setup.plugin.common.simulatedsession.training.AbstractNewSessionModel;
import com.sydac.trackdatautils.model.SegmentPosition;
import com.sydac.utility.DateTimeUtils;

public final class SimulationSessionView extends JPanel implements IModelListener
{
  private static final String EMPTY_STRING = ""; //$NON-NLS-1$

  private static final Registry REGISTRY = Registry.getInstance();

  private static final boolean NEED_COURSE_ID = REGISTRY.getBoolean(BasicSessionSetupPlugin.MandatoryFields.DOMAIN, BasicSessionSetupPlugin.MandatoryFields.COURSE_ID_KEY, false);

  private static final boolean NEED_SESSION_CODE = REGISTRY.getBoolean(BasicSessionSetupPlugin.MandatoryFields.DOMAIN, BasicSessionSetupPlugin.MandatoryFields.SESSION_CODE_KEY, false);

  private static final boolean ENABLE_REFERENCE_SESSION = REGISTRY.getBoolean(BasicSessionSetupPlugin.GUIConfig.DOMAIN, BasicSessionSetupPlugin.GUIConfig.ENABLE_REFERENCE_SESSION, false);
 
  private static final boolean ENABLE_SIMULATED_LOCATION = REGISTRY.getBoolean(BasicSessionSetupPlugin.GUIConfig.DOMAIN, MmrbemSessionSetupPlugin.ENABLE_SIMULATED_LOCATION, false);

  public static final boolean ENABLE_RESUME = Registry.getInstance().getBoolean(RegistryConstants.SCC.DOMAIN, RegistryConstants.SCC.ENABLE_RESUME, false);

  private static final String RUN_WITHOUT_SNAPSHOT = t("Run without a Snapshot"); //$NON-NLS-1$

  private static final int DRIVER_PHYSICAL_HUB_ID;
  
  private static final String SELECT_VL = t("<Please Select a Simulated Location>"); //$NON-NLS-1$
  
  private static final String SCC = "scc";//$NON-NLS-1$
  
  private static final String SIMULATED_LOCATION_FILE_PATH = "simulatedLocationFilePath";//$NON-NLS-1$
  
  private static final String SIMULATED_LOCATION_FILE = Registry.getInstance().getString(SCC, SIMULATED_LOCATION_FILE_PATH, null);
  
  private ArrayList<Double> scenarioTrainCarLengths = new ArrayList<>();

  static
  {
    Set<String> supportedSimulators = ConstantsModel.getInstance().getSupportedSimulators();
    // if (supportedSimulators.size() != 1)
    // throw new IllegalStateException("There must be exactly 1 supported
    // simulator"); //$NON-NLS-1$
    String simulatorName = supportedSimulators.iterator().next();
    DBSimulator simulator = null;
    DBSimulatorManager simManager = new DBSimulatorManager();
    simManager.load();
    for (DBSimulator sim : simManager)
    {
      sim.load();
      if (simulatorName.equals(sim.getSimulatorName()))
      {
        simulator = sim;
        break;
      }
    }

    String hubTypeName = Registry.getInstance().getString("scc", "driverhubtype"); //$NON-NLS-1$ //$NON-NLS-2$
    DBHubType hubType = null;
    DBHubTypeManager manager = new DBHubTypeManager();
    manager.load();
    for (DBHubType type : manager)
    {
      type.load();
      if (type.getHubTypeName().equals(hubTypeName))
      {
        hubType = type;
        break;
      }
    }
    final int driverHubType = hubType.getHubTypeId();

    Integer driverPhysicalHub = null;
    DBPhysicalHubManager physicalHubManager = new DBPhysicalHubManager(simulator);
    physicalHubManager.load();
    for (DBPhysicalHub hub : physicalHubManager)
    {
      if (driverHubType == hub.getHubTypeId())
      {
        driverPhysicalHub = hub.getPhysicalHubId();
        break;
      }
    }
    DRIVER_PHYSICAL_HUB_ID = driverPhysicalHub;
  }

  private final SimulationSessionController simulationSessionController;

  private final SimulationSessionModel simulationSessionModel;

  private final SimulationModel simulationModel;

  private SessionSnapshotManager sessionSnapshotManager;

  private static final Dimension MAJOR_FIELD_SIZE = new Dimension(500, 0);

  private NonEditableTextField instructorField = new NonEditableTextField(MAJOR_FIELD_SIZE);

  private JButton instructorButton = new JButton(t("Select Instructor...")); //$NON-NLS-1$

  private NonEditableTextField scenarioField = new NonEditableTextField(MAJOR_FIELD_SIZE);

  private JButton scenarioButton = new JButton(t("Select Scenario...")); //$NON-NLS-1$

  private NonEditableTextField traineeField = new NonEditableTextField(MAJOR_FIELD_SIZE);

  private JButton snapshotButton = new JButton(t("Select Snapshot...")); //$NON-NLS-1$

  private NonEditableTextField snapshotField = new NonEditableTextField(MAJOR_FIELD_SIZE);

  private JButton traineeButton = new JButton(t("Select Trainee...")); //$NON-NLS-1$

  private JTextField startPositionField = new NonEditableTextField(MAJOR_FIELD_SIZE);

  private JButton startPositionButton = new JButton(t("Select Start Position...")); //$NON-NLS-1$

  private JLabel referenceSessionLabel = new JLabel(t("Reference Session")); //$NON-NLS-1$

  private JComboBox<ReferenceSessionItem> referenceSessionCombo = new SizedComboBox<>(MAJOR_FIELD_SIZE);
  
  private JLabel simulatedLocationLabel = new JLabel(t("Simulated Location")); //$NON-NLS-1$

  private JComboBox<Object> virtualLocationCombo = new SizedComboBox<>(MAJOR_FIELD_SIZE);

  private JLabel dateLabel = new JLabel(t("Initial Date")); //$NON-NLS-1$

  private DatePickerUTC dateField = new DatePickerUTC();

  private JLabel timeLabel = new JLabel(t("Initial Time")); //$NON-NLS-1$

  private TimeField timeField = new TimeField();

  private JLabel courseIdLabel = new JLabel(t("Course ID")); //$NON-NLS-1$

  private LimitedTextField courseIdField = new LimitedTextField(20);

  private JLabel sessionCodeLabel = new JLabel(t("Session Code")); //$NON-NLS-1$

  private LimitedTextField sessionCodeField = new LimitedTextField(20);

  private MessagePanel messagePanel = new MessagePanel();

  private JButton startButton;

  private JButton clearButton;

  private Insets defaultInsets = new Insets(5, 5, 5, 5);
  
  private String simulatedLocation ="1-2";
  
  public static final String SIMULATED_LOCATION = "scc.simulatedLocation"; //$NON-NLS-1$
  
  private HubLocationFilter hubLocationFilter = new HubLocationFilter();
  
  private SegmentPosition changedSP;
  
  private double trainLength = 0.0;

  /**
   * 
   * @param controller
   * @param model
   */
  public SimulationSessionView(SimulationSessionController controller, SimulationSessionModel model)
  {
    simulationSessionModel = model;
    simulationSessionController = controller;
    simulationModel = SimulationModel.getInstance();
    sessionSnapshotManager = SessionSnapshotManager.getInstance();
  }

  /**
  * 
  */
  public void initialise()
  {
    layoutScreen();
    attachListeners();
    setEnabled(true);
  } // NewSessionView

  private void attachListeners()
  {
    simulationSessionModel.addModelListener(this, AbstractNewSessionModel.Change.INSTRUCTOR_CHANGED, true);
    simulationSessionModel.addModelListener(this, LiveSessionModel.Change.SCENARIO_CHANGED, true);
    simulationSessionModel.addModelListener(this, SimulationSessionModel.Change.SNAPSHOT_CHANGED, true);
    simulationSessionModel.addModelListener(this, LiveSessionModel.Change.DATETIME_CHANGED, true);
    simulationSessionModel.addModelListener(this, LiveSessionModel.Change.START_POSITION_CHANGED, true);
    simulationSessionModel.addModelListener(this, AbstractNewSessionModel.Change.COURSE_ID_CHANGED, true);
    simulationSessionModel.addModelListener(this, AbstractNewSessionModel.Change.SESSION_CODE_CHANGED, true);
    simulationSessionModel.addModelListener(this, ITrainingSessionModel.Change.HUB_TRAINEE_CHANGED, true);
    simulationSessionModel.addModelListener(this, IHubLocationModel.Change.HUB_LOCATION_CHANGED, true);
    simulationModel.addModelListener(this, SimulationModel.Change.IN_REPLAY_CHANGED, false);
    sessionSnapshotManager.addModelListener(sessionSnapshotManagerListener, Change.SESSION_SNAPSHOT_DATA_CHANGED, false);
    sessionSnapshotManager.addModelListener(sessionSnapshotManagerListener, Change.SESSION_DATA_CHANGED, false);
  }

  @Override
  public void addNotify()
  {
    super.addNotify();
  }

  @Override
  public void removeNotify()
  {
    super.removeNotify();
  }

  /**
   * Lays out the screen
   */
  private void layoutScreen()
  {
    setLayout(new GridBagLayout());

    scenarioButton.addActionListener(new ActionListener()
    {
      @Override
      public void actionPerformed(ActionEvent e)
      {
        simulationSessionController.selectScenario();
      }
    });

    instructorButton.addActionListener(new ActionListener()
    {
      @Override
      public void actionPerformed(ActionEvent e)
      {
        simulationSessionController.selectInstructor();
      }
    });

    snapshotButton.addActionListener(new ActionListener()
    {
      @Override
      public void actionPerformed(ActionEvent e)
      {
        simulationSessionController.selectSnapshot();
      }
    });

    referenceSessionCombo.addActionListener(new ActionListener()
    {
      @Override
      public void actionPerformed(ActionEvent e)
      {
        Object selectedItem = referenceSessionCombo.getSelectedItem();

        if (selectedItem != null && selectedItem instanceof ReferenceSessionItem)
        {
          simulationSessionController.selectReferenceSession(((ReferenceSessionItem)selectedItem).getSessionId());
        }
        else
        {
          simulationSessionController.clearReferenceSession();
        }
      }
    });
    
    virtualLocationCombo.addActionListener(event ->
    {
       Object selectedItem = virtualLocationCombo.getSelectedItem();
      
      if (selectedItem != null && selectedItem instanceof VirtualLocation)
      {
        String virtualLocationDescription = ((VirtualLocation)selectedItem).getLocation()
            .getVirtualLocationDescription();
        
        SegmentPosition sp = simulationSessionModel
            .getStartPosition(simulationSessionController.getScenarioTrain().getScenarioTrainId());
        if(sp == null)
         return;
        
        double trainLength = 0.0;
        for (DBTrainElement element : simulationSessionController.getScenarioTrain().getTrain().getElements())
        {
          trainLength = trainLength + (double)element.getCar().getLength();
        }
        double updatedOffset = sp.getOffset();
        
        SegmentPosition.Orientation orientation = sp.getOrientation();
        if (virtualLocationDescription.contains("2-1"))
        {
          if(sp.getOrientation().equals(SegmentPosition.Orientation.ALPHA_TO_BETA))
          {
            updatedOffset = updatedOffset - trainLength;
            if(updatedOffset < 0.0)
            {
              // assigne the start segment offset if less than 0
              updatedOffset = 0.0;
              
            }
          }
          else if(sp.getOrientation().equals(SegmentPosition.Orientation.BETA_TO_ALPHA))
          {
            updatedOffset = updatedOffset + trainLength;
            if(updatedOffset > sp.getSegment().getLength() )
            {
              updatedOffset = sp.getSegment().getLength();
            }
          }
          
          orientation = sp.getOrientation().opposite();
          simulatedLocation = "2-1";
        }

        changedSP = new SegmentPosition(sp.getSegment(), updatedOffset, orientation);
        simulationSessionController.selectSimulatedLocation(DRIVER_PHYSICAL_HUB_ID,
        		((VirtualLocation)selectedItem).getLocation());
      }
      else
      {
        simulationSessionController.clearSimulatedLocation(DRIVER_PHYSICAL_HUB_ID);
      }
    });

    //
    // LAYOUT
    //

    add(instructorButton, new GridBagConstraints(0, 0, 1, 1, 0.0, 0.0, GridBagConstraints.WEST, GridBagConstraints.HORIZONTAL, defaultInsets, 0, 0));
    add(instructorField, new GridBagConstraints(1, 0, 3, 1, 0.0, 0.0, GridBagConstraints.WEST, GridBagConstraints.NONE, defaultInsets, 0, 0));
    add(scenarioButton, new GridBagConstraints(0, 1, 1, 1, 0.0, 0.0, GridBagConstraints.WEST, GridBagConstraints.HORIZONTAL, defaultInsets, 0, 0));
    add(scenarioField, new GridBagConstraints(1, 1, 3, 1, 0.0, 0.0, GridBagConstraints.WEST, GridBagConstraints.NONE, defaultInsets, 0, 0));
    if (ENABLE_RESUME)
    {
      add(snapshotButton, new GridBagConstraints(0, 2, 1, 1, 0.0, 0.0, GridBagConstraints.WEST, GridBagConstraints.HORIZONTAL, defaultInsets, 0, 0));
      add(snapshotField, new GridBagConstraints(1, 2, 3, 1, 0.0, 0.0, GridBagConstraints.WEST, GridBagConstraints.NONE, defaultInsets, 0, 0));
    }
    add(traineeButton, new GridBagConstraints(0, 3, 1, 1, 0.0, 0.0, GridBagConstraints.WEST, GridBagConstraints.HORIZONTAL, defaultInsets, 0, 0));
    add(traineeField, new GridBagConstraints(1, 3, 3, 1, 0.0, 0.0, GridBagConstraints.WEST, GridBagConstraints.NONE, defaultInsets, 0, 0));
    add(startPositionButton, new GridBagConstraints(0, 4, 1, 1, 0.0, 0.0, GridBagConstraints.WEST, GridBagConstraints.HORIZONTAL, defaultInsets, 0, 0));
    add(startPositionField, new GridBagConstraints(1, 4, 3, 1, 0.0, 0.0, GridBagConstraints.WEST, GridBagConstraints.NONE, defaultInsets, 0, 0));
    if (ENABLE_REFERENCE_SESSION)
    {
      add(referenceSessionLabel, new GridBagConstraints(0, 5, 1, 1, 0.0, 0.0, GridBagConstraints.EAST, GridBagConstraints.NONE, defaultInsets, 0, 0));
      add(referenceSessionCombo, new GridBagConstraints(1, 5, 3, 1, 0.0, 0.0, GridBagConstraints.WEST, GridBagConstraints.NONE, defaultInsets, 0, 0));
    } // if
    if (ENABLE_SIMULATED_LOCATION)
    {
        add(simulatedLocationLabel, new GridBagConstraints(0, 6, 1, 1, 0.0, 0.0, GridBagConstraints.EAST, GridBagConstraints.NONE, defaultInsets, 0, 0));
        add(virtualLocationCombo, new GridBagConstraints(1, 6, 3, 1, 0.0, 0.0, GridBagConstraints.WEST, GridBagConstraints.NONE, defaultInsets, 0, 0));
    } // if

    add(dateLabel, new GridBagConstraints(0, 7, 1, 1, 0.0, 0.0, GridBagConstraints.EAST, GridBagConstraints.NONE, defaultInsets, 0, 0));
    add(dateField, new GridBagConstraints(1, 7, 1, 1, 0.0, 0.0, GridBagConstraints.WEST, GridBagConstraints.HORIZONTAL, defaultInsets, 0, 0));
    add(timeLabel, new GridBagConstraints(0, 8, 1, 1, 0.0, 0.0, GridBagConstraints.EAST, GridBagConstraints.NONE, defaultInsets, 0, 0));
    add(timeField, new GridBagConstraints(1, 8, 1, 1, 0.0, 0.0, GridBagConstraints.WEST, GridBagConstraints.NONE, defaultInsets, 0, 0));
    add(courseIdLabel, new GridBagConstraints(2, 7, 1, 1, 0.0, 0.0, GridBagConstraints.EAST, GridBagConstraints.NONE, defaultInsets, 0, 0));
    add(courseIdField, new GridBagConstraints(3, 7, 1, 1, 0.0, 0.0, GridBagConstraints.WEST, GridBagConstraints.NONE, defaultInsets, 0, 0));
    add(sessionCodeLabel, new GridBagConstraints(2, 8, 1, 1, 0.0, 0.0, GridBagConstraints.EAST, GridBagConstraints.NONE, defaultInsets, 0, 0));
    add(sessionCodeField, new GridBagConstraints(3, 8, 1, 1, 0.0, 0.0, GridBagConstraints.WEST, GridBagConstraints.NONE, defaultInsets, 0, 0));

    traineeButton.addActionListener(new ActionListener()
    {
      @Override
      public void actionPerformed(ActionEvent e)
      {
        TraineeSelectionDialog traineeDialog = new TraineeSelectionDialog(MainFrame.getInstance(), true);
        traineeDialog.setVisible(true);

        if (traineeDialog.isValidSelection() == true)
        {
          simulationSessionModel.setHubTrainee(DRIVER_PHYSICAL_HUB_ID, traineeDialog.getSelectedTrainee());
        }
      }
    });

    startPositionButton.addActionListener(new ActionListener()
    {
      @Override
      public void actionPerformed(ActionEvent e)
      {
        simulationSessionController.selectStartPosition(simulationSessionController.getScenarioTrain().getScenarioTrainId());
      }
    });

    final Dimension MAIN_BUTTON_SIZE = new Dimension(100, 35);

    startButton = new SizedButton(t("Start Session"), SessionIcons.NEW, MAIN_BUTTON_SIZE); //$NON-NLS-1$
    startButton.addActionListener(new ActionListener()
    {
      @Override
      public void actionPerformed(ActionEvent e)
      {
        if (ENABLE_SIMULATED_LOCATION)
        {
          simulationSessionModel
          .setStartPosition(simulationSessionController.getScenarioTrain().getScenarioTrainId(), changedSP);
          setSimulatedLocation();  
        }
        loadButtonPressed();
      }
    });

    final JPanel thisPanel = this;

    clearButton = new SizedButton(t("Clear All"), EditingIcons.CLEAR, MAIN_BUTTON_SIZE); //$NON-NLS-1$
    clearButton.addActionListener(new ActionListener()
    {
      @Override
      public void actionPerformed(ActionEvent e)
      {
        if (JOptionPane.showConfirmDialog(thisPanel, t("Are you sure you want to clear all setup data?"), //$NON-NLS-1$
            t("Confirm Clear All"), JOptionPane.YES_NO_OPTION) //$NON-NLS-1$
        == JOptionPane.YES_OPTION)
        {
          virtualLocationCombo.setSelectedIndex(0);
          simulationSessionController.clear();
        }
      }
    });
    // some padding.
    add(new JPanel(), new GridBagConstraints(0, 9, 4, 1, 1.0, 1.0, GridBagConstraints.WEST, GridBagConstraints.BOTH, defaultInsets, 0, 0));

    messagePanel.setMessage("Test Message"); //$NON-NLS-1$
    add(messagePanel, new GridBagConstraints(0, 10, 4, 1, 1.0, 0.0, GridBagConstraints.WEST, GridBagConstraints.HORIZONTAL, defaultInsets, 0, 0));
    add(startButton, new GridBagConstraints(0, 11, 1, 1, 0.0, 0.0, GridBagConstraints.WEST, GridBagConstraints.NONE, defaultInsets, 0, 0));
    add(clearButton, new GridBagConstraints(3, 12, 1, 1, 0.0, 0.0, GridBagConstraints.EAST, GridBagConstraints.NONE, defaultInsets, 0, 0));

    // Add the tooltips to the controls
    TooltipManager.addToolTipText(instructorButton, t("Select the instructor for this session")); //$NON-NLS-1$
    TooltipManager.addToolTipText(scenarioButton, t("Select the scenario to run for this session")); //$NON-NLS-1$
    TooltipManager.addToolTipText(snapshotButton, com.sydac.mmrbem.scc.plugin.sessionsetup.i18n.SessionSetupI18N.t("Select the resume marker to run for this session")); //$NON-NLS-1$
    TooltipManager.addToolTipText(dateField, t("Enter the initial simulated date for the session (dd-mm-yyyy)")); //$NON-NLS-1$
    TooltipManager.addToolTipText(timeField, t("Enter the initial simulated time for the session (24-hour hh:mm:ss)")); //$NON-NLS-1$
    TooltipManager.addToolTipText(courseIdField, t("Enter the course identifier for the session")); //$NON-NLS-1$
    TooltipManager.addToolTipText(sessionCodeField, t("Enter the session code for the session")); //$NON-NLS-1$
    TooltipManager.addToolTipText(startButton, t("Start a new session using the selected scenario")); //$NON-NLS-1$
    TooltipManager.addToolTipText(clearButton, t("Clear all fields on this page")); //$NON-NLS-1$

    // Update the help message for the components that produce errors
    DocumentListener helpListener = new DocumentListener()
    {
      private void update()
      {
        updateHelpMessage();
      }

      @Override
      public void removeUpdate(DocumentEvent e)
      {
        update();
      }

      @Override
      public void insertUpdate(DocumentEvent e)
      {
        update();
      }

      @Override
      public void changedUpdate(DocumentEvent e)
      {
        update();
      }
    };

    for (JTextField f : new JTextField[] { courseIdField, sessionCodeField })
    {
      f.getDocument().addDocumentListener(helpListener);
    }

    timeField.addChangeListener(new ChangeListener()
    {
      @Override
      public void stateChanged(ChangeEvent e)
      {
        updateHelpMessage();
      }
    });
  }

  // -----------------------
  // Interface Methods
  // -----------------------

  /**
   * @see com.sydac.foundation.IModelListener
   */
  @Override
  public void update(Model model, Enum<?> whatChanged)
  {
    if (model instanceof SimulationSessionModel)
    {
      if (whatChanged == AbstractNewSessionModel.Change.INSTRUCTOR_CHANGED)
      {
        DBSimInstructor dbInstructor = simulationSessionModel.getInstructor();

        if (dbInstructor == null)
        {
          instructorField.setText(EMPTY_STRING);
        }
        else
        {
          DBSimUser user = dbInstructor.getUser();

          instructorField.setText(DBSimUserFormatter.getDisplayName(user));
        }
      }
      else if (whatChanged == LiveSessionModel.Change.SCENARIO_CHANGED)
      {
        DBScenario dbScenario = simulationSessionModel.getScenario();
        scenarioField.setText(dbScenario == null ? EMPTY_STRING : dbScenario.getDescription());
        snapshotField.setText(dbScenario == null ? EMPTY_STRING : RUN_WITHOUT_SNAPSHOT);
        refreshReferenceSessionList();
        refreshSimulatedLocationList();
      }
      else if (whatChanged == SimulationSessionModel.Change.SNAPSHOT_CHANGED)
      {
        DBSessionSnapshot dbSnapshot = simulationSessionModel.getSnapshot();
        DBScenario dbScenario = simulationSessionModel.getScenario();

        if (dbSnapshot == null)
        {
          if (dbScenario != null)
          {
            snapshotField.setText(RUN_WITHOUT_SNAPSHOT);
            updateStartPosition();
          }
          else
          {
            snapshotField.setText(BLANK);
          }
        }
        else
        {
          startPositionField.setText(BLANK);
          DBSimSession session = new DBSimSession(dbSnapshot.getValue(DBSessionSnapshot.SISE_SIMSESSION_ID));
          Date d = new Date(session.getStartDateUTC().getTime() + dbSnapshot.getElapsedTimeMillis());

          snapshotField.setText(t("Snapshot of Scenario \"{0}\" taken on {1} at {2}", //$NON-NLS-1$
              dbScenario.getDescription(), DateTimeUtils.getShortDateString(d), DateTimeUtils.getShortTimeString(d)));
        }
        refreshSimulatedLocationList();
      }
      else if (whatChanged == LiveSessionModel.Change.DATETIME_CHANGED)
      {
        Date dateTime = simulationSessionModel.getDateTime();

        if (dateTime != null)
        {
          dateField.setDateUTC(dateTime);
          timeField.setText(DateTimeUtils.getShortTimeString(dateTime));
        }
        else
        {
          dateField.clearDate();
          timeField.setText(EMPTY_STRING);
        }
      }
      else if (whatChanged == AbstractNewSessionModel.Change.COURSE_ID_CHANGED)
      {
        String courseId = simulationSessionModel.getCourseId();

        if (courseId == null)
        {
          courseIdField.setText(EMPTY_STRING);
        }
        else
        {
          courseIdField.setText(courseId);
        }
      }
      else if (whatChanged == AbstractNewSessionModel.Change.SESSION_CODE_CHANGED)
      {
        String sessionCode = simulationSessionModel.getSessionCode();

        if (sessionCode == null)
        {
          sessionCodeField.setText(EMPTY_STRING);
        }
        else
        {
          sessionCodeField.setText(sessionCode);
        }
      }
      else if (whatChanged == ITrainingSessionModel.Change.HUB_TRAINEE_CHANGED)
      {
        DBSimTrainee trainee = simulationSessionModel.getHubTrainee(DRIVER_PHYSICAL_HUB_ID);

        if (trainee != null)
        {
          DBSimUser user = trainee.getUser();
          traineeField.setText(DBSimUserFormatter.getDisplayName(user));
        }
        else
        {
          traineeField.setText(EMPTY_STRING);
        }
      }

      else if (whatChanged == LiveSessionModel.Change.START_POSITION_CHANGED || whatChanged == IHubLocationModel.Change.HUB_LOCATION_CHANGED)
      {
    	  refreshSimulatedLocationList();
        updateStartPosition();
      }
    }
    else if (model instanceof SimulationModel)
    {
      if (!simulationModel.isReplay())
      {
        simulationSessionController.clear();
      }
    }

    refreshControlEnabling();
  }
  
  private void setSimulatedLocation()
  {
    if (null != SIMULATED_LOCATION_FILE)
    {
      try
      {

        FileInputStream in = new FileInputStream(SIMULATED_LOCATION_FILE);
        Properties props = new Properties();
        props.load(in);
        in.close();

        FileOutputStream out = new FileOutputStream(SIMULATED_LOCATION_FILE);
        props.setProperty(SIMULATED_LOCATION, simulatedLocation);
        props.store(out, null);
        out.close();
      }
      catch (IOException ex)
      {
        Tracer.getInstance().error("Error while reading file :- " + SIMULATED_LOCATION_FILE);
        Tracer.getInstance().error(ex);
      }
    }
  }

  private void updateStartPosition()
  {
    startPositionField.setText(EMPTY_STRING);

    if (simulationSessionModel.getScenario() != null)
    {
      // assuming we always have a train....
      SegmentPosition pos = simulationSessionModel.getStartPosition(simulationSessionController.getScenarioTrain().getScenarioTrainId());

      if (pos != null)
      {
        startPositionField.setText(MessageFormat.format(t("{0} at {1}{2}"), //$NON-NLS-1$
            TrackNetworksI18N.getText(pos.getSegment().getName()), UnitConverters.OFFSET_CONV.convertToFormatted(pos.getOffset()), UnitConverters.OFFSET_CONV.getLabel()));
      }
    }
  }

  private IModelListener sessionSnapshotManagerListener = (Model model, Enum<?> whatChanged) ->
  {
    if (whatChanged == Change.SESSION_SNAPSHOT_DATA_CHANGED)
    {
      onSnapshotListChange();
      refreshSimulatedLocationList();
    }
    else if (whatChanged == Change.SESSION_DATA_CHANGED)
    {
      refreshReferenceSessionList();
    }
  };

  private void onSnapshotListChange()
  {
    if (null != simulationSessionModel)
    {
      DBScenario scenario = simulationSessionModel.getScenario();
      if (null != scenario)
      {
        if (sessionSnapshotManager.hasSessionSnapshots(scenario))
        {
          SwingUtilities.invokeLater(() -> snapshotButton.setEnabled(true));
        }
      }
    }
  }

  private void refreshReferenceSessionList()
  {
    DBScenario dbScenario = simulationSessionModel.getScenario();
    referenceSessionCombo.removeAllItems();
    if (dbScenario != null)
    {
      DBSimSessionManager sessions = new DBSimSessionManager(dbScenario);
      sessions.load();
      Map<Integer, DBSimSession> filteredSessions = new TreeMap<>();
      for (DBSimSession session : sessions)
      {
        if (session.isReplay() && !filteredSessions.containsKey(session.getSessionId()))
        {
          filteredSessions.put(session.getSessionId(), session);
        }
      }
      List<ReferenceSessionItem> items = new ArrayList<>(filteredSessions.size());
      for (DBSimSession session : filteredSessions.values())
      {
        DBSimSessionHub sessionHub = sessionSnapshotManager.getSession(session.getSessionId());
        try
        {
          int sessionId = session.getSessionId();
          Date startDate = session.getStartDateUTC();
          String sessionCode = session.getSessionCode();
          String instructor = session.getInstructor().getUser().getDisplayString();
          String trainee = null;
          if (sessionHub.getDriver() != null)
          {
            trainee = sessionHub.getDriver().getUser().getDisplayString();
          }
          ReferenceSessionItem item = new ReferenceSessionItem(sessionId, startDate, trainee, instructor, sessionCode);
          items.add(item);
        }
        catch (Exception e)
        {
          Tracer.getInstance().error(e);
        }
      }
      Collections.sort(items);
      referenceSessionCombo.addItem(new ReferenceSessionItem());
      for (ReferenceSessionItem item : items)
      {
        referenceSessionCombo.addItem(item);
      }
    }
  }
  
  private void refreshSimulatedLocationList()
  {
    DBScenario dbScenario = simulationSessionModel.getScenario();
    if (dbScenario != null)
    {
      List<VirtualLocation> sortedVLs = dbScenario.getVirtualLocations().stream()
          .filter(hubLocationFilter::allowSelection).map(VirtualLocation::new).sorted()
          .collect(Collectors.toList());
      if (!ENABLE_SIMULATED_LOCATION)
      {
        simulationSessionController.selectSimulatedLocation(DRIVER_PHYSICAL_HUB_ID,
            sortedVLs.get(0).getLocation());
      }
      else
      {
        // auto-fill location if only one is configured
        boolean hasOnlyOneVL = sortedVLs.size() == 1;
        if (hasOnlyOneVL)
        {
          ComboBoxes.atomicPopulate(virtualLocationCombo, sortedVLs, sortedVLs.get(0));
          virtualLocationCombo.setSelectedIndex(0);
        }
        else
        {
          ComboBoxes.atomicPopulate(virtualLocationCombo, SELECT_VL, sortedVLs, SELECT_VL);
        }
      }
    }
  }

  private void refreshControlEnabling()
  {
    setEnabled(isEnabled());
  }

  /**
   * @see javax.swing.JPanel
   */
  @Override
  public void setEnabled(boolean enabled)
  {
    super.setEnabled(enabled);

    boolean scenarioSelected = simulationSessionModel.getScenario() != null;
    boolean snapshotSelected = simulationSessionModel.getSnapshot() != null;
    boolean hasSnapshot = scenarioSelected && sessionSnapshotManager.hasSessionSnapshots(simulationSessionModel.getScenario());

    instructorButton.setEnabled(enabled);
    scenarioButton.setEnabled(enabled);
    snapshotButton.setEnabled(enabled && hasSnapshot);
    traineeButton.setEnabled(enabled);
    startPositionButton.setEnabled(enabled && scenarioSelected && !snapshotSelected);

    referenceSessionLabel.setEnabled(enabled && scenarioSelected);
    referenceSessionCombo.setEnabled(enabled && scenarioSelected && referenceSessionCombo.getItemCount() > 1);
    
    simulatedLocationLabel.setEnabled(enabled && scenarioSelected);
    virtualLocationCombo.setEnabled(enabled && scenarioSelected && virtualLocationCombo.getItemCount() > 1);

    dateLabel.setEnabled(enabled && scenarioSelected);
    dateField.setEnabled(enabled && scenarioSelected && !snapshotSelected);
    timeLabel.setEnabled(enabled && scenarioSelected);
    timeField.setEnabled(enabled && scenarioSelected && !snapshotSelected);

    courseIdLabel.setEnabled(enabled && scenarioSelected);
    courseIdField.setEnabled(enabled && scenarioSelected);
    sessionCodeLabel.setEnabled(enabled && scenarioSelected);
    sessionCodeField.setEnabled(enabled && scenarioSelected);

    startButton.setEnabled(enabled && scenarioSelected && simulationSessionModel.getInstructor() != null && !simulationSessionModel.getHubTrainees().isEmpty() 
            && !simulationSessionModel.getHubLocations().isEmpty());
    clearButton.setEnabled(enabled);

    updateHelpMessage();
  }

  private void updateHelpMessage()
  {
    if (simulationSessionModel.getInstructor() == null)
    {
      messagePanel.setMessage(t("Please select yourself as the Instructor.")); //$NON-NLS-1$
    }
    else if (simulationSessionModel.getScenario() == null)
    {
      messagePanel.setMessage(t("Please select a Scenario.")); //$NON-NLS-1$
    }
    else if (dateField.getDateUTC() == null)
    {
      messagePanel.setMessage(t("Please enter a valid date."), IconType.ERROR); //$NON-NLS-1$
    }
    else if (DateTimeUtils.parseTime(timeField.getText()) == null)
    {
      messagePanel.setMessage(t("Please enter a valid time."), IconType.ERROR); //$NON-NLS-1$
    }
    else if (NEED_COURSE_ID && courseIdField.getText().equals(EMPTY_STRING))
    {
      messagePanel.setMessage(t("Please enter a Course ID.")); //$NON-NLS-1$
    }
    else if (NEED_SESSION_CODE && sessionCodeField.getText().equals(EMPTY_STRING))
    {
      messagePanel.setMessage(t("Please enter a Session Code.")); //$NON-NLS-1$
    }

    else
    {
      Map<Integer, DBSimTrainee> hubTrainees = simulationSessionModel.getHubTrainees();

      if (hubTrainees.size() == 0)
      {
        messagePanel.setMessage(t("Please select at least one Trainee.")); //$NON-NLS-1$
      }
      else
      {
        if (isEnabled())
        {
          messagePanel.setMessage(t("Select Start Session to begin the training session."), IconType.OK); //$NON-NLS-1$
        }
        else
        {
          messagePanel.removeMessage();
        }
      }
    }
  }

  /**
   * Called when the load scenario button is pressed.
   */
  private void loadButtonPressed()
  {
    Date date = dateField.getDateUTC();
    // parse methods assume UTC time zone, so no conversion required.
    Date time = DateTimeUtils.parseTime(timeField.getText());

    if (date == null)
    {
      ErrorManager.getInstance().showError(t("Invalid Date"), //$NON-NLS-1$
          t("Please enter a valid date.")); //$NON-NLS-1$
      dateField.requestFocus();
    }
    else if (time == null)
    {
      ErrorManager.getInstance().showError(t("Invalid Time"), //$NON-NLS-1$
          t("Please enter a valid time.")); //$NON-NLS-1$
      timeField.requestFocus();
    }
    else if (NEED_COURSE_ID && courseIdField.getText().equals(EMPTY_STRING))
    {
      ErrorManager.getInstance().showError(t("Course ID Missing"), //$NON-NLS-1$
          t("Please enter a Course ID.")); //$NON-NLS-1$
      courseIdField.requestFocus();
    }
    else if (NEED_SESSION_CODE && sessionCodeField.getText().equals(EMPTY_STRING))
    {
      ErrorManager.getInstance().showError(t("Session Code Missing"), //$NON-NLS-1$
          t("Please enter a Session Code.")); //$NON-NLS-1$
      sessionCodeField.requestFocus();
    }
    else
    {
      simulationSessionController.setDateTime(new Date(date.getTime() + time.getTime()));
      simulationSessionController.setTextItems(courseIdField.getText(), sessionCodeField.getText());
      simulationSessionController.loadScenario();
    }
  }
}