/*******************************************************************************
 * (C) Copyright 2020 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.dmi.backend.logic;

import com.sydac.foundation.IListenerManager;
import com.sydac.foundation.IPropertyModel;
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

  /**
   * Called when a property in {@link IPropertyModel} representing
   * TMSBackendInputs is updated.
   *
   * @param key
   *          Identifies the property.
   * @param oldValue
   *          The value before the update.
   * @param newValue
   *          The value after the update.
   * @param vehicleIndex
   *          The vehicle index where this property belongs to.
   * @param <T>
   *          the type variable
   */
  default <T> void tmsVehicleOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue,
      int vehicleIndex)
  {}

  /**
   * Called when a property in {@link IPropertyModel} representing
   * applicationInputs is updated.
   *
   * @param key
   *          Identifies the property.
   * @param oldValue
   *          The value before the update.
   * @param newValue
   *          The value after the update.
   * @param vehicleIndex
   *          The vehicle index where this property belongs to.
   * @param <T>
   *          the type variable
   */
  default <T> void appInputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue, int vehicleIndex)
  {}

  /**
   * Called when a property in {@link IPropertyModel} representing Events are
   * updated.
   *
   * @param key
   *          Identifies the property.
   * @param oldValue
   *          The value before the update.
   * @param newValue
   *          The value after the update.
   * @param vehicleIndex
   *          The vehicle index where this property belongs to. * The value
   *          after the update.
   * @param eventIndex
   *          The event index with in the vehicle
   * @param <T>
   *          the type variable
   */
  default <T> void eventsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue, int vehicleIndex,
      int eventIndex)
  {}

  /**
   * Called when a property in {@link IPropertyModel} representing PIS are
   * updated.
   *
   * @param key
   *          Identifies the property.
   * @param oldValue
   *          The value before the update.
   * @param newValue
   *          The value after the update.
   * @param vehicleIndex
   *          The vehicle index where this property belongs to. * The value
   * @param <T>
   *          the type variable
   */
  default <T> void pisOutputPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue, int vehicleIndex)
  {}

  /**
   * Called when a property in {@link IPropertyModel} representing
   * CBTCOnboardOutputs updated.
   *
   * @param key
   *          Identifies the property.
   * @param oldValue
   *          The value before the update.
   * @param newValue
   *          The value after the update.
   * @param vehicleIndex
   *          The vehicle index where this property belongs to. * The value
   * @param <T>
   *          the type variable
   */
  default <T> void cbtcOnboardOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue,
      int vehicleIndex)
  {}

  /**
   * Called when a property in {@link IPropertyModel} representing
   * CBTCPlatformOutputs updated.
   *
   * @param key
   *          Identifies the property.
   * @param oldValue
   *          The value before the update.
   * @param newValue
   *          The value after the update.
   * @param vehicleIndex
   *          The vehicle index where this property belongs to. * The value
   * @param <T>
   *          the type variable
   */
  default <T> void cbtcPlatformOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue,
      int vehicleIndex)
  {}

  /**
   * Called when a property in {@link IPropertyModel} representing
   * DMIVehicleOutputs updated.
   *
   * @param key
   *          Identifies the property.
   * @param oldValue
   *          The value before the update.
   * @param newValue
   *          The value after the update.
   * @param vehicleIndex
   *          The vehicle index where this property belongs to. * The value
   * @param <T>
   *          the type variable
   */
  default <T> void dmiVehicleOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue,
      int vehicleIndex)
  {}

  default <T> void pisBeOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue, int vehicleIndex)
  {}
}
