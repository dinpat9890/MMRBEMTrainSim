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

import java.awt.BorderLayout;
import java.awt.Dimension;
import java.util.Collections;
import java.util.HashMap;
import java.util.LinkedHashMap;
import java.util.Map;
import java.util.Properties;

import javax.swing.JPanel;
import javax.swing.Timer;

import com.sydac.common.febe.frontend.IHubObjectCallback;
import com.sydac.common.febe.frontend.IODataObjectMonitor;
import com.sydac.simcomms.CObject;
import com.sydac.simcomms.framework.GatewayProvider;

import javafx.embed.swing.JFXPanel;

/**
 * Frontend Panel Manager that bridges the simulator session with the JavaFx
 * application's creation and presentation
 *
 * @author Nazim Oliyath
 */
public abstract class AbstractFrontendPanelManager implements IFxFrontendPanelManager
{
  private static final String WIDTH_KEY = "width"; //$NON-NLS-1$

  private static final String HEIGHT_KEY = "height"; //$NON-NLS-1$

  protected static final String HIDE_MOUSE = "hideMouse"; //$NON-NLS-1$

  protected IODataObjectMonitor monitor;

  protected final Map<Integer, FrontendJFXPanel> fxPanels = Collections.synchronizedMap(new HashMap<>());

  protected final Map<Integer, IHubObjectCallback> hubObjectCallbacks = new LinkedHashMap<>();

  protected IFxFrontendSceneManager sceneManager = createSceneManager();

  protected boolean hideMouse = false;

  protected GatewayProvider gatewayProvider;

  protected HubObjectProvider hubObjectProvider;

  protected int xPos;

  protected int yPos;

  protected int width;

  protected int height;

  public AbstractFrontendPanelManager()
  {
    // Empty constructor
  }

  @Override
  public void initialise(int xpos, int ypos, int aWidth, int aHeight)
  {
    this.xPos = xpos;
    this.yPos = ypos;
    this.width = aWidth;
    this.height = aHeight;
  }

  protected void prepareFrontend(int carIndex)
  {
    hubObjectProvider = new HubObjectProvider(gatewayProvider);
    hubObjectCallbacks.put(carIndex, hubObjectProvider);
//    ApplicationFactory.register(carIndex, hubObjectProvider);
  }

  @Override
  public void resetSession()
  {
    monitor = null;

    for (int carIndex : this.hubObjectCallbacks.keySet())
    {
      if (fxPanels.containsKey(carIndex))
      {
        fxPanels.get(carIndex).reset(carIndex);
      }
    }

    for (FrontendJFXPanel panel : fxPanels.values())
    {
      panel.clearScenes();
    }

    fxPanels.clear();
    hubObjectCallbacks.clear();
    ApplicationFactory.flush();

    flush();
  }

  protected abstract IFxFrontendSceneManager createSceneManager();

  /**
   * This method gets call on reset session
   */
  protected abstract void flush();

  public JPanel getPanel(final int carIndex, Properties properties)
  {
    JPanel jp = new JPanel();
    jp.setLayout(new BorderLayout());

    if (!fxPanels.containsKey(carIndex))
    {
      fxPanels.put(carIndex, new FrontendJFXPanel());
    }

    JFXPanel fxPanel = fxPanels.get(carIndex);

    if (properties != null)
    {
      int gmiWidth = Integer.parseInt(properties.getProperty(WIDTH_KEY));
      int gmiHeight = Integer.parseInt(properties.getProperty(HEIGHT_KEY));

      Dimension dim = new Dimension(gmiWidth, gmiHeight);

      jp.setMinimumSize(dim);
      jp.setPreferredSize(dim);
    }

    jp.add(fxPanel, BorderLayout.CENTER);

    return jp;
  }

  @Override
  public void setHideMouse(boolean aHideMouse)
  {
    hideMouse = aHideMouse;
  }

  @Override
  public void setGatewayProvider(GatewayProvider gatewayProvider)
  {
    this.gatewayProvider = gatewayProvider;
  }
}
