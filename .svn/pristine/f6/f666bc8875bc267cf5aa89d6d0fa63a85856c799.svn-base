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

import java.util.Properties;

import com.sydac.simcomms.framework.GatewayProvider;

/**
 * {@link IFrontendPanelManager} extension that handles creation and
 * presentation of the JavaFx application
 * 
 * @author Nazim Oliyath
 *
 */
public interface IFxFrontendPanelManager extends IFrontendPanelManager
{

  final String XPOS_KEY = "XPOS_KEY"; //$NON-NLS-1$

  final String YPOS_KEY = "YPOS_KEY"; //$NON-NLS-1$

  final String APP_HEIGHT_KEY = "APP_HEIGHT_KEY"; //$NON-NLS-1$

  final String APP_WIDTH_KEY = "APP_WIDTH_KEY"; //$NON-NLS-1$

  /**
   * Creates the JavaFx Application for the given car and properties.
   * <p>
   *
   * @param carIndex  The car that we are interested in.
   * @param properties May be null. If suppled, these are usually from the GMI plugin
   *          definition, and can be used for differentiating between multiple
   *          panels.
   */
  public void createFxApplication(int carIndex, Properties properties);

  /**
   * API to control the presentation (show/hide) of the JavaFx application
   * 
   * @param carIndex
   *          - carIndex of vehicle being simulated
   * @param show
   *          true - displays the application <br>
   *          false - hides/kills the application
   */
  public void showFxApplication(int carIndex, boolean show);

  /**
   * API to pause/un-pause the JavaFx application. Paused applications will not
   * respond to any user inputs.<br>
   * <br>
   * Note: The application can be paused/un-paused only if it has been created
   * first and is current showing
   * 
   * @param pause flag to pause application
   */
  public void pauseFxApplication(boolean pause);

  public void setHideMouse(boolean hideMouse);

  public void setGatewayProvider(GatewayProvider gatewayProvider);
  
  void initialise(int x, int y, int width, int height);

}
