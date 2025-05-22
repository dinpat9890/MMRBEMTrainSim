/*
 * ==================================================================
 *
 * (C) Copyright 2019 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * ==================================================================
 */
package com.sydac.mmrbem.psd.backend.app;

import com.sydac.common.febe.CommsTrainUtils;
import com.sydac.common.febe.CommsUtils;
import com.sydac.core.runtimedata.CoreObjectConstants;
import com.sydac.core.runtimedata.ObjectDefinition;
import com.sydac.project.runtimedata.ProjectObjectConstants;
import com.sydac.simcomms.CObject;
import com.sydac.simcomms.CallbackId;
import com.sydac.simcomms.Gateway;
import com.sydac.simcomms.ICObjectCreationListener;

/**
 * Class to monitor SDIS Crew Message
 */
public class EventsObjectMonitor extends AbstractCommsObjectMonitor
{
  private final IEventsObjectCallback eventsObjectCallback;

  private final int vehicleEventsClassId;

  private final int vehicleEventClassId;

  private final int vehicleOutputClassId;

  /**
   * Creates an {@link EventsObjectMonitor}. The <code>start</code> method
   * should be called to receive callbacks.
   * 
   * @param aGateway
   *          For connecting to Comms.
   * @param eventsObjectCallback
   *          Callback to notify of interface object creation
   * @param eventsDefinition
   *          Definition of the Events object
   * @param eventDefinition
   *          Definition of the Event object
   * @param vehicleOutputDefinition
   *          Definition of vehicle output
   * @param scenarioTrainId
   *          ID of the scenario train
   * 
   */
  public EventsObjectMonitor(Gateway aGateway, IEventsObjectCallback eventsObjectCallback,
      ObjectDefinition eventsDefinition, ObjectDefinition eventDefinition,
      ObjectDefinition vehicleOutputDefinition, int scenarioTrainId)
  {
    super(aGateway, scenarioTrainId);
    this.eventsObjectCallback = eventsObjectCallback;
    this.vehicleEventsClassId = CommsUtils.getClassId(eventsDefinition);
    this.vehicleEventClassId = CommsUtils.getClassId(eventDefinition);
    this.vehicleOutputClassId = CommsUtils.getClassId(vehicleOutputDefinition);
  }

  @Override
  public CObjectCreationListener getCObjectCreationListener()
  {
    // create CObject listener to monitor Crew Message comms number
    return new CObjectCreationListener();
  }

  /**
   * Implementation of {@link ICObjectCreationListener} Finds the correct
   * CObject and register (Crew Message) for property changes.
   */
  private class CObjectCreationListener implements ICObjectCreationListener
  {
    // vehicle index
    private Integer vehicleIndex;

    /**
     * Constructs a CObjectCreationListener. All the fields are initialized to
     * default values
     */
    public CObjectCreationListener()
    {
      this.vehicleIndex = null;
    }

    /**
     * Constructs a CObjectCreationListener with <code>vehicleIndex</code>
     * property.
     * 
     * @param vehicleIndex
     *          The vehicle index to set
     */
    public CObjectCreationListener(Integer vehicleIndex)
    {
      this.vehicleIndex = vehicleIndex;
    }

    @Override
    public void objectCreated(CObject[] objects)
    {
      for (CObject object : objects)
      {
        // Check if this is the World or train
        if (CommsUtils.testClassId(object, CoreObjectConstants.ClassId.WORLD)
            || CommsTrainUtils.testCObjectIsTrain(object, scenarioTrainId))
        {
          CallbackId<ICObjectCreationListener> objectCreationListener = addChildCreationListener(object,
              null);
          object.addDestructionListener((CObject[] cObjects) -> {
            for (CObject cObject : cObjects)
            {
              if (CommsUtils.testClassId(cObject, CoreObjectConstants.ClassId.WORLD))
              {
                cObject.removeChildCreationListener(objectCreationListener);
              }
            }
          });
        }
        else if (CommsTrainUtils.testCObjectIsVehicle(object))
        {
          Long index = Math.round(
              object.getNumbers().getInfo().getInfo(ProjectObjectConstants.Vehicle.INDEX).getInitial());
          CallbackId<ICObjectCreationListener> objectCreationListener = addChildCreationListener(object,
              index.intValue());
          object.addDestructionListener((CObject[] cObjects) -> {
            for (CObject cObject : cObjects)
            {
              if (CommsUtils.testClassId(cObject, index.intValue()))
              {
                cObject.removeChildCreationListener(objectCreationListener);
              }
            }
          });
        }
        else if (CommsUtils.testClassId(object, vehicleOutputClassId))
        {
          CallbackId<ICObjectCreationListener> objectCreationListener = addChildCreationListener(object,
              vehicleIndex);
          eventsObjectCallback.onVehicleEventsObjectCreation(object, vehicleIndex);
          object.addDestructionListener((CObject[] cObjects) -> {
            for (CObject cObject : cObjects)
            {
              if (CommsUtils.testClassId(cObject, vehicleOutputClassId))
              {
                eventsObjectCallback.onVehicleEventsObjectDestruction(vehicleIndex);
                cObject.removeChildCreationListener(objectCreationListener);
              }
            }
          });
        }
        else if (CommsUtils.testClassId(object, vehicleEventsClassId))
        {
          CallbackId<ICObjectCreationListener> objectCreationListener = addChildCreationListener(object,
              vehicleIndex);
          eventsObjectCallback.onVehicleEventsObjectCreation(object, vehicleIndex);
          object.addDestructionListener((CObject[] cObjects) -> {
            for (CObject cObject : cObjects)
            {
              if (CommsUtils.testClassId(cObject, vehicleEventsClassId))
              {
                cObject.removeChildCreationListener(objectCreationListener);
              }
            }
          });

        }
        else if (CommsUtils.testClassId(object, vehicleEventClassId))
        {
          eventsObjectCallback.onVehicleEventObjectCreation(object, vehicleIndex, object.getId());
        }
      }
    }

    private CallbackId<ICObjectCreationListener> addChildCreationListener(CObject object,
        Integer aVehicleIndex)
    {
      CallbackId<ICObjectCreationListener> callbackId;
      if (null == aVehicleIndex)
      {
        // adds creation listener to this object.
        CObjectCreationListener objectCreationListener = new CObjectCreationListener();
        callbackId = object.addChildCreationListener(objectCreationListener);
      }
      else
      {
        // adds creation listener with vehicle index to this object.
        CObjectCreationListener objectCreationListener = new CObjectCreationListener(aVehicleIndex);
        callbackId = object.addChildCreationListener(objectCreationListener);
      }
      return callbackId;
    }
  }

}
