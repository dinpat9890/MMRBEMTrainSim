/*
 * ==================================================================
 * 
 * (C) Copyright 2020 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.dmi.fe.base;

import java.util.Collection;

import com.sydac.mmrbem.cabscreens.fe.base.AbstractFxFrontendModule;
import com.sydac.mmrbem.cabscreens.fe.base.IFxFrontendPanelManager;
import com.sydac.mmrbem.dmi.common.state.ApplicationConstants;
import com.sydac.simcomms.application.CommsConnectionInfo;
import com.sydac.simcomms.framework.UnitCreator;

/**
 * DMI Frontend Application entry point.
 * 
 * @author joshian
 *
 */
public final class DMIFrontendModule extends AbstractFxFrontendModule
{
  /**
   * @param unitCreators
   *          unit creators
   * @param connectionInfo
   *          connection information
   */
  public DMIFrontendModule(Collection<UnitCreator> unitCreators, CommsConnectionInfo connectionInfo)
  {
    super(unitCreators, connectionInfo);
    setupFrontend();
  }

  /**
   * @param connectionInfo
   *          connection information
   */
  public DMIFrontendModule(CommsConnectionInfo connectionInfo)
  {
    super(connectionInfo);
    setupFrontend();
  }

  @Override
  protected IFxFrontendPanelManager createFxPanelManager()
  {
    return new DMIFrontendPanelManager(this);
  }

  private void setupFrontend()
  {
    applicationName = ApplicationConstants.APP_NAME;
    frameTitle = ApplicationConstants.FRAME_TITLE_PREFIX;
  }

}
