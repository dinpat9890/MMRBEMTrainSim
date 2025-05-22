/*
 * ================================================================== (C)
 * Copyright 2020 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.psd.backend.vehicle.request.handler;

import com.sydac.foundation.PropertyKey;

/**
 * Implement this interface to encapsulate the TCMS Vehicle Outputs specific
 * update parameters.
 * 
 * @author joshian
 */
public interface ITCMSVehicleOutputsRequest<T>
{
  public PropertyKey<Integer> getPropertyKey();

  public T getOldValue();

  public T getNewValue();

  public int getCarIndex();

}
