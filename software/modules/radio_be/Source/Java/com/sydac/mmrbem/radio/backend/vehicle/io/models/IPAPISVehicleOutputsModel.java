/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.radio.backend.vehicle.io.models;

import com.sydac.foundation.IObservablePropertyModel;

public interface IPAPISVehicleOutputsModel extends IObservablePropertyModel
{
  Integer getPapisCctvPower();
}
