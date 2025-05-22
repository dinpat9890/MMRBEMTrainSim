/**
 * ==================================================================
 * 
 * (C) Copyright 2015 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.scc.plugin.sessionsetup;

import java.io.IOException;
import java.util.Collection;
import java.util.Collections;
import java.util.List;

import javax.swing.JPanel;

import com.sydac.common.dataobjects.DBScenario;
import com.sydac.common.log.Tracer;
import com.sydac.common.registry.Registry;
import com.sydac.common.sessiondata.BaseSessionData;
import com.sydac.mmrbem.scc.plugin.sessionsetup.gui.SessionSetupTabPanel;
import com.sydac.mmrbem.scc.plugin.sessionsetup.replay.ReplaySessionController;
import com.sydac.mmrbem.scc.plugin.sessionsetup.replay.ReplaySessionModel;
import com.sydac.mmrbem.scc.plugin.sessionsetup.replay.ReplaySessionView;
import com.sydac.mmrbem.scc.plugin.sessionsetup.simulation.SimulationSessionController;
import com.sydac.mmrbem.scc.plugin.sessionsetup.simulation.SimulationSessionModel;
import com.sydac.mmrbem.scc.plugin.sessionsetup.simulation.SimulationSessionView;

import com.sydac.mmrbem.scc.plugin.sessionsetup.simulation.preview.PreviewSessionController;
import com.sydac.mmrbem.scc.plugin.sessionsetup.simulation.preview.PreviewSessionView;
import com.sydac.peer.application.PeerApplication;
import com.sydac.simcomms.Gateway;
import com.sydac.simcomms.GenericData;
import com.sydac.simcomms.SessionData;
import com.sydac.simcomms.framework.ScenarioProcessing;
import com.sydac.simcomms.framework.Unit;
import com.sydac.simcomms.framework.UnitCreator;
import com.sydac.simcomms.system.CSystem;
import com.sydac.simcomms.system.State;
import com.sydac.simulatorcontroller.common.RegistryConstants;
import com.sydac.simulatorcontroller.gui.MainFrame;
import com.sydac.simulatorcontroller.model.ScenarioManager;
import com.sydac.simulatorcontroller.plugin.ISessionSetupPlugin;
import com.sydac.simulatorcontroller.session.request.SessionRequester;
import com.sydac.simulatorcontroller.session.setup.gui.container.SessionSetupNavigationPage;
import com.sydac.simulatorcontroller.session.setup.plugin.basic.BasicSessionSetupPlugin;
import com.sydac.simulatorcontroller.session.setup.plugin.basic.simulatedsession.preview.PreviewSessionModel;

/**
 * A class that provides implementation for the {@link ISessionSetupPlugin}
 * interface. {@link MmrbemSessionSetupPlugin} provides a GUI for session setup
 * and functionality for starting new and resume sessions for COFMOW sims.
 * 
 */
public class MmrbemSessionSetupPlugin extends BasicSessionSetupPlugin
{
  public static final String ENABLE_IDEAL_RUN_KEY = "enableidealrun"; //$NON-NLS-1$

  private static final String ENABLE_AUTO_TESTING = "enableautotesting"; //$NON-NLS-1$
  
  public static final String PLUGIN_DOMAIN = "scc.basicSessionSetup"; //$NON-NLS-1$
  
  public static final String VIRTUAL_LOCATION_FILTER = "virtualLocationFilter"; //$NON-NLS-1$
  
  public static final String ENABLE_SIMULATED_LOCATION = "enableSimulatedLocation"; //$NON-NLS-1$
  
  /* Jpanel instance which holds the UI for SessionSetupNavigationPage */

  private JPanel sessionSetupPanel;

  /* Preview session controller */
  private PreviewSessionController previewSessionController;

  @Override
  public void initialise(SessionRequester aSessionRequester, MainFrame aMainFrame)
  {
    boolean idealRunEnabled = Registry.getInstance().getBoolean(RegistryConstants.SCC.DOMAIN, ENABLE_IDEAL_RUN_KEY, false);
    SimulationSessionModel simulationSessionModel = new SimulationSessionModel();
    ReplaySessionModel replaySessionModel = new ReplaySessionModel();
    PreviewSessionModel previewSessionModel = new PreviewSessionModel();

    /* Simulation session controller */
    SimulationSessionController newSessionController = new SimulationSessionController(aSessionRequester, simulationSessionModel);
    /* Replay session controller */
    ReplaySessionController replaySessionController = new ReplaySessionController(aSessionRequester, replaySessionModel);
    previewSessionController = new PreviewSessionController(aSessionRequester, previewSessionModel);

    SimulationSessionView newSessionView = new SimulationSessionView(newSessionController, simulationSessionModel);
    newSessionView.initialise();
    ReplaySessionView replaySessionView = new ReplaySessionView(replaySessionController, replaySessionModel);
    PreviewSessionView previewSessionView = new PreviewSessionView(previewSessionController, previewSessionModel);
    // verify to show ideal run tab
   
    sessionSetupPanel = new SessionSetupTabPanel(newSessionView, null, replaySessionView, previewSessionView);
  }

  // HACK:start
  // Allow automated session launching of the test scenarios
  private CSystem backgroundSystem = null;

  private boolean autoTestingEnabled = Registry.getInstance().getBoolean(RegistryConstants.SCC.DOMAIN, ENABLE_AUTO_TESTING, false);

  
  // HACK:end

  @Override
  public SessionSetupNavigationPage createSessionSetupNavigationPage()
  {
    return new SessionSetupNavigationPage(sessionSetupPanel);
  }

  @Override
  public Collection<UnitCreator> getScenarioUnitCreators(CSystem aSystem)
  {
    backgroundSystem = aSystem;
    return Collections.singleton(() -> new PluginUnit());
  }

  private class PluginUnit implements Unit, ScenarioProcessing
  {
    @Override
    public Collection<UnitCreator> defineSession(Gateway aGateway)
    {
      try
      {
        SessionData<GenericData> sd = aGateway.getSessionData();
        if (sd.isSimulation())
        {
          BaseSessionData sessionData = PeerApplication.deserialiseFromComms(sd);
          previewSessionController.defineSession(sessionData);
        }
      }
      catch (IOException e)
      {
        Tracer.getInstance().error(e);
      }
      return Collections.emptyList();
    }
  }

}
