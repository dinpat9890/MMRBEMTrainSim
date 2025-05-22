/*******************************************************************************
 * (C) Copyright 2020 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.psd.backend.vehicle.request.handler;

import com.sydac.foundation.PropertyKey;

/**
 * This class to encapsulates the update parameters from comms.
 * 
 * @author joshian
 */
public class CommonVehicleOutputsRequest<T> implements ITCMSVehicleOutputsRequest<T>
{
  protected final PropertyKey<Integer> key;

  protected final T oldValue;

  protected final T newValue;

  protected final int carIndex;

  public CommonVehicleOutputsRequest(PropertyKey<Integer> aKey, T aOldValue, T aNewValue, int aCarIndex)
  {
    key = aKey;
    oldValue = aOldValue;
    newValue = aNewValue;
    carIndex = aCarIndex;
  }

  @Override
  public PropertyKey<Integer> getPropertyKey()
  {
    return key;
  }

  @Override
  public T getOldValue()
  {
    return oldValue;
  }

  @Override
  public T getNewValue()
  {
    return newValue;
  }

  @Override
  public int getCarIndex()
  {
    return carIndex;
  }
}
