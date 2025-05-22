/*
 * ==================================================================
 *
 * (C) Copyright 2021 Oktal Sydac Pvt Ltd., all rights reserved. This is
 * unpublished proprietary source code of Sydac. The copyright notice above does
 * not evidence any actual or intended publication of such source code.
 * ==================================================================
 */
package com.sydac.mmrbem.psd.backend.logic;

import java.lang.reflect.Field;
import java.text.MessageFormat;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
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
import com.sydac.mmrbem.psd.backend.app.io.handlers.IAppOutputsHandler;
import com.sydac.mmrbem.psd.backend.app.io.models.IAppInputsModel;
import com.sydac.mmrbem.psd.backend.comms.CommsBinding;
import com.sydac.mmrbem.psd.backend.io.IAppInputsHandler;
import com.sydac.mmrbem.psd.backend.vehicle.io.properties.ICBTCOnboardOutputsProperties;
import com.sydac.mmrbem.psd.backend.vehicle.io.properties.ICBTCPlatformInputsProperties;
import com.sydac.mmrbem.psd.backend.vehicle.io.properties.ICBTCPlatformOutputsProperties;
import com.sydac.mmrbem.psd.backend.vehicle.io.properties.IPISBEOutputsProperties;
import com.sydac.mmrbem.psd.backend.vehicle.io.properties.IPSDVehicleOutputsProperties;
import com.sydac.mmrbem.psd.backend.vehicle.io.properties.IVehicleProperties;
import com.sydac.mmrbem.psd.common.io.properties.IAppInputsProperties;

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
   * PAPIS Vehicle ProperyKey change callback are queued and executed in a
   * single thread
   */
  private final ExecutorService pisBeOutputsExecutor = Executors.newSingleThreadExecutor();

  /**
   * CBTCPlatformOutputs ProperyKey change callback are queued and executed in a
   * single thread
   */
  private final ExecutorService cbtcPlatformOutputsExecutor = Executors.newSingleThreadExecutor();

  private final ExecutorService cbtcPlatformInputsExecutor = Executors.newSingleThreadExecutor();

  private final List<Class<?>> cbtcPlatformOutputsPropertyKeyDefinitions = Collections
      .synchronizedList(new ArrayList<>());

  private final List<Class<?>> cbtcPlatformInputsPropertyKeyDefinitions = Collections
      .synchronizedList(new ArrayList<>());

  /** Active vehicle index */
  private final int activeVehicleIndex;

  /** Reference to CommsBinding */
  private final CommsBinding commsBinding;

  /** Holds the state of ApplicationInputs */
  private final IAppInputsModel appInputsModel;

  /** Holds the setter of ApplicationOutputs */
  private final IAppOutputsHandler appOutputHandler;

  private final IAppInputsHandler appInputHandler;

  /** List of lister managers to detach */
  private final List<IListenerManager> listenerManagers = Collections.synchronizedList(new ArrayList<>());

  private final List<Class<?>> psdVehicleOutputsPropertyKeyDefinitions = Collections
      .synchronizedList(new ArrayList<>());

  /** AppInputs property key definitions */
  private final List<Class<?>> appInputsPropertyKeyDefinitions = Collections
      .synchronizedList(new ArrayList<>());

  /** Vehicle property key definitions */
  private final List<Class<?>> vehicleObjectPropertyKeyDefinitions = Collections
      .synchronizedList(new ArrayList<>());

  private final List<Class<?>> pisBeOutputsPropertyKeyDefinitions = Collections
      .synchronizedList(new ArrayList<>());

  private final ExecutorService cbtcOnboardOutputsExecutor = Executors.newSingleThreadExecutor();

  private final List<Class<?>> cbtcOnboardOutputsPropertyKeyDefinitions = Collections
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
    this.appInputsModel = (IAppInputsModel)commsBinding.getAppInputsModel();
    this.appOutputHandler = (IAppOutputsHandler)commsBinding.getAppOutputsSetter();
    this.appInputHandler = (IAppInputsHandler)commsBinding.getAppInputsSetter();

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
      else if (clazz.isAssignableFrom(IPSDVehicleOutputsProperties.class))
      {
        psdVehicleOutputsPropertyKeyDefinitions.add(clazz);
      }
      else if (clazz.isAssignableFrom(ICBTCPlatformOutputsProperties.class))
      {
        cbtcPlatformOutputsPropertyKeyDefinitions.add(clazz);
      }
      else if (clazz.isAssignableFrom(IPISBEOutputsProperties.class))
      {
        pisBeOutputsPropertyKeyDefinitions.add(clazz);
      }
      else if (clazz.isAssignableFrom(ICBTCPlatformInputsProperties.class))
      {
        cbtcPlatformInputsPropertyKeyDefinitions.add(clazz);
      }
      else if (clazz.isAssignableFrom(ICBTCOnboardOutputsProperties.class))
      {
        cbtcOnboardOutputsPropertyKeyDefinitions.add(clazz);
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

    listenerManagers.forEach(IListenerManager::attachToModel);
  }

  @Override
  public void detachFromModel()
  {
    listenerManagers.forEach(IListenerManager::detachFromModel);
  }

  // public Map<Integer, IPropertyModel> getVehicleEventsModels(int
  // vehicleIndex)
  // {
  // return commsBinding.getVehicleCrewMessageModels().get(vehicleIndex);
  // }

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
    return commsBinding.getActiveVehicleIndex();
  }

  /**
   * Returns the instance of {@link IPropertySetter} for the
   * <code>vehicleIndex</code>
   * 
   * @param vehicleIndex
   *          vehicle index
   *
   * @return Instance of property setter for each vehicle's VehicleInputsSetter
   */
  public IPropertySetter getVehicleInputsSetter(Integer vehicleIndex)
  {
    return commsBinding.getVehicleInputsSetters().get(vehicleIndex);
  }

  /**
   * Accessor for <code>appInputsModel</code>
   *
   * @return IAppInputsModel the appInputsModel
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
      else if (IoType.CBTC_PLATFORM_OUTPUTS == ioType)
      {
        Runnable eventsUpdatesTask = () -> cbtcPlatformOutputsPropertyUpdated(key, oldValue, newValue,
            indexPair.getFirst());
        cbtcPlatformOutputsExecutor.execute(eventsUpdatesTask);
      }
      else if (IoType.PIS_BE_OUTPUTS == ioType)
      {
        Runnable vehicleUpdatesTask = () -> pisBeOutputsPropertyUpdated(key, oldValue, newValue,
            indexPair.getFirst());
        pisBeOutputsExecutor.execute(vehicleUpdatesTask);
      }
      else if (IoType.CBTC_PLATFORM_INTPUTS == ioType)
      {
        Runnable eventsUpdatesTask = () -> cbtcPlatformInputsPropertyUpdated(key, oldValue, newValue,
            indexPair.getFirst());
        cbtcPlatformInputsExecutor.execute(eventsUpdatesTask);
      }
      else if (IoType.CBTC_ON_BOARD_OUTPUTS == ioType)
      {
        Runnable eventsUpdatesTask = () -> cbtcOnboardOutputsPropertyUpdated(key, oldValue, newValue,
            indexPair.getFirst());
        cbtcOnboardOutputsExecutor.execute(eventsUpdatesTask);
      }
    }

  }

  private enum IoType
  {
    APP_INPUTS, VEHICLE_OBJECT, VEHICLE_OUTPUTS, PIS_BE_OUTPUTS, CBTC_PLATFORM_OUTPUTS, CBTC_PLATFORM_INTPUTS, CBTC_ON_BOARD_OUTPUTS;
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

  public void attchCbtcPlatformOutputsToModels()
  {
    // Listeners for CBTCPlatformOutputsProperties
    commsBinding.getCbtcPlatformOutputsModels().entrySet().forEach(entry -> {
      int vehicleIndex = entry.getKey();
      IPropertyModel propertyModel = entry.getValue();
      if (commsBinding.getCbtcPlatformOutputsModels() != null)
      {
        IListenerManager listenerManager = (buildListenerManager(cbtcPlatformOutputsPropertyKeyDefinitions,
            propertyModel, new Pair<>(vehicleIndex, null), IoType.CBTC_PLATFORM_OUTPUTS));
        listenerManager.attachToModel();
        listenerManagers.add(listenerManager);
      }
    });
  }

  public void bindPisOutputsToModel()
  {
    commsBinding.getPISBEOutputsModel().entrySet().forEach(entry -> {
      int vehicleIndex = entry.getKey();
      IPropertyModel propertyModel = entry.getValue();
      if (commsBinding.getPISBEOutputsModel() != null)
      {
        IListenerManager listenerManager = buildListenerManager(pisBeOutputsPropertyKeyDefinitions,
            propertyModel, new Pair<>(vehicleIndex, null), IoType.PIS_BE_OUTPUTS);
        listenerManagers.add(listenerManager);
        listenerManager.attachToModel();
      }
    });
  }

  /**
   * Returns the instance of {@link IPropertySetter} for the CBTCOnboardInputs
   * for the requested <code>vehicleIndex</code>.
   * 
   * @param vehicleIndex
   *          vehicle index
   *
   * @return Instance of property setter for the requested vehicle's
   *         CBTCOnboardInputs
   */
  public IPropertySetter getCbtcPlatoformInputsSetter(Integer vehicleIndex)
  {
    return commsBinding.getCbtcPlatforInputputsSetters().get(vehicleIndex);
  }

  public void attchCbtcOnboardOutputsToModels()
  {
    commsBinding.getCbtcOnboardOutputsModels().entrySet().forEach(entry -> {
      int vehicleIndex = entry.getKey();
      IPropertyModel propertyModel = entry.getValue();
      if (commsBinding.getCbtcOnboardOutputsModels() != null)
      {
        IListenerManager listenerManager = buildListenerManager(cbtcOnboardOutputsPropertyKeyDefinitions,
            propertyModel, new Pair<>(vehicleIndex, null), IoType.CBTC_ON_BOARD_OUTPUTS);
        listenerManager.attachToModel();
        listenerManagers.add(listenerManager);
      }
    });
  }
}
