/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.backend.app;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;

import com.sydac.common.dataobjects.DBScenarioTrain;
import com.sydac.common.febe.backend.ApplicationObjectCreator;
import com.sydac.common.febe.backend.IStateObjectsCallback;
import com.sydac.common.febe.backend.IVehicleBackend;
import com.sydac.common.febe.backend.StateObjectsCallbackForwarder;
import com.sydac.common.febe.backend.input.BasicInputInterpreter;
import com.sydac.common.registry.Registry;
import com.sydac.common.sessiondata.HubData;
import com.sydac.core.runtimedata.ObjectDefinition;
import com.sydac.mmrbem.tcms.backend.comms.CommsBinding;
import com.sydac.mmrbem.tcms.backend.logic.BusinessLogic;
import com.sydac.mmrbem.tcms.backend.logic.DateTimeModel;
import com.sydac.mmrbem.tcms.backend.logic.SharedDataModel;
import com.sydac.mmrbem.tcms.common.state.ApplicationConstants;
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
public class TCMSVehicleBackend implements IVehicleBackend
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

  private TrainConfigurationHandler trainConfigurationHandler;

  @Autowired
  private SharedDataModel sharedModel;
  
  /** Reference to scenario Train object. */
  private CObject scenrioTrainObject;

  public TCMSVehicleBackend()
  {
    super();
  }

  public void initialize(Gateway gateway, DBScenarioTrain aTrain)
  {
    sharedModel.create();

    commsBinding.initialize(gateway, aTrain, carIndex);

    trainConfigurationHandler = new TrainConfigurationHandler(gateway, aTrain, sharedModel);

    int standByScreenTime = Registry.getInstance().getInteger(ApplicationConstants.DOMAIN_NAME,
        ApplicationConstants.STAND_BY_SCREEN_TIME, 5);

    sharedModel.setTotalVehicles(aTrain.getTrain().getElements().getCount());
    sharedModel.setTrainName(aTrain.getScenarioTrainName());
    sharedModel.setStandByScreenTime(standByScreenTime);

    EventsObjectMonitor eventsObjectMonitor = createEventsObjectMonitor(gateway, aTrain.getScenarioTrainId());
    eventsObjectMonitor.start();

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
        .getObjectDefinition(ProjectObjectConstants.ClassId.VDU);
    ObjectDefinition appInputsObjectOef = ProjectObjectDefinition
        .getObjectDefinition(ProjectObjectConstants.ClassId.VDU_INPUTS);
    ObjectDefinition appOutputsObjectDef = ProjectObjectDefinition
        .getObjectDefinition(ProjectObjectConstants.ClassId.VDU_OUTPUTS);
    ObjectDefinition appInputsValuesObjectDef = ProjectObjectDefinition
        .getObjectDefinition(ProjectObjectConstants.ClassId.VDU_INPUTS_VALUES);
    ObjectDefinition appInputsModesObjectDef = ProjectObjectDefinition
        .getObjectDefinition(ProjectObjectConstants.ClassId.VDU_INPUTS_MODES);

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

    return new BackendStateObjectsCallbackForwarder(
        new IStateObjectsCallback[] { commsBinding, trainConfigurationHandler }, carIndex, aGateway);
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

      
      scenrioTrainObject.addCreationCallback(trainChild -> {
        if (trainChild.getName().equals(ProjectObjectConstants.ClassName.INTERCOM))
        {
          trainChild.addCreationCallback(intercomChild -> {
            if (intercomChild.getName().equals(ProjectObjectConstants.ClassName.INTERCOM_OUTPUTS))
            {
              commsBinding.setIntercomOutPutsMap(intercomChild.getId(), intercomChild);
              commsBinding.bindIntercomOutputs();
              businessLogic.attachIntercomOutPutsToModels();

              intercomChild.addCreationCallback(onpOutputs -> {
                if (onpOutputs.getName().equals(ProjectObjectConstants.ClassName.OHP_OUTPUTS))
                {
                  
                  commsBinding.setOHPOutPutsMap(onpOutputs.getId(), onpOutputs);
                  commsBinding.bindOHPOutPuts();
                  businessLogic.attachOHPOutPutsToModels();
                }
              });
            }
            else if (intercomChild.getName().equals(ProjectObjectConstants.ClassName.INTERCOM_INPUTS))
            {
              commsBinding.setIntercomInputs(intercomChild);
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
        else if (vehicleChild.getName().equals(ProjectObjectConstants.ClassName.TCMS_VEHICLE_INPUTS))
        {
          commsBinding.setTCMSVehicleInputs(vehicleChild, aVehicleIndex);
        }
        else if (vehicleChild.getName().equals(ProjectObjectConstants.ClassName.TCMS_VEHICLE_OUTPUTS))
        {
          commsBinding.setTCMSVehicleOutputs(vehicleChild, aVehicleIndex);
        }
        else if (vehicleChild.getName().equals(ProjectObjectConstants.ClassName.PIS_BE))
        {
          vehicleChild.addCreationCallback(vehicleChildInput -> {
            if (vehicleChildInput.getName().equals(ProjectObjectConstants.ClassName.PIS_BE_INPUTS))
            {
              vehicleChildInput.addCreationCallback(vehicleChildInputValues -> {
                if (vehicleChildInputValues.getName()
                    .equals(ProjectObjectConstants.ClassName.PIS_BE_INPUTS_VALUES))
                {
                  commsBinding.setPISBEInputs(vehicleChildInputValues, aVehicleIndex);
                }
              });
            }
            else if (vehicleChildInput.getName().equals(ProjectObjectConstants.ClassName.PIS_BE_OUTPUTS))
            {
              commsBinding.setPISBEOutputs(vehicleChildInput, aVehicleIndex);
            }
          });
        }
        else if (vehicleChild.getName().equals(ProjectObjectConstants.ClassName.PAPIS_VEHICLE_OUTPUTS))
        {
          commsBinding.setPAPISVehicleOutputs(vehicleChild, aVehicleIndex);
        } else if (vehicleChild.getName().equals(ProjectObjectConstants.ClassName.CBTC_VEHICLE_INPUTS))
        {
          commsBinding.setCbtcVehicleInputs(vehicleChild, aVehicleIndex);
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
      }
    }

    // To Do: adding for test purpose
    @Override
    public void onTrainObjectCreation(CObject object)
    {
      super.onTrainObjectCreation(object);
      scenrioTrainObject = object;
    }
  }

  /**
   * Creates monitor for events object creation.
   * 
   * @param aGateway
   * @param scenarioTrainId
   * @return
   */
  private EventsObjectMonitor createEventsObjectMonitor(Gateway aGateway, int scenarioTrainId)
  {
    ObjectDefinition eventsDefinition = ProjectObjectDefinition
        .getObjectDefinition(ProjectObjectConstants.ClassId.TCMS_MESSAGES);
    ObjectDefinition eventDefinition = ProjectObjectDefinition
        .getObjectDefinition(ProjectObjectConstants.ClassId.TCMS_MESSAGE);
    ObjectDefinition vehicleOutputDefinition = ProjectObjectDefinition
        .getObjectDefinition(ProjectObjectConstants.ClassId.TCMS_VEHICLE_OUTPUTS);
    return new EventsObjectMonitor(aGateway, commsBinding, eventsDefinition, eventDefinition,
        vehicleOutputDefinition, scenarioTrainId);
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
    trainConfigurationHandler = null;
  }
}
