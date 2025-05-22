/*
 * ==================================================================
 *
 * (C) Copyright 2020 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *
 * ==================================================================
 */
package com.sydac.mmrbem.cabscreens.fe.base;

import java.awt.AWTException;
import java.awt.Dimension;
import java.awt.Robot;
import java.awt.Toolkit;
import java.io.IOException;
import java.util.Collection;
import java.util.Collections;
import java.util.HashMap;
import java.util.Map;

import com.sydac.common.febe.HubUtils;
import com.sydac.common.febe.frontend.IHubObjectCallback;
import com.sydac.common.log.Tracer;
import com.sydac.common.registry.Registry;
import com.sydac.common.sessiondata.AcceptCache;
import com.sydac.common.sessiondata.BaseScenarioData;
import com.sydac.common.sessiondata.BaseSessionData;
import com.sydac.peer.application.PeerApplication;
import com.sydac.simcomms.CObject;
import com.sydac.simcomms.Gateway;
import com.sydac.simcomms.application.CommsConnectionInfo;
import com.sydac.simcomms.framework.UnitCreator;
import com.sydac.simcomms.system.CSystem;
import com.sydac.simulatorcontroller.types.SimulatorType;

/**
 * Base class for running panels supplied by {@link IFrontendPanelManager} as a
 * standalone module.
 */
public abstract class AbstractFrontendModule extends PeerApplication
{
  protected static final String GUI_DOMAIN = "gui"; //$NON-NLS-1$

  protected static final String SCREEN_HIDE_MOUSE = "screen.hide.mouse"; //$NON-NLS-1$

  protected static final String SCREEN_UNDECORATED = "screen.undecorated"; //$NON-NLS-1$

  protected static final String SCREEN_BACKGROUND = "screen.background"; //$NON-NLS-1$

  protected static final boolean UNDECORATED = Registry.getInstance().getBoolean(GUI_DOMAIN, SCREEN_UNDECORATED, true);

  protected static final boolean HIDE_MOUSE = Registry.getInstance().getBoolean(GUI_DOMAIN, SCREEN_HIDE_MOUSE, true);
  
  protected static final String HUB_DOMAIN = "hub";//$NON-NLS-1$
  
  protected static final String HUB_NAME_PROPERTY = "hubName";//$NON-NLS-1$
  
  protected static final String SIM_NAME_PROPERTY = "simName";//$NON-NLS-1$
  
  private AcceptCache acceptCache;

  // These objects have an application-long lifetime.
  protected IFrontendPanelManager panelManager = createPanelManager();  

  /**
   * Set from the PAM properties passed in via
   * {@link #initialise(int, int, int, int)}.
   */
  protected int x;

  /**
   * Set from the PAM properties passed in via
   * {@link #initialise(int, int, int, int)}.
   */
  protected int y;

  /**
   * Set from the PAM properties passed in via
   * {@link #initialise(int, int, int, int)}.
   */
  protected int width;

  /**
   * Set from the PAM properties passed in via
   * {@link #initialise(int, int, int, int)}.
   */
  protected int height;

  // These objects have a lifetime of a single session

  public AbstractFrontendModule(Collection<UnitCreator> unitCreators, CommsConnectionInfo connectionInfo)
  {
    super(unitCreators, connectionInfo);
  }

  public AbstractFrontendModule(CommsConnectionInfo connectionInfo)
  {
    this(Collections.emptyList(), connectionInfo);
  }
  
  /**
   * Creates a {@link IFrontendPanelManager}.
   *
   * @return the {@link IFrontendPanelManager} for your application.
   */
  protected abstract IFrontendPanelManager createPanelManager();

  /**
   * Moves the mouse to a point where it is less obstructive if
   * {@link #HIDE_MOUSE} is set. This is only really useful for the splash
   * screen. Once <a href=
   * "https://adl-atlassian.corp.knorr-bremse.com/jira/browse/CORETRAIN-2081">
   * CORETRAIN-2081</a> is resolved this should no longer be needed.
   *
   */
  protected void hideMouse()
  {
    if (HIDE_MOUSE)
    {
      try
      {
        Robot robot = new Robot();
        Dimension screenSize = Toolkit.getDefaultToolkit().getScreenSize();
        robot.mouseMove(screenSize.width, 0);
      }
      catch (AWTException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  @Override
  public final void initialise(final int xpos, final int ypos, int aWidth, int aHeight)
  {
    panelManager = createPanelManager();
    x = xpos;
    y = ypos;
    width = aWidth;
    height = aHeight;
    hideMouse();
    initialiseImpl(xpos, ypos, aWidth, aHeight);
    SimulatorType simulatorType = SimulatorType.valueOf(Registry.getInstance()
        .getString(HUB_DOMAIN, SIM_NAME_PROPERTY));
    // Prepare the acceptCache with either hub or simulator ID.
    acceptCache = new AcceptCache(simulatorType.getId());
  }

  /**
   * Implementation specific application initialisation
   *
   * @param carIndex
   *          The car that this application's hub is on.
   */
  protected abstract void initialiseApplication(int carIndex);

  /**
   * {@inheritDoc}
   * <p>
   * Default behaviour in {@link AbstractFrontendModule} is to return true.
   */
  @Override
  protected boolean doAcceptScenario(CSystem system, BaseScenarioData scenarioData)
  {
    return acceptCache.acceptScenario(scenarioData);
  }

  @Override
  public Collection<UnitCreator> defineSession(Gateway gateway)
  {
    Collection<UnitCreator> collection = null;
    try
    {
      BaseScenarioData scenarioData = deserialiseFromComms(gateway.getScenarioData());
      BaseSessionData sessionData = deserialiseFromComms(gateway.getSessionData());

      int carIndex = HubUtils.findVehicleIndex(scenarioData, HubUtils.findLogicalHubId(scenarioData, Registry.getInstance()));

      initialiseApplication(carIndex);

      panelManager.prepareFrontend(gateway, scenarioData, sessionData, carIndex);

      IHubObjectCallback callback = new HubInitializationWatcher(carIndex);

      Map<Integer, IHubObjectCallback> callbacks = new HashMap<>();
      callbacks.put(carIndex, callback);

      panelManager.startFrontends(getApplicationName(), gateway, scenarioData, sessionData, !gateway.isReplay(), callback);

      collection= doDefineSession(gateway, scenarioData, sessionData); 
      return collection;
    }
    catch (IOException ex)
    {
      Tracer.getInstance().error(ex);
    }
    return collection;
  }

  protected abstract IHubObjectCallback createHubObjectCallback(int carIndex);

  /**
   * Called when {@link #defineSession(Gateway)} is called, after the base class
   * has done its work.
   *
   * @param gateway
   *          For accessing Comms.
   * @param scenarioData
   *          The scenario that was loaded.
   * @param sessionData
   *          The session that was defined.
   *
   * @return The creators, if any, that the comms layer should execute in order
   *         to create new Units with a session lifetime.
   */
  protected Collection<UnitCreator> doDefineSession(Gateway gateway, BaseScenarioData scenarioData, BaseSessionData sessionData)
  {
    Collection<UnitCreator> collection = null;
    return collection;
  }

  /**
   * Returns a name to append to related Comms object names. This string is only
   * used for diagnostics, it should not be localised.
   *
   * @return a human-readable name to give the Comms object(s) to help identify
   *         it in CommsShow.
   */
  protected abstract String getApplicationName();

  /**
   * Returns a title to use for an application frame. Called by
   *
   * @param carIndex carIndex
   * 
   * @return a title to use for an application frame.
   */
  protected abstract String getFrameTitle(int carIndex);

  @Override
  public final void setVisible(boolean aVisible)
  {
    // Ignore, we don't get enough control over when this is called
  }

  @Override
  public void resetSession()
  {
    panelManager.resetSession();
  }

  protected abstract void showApplication(final int carIndex, final boolean show);

  protected abstract void initialiseImpl(final int xpos, final int ypos, int aWidth, int aHeight);

  /**
   * Entity to control the visibility of the Frontend application based on the
   * initialization / destruction of hub objects.
   * 
   * @author Nazim Oliyath
   *
   */
  private final class HubInitializationWatcher implements IHubObjectCallback
  {
    private int bitmask = 0x000;

    private final int carIndex;

    public HubInitializationWatcher(int carIndex)
    {
      this.carIndex = carIndex;
    }

    @Override
    public void onHubValuesCreation(CObject hubValues)
    {
      bitmask |= 0x001;
      makeVisibleWhenReady();
    }

    @Override
    public void onHubOutputCreation(CObject hubOutput)
    {
      bitmask |= 0x010;
      makeVisibleWhenReady();
    }

    @Override
    public void onHubInputCreation(CObject hubInput)
    {
      bitmask |= 0x100;
      makeVisibleWhenReady();
    }

    @Override
    public void onHubObjectDestruction()
    {
      showApplication(HubInitializationWatcher.this.carIndex, false);
    }

    /**
     * Request application to be made visible when all the hubObjects <br>
     * (Inputs/Outputs/Values) have been created
     */
    private void makeVisibleWhenReady()
    {
      if (bitmask == 0x111)
      {
        showApplication(HubInitializationWatcher.this.carIndex, true);
      }
    }
  }

}
