/*
 * ==================================================================
 *
 * (C) Copyright 2021 Oktal Sydac Pvt Ltd., all rights reserved. This is
 * unpublished proprietary source code of Sydac. The copyright notice above does
 * not evidence any actual or intended publication of such source code.
 * ==================================================================
 */
package com.sydac.mmrbem.psd.backend.logic;

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
  {}

  default <T> void appInputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue, int vehicleIndex)
  {}

  default <T> void pisBeOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue, int vehicleIndex)
  {}

  default <T> void cbtcPlatformOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue,
      int vehicleIndex)
  {}

  default <T> void cbtcPlatformInputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue,
      int vehicleIndex)
  {}

  default <T> void cbtcVehicleOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue,
      int vehicleIndex)
  {}

  default <T> void cbtcOnboardOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue,
      int vehicleIndex)
  {}
}
