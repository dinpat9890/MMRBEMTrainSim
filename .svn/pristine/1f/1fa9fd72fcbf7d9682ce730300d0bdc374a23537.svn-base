/*******************************************************************************
 * (C) Copyright 2020 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.dmi.backend.app;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;

import com.sydac.common.dataobjects.DBScenarioTrain;
import com.sydac.common.febe.backend.ApplicationObjectCreator;
import com.sydac.common.febe.backend.IStateObjectsCallback;
import com.sydac.common.febe.backend.IVehicleBackend;
import com.sydac.common.febe.backend.StateObjectsCallbackForwarder;
import com.sydac.common.febe.backend.input.BasicInputInterpreter;
import com.sydac.common.registry.Registry;
import com.sydac.core.runtimedata.ObjectDefinition;
import com.sydac.mmrbem.dmi.backend.comms.CommsBinding;
import com.sydac.mmrbem.dmi.backend.logic.BusinessLogic;
import com.sydac.mmrbem.dmi.backend.logic.DateTimeModel;
import com.sydac.mmrbem.dmi.backend.logic.SharedDataModel;
import com.sydac.mmrbem.dmi.common.state.ApplicationConstants;
import com.sydac.project.runtimedata.ProjectObjectConstants;
import com.sydac.project.runtimedata.ProjectObjectDefinition;
import com.sydac.simcomms.CObject;
import com.sydac.simcomms.Gateway;

/**
 * Manages the DMI classes of a single vehicle's DMI.
 * <p>
 * Lifetime of a single session.
 * 
 */
public class DMIVehicleBackend implements IVehicleBackend
{

  private ApplicationObjectCreator applicationObjectCreator;

  /** The comms binding. */
  @Autowired
  private CommsBinding commsBinding;

  @Autowired
  private BusinessLogic businessLogic;

  /** Reference to scenario vehicle object. */
  private CObject scenarioVehicleObject;

  @Value("${carIndex}")
  private Integer carIndex;

  @Value("${scenarioTrainId}")
  private Integer scenarioTrainId;

  /** The shared model. */
  @Autowired
  private SharedDataModel sharedModel;

  private int vehicleIndex;

  public DMIVehicleBackend()
  {
    super();
  }

  public void initialize(Gateway gateway, DBScenarioTrain aTrain)
  {
    sharedModel.create();
    commsBinding.initialize(gateway, aTrain, carIndex);

    String serviceNumber = String.valueOf(aTrain.getTrainId());

    if (serviceNumber == null || (ApplicationConstants.BLANK).equals(serviceNumber.trim()))
    {
      serviceNumber = Registry.getInstance().getString(ApplicationConstants.DOMAIN_NAME,
          ApplicationConstants.SERVICE_NUMBER);
    }

    String softwareVersion = Registry.getInstance().getString(ApplicationConstants.DOMAIN_NAME,
        ApplicationConstants.SOFTWARE_VERSION);

    sharedModel.setServiceNumber(serviceNumber);
    sharedModel.setSoftwareVersion(softwareVersion);
    applicationObjectCreator = startBusinessLogic(gateway, scenarioTrainId, carIndex);
    applicationObjectCreator.start();
  }

  /**
   * Start business logic.
   *
   * @param aGateway
   *          the a gateway
   * @param scenarioTrainId
   *          the scenario train id
   * @param carIndex
   *          the car index
   * @return the application object creator
   */
  @SuppressWarnings("deprecation")
  private ApplicationObjectCreator startBusinessLogic(Gateway aGateway, int scenarioTrainId,
      final int carIndex)
  {
    ObjectDefinition dmiObjectDef = ProjectObjectDefinition
        .getObjectDefinition(ProjectObjectConstants.ClassId.DMI);
    ObjectDefinition dmiInputsObjectOef = ProjectObjectDefinition
        .getObjectDefinition(ProjectObjectConstants.ClassId.DMI_INPUTS);
    ObjectDefinition dmiOutputsObjectDef = ProjectObjectDefinition
        .getObjectDefinition(ProjectObjectConstants.ClassId.DMI_OUTPUTS);
    ObjectDefinition dmiInputsValuesObjectDef = ProjectObjectDefinition
        .getObjectDefinition(ProjectObjectConstants.ClassId.DMI_INPUTS_VALUES);
    ObjectDefinition dmiInputsModesObjectDef = ProjectObjectDefinition
        .getObjectDefinition(ProjectObjectConstants.ClassId.DMI_INPUTS_MODES);

    // Create objects in Comms
    StateObjectsCallbackForwarder forwarder = createForwarder(carIndex, scenarioTrainId);
    BasicInputInterpreter inputInterpreter = new BasicInputInterpreter(dmiInputsValuesObjectDef);

    return new ApplicationObjectCreator(aGateway, forwarder, inputInterpreter, dmiObjectDef,
        dmiInputsObjectOef, dmiOutputsObjectDef, dmiInputsValuesObjectDef, dmiInputsModesObjectDef,
        ProjectObjectConstants.ClassId.CBTC_ONBOARD_INPUTS,
        ProjectObjectConstants.ClassId.CBTC_ONBOARD_OUTPUTS, scenarioTrainId, carIndex);
  }

  @SuppressWarnings("all")
  protected BackendStateObjeectsCallbackForwarder createForwarder(final int carIndex,
      final int aScenarioTrainId)
  {
    return new BackendStateObjeectsCallbackForwarder(new IStateObjectsCallback[] { commsBinding }, carIndex);
  }

  private class BackendStateObjeectsCallbackForwarder extends StateObjectsCallbackForwarder
  {
    private final int carIndex;

    private BackendStateObjeectsCallbackForwarder(IStateObjectsCallback[] aReceivers, int carIndex)
    {
      super(aReceivers);
      this.carIndex = carIndex;
    }

    @Override
    public void onApplicationOutputsObjectCreation(CObject aApplicationOutputsObject)
    {

      super.onApplicationOutputsObjectCreation(aApplicationOutputsObject);
      // Once outputs are ready we can start the business logic
      businessLogic.init();
      businessLogic.attachListener();

      /**
       * Below code is work around to bind the CBTC onboard and platform data
       * with application as Vehicle is not responsible for creating this CBTC
       * onboard objects, CBTC Unit and CBTC On board is responsible for
       * creating the objects under Vehicle. The sequence in which the objects
       * are added under vehicle is not consistent, also the CBTC application or
       * DMI application can be restarted at any point during the scenario, to
       * make sure the binding happens when the objects are created we have
       * added below work around.
       */
      scenarioVehicleObject.addCreationCallback(vehicleChild -> {
        if (vehicleChild.getName().equals(ProjectObjectConstants.ClassName.CBTC_ONBOARD_INPUTS))
        {
          commsBinding.setCBTCOnboardInputs(vehicleChild, vehicleIndex);
          commsBinding.bindCBTCOnboardInputs();
        }
        else if (vehicleChild.getName().equals(ProjectObjectConstants.ClassName.CBTC_ONBOARD_OUTPUTS))
        {
          commsBinding.setCBTCOnboardOutputs(vehicleChild, vehicleIndex);
          commsBinding.bindCBTConboardOutputs();
          businessLogic.attchCbtcOnboardOutputsToModels();
        }
        if (vehicleChild.getName().equals(ProjectObjectConstants.ClassName.CBTC_PLATFORM_OUTPUTS))
        {
          commsBinding.setCBTCPlatformOutputs(vehicleChild, vehicleIndex);
          commsBinding.bindCBTCPlatformOutputs();
          businessLogic.attchCbtcPlatformOutputsToModels();
        }
        if (vehicleChild.getName().equals(ProjectObjectConstants.ClassName.PIS_BE))
        {
          vehicleChild.addCreationCallback(vehicleChildInput -> {
            if (vehicleChildInput.getName().equals(ProjectObjectConstants.ClassName.PIS_BE_OUTPUTS))
            {
              commsBinding.setPISBEOutputs(vehicleChildInput, vehicleIndex);
              commsBinding.bindPisBeOutputs();
              businessLogic.attachPisBeOutputsToModels();
            }
          });
        }
      });
    }

    @Override
    public void onVehicleObjectCreation(CObject aVehicleObject, int aVehicleIndex)
    {
      super.onVehicleObjectCreation(aVehicleObject, aVehicleIndex);

      aVehicleObject.addCreationCallback(vehicleChild -> {

        if (vehicleChild.getName().equals(ProjectObjectConstants.ClassName.DMI_VEHICLE_OUTPUTS))
        {
          commsBinding.setDMIVehicleOutputs(vehicleChild, aVehicleIndex);
        }
        if (aVehicleIndex == carIndex)
        {
          scenarioVehicleObject = aVehicleObject;
          vehicleIndex = aVehicleIndex;
        }
      });
    }

    @Override
    public void onVehicleObjectDestruction(int aVehicleIndex)
    {
      super.onVehicleObjectDestruction(aVehicleIndex);
      if (carIndex == aVehicleIndex)
      {
        businessLogic.detachListeners();
        vehicleIndex = aVehicleIndex;
      }
    }

  }

  @Override
  public void runCycle(long aSimulatedTime)
  {
    // in case it is blown away during this call
    if (businessLogic != null)
    {
      businessLogic.process(aSimulatedTime);
    }
    DateTimeModel.getInstance().setTime(aSimulatedTime);
  }

  @Override
  public void resetSession()
  {
    commsBinding = null;
    businessLogic = null;
    sharedModel.destroy();
  }
}
