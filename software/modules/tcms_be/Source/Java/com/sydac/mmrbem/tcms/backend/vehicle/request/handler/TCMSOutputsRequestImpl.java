/*
 * ================================================================== (C)
 * Copyright 2020 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.tcms.backend.vehicle.request.handler;

import com.sydac.foundation.PropertyKey;

/**
 * This class holds update parameters and handler.
 * 
 * @author walbeg
 * @param <T>
 *          the type variable
 * @param <V>
 *          the value
 */
public class TCMSOutputsRequestImpl<T, V> extends CommonVehicleOutputsRequest<T>
{
  protected final V handler;

  public TCMSOutputsRequestImpl(PropertyKey<Integer> aKey, T aOldValue, T aNewValue, int aCarIndex, V aHandler)
  {
    super(aKey, aOldValue, aNewValue, aCarIndex);
    handler = aHandler;
  }

  public V getHandler()
  {
    return handler;
  }

}
