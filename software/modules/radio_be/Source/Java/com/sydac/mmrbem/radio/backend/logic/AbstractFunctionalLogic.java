/*
 * ==================================================================
 *
 * (C) Copyright 2022 Oktal Sydac Pvt Ltd., all rights reserved. This is
 * unpublished proprietary source code of Sydac. The copyright notice above does
 * not evidence any actual or intended publication of such source code.
 * ==================================================================
 */
package com.sydac.mmrbem.radio.backend.logic;

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
import com.sydac.mmrbem.radio.backend.app.io.handlers.IAppOutputsHandler;
import com.sydac.mmrbem.radio.backend.app.io.models.IAppInputsModel;
import com.sydac.mmrbem.radio.backend.comms.CommsBinding;
import com.sydac.mmrbem.radio.backend.io.IAppInputsHandler;
import com.sydac.mmrbem.radio.backend.radiointercom.properties.IRadioIntercomOutputProperties;
import com.sydac.mmrbem.radio.backend.vehicle.io.models.properties.ICBTCOnboardOutputsProperties;
import com.sydac.mmrbem.radio.backend.vehicle.io.models.properties.IPAPISVehicleOutputsProperties;
import com.sydac.mmrbem.radio.backend.vehicle.io.models.properties.IPISBEOutputsProperties;
import com.sydac.mmrbem.radio.backend.vehicle.io.models.properties.ITCMSVehicleOutputsProperties;
import com.sydac.mmrbem.radio.common.io.properties.IAppInputsProperties;
import com.sydac.mmrbem.radio.common.io.properties.IVehicleProperties;



public abstract class AbstractFunctionalLogic implements IFunctionalLogic
{
  /**
   * Pulse events are queued and executed in a single thread
   */
  private ScheduledExecutorService scheduledExecutorService = Executors.newSingleThreadScheduledExecutor();

  /**
   * Vehicle ProperyKey change callback are queued and executed in a single
   * thread
   */
  private final ExecutorService vehicleExecutor = Executors.newSingleThreadExecutor();

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
   * Event ProperyKey change callback are queued and executed in a single thread
   */
  private final ExecutorService eventUpdatesExecutor = Executors.newSingleThreadExecutor();

  /**
   * Event ProperyKey change callback are queued and executed in a single thread
   */
  private final ExecutorService radioIntercomUpdatesExecutor = Executors.newSingleThreadExecutor();

  /**
   * PAPIS Vehicle ProperyKey change callback are queued and executed in a
   * single thread
   */
  private final ExecutorService papisVehicleOutputsExecutor = Executors.newSingleThreadExecutor();
  
  /**
   * TCMSVehicle ProperyKey change callback are queued and executed in a single
   * thread
   */
  private final ExecutorService tcmsVehicleOutputsExecutor = Executors.newSingleThreadExecutor();

  /** Active vehicle index */
  private final int activeVehicleIndex;

  /** Reference to CommsBinding */
  private final CommsBinding commsBinding;

  /** List of lister managers to detach */
  private final List<IListenerManager> listenerManagers = Collections.synchronizedList(new ArrayList<>());

  /** AppInputs property key definitions */
  private final List<Class<?>> appInputsPropertyKeyDefinitions = Collections
      .synchronizedList(new ArrayList<>());

  /** Radio Intercom Outputs property key definitions */
  private final List<Class<?>> radioIntercomOutputsPropertyKeyDefinitions = Collections
      .synchronizedList(new ArrayList<>());

  private final List<Class<?>> papisVehicleOutputsPropertyKeyDefinitions = Collections
      .synchronizedList(new ArrayList<>());

  private final List<Class<?>> pisBeOutputsPropertyKeyDefinitions = Collections
      .synchronizedList(new ArrayList<>());

  /** Vehicle property key definitions */
  private final List<Class<?>> vehicleObjectPropertyKeyDefinitions = Collections
      .synchronizedList(new ArrayList<>());
  
  private final List<Class<?>> tcmsVehicleOutputsPropertyKeyDefinitions = Collections
      .synchronizedList(new ArrayList<>());

  private final ExecutorService pisBeOutputsExecutor = Executors.newSingleThreadExecutor();
  
  private final List<Class<?>> cbtcOnboardOutputsPropertyKeyDefinitions = Collections
      .synchronizedList(new ArrayList<>());
  private final ExecutorService cbtcOnboardOutputsExecutor = Executors.newSingleThreadExecutor();
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
      else if (clazz.isAssignableFrom(IRadioIntercomOutputProperties.class))
      {
        radioIntercomOutputsPropertyKeyDefinitions.add(clazz);
      }
      else if (clazz.isAssignableFrom(IPAPISVehicleOutputsProperties.class))
      {
        papisVehicleOutputsPropertyKeyDefinitions.add(clazz);
      }
      else if (clazz.isAssignableFrom(IPISBEOutputsProperties.class))
      {
        pisBeOutputsPropertyKeyDefinitions.add(clazz);
      }else if (clazz.isAssignableFrom(ITCMSVehicleOutputsProperties.class))
      {
        tcmsVehicleOutputsPropertyKeyDefinitions.add(clazz);
      }else if (clazz.isAssignableFrom(ICBTCOnboardOutputsProperties.class))
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
    
    commsBinding.getTCMSVehicleOutputsModel().entrySet().forEach(entry -> {
      int vehicleIndex = entry.getKey();
      IPropertyModel propertyModel = entry.getValue();
      if (commsBinding.getTCMSVehicleOutputsModel() != null)
      {
        IListenerManager listenerManager = buildListenerManager(tcmsVehicleOutputsPropertyKeyDefinitions,
            propertyModel, new Pair<>(vehicleIndex, null), IoType.TCMS_VEHICLE_OUTPUTS);
        listenerManagers.add(listenerManager);
      }
    });

    // Listeners for IVehicleProperties
    commsBinding.getVehicleObjectModels().entrySet().forEach(entry -> {
      int vehicleIndex = entry.getKey();
      IPropertyModel propertyModel = entry.getValue();
      if (propertyModel != null)
      {
        listenerManagers.add((buildListenerManager(vehicleObjectPropertyKeyDefinitions, propertyModel,
            new Pair<>(vehicleIndex, null), IoType.VEHICLE)));
      }
    });

    listenerManagers.forEach(IListenerManager::attachToModel);
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
   * Returns a map of {@link IPropertyModel} mapped by vehicleIndex for each
   * Vehicle's Output Model
   *
   * @return a map of model for each Vehicle's Output Model
   */
  public synchronized Map<Integer, IPropertyModel> getVehicleModels()
  {
    return commsBinding.getVehicleObjectModels();
  }

  /**
   * Returns the instance of {@link IPropertyModel} of Output Model for the
   * specified <code>vehicleIndex</code>
   *
   * @param vehicleIndex
   *          vehicle index
   *
   * @return IPropertyModel model
   */
  public IPropertyModel getVehicleModels(int vehicleIndex)
  {
    return getVehicleModels().get(vehicleIndex);
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
      if (IoType.VEHICLE == ioType)
      {
        Runnable vehicleUpdatesTask = () -> vehiclePropertyUpdated(key, oldValue, newValue,
            indexPair.getFirst());
        vehicleExecutor.execute(vehicleUpdatesTask);
      }
      else if (IoType.VEHICLE_OUTPUTS == ioType)
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

      else if (IoType.EVENTS == ioType)
      {
        Runnable eventsUpdatesTask = () -> eventsPropertyUpdated(key, oldValue, newValue,
            indexPair.getFirst(), indexPair.getSecond());
        eventUpdatesExecutor.execute(eventsUpdatesTask);
      }
      else if (IoType.RADIO_INTERCOM_OUTPUTS == ioType)
      {
        Runnable radioIntercomUpdatesTask = () -> radioIntercomOutputPropertyUpdated(key, oldValue, newValue,
            indexPair.getFirst());
        radioIntercomUpdatesExecutor.execute(radioIntercomUpdatesTask);
      }
      else if (IoType.PAPIS_VEHICLE_OUTPUTS == ioType)
      {
        Runnable vehicleUpdatesTask = () -> papisVehicleOutputsPropertyUpdated(key, oldValue, newValue,
            indexPair.getFirst());
        papisVehicleOutputsExecutor.execute(vehicleUpdatesTask);
      }
      else if (IoType.PIS_BE_OUTPUTS == ioType)
      {
        Runnable vehicleUpdatesTask = () -> pisBeOutputsPropertyUpdated(key, oldValue, newValue,
            indexPair.getFirst());
        pisBeOutputsExecutor.execute(vehicleUpdatesTask);
      } else if (IoType.TCMS_VEHICLE_OUTPUTS == ioType)
      {
        Runnable vehicleUpdatesTask = () -> tcmsVehicleOutputsPropertyUpdated(key, oldValue, newValue,
            indexPair.getFirst());
        tcmsVehicleOutputsExecutor.execute(vehicleUpdatesTask);
      } else if (IoType.CBTC_ON_BOARD_OUTPUTS == ioType)
      {
        Runnable eventsUpdatesTask = () -> cbtcOnboardOutputsPropertyUpdated(key, oldValue, newValue,
            indexPair.getFirst());
        cbtcOnboardOutputsExecutor.execute(eventsUpdatesTask);
      }
    }

  }

  private enum IoType
  {
    VEHICLE, APP_INPUTS, VEHICLE_OUTPUTS, TRAIN_COMPUTER_VEHICLE_OUTPUTS, TRAIN_COMPUTER_VEHICLE_INPUTS, EVENTS, RADIO_INTERCOM_OUTPUTS, PAPIS_VEHICLE_OUTPUTS, PIS_BE_OUTPUTS,TCMS_VEHICLE_OUTPUTS,CBTC_ON_BOARD_OUTPUTS;
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
      }, 500, TimeUnit.MILLISECONDS);
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

  public void attachRadioIntercomOutputModels()
  {

    commsBinding.getRadioIntercomOutputsModels().entrySet().forEach(entry -> {
      int vehicleIndex = entry.getKey();
      IPropertyModel propertyModel = entry.getValue();
      if (commsBinding.getRadioIntercomOutputsModels() != null)
      {
        IListenerManager listenerManager = buildListenerManager(radioIntercomOutputsPropertyKeyDefinitions,
            propertyModel, new Pair<>(vehicleIndex, null), IoType.RADIO_INTERCOM_OUTPUTS);
        listenerManager.attachToModel();
        listenerManagers.add(listenerManager);
      }
    });

  }

  public IPropertySetter getRadioIntercomInputSetter(int carIndex)
  {
    return commsBinding.getRadioIntercomInputSetters().get(carIndex);
  }

  public IPropertyModel getRadioIntercomOutputsModels(int carIndex)
  {
    return commsBinding.getRadioIntercomOutputsModels().get(carIndex);
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
  
  public IPropertyModel getTCMSVehicleOutputsModel(int vehicleIndex)
  {
    return commsBinding.getTCMSVehicleOutputsModel().get(vehicleIndex);
  }

  public synchronized Map<Integer, IPropertyModel> getTCMSVehicleOutputsModels()
  {
    return commsBinding.getTCMSVehicleOutputsModel();
  }
}
