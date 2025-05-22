/*
 * ==================================================================
 *
 * (C) Copyright 2017 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *
 * ==================================================================
 */
package com.sydac.mmrbem.radio.fe.comms;

import com.sydac.common.febe.frontend.IHubObjectCallback;
import com.sydac.foundation.IPropertyModel;
import com.sydac.foundation.IPropertySetter;
import com.sydac.simcomms.CObject;
import com.sydac.simcomms.Gateway;

/**
 * Listens to Comms.
 *
 * @author porinjub
 */
public abstract class CommsBinding implements IHubObjectCallback
{
  protected static final int DEFAULT_FREQUENCY = 20;

  /** The Gateway reference. */
  protected Gateway gateway;

  /** The vehicle index associated with this CommsBinding. */
  protected final int vehicleIndex;

  protected IPropertySetter hubInputsValuesSetter;

  protected IPropertyModel hubOutputsModel;

  protected IPropertyModel hubInputsModel;

  /**
   * Instantiates a new comms binding.
   *
   * @param aGateway
   *          The Gateway reference.
   * @param aVehicleIndex
   *          the vehicle index.
   */
  public CommsBinding(Gateway aGateway, int aVehicleIndex)
  {
    gateway = aGateway;
    vehicleIndex = aVehicleIndex;
  }

  public IPropertySetter getHubInputsValuesSetter()
  {
    return hubInputsValuesSetter;
  }

  public IPropertyModel getHubInputsModel()
  {
    return hubInputsModel;
  }

  public IPropertyModel getHubOutputsModel()
  {
    return hubOutputsModel;
  }

  @Override
  public void onHubObjectDestruction()
  {
    if (hubOutputsModel != null)
    {
      hubOutputsModel.destroy();
    }

    hubOutputsModel = null;

    hubInputsValuesSetter = null;
  }

  public void onHubInputCreation(CObject hubInputsObject)
  {
    // NO-OP at the moment.
  }

  /**
   * Terminate session.
   */
  public void terminateSession()
  {
    gateway = null;
  }
}
