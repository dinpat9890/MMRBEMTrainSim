/*******************************************************************************
 * (C) Copyright 2020 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.dmi.backend.comms;

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
import com.sydac.mmrbem.dmi.backend.app.io.handlers.IAppOutputsHandler;
import com.sydac.mmrbem.dmi.backend.app.io.models.IAppInputsModel;
import com.sydac.mmrbem.dmi.backend.io.IOutputHandler;
import com.sydac.mmrbem.dmi.backend.vehicle.io.handlers.ICBTCVehicleInputsHandler;
import com.sydac.mmrbem.dmi.backend.vehicle.io.models.ICBTCOnboardOutputsModel;
import com.sydac.mmrbem.dmi.backend.vehicle.io.models.ICBTCPlatformOutputsModel;
import com.sydac.mmrbem.dmi.backend.vehicle.io.models.IDMIVehicleOutputsModel;
import com.sydac.mmrbem.dmi.backend.vehicle.io.models.IPISBEOutputsModel;
import com.sydac.mmrbem.dmi.backend.vehicle.io.properties.ICBTCOnboardInputsProperties;
import com.sydac.mmrbem.dmi.backend.vehicle.io.properties.ICBTCOnboardOutputsProperties;
import com.sydac.mmrbem.dmi.backend.vehicle.io.properties.ICBTCPlatformOutputsProperties;
import com.sydac.mmrbem.dmi.backend.vehicle.io.properties.IDMIVehicleOutputsStartupScreenProperties;
import com.sydac.mmrbem.dmi.backend.vehicle.io.properties.IPISBEOutputsProperties;
import com.sydac.mmrbem.dmi.common.IEmptyHandler;
import com.sydac.mmrbem.dmi.common.io.properties.IAppInputsProperties;
import com.sydac.mmrbem.dmi.common.io.properties.IAppOutputsProperties;
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
public class CommsBinding extends StateObjectsCallbackAdapter implements IStateObjectsCallback, IOutputHandler
{
  /** The frequency at which changes are scanned */
  private static final int DEFAULT_FREQUENCY = 20;

  /** The gateway to access comms */
  private Gateway gateway;

  /** Reference to DBScenarioTrain */
  private DBScenarioTrain dbScenarioTrain;

  /**
   * The active vehicle index. These vehicles will have a Application object
   * created.
   */
  private int activeVehicleIndex;

  /** The application outputs setter. */
  private IPropertySetter appOutputsSetter;

  /** The application inputs model */
  private IPropertyModel appInputsModel;

  /** The application inputs model */
  private IPropertyModel pisOutputsModel;

  /** Flag indicating whether vehicleIOModels were created. */
  private final AtomicBoolean dmiBackendIOModelsCreated = new AtomicBoolean(false);

  /**
   * The CBTCOnboardInputs map.
   */
  private final Map<Integer, CObject> cbtcOnboardInputsMap = new ConcurrentHashMap<>();

  /**
   * The TMS Backend Inputs model map. Regardless of the number of instances of
   * {@link CommsBinding} , requires only one instance of respective models of
   * TMSBackendInputs
   */
  private final Map<Integer, IPropertyModel> cbtcOnboardOutputsModels = new ConcurrentHashMap<>();

  /**
   * The TMS Backend Inputs map. Regardless of the number of instances of
   * {@link CommsBinding} , requires only one instance of TMSBackendInputs
   */
  private final Map<Integer, CObject> cbtcPlatformOutputsMap = new ConcurrentHashMap<>();

  private final Map<Integer, CObject> cbtcOnboardOutputsMap = new ConcurrentHashMap<>();

  private final Map<Integer, CObject> dmiVehicleOutputsMap = new ConcurrentHashMap<>();

  /**
   * The TMS Backend Inputs model map. Regardless of the number of instances of
   * {@link CommsBinding} , requires only one instance of respective models of
   * TMSBackendInputs
   */
  private final Map<Integer, IPropertyModel> cbtcPlatformOutputsModels = new ConcurrentHashMap<>();

  private final Map<Integer, IPropertyModel> dmiVehicleOutputsModels = new ConcurrentHashMap<>();

  /**
   * The TMS Backend Outputs property setter map. Regardless of the number of
   * instances of {@link CommsBinding} , requires only one instance of
   * respective setters of TMSBackendOutputs
   */
  private final Map<Integer, IPropertySetter> cbtcOnboardInputsSetters = new ConcurrentHashMap<>();

  /**
   * Mapping vehicle index with map of indexed event models for that vehicle.
   * Regardless of the number of instances of {@link CommsBinding} , requires
   * only one instance of respective models of events list
   */
  private final Map<Integer, Map<Integer, IPropertyModel>> vehicleEventsModels = new ConcurrentHashMap<>();

  private final Map<Integer, CObject> pisBeOutputsMap = new ConcurrentHashMap<>();

  private final Map<Integer, IPropertyModel> pisBeOutputsModels = new ConcurrentHashMap<>();

  public CommsBinding()
  {
    // No Need to do any thing here
  }

  public void initialize(Gateway aGateway, DBScenarioTrain aTrain, int aVehicleIndex)
  {
    this.gateway = aGateway;
    this.dbScenarioTrain = aTrain;
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
    if (!dmiBackendIOModelsCreated.getAndSet(true))
    {
      dmiVehicleOutputsMap.entrySet().forEach(entry -> {
        // Accessor for ApplicationVehicleOutputs
        // Mutator is not needed for ApplicationVehicleOutputs. so passing an
        // empty interface..
        int vehicleIndex = entry.getKey();
        CObject aVehicleOutputsObject = entry.getValue();
        FeBePropertyModelWrapper<IEmptyHandler, IDMIVehicleOutputsModel> vehicleOutputsModelWrapper = FeBePropertyModelFactory
            .createWithInterfaces(IDMIVehicleOutputsStartupScreenProperties.class, IEmptyHandler.class,
                IDMIVehicleOutputsModel.class);
        IPropertyModel vehicleOutputsModel = vehicleOutputsModelWrapper.asManageableModel();
        vehicleOutputsModel.create();
        dmiVehicleOutputsModels.put(vehicleIndex, vehicleOutputsModel);
        PropertyCallbackBinder binder = new CommsInputBindingBuilder(aVehicleOutputsObject,
            IDMIVehicleOutputsStartupScreenProperties.class, vehicleOutputsModelWrapper.asHandler())
                .setRawConverter(byte[].class, CRaw::getValue).build();
        binder.bind(DEFAULT_FREQUENCY, true);
      });
    }
  }

  public void bindPisBeOutputs()
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
      pisBeOutputsModels.put(vehicleIndex, vehicleOutputsModel);

      PropertyCallbackBinder binder = new CommsInputBindingBuilder(aVehicleOutputsObject,
          IPISBEOutputsProperties.class, vehicleOutputsModelWrapper.asHandler())
              .setRawConverter(byte[].class, CRaw::getValue).build();
      binder.bind(DEFAULT_FREQUENCY, true);
      pisBeOutputsModels.put(vehicleIndex, vehicleOutputsModel);
    });

  }

  /**
   * @return the dmivehicleoutputsmodels
   */
  public Map<Integer, IPropertyModel> getDmivehicleoutputsmodels()
  {
    return dmiVehicleOutputsModels;
  }

  public IPropertyModel getVehicleOutputModel(int vehicleIndex)
  {

    return dmiVehicleOutputsModels.get(vehicleIndex);
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
  public Map<Integer, IPropertyModel> getCbtconboardoutputsmodels()
  {
    return cbtcOnboardOutputsModels;
  }

  public void bindCBTCOnboardInputs()
  {
    cbtcOnboardInputsMap.entrySet().forEach(entry -> {
      // Mutator for ApplicationVehicleInputs
      int vehicleIndex = entry.getKey();
      CObject aVehicleInputsObject = cbtcOnboardInputsMap.get(vehicleIndex);
      IPropertySetter vehicleInputsSetter = FeBeOutputHandlerFactory.createWithInterfaces(
          new CommsOutputBindingBuilder(gateway, aVehicleInputsObject, ICBTCOnboardInputsProperties.class)
              .setRawConverter(byte[].class, (byte[] b) -> b).build(),
          ICBTCOnboardInputsProperties.class, ICBTCVehicleInputsHandler.class);
      cbtcOnboardInputsSetters.put(vehicleIndex, vehicleInputsSetter);
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
    }
    cbtcOnboardOutputsModels.computeIfPresent(aVehicleIndex, (k, v) -> {
      v.destroy();
      return null;
    });
    cbtcPlatformOutputsModels.computeIfPresent(aVehicleIndex, (k, v) -> {
      v.destroy();
      return null;
    });
    dmiVehicleOutputsModels.computeIfPresent(aVehicleIndex, (k, v) -> {
      v.destroy();
      return null;
    });
    cbtcOnboardOutputsMap.remove(aVehicleIndex);
    cbtcOnboardInputsSetters.remove(aVehicleIndex);
    cbtcPlatformOutputsMap.remove(aVehicleIndex);
    cbtcOnboardInputsMap.remove(aVehicleIndex);

    vehicleEventsModels.computeIfPresent(aVehicleIndex, (k, v) -> {
      synchronized (v)
      {
        v.values().forEach(IPropertyModel::destroy);
      }
      v.clear();
      return null;
    });
    /*
     * vehicleEventsMap.computeIfPresent(aVehicleIndex, (k, v) -> { v.clear();
     * return null; });
     */
  }

  @Override
  public void onTrainObjectDestruction()
  {
    cbtcOnboardInputsSetters.clear();
    cbtcOnboardOutputsMap.clear();
    dmiVehicleOutputsMap.clear();
    cbtcPlatformOutputsMap.clear();
    cbtcOnboardInputsMap.clear();
    vehicleEventsModels.clear();
    pisBeOutputsModels.clear();
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
   * CBTCOnboardOutputs object
   * 
   * @return a map of model for each Vehicle
   */
  public Map<Integer, IPropertyModel> getCbtcOnboardOutputsModels()
  {
    return cbtcOnboardOutputsModels;
  }

  /**
   * Returns a map of {@link IPropertySetter} mapped by vehicleIndex for each
   * CBTCOnboardInputs object
   * 
   * @return a map of setter for each Vehicle
   */
  public Map<Integer, IPropertySetter> getCbtcOnboardInputsSetters()
  {
    return cbtcOnboardInputsSetters;
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

  public Map<Integer, IPropertyModel> getDmiVehicleOutputsModels()
  {
    return dmiVehicleOutputsModels;
  }

  /**
   * @return the activeVehicleIndex
   */
  public int getActiveVehicleIndex()
  {
    return activeVehicleIndex;
  }

  /**
   * Accessor for <code>dbScenarioTrain</code>
   *
   * @return the dbScenarioTrain
   */
  public DBScenarioTrain getDbScenarioTrain()
  {
    return dbScenarioTrain;
  }

  @Override
  public void setCBTCOnboardOutputs(CObject object, int carindex)
  {
    cbtcOnboardOutputsMap.put(carindex, object);
  }

  @Override
  public void setCBTCOnboardInputs(CObject object, int carindex)
  {
    cbtcOnboardInputsMap.put(carindex, object);
  }

  @Override
  public void setCBTCPlatformOutputs(CObject object, int carindex)
  {
    cbtcPlatformOutputsMap.put(carindex, object);
  }

  @Override
  public void setDMIVehicleOutputs(CObject object, int carindex)
  {
    dmiVehicleOutputsMap.put(carindex, object);
  }

  /**
   * Returns a {@link IPropertyModel} representing PISOutputs.
   * 
   * @return The model representing PISOutputs.
   */
  public IPropertyModel getPisOutputsModel()
  {
    return pisOutputsModel;
  }

  @Override
  public void setPISOutputs(CObject object)
  {
    // TODO Auto-generated method stub

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
}
