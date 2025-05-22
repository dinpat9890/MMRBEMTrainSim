/*
 * ==================================================================
 *
 * (C) Copyright 2021 Oktal Sydac Pvt Ltd., all rights reserved. This is
 * unpublished proprietary source code of Sydac. The copyright notice above does
 * not evidence any actual or intended publication of such source code.
 * ==================================================================
 */
package com.sydac.mmrbem.papis.backend.logic;

import com.sydac.foundation.IListenerManager;
import com.sydac.foundation.PropertyKey;

public interface IFunctionalLogic extends IListenerManager
{

  /**
   * Performs business logic processing to determine the appropriate outputs to
   * the user.
   * 
   * @param aSimTime
   *          The current simulated time in milliseconds.
   */
  default void process(long aSimTime)
  {}

  default <T> void vehicleOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue, int vehicleIndex)
  {}

  default <T> void vehiclePropertyUpdated(PropertyKey<T> key, T oldValue, T newValue, Integer vehicleIndex)
  {

  }

  default <T> void appInputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue, int vehicleIndex)
  {}

  default <T> void pisBeOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue, int vehicleIndex)
  {}

  default <T> void papisVehicleOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue,
      int vehicleIndex)
  {}

  default <T> void trainComputerVehicleOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue,
      int vehicleIndex)
  {}

  default <T> void eventsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue, int vehicleIndex,
      int eventIndex)
  {}

  default <T> void ohpOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue, int ohpIndex)
  {}

  default <T> void intercomOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue, int ohpIndex)
  {}
}
