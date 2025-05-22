/*
 * ==================================================================
 *
 * (C) Copyright 2021 Oktal Sydac Pvt Ltd., all rights reserved. This is
 * unpublished proprietary source code of Sydac. The copyright notice above does
 * not evidence any actual or intended publication of such source code.
 * ==================================================================
 */
package com.sydac.mmrbem.psd.backend.comms;

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
import com.sydac.mmrbem.psd.backend.app.io.handlers.IAppOutputsHandler;
import com.sydac.mmrbem.psd.backend.app.io.models.IAppInputsModel;
import com.sydac.mmrbem.psd.backend.io.IAppInputsHandler;
import com.sydac.mmrbem.psd.backend.io.IAppOutputHandler;
import com.sydac.mmrbem.psd.backend.vehicle.io.handlers.ICBTCVehicleInputsHandler;
import com.sydac.mmrbem.psd.backend.vehicle.io.models.ICBTCOnboardOutputsModel;
import com.sydac.mmrbem.psd.backend.vehicle.io.models.ICBTCPlatformOutputsModel;
import com.sydac.mmrbem.psd.backend.vehicle.io.models.IPISBEOutputsModel;
import com.sydac.mmrbem.psd.backend.vehicle.io.properties.ICBTCOnboardOutputsProperties;
import com.sydac.mmrbem.psd.backend.vehicle.io.properties.ICBTCPlatformInputsProperties;
import com.sydac.mmrbem.psd.backend.vehicle.io.properties.ICBTCPlatformOutputsProperties;
import com.sydac.mmrbem.psd.backend.vehicle.io.properties.IPISBEOutputsProperties;
import com.sydac.mmrbem.psd.common.IEmptyHandler;
import com.sydac.mmrbem.psd.common.io.properties.IAppInputsProperties;
import com.sydac.mmrbem.psd.common.io.properties.IAppOutputsProperties;
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
    implements IStateObjectsCallback, IAppOutputHandler
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

  private final Map<Integer, CObject> psdVehicleInputsMap = new ConcurrentHashMap<>();

  private final Map<Integer, CObject> psdVehicleOutputsMap = new ConcurrentHashMap<>();

  private final Map<Integer, IPropertyModel> psdVehicleOutputsModels = new ConcurrentHashMap<>();

  private IPropertySetter appInputsSetter;

  private final Map<Integer, CObject> cbtcPlatformOutputsMap = new ConcurrentHashMap<>();

  private final Map<Integer, IPropertyModel> cbtcPlatformOutputsModels = new ConcurrentHashMap<>();

  private final Map<Integer, CObject> pisBeOutputsMap = new ConcurrentHashMap<>();

  private final Map<Integer, IPropertyModel> pisBeOutputsModels = new ConcurrentHashMap<>();

  private final Map<Integer, CObject> cbtcPlatformInputsMap = new ConcurrentHashMap<>();

  private final Map<Integer, IPropertySetter> cbtcPlatformInputsSetters = new ConcurrentHashMap<>();
  private final Map<Integer, CObject> cbtcOnboardOutputsMap = new ConcurrentHashMap<>();
  private final Map<Integer, IPropertyModel> cbtcOnboardOutputsModels = new ConcurrentHashMap<>();
  /**
   * Mapping vehicle index with map of indexed event models for that vehicle.
   * Regardless of the number of instances of {@link CommsBinding} , requires
   * only one instance of respective models of events list
   */
  private final Map<Integer, Map<Integer, IPropertyModel>> vehicleEventsModels = new ConcurrentHashMap<>();

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
     

    }
  }

  public void bindPISBEOutputs()
  {
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
     

      CommsInputBindingBuilder bindingBuilder = new CommsInputBindingBuilder(aVehicleOutputsObject,
          IPISBEOutputsProperties.class, vehicleOutputsModelWrapper.asHandler());
      bindingBuilder.setRawConverter(byte[].class, CRaw::getValue);
      PropertyCallbackBinder binder = bindingBuilder.build();
      binder.bind(DEFAULT_FREQUENCY, true);
      pisBeOutputsModels.put(vehicleIndex, vehicleOutputsModel);
    });
  }

  
  
  public void bindCBTCPlatformInputs()
  {
    cbtcPlatformInputsMap.entrySet().forEach(entry -> {
      // Mutator for ApplicationVehicleInputs
      int vehicleIndex = entry.getKey();
      CObject aVehicleInputsObject = cbtcPlatformInputsMap.get(vehicleIndex);
      IPropertySetter vehicleInputsSetter = FeBeOutputHandlerFactory.createWithInterfaces(
          new CommsOutputBindingBuilder(gateway, aVehicleInputsObject, ICBTCPlatformInputsProperties.class)
              .setRawConverter(byte[].class, (byte[] b) -> b).build(),
          ICBTCPlatformInputsProperties.class, ICBTCVehicleInputsHandler.class);
      cbtcPlatformInputsSetters.put(vehicleIndex, vehicleInputsSetter);
    });
  }

  public void bindCBTCPlatformOutputs()
  {
    cbtcPlatformOutputsMap.entrySet().forEach(entry -> {
      // Accessor for ApplicationVehicleOutputs
      // Mutator is not needed for ApplicationVehicleOutputs. so passing an
      // empty interface..
      int vehicleIndex = entry.getKey();
      CObject aVehicleOutputsObject = entry.getValue();
      FeBePropertyModelWrapper<IEmptyHandler, ICBTCPlatformOutputsModel> vehicleOutputsModelWrapper = FeBePropertyModelFactory
          .createWithInterfaces(ICBTCPlatformOutputsProperties.class, IEmptyHandler.class,
              ICBTCPlatformOutputsModel.class);
      IPropertyModel vehicleOutputsModel = vehicleOutputsModelWrapper.asManageableModel();
      vehicleOutputsModel.create();
      cbtcPlatformOutputsModels.put(vehicleIndex, vehicleOutputsModel);

      CommsInputBindingBuilder bindingBuilder = new CommsInputBindingBuilder(aVehicleOutputsObject,
          ICBTCPlatformOutputsProperties.class, vehicleOutputsModelWrapper.asHandler());
      bindingBuilder.setRawConverter(byte[].class, CRaw::getValue);
      PropertyCallbackBinder binder = bindingBuilder.build();
      binder.bind(DEFAULT_FREQUENCY, true);
    });
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
    psdVehicleOutputsMap.remove(aVehicleIndex);
    pisBeOutputsMap.remove(aVehicleIndex);
    cbtcPlatformInputsMap.remove(aVehicleIndex);
    vehicleEventsModels.computeIfPresent(aVehicleIndex, (k, v) -> {
      synchronized (v)
      {
        v.values().forEach(IPropertyModel::destroy);
      }
      v.clear();
      return null;
    });
    cbtcPlatformOutputsModels.computeIfPresent(aVehicleIndex, (k, v) -> {
      v.destroy();
      return null;
    });
    cbtcOnboardOutputsModels.computeIfPresent(aVehicleIndex, (k, v) -> {
      v.destroy();
      return null;
    });
    cbtcPlatformOutputsMap.remove(aVehicleIndex);
  }

  @Override
  public void onTrainObjectDestruction()
  {
    vehicleInputsSetters.clear();
    vehicleInputsMap.clear();
    psdVehicleOutputsModels.clear();
    backendIOModelsCreated.set(false);
    pisBeOutputsModels.clear();
    cbtcPlatformOutputsMap.clear();
    cbtcPlatformInputsMap.clear();
    cbtcOnboardOutputsMap.clear();
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

  public IPropertyModel getPSDVehicleOutputsModel(int vehicleIndex)
  {

    return psdVehicleOutputsModels.get(vehicleIndex);
  }

  public Map<Integer, IPropertyModel> getPSDVehicleOutputsModel()
  {
    return psdVehicleOutputsModels;
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

  @Override
  public void setCBTCPlatformOutputs(CObject object, int carindex)
  {
    cbtcPlatformOutputsMap.put(carindex, object);
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

  /**
   * Returns a map of {@link IPropertyModel} mapped by vehicleIndex for each
   * CBTCPlatformOutputs object
   * 
   * @return a map of model for each Vehicle
   */
  public Map<Integer, IPropertyModel> getCbtcPlatformOutputsModels()
  {
    return cbtcPlatformOutputsModels;
  }

  public void setPISBEOutputs(CObject object, int vehicleIndex)
  {
    pisBeOutputsMap.put(vehicleIndex, object);

  }

  public IPropertyModel getPISBEOutputsModel(int vehicleIndex)
  {

    return pisBeOutputsModels.get(vehicleIndex);
  }

  public Map<Integer, IPropertyModel> getPISBEOutputsModel()
  {
    return pisBeOutputsModels;
  }

  public Map<Integer, IPropertySetter> getCbtcPlatforInputputsSetters()
  {
    return cbtcPlatformInputsSetters;
  }

  @Override
  public void setCBTCPlatformInputs(CObject object, int carindex)
  {
    cbtcPlatformInputsMap.put(carindex, object);    
  }

  public void setCBTCOnboardOutputs(CObject object, int carindex)
  {
    cbtcOnboardOutputsMap.put(carindex, object);
  }

  public void bindCBTConboardOutputs()
  {

    cbtcOnboardOutputsMap.entrySet().forEach(entry -> {

      // Accessor for ApplicationVehicleOutputs
      // Mutator is not needed for ApplicationVehicleOutputs. so passing an
      // empty interface..
      int vehicleIndex = entry.getKey();
      CObject aVehicleOutputsObject = entry.getValue();
      FeBePropertyModelWrapper<IEmptyHandler, ICBTCOnboardOutputsModel> vehicleOutputsModelWrapper = FeBePropertyModelFactory
          .createWithInterfaces(ICBTCOnboardOutputsProperties.class, IEmptyHandler.class,
              ICBTCOnboardOutputsModel.class);
      IPropertyModel vehicleOutputsModel = vehicleOutputsModelWrapper.asManageableModel();
      vehicleOutputsModel.create();

      cbtcOnboardOutputsModels.put(vehicleIndex, vehicleOutputsModel);

      CommsInputBindingBuilder bindingBuilder = new CommsInputBindingBuilder(aVehicleOutputsObject,
          ICBTCOnboardOutputsProperties.class, vehicleOutputsModelWrapper.asHandler());
      bindingBuilder.setRawConverter(byte[].class, CRaw::getValue);
      PropertyCallbackBinder binder = bindingBuilder.build();
      binder.bind(DEFAULT_FREQUENCY, true);
    });
  }

  public IPropertyModel getCbtcOutputModel(int vehicleIndex)
  {

    return cbtcOnboardOutputsModels.get(vehicleIndex);
  }

  /**
   * @return the cbtconboardoutputsmodels
   */
  
  public Map<Integer, IPropertyModel> getCbtcOnboardOutputsModels()
  {
    return cbtcOnboardOutputsModels;
  }
}