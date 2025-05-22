/*
 * ==================================================================
 * 
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.psd.fe.base;

import java.lang.reflect.Field;
import java.text.MessageFormat;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.concurrent.Executors;
import java.util.concurrent.ScheduledExecutorService;

import com.sydac.foundation.IListenerManager;
import com.sydac.foundation.IPropertyListener;
import com.sydac.foundation.IPropertyListenerManagerBuilder;
import com.sydac.foundation.IPropertyModel;
import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.cabscreens.fe.common.IFrontend;
import com.sydac.mmrbem.psd.fe.comms.CommsBinding;

/**
 * Abstract class for all Comms Listeners
 * 
 */
public abstract class AbstractCommsListener implements CommsListener
{
  /** ScheduleExecutorService. */
  public static final ScheduledExecutorService EXECUTOR = Executors.newSingleThreadScheduledExecutor();

  /** List of lister managers to detach */
  protected final List<IListenerManager> listenerManagers = Collections.synchronizedList(new ArrayList<>());

  /** AppOutputs property key definitions */
  protected final List<Class<?>> propertyKeyDefinitions = Collections.synchronizedList(new ArrayList<>());

  /** Reference to CommsBinding. */
  protected CommsBinding commsBinding;

  protected boolean attached = false;

  protected int scenarioCarIndex;

  protected IFrontend frontend;

  /**
   * @param scenarioCarIndex
   *          the scenarioCarIndex to set
   */
  public final void setScenarioCarIndex(int scenarioCarIndex)
  {
    this.scenarioCarIndex = scenarioCarIndex;
  }

  public final void setFrontend(IFrontend frontend)
  {
    this.frontend = frontend;
  }

  /**
   * Attaching listeners added for AppInputs properties.
   * 
   * @param commsBinding
   *          Reference to the CommsBinding associated with the desired vehicle
   *          index.
   */
  public void attachToModel(CommsBinding commsBinding)
  {
    if (!attached)
    {
      attached = true;

      this.commsBinding = commsBinding;

      listenerManagers.add(buildListenerManager(propertyKeyDefinitions, commsBinding.getHubOutputsModel()));

      listenerManagers.forEach(IListenerManager::attachToModel);
    }
  }

  /**
   * Detaches AppInputs listeners from model.
   */
  @Override
  public void detachFromModel()
  {
    listenerManagers.forEach(IListenerManager::detachFromModel);
  }

  /*
   *
   */
  protected IListenerManager buildListenerManager(List<Class<?>> propertyKeyDefinitions,
      IPropertyModel propertyModel)
  {
    IPropertyListenerManagerBuilder propertyListenerManagerBuilder = propertyModel
        .newListenerManagerBuilder();

    propertyKeyDefinitions.forEach(propertyKeyDefinition -> {
      for (Field f : propertyKeyDefinition.getFields())
      {
        if (f.getType().equals(PropertyKey.class))
        {
          PropertyKey<?> key;
          try
          {
            key = (PropertyKey<?>)f.get(null);
          }
          catch (IllegalArgumentException | IllegalAccessException e)
          {
            throw new IllegalStateException(MessageFormat.format("Cannot access {0} in {1}.", //$NON-NLS-1$
                f.getName(), propertyKeyDefinition), e);
          }
          propertyListenerManagerBuilder.add(key, new PropertyListener<>(), true);
        }
      }
    });

    return propertyListenerManagerBuilder.build();
  }

  /**
   * Property listener.
   * 
   * @author porinjub
   * @param <T>
   */
  private class PropertyListener<T> implements IPropertyListener<T>
  {
    @Override
    public void propertyUpdated(PropertyKey<T> key, T oldValue, T newValue)
    {
      appOutputsPropertyUpdated(key, oldValue, newValue);
    }
  }

  /**
   * Called when a property in {@link IPropertyModel} representing
   * ApplicationInputs are updated.
   *
   * @param key
   *          Identifies the property.
   * @param oldValue
   *          The value before the update.
   * @param newValue
   *          The value after the update.
   * @param <T>
   *          A type variable
   */
  protected abstract <T> void appOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue);
}
