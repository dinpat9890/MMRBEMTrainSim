/*
 * ==================================================================
 * (C)Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * ==================================================================
 */
package com.sydac.mmrbem.tcms.backend.vehicle.request.handler;

import java.util.List;

import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.tcms.common.data.VehicleDetailModel;

/**
 * This class holds Update parameters, handler and Vehicle details list.
 *
 * @param <T>
 *          type
 * @param <V>
 *          value
 */
public class TCMSOutputsECNScreenImpl<T, V> extends TCMSOutputsRequestImpl<T, V>
{
  protected final List<VehicleDetailModel> vehicleDetailModelList;

  public TCMSOutputsECNScreenImpl(PropertyKey<Integer> aKey, T aOldValue, T aNewValue, int aCarIndex,
      V aHandler, List<VehicleDetailModel> aVehicleDetailModelList)
  {
    super(aKey, aOldValue, aNewValue, aCarIndex, aHandler);
    vehicleDetailModelList = aVehicleDetailModelList;
  }

  public List<VehicleDetailModel> getVehicleDetailModelList()
  {
    return vehicleDetailModelList;
  }
}