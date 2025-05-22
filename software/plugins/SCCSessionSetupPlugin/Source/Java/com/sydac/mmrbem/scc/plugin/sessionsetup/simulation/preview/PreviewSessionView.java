/* ==================================================================
 *
 *  (C) Copyright 2010 Sydac Pty Ltd., all rights reserved.
 *  This is unpublished proprietary source code of Sydac.
 *  The copyright notice above does not evidence any actual
 *  or intended publication of such source code.
 *
 * ==================================================================
 */
package com.sydac.mmrbem.scc.plugin.sessionsetup.simulation.preview;

import static com.sydac.simulatorcontroller.i18n.SimulatorControllerI18N.t;

import java.awt.Dimension;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Insets;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.text.MessageFormat;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Date;
import java.util.List;
import java.util.Set;
import java.util.stream.Collectors;

import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;

import com.sydac.common.dataobjects.DBHubModeTypeAssoc;
import com.sydac.common.dataobjects.DBHubModeTypeAssocManager;
import com.sydac.common.dataobjects.DBHubType;
import com.sydac.common.dataobjects.DBHubTypeManager;
import com.sydac.common.dataobjects.DBPhysicalHub;
import com.sydac.common.dataobjects.DBPhysicalHubManager;
import com.sydac.common.dataobjects.DBScenario;
import com.sydac.common.dataobjects.DBSimulator;
import com.sydac.common.dataobjects.DBSimulatorManager;
import com.sydac.common.dataobjects.DBTrainElement;
import com.sydac.common.dataobjects.DBVirtualLocation;
import com.sydac.common.dataobjects.DBVirtualLocationManager;
import com.sydac.common.registry.Registry;
import com.sydac.content.i18n.TrackNetworksI18N;
import com.sydac.content.i18n.UnitConverters;
import com.sydac.foundation.IModelListener;
import com.sydac.foundation.Model;
import com.sydac.gui.components.ComboBoxes;
import com.sydac.gui.components.DatePickerUTC;
import com.sydac.gui.components.MessagePanel;
import com.sydac.gui.components.MessagePanel.IconType;
import com.sydac.gui.components.NonEditableTextField;
import com.sydac.gui.components.SizedButton;
import com.sydac.gui.components.SizedComboBox;
import com.sydac.gui.components.TimeField;
import com.sydac.gui.icon.EditingIcons;
import com.sydac.mmrbem.scc.plugin.sessionsetup.MmrbemSessionSetupPlugin;
import com.sydac.mmrbem.scc.plugin.sessionsetup.simulation.HubLocationFilter;
import com.sydac.mmrbem.scc.plugin.sessionsetup.simulation.VirtualLocation;
import com.sydac.simulatorcontroller.common.ErrorManager;
import com.sydac.simulatorcontroller.gui.common.TooltipManager;
import com.sydac.simulatorcontroller.gui.icon.SessionIcons;
import com.sydac.simulatorcontroller.model.ConstantsModel;
import com.sydac.simulatorcontroller.model.SimulationModel;
import com.sydac.simulatorcontroller.session.setup.plugin.basic.BasicSessionSetupPlugin;
import com.sydac.simulatorcontroller.session.setup.plugin.basic.simulatedsession.IHubLocationModel;
import com.sydac.simulatorcontroller.session.setup.plugin.basic.simulatedsession.preview.PreviewSessionModel;
import com.sydac.simulatorcontroller.session.setup.plugin.common.simulatedsession.LiveSessionModel;
import com.sydac.trackdatautils.model.SegmentPosition;
import com.sydac.utility.DateTimeUtils;

public final class PreviewSessionView
  extends JPanel
  implements IModelListener
{
  private static final String EMPTY_STRING = ""; //$NON-NLS-1$
  
  private static final Registry REGISTRY = Registry.getInstance();
  
  private static final boolean ENABLE_SIMULATED_LOCATION = REGISTRY.getBoolean(BasicSessionSetupPlugin.GUIConfig.DOMAIN, MmrbemSessionSetupPlugin.ENABLE_SIMULATED_LOCATION, false);
  
  private PreviewSessionController previewSessionController;
  
  private PreviewSessionModel previewSessionModel;
  
  private SimulationModel simulationModel;

  private static final Dimension MAJOR_FIELD_SIZE = new Dimension(500, 0);

  private NonEditableTextField scenarioField = new NonEditableTextField(MAJOR_FIELD_SIZE);
  private JButton scenarioButton = new JButton(t("Select Scenario...")); //$NON-NLS-1$
  
  private JTextField startPositionField = new NonEditableTextField(MAJOR_FIELD_SIZE);
  private JButton startPositionButton = new JButton(t("Select Start Position...")); //$NON-NLS-1$

  private JLabel dateLabel = new JLabel(t("Initial Date")); //$NON-NLS-1$
  private DatePickerUTC dateField = new DatePickerUTC();
  private JLabel timeLabel = new JLabel(t("Initial Time")); //$NON-NLS-1$
  private TimeField timeField = new TimeField();

  private MessagePanel messagePanel = new MessagePanel();
  private JButton startButton;
  private JButton clearButton;

  private Insets defaultInsets = new Insets(5, 5, 5, 5);
  
  private HubLocationFilter hubLocationFilter = new HubLocationFilter();
  
  private JLabel simulatedLocationLabel = new JLabel(t("Simulated Location")); //$NON-NLS-1$

  private JComboBox<Object> virtualLocationCombo = new SizedComboBox<>(MAJOR_FIELD_SIZE);
  
  private static final String SELECT_VL = t("<Please Select a Simulated Location>"); //$NON-NLS-1$

  // This probably belongs in a model, but too bad
  private static final int driverHubMode;

  private static final int driverPhysicalHubID;
  
  private SegmentPosition changedSP;
  static
  {
    Set<String> supportedSimulators = ConstantsModel.getInstance().getSupportedSimulators();
    // if (supportedSimulators.size() != 1)
    //throw new IllegalStateException("There must be exactly 1 supported simulator"); //$NON-NLS-1$
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

    DBHubModeTypeAssocManager modes = new DBHubModeTypeAssocManager();
    Integer mode = null;
    modes.load();
    for (DBHubModeTypeAssoc assoc : modes)
    {
      if (assoc.getHubTypeId() == driverHubType)
      {
        mode = assoc.getHubModeId();
        break;
      }
    }
    driverHubMode = mode;

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
    driverPhysicalHubID = driverPhysicalHub;
  }

  public PreviewSessionView(PreviewSessionController controller, PreviewSessionModel model)
  {
    previewSessionModel = model;
    previewSessionController = controller;

    simulationModel = SimulationModel.getInstance();

    layoutScreen();

    // Add the listeners to the models
    // FIXME: Don't pass partially constructed objects around, see #REVIEW 3061
    previewSessionModel.addModelListener(this, LiveSessionModel.Change.SCENARIO_CHANGED, true);
    previewSessionModel.addModelListener(this, LiveSessionModel.Change.DATETIME_CHANGED, true);
    previewSessionModel.addModelListener(this, LiveSessionModel.Change.START_POSITION_CHANGED, true);
    previewSessionModel.addModelListener(this, IHubLocationModel.Change.HUB_LOCATION_CHANGED, true);   

    simulationModel.addModelListener(this, SimulationModel.Change.IN_REPLAY_CHANGED, false);

    setEnabled(true);
  } // NewSessionView


  /**
   * Lays out the screen
   */
  private void layoutScreen()
  {
    setLayout(new GridBagLayout());

    scenarioButton.addActionListener( new ActionListener()
    {
      @Override
      public void actionPerformed( ActionEvent e )
      {
        // It is important to first clearHubLocations() and then selectScenario()
        // otherwise the data in the model will get flushed, and thus losing attributes from the selected scenario.
        previewSessionModel.clearHubLocations();
        previewSessionController.selectScenario();
      } // actionPerformed
    });
    
    virtualLocationCombo.addActionListener(event ->
    {
       Object selectedItem = virtualLocationCombo.getSelectedItem();
       VirtualLocation vertualLocationFor12 = (VirtualLocation)virtualLocationCombo.getItemAt(1);
            
      if (selectedItem != null && selectedItem instanceof VirtualLocation)
      {
        String virtualLocationDescription = ((VirtualLocation)selectedItem).getLocation()
            .getVirtualLocationDescription();
        SegmentPosition sp = previewSessionModel
            .getStartPosition(previewSessionController.getScenarioTrain().getScenarioTrainId());

        
        double trainLength = 0.0;
        for (DBTrainElement element : previewSessionController.getScenarioTrain().getTrain().getElements())
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
        }
        changedSP = new SegmentPosition(sp.getSegment(), updatedOffset, orientation);
        previewSessionModel.setHubLocation(driverPhysicalHubID,
            vertualLocationFor12.getLocation());
      }
      else
      {
        previewSessionModel.clearHubLocation(driverPhysicalHubID);
      }
    });

    //
    // LAYOUT
    //

    add(scenarioButton,   new GridBagConstraints(0, 0, 1, 1, 0.0, 0.0, GridBagConstraints.WEST, GridBagConstraints.HORIZONTAL, defaultInsets, 0, 0));
    add(scenarioField,    new GridBagConstraints(1, 0, 3, 1, 0.0, 0.0, GridBagConstraints.WEST, GridBagConstraints.NONE, defaultInsets, 0, 0));
    
    add(startPositionButton, new GridBagConstraints(0, 1, 1, 1, 0.0, 0.0, GridBagConstraints.WEST, GridBagConstraints.HORIZONTAL, defaultInsets, 0, 0));
    add(startPositionField, new GridBagConstraints(1, 1, 3, 1, 0.0, 0.0, GridBagConstraints.WEST, GridBagConstraints.NONE, defaultInsets, 0, 0));
    
    if (ENABLE_SIMULATED_LOCATION)
    {
      add(simulatedLocationLabel, new GridBagConstraints(0, 2, 1, 1, 0.0, 0.0, GridBagConstraints.EAST, GridBagConstraints.NONE, defaultInsets, 0, 0));
      add(virtualLocationCombo, new GridBagConstraints(1, 2, 3, 1, 0.0, 0.0, GridBagConstraints.WEST, GridBagConstraints.NONE, defaultInsets, 0, 0));
    } // if

    add(dateLabel,        new GridBagConstraints(0, 3, 1, 1, 0.0, 0.0, GridBagConstraints.EAST, GridBagConstraints.NONE, defaultInsets, 0, 0));
    add(dateField,        new GridBagConstraints(1, 3, 1, 1, 0.0, 0.0, GridBagConstraints.WEST, GridBagConstraints.HORIZONTAL, defaultInsets, 10, 0));
    add(timeLabel,        new GridBagConstraints(0, 4, 1, 1, 0.0, 0.0, GridBagConstraints.EAST, GridBagConstraints.NONE, defaultInsets, 0, 0));
    add(timeField,        new GridBagConstraints(1, 4, 1, 1, 0.0, 0.0, GridBagConstraints.WEST, GridBagConstraints.NONE, defaultInsets, 0, 0));

      
    add(new JPanel(), new GridBagConstraints(0, 5, 4, 1, 1.0, 1.0, GridBagConstraints.WEST, GridBagConstraints.BOTH, defaultInsets, 0, 0));
    final Dimension MAIN_BUTTON_SIZE = new Dimension(100, 35);
    startPositionButton.addActionListener(new ActionListener()
    {
      @Override
      public void actionPerformed(ActionEvent e)
      {
        previewSessionController.selectStartPosition(previewSessionController.getScenarioTrain().getScenarioTrainId());
      } // actionPerformed
    });

    startButton = new SizedButton(t("Start Session"), SessionIcons.NEW, MAIN_BUTTON_SIZE); //$NON-NLS-1$
    startButton.addActionListener( new ActionListener()
    {
      @Override
      public void actionPerformed( ActionEvent e )
      {
        if (ENABLE_SIMULATED_LOCATION)
        {
          previewSessionModel
              .setStartPosition(previewSessionController.getScenarioTrain().getScenarioTrainId(), changedSP);
        }

        loadButtonPressed();
      } // actionPerformed
    });

    final JPanel thisPanel = this;

    clearButton = new SizedButton(t("Clear All"), EditingIcons.CLEAR, MAIN_BUTTON_SIZE); //$NON-NLS-1$
    clearButton.addActionListener( new ActionListener()
    {
      @Override
      public void actionPerformed( ActionEvent e )
      {
        if (JOptionPane.showConfirmDialog(thisPanel,
            t("Are you sure you want to clear all setup data?"),  //$NON-NLS-1$
            t("Confirm Clear All"), JOptionPane.YES_NO_OPTION) //$NON-NLS-1$
            == JOptionPane.YES_OPTION)
        {
          virtualLocationCombo.setSelectedIndex(0);
          previewSessionController.clear();
        } // if
      } // actionPerformed
    });

    messagePanel.setMessage(t("Test Message")); //$NON-NLS-1$

    add(messagePanel, new GridBagConstraints(0, 7, 4, 1, 1.0, 0.0, GridBagConstraints.WEST, GridBagConstraints.HORIZONTAL, defaultInsets, 0, 0));
    add(startButton,  new GridBagConstraints(0, 8, 1, 1, 0.0, 0.0, GridBagConstraints.WEST, GridBagConstraints.NONE, defaultInsets, 0, 0));
    add(clearButton,  new GridBagConstraints(3, 8, 1, 1, 0.0, 0.0, GridBagConstraints.EAST, GridBagConstraints.NONE, defaultInsets, 0, 0));

    // Add the tooltips to the controls
    TooltipManager.addToolTipText(scenarioButton, t("Select the scenario to run for this session")); //$NON-NLS-1$
    TooltipManager.addToolTipText(dateField,      t("Enter the initial simulated date for the session (dd-mm-yyyy)")); //$NON-NLS-1$
    TooltipManager.addToolTipText(timeField,      t("Enter the initial simulated time for the session (24-hour hh:mm:ss)")); //$NON-NLS-1$
    TooltipManager.addToolTipText(startButton,    t("Start a new session using the selected scenario")); //$NON-NLS-1$
    TooltipManager.addToolTipText(clearButton,    t("Clear all fields on this page")); //$NON-NLS-1$

    timeField.addChangeListener(new ChangeListener()
    {
      @Override
      public void stateChanged(ChangeEvent e)
      {
        updateHelpMessage();
      }
    });
  } // layoutScreen


  // -----------------------
  // Interface Methods
  // -----------------------

  /**
   * @see com.sydac.foundation.IModelListener
   */
  @Override
  public void update( Model model, Enum<?> whatChanged )
  {
    if ( model instanceof PreviewSessionModel )
    {
      if ( whatChanged == LiveSessionModel.Change.SCENARIO_CHANGED )
      {
        DBScenario dbScenario = previewSessionModel.getScenario();
        scenarioField.setText(dbScenario == null ? EMPTY_STRING : dbScenario.getDescription() );
        
        refreshSimulatedLocationList();
      }
      else if ( whatChanged == LiveSessionModel.Change.DATETIME_CHANGED )
      {
        Date dateTime = previewSessionModel.getDateTime();

        if ( dateTime != null )
        {
          dateField.setDateUTC(dateTime);
          timeField.setText( DateTimeUtils.getShortTimeString( dateTime ) );
        } // if
        else
        {
          dateField.clearDate();
          timeField.setText(EMPTY_STRING);
        } // else
      } // else
      else if (whatChanged == LiveSessionModel.Change.START_POSITION_CHANGED || whatChanged == IHubLocationModel.Change.HUB_LOCATION_CHANGED)
      {
        updateStartPosition();
      } 
    } // if
    else if ( model instanceof SimulationModel )
    {
      if (!simulationModel.isReplay())
      {
        previewSessionController.clear();
      } // if
    } // else if

    refreshControlEnabling();
  }//update
  
  private void refreshSimulatedLocationList()
  {
    DBScenario dbScenario = previewSessionModel.getScenario();
    if (dbScenario != null)
    {
      List<VirtualLocation> sortedVLs = dbScenario.getVirtualLocations().stream()
          .filter(hubLocationFilter::allowSelection).map(VirtualLocation::new).sorted()
          .collect(Collectors.toList());
      if(!ENABLE_SIMULATED_LOCATION)
      {
        previewSessionModel.setHubLocation(driverPhysicalHubID, sortedVLs.get(0).getLocation());
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
    
  private void updateStartPosition()
  {
    startPositionField.setText(EMPTY_STRING);

    if (previewSessionModel.getScenario() != null)
    {
      // FIXME assuming we always have a train....
      SegmentPosition pos = previewSessionModel.getStartPosition(previewSessionController.getScenarioTrain().getScenarioTrainId());

      if (pos != null)
      {
        startPositionField.setText(MessageFormat.format(t("{0} at {1}{2}"), //$NON-NLS-1$
            TrackNetworksI18N.getText(pos.getSegment().getName()), UnitConverters.OFFSET_CONV.convertToFormatted(pos.getOffset()), UnitConverters.OFFSET_CONV.getLabel()));
      } // if
    }
  } // updateStartPosition


  private void refreshControlEnabling()
  {
    setEnabled(isEnabled());
  } // refreshControlEnabling

  /**
   * @see javax.swing.JPanel
   */
  @Override
  public void setEnabled( boolean enabled )
  {
    super.setEnabled( enabled );

    scenarioButton.setEnabled( enabled );
    scenarioField.setEnabled( enabled );

    boolean scenarioSelected = previewSessionModel.getScenario() != null;
    
    startPositionField.setEnabled(enabled && scenarioSelected);
    startPositionButton.setEnabled(enabled && scenarioSelected);

    dateLabel.setEnabled(enabled && scenarioSelected);
    dateField.setEnabled(enabled && scenarioSelected);
    timeLabel.setEnabled(enabled && scenarioSelected);
    timeField.setEnabled(enabled && scenarioSelected);
   
    simulatedLocationLabel.setEnabled(enabled && scenarioSelected);
    virtualLocationCombo.setEnabled(enabled && scenarioSelected && virtualLocationCombo.getItemCount() > 1);

    startButton.setEnabled(enabled && scenarioSelected);
    clearButton.setEnabled(enabled);

    messagePanel.setEnabled(enabled);
    updateHelpMessage();
  } // setEnabled

  private void updateHelpMessage()
  {
    if (previewSessionModel.getScenario() == null)
    {
      messagePanel.setMessage(t("Please select a Scenario.")); //$NON-NLS-1$
    } // else if
    else if (dateField.getDateUTC() == null)
    {
      messagePanel.setMessage(t("Please enter a valid date."), IconType.ERROR); //$NON-NLS-1$
    } // if
    else if (DateTimeUtils.parseTime(timeField.getText()) == null)
    {
      messagePanel.setMessage(t("Please enter a valid time."), IconType.ERROR); //$NON-NLS-1$
    } // else if
    else
    {
      if (isEnabled())
      {
        messagePanel.setMessage(t("Select Start Session to begin the training session."), IconType.OK); //$NON-NLS-1$
      } // if
      else
      {
        messagePanel.removeMessage();
      } // if
    } // else
  } // updateHelpMessage

  /**
   * Called when the load scenario button is pressed.
   */
  private void loadButtonPressed()
  {
    //FIXME Ideally there should be an option to select the location on the UI.
    //In COFMOW the location is assumed as the lead locomotive.
    // Assign the trainee to the virtual location (of lead locomotive)
    DBVirtualLocationManager locations = new DBVirtualLocationManager(previewSessionModel.getScenario());    
    locations.load();
    ArrayList<DBVirtualLocation> dbVirtualLocations = new ArrayList<>();
    for (DBVirtualLocation l : locations)
    {
      if (l.getHubModeId() == driverHubMode)
      {
        dbVirtualLocations.add(l);
      }
    }
    //finding out the lead locomotive
    Collections.sort(dbVirtualLocations, (DBVirtualLocation l1, DBVirtualLocation l2) ->
    {
      return l1.getVehicleIndex().compareTo(l2.getVehicleIndex());
    });   

    previewSessionModel.setHubLocation(driverPhysicalHubID, dbVirtualLocations.get(0));    
    
    Date date = dateField.getDateUTC();
    // parse methods assume UTC time zone, so no conversion required.
    Date time = DateTimeUtils.parseTime(timeField.getText());

    if ( date == null )
    {
      ErrorManager.getInstance().showError( t("Invalid Date"),  //$NON-NLS-1$
                                            t("Please enter a valid date.") ); //$NON-NLS-1$
      dateField.requestFocus();
    } // if
    else if ( time == null )
    {
      ErrorManager.getInstance().showError( t("Invalid Time"),  //$NON-NLS-1$
                                            t("Please enter a valid time.") ); //$NON-NLS-1$
      timeField.requestFocus();
    } // else if
    else
    {
      previewSessionController.setDateTime(new Date(date.getTime() + time.getTime()));
      previewSessionController.loadScenario();
    } // else
  } // loadButtonPressed

} // class PreviewSessionView

//-- EOF
