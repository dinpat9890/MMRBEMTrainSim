/*******************************************************************************
 * (C) Copyright 2020 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.dmi.backend.logic;

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
import com.sydac.mmrbem.dmi.backend.app.io.handlers.IAppOutputsHandler;
import com.sydac.mmrbem.dmi.backend.app.io.models.IAppInputsModel;
import com.sydac.mmrbem.dmi.backend.comms.CommsBinding;
import com.sydac.mmrbem.dmi.backend.vehicle.io.properties.ICBTCOnboardOutputsProperties;
import com.sydac.mmrbem.dmi.backend.vehicle.io.properties.ICBTCPlatformOutputsProperties;
import com.sydac.mmrbem.dmi.backend.vehicle.io.properties.IDMIVehicleOutputsStartupScreenProperties;
import com.sydac.mmrbem.dmi.backend.vehicle.io.properties.IPISBEOutputsProperties;
import com.sydac.mmrbem.dmi.common.io.properties.IAppInputsProperties;

public abstract class AbstractFunctionalLogic implements IFunctionalLogic
{
  /**
   * Application Inputs ProperyKey change callback are queued and executed in a
   * single thread
   */
  private final ExecutorService appInputsUpdatesExecutor = Executors.newSingleThreadExecutor();

  /**
   * PIS ProperyKey change callback are queued and executed in a single thread
   */
  private final ExecutorService pisUpdatesExecutor = Executors.newSingleThreadExecutor();

  /**
   * CBTCOnboardOutputs ProperyKey change callback are queued and executed in a
   * single thread
   */
  private final ExecutorService cbtcOnboardOutputsExecutor = Executors.newSingleThreadExecutor();

  /**
   * CBTCPlatformOutputs ProperyKey change callback are queued and executed in a
   * single thread
   */
  private final ExecutorService cbtcPlatformOutputsExecutor = Executors.newSingleThreadExecutor();

  private final ExecutorService dmiVehicleOutputsExecutor = Executors.newSingleThreadExecutor();

  private ScheduledExecutorService scheduledExecutorService = Executors.newSingleThreadScheduledExecutor();

  /** Active vehicle index */
  private final int activeVehicleIndex;

  /** Reference to CommsBinding */
  private final CommsBinding commsBinding;

  /** List of lister managers to detach */
  private final List<IListenerManager> listenerManagers = Collections.synchronizedList(new ArrayList<>());

  /** TMSBackendInputs property key definitions */
  private final List<Class<?>> cbtcOnboardOutputsPropertyKeyDefinitions = Collections
      .synchronizedList(new ArrayList<>());

  /** TMSBackendInputs property key definitions */
  private final List<Class<?>> cbtcPlatformOutputsPropertyKeyDefinitions = Collections
      .synchronizedList(new ArrayList<>());

  private final List<Class<?>> dmiVehicleOutputsPropertyKeyDefinitions = Collections
      .synchronizedList(new ArrayList<>());

  /** AppInputs property key definitions */
  private final List<Class<?>> appInputsPropertyKeyDefinitions = Collections
      .synchronizedList(new ArrayList<>());

  /** PISOutputs property key definitions */
  private final List<Class<?>> pisOutputsPropertyKeyDefinitions = Collections
      .synchronizedList(new ArrayList<>());

  /** Holds the state of ApplicationInputs */
  private final IAppInputsModel appInputsModel;

  private final List<Class<?>> pisBeOutputsPropertyKeyDefinitions = Collections
      .synchronizedList(new ArrayList<>());

  /**
   * PIS BE ProperyKey change callback are queued and executed in a single
   * thread
   */
  private final ExecutorService pisBeOutputsExecutor = Executors.newSingleThreadExecutor();

  /**
   * @param commsBinding
   *          instance of {@link CommsBinding}
   * @param propertyKeyDefinitions
   *          {@link PropertyKey} definitions
   */
  public AbstractFunctionalLogic(CommsBinding commsBinding, Class<?>... propertyKeyDefinitions)
  {
    this.commsBinding = commsBinding;
    this.appInputsModel = (IAppInputsModel)commsBinding.getAppInputsModel();
    this.activeVehicleIndex = commsBinding.getActiveVehicleIndex();
    for (Class<?> clazz : propertyKeyDefinitions)
    {
      if (clazz.isAssignableFrom(ICBTCOnboardOutputsProperties.class))
      {
        cbtcOnboardOutputsPropertyKeyDefinitions.add(clazz);
      }
      else if (clazz.isAssignableFrom(ICBTCPlatformOutputsProperties.class))
      {
        cbtcPlatformOutputsPropertyKeyDefinitions.add(clazz);
      }
      else if (clazz.isAssignableFrom(IAppInputsProperties.class))
      {
        appInputsPropertyKeyDefinitions.add(clazz);
      }
      else if (clazz.isAssignableFrom(IDMIVehicleOutputsStartupScreenProperties.class))
      {
        dmiVehicleOutputsPropertyKeyDefinitions.add(clazz);
      }
      else if (clazz.isAssignableFrom(IPISBEOutputsProperties.class))
      {
        pisBeOutputsPropertyKeyDefinitions.add(clazz);
      }
      else
      {
        throw new IllegalArgumentException(
            String.format("Unknown PropertyKey definition :: %s", clazz.getName())); //$NON-NLS-1$
      }
    }
  }

  /**
   * Accessor for <code>appInputsModel</code>
   *
   * @return the appInputsModel
   */
  public IAppInputsModel getAppInputsModel()
  {
    return appInputsModel;
  }

  @Override
  public void attachToModel()
  {
    // Listeners added for appInputsProperties
    listenerManagers
        .add(buildListenerManager(appInputsPropertyKeyDefinitions, commsBinding.getAppInputsModel(),
            new Pair<>(commsBinding.getActiveVehicleIndex(), null), IoType.APP_INPUTS));

    // Listeners for DMIVehicleOutputs
    commsBinding.getDmiVehicleOutputsModels().entrySet().forEach(entry -> {
      int vehicleIndex = entry.getKey();
      IPropertyModel propertyModel = entry.getValue();
      listenerManagers.add(buildListenerManager(dmiVehicleOutputsPropertyKeyDefinitions, propertyModel,
          new Pair<>(vehicleIndex, null), IoType.DMI_VEHICLE_OUTPUTS));
    });

    listenerManagers.forEach(IListenerManager::attachToModel);
  }

  public void attachPisBeOutputsToModels()
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

  /**
   * Attaches listeners for PISOutput properties.
   */
  public void attachPisOutputPropertiesToModel()
  {
    if (commsBinding.getPisOutputsModel() != null)
    {
      IListenerManager listenerManager = buildListenerManager(pisOutputsPropertyKeyDefinitions,
          commsBinding.getPisOutputsModel(), new Pair<>(activeVehicleIndex, null), IoType.PIS_OUTPUTS);
      listenerManager.attachToModel();
      listenerManagers.add(listenerManager);
    }
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
   * Returns map of indexed indexed events for the specified
   * <code>vehicleIndex</code>
   * 
   * @param vehicleIndex
   *          vehicleIndex
   * @return property model
   */
  public Map<Integer, IPropertyModel> getVehicleEventsModels(int vehicleIndex)
  {
    return commsBinding.getVehicleEventsModels().get(vehicleIndex);
  }

  /**
   * Accessor for <code>dbScenarioTrain</code>
   *
   * @return the dbScenarioTrain
   */
  public DBScenarioTrain getDbScenarioTrain()
  {
    return commsBinding.getDbScenarioTrain();
  }

  /**
   * Returns the instance of {@link IPropertyModel} of PISOutpus
   * 
   * @return property model
   */
  public IPropertyModel getPisOutpusModel()
  {
    return commsBinding.getPisOutputsModel();
  }

  protected <T> void setApplicationOutputsProperty(final PropertyKey<T> propKey, T value)
  {
    if (commsBinding.getAppOutputsSetter() != null)
    {
      commsBinding.getAppOutputsSetter().setProperty(propKey, value);
    }
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
      if (IoType.APP_INPUTS == ioType)
      {
        Runnable appInputsUpdatesTask = () -> appInputsPropertyUpdated(key, oldValue, newValue,
            indexPair.getFirst());
        appInputsUpdatesExecutor.execute(appInputsUpdatesTask);
      }
      else if (IoType.PIS_OUTPUTS == ioType)
      {
        Runnable eventsUpdatesTask = () -> pisOutputPropertyUpdated(key, oldValue, newValue,
            indexPair.getFirst());
        pisUpdatesExecutor.execute(eventsUpdatesTask);
      }
      else if (IoType.CBTC_ON_BOARD_OUTPUTS == ioType)
      {
        Runnable eventsUpdatesTask = () -> cbtcOnboardOutputsPropertyUpdated(key, oldValue, newValue,
            indexPair.getFirst());
        cbtcOnboardOutputsExecutor.execute(eventsUpdatesTask);
      }
      else if (IoType.CBTC_PLATFORM_OUTPUTS == ioType)
      {
        Runnable eventsUpdatesTask = () -> cbtcPlatformOutputsPropertyUpdated(key, oldValue, newValue,
            indexPair.getFirst());
        cbtcPlatformOutputsExecutor.execute(eventsUpdatesTask);
      }
      else if (IoType.DMI_VEHICLE_OUTPUTS == ioType)
      {
        Runnable eventsUpdatesTask = () -> dmiVehicleOutputsPropertyUpdated(key, oldValue, newValue,
            indexPair.getFirst());
        dmiVehicleOutputsExecutor.execute(eventsUpdatesTask);
      }
      else if (IoType.PIS_BE_OUTPUTS == ioType)
      {
        Runnable vehicleUpdatesTask = () -> pisBeOutputsPropertyUpdated(key, oldValue, newValue,
            indexPair.getFirst());
        pisBeOutputsExecutor.execute(vehicleUpdatesTask);
      }
    }
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
  public IPropertySetter getCbtcOnboardInputsSetter(Integer vehicleIndex)
  {
    return commsBinding.getCbtcOnboardInputsSetters().get(vehicleIndex);
  }

  private enum IoType
  {
    APP_INPUTS, CBTC_ON_BOARD_OUTPUTS, CBTC_PLATFORM_OUTPUTS, PIS_OUTPUTS, DMI_VEHICLE_OUTPUTS, PIS_BE_OUTPUTS;
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

}
