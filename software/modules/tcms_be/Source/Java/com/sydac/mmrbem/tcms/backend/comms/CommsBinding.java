/*
 * ==================================================================
 *
 * (C) Copyright 2021 Oktal Sydac Pvt Ltd., all rights reserved. This is
 * unpublished proprietary source code of Sydac. The copyright notice above does
 * not evidence any actual or intended publication of such source code.
 * ==================================================================
 */
package com.sydac.mmrbem.tcms.backend.comms;

import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;
import java.util.concurrent.atomic.AtomicBoolean;

import org.springframework.stereotype.Service;

import com.sydac.common.dataobjects.DBScenarioTrain;
import com.sydac.common.febe.backend.IStateObjectsCallback;
import com.sydac.common.febe.backend.StateObjectsCallbackAdapter;
import com.sydac.common.febe.binding.CommsInputBindingBuilder;
import com.sydac.common.febe.binding.CommsOutputBindingBuilder;
import com.sydac.common.febe.binding.FeBeOutputHandlerFactory;
import com.sydac.common.febe.binding.FeBePropertyModelFactory;
import com.sydac.common.febe.binding.FeBePropertyModelFactory.FeBePropertyModelWrapper;
import com.sydac.foundation.IPropertyModel;
import com.sydac.foundation.IPropertySetter;

import com.sydac.mmrbem.tcms.backend.app.IEventsObjectCallback;
import com.sydac.mmrbem.tcms.backend.app.io.handlers.IAppIntercomOutputsHandler;
import com.sydac.mmrbem.tcms.backend.app.io.handlers.IAppOutputsHandler;
import com.sydac.mmrbem.tcms.backend.app.io.models.IAppInputsModel;
import com.sydac.mmrbem.tcms.backend.app.io.models.IEventModel;
import com.sydac.mmrbem.tcms.backend.app.io.models.IOhpOutputsModel;
import com.sydac.mmrbem.tcms.backend.io.IAppInputsHandler;
import com.sydac.mmrbem.tcms.backend.io.IAppOutputHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.io.handlers.ICBTCVehicleInputsHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.io.handlers.ICBTCVehicleInputsProperties;
import com.sydac.mmrbem.tcms.backend.vehicle.io.handlers.ITCMSVehicleInputsHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.io.handlers.IVehicleInputsHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.io.models.IPAPISVehicleOutputsModel;
import com.sydac.mmrbem.tcms.backend.vehicle.io.models.IPISBEOutputsModel;
import com.sydac.mmrbem.tcms.backend.vehicle.io.models.ITCMSVehicleOutputsModel;
import com.sydac.mmrbem.tcms.backend.vehicle.io.models.IVehicleInputsModel;
import com.sydac.mmrbem.tcms.backend.vehicle.io.models.IVehicleModel;
import com.sydac.mmrbem.tcms.backend.vehicle.io.properties.IEventProperties;
import com.sydac.mmrbem.tcms.backend.vehicle.io.properties.IIntercomInputsProperties;
import com.sydac.mmrbem.tcms.backend.vehicle.io.properties.IIntercomOutputsProperties;
import com.sydac.mmrbem.tcms.backend.vehicle.io.properties.IOhpOutputsProperties;
import com.sydac.mmrbem.tcms.backend.vehicle.io.properties.IPAPISVehicleOutputsProperties;
import com.sydac.mmrbem.tcms.backend.vehicle.io.properties.IPISBEInputsProperties;
import com.sydac.mmrbem.tcms.backend.vehicle.io.properties.IPISBEOutputsProperties;
import com.sydac.mmrbem.tcms.backend.vehicle.io.properties.ITCMSVehicleInputsProperties;
import com.sydac.mmrbem.tcms.backend.vehicle.io.properties.ITCMSVehicleOutputsProperties;
import com.sydac.mmrbem.tcms.backend.vehicle.io.properties.IVehicleInputProperties;
import com.sydac.mmrbem.tcms.backend.vehicle.io.properties.IVehicleProperties;
import com.sydac.mmrbem.tcms.common.IEmptyHandler;
import com.sydac.mmrbem.tcms.common.io.properties.IAppInputsProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsProperties;
import com.sydac.simcomms.CObject;
import com.sydac.simcomms.CRaw;
import com.sydac.simcomms.Gateway;
import com.sydac.simcomms.PropertyCallbackBinder;

/**
 * Communicates information between the Comms layer and the application code.
 * <p>
 * Objects of this class should only be used for a single session.
 *
 */

@Service
public class CommsBinding extends StateObjectsCallbackAdapter
    implements IStateObjectsCallback, IAppOutputHandler, IEventsObjectCallback
{
  /** The frequency at which changes are scanned */
  private static final int DEFAULT_FREQUENCY = 20;

  /** The gateway to access comms */
  private Gateway gateway;

  /** Reference to DBScenarioTrain */
  private DBScenarioTrain scenarioTrain;

  /**
   * The active vehicle index. These vehicles will have a Application object
   * created.
   */
  private int activeVehicleIndex;

  /** The application outputs setter. */
  private IPropertySetter appOutputsSetter;

  /** The application inputs model */
  private IPropertyModel appInputsModel;

  /** Flag indicating whether vehicleIOModels were created. */
  private final AtomicBoolean backendIOModelsCreated = new AtomicBoolean(false);

  private final Map<Integer, CObject> vehicleInputsMap = new ConcurrentHashMap<>();

  private final Map<Integer, IPropertySetter> vehicleInputsSetters = new ConcurrentHashMap<>();

  private final Map<Integer, CObject> vehicleObjectMap = new ConcurrentHashMap<>();

  private final Map<Integer, IPropertyModel> vehicleObjectModels = new ConcurrentHashMap<>();

  private final Map<Integer, CObject> tcmsVehicleInputsMap = new ConcurrentHashMap<>();

  private final Map<Integer, CObject> tcmsVehicleOutputsMap = new ConcurrentHashMap<>();

  private final Map<Integer, IPropertyModel> tcmsVehicleOutputsModels = new ConcurrentHashMap<>();

  private final Map<Integer, IPropertySetter> tcmsVehicleInputSetters = new ConcurrentHashMap<>();

  private final Map<Integer, CObject> pisBeInputsMap = new ConcurrentHashMap<>();

  private final Map<Integer, CObject> pisBeOutputsMap = new ConcurrentHashMap<>();

  private final Map<Integer, IPropertyModel> pisBeOutputsModels = new ConcurrentHashMap<>();

  private final Map<Integer, IPropertySetter> pisBeInputSetters = new ConcurrentHashMap<>();

  private final Map<Integer, CObject> papisVehicleOutputsMap = new ConcurrentHashMap<>();

  private final Map<Integer, IPropertyModel> papisVehicleOutputsModels = new ConcurrentHashMap<>();

  private final Map<Integer, Map<Integer, CObject>> vehicleEventsMap = new ConcurrentHashMap<>();

  private IPropertySetter appInputsSetter;

  private final Map<Integer, Map<Integer, IPropertyModel>> vehicleCrewMessageModels = new ConcurrentHashMap<>();
  private final Map<Integer, CObject> cbtcVehicleInputsMap = new ConcurrentHashMap<>();
  private final Map<Integer, IPropertySetter> cbtcVehicleInputSetters = new ConcurrentHashMap<>();
  
  private final Map<Integer, IPropertyModel> vehicleInputsModels = new ConcurrentHashMap<>();
  
  
  /**
   * The TCMS Backend Inputs map. Regardless of the number of instances of
   * {@link CommsBinding} , requires only one instance of TCMSBackendInputs
   */
  private final Map<Integer, CObject> ohpOutputsMap = new ConcurrentHashMap<>();

  /**
   * Mapping vehicle index with map of indexed ohp output models for that
   * vehicle. Regardless of the number of instances of {@link CommsBinding} ,
   * requires only one instance of respective models of events list
   */
  private final Map<Integer, IPropertyModel> ohpOutputsModels = new ConcurrentHashMap<>();
  
  private   IPropertyModel ohpOutputsModel;

  private final Map<Integer, IPropertySetter> ohpInputSetters = new ConcurrentHashMap<>();

  /** The application outputs setter. */
  private IPropertySetter intercomOutputsSetter;

  /**
   * The TCMS Backend Inputs map. Regardless of the number of instances of
   * {@link CommsBinding} , requires only one instance of TCMSBackendInputs
   */
  private final Map<Integer, CObject> intercomOutputsMap = new ConcurrentHashMap<>();

  /**
   * Mapping vehicle index with map of indexed intercom output models for that
   * vehicle. Regardless of the number of instances of {@link CommsBinding} ,
   * requires only one instance of respective models of events list
   */
  private final Map<Integer, IPropertyModel> intercomOutputsModels = new ConcurrentHashMap<>();
  
  
  /**
   * Mapping vehicle index with map of indexed event models for that vehicle.
   * Regardless of the number of instances of {@link CommsBinding} , requires
   * only one instance of respective models of events list
   */
  private final Map<Integer, Map<Integer, IPropertyModel>> vehicleEventsModels = new ConcurrentHashMap<>();

  public Map<Integer, Map<Integer, IPropertyModel>> getVehicleCrewMessageModels()
  {
    return vehicleCrewMessageModels;
  }

  public CommsBinding()
  {
    // No Need to do any thing here
  }

  public void initialize(Gateway aGateway, DBScenarioTrain aTrain, int aVehicleIndex)
  {
    this.gateway = aGateway;
    this.scenarioTrain = aTrain;
    this.activeVehicleIndex = aVehicleIndex;
  }

  @Override
  public void onApplicationInputsObjectCreation(CObject aApplicationInputsObject)
  {
    // Accessor for ApplicationInputs.
    // Mutator is not needed for ApplicationInputs. so passing an empty
    // interface.

    FeBePropertyModelWrapper<IEmptyHandler, IAppInputsModel> appInputsModelWrapper = FeBePropertyModelFactory
        .createWithInterfaces(IAppInputsProperties.class, IEmptyHandler.class, IAppInputsModel.class);
    appInputsModel = appInputsModelWrapper.asManageableModel();
    appInputsModel.create();
    PropertyCallbackBinder binder = new CommsInputBindingBuilder(aApplicationInputsObject,
        IAppInputsProperties.class, appInputsModelWrapper.asHandler())
            .setRawConverter(byte[].class, CRaw::getValue).build();
    binder.bind(DEFAULT_FREQUENCY, true);

    appInputsSetter = FeBeOutputHandlerFactory.createWithInterfaces(
        new CommsOutputBindingBuilder(gateway, aApplicationInputsObject, IAppInputsProperties.class)
            .setRawConverter(byte[].class, (byte[] b) -> b).build(),
        IAppInputsProperties.class, IAppInputsHandler.class);
  }

  @Override
  public void onApplicationOutputsObjectCreation(CObject aApplicationOutputsObject)
  {

    // Mutator for ApplicationOutputs.
    appOutputsSetter = FeBeOutputHandlerFactory.createWithInterfaces(
        new CommsOutputBindingBuilder(gateway, aApplicationOutputsObject, IAppOutputsProperties.class)
            .setRawConverter(byte[].class, (byte[] b) -> b).build(),
        IAppOutputsProperties.class, IAppOutputsHandler.class);

    // ApplicationVehicleOutputs and ApplicationVehicleInputs.
    // Only one set of OutputsModels and InputsSetters are enough.
    if (!backendIOModelsCreated.getAndSet(true))
    {
      tcmsVehicleOutputsMap.entrySet().forEach(entry -> {

        // Accessor for ApplicationVehicleOutputs
        // Mutator is not needed for ApplicationVehicleOutputs. so passing an
        // empty interface..
        int vehicleIndex = entry.getKey();
        CObject aVehicleOutputsObject = entry.getValue();
        FeBePropertyModelWrapper<IEmptyHandler, ITCMSVehicleOutputsModel> vehicleOutputsModelWrapper = FeBePropertyModelFactory
            .createWithInterfaces(ITCMSVehicleOutputsProperties.class, IEmptyHandler.class,
                ITCMSVehicleOutputsModel.class);
        IPropertyModel vehicleOutputsModel = vehicleOutputsModelWrapper.asManageableModel();
        vehicleOutputsModel.create();
        tcmsVehicleOutputsModels.put(vehicleIndex, vehicleOutputsModel);

        CommsInputBindingBuilder bindingBuilder = new CommsInputBindingBuilder(aVehicleOutputsObject,
            ITCMSVehicleOutputsProperties.class, vehicleOutputsModelWrapper.asHandler());
        bindingBuilder.setRawConverter(byte[].class, CRaw::getValue);
        PropertyCallbackBinder binder = bindingBuilder.build();
        binder.bind(DEFAULT_FREQUENCY, true);
      });

      tcmsVehicleInputsMap.entrySet().forEach(entry -> {
        // Mutator for ApplicationVehicleInputs
        int vehicleIndex = entry.getKey();
        CObject aVehicleInputsObject = tcmsVehicleInputsMap.get(vehicleIndex);
        IPropertySetter vehicleInputsSetter = FeBeOutputHandlerFactory.createWithInterfaces(
            new CommsOutputBindingBuilder(gateway, aVehicleInputsObject, ITCMSVehicleInputsProperties.class)
                .setRawConverter(byte[].class, (byte[] b) -> b).build(),
            ITCMSVehicleInputsProperties.class, ITCMSVehicleInputsHandler.class);
        tcmsVehicleInputSetters.put(vehicleIndex, vehicleInputsSetter);
      });

      pisBeOutputsMap.entrySet().forEach(entry -> {

        // Accessor for ApplicationVehicleOutputs
        // Mutator is not needed for ApplicationVehicleOutputs. so passing an
        // empty interface..
        int vehicleIndex = entry.getKey();
        CObject aVehicleOutputsObject = entry.getValue();
        FeBePropertyModelWrapper<IEmptyHandler, IPISBEOutputsModel> vehicleOutputsModelWrapper = FeBePropertyModelFactory
            .createWithInterfaces(IPISBEOutputsProperties.class, IEmptyHandler.class,
                IPISBEOutputsModel.class);
        IPropertyModel vehicleOutputsModel = vehicleOutputsModelWrapper.asManageableModel();
        vehicleOutputsModel.create();
        pisBeOutputsModels.put(vehicleIndex, vehicleOutputsModel);

        CommsInputBindingBuilder bindingBuilder = new CommsInputBindingBuilder(aVehicleOutputsObject,
            IPISBEOutputsProperties.class, vehicleOutputsModelWrapper.asHandler());
        bindingBuilder.setRawConverter(byte[].class, CRaw::getValue);
        PropertyCallbackBinder binder = bindingBuilder.build();
        binder.bind(DEFAULT_FREQUENCY, true);
      });

      pisBeInputsMap.entrySet().forEach(entry -> {
        // Mutator for ApplicationVehicleInputs
        int vehicleIndex = entry.getKey();
        CObject aVehicleInputsObject = pisBeInputsMap.get(vehicleIndex);
        IPropertySetter vehicleInputsSetter = FeBeOutputHandlerFactory.createWithInterfaces(
            new CommsOutputBindingBuilder(gateway, aVehicleInputsObject, IPISBEInputsProperties.class)
                .setRawConverter(byte[].class, (byte[] b) -> b).build(),
            IPISBEInputsProperties.class, IVehicleInputsHandler.class);
        pisBeInputSetters.put(vehicleIndex, vehicleInputsSetter);
      });

      papisVehicleOutputsMap.entrySet().forEach(entry -> {

        // Accessor for ApplicationVehicleOutputs
        // Mutator is not needed for ApplicationVehicleOutputs. so passing an
        // empty interface..
        int vehicleIndex = entry.getKey();
        CObject aVehicleOutputsObject = entry.getValue();
        FeBePropertyModelWrapper<IEmptyHandler, IPAPISVehicleOutputsModel> vehicleOutputsModelWrapper = FeBePropertyModelFactory
            .createWithInterfaces(IPAPISVehicleOutputsProperties.class, IEmptyHandler.class,
                IPAPISVehicleOutputsModel.class);
        IPropertyModel vehicleOutputsModel = vehicleOutputsModelWrapper.asManageableModel();
        vehicleOutputsModel.create();
        papisVehicleOutputsModels.put(vehicleIndex, vehicleOutputsModel);

        CommsInputBindingBuilder bindingBuilder = new CommsInputBindingBuilder(aVehicleOutputsObject,
            IPAPISVehicleOutputsProperties.class, vehicleOutputsModelWrapper.asHandler());
        bindingBuilder.setRawConverter(byte[].class, CRaw::getValue);
        PropertyCallbackBinder binder = bindingBuilder.build();
        binder.bind(DEFAULT_FREQUENCY, true);
      });
      
      cbtcVehicleInputsMap.entrySet().forEach(entry -> {
        // Mutator for ApplicationVehicleInputs
        int vehicleIndex = entry.getKey();
        CObject aVehicleInputsObject = cbtcVehicleInputsMap.get(vehicleIndex);
        IPropertySetter vehicleInputsSetter = FeBeOutputHandlerFactory.createWithInterfaces(
            new CommsOutputBindingBuilder(gateway, aVehicleInputsObject, ICBTCVehicleInputsProperties.class)
                .setRawConverter(byte[].class, (byte[] b) -> b).build(),
                ICBTCVehicleInputsProperties.class, ICBTCVehicleInputsHandler.class);
        cbtcVehicleInputSetters.put(vehicleIndex, vehicleInputsSetter);
      });

      vehicleInputsMap.entrySet().forEach(entry -> {

        // Accessor for ApplicationVehicleOutputs
        // Mutator is not needed for ApplicationVehicleOutputs. so passing an
        // empty interface..
        int vehicleIndex = entry.getKey();
        CObject aVehicleOutputsObject = entry.getValue();
        FeBePropertyModelWrapper<IEmptyHandler, IVehicleInputsModel> vehicleOutputsModelWrapper = FeBePropertyModelFactory
            .createWithInterfaces(IVehicleInputProperties.class, IEmptyHandler.class,
                IVehicleInputsModel.class);
        IPropertyModel vehicleOutputsModel = vehicleOutputsModelWrapper.asManageableModel();
        vehicleOutputsModel.create();
        vehicleInputsModels.put(vehicleIndex, vehicleOutputsModel);

        CommsInputBindingBuilder bindingBuilder = new CommsInputBindingBuilder(aVehicleOutputsObject,
            IVehicleInputProperties.class, vehicleOutputsModelWrapper.asHandler());
        bindingBuilder.setRawConverter(byte[].class, CRaw::getValue);
        PropertyCallbackBinder binder = bindingBuilder.build();
        binder.bind(DEFAULT_FREQUENCY, true);
      });
      
    }
  }

  @Override
  public void onVehicleEventObjectCreation(CObject eventObject, int aVehicleIndex, int index)
  {
    FeBePropertyModelWrapper<IEmptyHandler, IEventModel> eventModelWrapper = FeBePropertyModelFactory
        .createWithInterfaces(IEventProperties.class, IEmptyHandler.class, IEventModel.class);
    IPropertyModel eventModel = eventModelWrapper.asManageableModel();
    eventModel.create();
    PropertyCallbackBinder binder = new CommsInputBindingBuilder(eventObject, IEventProperties.class,
        eventModelWrapper.asHandler()).setRawConverter(byte[].class, CRaw::getValue).build();
    binder.bind(DEFAULT_FREQUENCY, true);
    Map<Integer, IPropertyModel> indexedEvents = vehicleEventsModels.computeIfAbsent(aVehicleIndex,
        k -> new ConcurrentHashMap<>());
    indexedEvents.put(index, eventModel);
  }

  @Override
  public void onVehicleObjectCreation(CObject aVehicleObject, int aVehicleIndex)
  {
    FeBePropertyModelWrapper<IEmptyHandler, IVehicleModel> vehicleOutputsModelWrapper = FeBePropertyModelFactory
        .createWithInterfaces(IVehicleProperties.class, IEmptyHandler.class, IVehicleModel.class);
    IPropertyModel vehicleModel = vehicleOutputsModelWrapper.asManageableModel();
    vehicleModel.create();
    vehicleObjectModels.put(aVehicleIndex, vehicleModel);

    CommsInputBindingBuilder bindingBuilder = new CommsInputBindingBuilder(aVehicleObject,
        IVehicleProperties.class, vehicleOutputsModelWrapper.asHandler());
    PropertyCallbackBinder binder = bindingBuilder.build();
    binder.bind(DEFAULT_FREQUENCY, true);
  }

  @Override
  public void onVehicleObjectDestruction(int aVehicleIndex)
  {
    // It may be called more than once with same <code>aVehicleIndex</code>.
    if (aVehicleIndex == activeVehicleIndex)
    {
      appOutputsSetter = null;
      appInputsModel.destroy();
      appInputsModel = null;
      appInputsSetter = null;
    }

    vehicleInputsSetters.remove(aVehicleIndex);
    vehicleInputsMap.remove(aVehicleIndex);
    tcmsVehicleOutputsMap.remove(aVehicleIndex);
   
    tcmsVehicleInputSetters.remove(aVehicleIndex);
    pisBeOutputsMap.remove(aVehicleIndex);
    pisBeInputSetters.remove(aVehicleIndex);
    papisVehicleOutputsMap.remove(aVehicleIndex);
    cbtcVehicleInputSetters.remove(aVehicleIndex);
    vehicleEventsModels.computeIfPresent(aVehicleIndex, (k, v) -> {
      synchronized (v)
      {
        v.values().forEach(IPropertyModel::destroy);
      }
      v.clear();
      return null;
    });

    vehicleEventsMap.computeIfPresent(aVehicleIndex, (k, v) -> {
      v.clear();
      return null;
    });
    
    ohpOutputsMap.forEach((k, v) -> {
      synchronized (v)
      {
        v.destroy();
      }
    });
    ohpOutputsModels.forEach((k, v) -> {
      synchronized (v)
      {
        v.destroy();
      }

    });
    intercomOutputsMap.forEach((k, v) -> {
      synchronized (v)
      {
        v.destroy();
      }
    });
    ohpOutputsMap.clear();
    ohpOutputsModels.clear();
    intercomOutputsMap.clear();
  }

  @Override
  public void onTrainObjectDestruction()
  {
    vehicleInputsSetters.clear();
    vehicleInputsMap.clear();
    tcmsVehicleOutputsModels.clear();
    backendIOModelsCreated.set(false);
    tcmsVehicleInputSetters.clear();
    pisBeOutputsModels.clear();
    pisBeInputSetters.clear();
    papisVehicleOutputsModels.clear();
    vehicleEventsMap.clear();
    vehicleEventsModels.clear();
    cbtcVehicleInputSetters.clear();
    ohpOutputsMap.clear();
    ohpOutputsModels.clear();
    intercomOutputsMap.clear();
  }

  @Override
  public void setVehicleOutputs(CObject object, int carindex)
  {
    // It may be called more than once with same <code>aVehicleIndex</code>.
  }

  @Override
  public void setVehicleInputs(CObject object, int carindex)
  {
    // It may be called more than once with same <code>aVehicleIndex</code>.
    vehicleInputsMap.put(carindex, object);
  }

  /**
   * Returns a map of {@link IPropertySetter} mapped to vehicleIndex for each
   * vehicle's Input Setter
   *
   * @return a map of property setters for each vehicle's Input Setter
   */
  public Map<Integer, IPropertySetter> getVehicleInputsSetters()
  {
    return vehicleInputsSetters;
  }

  public Map<Integer, IPropertySetter> getTCMSVehicleInputsSetters()
  {
    return tcmsVehicleInputSetters;
  }

  public Map<Integer, IPropertySetter> getPISBEInputsSetters()
  {
    return pisBeInputSetters;
  }

  /**
   * Returns a {@link IPropertyModel} representing ApplicationInputs
   *
   * @return The model representing ApplicationInputs
   */
  public IPropertyModel getAppInputsModel()
  {
    return appInputsModel;
  }

  /**
   * Returns a {@link IPropertySetter} for ApplicationOutputs
   *
   * @return The property setter for ApplicationOutputs
   */
  public IPropertySetter getAppOutputsSetter()
  {
    return this.appOutputsSetter;
  }

  public IPropertySetter getAppInputsSetter()
  {
    return this.appInputsSetter;
  }

  /**
   * @return the activeVehicleIndex
   */
  public int getActiveVehicleIndex()
  {
    return activeVehicleIndex;
  }

  public IPropertyModel getTCMSVehicleOutputsModel(int vehicleIndex)
  {

    return tcmsVehicleOutputsModels.get(vehicleIndex);
  }

  public Map<Integer, IPropertyModel> getTCMSVehicleOutputsModel()
  {
    return tcmsVehicleOutputsModels;
  }

  public IPropertyModel getPISBEOutputsModel(int vehicleIndex)
  {

    return pisBeOutputsModels.get(vehicleIndex);
  }

  public Map<Integer, IPropertyModel> getPISBEOutputsModel()
  {
    return pisBeOutputsModels;
  }

  @Override
  public void setVehicleObject(CObject aVehicleObject, int aVehicleIndex)
  {
    vehicleObjectMap.put(aVehicleIndex, aVehicleObject);
  }

  public Map<Integer, CObject> getVehicleObjectMap()
  {
    return vehicleObjectMap;
  }

  public Map<Integer, IPropertyModel> getVehicleObjectModels()
  {
    return vehicleObjectModels;
  }

  public DBScenarioTrain getScenarioTrain()
  {
    return scenarioTrain;
  }

  public void setTCMSVehicleInputs(CObject object, int vehicleIndex)
  {
    tcmsVehicleInputsMap.put(vehicleIndex, object);

  }

  public void setTCMSVehicleOutputs(CObject object, int vehicleIndex)
  {
    tcmsVehicleOutputsMap.put(vehicleIndex, object);

  }

  public IPropertyModel getTCMSVehicleOutputsModels(int vehicleIndex)
  {
    return tcmsVehicleOutputsModels.get(vehicleIndex);
  }

  public void setPISBEInputs(CObject object, int vehicleIndex)
  {
    pisBeInputsMap.put(vehicleIndex, object);
  }

  public void setPISBEOutputs(CObject object, int vehicleIndex)
  {
    pisBeOutputsMap.put(vehicleIndex, object);

  }

  public void setPAPISVehicleOutputs(CObject vehicleChild, int aVehicleIndex)
  {
    papisVehicleOutputsMap.put(aVehicleIndex, vehicleChild);
  }

  public Map<Integer, IPropertyModel> getPAPISVehicleOutputsModel()
  {
    return papisVehicleOutputsModels;
  }

  /**
   * Accessor for <code>vehicleEventsmodels</code>
   *
   * @return the vehicleEventsmodels
   */
  public Map<Integer, Map<Integer, IPropertyModel>> getVehicleEventsModels()
  {
    return vehicleEventsModels;
  }

  public void setCbtcVehicleInputs(CObject object, int vehicleIndex)
  {
    cbtcVehicleInputsMap.put(vehicleIndex, object);

  }
  
  public Map<Integer, IPropertySetter> getCBTCVehicleInputsSetters()
  {
    return cbtcVehicleInputSetters;
  }
  
  public IPropertyModel getVehicleInputsModel(int vehicleIndex)
  {
    return vehicleInputsModels.get(vehicleIndex);
  }
  
  public Map<Integer, IPropertyModel> getVehicleInputsModel()
  {
    return vehicleInputsModels;
  }
  
  public void bindOHPOutPuts()
  {
    ohpOutputsMap.entrySet().forEach(entry -> {
      int index = entry.getKey();

      if (ohpOutputsModels.get(index) == null)
      {
        CObject ohpOutputsObject = ohpOutputsMap.get(index);

        FeBePropertyModelWrapper<IEmptyHandler, IOhpOutputsModel> ohpOutputsModelWrapper = FeBePropertyModelFactory
            .createWithInterfaces(IOhpOutputsProperties.class, IEmptyHandler.class, IOhpOutputsModel.class);
        ohpOutputsModel = ohpOutputsModelWrapper.asManageableModel();
        ohpOutputsModel.create();
        PropertyCallbackBinder binder = new CommsInputBindingBuilder(ohpOutputsObject,
            IOhpOutputsProperties.class, ohpOutputsModelWrapper.asHandler())
                .setRawConverter(byte[].class, CRaw::getValue).build();
        binder.bind(DEFAULT_FREQUENCY, true);
        ohpOutputsModels.put(index, ohpOutputsModel);
      }
    });

  }

  public void setOHPOutPutsMap(int ohpIndex, CObject onpOutputs)
  {
    ohpOutputsMap.put(ohpIndex, onpOutputs);

  }

  public Map<Integer, IPropertyModel> getOhpOutputsModels()
  {
    return ohpOutputsModels;
  }
  
  public IPropertyModel getOhpOutputsModel()
  {
    return ohpOutputsModel;
  }

  public Map<Integer, IPropertySetter> getOHPInputsSetters()
  {
    return ohpInputSetters;
  }

  public void setIntercomInputs(CObject ohpInput)
  {
    intercomOutputsSetter = FeBeOutputHandlerFactory.createWithInterfaces(
        new CommsOutputBindingBuilder(gateway, ohpInput, IIntercomInputsProperties.class)
            .setRawConverter(byte[].class, (byte[] b) -> b).build(),
        IIntercomInputsProperties.class, IAppIntercomOutputsHandler.class);

  }

  public IPropertySetter getOhpOutputsSetter()
  {
    return intercomOutputsSetter;
  }

  public void setIntercomOutPutsMap(int id, CObject intercomChild)
  {
    intercomOutputsMap.put(id, intercomChild);

  }

  public void bindIntercomOutputs()
  {
    intercomOutputsMap.entrySet().forEach(entry -> {
      int index = entry.getKey();

      if (intercomOutputsModels.get(index) == null)
      {
        CObject ohpOutputsObject = intercomOutputsMap.get(index);

        FeBePropertyModelWrapper<IEmptyHandler, IOhpOutputsModel> intercomOutputsModelWrapper = FeBePropertyModelFactory
            .createWithInterfaces(IIntercomOutputsProperties.class, IEmptyHandler.class,
                IOhpOutputsModel.class);
        IPropertyModel ohpOutputsModel = intercomOutputsModelWrapper.asManageableModel();
        ohpOutputsModel.create();
        PropertyCallbackBinder binder = new CommsInputBindingBuilder(ohpOutputsObject,
            IIntercomOutputsProperties.class, intercomOutputsModelWrapper.asHandler())
                .setRawConverter(byte[].class, CRaw::getValue).build();
        binder.bind(DEFAULT_FREQUENCY, true);
        intercomOutputsModels.put(index, ohpOutputsModel);
      }
    });

  }

  public Map<Integer, IPropertyModel> getIntercomOutputsModels()
  {
    return intercomOutputsModels;
  }

}