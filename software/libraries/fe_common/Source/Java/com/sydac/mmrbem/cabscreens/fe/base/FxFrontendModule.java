/*
 * ==================================================================
 * 
 * (C) Copyright 2016 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.cabscreens.fe.base;

import java.util.Collection;
import java.util.Collections;
import java.util.Properties;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

import com.sydac.common.febe.frontend.FrontendModule;
import com.sydac.common.febe.frontend.IHubObjectCallback;
import com.sydac.simcomms.CObject;
import com.sydac.simcomms.Gateway;
import com.sydac.simcomms.application.CommsConnectionInfo;
import com.sydac.simcomms.framework.UnitCreator;
import com.sydac.simcomms.system.State;

/**
 * This entity is the JavaFx abstraction for {@link AbstractFrontendModule}<br>
 * <br>
 * Frontend applications that use JavaFx for rendering will be extending this
 * class
 *
 * @author Nazim Oliyath
 */
@SuppressWarnings("deprecation")
public abstract class FxFrontendModule extends AbstractFrontendModule
{
  private static final String FX_LAUNCHER_THREAD = "Fx-Launcher-Thread"; //$NON-NLS-1$

  private IFxFrontendPanelManager fxFrontendPanelManager;

  private final Properties props = new Properties();

  /**
   * Constructor
   *
   * @param unitCreators
   *          unitCreators
   * @param connectionInfo
   *          connectionInfo
   */
  protected FxFrontendModule(Collection<UnitCreator> unitCreators, CommsConnectionInfo connectionInfo)
  {
    super(unitCreators, connectionInfo);
  }

  /**
   * @param connectionInfo
   *          connectionInfo
   */
  protected FxFrontendModule(CommsConnectionInfo connectionInfo)
  {
    this(Collections.emptyList(), connectionInfo);
  }

  /**
   * Concrete {@link FrontendModule} extensions should implement this method to
   * provide the implementation of {@link IFxFrontendPanelManager}
   *
   * @return {@link IFxFrontendPanelManager}
   */
  protected abstract IFxFrontendPanelManager createFxPanelManager();

  /*
   * (non-Javadoc)
   *
   * @see com.sydac.fgwiep.fe.base.AbstractFrontendModule#createPanelManager()
   */
  @Override
  protected final IFrontendPanelManager createPanelManager()
  {
    this.fxFrontendPanelManager = createFxPanelManager();
    return this.fxFrontendPanelManager;
  }

  /*
   * (non-Javadoc)
   *
   * @see
   * com.sydac.fgwiep.fe.base.AbstractFrontendModule#showApplication(boolean)
   */
  @Override
  protected final void showApplication(final int carIndex, final boolean show)
  {
    this.fxFrontendPanelManager.showFxApplication(carIndex, show);

    if (State.PAUSED == getStatus().getState())
    {
      this.fxFrontendPanelManager.pauseFxApplication(true);
    }
  }

  /*
   * (non-Javadoc)
   *
   * @see com.sydac.fgwiep.fe.base.AbstractFrontendModule#initialiseImpl(int,
   * int, int, int)
   */
  @Override
  protected final void initialiseImpl(int xpos, int ypos, int aWidth, int aHeight)
  {
    props.put(IFxFrontendPanelManager.XPOS_KEY, xpos);
    props.put(IFxFrontendPanelManager.YPOS_KEY, ypos);
    props.put(IFxFrontendPanelManager.APP_WIDTH_KEY, aWidth);
    props.put(IFxFrontendPanelManager.APP_HEIGHT_KEY, aHeight);
    fxFrontendPanelManager.initialise(xpos, ypos, aWidth, aHeight);
  }

  @Override
  public void stateChanging(State newState)
  {
    super.stateChanging(newState);

    if (State.PAUSED == newState)
    {
      fxFrontendPanelManager.pauseFxApplication(true);
    }
    else if (State.RUNNING == newState)
    {
      fxFrontendPanelManager.pauseFxApplication(false);
    }
  }

  @Override
  protected void initialiseApplication(int carIndex)
  {
    /*
     * Separate thread is used to create the JavaFx application.
     *
     * The thread that calls javafx.application.Application.start() gets blocked
     * till the JavaFx application exits, and here the createFrontedApp() call
     * is on a Comms thread, which shouldn't be blocked.
     */
    getFxExecutor().execute(() -> this.fxFrontendPanelManager.createFxApplication(carIndex, props));
    /*
     * We do this, as the hiding of the cursor is a per scene change, it can't
     * be done at a higher level
     */
    this.fxFrontendPanelManager.setHideMouse(HIDE_MOUSE);
  }

  /**
   * Single thread executor created with a customized thread factory.
   * <p>
   * Customized thread factory is used here so as to assign a ClassLoader to the
   * thread used by the executor.
   *
   * @return {@link ExecutorService}
   */
  public static ExecutorService getFxExecutor()
  {
    return Executors.newSingleThreadExecutor(runnable -> {

      Thread fxMainThread = new Thread(runnable, FX_LAUNCHER_THREAD);

      if (fxMainThread.isDaemon())
      {
        fxMainThread.setDaemon(false);
      }

      if (fxMainThread.getPriority() != Thread.NORM_PRIORITY)
      {
        fxMainThread.setPriority(Thread.NORM_PRIORITY);
      }

      ClassLoader classLoader = FxFrontendModule.class.getClassLoader();
      fxMainThread.setContextClassLoader(classLoader);

      return fxMainThread;
    });
  }

  @Override
  protected IHubObjectCallback createHubObjectCallback(final int aCarIndex)
  {
    return new FxFrontendModuleHubObjectCallback(aCarIndex);
  }

  @Override
  public Collection<UnitCreator> defineSession(Gateway gateway)
  {
    fxFrontendPanelManager.setGatewayProvider(this);
    return super.defineSession(gateway);
  }

  private final class FxFrontendModuleHubObjectCallback implements IHubObjectCallback
  {
    private boolean valuesCreated = false;

    private boolean outputCreated = false;

    private boolean inputCreated = false;

    private final int carIndex;

    private FxFrontendModuleHubObjectCallback(int aCarIndex)
    {
      carIndex = aCarIndex;
    }

    @Override
    public void onHubValuesCreation(CObject hubValues)
    {
      valuesCreated = true;
      makeVisibleWhenReady();
    }

    @Override
    public void onHubOutputCreation(CObject hubOutput)
    {
      outputCreated = true;
      makeVisibleWhenReady();
    }

    @Override
    public void onHubInputCreation(CObject hubInput)
    {
      inputCreated = true;
      makeVisibleWhenReady();
    }

    @Override
    public void onHubObjectDestruction()
    {
      showApplication(carIndex, false);
    }

    /**
     * Request application to be made visible when all the hubObjects <br>
     * (Inputs/Outputs/Values) have been created
     */
    private void makeVisibleWhenReady()
    {
      if (valuesCreated && outputCreated && inputCreated)
      {
        showApplication(carIndex, true);
      }
    }

    private void showApplication(final int carIndex, final boolean show)
    {
      fxFrontendPanelManager.showFxApplication(carIndex, show);

      if (State.PAUSED == getStatus().getState())
      {
        fxFrontendPanelManager.pauseFxApplication(true);
      }
    }
  }
}
