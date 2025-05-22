/*
 * ==================================================================
 * 
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
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
 * TCMS Frontend Application entry point.
 * 
 * @author joshian
 *
 */
public final class TCMSFrontendModule extends AbstractFxFrontendModule
{

  private static final Frontend FRONTEND = Frontend.TCMS;

  /**
   * @param unitCreators
   *          unit creators
   * @param connectionInfo
   *          connection information
   */
  public TCMSFrontendModule(Collection<UnitCreator> unitCreators, CommsConnectionInfo connectionInfo)
  {
    super(unitCreators, connectionInfo);
    setupFrontend();
  }

  /**
   * @param connectionInfo
   *          connection information
   */
  public TCMSFrontendModule(CommsConnectionInfo connectionInfo)
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
    applicationName = ApplicationConstants.TCMS_APP_NAME;
    frameTitle = ApplicationConstants.TCMS_FRAME_TITLE_PREFIX;
  }

}
