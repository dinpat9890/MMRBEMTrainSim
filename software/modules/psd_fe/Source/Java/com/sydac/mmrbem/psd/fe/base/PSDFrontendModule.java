/*
 * ==================================================================
 * 
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.psd.fe.base;

import java.util.Collection;

import com.sydac.mmrbem.cabscreens.fe.base.AbstractFxFrontendModule;
import com.sydac.mmrbem.cabscreens.fe.base.IFxFrontendPanelManager;
import com.sydac.mmrbem.psd.common.data.ApplicationConstants;
import com.sydac.mmrbem.psd.fe.common.Frontend;
import com.sydac.simcomms.application.CommsConnectionInfo;
import com.sydac.simcomms.framework.UnitCreator;

/**
 * TCMS Frontend Application entry point.
 * 
 * @author joshian
 *
 */
public final class PSDFrontendModule extends AbstractFxFrontendModule
{



  /**
   * @param unitCreators
   *          unit creators
   * @param connectionInfo
   *          connection information
   */
  public PSDFrontendModule(Collection<UnitCreator> unitCreators, CommsConnectionInfo connectionInfo)
  {
    super(unitCreators, connectionInfo);
    setupFrontend();
  }

  /**
   * @param connectionInfo
   *          connection information
   */
  public PSDFrontendModule(CommsConnectionInfo connectionInfo)
  {
    super(connectionInfo);
    setupFrontend();
  }

  @Override
  protected IFxFrontendPanelManager createFxPanelManager()
  {
    return new FrontendPanelManager(this);
  }

  private void setupFrontend()
  {
    applicationName = ApplicationConstants.PSD_APP_NAME;
    frameTitle = ApplicationConstants.PSD_FRAME_TITLE_PREFIX;
  }

}
