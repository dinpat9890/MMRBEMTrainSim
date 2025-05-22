package com.sydac.mmrbem.tcms.fe.gui.presenter;

import java.io.IOException;

import com.sydac.mmrbem.cabscreens.fe.base.LoadingException;
import com.sydac.mmrbem.cabscreens.fe.common.NodePseudoClassProperty;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.VehicleDoorStatesList.DoorState;
import com.sydac.mmrbem.tcms.common.state.DoorsEnum;
import com.sydac.mmrbem.tcms.fe.base.TCMSFactory;
import com.sydac.mmrbem.tcms.fe.common.TCMSUIConstants;
import com.sydac.mmrbem.tcms.fe.gui.AbstractTCMSController;
import com.sydac.mmrbem.tcms.fe.gui.data.VehicleDoorStatesDO;
import com.sydac.mmrbem.tcms.fe.gui.model.CarConfigurationModel;
import com.sydac.mmrbem.tcms.fe.gui.model.TrainTopViewComponentStatusModel;
import com.sydac.mmrbem.tcms.fe.gui.view.ViewPackage;
import com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs;

import javafx.beans.property.ObjectPropertyBase;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.control.Button;
import javafx.scene.layout.GridPane;

/**
 * This class acts as a controller for Car Orientation 2-1. As the mapping of
 * states and input req follows a specific mapping.
 * 
 */
public class DoorsIsolateCommandsPanelController2 extends AbstractTCMSController
{

  @FXML
  private Button isolateA1Btn;

  @FXML
  private Button isolateA2Btn;

  @FXML
  private Button isolateA3Btn;

  @FXML
  private Button isolateA4Btn;

  @FXML
  private Button isolateB1Btn;

  @FXML
  private Button isolateB2Btn;

  @FXML
  private Button isolateB3Btn;

  @FXML
  private Button isolateB4Btn;

  private NodePseudoClassProperty doorA1PseudoClassProperty;

  private NodePseudoClassProperty doorA2PseudoClassProperty;

  private NodePseudoClassProperty doorA3PseudoClassProperty;

  private NodePseudoClassProperty doorA4PseudoClassProperty;

  private NodePseudoClassProperty doorB1PseudoClassProperty;

  private NodePseudoClassProperty doorB2PseudoClassProperty;

  private NodePseudoClassProperty doorB3PseudoClassProperty;

  private NodePseudoClassProperty doorB4PseudoClassProperty;

  private ObjectPropertyBase<VehicleDoorStatesDO> doorA1State;

  private ObjectPropertyBase<VehicleDoorStatesDO> doorA2State;

  private ObjectPropertyBase<VehicleDoorStatesDO> doorA3State;

  private ObjectPropertyBase<VehicleDoorStatesDO> doorA4State;

  private ObjectPropertyBase<VehicleDoorStatesDO> doorB1State;

  private ObjectPropertyBase<VehicleDoorStatesDO> doorB2State;

  private ObjectPropertyBase<VehicleDoorStatesDO> doorB3State;

  private ObjectPropertyBase<VehicleDoorStatesDO> doorB4State;

  private TrainTopViewComponentStatusModel carComponentStatusModel;

  private Integer carIndex;

  public DoorsIsolateCommandsPanelController2(CarConfigurationModel carConfig,
      TrainTopViewComponentStatusModel carComponentStatusModel)
  {
    super();
    this.carIndex = carConfig.carIndexProperty().get();
    this.carComponentStatusModel = carComponentStatusModel;
  }

  @Override
  public void detachListeners()
  {
    // To Detach Listeners
  }

  @Override
  public void initializeImpl()
  {
    doorA1PseudoClassProperty = new NodePseudoClassProperty(isolateA1Btn);
    doorA2PseudoClassProperty = new NodePseudoClassProperty(isolateA2Btn);
    doorA3PseudoClassProperty = new NodePseudoClassProperty(isolateA3Btn);
    doorA4PseudoClassProperty = new NodePseudoClassProperty(isolateA4Btn);
    doorB1PseudoClassProperty = new NodePseudoClassProperty(isolateB1Btn);
    doorB2PseudoClassProperty = new NodePseudoClassProperty(isolateB2Btn);
    doorB3PseudoClassProperty = new NodePseudoClassProperty(isolateB3Btn);
    doorB4PseudoClassProperty = new NodePseudoClassProperty(isolateB4Btn);

    doorA1State = carComponentStatusModel.doorA1StatusProperty(carIndex);
    doorA2State = carComponentStatusModel.doorA2StatusProperty(carIndex);
    doorA3State = carComponentStatusModel.doorA3StatusProperty(carIndex);
    doorA4State = carComponentStatusModel.doorA4StatusProperty(carIndex);
    doorB1State = carComponentStatusModel.doorB1StatusProperty(carIndex);
    doorB2State = carComponentStatusModel.doorB2StatusProperty(carIndex);
    doorB3State = carComponentStatusModel.doorB3StatusProperty(carIndex);
    doorB4State = carComponentStatusModel.doorB4StatusProperty(carIndex);

    doorA1State.addListener(observable -> updateDoorA4ButtonState());
    doorA2State.addListener(observable -> updateDoorA3ButtonState());
    doorA3State.addListener(observable -> updateDoorA2ButtonState());
    doorA4State.addListener(observable -> updateDoorA1ButtonState());
    doorB1State.addListener(observable -> updateDoorB4ButtonState());
    doorB2State.addListener(observable -> updateDoorB3ButtonState());
    doorB3State.addListener(observable -> updateDoorB2ButtonState());
    doorB4State.addListener(observable -> updateDoorB1ButtonState());

    updateDoorA1ButtonState();
    updateDoorA2ButtonState();
    updateDoorA3ButtonState();
    updateDoorA4ButtonState();
    updateDoorB1ButtonState();
    updateDoorB2ButtonState();
    updateDoorB3ButtonState();
    updateDoorB4ButtonState();
  }

  private void updateDoorA1ButtonState()
  {
    if (doorA4State.get().getDoorState() == DoorState.ISOLATED)
    {
      doorA1PseudoClassProperty.set(TCMSUIConstants.DOOR_ISOLATED_PSEUDO_CLASS);
      isolateA1Btn.setText(DoorsEnum.DOOR_A1.getResetButtonText());
    }
    else
    {
      doorA1PseudoClassProperty.set(TCMSUIConstants.DOOR_NOT_ISOLATED_PSEUDO_CLASS);
      isolateA1Btn.setText(DoorsEnum.DOOR_A1.getIsolateButtonText());
    }
  }

  private void updateDoorA2ButtonState()
  {
    if (doorA3State.get().getDoorState() == DoorState.ISOLATED)
    {
      doorA2PseudoClassProperty.set(TCMSUIConstants.DOOR_ISOLATED_PSEUDO_CLASS);
      isolateA2Btn.setText(DoorsEnum.DOOR_A2.getResetButtonText());
    }
    else
    {
      doorA2PseudoClassProperty.set(TCMSUIConstants.DOOR_NOT_ISOLATED_PSEUDO_CLASS);
      isolateA2Btn.setText(DoorsEnum.DOOR_A2.getIsolateButtonText());
    }
  }

  private void updateDoorA3ButtonState()
  {
    if (doorA2State.get().getDoorState() == DoorState.ISOLATED)
    {
      doorA3PseudoClassProperty.set(TCMSUIConstants.DOOR_ISOLATED_PSEUDO_CLASS);
      isolateA3Btn.setText(DoorsEnum.DOOR_A3.getResetButtonText());
    }
    else
    {
      doorA3PseudoClassProperty.set(TCMSUIConstants.DOOR_NOT_ISOLATED_PSEUDO_CLASS);
      isolateA3Btn.setText(DoorsEnum.DOOR_A3.getIsolateButtonText());
    }
  }

  private void updateDoorA4ButtonState()
  {
    if (doorA1State.get().getDoorState() == DoorState.ISOLATED)
    {
      doorA4PseudoClassProperty.set(TCMSUIConstants.DOOR_ISOLATED_PSEUDO_CLASS);
      isolateA4Btn.setText(DoorsEnum.DOOR_A4.getResetButtonText());
    }
    else
    {
      doorA4PseudoClassProperty.set(TCMSUIConstants.DOOR_NOT_ISOLATED_PSEUDO_CLASS);
      isolateA4Btn.setText(DoorsEnum.DOOR_A4.getIsolateButtonText());
    }
  }

  private void updateDoorB1ButtonState()
  {
    if (doorB4State.get().getDoorState() == DoorState.ISOLATED)
    {
      doorB1PseudoClassProperty.set(TCMSUIConstants.DOOR_ISOLATED_PSEUDO_CLASS);
      isolateB1Btn.setText(DoorsEnum.DOOR_B1.getResetButtonText());
    }
    else
    {
      doorB1PseudoClassProperty.set(TCMSUIConstants.DOOR_NOT_ISOLATED_PSEUDO_CLASS);
      isolateB1Btn.setText(DoorsEnum.DOOR_B1.getIsolateButtonText());
    }
  }

  private void updateDoorB2ButtonState()
  {
    if (doorB3State.get().getDoorState() == DoorState.ISOLATED)
    {
      doorB2PseudoClassProperty.set(TCMSUIConstants.DOOR_ISOLATED_PSEUDO_CLASS);
      isolateB2Btn.setText(DoorsEnum.DOOR_B2.getResetButtonText());
    }
    else
    {
      doorB2PseudoClassProperty.set(TCMSUIConstants.DOOR_NOT_ISOLATED_PSEUDO_CLASS);
      isolateB2Btn.setText(DoorsEnum.DOOR_B2.getIsolateButtonText());
    }
  }

  private void updateDoorB3ButtonState()
  {
    if (doorB2State.get().getDoorState() == DoorState.ISOLATED)
    {
      doorB3PseudoClassProperty.set(TCMSUIConstants.DOOR_ISOLATED_PSEUDO_CLASS);
      isolateB3Btn.setText(DoorsEnum.DOOR_B3.getResetButtonText());
    }
    else
    {
      doorB3PseudoClassProperty.set(TCMSUIConstants.DOOR_NOT_ISOLATED_PSEUDO_CLASS);
      isolateB3Btn.setText(DoorsEnum.DOOR_B3.getIsolateButtonText());
    }
  }

  private void updateDoorB4ButtonState()
  {
    if (doorB1State.get().getDoorState() == DoorState.ISOLATED)
    {
      doorB4PseudoClassProperty.set(TCMSUIConstants.DOOR_ISOLATED_PSEUDO_CLASS);
      isolateB4Btn.setText(DoorsEnum.DOOR_B4.getResetButtonText());
    }
    else
    {
      doorB4PseudoClassProperty.set(TCMSUIConstants.DOOR_NOT_ISOLATED_PSEUDO_CLASS);
      isolateB4Btn.setText(DoorsEnum.DOOR_B4.getIsolateButtonText());
    }
  }

  @FXML
  private void onIsolateButtonAction(ActionEvent event)
  {

    TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendSelectedDoorIsolateCar(carIndex);
    if (event.getSource().equals(isolateA1Btn))
    {
      sendDoorA4IsolateReq();
    }
    else if (event.getSource().equals(isolateA2Btn))
    {
      sendDoorA3IsolateReq();
    }
    else if (event.getSource().equals(isolateA3Btn))
    {
      sendDoorA2IsolateReq();
    }
    else if (event.getSource().equals(isolateA4Btn))
    {
      sendDoorA1IsolateReq();
    }
    else if (event.getSource().equals(isolateB1Btn))
    {
      sendDoorB4IsolateReq();
    }
    else if (event.getSource().equals(isolateB2Btn))
    {
      sendDoorB3IsolateReq();
    }
    else if (event.getSource().equals(isolateB3Btn))
    {
      sendDoorB2IsolateReq();
    }
    else if (event.getSource().equals(isolateB4Btn))
    {
      sendDoorB1IsolateReq();
    }
  }

  private void sendDoorB4IsolateReq()
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendDoorIsolateReq(VDUInputs.DOOR_B4_ISO_REINS_REQ,
        ((doorB4State.get().getDoorState() != DoorState.ISOLATED)
            && (doorB4State.get().getDoorState() == DoorState.CLOSED_AND_LOCKED))
                ? TCMSUIConstants.ISOLATE_VALUE
                : TCMSUIConstants.REINSERT_VALUE);
  }

  private void sendDoorB3IsolateReq()
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendDoorIsolateReq(VDUInputs.DOOR_B3_ISO_REINS_REQ,
        ((doorB3State.get().getDoorState() != DoorState.ISOLATED)
            && (doorB3State.get().getDoorState() == DoorState.CLOSED_AND_LOCKED))
                ? TCMSUIConstants.ISOLATE_VALUE
                : TCMSUIConstants.REINSERT_VALUE);
  }

  private void sendDoorB2IsolateReq()
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendDoorIsolateReq(VDUInputs.DOOR_B2_ISO_REINS_REQ,
        ((doorB2State.get().getDoorState() != DoorState.ISOLATED)
            && (doorB2State.get().getDoorState() == DoorState.CLOSED_AND_LOCKED))
                ? TCMSUIConstants.ISOLATE_VALUE
                : TCMSUIConstants.REINSERT_VALUE);
  }

  private void sendDoorB1IsolateReq()
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendDoorIsolateReq(VDUInputs.DOOR_B1_ISO_REINS_REQ,
        ((doorB1State.get().getDoorState() != DoorState.ISOLATED)
            && (doorB1State.get().getDoorState() == DoorState.CLOSED_AND_LOCKED))
                ? TCMSUIConstants.ISOLATE_VALUE
                : TCMSUIConstants.REINSERT_VALUE);
  }

  private void sendDoorA4IsolateReq()
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendDoorIsolateReq(VDUInputs.DOOR_A4_ISO_REINS_REQ,
        ((doorA4State.get().getDoorState() != DoorState.ISOLATED)
            && (doorA4State.get().getDoorState() == DoorState.CLOSED_AND_LOCKED))
                ? TCMSUIConstants.ISOLATE_VALUE
                : TCMSUIConstants.REINSERT_VALUE);
  }

  private void sendDoorA3IsolateReq()
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendDoorIsolateReq(VDUInputs.DOOR_A3_ISO_REINS_REQ,
        ((doorA3State.get().getDoorState() != DoorState.ISOLATED)
            && (doorA3State.get().getDoorState() == DoorState.CLOSED_AND_LOCKED))
                ? TCMSUIConstants.ISOLATE_VALUE
                : TCMSUIConstants.REINSERT_VALUE);
  }

  private void sendDoorA2IsolateReq()
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendDoorIsolateReq(VDUInputs.DOOR_A2_ISO_REINS_REQ,
        ((doorA2State.get().getDoorState() != DoorState.ISOLATED)
            && (doorA2State.get().getDoorState() == DoorState.CLOSED_AND_LOCKED))
                ? TCMSUIConstants.ISOLATE_VALUE
                : TCMSUIConstants.REINSERT_VALUE);
  }

  private void sendDoorA1IsolateReq()
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendDoorIsolateReq(VDUInputs.DOOR_A1_ISO_REINS_REQ,
        ((doorA1State.get().getDoorState() != DoorState.ISOLATED)
            && (doorA1State.get().getDoorState() == DoorState.CLOSED_AND_LOCKED))
                ? TCMSUIConstants.ISOLATE_VALUE
                : TCMSUIConstants.REINSERT_VALUE);
  }

  public GridPane createCar(String fxmlName)
  {
    GridPane gridPane;
    FXMLLoader fxmlLoader = new FXMLLoader(ViewPackage.class.getResource(fxmlName));
    fxmlLoader.setController(this);
    try
    {
      gridPane = fxmlLoader.load();
    }
    catch (IOException exception)
    {
      logger.error(exception);
      throw new LoadingException(exception);
    }
    return gridPane;
  }
}
