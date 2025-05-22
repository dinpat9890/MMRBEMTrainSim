/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.psd.backend.app;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;

import com.sydac.common.dataobjects.DBScenarioTrain;
import com.sydac.common.febe.backend.ApplicationObjectCreator;
import com.sydac.common.febe.backend.IStateObjectsCallback;
import com.sydac.common.febe.backend.IVehicleBackend;
import com.sydac.common.febe.backend.StateObjectsCallbackForwarder;
import com.sydac.common.febe.backend.input.BasicInputInterpreter;
import com.sydac.common.sessiondata.HubData;
import com.sydac.core.runtimedata.ObjectDefinition;
import com.sydac.mmrbem.psd.backend.comms.CommsBinding;
import com.sydac.mmrbem.psd.backend.logic.BusinessLogic;
import com.sydac.mmrbem.psd.backend.logic.DateTimeModel;
import com.sydac.project.runtimedata.ProjectObjectConstants;
import com.sydac.project.runtimedata.ProjectObjectDefinition;
import com.sydac.simcomms.CObject;
import com.sydac.simcomms.Gateway;

/**
 * Manages the PSD classes of a single vehicle's PSD.
 * <p>
 * Lifetime of a single session.
 * 
 */
public class PSDVehicleBackend implements IVehicleBackend
{

  /** The comms binding. */
  @Autowired
  private CommsBinding commsBinding;

  @Autowired
  private BusinessLogic businessLogic;

  @Value("${carIndex}")
  private Integer carIndex;

  @Value("${scenarioTrainId}")
  private Integer scenarioTrainId;

  /** Reference to scenario vehicle object. */
  private CObject scenarioVehicleObject;

  private int vehicleIndex;

  public PSDVehicleBackend()
  {
    super();
  }

  public void initialize(Gateway gateway, DBScenarioTrain aTrain)
  {
    commsBinding.initialize(gateway, aTrain, carIndex);

    ApplicationObjectCreator applicationObjectCreator = startBusinessLogic(gateway,
        aTrain.getScenarioTrainId(), carIndex);
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

    ObjectDefinition appObjectDef = ProjectObjectDefinition
        .getObjectDefinition(ProjectObjectConstants.ClassId.PSD);
    ObjectDefinition appInputsObjectOef = ProjectObjectDefinition
        .getObjectDefinition(ProjectObjectConstants.ClassId.PSD_INPUTS);
    ObjectDefinition appOutputsObjectDef = ProjectObjectDefinition
        .getObjectDefinition(ProjectObjectConstants.ClassId.PSD_OUTPUTS);
    ObjectDefinition appInputsValuesObjectDef = ProjectObjectDefinition
        .getObjectDefinition(ProjectObjectConstants.ClassId.PSD_INPUTS_VALUES);
    ObjectDefinition appInputsModesObjectDef = ProjectObjectDefinition
        .getObjectDefinition(ProjectObjectConstants.ClassId.PSD_INPUTS_MODES);

    // Create objects in Comms
    StateObjectsCallbackForwarder forwarder = createForwarder(carIndex, scenarioTrainId, aGateway);
    BasicInputInterpreter inputInterpreter = new BasicInputInterpreter(appInputsValuesObjectDef);

    return new ApplicationObjectCreator(aGateway, forwarder, inputInterpreter, appObjectDef,
        appInputsObjectOef, appOutputsObjectDef, appInputsValuesObjectDef, appInputsModesObjectDef,
        ProjectObjectConstants.ClassId.VEHICLE_INPUTS, ProjectObjectConstants.ClassId.VEHICLE_OUTPUTS,
        scenarioTrainId, carIndex);
  }

  @SuppressWarnings("all")
  protected BackendStateObjectsCallbackForwarder createForwarder(final int carIndex,
      final int aScenarioTrainId, Gateway aGateway)
  {

    return new BackendStateObjectsCallbackForwarder(new IStateObjectsCallback[] { commsBinding }, carIndex,
        aGateway);
  }

  private class BackendStateObjectsCallbackForwarder extends StateObjectsCallbackForwarder
  {
    private final int carIndex;

    private Gateway aGateway;

    private BackendStateObjectsCallbackForwarder(IStateObjectsCallback[] aReceivers, int carIndex,
        Gateway aGateway)
    {
      super(aReceivers);
      this.carIndex = carIndex;
      this.aGateway = aGateway;
    }

    @Override
    public void onApplicationOutputsObjectCreation(CObject aApplicationOutputsObject)
    {

      super.onApplicationOutputsObjectCreation(aApplicationOutputsObject);
      // Once outputs are ready we can start the business logic
      businessLogic.init();
      businessLogic.attachListener();
      // Creates ProxyAudioController(for announcements)
      HubData hubData = new HubData();
      hubData.setScenarioTrainId(scenarioTrainId);

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
        if (vehicleChild.getName().equals(ProjectObjectConstants.ClassName.CBTC_PLATFORM_INPUTS))
        {
          commsBinding.setCBTCPlatformInputs(vehicleChild, vehicleIndex);
          commsBinding.bindCBTCPlatformInputs();
        }
        else if (vehicleChild.getName().equals(ProjectObjectConstants.ClassName.CBTC_PLATFORM_OUTPUTS))
        {
          commsBinding.setCBTCPlatformOutputs(vehicleChild, vehicleIndex);
          commsBinding.bindCBTCPlatformOutputs();
          businessLogic.attchCbtcPlatformOutputsToModels();
        }
        if (vehicleChild.getName().equals(ProjectObjectConstants.ClassName.CBTC_ONBOARD_OUTPUTS))
        {
          commsBinding.setCBTCOnboardOutputs(vehicleChild, vehicleIndex);
          commsBinding.bindCBTConboardOutputs();
          businessLogic.attchCbtcOnboardOutputsToModels();
        }
        
        if (vehicleChild.getName().equals(ProjectObjectConstants.ClassName.PIS_BE))
        {
          vehicleChild.addCreationCallback(vehicleChildInput -> {
            if (vehicleChildInput.getName().equals(ProjectObjectConstants.ClassName.PIS_BE_OUTPUTS))
            {
              commsBinding.setPISBEOutputs(vehicleChildInput, vehicleIndex);
              commsBinding.bindPISBEOutputs();
              businessLogic.attchPiSToModels();
            }
          });
        }
        
      });

    }

    @Override
    public void onVehicleObjectCreation(CObject aVehicleObject, int aVehicleIndex)
    {
      super.onVehicleObjectCreation(aVehicleObject, aVehicleIndex);

      commsBinding.setVehicleObject(aVehicleObject, aVehicleIndex);

      aVehicleObject.addCreationCallback(vehicleChild -> {
        if (vehicleChild.getName().equals(ProjectObjectConstants.ClassName.VEHICLE_INPUTS))
        {
          commsBinding.setVehicleInputs(vehicleChild, aVehicleIndex);
        }
        else if (vehicleChild.getName().equals(ProjectObjectConstants.ClassName.VEHICLE_OUTPUTS))
        {
          commsBinding.setVehicleOutputs(vehicleChild, aVehicleIndex);
        }
     
      });

      if (aVehicleIndex == carIndex)
      {
        scenarioVehicleObject = aVehicleObject;
        vehicleIndex = aVehicleIndex;
      }
    }

    @Override
    public void onVehicleObjectDestruction(int aVehicleIndex)
    {
      super.onVehicleObjectDestruction(aVehicleIndex);
      if (carIndex == aVehicleIndex)
      {
        businessLogic.detachListeners();
      }
    }

    // To Do: adding for test purpose
    @Override
    public void onTrainObjectCreation(CObject object)
    {
      /* TODO document why this method is empty */
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

  }
}
