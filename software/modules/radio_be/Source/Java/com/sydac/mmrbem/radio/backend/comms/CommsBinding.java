/*
 * ==================================================================
 *
 * (C) Copyright 2022 Oktal Sydac Pvt Ltd., all rights reserved. This is
 * unpublished proprietary source code of Sydac. The copyright notice above does
 * not evidence any actual or intended publication of such source code.
 * ==================================================================
 */
package com.sydac.mmrbem.radio.backend.comms;

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

import com.sydac.mmrbem.radio.backend.app.IEventsObjectCallback;
import com.sydac.mmrbem.radio.backend.app.io.handlers.IAppOutputsHandler;
import com.sydac.mmrbem.radio.backend.app.io.models.IAppInputsModel;
import com.sydac.mmrbem.radio.backend.io.IAppInputsHandler;
import com.sydac.mmrbem.radio.backend.io.IAppOutputHandler;
import com.sydac.mmrbem.radio.backend.radiointercom.handlers.IRadioIntercomInputsHandler;
import com.sydac.mmrbem.radio.backend.radiointercom.io.models.IRadioIntercomOutputsModel;
import com.sydac.mmrbem.radio.backend.radiointercom.io.models.IVehicleModel;
import com.sydac.mmrbem.radio.backend.radiointercom.properties.IRadioIntercomInputProperties;
import com.sydac.mmrbem.radio.backend.radiointercom.properties.IRadioIntercomOutputProperties;
import com.sydac.mmrbem.radio.backend.vehicle.io.models.ICBTCOnboardOutputsModel;
import com.sydac.mmrbem.radio.backend.vehicle.io.models.IPAPISVehicleOutputsModel;
import com.sydac.mmrbem.radio.backend.vehicle.io.models.IPISBEOutputsModel;
import com.sydac.mmrbem.radio.backend.vehicle.io.models.ITCMSVehicleOutputsModel;
import com.sydac.mmrbem.radio.backend.vehicle.io.models.properties.ICBTCOnboardOutputsProperties;
import com.sydac.mmrbem.radio.backend.vehicle.io.models.properties.IPAPISVehicleOutputsProperties;
import com.sydac.mmrbem.radio.backend.vehicle.io.models.properties.IPISBEOutputsProperties;
import com.sydac.mmrbem.radio.backend.vehicle.io.models.properties.ITCMSVehicleOutputsProperties;
import com.sydac.mmrbem.radio.common.IEmptyHandler;
import com.sydac.mmrbem.radio.common.io.properties.IAppInputsProperties;
import com.sydac.mmrbem.radio.common.io.properties.IAppOutputsProperties;
import com.sydac.mmrbem.radio.common.io.properties.IVehicleProperties;

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

  private final Map<Integer, CObject> papisVehicleOutputsMap = new ConcurrentHashMap<>();

  private final Map<Integer, IPropertySetter> vehicleInputsSetters = new ConcurrentHashMap<>();

  private final Map<Integer, CObject> vehicleObjectMap = new ConcurrentHashMap<>();

  private final Map<Integer, IPropertySetter> vehicleSetters = new ConcurrentHashMap<>();

  private final Map<Integer, IPropertyModel> vehicleObjectModels = new ConcurrentHashMap<>();

  private final Map<Integer, CObject> radioIntercomInputValuesMap = new ConcurrentHashMap<>();

  private final Map<Integer, CObject> radioIntercomOutputsMap = new ConcurrentHashMap<>();

  private final Map<Integer, IPropertyModel> radioIntercomOutputsModels = new ConcurrentHashMap<>();

  private final Map<Integer, IPropertySetter> radioIntercomInputSetters = new ConcurrentHashMap<>();

  private final Map<Integer, IPropertyModel> papisVehicleOutputsModels = new ConcurrentHashMap<>();

  private final Map<Integer, CObject> pisBeOutputsMap = new ConcurrentHashMap<>();

  private final Map<Integer, IPropertyModel> pisBeOutputsModels = new ConcurrentHashMap<>();
  
  private final Map<Integer, CObject> cbtcOnboardOutputsMap = new ConcurrentHashMap<>();
  
  private final Map<Integer, IPropertyModel> cbtcOnboardOutputsModels = new ConcurrentHashMap<>();

  private IPropertySetter appInputsSetter;

  private final Map<Integer, Map<Integer, IPropertyModel>> vehicleCrewMessageModels = new ConcurrentHashMap<>();
  
  private final Map<Integer, CObject> tcmsVehicleOutputsMap = new ConcurrentHashMap<>();

  private final Map<Integer, IPropertyModel> tcmsVehicleOutputsModels = new ConcurrentHashMap<>();

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
    }
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
    cbtcOnboardOutputsModels.computeIfPresent(aVehicleIndex, (k, v) -> {
      v.destroy();
      return null;
    });
    radioIntercomOutputsMap.computeIfPresent(aVehicleIndex, (k, v) -> {
      v.destroy();
      return null;
    });

    papisVehicleOutputsModels.computeIfPresent(aVehicleIndex, (k, v) -> {
      v.destroy();
      return null;
    });
    cbtcOnboardOutputsMap.remove(aVehicleIndex);
    vehicleSetters.remove(aVehicleIndex);
    vehicleInputsSetters.remove(aVehicleIndex);
    vehicleInputsMap.remove(aVehicleIndex);
    papisVehicleOutputsMap.remove(aVehicleIndex);
    radioIntercomInputSetters.remove(aVehicleIndex);
    radioIntercomInputValuesMap.remove(aVehicleIndex);
    pisBeOutputsMap.remove(aVehicleIndex);
    tcmsVehicleOutputsMap.remove(aVehicleIndex);
  }

  @Override
  public void onTrainObjectDestruction()
  {
    cbtcOnboardOutputsMap.clear();
    vehicleSetters.clear();
    vehicleInputsSetters.clear();
    vehicleInputsMap.clear();
    papisVehicleOutputsMap.clear();
    pisBeOutputsModels.clear();
    backendIOModelsCreated.set(false);
    radioIntercomInputSetters.clear();
    radioIntercomInputValuesMap.clear();
    radioIntercomOutputsMap.clear();
    radioIntercomOutputsModels.clear();
    papisVehicleOutputsModels.clear();
    tcmsVehicleOutputsModels.clear();
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

  public void setPAPISVehicleOutputs(CObject vehicleChild, int aVehicleIndex)
  {
    papisVehicleOutputsMap.put(aVehicleIndex, vehicleChild);
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

  public Map<Integer, IPropertySetter> getVehicleSetter()
  {
    return this.vehicleSetters;
  }

  public DBScenarioTrain getScenarioTrain()
  {
    return scenarioTrain;
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

  public void setRadioIntercomInputValues(CObject radioIntercomChild, int vehicleIndex)
  {
    radioIntercomInputValuesMap.put(vehicleIndex, radioIntercomChild);
  }

  public void bindRadioIntercomInputValues()
  {

    radioIntercomInputValuesMap.entrySet().forEach(entry -> {
      // Mutator for ApplicationVehicleInputs
      int vehicleIndex = entry.getKey();
      if (radioIntercomInputSetters.get(vehicleIndex) == null)
      {
        CObject aVehicleInputsObject = radioIntercomInputValuesMap.get(vehicleIndex);
        IPropertySetter radioInputsSetter = FeBeOutputHandlerFactory.createWithInterfaces(
            new CommsOutputBindingBuilder(gateway, aVehicleInputsObject, IRadioIntercomInputProperties.class)
                .setRawConverter(byte[].class, (byte[] b) -> b).build(),
            IRadioIntercomInputProperties.class, IRadioIntercomInputsHandler.class);
        radioIntercomInputSetters.put(vehicleIndex, radioInputsSetter);
      }
    });

  }

  public void setRadioIntercomOutputs(CObject radioIntercomChild, int vehicleIndex)
  {
    radioIntercomOutputsMap.put(vehicleIndex, radioIntercomChild);
  }

  public void bindRadioIntercomOutputs()
  {
    radioIntercomOutputsMap.entrySet().forEach(entry -> {
      // Accessor for ApplicationVehicleOutputs
      // Mutator is not needed for ApplicationVehicleOutputs. so passing an
      // empty interface..
      int vehicleIndex = entry.getKey();
      if (radioIntercomOutputsModels.get(vehicleIndex) == null)
      {
        CObject aVehicleOutputsObject = entry.getValue();
        FeBePropertyModelWrapper<IEmptyHandler, IRadioIntercomOutputsModel> radioOutputsModelWrapper = FeBePropertyModelFactory
            .createWithInterfaces(IRadioIntercomOutputProperties.class, IEmptyHandler.class,
                IRadioIntercomOutputsModel.class);
        IPropertyModel vehicleOutputsModel = radioOutputsModelWrapper.asManageableModel();
        vehicleOutputsModel.create();
        radioIntercomOutputsModels.put(vehicleIndex, vehicleOutputsModel);

        CommsInputBindingBuilder bindingBuilder = new CommsInputBindingBuilder(aVehicleOutputsObject,
            IRadioIntercomOutputProperties.class, radioOutputsModelWrapper.asHandler());
        bindingBuilder.setRawConverter(byte[].class, CRaw::getValue);
        PropertyCallbackBinder binder = bindingBuilder.build();
        binder.bind(DEFAULT_FREQUENCY, true);
      }
    });

  }

  public Map<Integer, IPropertyModel> getRadioIntercomOutputsModels()
  {
    return radioIntercomOutputsModels;
  }

  public Map<Integer, IPropertySetter> getRadioIntercomInputSetters()
  {
    return radioIntercomInputSetters;
  }

  public Map<Integer, IPropertyModel> getPAPISVehicleOutputsModel()
  {
    return papisVehicleOutputsModels;
  }

  public void setPISBEOutputs(CObject object, int vehicleIndex)
  {
    pisBeOutputsMap.put(vehicleIndex, object);
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
          .createWithInterfaces(IPISBEOutputsProperties.class, IEmptyHandler.class, IPISBEOutputsModel.class);
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

  public IPropertyModel getPISBEOutputsModel(int vehicleIndex)
  {
    return pisBeOutputsModels.get(vehicleIndex);
  }

  public Map<Integer, IPropertyModel> getPISBEOutputsModel()
  {
    return pisBeOutputsModels;
  }

  @Override
  public void onVehicleEventObjectCreation(CObject eventObject, int aVehicleIndex, int index)
  {
    // No Events linked.
  }
  
  public IPropertyModel getTCMSVehicleOutputsModel(int vehicleIndex)
  {

    return tcmsVehicleOutputsModels.get(vehicleIndex);
  }

  public Map<Integer, IPropertyModel> getTCMSVehicleOutputsModel()
  {
    return tcmsVehicleOutputsModels;
  }
  public void setTCMSVehicleOutputs(CObject object, int vehicleIndex)
  {
    tcmsVehicleOutputsMap.put(vehicleIndex, object);

  }
  
  public IPropertyModel getTCMSVehicleOutputsModels(int vehicleIndex)
  {
    return tcmsVehicleOutputsModels.get(vehicleIndex);
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

  
  public void setCBTCOnboardOutputs(CObject object, int carindex)
  {
    cbtcOnboardOutputsMap.put(carindex, object);
  }

  public Map<Integer, IPropertyModel> getCbtcOnboardOutputsModels()
  {
    return cbtcOnboardOutputsModels;
  }
 

  public IPropertyModel getCbtcOutputModel(int vehicleIndex)
  {

    return cbtcOnboardOutputsModels.get(vehicleIndex);
  }
}