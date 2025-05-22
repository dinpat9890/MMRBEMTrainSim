/*
 * ==================================================================
 * 
 * (C) Copyright 2020 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.tcms.fe.base;

import java.util.Collection;

import com.sydac.mmrbem.cabscreens.fe.base.AbstractFxFrontendModule;
import com.sydac.mmrbem.cabscreens.fe.base.IFxFrontendPanelManager;
import com.sydac.mmrbem.tcms.common.state.ApplicationConstants;
import com.sydac.mmrbem.tcms.fe.common.Frontend;
import com.sydac.simcomms.application.CommsConnectionInfo;
import com.sydac.simcomms.framework.UnitCreator;

/**
 * CCTV Frontend Application entry point.
 * 
 * @author joshian
 *
 */
public final class CCTVFrontendModule extends AbstractFxFrontendModule
{
  private static final Frontend FRONTEND = Frontend.CCTV;

  /**
   * @param unitCreators
   *          unit creators
   * @param connectionInfo
   *          connection information
   */
  public CCTVFrontendModule(Collection<UnitCreator> unitCreators, CommsConnectionInfo connectionInfo)
  {
    super(unitCreators, connectionInfo);
    setupFrontend();
  }

  /**
   * @param connectionInfo
   *          connection information
   */
  public CCTVFrontendModule(CommsConnectionInfo connectionInfo)
  {
    super(connectionInfo);
    setupFrontend();
  }

  @Override
  protected IFxFrontendPanelManager createFxPanelManager()
  {
    return new FrontendPanelManager(this, FRONTEND);
  }

  private void setupFrontend()
  {
    applicationName = ApplicationConstants.CCTV_APP_NAME;
    frameTitle = ApplicationConstants.CCTV_FRAME_TITLE_PREFIX;
  }

}
