/*
 * ==================================================================
 *
 * (C) Copyright 2019 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * ==================================================================
 */
package com.sydac.mmrbem.tcms.backend.app;

import com.sydac.simcomms.CObject;
import com.sydac.simcomms.Gateway;
import com.sydac.simcomms.ICObjectCreationListener;

/**
 * Abstract Class to monitor comms objects
 */
public abstract class AbstractCommsObjectMonitor
{
  protected final Gateway gateway;

  protected final int scenarioTrainId;

  // allocating a value which may not be used as an objectId
  protected static final int DUMMY_CLASS_ID_VALUE = -999;

  /**
   * Creates an {@link AbstractCommsObjectMonitor}. The <code>start</code>
   * method should be called to receive callbacks.
   * 
   * @param aGateway
   *          For connecting to Comms.
   * @param scenarioTrainId
   *          ID of the scenario train
   * 
   */
  public AbstractCommsObjectMonitor(Gateway aGateway, int scenarioTrainId)
  {
    this.gateway = aGateway;
    this.scenarioTrainId = scenarioTrainId;

  }

  /**
   * This method should be called after creating the instance of
   * {@link AbstractCommsObjectMonitor} to receive callbacks.
   */
  public final void start()
  {
    try
    {
      gateway.lock();
      CObject root = gateway.getRootObject();
      root.addChildCreationListener(getCObjectCreationListener());
    }
    finally
    {
      gateway.unlock();
    }
  }

  public abstract ICObjectCreationListener getCObjectCreationListener();

}