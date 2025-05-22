/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.radio.backend.app;

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
import com.sydac.mmrbem.radio.backend.comms.CommsBinding;
import com.sydac.mmrbem.radio.backend.logic.BusinessLogic;
import com.sydac.mmrbem.radio.backend.logic.DateTimeModel;
import com.sydac.project.runtimedata.ProjectObjectConstants;
import com.sydac.project.runtimedata.ProjectObjectDefinition;
import com.sydac.simcomms.CObject;
import com.sydac.simcomms.Gateway;

/**
 * Manages the TCMS classes of a single vehicle's TCMS.
 * <p>
 * Lifetime of a single session.
 * 
 */
public class RadioVehicleBackend implements IVehicleBackend
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

  private int vehicleIndex;

  /** Reference to scenario vehicle object. */
  private CObject scenrioVehicleObject;

  /** Reference to scenario train object. */
  private CObject scenrioTrainObject;

  public RadioVehicleBackend()
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
  private ApplicationObjectCreator startBusinessLogic(Gateway aGateway, int scenarioTrainId,
      final int carIndex)
  {

    ObjectDefinition appObjectDef = ProjectObjectDefinition
        .getObjectDefinition(ProjectObjectConstants.ClassId.RADIO);
    ObjectDefinition appInputsObjectOef = ProjectObjectDefinition
        .getObjectDefinition(ProjectObjectConstants.ClassId.RADIO_INPUTS);
    ObjectDefinition appOutputsObjectDef = ProjectObjectDefinition
        .getObjectDefinition(ProjectObjectConstants.ClassId.RADIO_OUTPUTS);
    ObjectDefinition appInputsValuesObjectDef = ProjectObjectDefinition
        .getObjectDefinition(ProjectObjectConstants.ClassId.RADIO_INPUTS_VALUES);
    ObjectDefinition appInputsModesObjectDef = ProjectObjectDefinition
        .getObjectDefinition(ProjectObjectConstants.ClassId.RADIO_INPUTS_MODES);

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

      scenrioTrainObject.addCreationCallback(vehicleChild -> {
        if (vehicleChild.getName().equals(ProjectObjectConstants.ClassName.RADIO_INTERCOM))
        {
          vehicleChild.addCreationCallback(radioIntercomChild -> {
            if (radioIntercomChild.getName()
                .equals(ProjectObjectConstants.ClassName.RADIO_INTERCOM_INPUTS_VALUES))
            {

              commsBinding.setRadioIntercomInputValues(radioIntercomChild, vehicleIndex);
              commsBinding.bindRadioIntercomInputValues();

            }
            else if (radioIntercomChild.getName()
                .equals(ProjectObjectConstants.ClassName.RADIO_INTERCOM_OUTPUTS))
            {
              commsBinding.setRadioIntercomOutputs(radioIntercomChild, vehicleIndex);
              commsBinding.bindRadioIntercomOutputs();
              businessLogic.attachRadioIntercomOutputModels();
            }

          });
        }
      });

      scenrioVehicleObject.addCreationCallback(vehicleChild -> {
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
      scenrioVehicleObject.addCreationCallback(vehicleChild -> {
        if (vehicleChild.getName().equals(ProjectObjectConstants.ClassName.CBTC_ONBOARD_OUTPUTS))
        {
          commsBinding.setCBTCOnboardOutputs(vehicleChild, vehicleIndex);
          commsBinding.bindCBTConboardOutputs();
          businessLogic.attchCbtcOnboardOutputsToModels();
        }
      });
      
     
    }

    @Override
    public void onVehicleObjectCreation(CObject aVehicleObject, int aVehicleIndex)
    {
      super.onVehicleObjectCreation(aVehicleObject, aVehicleIndex);
      commsBinding.setVehicleObject(aVehicleObject, aVehicleIndex);
      if (aVehicleIndex == carIndex)
      {
        scenrioVehicleObject = aVehicleObject;
        vehicleIndex = aVehicleIndex;
      }

      aVehicleObject.addCreationCallback(vehicleChild -> {
        if (vehicleChild.getName().equals(ProjectObjectConstants.ClassName.VEHICLE_INPUTS))
        {
          commsBinding.setVehicleInputs(vehicleChild, aVehicleIndex);
        }
        else if (vehicleChild.getName().equals(ProjectObjectConstants.ClassName.VEHICLE_OUTPUTS))
        {
          commsBinding.setVehicleOutputs(vehicleChild, aVehicleIndex);
        }
        else if (vehicleChild.getName().equals(ProjectObjectConstants.ClassName.PAPIS_VEHICLE_OUTPUTS))
        {
          commsBinding.setPAPISVehicleOutputs(vehicleChild, aVehicleIndex);
        }
        else if (vehicleChild.getName().equals(ProjectObjectConstants.ClassName.PIS_BE))
        {
          vehicleChild.addCreationCallback(vehicleChildInput -> {
            if (vehicleChildInput.getName().equals(ProjectObjectConstants.ClassName.PIS_BE_OUTPUTS))
            {
              commsBinding.setPISBEOutputs(vehicleChildInput, vehicleIndex);
              commsBinding.bindPISBEOutputs();
              businessLogic.attchPiSToModels();
            }
          });
        } else if (vehicleChild.getName().equals(ProjectObjectConstants.ClassName.TCMS_VEHICLE_OUTPUTS))
        {
          commsBinding.setTCMSVehicleOutputs(vehicleChild, aVehicleIndex);
        }
        else if (vehicleChild.getName().equals(ProjectObjectConstants.ClassName.CBTC_ONBOARD_OUTPUTS))
        {
          
          commsBinding.setCBTCOnboardOutputs(vehicleChild, vehicleIndex);
         commsBinding.bindCBTConboardOutputs();
          businessLogic.attchCbtcOnboardOutputsToModels();
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

    @Override
    public void onTrainObjectCreation(CObject object)
    {
      super.onTrainObjectCreation(object);
      scenrioTrainObject = object;
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
    // sharedModel.destroy();
  }
}
