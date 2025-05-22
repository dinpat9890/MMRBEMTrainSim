/*
 * ==================================================================
 *
 * (C) Copyright 2022 Oktal Sydac Pvt Ltd., all rights reserved. This is
 * unpublished proprietary source code of Sydac. The copyright notice above does
 * not evidence any actual or intended publication of such source code.
 * ==================================================================
 */
package com.sydac.mmrbem.papis.backend.logic;

import java.lang.reflect.Field;
import java.text.MessageFormat;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Map;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.ScheduledExecutorService;
import java.util.concurrent.TimeUnit;

import com.sydac.common.dataobjects.DBScenarioTrain;
import com.sydac.foundation.IListenerManager;
import com.sydac.foundation.IPropertyListener;
import com.sydac.foundation.IPropertyListenerManagerBuilder;
import com.sydac.foundation.IPropertyModel;
import com.sydac.foundation.IPropertySetter;
import com.sydac.foundation.PropertyKey;
import com.sydac.foundation.functional.Pair;
import com.sydac.mmrbem.papis.backend.app.io.handlers.IAppOutputsHandler;
import com.sydac.mmrbem.papis.backend.app.io.models.IAppInputsModel;
import com.sydac.mmrbem.papis.backend.comms.CommsBinding;
import com.sydac.mmrbem.papis.backend.io.IAppInputsHandler;
import com.sydac.mmrbem.papis.backend.vehicle.io.properties.IPAPISVehicleOutputsProperties;
import com.sydac.mmrbem.papis.backend.vehicle.io.properties.IPISBEInputsProperties;
import com.sydac.mmrbem.papis.backend.vehicle.io.properties.IPISBEOutputsProperties;
import com.sydac.mmrbem.papis.common.io.properties.IAppInputsProperties;
import com.sydac.mmrbem.papis.common.io.properties.IIntercomOutputsProperties;
import com.sydac.mmrbem.papis.common.io.properties.IOhpOutputsProperties;
import com.sydac.mmrbem.papis.common.io.properties.IVehicleProperties;

public abstract class AbstractFunctionalLogic implements IFunctionalLogic
{
  /**
   * Pulse events are queued and executed in a single thread
   */
  private ScheduledExecutorService scheduledExecutorService = Executors.newSingleThreadScheduledExecutor();

  /**
   * Application Inputs ProperyKey change callback are queued and executed in a
   * single thread
   */
  private final ExecutorService appInputsUpdatesExecutor = Executors.newSingleThreadExecutor();

  /**
   * Vehicle Output ProperyKey change callback are queued and executed in a
   * single thread
   */
  private final ExecutorService vehicleOutputsExecutor = Executors.newSingleThreadExecutor();

  /**
   * Vehicle ProperyKey change callback are queued and executed in a single
   * thread
   */
  private final ExecutorService vehicleObjectUpdatesExecutor = Executors.newSingleThreadExecutor();

  /**
   * PIS BE ProperyKey change callback are queued and executed in a single
   * thread
   */
  private final ExecutorService pisBeOutputsExecutor = Executors.newSingleThreadExecutor();

  /**
   * PAPIS Vehicle ProperyKey change callback are queued and executed in a
   * single thread
   */
  private final ExecutorService papisVehicleOutputsExecutor = Executors.newSingleThreadExecutor();

  /**
   * Event ProperyKey change callback are queued and executed in a single thread
   */
  private final ExecutorService eventUpdatesExecutor = Executors.newSingleThreadExecutor();

  /** Active vehicle index */
  private final int activeVehicleIndex;

  /** Reference to CommsBinding */
  private final CommsBinding commsBinding;

  /** List of lister managers to detach */
  private final List<IListenerManager> listenerManagers = Collections.synchronizedList(new ArrayList<>());

  /** AppInputs property key definitions */
  private final List<Class<?>> appInputsPropertyKeyDefinitions = Collections
      .synchronizedList(new ArrayList<>());

  /** Vehicle property key definitions */
  private final List<Class<?>> vehicleObjectPropertyKeyDefinitions = Collections
      .synchronizedList(new ArrayList<>());

  /** Events property key definitions */
  private final List<Class<?>> eventsPropertyKeyDefinitions = Collections.synchronizedList(new ArrayList<>());

  private final List<Class<?>> pisBeOutputsPropertyKeyDefinitions = Collections
      .synchronizedList(new ArrayList<>());

  private final List<Class<?>> pisBeInputsPropertyKeyDefinitions = Collections
      .synchronizedList(new ArrayList<>());

  private final List<Class<?>> papisVehicleOutputsPropertyKeyDefinitions = Collections
      .synchronizedList(new ArrayList<>());

  /** Ohp output property key definitions */
  private final List<Class<?>> ohpOutputsPropertyKeyDefinitions = Collections
      .synchronizedList(new ArrayList<>());

  /**
   * Ohp Output ProperyKey change callback are queued and executed in a single
   * thread
   */
  private final ExecutorService ohpOutputUpdatesExecutor = Executors.newSingleThreadExecutor();

  /**
   * Ohp Output ProperyKey change callback are queued and executed in a single
   * thread
   */
  private final ExecutorService intercomOutputUpdatesExecutor = Executors.newSingleThreadExecutor();

  /** Intercom output property key definitions */
  private final List<Class<?>> intercomOutputsPropertyKeyDefinitions = Collections
      .synchronizedList(new ArrayList<>());

  /**
   * @param commsBinding
   *          instance of {@link CommsBinding}
   * @param propertyKeyDefinitions
   *          {@link PropertyKey} definitions
   */
  protected AbstractFunctionalLogic(CommsBinding commsBinding, Class<?>... propertyKeyDefinitions)
  {
    this.commsBinding = commsBinding;
    this.activeVehicleIndex = commsBinding.getActiveVehicleIndex();

    for (Class<?> clazz : propertyKeyDefinitions)
    {
      if (clazz.isAssignableFrom(IAppInputsProperties.class))
      {
        appInputsPropertyKeyDefinitions.add(clazz);
      }
      else if (clazz.isAssignableFrom(IVehicleProperties.class))
      {
        vehicleObjectPropertyKeyDefinitions.add(clazz);
      }
      else if (clazz.isAssignableFrom(IPISBEOutputsProperties.class))
      {
        pisBeOutputsPropertyKeyDefinitions.add(clazz);
      }
      else if (clazz.isAssignableFrom(IPISBEInputsProperties.class))
      {
        pisBeInputsPropertyKeyDefinitions.add(clazz);
      }
      else if (clazz.isAssignableFrom(IPAPISVehicleOutputsProperties.class))
      {
        papisVehicleOutputsPropertyKeyDefinitions.add(clazz);
      }
      else if (clazz.isAssignableFrom(IOhpOutputsProperties.class))
      {
        ohpOutputsPropertyKeyDefinitions.add(clazz);
      }
      else if (clazz.isAssignableFrom(IIntercomOutputsProperties.class))
      {
        intercomOutputsPropertyKeyDefinitions.add(clazz);
      }
      else
      {
        throw new IllegalArgumentException(
            String.format("Unknown PropertyKey definition :: %s", clazz.getName())); //$NON-NLS-1$
      }
    }
  }

  @Override
  public void attachToModel()
  {
    // Listeners added for IAppInputsProperties
    listenerManagers
        .add(buildListenerManager(appInputsPropertyKeyDefinitions, commsBinding.getAppInputsModel(),
            new Pair<>(commsBinding.getActiveVehicleIndex(), null), IoType.APP_INPUTS));

    // Listeners for IVehicleProperties
    commsBinding.getVehicleObjectModels().entrySet().forEach(entry -> {
      int vehicleIndex = entry.getKey();
      IPropertyModel propertyModel = entry.getValue();
      if (propertyModel != null)
      {
        listenerManagers.add((buildListenerManager(vehicleObjectPropertyKeyDefinitions, propertyModel,
            new Pair<>(vehicleIndex, null), IoType.VEHICLE_OBJECT)));
      }
    });

    commsBinding.getPAPISVehicleOutputsModel().entrySet().forEach(entry -> {
      int vehicleIndex = entry.getKey();
      IPropertyModel propertyModel = entry.getValue();
      if (commsBinding.getPAPISVehicleOutputsModel() != null)
      {
        IListenerManager listenerManager = buildListenerManager(papisVehicleOutputsPropertyKeyDefinitions,
            propertyModel, new Pair<>(vehicleIndex, null), IoType.PAPIS_VEHICLE_OUTPUTS);
        listenerManagers.add(listenerManager);
      }
    });

    // Listeners for vehicle events
    commsBinding.getVehicleEventsModels().entrySet().forEach(entry -> {
      int vehicleIndex = entry.getKey();
      Map<Integer, IPropertyModel> vehicleEventsModels = entry.getValue();
      vehicleEventsModels.entrySet().forEach(indexedEventsModels -> {
        Integer index = indexedEventsModels.getKey();
        IPropertyModel vehicleEventModel = indexedEventsModels.getValue();
        listenerManagers.add(buildListenerManager(eventsPropertyKeyDefinitions, vehicleEventModel,
            new Pair<>(vehicleIndex, index), IoType.EVENTS));
      });
    });

    listenerManagers.forEach(IListenerManager::attachToModel);
  }

  public void attachPISBEOutputModels()
  {
    commsBinding.getPISBEOutputsModel().entrySet().forEach(entry -> {
      int vehicleIndex = entry.getKey();
      IPropertyModel propertyModel = entry.getValue();
      if (commsBinding.getPISBEOutputsModel() != null)
      {
        IListenerManager listenerManager = buildListenerManager(pisBeOutputsPropertyKeyDefinitions,
            propertyModel, new Pair<>(vehicleIndex, null), IoType.PIS_BE_OUTPUTS);
        listenerManager.attachToModel();
        listenerManagers.add(listenerManager);
      }
    });
  }

  @Override
  public void detachFromModel()
  {
    listenerManagers.forEach(IListenerManager::detachFromModel);
  }

  private IListenerManager buildListenerManager(List<Class<?>> propertyKeyDefinitions,
      IPropertyModel propertyModel, Pair<Integer, Integer> indexPair, IoType ioType)
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
          propertyListenerManagerBuilder.add(key, new PropertyListener<>(indexPair, ioType), true);
        }
      }
    });
    return propertyListenerManagerBuilder.build();
  }

  // Setter for Outputs properties
  protected <T> void setApplicationOutputsProperty(final PropertyKey<T> propKey, T value)
  {
    if (commsBinding.getAppOutputsSetter() != null)
    {
      commsBinding.getAppOutputsSetter().setProperty(propKey, value);
    }
  }

  /**
   * Checks if the <code>properyKey</code> object belongs to the
   * <code>propertyKeyDefinition</code> class.
   * 
   * @param propertyKey
   *          The instance of {@link PropertyKey} to be checked.
   * @param propertyKeyDefinition
   *          The property key definition class.
   * @return <code>true</code> if the <code>propertyKey</code> belongs to the
   *         <code>propertyKeyDefinition</code> class.
   */
  protected boolean checkPropertyKeyOwner(PropertyKey<?> propertyKey, Class<?> propertyKeyDefinition)
  {
    for (Field f : propertyKeyDefinition.getFields())
    {
      if (f.getType().equals(PropertyKey.class))
      {
        PropertyKey<?> currentKey;
        try
        {
          currentKey = (PropertyKey<?>)f.get(null);
        }
        catch (IllegalArgumentException | IllegalAccessException e)
        {
          throw new IllegalStateException(MessageFormat.format("Cannot access {0} in {1}.", //$NON-NLS-1$
              f.getName(), propertyKeyDefinition), e);
        }
        if (propertyKey.equals(currentKey))
        {
          return true;
        }
      }
    }
    return false;
  }

  /**
   * Accessor for <code>activeVehicleIndex</code>
   *
   * @return the activeVehicleIndex
   */
  public int getActiveVehicleIndex()
  {
    return activeVehicleIndex;
  }

  public IPropertySetter getPISBEInputsSetter(Integer vehicleIndex)
  {
    return commsBinding.getPISBEInputsSetters().get(vehicleIndex);
  }

  /**
   * Accessor for <code>appInputsModel</code>
   *
   * @return the appInputsModel
   */
  public IAppInputsModel getAppInputsModel()
  {
    return (IAppInputsModel)commsBinding.getAppInputsModel();
  }

  /**
   * Accessor for <code>appOutputHandler</code>
   * 
   * @return the appOutputHandler
   */
  public IAppOutputsHandler getAppOutputHandler()
  {
    return (IAppOutputsHandler)commsBinding.getAppOutputsSetter();
  }

  /**
   * Accessor for <code>appInputHandler</code>
   * 
   * @return the appInputHandler
   */
  public IAppInputsHandler getAppInputHandler()
  {
    return (IAppInputsHandler)commsBinding.getAppInputsSetter();
  }

  /**
   * Accessor for <code>dbScenarioTrain</code>
   *
   * @return the dbScenarioTrain
   */
  public DBScenarioTrain getScenarioTrain()
  {
    return commsBinding.getScenarioTrain();
  }

  private class PropertyListener<T> implements IPropertyListener<T>
  {
    private final Pair<Integer, Integer> indexPair;

    private final IoType ioType;

    public PropertyListener(Pair<Integer, Integer> indexPair, IoType ioType)
    {
      this.indexPair = indexPair;
      this.ioType = ioType;
    }

    @Override
    public void propertyUpdated(PropertyKey<T> key, T oldValue, T newValue)
    {
      if (IoType.VEHICLE_OUTPUTS == ioType)
      {
        Runnable vehicleOutputsUpdatesTask = () -> vehicleOutputsPropertyUpdated(key, oldValue, newValue,
            indexPair.getFirst());
        vehicleOutputsExecutor.execute(vehicleOutputsUpdatesTask);
      }

      else if (IoType.APP_INPUTS == ioType)
      {
        Runnable appInputsUpdatesTask = () -> appInputsPropertyUpdated(key, oldValue, newValue,
            indexPair.getFirst());
        appInputsUpdatesExecutor.execute(appInputsUpdatesTask);
      }

      else if (IoType.VEHICLE_OBJECT == ioType)
      {
        Runnable vehicleUpdatesTask = () -> vehiclePropertyUpdated(key, oldValue, newValue,
            indexPair.getFirst());
        vehicleObjectUpdatesExecutor.execute(vehicleUpdatesTask);
      }

      else if (IoType.PIS_BE_OUTPUTS == ioType)
      {
        Runnable vehicleUpdatesTask = () -> pisBeOutputsPropertyUpdated(key, oldValue, newValue,
            indexPair.getFirst());
        pisBeOutputsExecutor.execute(vehicleUpdatesTask);
      }

      else if (IoType.PAPIS_VEHICLE_OUTPUTS == ioType)
      {
        Runnable vehicleUpdatesTask = () -> papisVehicleOutputsPropertyUpdated(key, oldValue, newValue,
            indexPair.getFirst());
        papisVehicleOutputsExecutor.execute(vehicleUpdatesTask);
      }

      else if (IoType.EVENTS == ioType)
      {
        Runnable eventsUpdatesTask = () -> eventsPropertyUpdated(key, oldValue, newValue,
            indexPair.getFirst(), indexPair.getSecond());
        eventUpdatesExecutor.execute(eventsUpdatesTask);
      }
      else if (IoType.OHP_OUTPUTS == ioType)
      {
        Runnable ohpUpdatesTask = () -> ohpOutputsPropertyUpdated(key, oldValue, newValue,
            indexPair.getFirst());
        ohpOutputUpdatesExecutor.execute(ohpUpdatesTask);
      }
      else if (IoType.INTERCOM_OUTPUT == ioType)
      {
        Runnable intercomUpdatesTask = () -> intercomOutputsPropertyUpdated(key, oldValue, newValue,
            indexPair.getFirst());
        intercomOutputUpdatesExecutor.execute(intercomUpdatesTask);
      }
    }

  }

  private enum IoType
  {
    APP_INPUTS, VEHICLE_OBJECT, VEHICLE_OUTPUTS, TRAIN_COMPUTER_VEHICLE_OUTPUTS, TRAIN_COMPUTER_VEHICLE_INPUTS, PIS_BE_OUTPUTS, PAPIS_VEHICLE_OUTPUTS, EVENTS, OHP_OUTPUTS, INTERCOM_OUTPUT;
  }

  /**
   * Attaches listeners.
   */
  public void attachListeners()
  {
    attachToModel();
  }

  /**
   * Detaches listeners.
   */
  public void detachListeners()
  {
    detachFromModel();
  }

  /**
   * Sends pulse value to the specified {@link IPropertySetter} with the
   * specified {@link PropertyKey} and value.
   * 
   * @param propertySetter
   *          property setter
   * @param propKey
   *          prop key
   * @param value1
   *          value1
   * @param value2
   *          value2
   * @param <T>
   *          the type variable
   */
  protected <T> void sendPulseRequest(final IPropertySetter propertySetter, final PropertyKey<T> propKey,
      T value1, T value2)
  {
    if (propertySetter != null)
    {
      propertySetter.setProperty(propKey, value1);
      // reset the number after a delay of 100ms.
      scheduledExecutorService.schedule(new Runnable() {
        @Override
        public void run()
        {
          propertySetter.setProperty(propKey, value2);
        }
      }, 100, TimeUnit.MILLISECONDS);
    }
  }

  /**
   * Sends input value to the specified {@link IPropertySetter} with the
   * specified {@link PropertyKey} and value.
   * 
   * @param propertySetter
   *          property setter
   * @param propKey
   *          prop key
   * @param value1
   *          value1
   * @param <T>
   *          the type variable
   */
  protected <T> void setInputData(final IPropertySetter propertySetter, final PropertyKey<T> propKey,
      T value1)
  {
    if (propertySetter != null)
    {
      propertySetter.setProperty(propKey, value1);
    }
  }

  

  public void attachOHPOutPutsToModels()
  {
    // Listeners for vehicle events
    commsBinding.getOhpOutputsModels().entrySet().forEach(entry -> {
      int ohpIndex = entry.getKey();
      IPropertyModel ohpOutputModel = entry.getValue();
      IListenerManager listner = buildListenerManager(ohpOutputsPropertyKeyDefinitions, ohpOutputModel,
          new Pair<>(ohpIndex, ohpIndex), IoType.OHP_OUTPUTS);
      listenerManagers.add(listner);
      listner.attachToModel();
    });

  }

  /**
   * Accessor for <code>appOutputHandler</code>
   * 
   * @return the appOutputHandler
   */
  public IPropertySetter getIntercomHandler()
  {
    return commsBinding.getIntercomOutputsSetter();
  }
  
  public IPropertySetter getOhpHandler()
  {
    return commsBinding.getOhpInputSetter();
  }

  public void attachIntercomOutPutsToModels()
  {
    // Listeners for vehicle events
    commsBinding.getIntercomOutputsModels().entrySet().forEach(entry -> {
      int intercomIndex = entry.getKey();
      IPropertyModel intercomOutputModel = entry.getValue();
      IListenerManager listner = buildListenerManager(intercomOutputsPropertyKeyDefinitions,
          intercomOutputModel, new Pair<>(intercomIndex, intercomIndex), IoType.INTERCOM_OUTPUT);
      listenerManagers.add(listner);
      listner.attachToModel();
    });

  }

  
}
