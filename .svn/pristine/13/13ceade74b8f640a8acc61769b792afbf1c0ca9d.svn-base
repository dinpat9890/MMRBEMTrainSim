/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.fe.gui.binder;

import com.sydac.mmrbem.cabscreens.fe.gui.binder.AbstractScreenBinder;
import com.sydac.mmrbem.tcms.common.io.properties.IAppDataLoadingOutputHandler;
import com.sydac.project.runtimedata.ProjectObjectConstants;

public class CommunicationErrorBinder extends AbstractScreenBinder
{
  private final IAppDataLoadingOutputHandler dataLoadingOutputHandler;

  public CommunicationErrorBinder(int carIndex, IAppDataLoadingOutputHandler dataLoadingOutputHandler)
  {
    super(carIndex);
    this.dataLoadingOutputHandler = dataLoadingOutputHandler;
  }

  @Override
  public void doBinding()
  {
    frontendDataModel.bindIOData(ProjectObjectConstants.VDUOutputs.DATA_LOADING_SEQUENCE,
        () -> dataLoadingOutputHandler.setProgressMessageId(
            (int)frontendDataModel.getIOData(ProjectObjectConstants.VDUOutputs.DATA_LOADING_SEQUENCE)));
  }

}
