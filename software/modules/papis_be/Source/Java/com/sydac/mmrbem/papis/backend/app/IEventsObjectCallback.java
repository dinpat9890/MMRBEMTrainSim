package com.sydac.mmrbem.papis.backend.app;

import com.sydac.common.log.Tracer;
import com.sydac.simcomms.CObject;

@FunctionalInterface
public interface IEventsObjectCallback
{
  /**
   * Called when the vehicleEvents object is created.
   * 
   * @param eventsObject
   *          The application events object.
   * @param aVehicleIndex
   *          The index of the vehicle.
   */
  default void onVehicleEventsObjectCreation(CObject eventsObject, int aVehicleIndex)
  {
    Tracer.getInstance()
        .debug(String.format("%s created on vehilce %s", eventsObject.getName(), aVehicleIndex)); //$NON-NLS-1$
  }

  /**
   * /** Called when the vehicleEvent object is created.
   * 
   * @param eventObject
   *          The vehicle events object.
   * @param aVehicleIndex
   *          The index of the vehicle.
   * @param index
   *          The index of the event.
   */
  public void onVehicleEventObjectCreation(CObject eventObject, int aVehicleIndex, int index);

  /**
   * Called when the vehicleEvents object is destroyed.
   * 
   * @param aVehicleIndex
   *          The index of the vehicle.
   */
  default void onVehicleEventsObjectDestruction(int aVehicleIndex)
  {
    Tracer.getInstance().debug(String.format("Events object destroyed on vehilce %s", aVehicleIndex)); //$NON-NLS-1$
  }
}
